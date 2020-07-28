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

    std::vector<std::pair<int, int>> twos_difference(const std::vector<int> &vec) {
        vector <pair <int,int> > ans;
        vector <int> a = vec;
        map <int,int> vis;
        sort(all(a),greater <int> ());
        for(int i = 0;i < len(a);++i){
            if(vis[a[i] - 2]){
                ans.emplace_back(make_pair(a[i] - 2,a[i]));
            }
            if(vis[a[i] + 2]){
                ans.emplace_back(make_pair(a[i],a[i] + 2));
            }
            vis[a[i]] = true;
        }
        sort(all(ans));
        return ans;
    }

    void solve(){
        int n;
        cin>>n;
        vector <int> vec;
        for(int i = 0;i < n;++i){
            int val;
            cin>>val;
            vec.emplace_back(val);
        }
        vector < pair <int,int> > ans = twos_difference(vec);
        for(auto p : ans){
            cout<<p.first<<' '<<p.second<<'\n';
        }
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