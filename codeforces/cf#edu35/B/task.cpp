#include <iostream>
using namespace std;

int main() {
	long long number;
	cin>>number;
	while(true){
		bool found = false;
		long long mask = 27LL;
		long long re_mask = 14LL;
		for(int i = 0;i < 64;++i){
			if((number & (mask << i)) == (mask << i)){
				found = true;
				number ^= (mask << i);
				number |= (re_mask << i);
				break;
			}
		}
		if(!found){
			break;
		}
	}
	cout<<number;
	return 0;
}
