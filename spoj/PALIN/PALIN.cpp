using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define fn "PALIN"  /// ___FILE_NAME_HERE___
#define rep(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define __rep(c,it) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();it++)

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
    return (x < 0 ? -x : x);
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
    return (ll)x*y%MOD;
}
/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

const int N=1e6+6;
char s[N];
int cnt[30];
int n,ans=0;

void solve()
{
    scanf("%d%s",&n,&s);
    for(int i=0;i<n;i++)
        cnt[s[i]-'A']++;
    int maxOdd=-1,uniIdx=-1;
    for(int i=0;i<26;i++)
        if(cnt[i] & 1)
        {
            if(maxOdd < cnt[i])
               maxOdd=cnt[i],uniIdx=i;
        }
    for(int i=0;i<26;i++)
    {
        if(cnt[i] & 1 and i!=uniIdx)cnt[i]--;
        ans+=cnt[i];
    }
    printf("%d",ans);
}}

int main(void)
{
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
///remember : 1 tap hop cac ki tu co the sap xep lai thanh palindrome khi va chi khi co nhieu nhat 1 ki tu xuat hien le lan
///cac ki tu con lai xuat hien chan lan.
