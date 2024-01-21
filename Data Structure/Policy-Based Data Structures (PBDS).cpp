
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;




// unordered set
typedef cc_hash_table<int, null_type> unordered_set_type;
typedef tree<int, null_type, hash<int>, equal_to<int>, unordered_set_type> unordered_set_tree;

// multiset (ascending order)
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// multiset (descending order) 
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// unordered multiset
typedef cc_hash_table<int, null_type> unordered_multiset_type;
typedef tree<int, null_type, hash<int>, equal_to<int>, unordered_multiset_type> unordered_multiset_tree;





// several data types 

template<typename T>
struct custom_compare {
    bool operator() (const T& a, const T& b) const {
        return a < b;
    }
};

template<>
struct custom_compare<pair<int, int>> {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }
};

template<>
struct custom_compare<vector<int>> {
    bool operator() (const vector<int>& a, const vector<int>& b) const {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    }
};

template<>
struct custom_compare<string> {
    bool operator() (const string& a, const string& b) const {
        return a < b;
    }
};

template<typename T>
using ordered_set = tree<T, null_type, custom_compare<T>, rb_tree_tag, tree_order_statistics_node_update>;






int main() {
    ordered_set pbds_set;

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





