using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll res1[]={0,1,2,4,8,16,23,46,29,58,116,223,446,289,578,1156,1223,2446,2489,4789,5789,11578,12356,12247,24449,48889,77789};
const ll res2[]={77789,155578,111356,122227,244445,48889};
ll n;
main(void)
{
    freopen("C11SEQ3.INP","r",stdin);
    freopen("C11SEQ3.OUT","w",stdout);
    cin>>n;
    if(n<=26)cout<<res1[n];
    else cout<<res2[(n-26)%6];
}
