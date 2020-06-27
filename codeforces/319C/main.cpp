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

    const int N = 1e5 + 5;
    const llong inf = 1e18;
    int a[N],b[N];
    int n;
    llong f[N];

    class Line{
    public:
        llong m,b;
    public:
        Line(){}
        Line(llong _m,llong _b):m(_m),b(_b){};
        llong evaluate(int x) const{
            return m * (llong)x + b;
        }
    };

    class ConvexHullTrick{
    private:
        vector <Line> hull;
    public:
        ConvexHullTrick(){
            hull.clear();
        }
        bool bad(const Line &la,const Line &lb,const Line &lc){
            return (long double)(lc.b - la.b) * (la.m - lb.m) <= (long double)(lb.b - la.b) * (la.m - lc.m);
        }
        void addLine(Line nw){
            while(hull.size() > 1 and bad(hull[hull.size() - 2],hull.back(),nw)){
                hull.pop_back();
            }
            hull.emplace_back(nw);
        }
        llong get(int x){
            int l = 0,r = hull.size() - 1;
            while(r - l > 1){
                int mid = (l + r) >> 1;
                if(hull[mid].evaluate(x) < hull[mid + 1].evaluate(x)){
                    r = mid;
                } else {
                    l = mid;
                }
            }
            return min(hull[l].evaluate(x),hull[r].evaluate(x));
        }
    };
    ConvexHullTrick *cht = new ConvexHullTrick();

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        for(int i = 1;i <= n;++i){
            cin>>b[i];
        }
        fill(f + 1,f + 1 + n,inf);
        f[1] = 1LL * b[1] * 1LL * a[n];
        cht -> addLine(Line(b[1],f[1]));
        for(int i = 2;i <= n;++i){
            f[i] = 1LL * b[i] * 1LL * a[n] + cht -> get(a[i] - a[n]);
            cht -> addLine(Line(b[i],f[i]));
        }
        cout<<*min_element(f + 1,f + 1 + n);
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
