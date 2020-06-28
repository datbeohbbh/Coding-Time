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

    const int lg = 18;
    const int N = 1e5;
    int n,k;
    llong ans = 0;

    class RMQ{
    public:
        vector < vector <int> > rmq;
        vector < int > a;
        int m;
    public:
        int compare(int i,int j){
            return (a[i] < a[j] ? j : i);
        }
        RMQ(vector <int> a){
            m = len(a);
            this -> a = a;
            rmq.resize(lg + 2,vector <int> (m + 1));
            for(int i = 1;i < m;++i){
                rmq[0][i] = i;
            }
            for(int j = 1;j <= lg;++j){
                for(int i = 1;i + MASK(j) - 1 < m;++i){
                    rmq[j][i] = compare(rmq[j - 1][i],rmq[j - 1][i + MASK(j - 1)]);
                }
            }
        }
        ~RMQ(){
            rmq.clear();
        }
        int get(int l,int r){
            int x = (int)log2(r - l + 1);
            return compare(rmq[x][l],rmq[x][r - MASK(x) + 1]);
        }
        llong findLR(int ll,int rr,int mi,int val){
            int pos_l = mi,pos_r = mi;
            if(a[mi] > val){
                return 0;
            }
            for(int l = ll,r = mi,mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
                if(a[get(mid,mi)] <= val){
                    r = mid - 1;
                    pos_l = mid;
                } else {
                    l = mid + 1;
                }
            }
            for(int l = mi,r = rr,mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
                if(a[get(mi,mid)] <= val){
                    l = mid + 1;
                    pos_r = mid;
                } else {
                    r = mid - 1;
                }
            }
            return 1LL * (mi - pos_l + 1) * 1LL * (pos_r - mi + 1);
        }
    };

    void calc(int l,int r,RMQ *rmq_c,RMQ *rmq_d){
        if(l > r){
            return ;
        }
        int mid = rmq_c -> get(l,r);
        calc(l,mid - 1,rmq_c,rmq_d);
        calc(mid + 1,r,rmq_c,rmq_d);
        ans += rmq_d -> findLR(l,r,mid,rmq_c -> a[mid] + k);
        ans -= rmq_d -> findLR(l,r,mid,rmq_c -> a[mid] - k - 1);
    }

    llong compute(){
        ans = 0;
        cin>>n>>k;
        vector <int> c(n + 1,0);
        vector <int> d(n + 1,0);
        for(int i = 1;i <= n;++i){
            cin>>c[i];
        }
        for(int i = 1;i <= n;++i){
            cin>>d[i];
        }
        RMQ *rmq_d = new RMQ(d);
        RMQ *rmq_c = new RMQ(c);
        calc(1,n,rmq_c,rmq_d);
        return ans;
    }

    void solve(){
        int T;
        cin>>T;
        for(int t = 1;t <= T;++t){
            cout<<"Case #"<<t<<": "<<compute()<<'\n';
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
