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
	typedef struct node{
		int val,prior,szt;
		node *l,*r;
		node(){}
		node(int _val,int _prior,int _szt):val(_val),prior(_prior),szt(_szt),l(NULL),r(NULL){}
	}node;
	typedef node* pnode;

	struct ImplicitTreap{
		pnode tree;
		ImplicitTreap(){
			tree = NULL;
		}

		int cnt_size(pnode t){
			return (t ? t -> szt : 0);
		}

		void upd_size(pnode &t){
			if(t){
				t -> szt = cnt_size(t -> l) + 1 + cnt_size(t -> r);
			}
		}

		void split(pnode t,pnode &l,pnode &r,int pos,int add = 0){
			if(!t)return (void)(l = r = NULL);
			int cur_pos = add + cnt_size(t -> l);
			if(cur_pos < pos){
				split(t -> r,t -> r,r,pos,cur_pos + 1);
				l = t;
			} else {
				split(t -> l,l,t -> l,pos,add);
				r = t;
			}
			upd_size(t);
		}

		void merge(pnode &t,pnode l,pnode r){
			if(!l or !r){
				t = l ? l : r;
			} else if(l -> prior > r -> prior){
				merge(l -> r,l -> r,r);;
				t = l;
			} else {
				merge(r -> l,l,r -> l);
				t = r;
			}
			upd_size(t);
		}

		int get(int pos){
			pnode x,y,z,cur;
			split(tree,x,y,pos - 1);
			split(y,cur,z,1);
			int ret = (cur ? cur -> val : -1);
			merge(tree,x,cur);
			merge(tree,tree,z);
			return ret;
		}

		void ins(int pos,int val){
			pnode l,r,cur;
			cur = new node;
			cur -> val = val,cur -> szt = 1,cur -> prior = rand() % PRIORITY;
			cur -> l = cur -> r = NULL;
			split(tree,l,r,pos - 1);
			merge(tree,l,cur);
			merge(tree,tree,r);
		}

		int lwb(int val){
			int p = 0;
			int l = 1,r = cnt_size(tree);
			for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
				if(get(mid) <= val){
					l = mid + 1;
					p = mid;
				} else {
					r = mid - 1;
				}
			}
			return p;
		}
	}treap;

    const int N = 2e5 + 5;
    int a[N];
    int n,q;

    void solve(){
    	srand(time(NULL));
    	cin>>n>>q;
    	for(int i = 1;i <= n;++i){
    		cin>>a[i];
    	}
    	sort(a + 1,a + 1 + n);
    	for(int i = 1;i <= n;++i){
    		treap.ins(i,a[i]);
    	}
    	while(q--){
    		int type,d;
    		cin>>type>>d;
    		if(type == 1){
    			int k = treap.lwb(d);
    			d += k;
    			k = treap.lwb(d);
    			treap.ins(k + 1,d);
    		} else if(type == 2){
    			cout<<treap.lwb(d)<<'\n';
    		} else {
    			if(d > treap.cnt_size(treap.tree)){
    				cout<<"invalid\n";
    			} else {
    				cout<<treap.get(d)<<'\n';
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
