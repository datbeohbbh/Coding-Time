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

    int candlesBurning(int x, int pn, int p){
        int tmp = pn;
        int cc = 0;
        int u = 0;
        int dd = 0;
        while(tmp > 0){
            cc += tmp * x;
            dd += x;
            u += (tmp % p);
            tmp /= p;
            if(u >= p){
                tmp += (u / p);
                u %= p;
            }
        }
        if(u >= p){
            tmp += (u / p);
            cc += tmp * x;
            dd += x;
            u %= p;
        }
        return cc  - dd;
    }

    void solve(){
        int x,pn,p;
        cin>>x>>pn>>p;
        cout<<candlesBurning(x, pn,  p);
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
