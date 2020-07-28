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

    string compute_1(){
        int x,y;
        cin>>x>>y;
        //return AC((llong)x,(llong)y);
        if(Abs(x) + Abs(y) > 200){
            return AC((llong)x,(llong)y);
        }
        string ans = "";
        int lg = 0;
        while((1 << lg) < (Abs(x) + Abs(y))){
            ++lg;
        }
        int maxx = 1e9;
        lg = 8;
        for(int u = 0;u < (1 << lg);++u){
            for(int v = 0;v < (1 << lg);++v){
                int c_x = 0;
                int c_y = 0;
                string t = "";
                for(int i = 0;i < lg;++i){
                    if(x == c_x and y == c_y){
                        break;
                    }
                    if(!BIT(u,i)){
                        if(!BIT(v,i)){
                            t += "E";
                            c_x += (1 << i);
                        } else {
                            t += "W";
                            c_x -= (1 << i);
                        }
                    } else {
                        if(!BIT(v,i)){
                            t += "N";
                            c_y += (1 << i);
                        } else {
                            t += "S";
                            c_y -= (1 << i);
                        }
                    }
                }
                if(x == c_x and y == c_y and len(t) < maxx){
                    maxx = len(t);
                    ans = t;
                }
            }
        }
        if(maxx == 1e9){
            return "IMPOSSIBLE";
        } else {
            return ans;
        }
    }

    void solve(){
        int T;
        cin>>T;
        for(int t = 1;t <= T;++t){
            cout<<"Case #"<<t<<": "<<compute_1()<<'\n';
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
