#include <bits/stdc++.h>

using namespace std;

template <class T,class U>
void maximize(T &lhs,U rhs){
    if(lhs < rhs)lhs = rhs;
}
template <class T,class U>
void minimize(T &lhs,U rhs){
    if(lhs > rhs)lhs = rhs;
}
template < class T,class U >
void maximize(T &lhs,const initializer_list < U > &rhs){
    U max_rhs = max(rhs);
    if(lhs < max_rhs){
        lhs = max_rhs;
    }
}
template < class T,class U >
void minimize(T &lhs,const initializer_list < U > &rhs){
    U min_rhs = min(rhs);
    if(lhs > min_rhs){
        lhs = min_rhs;
    }
}
template <class T>
T tabs(T x){
    return (x < (T)0 ? -x : x);
}

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define fn "test"    /// FILE NAME HERE!!!

/* ================================= END OF TEMPLATE ================================= */


/* ================================= DEBUG ================================= */

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rand __rand
mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
template <class T = int>
T rand(T range = numeric_limits <T> :: max()){
    return (T) (generator() % range);
}

/* ================================= DEBUG ================================= */

namespace Task{

    const llong base = 1000000007;
    const llong inf = 1e18;
    class Solver{
    public:
        vector < llong > l;
        vector < llong > w;
        vector < llong > h;
        set < pair < llong,llong > > comp_range;
        set < pair < llong,llong > > start_comp;
        vector < tuple < llong,llong,llong,llong > > comp;
        vector < llong > pcomp;
        vector < llong > ver;
        int n,k;
        int cnt_comp = 0;
        llong ans = 1;
        llong cur_sum = 0;
    public:
        ~Solver(){
            l.clear();
            w.clear();
            h.clear();
            comp_range.clear();
            start_comp.clear();
            comp.clear();
            ver.clear();
            pcomp.clear();
        }
    public:

        llong mulmod(llong u,llong v,llong mod){
            return ((u % mod) * (v % mod)) % mod;
        }

        void calc(vector < llong > &vec){
            llong A,B,C,D;
            cin>>A>>B>>C>>D;
            for(int i = k + 1;i <= n;++i){
                vec[i] = ((mulmod(A,vec[i - 2],D) + mulmod(B,vec[i - 1],D) + C % D) % D) + 1;
            }
        }

        bool checkInside(llong lo,llong hi){
            if(start_comp.empty()){
                return false;
            }
            auto it = start_comp.lower_bound({lo,-inf});
            if(it == start_comp.end()){
                --it;
            }
            if((it -> first) > lo and it != start_comp.begin()){
                --it;
            }
            if((it -> first) > lo){
                return false;
            }
            tuple < llong,llong,llong,llong > t = comp[it -> second];
            if(get < 0 > (t) <= lo and get < 1 > (t) >= hi){
                ans = mulmod(ans,cur_sum,base);
                return true;
            }
            return false;
        }

        bool checkIntersect(llong lo,llong hi,llong height){
            if(comp_range.empty()){
                return false;
            }
            vector < llong > pos;
            llong f = lo;
            while(true){
                auto it = comp_range.lower_bound({f,-inf});
                if(it == comp_range.end()){
                    break;
                }
                if((it -> first) > hi){
                    break;
                }
                pos.emplace_back(it -> second);
                f = it -> first;
                int idx = it -> second;
                llong l_comp = get < 0 > (comp[idx]);
                llong r_comp = get < 1 > (comp[idx]);
                comp_range.erase({l_comp,idx});
                comp_range.erase({r_comp,idx});
                start_comp.erase({l_comp,idx});
            }
            if(pos.empty()){
                return false;
            }
            llong t = cur_sum;
            llong min_pos = lo,max_pos = hi;
            for(int idx : pos){
                t -= pcomp[idx];
                minimize(min_pos,get < 0 > (comp[idx]));
                maximize(max_pos,get < 1 > (comp[idx]));
            }
            llong add_ver = 0;
            sort(pos.begin(),pos.end(),[&](const int &i,const int &j){
                return get < 0 > (comp[i]) < get < 0 > (comp[j]);
            });
            for(int i = 1; i < len(pos) - 1;++i){
                int idx = pos[i];
                llong u = get < 0 > (comp[idx]);
                llong v = get < 1 > (comp[idx]);
                llong hl = get < 2 > (comp[idx]);
                llong hr = get < 3 > (comp[idx]);
                add_ver += ver[idx] - hl - hr + (hl - height) + (hr - height);
            }
            llong fh = height,gh = height;
            if(len(pos) > 1){
                if(get < 0 > (comp[pos[0]]) <= lo){
                    llong hl = get < 2 > (comp[pos[0]]);
                    llong hr = get < 3 > (comp[pos[0]]);
                    add_ver += ver[pos[0]] - hr + (hr - height);
                    fh =  hl;
                } else {
                    llong hl = get < 2 > (comp[pos[0]]);
                    llong hr = get < 3 > (comp[pos[0]]);
                    add_ver += ver[pos[0]] - hl - hr + (hr - height) + (hl - height) + height;
                }
                if(get < 1 > (comp[pos.back()]) >= hi){
                    llong hl = get < 2 > (comp[pos.back()]);
                    llong hr = get < 3 > (comp[pos.back()]);
                    add_ver += ver[pos.back()] - hl + (hl - height);
                    gh = hr;
                } else {
                    llong hl = get < 2 > (comp[pos.back()]);
                    llong hr = get < 3 > (comp[pos.back()]);
                    add_ver += ver[pos.back()] - hl - hr + (hl - height) + (hr - height) + height;
                }
            } else {
                llong u = get < 0 > (comp[pos[0]]);
                llong v = get < 1 > (comp[pos[0]]);
                llong hl = get < 2 > (comp[pos[0]]);
                llong hr = get < 3 > (comp[pos[0]]);
                if(lo <= u and v <= hi){
                    add_ver += ver[pos[0]] - hl - hr + (hl - height) + (hr - height) + height + height;
                    if(u == lo){
                        fh = hl;
                    }
                    if(v == hi){
                        gh = hr;
                    }
                } else if(u < lo){
                    fh = hl;
                    add_ver += ver[pos[0]] - hr + (hr - height) + height;
                } else {
                    gh = hr;
                    add_ver += ver[pos[0]] - hl + (hl - height) + height;
                }
            }
            llong curp = 2LL * (max_pos - min_pos) + add_ver;
            ans = mulmod(ans,t + curp,base);
            cur_sum = t + curp;
            ++cnt_comp;
            comp[cnt_comp] = {min_pos,max_pos,fh,gh};
            ver[cnt_comp] = add_ver;
            pcomp[cnt_comp] = curp;
            start_comp.insert({min_pos,cnt_comp});
            comp_range.insert({min_pos,cnt_comp});
            comp_range.insert({max_pos,cnt_comp});
            return true;
        }

        void solve(){
            cin>>n>>k;
            l.resize(n + 2,0);
            w.resize(n + 2,0);
            h.resize(n + 2,0);
            ver.resize((n << 1) + 2,0);
            comp.resize((n << 1) + 2,{0,0,0,0});
            pcomp.resize((n << 1) + 2,0);
            for(int i = 1;i <= k;++i){
                cin>>l[i];
            }
            calc(l);
            for(int i = 1;i <= k;++i){
                cin>>w[i];
            }
            calc(w);
            for(int i = 1;i <= k;++i){
                cin>>h[i];
            }
            calc(h);
            for(int i = 1;i <= n;++i){
                if(checkInside(l[i],l[i] + w[i])){
                    continue;
                } else if(checkIntersect(l[i],l[i] + w[i],h[i])){
                    continue;
                } else {
                    ++cnt_comp;
                    comp[cnt_comp] = {l[i],l[i] + w[i],h[i],h[i]};
                    ver[cnt_comp] = h[i] + h[i];
                    pcomp[cnt_comp] = 2LL * (h[i] + w[i]);
                    start_comp.insert({l[i],cnt_comp});
                    comp_range.insert({l[i],cnt_comp});
                    comp_range.insert({l[i] + w[i],cnt_comp});
                    ans = mulmod(ans,cur_sum + pcomp[cnt_comp],base);
                    cur_sum += pcomp[cnt_comp];
                }
            }
            cout<<ans<<'\n';
        }
    };

    void solve(){
        int T;
        cin>>T;
        for(int test = 1;test <= T;++test){
            cout<<"Case #"<<test<<": ";
            (new Solver) -> solve();
        }
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".txt","w",stdout);
#endif // ONLINE_JUDGE
    Task::solve();
}


