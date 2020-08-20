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

    void solve(){
        int T;
        cin>>T;
        for(int tests = 1;tests <= T;++tests){
            string s;
            cin>>s;
            int cntB = 0,cntD = 0;
            for_each(s.begin(),s.end(),[&](const char &c){
                    cntB += c == 'B';
                    cntD += c == '.';
            });
            cout<<"Case #"<<tests<<": ";
            cout<<(cntD and cntB >= cntD ? "Y\n" : "N\n");
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

