using namespace std;
#include<bits/stdc++.h>

typedef string bignum;
const int MAXN=555;
int F[MAXN][MAXN],n,m,RemX[MAXN],RemY[MAXN],k=0;
bignum X,Y,S="",maxx="";
bool ok=true;

bool cmp(bignum A,bignum B)
{
    return (A.size()>B.size()) || (A.size()==B.size() && A>B);
}

void ReadData()
{
    freopen("NUMBER.INP","r",stdin);
    freopen("NUMBER.OUT","w",stdout);
    cin>>X>>Y;
    X=' '+X;
    Y=' '+Y;
    n=X.size()-1;
    m=Y.size()-1;
}

void Traces(int i,int j)
{
    int d=0,t=0;
    while(i>0 && j>0)
    {
        if(X[i]==Y[j] && X[i]!=' ')
        {
            RemX[++d]=i;
            RemY[++t]=j;
            S.push_back(X[i]);
            i--;
            j--;
        }
        else if(F[i][j]==F[i-1][j-1])
        {
            i--;
            j--;
        }
        else if(F[i][j]==F[i-1][j])i--;
        else if(F[i][j]==F[i][j-1])j--;
    }
    if(S=="")
    {
        ok=false;
        return ;
    }
    memset(F,0,sizeof(F));
    while(S[0]=='0')S.erase(0,1);
    if(cmp(S,maxx))maxx=S;
    else {
    for(int i=1; i<=d; i++)X.erase(RemX[i],1);
    for(int i=1; i<=t; i++)Y.erase(RemY[i],1);
    }
    n=X.size()-1;
    m=Y.size()-1;
    S="";
}

void Optimize()
{
    while(ok)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(X[i]==Y[j])F[i][j]=F[i-1][j-1]+1;
                else F[i][j]=max(max(F[i-1][j],F[i][j-1]),F[i-1][j-1]);
        Traces(n,m);
    }
    for(int i=maxx.size()-1; i>=0; i--)cout<<maxx[i];
}

main(void)
{
    ReadData();
    Optimize();
    /*

    */
}
