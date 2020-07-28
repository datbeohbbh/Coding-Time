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

#define ll long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    using MOD_TYPE = long long; // or int
    const MOD_TYPE MOD = (MOD_TYPE) 998244353;

    template<class T>
    struct Modular {
    private :
        T val;
    public:
        Modular() {
            val = 0;
        }

        Modular(const T &new_val) {
            val = new_val % MOD;
            val = (val >= MOD ? val - MOD : (val < 0 ? val + MOD : val));
        }

        Modular<T>& operator=(const Modular<T> &x) {
            this -> val = x.val;
            return *this;
        }

        friend bool operator==(const Modular<T> &x, const Modular<T> &y) {
            return x . val == y . val;
        }

        friend bool operator!=(const Modular<T> &x, const Modular<T> &y) {
            return !(x == y);
        }

        friend bool operator<(const Modular<T> &x, const Modular<T> &y) {
            return x . val < y . val;
        }

        friend bool operator>(const Modular<T> &x, const Modular<T> &y) {
            return x . val > y . val;
        }

        friend bool operator<=(const Modular<T> &x, const Modular<T> &y) {
            return !(x > y);
        }

        friend bool operator>=(const Modular<T> &x, const Modular<T> &y) {
            return !(x < y);
        }

        friend ostream &operator<<(ostream &out, const Modular<T> &x) {
            return out << x . val;
        }

        friend istream &operator>>(istream &in, Modular<T> &x) {
            return in >> x . val;
        }

        Modular<T> &operator+=(const Modular<T> &x) {
            val = (val % MOD + x . val % MOD);
            val -= (val > MOD ? MOD : 0);
            return *this;
        }

        Modular<T> &operator-=(const Modular<T> &x) {
            val = (val % MOD - x . val % MOD);
            val += (val < 0 ? MOD : 0);
            return *this;
        }

        Modular<T> operator-() const {
            return Modular<T> (0) - *this;
        }

        Modular<T> &operator++() {
            return (*this += Modular<T> (1));
        }

        Modular<T> &operator--() {
            return (*this -= Modular<T> (1));
        }

        Modular<T> &operator*=(const Modular<T> &x) {
            val = (long long) (val % MOD) * (x . val % MOD) % MOD;
            return *this;
        }

        Modular<T> &operator^=(T h) {
            Modular<T> res = Modular<T> (1);
            Modular<T> x = *this;
            for (; h > 0; x = x * x, h /= (T) 2) {
                if (h & 1) {
                    res *= x;
                }
            }
            (*this = res);
            return *this;
        }

        Modular<T> &operator^=(Modular<T> h) {
            return (*this ^= h . val);
        }

        Modular<T> operator^(T h) {
            return (Modular<T> (*this) ^= h);
        }

        Modular<T> operator^(Modular<T> h) {
            return (Modular<T> (*this) ^= h . val);
        }

        Modular<T> &operator/=(Modular<T> &x) {
            return (*this *= (x ^ (MOD - 2)));
        }

        Modular<T> operator+(const Modular<T> &x) {
            return (Modular<T> (*this) += x);
        }

        Modular<T> operator-(const Modular<T> &x) {
            return (Modular<T> (*this) -= x);
        }

        Modular<T> operator*(const Modular<T> &x) {
            return (Modular<T> (*this) *= x);
        }

        Modular<T> operator/(Modular<T> x) {
            return (Modular<T> (*this) /= x);
        }
    };

    using mod_t = Modular<MOD_TYPE>;

    const int N = 2e5 + 5;
    mod_t fact[N],inv_fact[N];
    int n,m;

    void solve(){
        cin>>n>>m;
        if(n - 1 > m){
            cout<<0,exit(0);
        }
        fact[0] = inv_fact[0] = mod_t(1);
        for(int i = 1;i <= m;++i){
            fact[i] = fact[i - 1] * mod_t(i);
            inv_fact[i] = mod_t(1) / fact[i];
        }
        auto coef = [&](const int &u,const int &v){
            return fact[u] * inv_fact[v] * inv_fact[u - v];
        };
        cout<<(coef(m,n - 1) * (mod_t(2) ^ (n - 3)) * mod_t(n - 2))<<'\n';
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