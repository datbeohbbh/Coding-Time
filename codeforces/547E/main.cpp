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

    const int N = 2e5 + 5;
    const int lg = 20;
    int n,q;
    string s[N];
    string str = "";
    int pos[N << 1];
    int start[N];

    class SuffixArray{
    public:
        vector < vector < int > > suffRank;
        vector < pair < pair < int,int > , int > > curRank;
        vector < int > rank;
        vector < int > posRank;
        string t;
    public:
        SuffixArray(const string &tt):t(tt){
            suffRank.resize(lg + 2,vector < int > (len(t) + 2));
            curRank.resize(len(t),{{0,0},0});
            rank.resize(len(t) + 2,0);
            posRank.resize(len(t) + 2,0);
            for(int i = 0;i < len(t);++i){
                suffRank[0][i] = t[i] - 'a';
            }
            for(int j = 1;j <= lg;++j){
                for(int i = 0;i < len(t);++i){
                    curRank[i] = {{suffRank[j - 1][i],(i + MASK(j - 1) < len(t) ? suffRank[j - 1][i + MASK(j - 1)] : -1)},i};
                }
                sort(all(curRank));
                for(int i = 0;i < len(t);++i){
                    suffRank[j][curRank[i].second] = (i and curRank[i].first == curRank[i - 1].first ? suffRank[j][curRank[i - 1].second] : i);
                }
            }
            for(int i = 0;i < len(t);++i){
                rank[i] = curRank[i].second;
                posRank[rank[i]] = i;
            }
        }
        int lcp(int rx,int ry){
            if(rx > ry){
                swap(rx,ry);
            }
            int res = 0;
            for(int j = lg;~j;--j){
                if(ry + MASK(j) <= len(t)){
                    if(suffRank[j][rx] == suffRank[j][ry]){
                        rx += MASK(j);
                        ry += MASK(j);
                        res |= MASK(j);
                    }
                }
            }
            return res;
        }
    };
    SuffixArray *sa;

    class MergeSortTree{
    public:
        vector < vector < int > > tree;
    public:
        MergeSortTree(int sizeTree){
            tree.resize((sizeTree << 2) + 2,vector < int > ());
        }
        void buildTree(int l,int r,const SuffixArray *sa,int node = 1){
            if(l > r){
                return ;
            }
            if(l == r){
                tree[node].emplace_back(pos[sa -> rank[l]]);
                return ;
            }
            int mid = (l + r) >> 1;
            buildTree(l,mid,sa,node << 1);
            buildTree(mid + 1,r,sa,node << 1 | 1);
            tree[node].resize(len(tree[node << 1]) + len(tree[node << 1 | 1]));
            merge(all(tree[node << 1]),all(tree[node << 1 | 1]),tree[node].begin());
        }
        int calc(int tl,int tr,int val,int l,int r,int node = 1){
            if(l > r or r < tl or l > tr){
                return 0;
            }
            if(tl <= l and r <= tr){
                int p = -1;
                int lo = 0,hi = len(tree[node]) - 1;
                while(lo <= hi){
                    int mid = (lo + hi) >> 1;
                    if(tree[node][mid] <= val){
                        p = mid;
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                return ++p;
            }
            int mid = (l + r) >> 1;
            return calc(tl,tr,val,l,mid,node << 1) + calc(tl,tr,val,mid + 1,r,node << 1 | 1);
        }
        int f(int lk,int rk,int l,int r,int tl,int tr){
            return calc(lk,rk,r,tl,tr) - calc(lk,rk,l - 1,tl,tr);
        }
    };
    MergeSortTree *mseg;

    vector < vector < int > > rmq;
    vector < pair < int,int > > occ;

    int getLen(int l,int r){
        if(l > --r){
            return len(sa -> t) - sa -> rank[l];
        }
        int x = (int)log2(r - l + 1);
        return min(rmq[x][l],rmq[x][r - MASK(x) + 1]);
    }

    pair < int,int > compute(int ra,int L){
        pair < int,int > ret(-1,-1);
        for(int l = 0,r = ra,mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
            if(getLen(mid,ra) >= L){
                r = mid - 1;
                ret.first = mid;
            } else {
                l = mid + 1;
            }
        }
        for(int l = ra,r = len(sa -> t) - 1,mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
            if(getLen(ra,mid) >= L){
                l = mid + 1;
                ret.second = mid;
            } else {
                r = mid - 1;
            }
        }
        return ret;
    }

    void solve(){
        cin>>n>>q;
        for(int l = 0,i = 1;i <= n;++i){
            cin>>s[i];
            str += s[i] + "#";
            start[i] = l;
            for(int j = l;j < len(str) - 1;++j){
                pos[j] = i;
            }
            pos[len(str) - 1] = -1;
            l += len(s[i]) + 1;
        }
        sa = new SuffixArray(str);
        mseg = new MergeSortTree(len(sa -> t));
        mseg -> buildTree(0,len(sa -> t) - 1,sa);
        rmq.resize(lg + 2,vector < int > (2 + len(sa -> t),0));
        for(int i = 0;i < len(sa -> t) - 1;++i){
            rmq[0][i] = sa -> lcp(sa -> rank[i],sa -> rank[i + 1]);
        }
        for(int j = 1;j <= lg;++j){
            for(int i = 0;i + MASK(j) < len(sa -> t);++i){
                rmq[j][i] = min(rmq[j - 1][i],rmq[j - 1][i + MASK(j - 1)]);
            }
        }
        occ.resize(n + 2,{0,0});
        for(int i = 1;i <= n;++i){
            occ[i] = compute(sa -> posRank[start[i]],len(s[i]));
        }
        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            if(~occ[k].first and ~occ[k].second){
                cout<<mseg -> f(occ[k].first,occ[k].second,l,r,0,len(sa -> t) - 1)<<'\n';
            } else {
                cout<<"0\n";
            }
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
