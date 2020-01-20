using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=2222;
struct Palin
{
    string ss;
    ll pos;
};
Palin P[MAXN];
ll F[MAXN][MAXN],n,M,k,d=0;
string X,Y,S="",Str;

bool cmp(Palin A,Palin B){return (A.pos<B.pos);}

void ReadData()
{
    freopen("COUNTPL.INP","r",stdin);
    freopen("COUNTPL.OUT","w",stdout);
    cin>>n;   cin>>X;
    for(int i=X.size()-1;i>=0;i--)Y.push_back(X[i]);
    X=' '+X;   Y=' '+Y;   M=n;   Str=X;
}

void Traces(ll i,ll j)
{
    while(i>0 && j>0)
    {
        if(X[i]==Y[j] && X[i]!=' ')
        {
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
    k=F[n][M];
    i=X.find(S);   X.erase(i,k);
    j=Y.find(S);   Y.erase(j,k);
    n=X.size()-1;  M=n;
    P[d].ss=S;     P[d].pos=Str.find(S);
    S="";
}

void Palindrome()
{
    while(n>0 && M>0)
    {
        d++;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=M;j++)
              if(X[i]==Y[j])F[i][j]=F[i-1][j-1]+1;
                  else F[i][j]=max(max(F[i-1][j],F[i][j-1]),F[i-1][j-1]);
        Traces(n,M);
        memset(F,0,sizeof(F));
    }
}

void PrintResult()
{
    sort(P+1,P+1+d,cmp);
    cout<<d<<endl;
    for(int i=1;i<=d;i++)cout<<P[i].ss<<endl;
}

main(void)
{
    ReadData();
    Palindrome();
    PrintResult();
}
