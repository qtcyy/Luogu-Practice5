#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> tree; // 线段树数组
    vector<int> lazy; // 延迟更新数组
    int n;

    // 建树函数
    void build(vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            int left_child = 2 * node + 1;
            int right_child = 2 * node + 2;
            build(data, left_child, start, mid);
            build(data, right_child, mid + 1, end);
            tree[node] = tree[left_child] + tree[right_child];
        }
    }

    // 区间加值函数
    void rangeUpdate(int node, int start, int end, int l, int r, int val) {
        if (lazy[node] != 0) { // 先处理延迟更新
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > r || end < l) // 完全不重叠
            return;

        if (start >= l && end <= r) { // 完全重叠
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        // 部分重叠
        int mid = (start + end) / 2;
        rangeUpdate(2 * node + 1, start, mid, l, r, val);
        rangeUpdate(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // 区间查询函数
    int rangeQuery(int node, int start, int end, int l, int r) {
        if (start > r || end < l)
            return 0;

        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start >= l && end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        int left_sum = rangeQuery(2 * node + 1, start, mid, l, r);
        int right_sum = rangeQuery(2 * node + 2, mid + 1, end, l, r);
        return left_sum + right_sum;
    }

public:
    SegmentTree(vector<int>& data) {
        n = data.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(data, 0, 0, n - 1);
    }

    void updateRange(int l, int r, int val) {
        rangeUpdate(0, 0, n - 1, l, r, val);
    }

    int queryRange(int l, int r) {
        return rangeQuery(0, 0, n - 1, l, r);
    }
};

int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree st(data);
    cout << "Initial sum of range(1, 3): " << st.queryRange(1, 3) << endl;
    st.updateRange(1, 3, 5);
    cout << "Updated sum of range(1, 3): " << st.queryRange(1, 3) << endl;
    cout << "Sum of range(0, 2): " << st.queryRange(0, 2) << endl;

    return 0;
}
