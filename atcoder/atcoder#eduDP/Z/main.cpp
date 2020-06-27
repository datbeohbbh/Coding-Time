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

#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/


namespace task{

    const int N = 2e5 + 5;
    int h[N];
    llong f[N];
    int n;
    llong c;

    struct Line{
    public:
        llong m,b;
    public:
        Line(llong _m,llong _b){
            this -> m = _m;
            this -> b = _b;
        }
        llong evalute(int x) const{
            return m * (llong)x + b;
        }
    };

    class ConvexHullTrick{
    public:
        vector <Line> hull;
    public:
        bool bad(Line la,Line lb,Line lc){
            return (lc.b - la.b) * (la.m - lb.m) <= (la.m -lc.m) * (lb.b - la.b);
        }
        void addLine(Line l){
            while(hull.size() >= 2 and bad(hull[hull.size() - 2],hull.back(),l)){
                hull.pop_back();
            }
            hull.emplace_back(l);
        }
        llong getMin(int x){
            int l = 0,r = hull.size() - 1;
            while(l < r){
                int mid = (l + r) >> 1;
                if(hull[mid].evalute(x) < hull[mid + 1].evalute(x)){
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return min(hull[l].evalute(x),hull[r].evalute(x));
        }
    };

    void solve(){
        cin>>n>>c;
        for(int i = 1;i <= n;++i){
            cin>>h[i];
        }
        ConvexHullTrick *cht = new ConvexHullTrick();
        cht -> addLine(Line(-2 * h[1],1LL * h[1] * 1LL * h[1]));
        for(int i = 2;i <= n;++i){
            f[i] = 1LL * h[i] * 1LL * h[i] + c + cht -> getMin(h[i]);
            cht -> addLine(Line(-2 * h[i],f[i] + 1LL * h[i] * 1LL * h[i]));
        }
        cout<<f[n];
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
