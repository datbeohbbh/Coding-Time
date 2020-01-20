using namespace std;
#include<bits/stdc++.h>

set <string> s;
int k,n,sz;

main(void)
{
    scanf("%d\n",&k);
    for(int i=1; i<=k; i++)
    {
        scanf("%d\n",&n);
        for(int i=1; i<=n; i++)
        {
            string name;
            getline(cin,name);
            s.insert(name);
        }
    }
    sz=s.size();
    printf("%d",sz);
}
