#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set =
       tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x=y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x){
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD){
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define emp emplace_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

	const int PRIORITY = 2e9;
	typedef struct node{
		ll sum,val,lazy;
		int szt,prior;
		node* l;
		node* r;
		node(){}
		node(ll _sum,ll _val,ll _lazy,int _szt,int _prior):sum(_sum),val(_val),lazy(_lazy),szt(_szt),prior(_prior),l(NULL),r(NULL){}
	}node;
	typedef node* pnode;

	struct ImplicitTreap{
		pnode tree;
		void clr(){
			tree = NULL;
		}

		int cnt_size(pnode t){
			return (!t ? 0 : t -> szt);
		}

		void upd_size(pnode &t){
			if(t){
                t -> szt = cnt_size(t -> l) + 1 + cnt_size(t -> r);
            }
		}

		void pushdown(pnode &t){
			if(t and t -> lazy){
				t -> val += t -> lazy;
				t -> sum += (t -> lazy) * 1LL * cnt_size(t);
				if(t -> l){
					t -> l -> lazy += t -> lazy;
				}
				if(t -> r){
					t -> r -> lazy += t -> lazy;
				}
				t -> lazy = 0;
			}
		}

		void combine(pnode &t){
            if(!t)return ;
			pushdown(t -> l);
			pushdown(t -> r);
			t -> sum = t -> val;
			if(t -> l){
				t -> sum += t -> l -> sum;
			}
			if(t -> r){
				t -> sum += t -> r -> sum;
			}
		}

		void split(pnode t,pnode &l,pnode &r,int pos,int add = 0){
			pushdown(t);
			if(!t){
				return (void)(l = r = NULL);
			}
			int cur_pos = add + cnt_size(t -> l);
			if(cur_pos < pos){
				split(t -> r,t -> r,r,pos,cur_pos + 1);
				l = t;
			} else {
				split(t -> l,l,t -> l,pos,add);
				r = t;
			}
			upd_size(t);
			combine(t);
		}

		void merge(pnode &t,pnode l,pnode r){
			pushdown(l);
			pushdown(r);
			if(!l or !r){
				t = (l ? l : r);
			}
            else if(l -> prior > r -> prior){
				merge(l -> r,l -> r,r);
				t = l;
			} else {
				merge(r -> l,l,r -> l);
				t = r;
			}
			upd_size(t);
			combine(t);
		}

		void update_range(int l,int r,int val){
			pnode x,y,z,cur;
			split(tree,x,y,l - 1);
			split(y,cur,z,r - l + 1);
			if(cur){
                cur -> lazy += val;
            }
			merge(tree,x,cur);
			merge(tree,tree,z);
		}

		ll query_range(int l,int r){
			pnode x,y,z,cur;
			ll ans = 0;
			split(tree,x,y,l - 1);
			split(y,cur,z,r - l + 1);
			if(cur){
                ans = cur -> sum;
			}
			merge(tree,x,cur);
			merge(tree,tree,z);
			return ans;
		}

        void init(pnode &cur){
            cur -> sum = cur -> val = cur -> lazy = 0;
            cur -> szt = 1;
            cur -> prior = rand() % PRIORITY;
        }

		void ins(int l){
            pnode cur = new node;
            init(cur);
            pnode x,y;
            split(tree,x,y,l - 1);
            merge(tree,x,cur);
            merge(tree,tree,y);
		}

	}treap;

	int n,c;

    void solve(){
    	srand(time(NULL));
    	int T;
    	cin>>T;
    	while(T--){
    		cin>>n>>c;
    		treap.clr();
    		for(int i = 1;i <= n;++i){
    			treap.ins(i);
    		}
    		for(int i = 1;i <= c;++i){
    			int op,p,q,v;
    			cin>>op;
    			if(op){
    				cin>>p>>q;
    				cout<<treap.query_range(p,q)<<'\n';
    			} else {
    				cin>>p>>q>>v;
    				treap.update_range(p,q,v);
    			}
    		}
    	}
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
