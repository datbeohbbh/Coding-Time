#include <bits/stdc++.h>
#include <bit>

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
    vector < int > par;
    vector < pair < int,int > > edges;
    vector < vector < int > > p;
    vector < tuple < char,int,int > > queries;
    vector < bool > del;
    vector < llong > sum;
    set < pair < llong,int > , greater < pair < llong,int > > > heap;
    int n,q,m;

    int findp(int u){
        return (par[u] == u ? u : par[u] = findp(par[u]));
    }

    void join(int u,int v){
        u = findp(u),v = findp(v);
        if(u == v){
            return ;
        }
        heap.erase(heap.find({sum[v],v}));
        heap.erase(heap.find({sum[u],u}));
        heap.insert({sum[u] += sum[v],par[v] = u});
    }

    void solve(){
        cin>>n>>m>>q;
        p.resize(n,vector < int > ());
        sum.resize(n,0);
        for(int i = 0;i < n;++i){
            int val;
            cin>>val;
            p[i].emplace_back(val);
        }
        edges.resize(m,{0,0});
        del.resize(m,false);
        for(int i = 0;i < m;++i){
            cin>>edges[i].first>>edges[i].second;
            --edges[i].first;
            --edges[i].second;
        }
        for(int i = 0;i < q;++i){
            char op;
            cin>>op;
            if(op == 'D'){
                int k;
                cin>>k; --k;
                queries.emplace_back(make_tuple(op,k,-1));
                del[k] = true;
            } else {
                int a,x;
                cin>>a>>x; --a;
                queries.emplace_back(make_tuple(op,a,x));
                p[a].emplace_back(x);
            }
        }
        par.resize(n);
        iota(all(par),0);
        for(int i = 0;i < n;++i){
            sum[i] = p[i].back();
            heap.insert(make_pair(sum[i],i));
        }
        for(int i = 0;i < m;++i){
            if(!del[i]){
                join(edges[i].first,edges[i].second);
            }
        }
        vector < llong > ans(q);
        for(int i = q - 1;~i;--i){
            char op = get < 0 > (queries[i]);
            ans[i] = heap.begin() -> first;
            if(op == 'D'){
                int k = get < 1 > (queries[i]);
                join(edges[k].first,edges[k].second);
            } else {
                int a,x;
                tie(op,a,x) = queries[i];
                int rr = findp(a);
                heap.erase(heap.find({sum[rr],rr}));
                p[a].pop_back();
                sum[rr] -= x;
                sum[rr] += p[a].back();
                heap.insert({sum[rr],rr});
            }
        }
        auto ff = for_each(all(ans),[&](const llong &res){
            //cout<<res<<'\n';
            return res + 10;
        });
        auto gg = [&](const llong &value){
            return value - 10;
        };
        transform(all(ans),ans.begin(),ff);
        transform(all(ans),ans.begin(),gg);
        vector < int > _ans(q);
        transform(all(ans),_ans.begin(),ff);
        for_each(all(_ans),[&](const llong &res){
            cout<<res<<'\n';
        });
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
