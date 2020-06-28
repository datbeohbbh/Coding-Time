#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set = tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

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
template <class T>
T safe_sqrt(T x){
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD){
    return ((x + k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x - k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}
template <class T>
struct Modular{
    const T base = (T)(1e9 + 7);
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
        return (x < y) or (x == y);
    }
    friend bool operator >= (const Modular <T> &x,const Modular <T> &y){
        return (x > y) or (x == y);
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
        val =(val % base - x.val % base);
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
        for(;h > 0;x =x * x,h /= (T)2){
            if(h & 1){
                res *= x;
            }
        }
        *this = res;
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
    Modular <T> operator /= (Modular <T> &x){
        return (*this *= (x ^ (base - 2)));
    }
    Modular <T> operator / (Modular <T> &x){
        return (*this /= x);
    }
};
#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

class B;

class A{
    friend class B;
private:
    int a;
    void set(int b){
        a = b;
        cout<<a + 1;
    }
};

class B{
public:
    void work(int val){
        A x;
        x.set(val);
    }
};

namespace task{

    void solve(){
        B b;
        b.work(100);
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