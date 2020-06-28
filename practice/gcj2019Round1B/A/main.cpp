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

    const char dir[] = {'N','S','E','W'};

    void compute(){
        int p,q;
        cin>>p>>q;
        vector <pair <int,int> > a(p + 2);
        vector <pair <int,int> > f[4];
        for(int i = 1;i <= p;++i){
            cin>>a[i].first>>a[i].second;
            char c;
            cin>>c;
            for(int j = 0;j < 4;++j){
                if(c == dir[j]){
                    f[j].emplace_back(a[i]);
                }
            }
        }
        vector <int> sumN(q + 2,0);
        vector <int> sumS(q + 2,0);
        vector <int> sumW(q + 2,0);
        vector <int> sumE(q + 2,0);
        for(pair <int,int> iter : f[0]){
            ++sumN[iter.second + 1];
        }
        for(pair <int,int> iter : f[1]){
            ++sumS[iter.second - 1];
        }
        for(pair <int,int> iter : f[2]){
            ++sumE[iter.first + 1];
        }
        for(pair <int,int> iter : f[3]){
            ++sumW[iter.first - 1];
        }
        for(int i = 1;i <= q;++i){
            sumN[i] += sumN[i - 1];
            sumE[i] += sumE[i - 1];
        }
        for(int i = q - 1;i >= 0;--i){
            sumS[i] += sumS[i + 1];
            sumW[i] += sumW[i + 1];
        }
        int l = 0,r = 0;
        int maxX = -1,maxY = -1;
        for(int i = 0;i <= q;++i){
            if(maxX < sumW[i] + sumE[i]){
                maxX = sumW[i] + sumE[i];
                l = i;
            }
            if(maxY < sumN[i] + sumS[i]){
                maxY = sumN[i] + sumS[i];
                r = i;
            }
        }
        cout<<l<<' '<<r;
    }

    void solve(){
        int T;
        cin>>T;
        for(int t = 1;t <= T;++t){
            cout<<"Case #"<<t<<": ";
            compute();
            cout<<'\n';
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
