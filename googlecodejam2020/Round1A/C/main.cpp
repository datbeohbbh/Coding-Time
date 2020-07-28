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

    int row,col;

    void compute(){
        cin>>row>>col;
        vector < vector <int> > a(row + 2,vector <int> (col + 2));
        vector < vector <int> > d(row + 2,vector <int> (col + 2,0));
        vector < vector <int> > u(row + 2,vector <int> (col + 2,0));
        vector < vector <int> > l(row + 2,vector <int> (col + 2,0));
        vector < vector <int> > r(row + 2,vector <int> (col + 2,0));
        llong sum = 0;
        for(int i = 1;i <= row;++i){
            for(int j = 1;j <= col;++j){
                cin>>a[i][j];
                sum += a[i][j];
            }
        }
        llong ans = sum;
        vector <pair <int,int> > cur[2];
        int f = 0;
        for(int i = 1;i <= row;++i){
            for(int j = 1;j <= col;++j){
                d[i][j] = i - 1;
                u[i][j] = i + 1;
                l[i][j] = j - 1;
                r[i][j] = j + 1;
                cur[f].emplace_back(make_pair(i,j));
            }
        }
        vector < vector <int> > del(row + 2,vector <int> (col + 2,-1));
        for(int round = 0; ;++round,f ^= 1){
            vector <pair <int,int> > elimination;
            for(pair <int,int> p : cur[f]){
                int t = 0,cnt = 0;
                int i = p.first;
                int j = p.second;
                if(d[i][j]){
                    ++cnt;
                    t += a[d[i][j]][j];
                }
                if(u[i][j] <= row){
                    ++cnt;
                    t += a[u[i][j]][j];
                }
                if(l[i][j]){
                    ++cnt;
                    t += a[i][l[i][j]];
                }
                if(r[i][j] <= col){
                    ++cnt;
                    t += a[i][r[i][j]];
                }
                if(a[i][j] * cnt < t){
                    elimination.emplace_back(p);
                    del[i][j] = round;
                    sum -= a[i][j];
                }
            }
            if(elimination.empty()){
                break;
            }
            ans += sum;
            for(pair <int,int> p : elimination){
                int i = p.first;
                int j = p.second;
                if(d[i][j]){
                    if(del[d[i][j]][j] != round){
                        del[d[i][j]][j] = round;
                        cur[f ^ 1].emplace_back(make_pair(d[i][j],j));
                    }
                }
                if(u[i][j] <= row){
                    if(del[u[i][j]][j] != round){
                        del[u[i][j]][j] = round;
                        cur[f ^ 1].emplace_back(make_pair(u[i][j],j));
                    }
                }
                if(l[i][j]){
                    if(del[i][l[i][j]] != round){
                        del[i][l[i][j]] = round;
                        cur[f ^ 1].emplace_back(make_pair(i,l[i][j]));
                    }
                }
                if(r[i][j] <= col){
                    if(del[i][r[i][j]] != round){
                        del[i][r[i][j]] = round;
                        cur[f ^ 1].emplace_back(make_pair(i,r[i][j]));
                    }
                }
            }
            cur[f].clear();
            for(pair <int,int> p : elimination){
                int i = p.first;
                int j = p.second;
                if(d[i][j]){
                    u[d[i][j]][j] = u[i][j];
                }
                if(u[i][j] <= row){
                    d[u[i][j]][j] = d[i][j];
                }
                if(l[i][j]){
                    r[i][l[i][j]] = r[i][j];
                }
                if(r[i][j] <= col){
                    l[i][r[i][j]] = l[i][j];
                }
            }
        }
        cout<<ans<<'\n';

    }

    void solve(){
        int T;
        cin>>T;
        for(int test = 1;test <= T;++test){
            cout<<"Case #"<<test<<": ";
            compute();
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
