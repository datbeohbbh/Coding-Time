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

    vector < vector <bool> > a;
    vector < vector <Mint> > f;
    int n;

    Mint calc(int mask,int t){
        if(mask == (1 << n) - 1){
            return Mint(1);
        }
        if(t >= 100){
            return Mint(0);
        }
        if(f[t][mask] != Mint(-1)){
            return f[t][mask];
        }
        Mint ret = calc(mask,t + 1);
        for(int i = 0;i < n;++i){
            if(!((mask >> i) & 1)){
                if(a[i][t]){
                    ret += calc(mask | (1 << i),t + 1);
                }
            }
        }
        return (f[t][mask] = ret);
    }

    Mint compute(){
        cin>>n;
        cin.ignore();
        a.clear();
        f.clear();
        a.resize(n + 1,vector <bool>(101, false));
        f.resize(101,vector <Mint> ((1 << n),Mint(-1)));
        for(int i = 0;i < n;++i){
            string s;
            getline(cin,s);
            stringstream ss(s);
            int val;
            while(ss >> val){
                a[i][--val] = true;
            }
        }
        return calc(0,0);
    }

    void solve(){
        int T;
        cin>>T;
        while(T--){
            cout<<compute()<<'\n';
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
