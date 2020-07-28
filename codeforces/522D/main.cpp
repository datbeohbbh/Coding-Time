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

    const int N = 5e5 + 5;
    const int inf = 1e9;
    int n,m;
    int a[N],next[N];
    vector <int> compress;

    class MergeSortTree{
    public:
        vector < vector < pair <int,int> > > tree;
        vector < vector <int> > minpref;
    public:
        MergeSortTree(int szt){
            tree.resize((szt << 2) + 10,vector < pair <int,int> > ());
            minpref.resize((szt << 2) + 10,vector <int> ());
        }
        void buildTree(int l,int r,int node = 1){
            if(l > r){
                return ;
            }
            if(l == r){
                tree[node].emplace_back(make_pair(next[l],next[l] - l));
                minpref[node].emplace_back(next[l] - l);
                return ;
            }
            int mid = (l + r) >> 1;
            buildTree(l,mid,node << 1);
            buildTree(mid + 1,r,node << 1 | 1);
            tree[node].resize(len(tree[node << 1]) + len(tree[node << 1 | 1]));
            merge(all(tree[node << 1]),all(tree[node << 1 | 1]),tree[node].begin());
            for(pair <int,int> value : tree[node]){
                minpref[node].emplace_back(value.second);
            }
            for(int i = 1;i < len(minpref[node]);++i){
                minimize(minpref[node][i],minpref[node][i - 1]);
            }
        }
        int compute(int ll,int rr,int l,int r,int node = 1){
            if(l > r or r < ll or l > rr){
                return inf;
            }
            if(ll <= l and r <= rr){
                int lo = 0;
                int hi = len(tree[node]) - 1;
                int pos = -1;
                while(lo <= hi){
                    int mid = (lo + hi) >> 1;
                    if(tree[node][mid].first <= rr){
                        pos = mid;
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                if(~pos){
                    return minpref[node][pos];
                } else {
                    return inf;
                }
            }
            int mid = (l + r) >> 1;
            return min(compute(ll,rr,l,mid,node << 1),compute(ll,rr,mid + 1,r,node << 1 | 1));
        }
    };

    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            compress.emplace_back(a[i]);
        }
        sort(all(compress));
        compress.erase(unique(all(compress)),compress.end());
        for(int i = 1;i <= n;++i){
            a[i] = lower_bound(all(compress),a[i]) - compress.begin() + 1;
        }
        vector <int> vis(n + 2,false);
        for(int i = n;i >= 1;--i){
            if(!vis[a[i]]){
                next[i] = n + 1;
            } else {
                next[i] = vis[a[i]];
            }
            vis[a[i]] = i;
        }
        MergeSortTree *mseg = new MergeSortTree(n);
        mseg -> buildTree(1,n);
        while(m--){
            int l,r;
            cin>>l>>r;
            int ans = mseg -> compute(l,r,1,n);
            cout<<(ans == inf ? -1 : ans)<<'\n';
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
