using namespace std;
#include<bits/stdc++.h>

map <string,int> m;
string s,res="";
int n;

main(void)
{
    scanf("%d\n",&n);
    for(int i=1; i<=n; i++)
    {
        getline(cin,s);
        m[s]++;
    }
    for(map <string,int> :: iterator it=m.begin(); it!=m.end(); it++)
        if((it->second) % 2 !=0)
        {
            cout<<(it->first);
            return 0;
        }
    cout<<-1;
}
