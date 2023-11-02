
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
