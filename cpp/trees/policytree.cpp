// policy tree (for o(1) dist in set)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef tree<int ,null_type,less<int >,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
xx=(m[v].order_of_key(r+1))-(m[v].order_of_key(l)); // dist bw with l and r
