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
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    class Solver{
        public:
            string c;
            int n;
        public:
            void solve(){
                cin>>n;
                cin>>c;
                for(int i = 0;i < 2;++i){
                    int s = 0;
                    for(int cur = 0;cur < len(c);++cur){
                        int j = cur;
                        while(j < len(c) and c[cur] == c[j]){
                            ++j;
                        }
                        if(c[cur] - 'A' == i){
                            s += (j - cur);
                        } else {
                            s -= (j - cur);
                        }
                        cur = --j;
                    }
                    if(s > 0 and s < 3){
                        cout<<"Y\n";
                        return;
                    }
                }
                cout<<"N\n";
            }
    };
    
    void solve(){
        int T;
        cin>>T;
        for(int tests = 1;tests <= T;++tests){
            cout<<"Case #"<<tests<<": ";
            (new Solver) -> solve();
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".txt","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}

