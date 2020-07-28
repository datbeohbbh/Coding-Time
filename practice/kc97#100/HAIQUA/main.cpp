#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> *a;
    a = new vector <int>;
    for(int i = 0;i < 10;++i){
        a -> push_back(i);
    }
    for(int i = 0;i < a -> size();++i){
        cout<<(*a)[i]<<'\n';
    }
    return 0;
}