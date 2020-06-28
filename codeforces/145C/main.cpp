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
    using Type = llong;
    const Type base = (Type)1000000007;
    using Mint = Modular<Type,base>;

    const int N = 1e5 + 5;
    int n,k;
    int a[N];
    Mint fact[N],inv_fact[N];
    Mint f[2000][2000];
    map <int,int> ma;

    Mint coef(int x,int y){
        if(x > y){
            return Mint(0);
        }
        return fact[y] * inv_fact[x] * inv_fact[y - x];
    }

    void solve(){
        int cntLucky = 0;
        int cntUnlucky = 0;
        cin>>n>>k;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            int val = a[i];
            int msk = 0;
            while(val){
                msk |= MASK(val % 10);
                val /= 10;
            }
            if(msk == 16 or msk == 128 or msk == 144){
                ++ma[a[i]];
            } else {
                ++cntUnlucky;
            }
        }
        fact[0] = inv_fact[0] = Mint(1);
        for(int i = 1;i <= n;++i){
            fact[i] = fact[i - 1] * Mint(i);
            inv_fact[i] = Mint(1) / fact[i];
        }
        for(auto c : ma){
            a[++cntLucky] = c.second;
        }
        f[0][0] = Mint(1);
        for(int i = 1;i <= cntLucky;++i){
            f[i][0] = Mint(1);
            for(int j = 1;j <= i;++j){
                f[i][j] += f[i - 1][j] + f[i - 1][j - 1] * Mint(a[i]);
            }
        }
        Mint ans = Mint(0);
        for(int i = 0;i <= cntUnlucky;++i){
            int j = k - i;
            if(j >= 0 and j <= cntLucky){
                ans += coef(i,cntUnlucky) * f[cntLucky][j];
            }
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
