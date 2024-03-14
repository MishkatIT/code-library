#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<ll> tree, lazy;

class segmentTree
{
public:
    int n;
    segmentTree(vector<ll>& v)
    {
        n = v.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(v, 1, 0, n - 1);
    }

    void build(vector<ll>& v, int node, int s, int e)
    {
        if (s == e) {
            tree[node] = v[s];
            return;
        }
        int mid = (s + e) / 2;
        build(v, 2 * node, s, mid);
        build(v, 2 * node + 1, mid + 1, e);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }


    void propagate(int node, int s, int e)
    {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (s != e) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void range_update(int node, int s, int e, int l, int r, ll val)
    {
        if (e < l || r < s) {
            return;
        }
        propagate(node, s, e);
        if (l <= s && e <= r) {
            lazy[node] += val;
            propagate(node, s, e);
            return;
        }
        int mid = (s + e) / 2;
        range_update(2 * node, s, mid, l, r, val);
        range_update(2 * node + 1, mid + 1, e, l, r, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    ll range_query(int node, int s, int e, int l, int r)
    {
        if (e < l || r < s) {
            return LLONG_MAX;
        }
        propagate(node, s, e);
        if (l <= s && e <= r) {
            return tree[node];
        }
        int mid = (s + e) / 2;
        ll left = range_query(2 * node, s, mid, l, r);
        ll right = range_query(2 * node + 1, mid + 1, e, l, r);
        return min(left, right);
    }

    ll query(int l, int r)
    {
        return range_query(1, 0, n - 1, l - 1, r - 1);
    }
    void update(int l, int r, ll val)
    {
        range_update(1, 0, n - 1, l - 1, r - 1, val);
    }

};




int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        segmentTree st(v);
        while(q--) {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << '\n';
        }
    }
    return 0;
}
