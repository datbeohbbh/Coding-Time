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

    const llong base[] = {1000000007,1000000087};
    const llong coef[] = {29,31};
    const int N = 250250;
    vector < vector < llong > > pw;
    string s,t;
    int n,m;
    int st = -1,en = -1;

    class Hash{
    public:
        vector < vector < llong > > h;
        int len;
    public:
        Hash(const string &str){
            len = len(str) - 1;
            h.resize(2,vector < llong > (len + 2,0));
            for(int i = 1;i <= len;++i){
                for(int j = 0;j < 2;++j){
                    h[j][i] = (h[j][i - 1] * coef[j] + (llong)(str[i] - 'a' + 1)) % base[j];
                }
            }
        }
        llong getHash(int l,int r,int j) const {
            return (h[j][r] - h[j][l - 1] * pw[j][r - l + 1] + base[j] * base[j]) % base[j];
        }
        pair < llong,llong > getHash(int l,int r) const {
            return {getHash(l,r,0),getHash(l,r,1)};
        }
    };

    void solve(){
        cin>>s>>t;
        n = len(s);
        m = len(t);
        s = " " + s;
        t = " " + t;
        pw.resize(2,vector < llong > (n + 2,0));
        pw[0][0] = pw[1][0] = 1;
        for(int i = 1;i <= n;++i){
            for(int j = 0;j < 2;++j){
                pw[j][i] = (pw[j][i - 1] * coef[j]) % base[j];
            }
        }
        Hash *f = new Hash(s);
        Hash *g = new Hash(t);
        function < bool(int) > ok = [&](const int &k){
            set < pair < llong,llong > > heap;
            bool found = false;
            for(int i = 1;i + k - 1 <= n;++i){
                if(heap.find(f-> getHash(i,i + k - 1)) == heap.end()){
                    heap.insert(f -> getHash(i,i + k - 1));
                }
            }
            for(int i = 1;i + k - 1 <= m;++i){
                if(heap.find(g -> getHash(i,i + k - 1)) != heap.end()){
                    st = i;
                    en = st + k - 1;
                    found = true;
                    break;
                }
            }
            return found;
        };
        for(int l = 1,r = m,mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
            if(ok(mid)){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if(~st and ~en){
            cout<<t.substr(st,en)<<'\n'<<en - st + 1;
        } else {
            cout<<0;
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
