#include <bits/stdc++.h>

using namespace std;

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x = y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x = y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rand __rand
mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
template <class T = int>
T rand(T range = numeric_limits <T> :: max()){
    return (T) (generator() % range);
}


#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

/*    --------------------------------- TEST GENERATOR RULES ---------------------------------
 *
 *  - creat 3 file test.inp , test.out , gtest.out and keep original file main.cpp
 *
 *  - add to cmake this line : add_executable(test test.cpp)
 *
 *  - close stream input and output right after done with it.
 */

#define RED     "\033[31m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"

namespace task {

    class Solver{
    private:
        // variables
    public:
        Solver(){}
        ~Solver(){ // CLEAN

        }
        void solve(ifstream &cin,ofstream &cout){ // your code goes here

            cin.close();
            cout.close();
        }
    };

    void solve() {
        ifstream cin("test.inp");
        ofstream cout("test.out");
        (new Solver) -> solve(cin,cout);
    }
}

namespace TestGenerator {

    class Solver{
    private:
        // variables
    public:
        Solver(){}
        ~Solver(){ // CLEAN

        }
        void solve(ifstream &cin,ofstream &cout){ // your code goes here

            cin.close();
            cout.close();
        }
    };

    void solve() {
        ifstream cin("test.inp");
        ofstream cout("gtest.out");
        (new Solver) -> solve(cin,cout);
    }

    string getInformation(ifstream &file) {
        char c;
        string ret = "";
        while (file . get(c)) {
            ret += c;
        }
        file . close();
        while (ret . back() == '\n') {
            ret . pop_back();
        }
        return ret;
    }

    bool check(string out_a,string out_b){
        // checker
        return true;
    }

    bool compareFile() {
        ifstream a("test.out");
        ifstream b("gtest.out");
        string out_a = getInformation(a);
        string out_b = getInformation(b);
        return (out_a == out_b);
    }

    void testing(const int NUM_TEST) {
        for (int test_id = 1; test_id <= NUM_TEST; ++test_id) {
            ofstream gentest("test.inp");

            // ------- test area --------//
            cout << "running on test :" << ' ' << test_id << '\n';
            cout <<"input of test " << test_id << ' ' << ":" << '\n';



            // ------- test area --------//

            gentest . close();

            task::solve();
            TestGenerator::solve();
            bool flag = TestGenerator::compareFile();
            cout<<"test "<<test_id<<" : ";
            if (!flag) {
                cout<<RED<<"failed"<<RESET<<'\n'<<'\n';
                cout<<RED<<"status : failed"<<RESET;
                exit(0);
            } else {
                cout<<GREEN<<"passed"<<RESET<<'\n';
            }
            cout << '\n';
        }
        cout<<GREEN<<"status : accepted"<<RESET;
    }
}

int main(void){
    TestGenerator::testing(5);
    //task::solve();
}
