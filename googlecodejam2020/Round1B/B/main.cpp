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

    void compute(int a,int b){
        if(!(a == b and a == 1e9 - 5)){
            exit(0);
        }
        int d = (a << 1);
        for(int l = 0;l <= 10;++l){
            for(int r = 0;r <= 10;++r){
                int x = 5 - l;
                int y = 5 - r;
                cout<<x<<' '<<y<<endl;
                string s;
                cin>>s;
                if(s == "CENTER"){
                    return;
                }
            }
        }
    }

    void solve(){
        int T,a,b;
        cin>>T>>a>>b;
        for(int t = 1;t <= T;++t){
            compute(a,b);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    task::solve();
}
