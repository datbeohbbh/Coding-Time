/*#include <bits/stdc++.h>

using namespace std;

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x = y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x = y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1LL)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE
*/
/*----------END_OF_TEMPLATE----------*/
/*
namespace task{

    void calc(){
        int n,m;
        cin>>n>>m;
        vector <llong> a;
        vector < pair <llong,llong> > seg;
        for(int i = 0;i < n;++i){
            string s;
            cin>>s;
            llong mask = 0;
            for(int j = 0;j < m;++j){
                mask |= 1LL * (s[m - j - 1] - '0') * 1LL * MASK(j);
            }
            a.emplace_back(mask);
        }
        sort(all(a));
        if(a[0] != 0){
            seg.emplace_back(make_pair(0,a[0] - 1));
        }
        if(a.back() != MASK(m) - 1){
            seg.emplace_back(make_pair(a.back() + 1,MASK(m) - 1));
        }
        for(int i = 0;i < len(a) - 1;++i){
            llong l = a[i];
            llong r = a[i + 1];
            if(l + 1 <= r - 1){
                seg.emplace_back(make_pair(l + 1,r - 1));
            }
        }
        sort(all(seg));
        llong mid = 1 + ((MASK(m) - 1LL * n - 1) >> 1LL);
        for(int i = 0;i < len(seg);++i){
            llong l = seg[i].first;
            llong r = seg[i].second;
            if(mid > r - l + 1){
                mid -= r - l + 1;
            } else {
                llong ans = l + mid - 1;
                for(int j = 0;j < m;++j){
                    cout<<BIT(ans,m - j - 1);
                }
                cout<<'\n';
                return;
            }
        }
    }

    void solve(){
        int T;
        cin>>T;
        while(T--){
            calc();
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
*/

#include <bits/stdc++.h>

using namespace std;

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x = y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x = y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    const int MAXN = 1e5 + 42;

    map<char, int> to[MAXN];
    int link[MAXN], que[MAXN], sz = 1;

    void add_str(string s, int k)
    {
        int v = 0;
        for(auto c: s)
        {
            if(!to[v][c]) to[v][c] = sz++;
            v = to[v][c];
        }
    }

    void push_links()
    {
        link[0] = -1;
        int st = 0, fi = 1;
        que[0] = 0;
        while(st < fi)
        {
            int v = que[st++];
            for(auto it: to[v])
            {
                int u = it.second;
                int c = it.first;
                int j = link[v];
                while(j != -1 && !to[j][c]){
                    j = link[j];
                }
                if(j != -1) {
                    link[u] = to[j][c];
                }
                que[fi++] = u;
            }
        }
        for(int i = 0;i < sz;++i){
            cout<<i<<' '<<link[i]<<'\n';
        }
    }

    void solve(){
        add_str("dabce",1);
        add_str("abc",1);
        add_str("bc",1);
        push_links();
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
