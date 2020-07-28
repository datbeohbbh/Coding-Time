
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

template <class T>
using ordered_set = tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

#define rand __rand
mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
template <class T = int>
T rand(T range = numeric_limits <T> :: max()){
    return (T) (generator() % range);
}

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

#define type_of_base long long
// or int

const type_of_base base = (type_of_base)(1e9 + 7);

template <class T>
struct Modular{
    T val;
    Modular(){
        val = 0;
    }
    Modular(const T &new_val){
        val = new_val % base;
        val = (val >= base ? val - base : (val < 0 ? val + base : val));
    }
    void operator = (const Modular <T> &x){
        val = x.val % base;
    }
    friend bool operator == (const Modular <T> &x,const Modular <T> &y){
        return x.val == y.val;
    }
    friend bool operator != (const Modular <T> &x,const Modular <T> &y){
        return !(x == y);
    }
    friend bool operator < (const Modular <T> &x,const Modular <T> &y){
        return x.val < y.val;
    }
    friend bool operator > (const Modular <T> &x,const Modular <T> &y){
        return x.val > y.val;
    }
    friend bool operator <= (const Modular <T> &x,const Modular <T> &y){
        return !(x > y);
    }
    friend bool operator >= (const Modular <T> &x,const Modular <T> &y){
        return !(x < y);
    }
    friend ostream& operator << (ostream &out,const Modular <T> &x){
        return out << x.val;
    }
    friend istream& operator >> (istream &in,Modular <T> &x){
        return in >> x.val;
    }
    Modular <T> operator += (const Modular <T> &x){
        val = (val % base + x.val % base);
        val -= (val > base ? base : 0);
        return *this;
    }
    Modular <T> operator -= (const Modular <T> &x){
        val = (val % base - x.val % base);
        val += (val < 0 ? base : 0);
        return *this;
    }
    Modular <T> operator + (const Modular <T> &x){
        return (*this += x);
    }
    Modular <T> operator - (const Modular <T> &x){
        return (*this -= x);
    }
    Modular <T> operator - () const {
        return Modular <T> (0) - *this;
    }
    Modular <T> operator ++ (){
        return (*this += Modular <T> (1));
    }
    Modular <T> operator -- (){
        return (*this -= Modular <T> (1));
    }
    Modular <T> operator *= (const Modular <T> &x){
        val = ((val % base) * (x.val % base)) % base;
        return *this;
    }
    Modular <T> operator * (const Modular <T> &x){
        return (*this *= x);
    }
    Modular <T> operator ^= (T h){
        Modular <T> res = Modular <T> (1);
        Modular <T> x = *this;
        for(;h > 0;x = x * x,h /= (T)2){
            if(h & 1){
                res *= x;
            }
        }
        //*this = res;
        return res;
    }
    Modular <T> operator ^ (T h){
        return (*this ^= h);
    }
    Modular <T> operator ^= (Modular <T> h){
        return (*this ^= h.val);
    }
    Modular <T> operator ^ (Modular <T> h){
        return (*this ^= h.val);
    }
    Modular <T> operator /= (Modular <T> x){
        return (*this *= (x ^ (base - 2)));
    }
    Modular <T> operator / (Modular <T> x){
        return (*this /= x);
    }
};

#define mod_t Modular <type_of_base>

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 1e5 + 5;
    string s;
    int n,k;
    mod_t ans = 0;

    void solve(){
       /* cin>>s>>k;
        n = s.size();
        mod_t inv = mod_t (1) / ((mod_t (2) ^ n) - 1);
        mod_t x = ((mod_t (2) ^ n) ^ k) - 1;
        for(int i = 0;i < n;++i){
            if(s[i] != '0' and s[i] != '5')continue;
            mod_t pw = (mod_t (2) ^ i);
            mod_t mul = pw * x * inv;
            ans += mul;
        }
        cout<<ans;*/
       mod_t x = 2;
       mod_t y =  (mod_t(1) / x) * (x ^ 5) ;
       cout<<y<<'\n';
       mod_t z = (x ^ 5) * y;
       z /= (x ^ y);
       cout<<z<<'\n';
       mod_t xx = 3;
       mod_t yy = 4;
       mod_t zz = 144;
       cout<<zz / ((xx * yy) ^ 2)<<'\n';
       cout<<xx<<' '<<yy<<' '<<zz;
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


