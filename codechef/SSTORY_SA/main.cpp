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

    const int maxlg = 19;
    const int inf = 1e9;
    string s,t;
    int st = -1,en = -1;

    class SuffixArray{
    public:
        vector < vector < int > > suffRank;
        vector < pair < pair < int,int >,int > > curRank;
        vector < int > rank;
        vector < int > posRank;
        vector < int > lcp;
        int L;
    public:
        SuffixArray(const string &str){
            L = len(str);
            suffRank.resize(maxlg + 2,vector < int > (L + 2,0));
            curRank.resize(L);
            rank.resize(L);
            posRank.resize(L);
            lcp.resize(L);
            for(int i = 0;i < L;++i){
                suffRank[0][i] = str[i] - 'a';
            }
            for(int j = 1;j <= maxlg;++j){
                for(int i = 0;i < L;++i){
                    curRank[i] = {{suffRank[j - 1][i],i + MASK(j - 1) < L ? suffRank[j - 1][i + MASK(j - 1)] : -1},i};
                }
                sort(all(curRank));
                for(int i = 0;i < L;++i){
                    suffRank[j][curRank[i].second] = (i and curRank[i - 1].first == curRank[i].first ? suffRank[j][curRank[i - 1].second] : i);
                }
            }
            for(int i = 0;i < L;++i){
                rank[i] = curRank[i].second;
                posRank[rank[i]] = i;
            }
        }
        int calcLcp(int rx,int ry) const {
            if(rx > ry){
                swap(rx,ry);
            }
            int ret = 0;
            for(int j = maxlg;~j;--j){
                if(ry + MASK(j) - 1 < L){
                    if(suffRank[j][rx] == suffRank[j][ry]){
                        rx += MASK(j);
                        ry += MASK(j);
                        ret |= MASK(j);
                    }
                }
            }
            return ret;
        }
        void buildLcp(){
            for(int i = 0;i < L - 1;++i){
                lcp[i] = calcLcp(rank[i],rank[i + 1]);
            }
        }
    }*sa;

    vector < vector < int > > rmq;
    vector < vector < int > > rmqIndex;

    int getLen(int l,int r){
        if(l > --r){
            return sa -> L - sa -> rank[l];
        }
        int x = (int)log2(r - l + 1);
        return min(rmq[x][l],rmq[x][r - MASK(x) + 1]);
    }

    pair < int,int > occ(int ra,int k){
        pair < int,int > res(-1,-1);
        for(int l = 0,r = ra,mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
            if(getLen(mid,ra) >= k){
                r = mid - 1;
                res.first = mid;
            } else {
                l = mid + 1;
            }
        }
        for(int l = ra,r = sa -> L - 1,mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
            if(getLen(ra,mid) >= k){
                l = mid + 1;
                res.second = mid;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }

    int maxL = -1;
    bool ok(int suff,int k){
        bool found = false;
        int newStart = inf;
        pair < int,int > pos = occ(sa -> posRank[suff],k);
        int ra = pos.first;
        int rb = pos.second;
        if(~ra and ~rb){
            int x = (int)log2(rb - ra + 1);
            int mi = min(rmqIndex[x][ra],rmqIndex[x][rb - MASK(x) + 1]);
            if(mi != inf){
                found = true;
                minimize(newStart,mi);
            }
        }
        if(found){
            if(k > maxL) {
                st = newStart;
                en = newStart + k - 1;
                maxL = k;
            } else if(k == maxL){
                minimize(st,newStart);
                en = st + k - 1;
            }
        }
        return found;
    }

    void solve(){
         cin>>s>>t;
         sa = new SuffixArray(s + "#" + t);
         sa -> buildLcp();
         rmq.resize(maxlg + 2,vector < int > (sa -> L + 2,0));
         rmqIndex.resize(maxlg + 2,vector < int > (sa -> L + 2,0));
         for(int i = 0;i < sa -> L - 1;++i){
             rmq[0][i] = sa -> lcp[i];
         }
         for(int i = 0;i < sa -> L;++i){
             rmqIndex[0][i] = (sa -> rank[i] <= len(s) ? inf : sa -> rank[i] - len(s) - 1);
         }
         for(int j = 1;j <= maxlg;++j){
             for(int i = 0;i + MASK(j) - 1 < sa -> L - 1;++i){
                 rmq[j][i] = min(rmq[j - 1][i],rmq[j - 1][i + MASK(j - 1)]);
             }
         }
         for(int j = 1;j <= maxlg;++j){
             for(int i = 0;i + MASK(j) - 1 < sa -> L;++i){
                 rmqIndex[j][i] = min(rmqIndex[j - 1][i],rmqIndex[j - 1][i + MASK(j - 1)]);
             }
         }
         int cur = 0;
         for(int i = 0;i < len(s);++i){
             maximize(cur,i);
             while(cur < len(s) and cur - i + 1 <= len(t) and ok(i,cur - i + 1)){
                 ++cur;
             }
         }
         if(~st and ~en){
             for_each(t.begin() + st,t.begin() + en + 1,[&](const char &c){
                 cout<<c;
             });
             cout<<'\n'<<en - st + 1;
         } else {
             cout<<0;
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
