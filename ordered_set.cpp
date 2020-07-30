/* ================================= ORDERED SET ================================= */

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using ordered_set = tree <T,null_type,std::less <T>,rb_tree_tag,tree_order_statistics_node_update>;
/*
  - find_by_order(k) The first returns an iterator to the k-th largest element (counting from zero).
  - order_of_key(item)  The second — the number of items in a set that are strictly smaller than our item.
*/

/* ================================= ORDERED SET ================================= */

