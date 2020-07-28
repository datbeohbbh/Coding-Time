#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

template <class T>
using ordered_set = tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

#define rand __rand
mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
template <class T = int>
T rand(T range = numeric_limits <T> :: max()){
    return (T) (generator() % range);
}

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

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 2e5 + 5;
    pii point[N];
    int n;

    class MergeSortTree{
    public:
        vector < vector < pair <int,ll> > > tree;
        vector < vector < ll > > sum;
    public:
        MergeSortTree(int _size){
            tree.resize((_size << 2),vector <pair <int,ll> > ());
            sum.resize((_size << 2),vector <ll> ());

        }
        void buildTree(int l,int r,int node = 1){
            if(l > r){
                return ;
            }
            if(l == r){
                tree[node].emplace_back(make_pair(point[l].second,point[l].first));
                sum[node].emplace_back(point[l].first);
                return;
            }
            int mid = (l + r) >> 1;
            buildTree(l,mid,node << 1);
            buildTree(mid + 1,r,node << 1 | 1);
            tree[node].resize(tree[node << 1].size() + tree[node << 1 | 1].size());
            sum[node].resize(tree[node << 1].size() + tree[node << 1 | 1].size());
            merge(all(tree[node << 1]),all(tree[node << 1 | 1]),tree[node].begin());
            for(int i = 0;i < tree[node].size();++i){
                sum[node][i] = tree[node][i].second;
            }
            for(int i = 1;i < tree[node].size();++i){
                sum[node][i] += sum[node][i - 1];
            }
        }

        ll getSum(int l,int r,int node){
            return sum[node][r] - (l ? sum[node][l - 1] : 0);
        }

        bool chk(int cmp,int x,int y){
            return (cmp ? x >= y : x <= y);
        }

        ll cnt(int cmp,int tl,int tr,pii p,int l,int r,int node = 1){
            if(l > r or tl > tr or r < tl or l > tr){
                return 0;
            }
            if(tl <= l and r <= tr){
                int lo = 0,hi = tree[node].size() - 1;
                int pos = -1;
                for(int mid = (lo + hi) >> 1;lo <= hi;mid = (lo + hi) >> 1){
                    if(chk(cmp,tree[node][mid].first,p.second)){
                        if(!cmp){
                            lo = mid + 1;
                        } else {
                            hi = mid - 1;
                        }
                        pos = mid;
                    } else {
                        if(!cmp){
                            hi = mid - 1;
                        } else {
                            lo = mid + 1;
                        }
                    }
                }
                if(~pos){
                    if(!cmp){
                        return 1LL * (pos + 1) * 1LL * p.first - getSum(0,pos,node);
                    } else {
                        return getSum(pos,tree[node].size() - 1,node) - 1LL * (tree[node].size() - pos) * 1LL * p.first;
                    }
                }
                return 0;
            }
            int mid = (l + r) >> 1;
            ll x = cnt(cmp,tl,tr,p,l,mid,node << 1);
            ll y = cnt(cmp,tl,tr,p,mid + 1,r,node << 1 | 1);
            return x + y;
            //return cnt(cmp,tl,tr,p,l,mid,node << 1) + cnt(cmp,tl,tr,p,mid + 1,r,node << 1 | 1);
        }
    };

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>point[i].first;
        }
        for(int i = 1;i <= n;++i){
            cin>>point[i].second;
        }
        sort(point + 1,point + 1 + n);
        MergeSortTree *mseg = new MergeSortTree(n + 2);
        mseg -> buildTree(1,n);
        ll ans = 0;
        for(int i = 1;i <= n;++i){
            ans += mseg -> cnt(0,1,i - 1,point[i],1,n);
            ans += mseg -> cnt(1,i + 1,n,point[i],1,n);
        }
        cout<<ans / 2LL;
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
