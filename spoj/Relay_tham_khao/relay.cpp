#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

const int nmax = 805;
const int kmax = 42;
const int vc = 99999999;
struct dinh
{
    int w,u,p;
    bool operator < (const dinh& x) const
    {
        return (w < x.w) || ((w==x.w) && (p < x.p)) || ((w==x.w) && (p==x.p) && (u <x.u));
    }
};

int n,m,k;
vector <pii> adj[nmax];
set <dinh> S;
int f[nmax][kmax];
int dd[nmax][kmax];

void doc()
{
    cin >> k >> n >> m;
    for (int i=1; i<=m; i++)
    {
        int u,v, c;
        cin >> u >> v >> c;
        adj[u].push_back(mp(v,c));
        adj[v].push_back(mp(u,c));
    }
}

void khoitao()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=k+1; j++) f[i][j] = vc;
}
void dijkstra()
{
    khoitao();
    dinh t;
    t.w = 0; t.u = 1; t.p = 1;
    S.insert(t);
    f[1][1] = 0;
    while (!S.empty())
    {
        t = *S.begin();
        S.erase(S.begin());
        int u = t.u;
        int w = t.w;
        int p = t.p;
        dd[u][p] = 1;
        for (int i=0; i<adj[u].size(); i++)
        {
            int v = (adj[u][i]).fi;
            int c = (adj[u][i]).se;
            int ww = f[u][p] + c;
            int j;
            for (j = 1; j<=k+1; j++)
            if (f[v][j] > ww) break;///xac dinh duong di ngan nhat tu 1->v la duong thu may
            if (j <= k)///neu con chua du k duong di ngan nhat va j tm <=k thi cap nhat lai duong di ngan thu j tu 1->v
            {
                set <dinh> :: iterator it;
                dinh tt;
                for (int jj=k; jj>=j+1;jj--)
                if (f[v][jj-1] != vc)
                {
                    tt.u = v; tt.w = f[v][jj-1]; tt.p = jj-1;
                    it = S.find(tt);
                    if (it != S.end())
                    {
                        tt.p++;
                        S.erase(it);
                        S.insert(tt);
                    }
                    f[v][jj] = f[v][jj-1];
                }
                f[v][j] = ww;
                tt.u = v; tt.w = ww; tt.p = j;
                S.insert(tt);
            }
        }
    }
}
void ghi()
{
    int s = 0;
    for (int i=1; i<=k; i++)s+=f[n][i];
    cout << s;
}
int main()
{
    freopen("relay.inp","r",stdin);
    freopen("relay.out","w",stdout);
    doc();
    dijkstra();
    ghi();
    return 0;
}
