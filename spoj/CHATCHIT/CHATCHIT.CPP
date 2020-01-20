using namespace std;
#include<bits/stdc++.h>

string s[300],st="",ss="";
int n=0;

main(void)
{
    freopen("chat.inp","r",stdin);
    freopen("chat.out","w",stdout);
    getline(cin,st);
    for(int i=0; i<st.size(); i++)
    {
        if(st[i]!=' ')ss+=st[i];
        else
        {
            s[++n]=ss;
            ss="";
        }
    }
    s[++n]=ss;
    for(int i=1; i<=n; i++)
    {
        if(s[i]=="k" || s[i]=="ko" || s[i]=="hok")s[i]="khong";
        else if(s[i]=="ng")s[i]="nguoi";
        else if(s[i]=="n")s[i]="nhieu";
        else if(s[i]=="dc")s[i]="duoc";
        else if(s[i]=="ntn")s[i]="nhu the nao";
        else if(s[i]=="kq")s[i]="ket qua";
        else
        {
            for(int j=0; j<(s[i]).size(); j++)
                if((s[i])[j]=='w' || (s[i])[j]=='f' || (s[i])[j]=='dz' || (s[i])[j]=='z' || (s[i])[j]=='j')
                {
                    string st1="",st2="",st3="";
                    for(int k=0; k<j; k++)st1+=(s[i])[k];
                    for(int k=j+1; k<(s[i]).size(); k++)st2+=(s[i])[k];
                    if((s[i])[j]=='dz' || (s[i])[j]=='z')st3="d";
                    else if((s[i])[j]=='w')st3="qu";
                    else if((s[i])[j]=='f')st3="ph";
                    else if((s[i])[j]=='j')st3="gi";
                    s[i]=st1+st3+st2;
                    break;
                }
        }
    }
    for(int i=1; i<=n-1; i++)cout<<s[i]<<" ";
    cout<<s[n];
}
