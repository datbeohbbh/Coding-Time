//#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//
//using namespace __gnu_pbds;
//using namespace std;
//
//template <class T>
//using ordered_set =
//       tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
/////find_by_order()
/////order_of_key()
//
//template <class T,class U>
//void maximize(T &x,U y)
//{
//    if(x < y)x=y;
//}
//template <class T,class U>
//void minimize(T &x,U y)
//{
//    if(x > y)x=y;
//}
//template <class T>
//T Abs(T x)
//{
//    return (x < (T)0 ? -x : x);
//}
//template <class T>
//T safe_sqrt(T x)
//{
//    return sqrt(max(x,(T)0));
//}
//template <class T,class U,class V>
//T addmod(T x,U k,V MOD)
//{
//    return ((x+k)%MOD + MOD)%MOD;
//}
//template <class T,class U,class V>
//T submod(T x,U k,V MOD)
//{
//    return ((x-k)%MOD + MOD)%MOD;
//}
//template <class T,class U,class V>
//T mul(T x,U y,V MOD)
//{
//    return (long long)x*y%MOD;
//}
//
//#define ll long long
//#define pll pair <ll,ll>
//#define pii pair <int,int>
//#define fir first
//#define sec second
//#define mp make_pair
//#define pb push_back
//#define MASK(i) ((1LL)<<(i))
//#define BIT(x,i) (((x)>>(i))&1)
//#define all(c) (c).begin(),(c).end()
//#define sz(c) (int)((c).size())
//#define fn "test"    ///FILE_NAME_HERE
//
///*------------------------------------------END_OF_TEMPLATE------------------------------------------*/
//
//namespace task{
//
//const int N=2e5;
//int a[N];
//set <pair <ll,int> > heap;
//int n;
//vector <pair <ll,int> > ans;
//
//void solve()
//{
//    cin>>n;
//    for(int i = 1;i <= n;++i)
//       cin>>a[i];
//    for(int i = 1;i <= n;++i)
//       heap.insert(mp(a[i],i));
//    while(sz(heap) >= 2)
//    {
//       set <pair <ll,int> > :: iterator it = heap.begin();
//       ll x = it -> fir;
//       ll y = (++it) -> fir;
//       if(x ^ y)
//       {
//          --it;
//          ans.pb(*it);
//          heap.erase(heap.begin());
//          continue;
//       }
//       heap.erase(heap.begin());
//       heap.insert(mp(2LL*x,it->sec));
//       heap.erase(it);
//    }
//    while(!heap.empty())
//      ans.pb(*heap.begin()),heap.erase(heap.begin());
//    sort(all(ans),[](const pair <ll,int> &x,const pair <ll,int> &y)
//    {
//       return x.sec < y.sec;
//    });
//    cout<<sz(ans)<<'\n';
//    for(auto res : ans)
//      cout<<res.fir<<' ';
//}}
//
//int main(void)
//{
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//    freopen(fn".inp","r",stdin);
//    freopen(fn".out","w",stdout);
//    #endif // ONLINE_JUDGE
//    task::solve();
//}
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
void maximize(T &x,U y)
{
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y)
{
    if(x > y)x=y;
}
template <class T>
T Abs(T x)
{
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x)
{
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD)
{
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD)
{
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD)
{
    return (long long)x*y%MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

const int N = 1e5 + 5;
const ll base = 1e9 + 7;
int a[N];
multiset <pair <ll,ll> > heap;
int n;
ll x;

void solve()
{
    cin>>n>>x;
    ll sum = 0;
    for(int i = 1;i <= n;++i){
        cin>>a[i];
        sum+=1LL*a[i];
    }
    for(int i = 1;i <= n;++i){
        heap.insert(mp(sum - 1LL*a[i],1));
    }
    ll t = 0;
    while(!heap.empty()){
        pll top = *heap.begin();
        t += 1LL*top.fir;
        ll tmp = 0;
        while(!heap.empty()){
            ll gap = (heap.begin() -> fir) - t;
            if(gap != 0)break;
            tmp += (heap.begin() -> sec);
            heap.erase(heap.begin());
        }
        ll k;
        ll cnt = 0;
        for(k = x;k <= tmp;k*=x){
            if(tmp % k)
              break;
            ++cnt;
            if(k > tmp/x)
              break;
        }
        if(cnt <= 0)
          break;
        heap.insert(mp(cnt,tmp / k));
    }
    ll ans = 1;
    minimize(t,sum);
    for(;t > 0;t/=2LL,x = mul(x,x,base))
      if(t & 1)
        ans = mul(ans,x,base);
    cout<<ans;
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
