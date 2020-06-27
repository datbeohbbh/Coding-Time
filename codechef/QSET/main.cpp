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

    const int N = 1e5 + 5;
    const int blockSize = 316;
    int freq[blockSize + 2][3],extra[blockSize + 2];
    vector < pair <int,int> > blocks;
    int a[N],sum[N];
    int n,m;

    void solve(){
        cin>>n>>m;
        for(int i = 0;i < n;++i){
            char c;
            cin>>c;
            a[i] = sum[i] = c - '0';
        }
        sum[0] %= 3;
        for(int i = 1;i < n;++i){
            sum[i] = (sum[i - 1] + a[i]) % 3;
        }
        for(int l = 0;l < n;l += blockSize){
            int r = min(n - 1,l + blockSize - 1);
            blocks.emplace_back(make_pair(l,r));
        }
        for(int b = 0;b < len(blocks);++b){
            for(int i = blocks[b].first;i <= blocks[b].second;++i){
                ++freq[b][sum[i]];
            }
        }
        auto coef = [](const int &x){
            return (x < 1 ? 0LL : 1LL * x * 1LL * (x - 1));
        };
        int cnt[3] = {0};
        while(m--){
            int type,l,r;
            cin>>type>>l>>r;
            --l;
            if(type == 1){
                int curBlock = l / blockSize;
                int t = r - a[l];
                for(int i = l;i <= blocks[curBlock].second;++i){
                    --freq[curBlock][sum[i]];
                    ++freq[curBlock][(sum[i] + t % 3 + 3) % 3];
                    sum[i] = (sum[i] + t % 3 + 3) % 3;
                }
                for(int i = curBlock + 1;i < len(blocks);++i){
                    extra[i] += t;
                }
                a[l] = r;
            } else {
                --r;
                fill(cnt,cnt + 3,0);
                cnt[0] = 1;
                int block_l = l / blockSize;
                int block_r = r / blockSize;
                llong ans = 0;
                if(block_l == block_r){
                    for(int i = l;i <= r;++i){
                        ++cnt[(sum[i] + extra[block_r] % 3 + 3)  % 3];
                    }
                } else {
                    for(int i = l;i <= blocks[block_l].second;++i){
                        ++cnt[(sum[i] + extra[block_l] % 3 + 3) % 3];
                    }
                    for(int i = r;i >= blocks[block_r].first;--i){
                        ++cnt[(sum[i] + extra[block_r] % 3 + 3) % 3];
                    }
                    for(int i = block_l + 1;i < block_r;++i){
                        for(int d = 0;d < 3;++d){
                            cnt[d] += freq[i][(d - extra[i] % 3 + 3) % 3];
                        }
                    }
                }
                for(int d = 0;d < 3;++d){
                    ans += coef(cnt[d]);
                }
                cout<<ans / 2LL<<'\n';
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
