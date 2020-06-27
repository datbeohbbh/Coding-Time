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

/* Author : Mohamed Ahmed (handle : MohamedAhmed04)
   contest name : IOI 2010 (day 1)
   problem name : Quality of living (IOI 2010-Quality of living)
   problem statement link :
   https://ioi2010.org/Tasks/Day1/Quality_of_Living.shtml
   link to submit from it :
   https://contest.yandex.ru/ioi/contest/570/enter/
   problem description :
   given grid of R rows and C column that contains elements from 1 to R*C
   return minimum median possible of H*W rectangle inside the grid where
   median is numbers that the number of values smaller than it inside the
   H*W rectangle equal to number of values bigger than it.
   H is odd , W is odd
   problem solution :
   first we will make the grid 1-indexed to be easy for us in prefix array that we will
   make and after that we will binary search of possible values of median and now make
   2 prefix arrays so smaller[i][j] is number of elements in rectangle
   (1 , 1) to (i , j) that's < mid and bigger[i][j] is number of elements in rectangle
   (1 , 1) to (i , j) that's > mid and after that we will loop of all possible rectangles of
   size H*W that we can make and make bool t which will be true if number of elements more than mid
   is <= number of elements that less than median and if that condition is true then r will be equal
   to mid-1 as there's answer less than current mid else then the answer is greater than mid.
   note :
   - the rule to know number of smaller elements than mid in current rectangle is :
     smaller[i+H-1][j+W-1] - smaller[i+H-1][j-1] - smaller[i-1][j+W-1] + smaller[i-1][j-1]
     and role for bigger elements than mid is :
     bigger[i+H-1][j+W-1] - bigger[i+H-1][j-1] - bigger[i-1][j+W-1] + bigger[i-1][j-1]
   - if we found an rectangle which mid is the median then ans is min(ans , mid).
   - see comments bellow for more clarification.
*/

namespace task{

const int N = 1e3 + 3;
int a[N][N],smaller[N][N],bigger[N][N];
int n,m,h,w,ans = N*N;

void solve()
{
    cin>>n>>m>>h>>w;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cin>>a[i][j];
        }
    }
    int l = 1,r = n*m;
    for(int mid = (l + r)>>1;l <= r;mid = (l + r)>>1){
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                smaller[i][j] = bigger[i][j] = 0;
            }
        }
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                smaller[i][j] = smaller[i - 1][j] + smaller[i][j - 1] - smaller[i - 1][j - 1] + (a[i][j] < mid);
                bigger[i][j] = bigger[i - 1][j] + bigger[i][j - 1] - bigger[i - 1][j - 1] + (a[i][j] > mid);
            }
        }
        bool f = false;
        for(int i = 1;i + h - 1 <= n;++i){
            for(int j = 1;j + w - 1 <= m;++j){
                int sm = smaller[i + h - 1][j + w - 1] - smaller[i - 1][j + w - 1] - smaller[i + h - 1][j - 1] + smaller[i - 1][j - 1];
                int bg = bigger[i + h - 1][j + w - 1] - bigger[i - 1][j + w - 1] - bigger[i + h - 1][j - 1] + bigger[i - 1][j - 1];
                if(sm >= bg){
                    f = true;
                    if(sm == bg){
                        minimize(ans,mid);
                    }
                }
            }
        }
        if(f){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
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
