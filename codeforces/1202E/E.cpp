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

	const int N = 2e5 + 5;
	const int lg = 18;

	struct SuffixArray{
		int len;
		int ra[N];
		pair <pii,int> cur_rank[N];
		int p[N][lg + 1];
		string st;

		SuffixArray(){
			st = "";
		}

		void build(string str){
			st = str;
			len = sz(st) - 1;
			for(int i = 0;i <= len;++i){
				p[i][0] = st[i] - 'a';
			}
			for(int j = 1;j <= lg;++j){
				for(int i = 0;i <= len;++i){
					cur_rank[i] = {{p[i][j - 1],(i + MASK(j - 1) <= len ? p[i + MASK(j - 1)][j - 1] : - 1)},i};
				}
				sort(cur_rank,cur_rank + len + 1);
				for(int i = 0;i <= len;++i){
					p[cur_rank[i].sec][j] = (i and cur_rank[i - 1].fir.fir == cur_rank[i].fir.fir
							 				   and cur_rank[i - 1].fir.sec == cur_rank[i].fir.sec
							 				   	 ? p[cur_rank[i - 1].sec][j] : i);
				}
			}
			for(int i = 0;i <= len;++i){
				ra[i] = cur_rank[i].sec;
			}
		}

		int ok(string pat,int pos){
			string u = "";
			int i = 0,j = ra[pos];
			while(i < sz(pat) and j <= len){
				u.pb(st[j]);
				++i;
				++j;
			}
			if(pat == u)return 0;
			return (pat > u ? 1 : -1);
		}

		int find_left(string pat){
			int l = 0,r = len;
			int pl = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				int sgn = ok(pat,mid);
				if(!sgn){
					r = mid - 1;
					pl = mid;
				} else {
					if(sgn == 1){
						l = mid + 1;
					} else {
						r = mid - 1;
					}
				}
			}
			return pl;
		}

		int find_right(string pat){
			int l = 0,r = len;
			int pr = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				int sgn = ok(pat,mid);
				if(!sgn){
					l = mid + 1;
					pr = mid;
				} else {
					if(sgn == 1){
						l = mid + 1;
					} else {
						r = mid - 1;
					}
				}
			}
			return pr;
		}
	}sa[2];

	string t[2];
	int pref[2][N];
	int f[N],g[N];
	int n;

    void solve(){
    	cin>>t[0]>>n;
    	t[1] = t[0];
    	reverse(all(t[1]));
    	sa[0].build(t[0]);
    	sa[1].build(t[1]);
    	for(int i = 1;i <= n;++i){
    		string s,rev_s;
    		cin>>s;
    		rev_s = s;
    		reverse(all(rev_s));
    		int ls = sa[0].find_left(s);
    		int rs = sa[0].find_right(s);
    		int lrs = sa[1].find_left(rev_s);
    		int rrs = sa[1].find_right(rev_s);
    		if(~ls and ~rs){
    			pref[0][ls] += 1;
    			pref[0][rs + 1] -= 1;
    		}
    		if(~lrs and ~rrs){
    			pref[1][lrs] += 1;
    			pref[1][rrs + 1] -= 1;
    		}
    	}
    	for(int j = 0;j < 2;++j){
    		for(int i = 0;i < sz(t[j]);++i){
    			pref[j][i] += (i ? pref[j][i - 1] : 0);
    		}
    	}
    	for(int i = 0;i < sz(t[0]);++i){
    		f[sa[0].ra[i]] = pref[0][i];
    	}
    	for(int i = 0;i < sz(t[1]);++i){
    		g[sz(t[1]) - sa[1].ra[i] - 1] = pref[1][i];
    	}
    	ll ans = 0;
    	for(int i = 1;i < sz(t[0]);++i){
    		ans += 1LL*g[i - 1]*1LL*f[i];
    	}
    	cout<<ans;
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
