using namespace std;
#include<bits/stdc++.h>
#define ll int

const ll MAXN=5001;
ll F[MAXN][MAXN],n,M,k;
string X,Y,S;

void ReadData()
{
    freopen("NKPALIN.INP","r",stdin);
    freopen("NKPALIN.OUT","w",stdout);
    cin>>X;
    for(int i=X.size()-1; i>=0; i--)Y.push_back(X[i]);
    X=' '+X;  Y=' '+Y;  n=X.size()-1;  M=n;
}

void Optimize()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=M; j++)
        {
            if(X[i]==Y[j])F[i][j]=F[i-1][j-1]+1;
            else F[i][j]=max(max(F[i-1][j],F[i-1][j-1]),F[i][j-1]);
        }
}

void Traces()
{
    while(M!=0 && n!=0)
    {
        if(X[n]==Y[M])
        {
            S.push_back(X[n]);
            n--;
            M--;
        }
        else if(F[n][M]==F[n-1][M-1])
        {
            n--;
            M--;
        }
        else if(F[n][M]==F[n-1][M])n--;
        else if(F[n][M]==F[n][M-1])M--;
    }
    cout<<S;
}

main(void)
{
    ReadData();
    Optimize();
    Traces();
}
