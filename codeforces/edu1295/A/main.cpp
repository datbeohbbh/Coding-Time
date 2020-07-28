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

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    using MOD_TYPE = long long; // or int
    template<class T,MOD_TYPE MOD = (MOD_TYPE)1000000007> class Modular {
    private :
        T value;
    public:
        Modular () {
            value = 0;
        }

        Modular (const T &new_value) {
            value = new_value % MOD;
            value = (value >= MOD ? value - MOD : (value < 0 ? value + MOD : value));
        }

        Modular<T> &operator= (const Modular<T> &x) {
            this -> value = x . value;
            return *this;
        }

        friend bool operator== (const Modular<T> &x, const Modular<T> &y) {
            return x . value == y . value;
        }

        friend bool operator!= (const Modular<T> &x, const Modular<T> &y) {
            return !(x == y);
        }

        friend bool operator< (const Modular<T> &x, const Modular<T> &y) {
            return x . value < y . value;
        }

        friend bool operator> (const Modular<T> &x, const Modular<T> &y) {
            return x . value > y . value;
        }

        friend bool operator<= (const Modular<T> &x, const Modular<T> &y) {
            return !(x > y);
        }

        friend bool operator>= (const Modular<T> &x, const Modular<T> &y) {
            return !(x < y);
        }

        friend ostream &operator<< (ostream &out, const Modular<T> &x) {
            return out << x . value;
        }

        friend istream &operator>> (istream &in, Modular<T> &x) {
            return in >> x . value;
        }

        Modular<T> &operator+= (const Modular<T> &x) {
            value = (value % MOD + x . value % MOD);
            value -= (value > MOD ? MOD : 0);
            return *this;
        }

        Modular<T> &operator-= (const Modular<T> &x) {
            value = (value % MOD - x . value % MOD);
            value += (value < 0 ? MOD : 0);
            return *this;
        }

        Modular<T> operator- () const {
            return Modular<T>(0) - *this;
        }

        Modular<T> &operator++ () {
            return (*this += Modular<T>(1));
        }

        Modular<T> &operator-- () {
            return (*this -= Modular<T>(1));
        }

        Modular<T> &operator*= (const Modular<T> &x) {
            value = (long long) (value % MOD) * (x . value % MOD) % MOD;
            return *this;
        }

        Modular<T> &operator^= (T h) {
            Modular<T> res = Modular<T>(1);
            Modular<T> x = *this;
            for (; h > 0; x = x * x, h /= (T) 2) {
                if (h & 1) {
                    res *= x;
                }
            }
            (*this = res);
            return *this;
        }

        Modular<T> &operator^= (Modular<T> h) {
            return (*this ^= h . value);
        }

        Modular<T> operator^ (T h) {
            return (Modular<T>(*this) ^= h);
        }

        Modular<T> operator^ (Modular<T> h) {
            return (Modular<T>(*this) ^= h . value);
        }

        Modular<T> &operator/= (Modular<T> &x) {
            return (*this *= (x ^ (MOD - 2)));
        }

        Modular<T> operator+ (const Modular<T> &x) {
            return (Modular<T>(*this) += x);
        }

        Modular<T> operator- (const Modular<T> &x) {
            return (Modular<T>(*this) -= x);
        }

        Modular<T> operator* (const Modular<T> &x) {
            return (Modular<T>(*this) *= x);
        }

        Modular<T> operator/ (Modular<T> x) {
            return (Modular<T>(*this) /= x);
        }
    };
    using mod_t = Modular<MOD_TYPE>;

    void solve(){
        mod_t a = 2;
        mod_t b = 3;
        mod_t c = 4;
        cout<<(a ^ mod_t(64))<<'\n';
        cout<<(b * c) / a<<'\n';
        cout<<b<<'\n';
        cout<<(((b += c) - a) * 2) / 5<<'\n';
        b = (a ^ 2) / c;
        cout<<b<<'\n';
        cout<<a<<' '<<b<<' '<<c<<'\n';
        a = b = c = 2;
        cout<<a<<' '<<b<<' '<<c<<'\n';
        ++b;
        --a;
        cout<<a<<' '<<b<<' '<<c<<'\n';
        cout<<(((a += b) * 2) = c) * 12<<'\n';
        cout<<((a = c))<<'\n';
        cout<<a<<'\n';
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
