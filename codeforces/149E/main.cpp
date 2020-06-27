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

    const int N =3e5 + 5;
    const int lg = 19;
    const int inf = 1e9;
    string s;
    string p[N];
    int rmq[lg + 2][N];
    int _log[N];
    int ll[N],rr[N];
    int sparseTable[2][lg + 2][N];
    int m;

    class SuffixArray{
    private:
        string s;
        int length;
    public:
        int posRank[N];
        int rank[N];
        int lcp[N];
        int sp[lg + 2][N];
        pair <pair <int,int>,int> curRank[N];
    public:
        SuffixArray(string s){
            this -> s = s;
            this -> length = len(s);
        }

        void buildSuffixArray(){
            for(int i = 0;i < length;++i){
                sp[0][i] = s[i] - 'A';
            }
            for(int j = 1;j <= lg;++j){
                for(int i = 0;i < length;++i){
                    curRank[i] = {{sp[j - 1][i],(i + MASK(j - 1) < length ? sp[j - 1][i + MASK(j - 1)] : -1)},i};
                }
                sort(curRank,curRank + length);
                for(int i = 0;i < length;++i){
                    sp[j][curRank[i].second] = (i and curRank[i].first == curRank[i - 1].first ? sp[j][curRank[i - 1].second] : i);
                }
            }
            for(int i = 0;i < length;++i){
                rank[i] = curRank[i].second;
                posRank[rank[i]] = i;
            }
        }

        int computeLcp(int rx,int ry){
            int ret = 0;
            if(rx > ry){
                swap(rx,ry);
            }
            for(int j = lg;~j;--j){
                if(ry + MASK(j) <= length){
                    if(sp[j][rx] == sp[j][ry]){
                        ret += MASK(j);
                        rx += MASK(j);
                        ry += MASK(j);
                    }
                }
            }
            return ret;
        }
    };
    SuffixArray *sa;

    int getLcp(int l,int r){
        --r;
        if(l > r){
            return len(s) - sa -> rank[l];
        }
        int x = _log[r - l + 1];
        return min(rmq[x][l],rmq[x][r - MASK(x) + 1]);
    }

    pair <int,int> compute(int ra,int len){
        int l = ra,r = len(s) - 1;
        int pos_l = -1,pos_r = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(getLcp(ra,mid) >= len){
                l = mid + 1;
                pos_r = mid;
            } else {
                r = mid - 1;
            }
        }
        l = 0,r = ra;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(getLcp(mid,ra) >= len){
                r = mid - 1;
                pos_l = mid;
            } else {
                l = mid + 1;
            }
        }
        return make_pair(pos_l,pos_r);
    }

    void solve(){
        cin>>s>>m;
        int tmpLen = len(s);
        for(int i = 1;i <= m;++i){
            cin>>p[i];
            ll[i] = len(s) + 1;
            rr[i] = ll[i] + len(p[i]) - 1;
            s += "a" + p[i];
        }
        sa = new SuffixArray(s);
        sa -> buildSuffixArray();

        /*for(int i = 0;i < len(s);++i){
            cout<<"["<<i<<"]:  "<<s.substr(sa -> rank[i])<<'\n';
        }*/
        for(int i = 2;i <= len(s);++i){
            _log[i] = _log[i >> 1] + 1;
        }
        for(int i = 0;i < len(s) - 1;++i){
            sa -> lcp[i] = sa -> computeLcp(sa -> rank[i],sa -> rank[i + 1]);
        }
        for(int i = 0;i < len(s) - 1;++i){
            rmq[0][i] = sa -> lcp[i];
        }
        for(int j = 1;j <= lg;++j){
            for(int i = 0;i + MASK(j) < len(s);++i){
                rmq[j][i] = min(rmq[j - 1][i],rmq[j - 1][i + MASK(j - 1)]);
            }
        }
        for(int i = 0;i < len(s);++i){
            if(sa -> rank[i] < tmpLen){
                sparseTable[0][0][i] = sparseTable[1][0][i] = sa -> rank[i];
            } else {
                sparseTable[0][0][i] = inf;
                sparseTable[1][0][i] = -inf;
            }
        }
        for(int j = 1;j <= lg;++j){
            for(int i = 0;i + MASK(j) <= len(s);++i){
                sparseTable[0][j][i] = min(sparseTable[0][j - 1][i],sparseTable[0][j - 1][i + MASK(j - 1)]);
                sparseTable[1][j][i] = max(sparseTable[1][j - 1][i],sparseTable[1][j - 1][i + MASK(j - 1)]);
            }
        }
        auto getMin = [&](const int &l,const int &r) -> int{
            int x = _log[r - l + 1];
            return min(sparseTable[0][x][l],sparseTable[0][x][r - MASK(x) + 1]);
        };
        auto getMax = [&](const int &l,const int &r) -> int{
            int x = _log[r - l + 1];
            return max(sparseTable[1][x][l],sparseTable[1][x][r - MASK(x) + 1]);
        };
        int ans = 0;
        for(int i = 1;i <= m;++i){
            for(int j = ll[i];j < rr[i];++j){
                pair <int,int> pa = compute(sa -> posRank[ll[i]],j - ll[i] + 1);
                pair <int,int> pb = compute(sa -> posRank[j + 1],rr[i] - j);
                if(~pa.first and ~pa.second and ~pb.first and ~pb.second){
                    if(getMin(pa.first,pa.second) + j - ll[i] < getMax(pb.first,pb.second)){
                        int xx = getMin(pa.first,pa.second);
                        int yy = getMax(pb.first,pb.second);
                        ++ans;
                        break;
                    }
                }
            }
        }
        cout<<ans;
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
