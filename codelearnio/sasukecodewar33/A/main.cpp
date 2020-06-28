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

    int balance(vector <int> a){
        string s = "0123";
        do{
            int i = s[0] - '0';
            int j = s[1] - '0';
            int k = s[2] - '0';
            int t = s[3] - '0';
            if(a[i] + a[j] == a[k] + a[t]){
                return a[i] + a[j];
            }
        }while (next_permutation(all(s)));
        return -1;
    }

    void solve(){
        vector <int> a;
        int val;
        while(cin >> val){
            a.emplace_back(val);
        }
        cout<<balance(a);
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
