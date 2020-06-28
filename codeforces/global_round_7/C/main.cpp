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

    template<class T,T MOD>
    class Modular {
    private :
        T value;
    public :
        using modType = Modular <T,MOD>;
    public:
        Modular <T,MOD> () {
            value = 0;
        }

        explicit Modular<T,MOD> (const T &new_value) {
            value = new_value % MOD;
            value = (value >= MOD ? value - MOD : (value < 0 ? value + MOD : value));
        }

        modType &operator= (const modType &other) {
            value = other.value;
            return *this;
        }

        bool operator == (const modType &other) const {
            return value == other.value;
        }

        bool operator!= (const modType &other) const {
            return !(value == other.value);
        }

        bool operator< (const modType &other) const {
            return value < other.value;
        }

        bool operator> (const modType &other) const {
            return value > other.value;
        }

        bool operator<= (const modType &other) const {
            return !(value > other.value);
        }

        bool operator>= (const modType &other) const {
            return !(value < other.value);
        }

        friend ostream &operator<< (ostream &out, const modType &other) {
            return out << other.value;
        }

        friend istream &operator>> (istream &in, modType &other) {
            return in >> other.value;
        }

        modType &operator+= (const modType &x) {
            value = (value % MOD + x . value % MOD);
            value -= (value > MOD ? MOD : 0);
            return *this;
        }

        modType &operator-= (const modType &x) {
            value = (value % MOD - x . value % MOD);
            value += (value < 0 ? MOD : 0);
            return *this;
        }

        modType operator- () const {
            return modType(0) - *this;
        }

        modType &operator++ () {
            return (*this += modType(1));
        }

        modType &operator-- () {
            return (*this -= modType(1));
        }

        modType& operator *=(const modType &x) {
            value = (long long) (value % MOD) * (x . value % MOD) % MOD;
            return *this;
        }

        modType& operator^= (T h) {
            modType res = modType(1);
            modType x = *this;
            for (; h > 0; x = x * x, h /= (T) 2) {
                if (h & 1) {
                    res *= x;
                }
            }
            (*this = res);
            return *this;
        }

        modType& operator^= (modType h) {
            return (*this ^= h . value);
        }

        modType operator^ (modType h) const {
            return (modType(*this) ^= h . value);
        }

        modType &operator/= (const modType &x) {
            return (*this *= (x ^ modType(MOD - 2)));
        }

        modType operator+ (const modType &x) {
            return (modType(*this) += x);
        }

        modType operator- (const modType &x) {
            return (modType(*this) -= x);
        }

        modType operator* (const modType &x) {
            return (modType(*this) *= x);
        }

        modType operator/ (modType x) {
            return (modType(*this) /= x);
        }
    };
    using Type = int;
    const Type base = (Type)1000000007;
    using Mint = Modular<Type,base>;

    /*const int N = 2e5 + 5;
    int n,k;
    int p[N],pos[N];

    void solve(){
        cin>>n>>k;
        llong sum = 0;
        for(int i = 1;i <= n;++i){
            cin>>p[i];
            pos[p[i]] = i;
        }
        vector <int> ve;
        int val = n;
        for(int i = k;i > 0;--i){
            sum += (llong)val;
            ve.emplace_back(pos[val--]);
        }
        sort(all(ve));
        Mint ans = 1;
        for(int i = 1;i < len(ve);++i){
            Mint gap = Mint(ve[i] - ve[i - 1]);
            ans *= gap;
        }
        cout<<sum<<' '<<ans;
    }*/
    const int N = 2e5 + 5;
    Mint fact[N],inv_fact[N];
    int n,m;

    void solve(){
        cin>>n>>m;
        if(n - 1 > m){
            cout<<0,exit(0);
        }
        fact[0] = inv_fact[0] = Mint(1);
        for(int i = 1;i <= m;++i){
            fact[i] = fact[i - 1] * Mint(i);
            inv_fact[i] = Mint(1) / fact[i];
        }
        auto coef = [&](const int &u,const int &v){
            return fact[u] * inv_fact[v] * inv_fact[u - v];
        };
        Mint ans = Mint(1);
        cout<<(coef(m,n - 1) * (Mint(2) ^ Mint(n - 3)) * Mint(n - 2))<<'\n';
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGmod_t xx = 2;E
    task::solve();
}
