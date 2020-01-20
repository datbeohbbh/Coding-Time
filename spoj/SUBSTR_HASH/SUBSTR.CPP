using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=1e6+6;
const ll base=1e9+7;
ll hashA[MAXN],ppow[MAXN],hashB=0,n,m;
string a,b;

ll gethash(ll i,ll j)
{
    return (hashA[j]-hashA[i-1]*ppow[j-i+1]+base*base)%base;
    //ppow[j-i+1] cung bang ppow[n]
}

main(void)
{
    //freopen("substr.inp","r",stdin);
    //freopen("substr.out","w",stdout);
    cin>>a>>b;
    n=b.size();
    m=a.size();
    a=' '+a;
    b=' '+b;
    ppow[0]=1;
    for(int i=1; i<=n; i++)hashB=(hashB*26+b[i]-'a')%base;
    for(int i=1; i<=m; i++)ppow[i]=(ppow[i-1]*26)%base;
    for(int i=1; i<=m; i++)hashA[i]=(hashA[i-1]*26+a[i]-'a')%base;
    for(int i=1; i<=m-n+1; i++)// gia su i la vi tri xuat phat co the cua xau b trong a ==> [i..i+n-1] = b.size()
        if(hashB==gethash(i,i+n-1))cout<<i<<" ";
    return 0;
}
