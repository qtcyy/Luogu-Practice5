#include <stdio.h>
#include <limits.h>
#define MAX 1000  // 根据需要调整最大节点数

int arr[] = {1, 3, 5, 7, 9, 11};  // 原始数组
int tree[MAX];  // 线段树数组
int lazy[MAX];  // 懒惰传播数组

void build(int node, int start, int end) {
    if (start == end) {
        // 叶子节点
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        tree[node] = (tree[2*node+1] > tree[2*node+2] ? tree[2*node+1] : tree[2*node+2]);
    }
}

void updateRange(int node, int start, int end, int l, int r, int val) {
    if (lazy[node] != 0) {
        // 需要先处理懒惰传播
        tree[node] += lazy[node];
        if (start != end) {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > end || start > r || end < l) {
        // 范围外
        return;
    }

    if (start >= l && end <= r) {
        // 当前区间完全包含在更新区间内
        tree[node] += val;
        if (start != end) {
            lazy[2*node+1] += val;
            lazy[2*node+2] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    updateRange(2*node+1, start, mid, l, r, val);
    updateRange(2*node+2, mid+1, end, l, r, val);
    tree[node] = (tree[2*node+1] > tree[2*node+2] ? tree[2*node+1] : tree[2*node+2]);
}

int queryRange(int node, int start, int end, int l, int r) {
    if (start > end || start > r || end < l) {
        // 范围外
        return INT_MIN;
    }

    if (lazy[node] != 0) {
        // 处理懒惰传播
        tree[node] += lazy[node];
        if (start != end) {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start >= l && end <= r) {
        // 完全包含在查询范围内
        return tree[node];
    }

    int mid = (start + end) / 2;
    int left_max = queryRange(2*node+1, start, mid, l, r);
    int right_max = queryRange(2*node+2, mid+1, end, l, r);
    return (left_max > right_max ? left_max : right_max);
}

int main() {
    int n = sizeof(arr) / sizeof(arr[0]);
    build(0, 0, n-1);
    printf("Original maximum in range [1, 4]: %d\n", queryRange(0, 0, n-1, 1, 4));

    updateRange(0, 0, n-1, 1, 3, 5);
    printf("New maximum in range [1, 4]: %d\n", queryRange(0, 0, n-1, 1, 4));

    return 0;
}
