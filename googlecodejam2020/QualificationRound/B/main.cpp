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

    void compute(int test){
        string s,ans = "";
        cin>>s;
        int n = len(s);
        vector <int> open(n + 2,0);
        vector <int> close(n + 2,0);
        set < pair <int,int> > val[10];
        for(int i = 0;i < n;++i){
            int l = i;
            int r = i;
            while(l >= 0 and s[l] -'0' >= s[i] - '0'){
                --l;
            }
            while(r < n and s[r] - '0' >= s[i] - '0'){
                ++r;
            }
            ++l,--r;
            val[s[i] - '0'].insert(make_pair(l,r));
        }
        //val[0].insert(make_pair(-1,n));
        for(int i = 1;i < 10;++i){
            for(pair <int,int> p : val[i]){
                int subs = 0;
                if(p.first - 1 >= 0){
                    maximize(subs,s[p.first - 1] - '0');
                }
                if(p.second + 1 < n){
                    maximize(subs,s[p.second + 1] - '0');
                }
                for(int j = 1;j <= i - subs;++j){
                    ++open[p.first];
                    ++close[p.second];
                }
            }
        }
        for(int i = 0;i < n;++i){
            for(int j = 1;j <= open[i];++j){
                ans += "(";
            }
            ans += s[i];
            for(int j = 1;j <= close[i];++j){
                ans += ")";
            }
        }
        cout<<"Case #"<<test<<":"<<" "<<ans<<'\n';
    }

    void solve(){
        int numTest;
        cin>>numTest;
        for(int test = 1;test <= numTest;++test){
            compute(test);
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
