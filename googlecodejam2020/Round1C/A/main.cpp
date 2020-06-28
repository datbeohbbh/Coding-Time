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

    void compute(){
        int x,y;
        string m;
        cin>>x>>y>>m;
        set < pair < pair <int,int> ,int > > heap;
        int ans = 1e9;
        heap.insert(make_pair(make_pair(x,y),0));
        for(int i = 0;i < len(m);++i){
            if(m[i] == 'N'){
                y += 1;
                heap.insert(make_pair(make_pair(x,y),i + 1));
            }
            if(m[i] == 'S'){
                y -= 1;
                heap.insert(make_pair(make_pair(x,y),i + 1));
            }
            if(m[i] == 'W'){
                x -= 1;
                heap.insert(make_pair(make_pair(x,y),i + 1));
            }
            if(m[i] == 'E'){
                x += 1;
                heap.insert(make_pair(make_pair(x,y),i + 1));
            }
        }
        for(auto p : heap){
            int lim = p.second;
            if(Abs(p.first.first) + Abs(p.first.second) <= lim){
                minimize(ans,max(Abs(p.first.first) + Abs(p.first.second),lim));
            }
        }
        if(ans == 1e9){
            cout<<"IMPOSSIBLE"<<'\n';
        } else {
            cout<<ans<<'\n';
        }
    }

    void solve(){
        int T;
        cin>>T;
        for(int t = 1;t <= T;++t){
            cout<<"Case #"<<t<<": ";
            compute();
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
