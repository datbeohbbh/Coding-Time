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

    int h[6][6] = {
            {2,1,1,1,1,1},
            {3,2,1,1,1,1},
            {4,2,2,1,1,1},
            {5,3,2,2,1,1},
            {6,3,2,2,2,1},
            {7,4,3,2,2,2}
                };

    void compute(int w){
        vector <int> s;
        s.emplace_back(-1);
        for(int i = 1;i <= w;++i){
            cout<<i<<endl;
            int sum; cin>>sum;
            s.emplace_back(sum);
        }
    }

    void solve(){
        int T,w;
        cin>>T>>w;
        for(int t = 1;t <= T;++t){
            if(w == 6){
                compute(w);
            }
        }
    }
}

int main(void){
    task::solve();
}
