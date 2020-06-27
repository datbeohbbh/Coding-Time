using namespace std;
#include<bits/stdc++.h>
#define ll long long
ll n;
ll a[1010][1010],b[1010][1010];

main(void)
{
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
        }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
            {
                ll coun=0;
                for(int ii=1; ii<=n; ii++)
                    for(int jj=1; jj<=n; jj++)
                        if(abs(ii-i)+abs(jj-j)==k-1 && a[ii][jj]==1)coun++;
                if(coun>1)b[i][j]=1;
            }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cout<<b[i][j]<<" ";
        cout<<endl;
    }
}
