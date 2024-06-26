#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class segmentTree
{
public:
    int n;
    vector<ll> Tree, Lazy;

    segmentTree(vector<ll>& v)
    {
        n = v.size();
        Tree.resize(4 * n);
        Lazy.resize(4 * n);
        build(v, 1, 0, n - 1);
    }

    #define lc (node << 1)
    #define rc ((node << 1) | 1)

    void build(vector<ll>& v, int node, int s, int e)
    {
        if (s == e) {
            Tree[node] = v[s];
            return;
        }
        int mid = (s + e) / 2;
        build(v, lc, s, mid);
        build(v, rc, mid + 1, e);
        Tree[node] = merge(Tree[lc], Tree[rc]);
    }

    ll merge(ll a, ll b)
    {
        return min(a, b);
    }

    void propagate(int node, int s, int e)
    {
        if (Lazy[node] != 0) {
            Tree[node] += Lazy[node];
            if (s != e) {
                Lazy[lc] += Lazy[node];
                Lazy[rc] += Lazy[node];
            }
            Lazy[node] = 0;
        }
    }

    void range_update(int node, int s, int e, int l, int r, ll val)
    {
        propagate(node, s, e);
        if (e < l || r < s) {
            return;
        }
        if (l <= s && e <= r) {
            Lazy[node] += val;
            propagate(node, s, e);
            return;
        }
        int mid = (s + e) / 2;
        range_update(lc, s, mid, l, r, val);
        range_update(rc, mid + 1, e, l, r, val);
        Tree[node] = merge(Tree[lc], Tree[rc]);
    }

    ll range_query(int node, int s, int e, int l, int r)
    {
        propagate(node, s, e);
        if (e < l || r < s) {
            return LLONG_MAX;
        }
        if (l <= s && e <= r) {
            return Tree[node];
        }
        int mid = (s + e) / 2;
        ll left = range_query(lc, s, mid, l, r);
        ll right = range_query(rc, mid + 1, e, l, r);
        return merge(left, right);
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
