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

    const int N = 100;
    int k,L;
    llong f[N + 2][N + 2][12];
    vector <llong> vec;

    void calc(int ll,int sum,llong ans = 0){
        if(len(vec) >= k){
            return;
        }
        if(!ll){
            if(!sum){
                vec.emplace_back(ans);
            }
            return;
        }
        for(int d = (ll == L ? 1 : 0);d < 10;++d){
            if(sum - d >= 0){
                calc(ll - 1,sum - d,ans * 10LL + d);
            }
        }
    }

    void solve(){
        cin>>k;
        for(int l = 2;l <= N;++l){
            for(int d = 1;d < 10;++d){
                f[l][1][d] = 1;
            }
            for(int i = 2;i <= l;++i){
                for(int s = 0;s <= 10;++s){
                    for(int d = 0;d < 10;++d){
                        if(s - d >= 0){
                            f[l][i][s] += f[l][i - 1][s - d];
                        }
                    }
                }
            }
        }
        for(int l = 2;l <= N;++l){
            if(k > f[l][l][10]){
                k -= f[l][l][10];
            } else {
                L = l;
                break;
            }
        }
        calc(L,10);
        //cout<<vec[k - 1];
        Mint a = Mint(3);
        Mint b = Mint(2);
        cout<<(a ^= Mint(1) / b);
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
