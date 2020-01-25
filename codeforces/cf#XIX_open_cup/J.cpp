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

	const int N = 2e3 + 3;
	int n;
	ll a[N];

	struct point {
		ll x,y;

		point(){}
		point(ll _x,ll _y):x(_x),y(_y){}

		ll ccw(point A,point B,point C){
			return Abs((B.x - A.x) * (C.y - B.y) - (C.x - B.x) * (B.y - A.y));
		}

		bool intersect(point A,point B,point C,point D){
			return (ccw(A,B,D) + ccw(A,C,B) == ccw(A,C,D) + ccw(C,B,D)
                and ccw(A,B,D)*ccw(A,C,B) > 0 and ccw(A,C,D)*ccw(C,B,D) > 0);
		}

	};
	point p[N<<1],home,f;

    void solve(){
    	cin>>n;
    	for(int i = 1;i <= (n<<1);++i){
    		cin>>a[i];
    	}
    	cin>>home.x;
    	int pos;
    	ll curx = a[1],cury = 0;
    	p[1] = point(curx,cury);
    	for(int i = 1;i < (n<<1);++i){
    		ll nx = a[i + 1];
    		ll ny = cury + (i & 1 ? 1 : - 1) * (a[i + 1] - a[i]);
            p[i + 1] = point(nx,ny);
            if(a[i] <= home.x and home.x <= a[i + 1]){
            	ll na = cury - ny;
            	ll nb = nx - curx;
            	ll c = nx*(ny - cury) + ny*(curx - nx);
            	home.y = (-c - na * home.x) / nb;
            	pos = i;
            }
    		swap(curx,nx);
    		swap(cury,ny);
    	}
    	ll lo = 0,hi = 1e10;
    	ll ans;
    	for(ll mid = (lo + hi) >> 1;lo <= hi;mid = (lo + hi) >> 1){
    		point sun = point(0,mid);
    		bool ok = true;
    		for(int i = 1;i < pos;++i){
    			if(f.intersect(home,sun,p[i],p[i + 1])){
    				ok = false;
    			}
    		}
    		if(ok){
    			hi = mid - 1;
    			ans = mid;
    		} else {
    			lo = mid + 1;
    		}
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
