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

    int get(pair <int,int> a,pair <int,int> b){
        return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
    }

    int ccw(pair <int,int> a,pair <int,int> b){
        return Abs(a.first * b.second - a.second * b.first);
    }

    bool chk(vector < pair <int,int> > p){
        pair <int,int> a = p[0];
        pair <int,int> b = p[1];
        pair <int,int> c = p[2];
        pair <int,int> d = p[3];
        if((c.first - a.first) * (d.first - b.first) + (c.second - a.second) * (d.second - b.second) != 0){
            return false;
        }
        if(ccw(make_pair(b.first - a.first,b.second - a.second),make_pair(c.first - a.first,c.second - a.second))
         + ccw(make_pair(c.first - a.first,c.second - a.second),make_pair(d.first - a.first,d.second - a.second)) == 0){
            return false;
        }
        if(get(a,b) == get(b,c) and get(a,b) == get(c,d) and get(a,b) == get(a,d)){
            return get(a,c) != get(b,d);
        }
        return false;
    }

    bool isRhombusNotSquare(vector< vector<int> > points){
        pair <int,int> p[4];
        for(int i = 0;i < 4;++i){
            p[i].first = points[i][0];
            p[i].second = points[i][1];
        }
        string s = "0123";
        do{
            vector < pair <int,int> > pp;
            for(int i = 0;i < len(s);++i){
                pp.emplace_back(p[s[i] - '0']);
            }
            if(chk(pp)){
                return true;
            }
        }while (next_permutation(all(s)));
        return false;
    }

    void solve(){
        vector < vector <int> > points(4,vector <int> (2,0));
        for(int i = 0;i < 4;++i){
            for(int j = 0;j < 2;++j){
                cin>>points[i][j];
            }
        }
        cout<<isRhombusNotSquare(points);
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
