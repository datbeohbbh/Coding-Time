using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll>
#define pii pair<int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define fn "CHAIN2"  /// ___FILE_NAME_HERE___
#define rep(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define __rep(c,it) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();it++)

const int MAXN=26;
int n,ans=0;
string s;
set <string> st;
struct trieNode
{
    trieNode *child[MAXN];
    bool isLeaf;
    int cnt;
    trieNode()
    {
        for(int i=0; i<=25; i++)child[i]=NULL;
        isLeaf=false;
        cnt=0;
    }
};
trieNode *root=new trieNode;
struct Trie
{
    void insertt()
    {
        int cntLeaf=0;
        trieNode *froot=root;
        for(int i=0; i<sz(s); i++)
        {
            int idx=(int)(s[i]-'a');
            if(!froot->child[idx])
                froot->child[idx]=new trieNode;
            cntLeaf+=froot->child[idx]->isLeaf;
            froot=froot->child[idx];
        }
        froot->isLeaf=true;
        froot->cnt=cntLeaf+1;
    }
};
Trie trie;

queue <trieNode*> q;
int bfs()
{
    q.push(root);
    for(; q.size(); q.pop())
    {
        trieNode *node=q.front();
        ans=max(ans,node->cnt);
        for(int i=0; i<26; i++)
            if(node->child[i])
                q.push(node->child[i]);
    }
    return ans;
}

int main(void)
{
    cin.sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>s,st.insert(s);
    for(set <string> :: iterator it=st.begin(); it!=st.end(); it++)
        s=*it,trie.insertt();
    cout<<bfs();
}
///_______________________MY_SOLUTION_______________________
///+tom tat : cho n xau , tim 1 tap khac rong cac xau sao cho xau i la tien to cua xau i+1.tim tap co luc luong
///lon nhat .
///-thuat toan : trie,bfs.
///-truoc het thi nhan thay la dieu kien la tien to khi xau u co do dai nho hon v thi u la tien to cua v neu
///|u| ki tu dau cua v bang u.nhu vay ta can 1 thuat toan nao do co the tiep noi tien to cua cac xau nho hon.
///ereka!do la trie.ta lan luot dua n xau vao cay theo thu tu tang dan theo do dai.
///-1 dinh cua cay trie se co 3 thong tin sau.
///+con tro toi cac nut con.
///+1 bien isLeaf=true de danh dau dinh i nao do la kt cua xau dang dua vao cay,nguoc lai bang false.
///+1 bien cnt:so luong xau la tien to cua xau dang xet khi dua vao cay.
///-nhu vay khi dua 1 xau s vao cay ta chi can lam bt nhung bien cnt se cong voi isLeaf.vi isLeaf la bao hieu dinh
///do la kt cua 1 xau nao do ngan hon s.
///bay gio dat ra la ta phai duyet cay trie de den cac nut la va lay cap nhat kq.ta se dung bfs voi queue se luu
///con tro trieNode* loang tu goc,voi mot dinh lay max cnt cua dinh do.
///-luu y:ta co the lam nhanh hon ko can bfs bang cach khi cap nhat cho cnt khi insertt thi lay max luon cho nhanh
///skill:phan tich,toi uu hoa,nghi ro rang.
