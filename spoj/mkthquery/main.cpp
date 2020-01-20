#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set =
tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x=y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x){
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD){
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 1e5 + 5;
    int a[N];
    int b[N];
    int value[N];
    int n,q;

    struct Vertice{
        Vertice *left,*right;
        int cnt,sum;
        Vertice(int _cnt):cnt(_cnt),sum(_cnt),left(nullptr),right(nullptr){}
        Vertice(Vertice *_left,Vertice *_right):left(_left),right(_right),sum(0){
            if(_left)sum += _left -> sum;
            if(_right)sum += _right -> sum;
        }
    };

    Vertice* buildTree(int l,int r){
        if(l == r){
            return new Vertice(0);
        }
        int mid = (l + r) >> 1;
        return new Vertice(buildTree(l,mid),buildTree(mid + 1,r));
    }

    Vertice* updateNode(Vertice *cur,int pos,int l,int r){
        if(l > pos or r < pos or l > r){
            return new Vertice(0);
        }
        if(l == r){
            return new Vertice(cur -> cnt + 1);
        }
        int mid = (l + r) >> 1;
        if(pos <= mid){
            return new Vertice(updateNode(cur -> left,pos,l,mid),cur -> right);
        } else {
            return new Vertice(cur -> left,updateNode(cur -> right,pos,mid + 1,r));
        }
    }
    int getKthNumber(Vertice *cur_left,Vertice *cur_right,int l,int r,int k){
        if(l == r){
            return l;
        }
        int f = cur_right -> left -> sum - cur_left -> left -> sum;
        int mid = (l + r) >> 1;
        if(f >= k){
            return getKthNumber(cur_left -> left,cur_right -> left,l,mid,k);
        } else {
            return getKthNumber(cur_left -> right,cur_right -> right,mid + 1,r,k - f);
        }
    }
    Vertice* *root;

    void solve(){
        cin>>n>>q;
        vector <int> ve;
        for(int i = 0;i < n;++i){
            cin>>a[i];
            ve.emplace_back(a[i]);
        }
        sort(all(ve));
        ve.erase(unique(all(ve)),ve.end());
        for(int i = 0;i < n;++i){
            b[i] = lower_bound(all(ve),a[i]) - ve.begin();
            value[b[i]] = a[i];
        }
        root = new Vertice* [n + 1];
        Vertice* null = buildTree(0,n - 1);
        for(int i = 0;i < n;++i){
            root[i] =  updateNode((!i ? null : root[i - 1]),b[i],0,n - 1);
        }
        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            --l,--r;
            int pos = getKthNumber(l == 0 ? null : root[l - 1],root[r],0,n - 1,k);
            cout<<value[pos]<<'\n';
        }
    }}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
#endif // ONLINE_JUDGE
    task::solve();
}

