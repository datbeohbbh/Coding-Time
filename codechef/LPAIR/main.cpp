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

    const int N = 1e5 + 5;
    int n;
    pair <int,int> p[N];

    class FenwickTree{
    public:
        vector <int> ft;
        int szt;
    public:
        FenwickTree(int szt){
            this -> szt = szt;
            ft.resize(szt + 5,0);
        }
        int rsq(int node){
            int ret = 0;
            for(;node > 0;node -= node & (-node)){
                ret += ft[node];
            }
            return ret;
        }
        void update(int node){
            for(;node <= szt;node += node & (-node)){
                ft[node] += 1;
            }
        }
    };

    void solve(){
        cin>>n;
        vector <int> compress;
        for(int i = 1;i <= n;++i){
            cin>>p[i].first>>p[i].second;
            compress.emplace_back(p[i].first);
            compress.emplace_back(p[i].second);
        }
        sort(all(compress));
        compress.erase(unique(all(compress)),compress.end());
        for(int i = 1;i <= n;++i){
            p[i].first = lower_bound(all(compress),p[i].first) - compress.begin() + 1;
            p[i].second = lower_bound(all(compress),p[i].second) - compress.begin() + 1;
        }
        sort(p + 1,p + 1 + n);
        FenwickTree *fwt = new FenwickTree(len(compress) + 2);
        llong ans = 0;
        for(int i = n;i >= 1;--i){
            ans += 1LL * fwt -> rsq(p[i].second);
            fwt -> update(p[i].second);
        }
        cout<<ans;
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
