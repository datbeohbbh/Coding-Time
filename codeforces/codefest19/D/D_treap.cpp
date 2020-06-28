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
#define BIT(x,i) (((x)>>(i))&1LL)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

	const int PRIORITY = 2e9;
	const ll inf = 1e18;
    const int N = 2e5 + 5;

	typedef struct node 	{
		ll lazy_val,lazy_idx;
		pair <ll,pii> min_val,val;
		int prior,szt;
		node *l,*r;
		node(){}
		node(pair <ll,pii> _val,pair <ll,pii> _min_val,int _prior,int _szt,ll _lazy_val,ll _lazy_idx){
            min_val = _min_val;
			val = _val,prior = _prior,szt = _szt;
			lazy_val = _lazy_val,lazy_idx = _lazy_idx;
			l = r = NULL;
		}
	}node;
	typedef node* pnode;

	struct ImplicitTreap{
		pnode tree;
		ImplicitTreap(){
			tree = NULL;
		}

		int cnt(pnode t){
			return (t ? t -> szt : 0);
		}

		void upd_size(pnode &t){
			if(t){
				t -> szt = cnt(t -> l) + 1 + cnt(t -> r);
			}
		}

		void pushdown(pnode &t){
			if(t and t -> lazy_val and t -> lazy_idx){
				(t -> val).fir += t -> lazy_val;
				(t -> val).sec.fir += t -> lazy_idx;
                (t -> min_val).fir += t -> lazy_val;
				(t -> min_val).sec.fir += t -> lazy_idx;
				if(t -> l){
					t -> l -> lazy_val += t -> lazy_val;
					t -> l -> lazy_idx += t -> lazy_idx;
				}
				if(t -> r){
					t -> r -> lazy_val += t -> lazy_val;
					t -> r -> lazy_idx += t -> lazy_idx;
				}
				t -> lazy_idx = t -> lazy_val = 0;
			}
		}

		void combine(pnode &t){
            if(!t)return ;
            pushdown(t -> l);
            pushdown(t -> r);
            t -> min_val = t -> val;
            if(t -> l)minimize(t -> min_val,t -> l -> min_val);
            if(t -> r)minimize(t -> min_val,t -> r -> min_val);
		}

		void split(pnode t,pnode &l,pnode &r,int pos,int add = 0){
			pushdown(t);
			if(!t){
				return (void)(l = r = NULL);
			}
			int cur_pos = add + cnt(t -> l);
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
			} else if(l -> prior > r -> prior){
				merge(l -> r,l -> r,r);
				t = l;
			} else {
				merge(r -> l,l,r -> l);
				t = r;
			}
			upd_size(t);
			combine(t);
		}

		void ins(pair <ll,pii> val){
			pnode cur = new node;
			cur -> val = cur -> min_val = val;
			cur -> lazy_val = cur -> lazy_idx = 0;
			cur -> szt = 1,cur -> prior = rand() % PRIORITY;
			cur -> l = cur -> r = NULL;
			pnode t1,t2;
			split(tree,t1,t2,-val.sec.fir - 1);
			merge(tree,t1,cur);
			merge(tree,tree,t2);
		}

		void modify(int subs){
			if(!tree)return ;
			pair <ll,pii> val = tree -> min_val;
			pnode t1,t2,t3,t4;
			split(tree,t1,t2,-val.sec.fir - 1);
			split(t2,t3,t4,1);
			if(t4){
				t4 -> lazy_idx += 1;
				t4 -> lazy_val -= 1LL*subs;
			}
			merge(tree,t1,t4);
		}

	}treap;

	ll s[N];
	int perm[N];
	int n;

    void solve(){
    	srand(time(NULL));
    	cin>>n;
    	for(int i = 1;i <= n;++i){
    		cin>>s[i];
    		treap.ins({s[i],{-i,i}});
    	}
    	for(int i = 1;i <= n;++i){
    		if(treap.tree){
    			int idx = (treap.tree -> min_val).sec.sec;
    			perm[idx] = i;
    			treap.modify(i);
    		}
    	}
    	for(int i = 1;i <= n;++i){
    		cout<<perm[i]<<' ';
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
