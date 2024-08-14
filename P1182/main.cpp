#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

inline bool check(int x) {
    int tot = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (tot + a[i] <= x)
            tot += a[i];
        else {
            tot = a[i];
            sum++;
        }
    }
    return sum >= m;
}

signed main() {
    cin >> n >> m;
    a.resize(n + 1);
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l << endl;

    return 0;
}