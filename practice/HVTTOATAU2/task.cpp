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

const int N=1e5+5;
const char c[]={'A','B','C'};
bool in_aux[N];
stack <int> aux;
int a[N];
vector <pii> ans;
int n;

void solve()
{
    cin>>n;
    for(int i = 1;i <= n;++i){
        cin>>a[i];
    }
    int cur = 1;
    for(int i = 1;i <= n;++i){
        if(in_aux[a[i]]){
            if(!aux.empty() and aux.top() == a[i]){
                ans.pb(mp(1,2));
                aux.pop();
            }
            else
              cout<<"NO",exit(0);
        }
        else{
            while(cur <= n and cur ^ a[i]){
                aux.push(cur);
                in_aux[cur++] = true;
                ans.pb(mp(0,1));
            }
            if(cur > n)
              cout<<"NO",exit(0);
            ans.pb(mp(0,2));
            ++cur;
        }
    }
    cout<<"YES\n";
    for(int i = 0;i < sz(ans);++i)
      cout<<c[ans[i].fir]<<"->"<<c[ans[i].sec]<<'\n';
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
