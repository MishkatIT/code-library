#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Ordered Set (Ascending Order)
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Ordered Set (Descending Order)
template <typename T>
using ordered_set_desc = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Ordered Multiset (Ascending Order)
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Ordered Multiset (Descending Order)
template <typename T>
using ordered_multiset_desc = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;





// several data types

template<typename T>
struct custom_compare {
    bool operator() (auto& a, auto& b) const {
        return a < b;
    }
};

template<>
struct custom_compare<pair<int, int>> {
    bool operator() (auto& a, auto& b) const {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }
};

template<>
struct custom_compare<vector<int>> {
    bool operator() (auto& a, auto& b) const {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    }
};

template<>
struct custom_compare<string> {
    bool operator() (auto& a, auto& b) const {
        return a < b;
    }
};

template<typename T>
using ordered_set_customType = tree<T, null_type, custom_compare<T>, rb_tree_tag, tree_order_statistics_node_update>;




int main() {
    ordered_set<int> pbds_set;

    pbds_set.insert(3);
    pbds_set.insert(1);
    pbds_set.insert(4);
    pbds_set.insert(2);
    pbds_set.insert(5);

    int order = pbds_set.order_of_key(4);
    int kth_element = *pbds_set.find_by_order(2);
    pbds_set.erase(2);

    for (auto it = pbds_set.begin(); it != pbds_set.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}





