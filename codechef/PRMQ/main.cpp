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

    const int N = 1e5 + 5;
    const int maxValue = 1e6;
    int n,q;
    vector < vector < pair <int,int> > > li;
    vector <int> prime;
    int e[maxValue + 2];

    class MergeSortTree{
    public:
        vector < vector < pair <int,int> > > st;
        vector < vector < int > > sum;
    public:
        MergeSortTree(int size_tree){
            st.resize((size_tree << 2) | 4,vector < pair < int,int > > ());
            sum.resize((size_tree) << 2 | 4,vector < int > ());
        }
        void buildTree(int l,int r,int node = 1){
            if(l > r){
                return;
            }
            if(l == r){
                for_each(all(li[l]),[&](pair <int,int> &p){
                    st[node].emplace_back(p);
                    sum[node].emplace_back(p.second);
                });
                for(int i = 1;i < len(sum[node]);++i){
                    sum[node][i] += sum[node][i - 1];
                }
                return;
            }
            int mid = (l + r) >> 1;
            buildTree(l,mid,node << 1);
            buildTree(mid + 1,r,node << 1 | 1);
            st[node].resize(len(st[node << 1]) + len(st[node << 1 | 1]));
            sum[node].resize(len(st[node << 1]) + len(st[node << 1 | 1]));
            merge(all(st[node << 1]),all(st[node << 1 | 1]),st[node].begin());
            for(int i = 0;i < len(st[node]);++i){
                sum[node][i] = st[node][i].second;
            }
            for(int i = 1;i < len(sum[node]);++i){
                sum[node][i] += sum[node][i - 1];
            }
        }
        int rsq(int tl,int tr,int value,int l,int r,int node = 1){
            if(l > r or r < tl or l > tr){
                return 0;
            }
            if(tl <= l and r <= tr){
                int lo = 0,hi = len(st[node]) - 1;
                int pos = -1;
                while(lo <= hi){
                    int mid = (lo + hi) >> 1;
                    if(st[node][mid].first <= value){
                        lo = mid + 1;
                        pos = mid;
                    } else {
                        hi = mid - 1;
                    }
                }
                return (~pos ? sum[node][pos] : 0);
            }
            int mid = (l + r) >> 1;
            return rsq(tl,tr,value,l,mid,node << 1) + rsq(tl,tr,value,mid + 1,r,node << 1 | 1);
        }
    };
    MergeSortTree *tree;

    void solve(){
        cin>>n;
        li.resize(n + 2,vector <pair <int,int> > ());
        iota(e,e + 1 + maxValue,0);
        for(int i = 2;i <= maxValue;++i){
            if(e[i] == i){
                prime.emplace_back(i);
            }
            for(int j = 0;j < len(prime) and i * prime[j] <= maxValue;++j){
                e[i * prime[j]] = prime[j];
                if(i % prime[j] == 0){
                    break;
                }
            }
        }
        for(int val,i = 1;i <= n;++i){
            cin>>val;
            for(int k = e[val];k > 1 and val > 1;k = e[val]){
                li[i].emplace_back(make_pair(k,0));
                while(val % k == 0){
                    val /= k;
                    ++li[i].back().second;
                }
            }
            sort(all(li[i]));
        }
        tree = new MergeSortTree(n);
        tree -> buildTree(1,n);
        cin>>q;
        while(q--){
            int l,r,x,y;
            cin>>l>>r>>x>>y;
            cout<<tree -> rsq(l,r,y,1,n) - tree -> rsq(l,r,x - 1,1,n)<<'\n';
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
