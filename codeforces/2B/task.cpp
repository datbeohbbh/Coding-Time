#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int main() {
	for(int i = 2;i <= 200000;++i){
		int x = i;
		for(int j = 2;j <= x;++j){
			if(x % j)continue;
			while(x % j == 0)
			  x/=j;
			v.push_back(j);
		}
		if(x > 1)
		  v.push_back(x);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	cout<<v.size();
	return 0;
}
