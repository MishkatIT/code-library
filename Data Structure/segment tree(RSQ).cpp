#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<long long> tree, lazy;
    int n;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<int>& arr, int node, int s, int e) {
        if (s == e) {
            tree[node] = arr[s];
        } else {
            int mid = (s + e) / 2;
            build(arr, 2 * node, s, mid);
            build(arr, 2 * node + 1, mid + 1, e);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void propagate(int node, int s, int e) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (s != e) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int s, int e, int l, int r, int val) {
        propagate(node, s, e);
        if (l > e || r < s) {
            return;
        }
        if (l <= s && e <= r) {
            lazy[node] += val;
            propagate(node, s, e);
            return;
        }
        int mid = (s + e) / 2;
        update(2 * node, s, mid, l, r, val);
        update(2 * node + 1, mid + 1, e, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long query(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
        if (l > e || r < s) {
            return 0;
        }
        if (l <= s && e <= r) {
            return tree[node];
        }
        int mid = (s + e) / 2;
        long long leftSum = query(2 * node, s, mid, l, r);
        long long rightSum = query(2 * node + 1, mid + 1, e, l, r);
        return leftSum + rightSum;
    }

    void range_update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    long long range_query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    int t;
    cin >> t;
    int cs = 0;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        SegmentTree st(arr);
        cout << "Case " << ++cs << ":\n";
        while (q--) {
            int type, l, r;
            cin >> type >> l >> r;
            l--, r--;
            if (type == 0) {
                int val;
                cin >> val;
                st.range_update(l, r, val);
            } else {
                cout << st.range_query(l, r) << '\n';
            }
        }
    }
    return 0;
}
