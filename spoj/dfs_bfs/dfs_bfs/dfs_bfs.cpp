#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;//so dinh toi da la 10^5 dinh,thi khai bao thua ra 1 ti
vector <int> adj[N];//ma hoa do thi
int n,m,cnt=0;
bool vis[N];//mang danh dau

queue <int> q;
void bfs(int u)
{
    cout<<"tham thanh phan lien thong thu "<<cnt<<endl;
    q.push(u);
    vis[u]=1;//dinh u da tham thi danh la 1
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        cout<<u<<' ';
        for(int i=0;i<adj[u].size();++i)
        {
            int v=adj[u][i];
            if(vis[v]==0) // v chua tham
            {
                q.push(v);// cho v vao queue.hieu nhu la tham v
                vis[v]=1;//danh dau v da tham.
            }
        }
    }
    cout<<endl;
}

void dfs(int u)
{
    vis[u]=1;//da tham u
    cout<<u<<' ';
    for(int i=0;i<adj[u].size();++i)
    {
        int v=adj[u][i];
        if(vis[v]==0)
            dfs(v);
    }
}

int main()
{
    ///chuong trinh in ra qua trinh tham dfs/bfs cua 1 do thi (do thi co the co nhieu thanh phan lien thong)
    freopen("dfs_bfs.inp","r",stdin);
    freopen("dfs_bfs.out","w",stdout);
    cin>>n>>m; //so dinh,so canh cua do thi
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); ///neu do thi mot chieu
        adj[v].push_back(u); ///do thi 2 chieu thi them cai nay
    }
    cout<<"duyet bfs :"<<endl;
    for(int i=1;i<=n;++i)
        if(vis[i]==0)//mang vis[] danh dau dinh i da tham hay chua,chua tham thi tham
    {
        cnt++;
        bfs(i);    cout<<"tham thanh phan lien thong thu "<<cnt<<endl;
    }
    cout<<endl<<endl;
    memset(vis,false,sizeof(vis));
    cnt=0;
    cout<<"duyet dfs :"<<endl;
    for(int i=1;i<=n;++i)
        if(vis[i]==0)
    {
        cnt++;
        cout<<"tham thanh phan lien thong thu "<<cnt<<endl;
        dfs(i);
        cout<<endl;
    }
}
