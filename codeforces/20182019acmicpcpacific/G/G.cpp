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

	pair <double,double> c[5];
	double x0,y0,x1,y1,x2,y2;

	bool intersect(double a,double b,double c,double l){
		double B = a*c + a*y0*b - x0*b*b;
		B = (B * B) / (b * b * b * b);
		double C = b*b*(x0*x0 + y0*y0 - l*l) + c*c + 2.0*c*y0*b + y0*y0*b*b;
		C = C / (b * b);
		return (B > C);
	}

	pair <pair <double,double>,double> make_line(pair <double,double> A,pair <double,double> B){
		pair <double,double> n = mp(B.fir - A.fir,B.sec - A.sec);
		n = mp(-n.sec,n.fir);
		double val = -n.fir * A.fir - n.sec * A.sec;
		return mp(n,val);
	}

	bool f(double l){
		for(int i = 0;i < 4;++i){
			pair <pair <double,double>,double> li = make_line(c[i],c[(i + 1) % 4]);
			if(intersect(li.fir.fir,li.fir.sec,li.sec,l)){
				return false;
			}
			return true;
		}
	}

    void solve(){
    	cin>>x0>>y0>>x1>>y1>>x2>>y2;
    	c[0] = mp(x1,y1);
    	c[1] = mp(x1,y2);
    	c[2] = mp(x2,y2);
    	c[3] = mp(x2,y1);
    	double l = 0.0,r = 1e9,ans = 0.0;
    	int lim = 0;
    	for(double mid = (l + r) / 2.0;l <= r and lim <= 1e5;++lim){
    		if(f(mid)){
    			ans = mid;
    			l = mid;
    		} else {
    			r = mid;
    		}
    	}
    	cout<<setprecision(3)<<fixed<<ans;
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
