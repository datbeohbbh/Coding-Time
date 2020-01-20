//#include "t04_students.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

int t04_students() {
    int n;
    cin>>n;
    vector <pair <int,string> > ve;
    for(int i = 0;i < n;i++){
    	string a,b;
    	int x,y,z;
        cin>>a>>b>>x>>y>>z;
        ve.push_back(make_pair(x + y + z,a + " " + b));
    }
    sort(ve.rbegin(),ve.rend());
    for(int i = 0;i < ve.size();++i){
    	cout<<ve[i].second<<'\n';
    }
}

int main(void){
	int c = t04_students();
}
