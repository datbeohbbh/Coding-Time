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

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    class TreeNode{
    public:
        TreeNode *left,*right;
        int value;
    public:
        TreeNode(int val){
            this -> left = this -> right = nullptr;
            this -> value = val;
        }
        TreeNode(int val,TreeNode *ll,TreeNode *rr){
            this -> value = val;
            this -> left = ll;
            this -> right = rr;
        }
        void withLeaves(int val_l,int val_r){
            this -> left = new TreeNode(val_l);
            this -> right = new TreeNode(val_r);
        }
    };

    class Solution{
    public:

        static void dfs(TreeNode *root,int cur,int &ans){
            if(root -> left){
                dfs(root -> left,cur + root -> left -> value,ans);
            }
            if(root -> right){
                dfs(root -> right,cur + root -> right -> value,ans);
            }
            ans = max(ans, cur);
        }

         static int maxSum(TreeNode *root){
            if(!root) {
                return -1;
            }
            int ans = -2e9;
            dfs(root,root -> value,ans);
            return ans;
        }
    };

    void solve(){
        TreeNode *left = new TreeNode(-22);
        left -> withLeaves(9,50);
        TreeNode *right = new TreeNode(11);
        right -> withLeaves(9,2);
        TreeNode *root = new TreeNode(5,left,right);
        //root = nullptr;
        cout<<(new Solution) -> maxSum(root);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
