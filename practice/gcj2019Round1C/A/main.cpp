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

    char win[1000][1000];
    char lose[1000];

    void compute(){
        int n;
        cin>>n;
        vector <string> c;
        for(int i = 1;i <= n;++i){
            string s;
            cin>>s;
            c.emplace_back(s);
        }
        string ans = "";
        for(int j = 0;j <= 500;++j){
            vector <char> ve;
            for(int i = 0;i < len(c);++i){
                ve.emplace_back(c[i][j % len(c[i])]);
            }
            sort(all(ve));
            ve.erase(unique(all(ve)),ve.end());
            if(len(ve) == 3){
                cout<<"IMPOSSIBLE";
                return;
            }
            if(len(ve) == 1){
                ans += lose[ve.front()];
                cout<<ans;
                return ;
            } else {
                ans += win[ve[0]][ve[1]];
                vector <string> nw;
                for(int i = 0;i < len(c);++i){
                    if(c[i][j % len(c[i])] == win[ve[0]][ve[1]]){
                        nw.emplace_back(c[i]);
                    }
                }
                swap(c,nw);
            }
        }
        cout<<"IMPOSSIBLE";
    }

    void solve(){
        int T;
        cin>>T;
        lose['R'] = 'P';
        lose['S'] = 'R';
        lose['P'] = 'S';
        win['R']['P'] = win['P']['R'] = 'P';
        win['R']['S'] = win['S']['R'] = 'R';
        win['P']['S'] = win['S']['P'] = 'S';
        for(int t = 1;t <= T;++t){
            cout<<"Case #"<<t<<": ";
            compute();
            cout<<'\n';
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
