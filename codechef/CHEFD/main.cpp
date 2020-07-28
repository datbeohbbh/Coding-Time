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

    const int p[] = {2,3,5};
    const int N = 1e5 + 5;
    int a[N];
    int n,m;

    class FenwickTree{
    public:
        vector <int> tree;
        int num_node;
    public:
        FenwickTree(int num_node){
            this -> num_node = num_node;
            tree.resize(num_node + 2,0);
        }
        ~FenwickTree(){
            tree.clear();
            num_node = 0;
        }
        void update(int node,int val){
            for(;node <= num_node;node += node & (-node)){
                tree[node] += val;
            }
        }
        void update(int l,int r,int val){
            update(l,val);
            update(r + 1,-val);
        }
        int rsq(int node){
            int ret = 0;
            for(;node > 0;node -= node & (-node)){
                ret += tree[node];
            }
            return ret;
        }
    };

    void solve(){
        cin>>n;
        FenwickTree* *fwt = new FenwickTree* [3];
        for(int i = 0;i < 3;++i){
            fwt[i] = new FenwickTree(n);
        }
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            for(int j = 0;j < 3;++j){
                int c = 0;
                while(a[i] % p[j] == 0){
                    a[i] /= p[j];
                    ++c;
                }
                fwt[j] -> update(i,i,c);
            }
        }
        cin>>m;
        while(m--){
            int type,l,r,pp;
            cin>>type>>l>>r;
            if(type == 1){
                cin>>pp;
                int idx = (pp == 2 ? 0 : pp == 3 ? 1 : 2);
                fwt[idx] -> update(l,r,-1);
            } else {
                a[l] = r;
                for(int j = 0;j < 3;++j){
                    int c = 0;
                    while(a[l] % p[j] == 0){
                        a[l] /= p[j];
                        ++c;
                    }
                    int old_val = fwt[j] -> rsq(l);
                    fwt[j] -> update(l,l,-old_val + c);
                }
            }
        }
        auto fastExp = [&](llong x,int h){
            llong ret = 1;
            for(;h > 0;h >>= 1,x = x * x){
                if(h & 1){
                    ret *= x;
                }
            }
            return ret;
        };
        for(int i = 1;i <= n;++i){
            llong ans = 1LL * a[i];
            for(int j = 0;j < 3;++j){
                int h = fwt[j] -> rsq(i);
                if(h > 0){
                    ans *= fastExp(p[j],h);
                }
            }
            cout<<ans<<' ';
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
