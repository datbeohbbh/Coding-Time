#include <bits/stdc++.h>
using namespace std;
queue <int> q;
bool dd[1000003];
 int dem=0;
void bfs(int u)
{
    q.push(u);
    while (!q.empty())
    {

        u=q.front();
        q.pop();
        if(u!=0)
        {
        for (int i=1;i<=sqrt(u);i++)
        {
            if (u%i==0)
            {
                int v=u/i;
                if (i<=v)
                {
                    if (dd[(i-1)*(v+1)]==0)
                    {
                        q.push((i-1)*(v+1));
                        dd[(i-1)*(v+1)]=1;
                        dem++;
                    }
                }
            }

        }
        }
    }

}
int main()
{
    int n;

    freopen("ZEROPATH.inp","r",stdin);
    freopen("ZEROPATH.out","w",stdout);
    cin>>n;
    bfs(n);
    cout<<dem<<endl;
    for (int i=0;i<=1000000;i++)
    {
        if (dd[i]==1) cout<<i<<" ";
    }


}
