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

    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    };

    const int N = 1e5 + 2;
    vector < pair <int,int> > block;
    int pref[N],a[N];
    int n,q,blockSize;

    void solve(){
        cin>>n>>q;

        blockSize = (int)sqrt(n + q);
        vector <int> extra(blockSize + 2,0);
        unordered_map <int,int,custom_hash> freq[blockSize + 2];

        for(int i = 0;i < n;++i){
            cin>>pref[i];
            a[i] = pref[i];
        }
        for(int i = 1;i < n;++i){
            pref[i] ^= pref[i - 1];
        }
        for(int l = 0;l < n;l += blockSize){
            int r = min(n - 1,l + blockSize - 1);
            block.emplace_back(make_pair(l,r));
        }
        for(int i = 0;i < len(block);++i){
            for(int l = block[i].first;l <= block[i].second;++l){
                ++freq[i][pref[l]];
            }
        }
        while(q--){
            int type,i,x,k;
            cin>>type>>i;
            --i;
            if(type == 1){
                cin>>x;
                int b = i / blockSize;
                for(int l = i;l <= block[b].second;++l){
                    auto it = freq[b].find(pref[l]);
                    --(it -> second);
                    if(it -> second == 0){
                        freq[b].erase(pref[l]);
                    }
                    ++freq[b][pref[l] ^ a[i] ^ x];
                    pref[l] ^= a[i] ^ x;
                }
                for(int j = b + 1;j < len(block);++j){
                    extra[j] ^= a[i] ^ x;
                }
                a[i] = x;
            } else {
                int ans = 0;
                cin>>k;
                int b = i / blockSize;
                for(int l = block[b].first;l <= i;++l){
                    ans += ((pref[l] ^ extra[b]) == k);
                }
                for(int j = 0;j < b;++j){
                    if(freq[j].find(k ^ extra[j]) != freq[j].end()) {
                        ans += freq[j][k ^ extra[j]];
                    }
                }
                cout<<ans<<'\n';
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
