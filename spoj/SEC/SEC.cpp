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
#define fn "SEC"  /// ___FILE_NAME_HERE___
#define rep(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define __rep(c,it) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();it++)

const int SIZE=2;
const int MAXN=1e4+4;
int n,m;
char s[MAXN];
struct trieNode
{
    trieNode *child[SIZE];
    bool isLeaf;
    int c;
    trieNode()
    {
        for(int i=0;i<=1;i++)child[i]=NULL;
        isLeaf=false;
        c=0;
    }
};
trieNode *root=new trieNode;
struct Trie
{
    void insertt(int len)
    {
        trieNode *froot=root;
        int cLeaf=0;
        for(int i=0;i<len;i++)
        {
            int bit=(int)(s[i]-'0');
            if(!froot->child[bit])
                froot->child[bit]=new trieNode;
            froot=froot->child[bit];
            cLeaf+=froot->isLeaf;
        }
        froot->isLeaf=true;
        froot->c=cLeaf+1;
    }
    int cnt(int len)
    {
        trieNode *froot=root;
        int ans=0;
        for(int i=0;i<len;i++)
        {
            int bit=(int)(s[i]-'0');
            if(!froot->child[bit])return ans;
            if(froot->child[bit])
                froot=froot->child[bit];
        }
        queue <trieNode*> q;
        q.push(froot);
        for(;sz(q);q.pop())
        {
            trieNode *node=q.front();
            bool ok=(node->child[0]==NULL and node->child[1]==NULL);
            if(ok)ans+=node->c;
            else
            {
                for(int i=0;i<=1;i++)
                    if(node->child[i])q.push(node->child[i]);
            }
        }
        return ans;
    }
};
Trie trie;

///xau do trung voi ca 1 xau khac,hoac la ca xau khac trung no.

int main(void)
{
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d",&n,&m);
    for(int len,i=1;i<=n;i++)
    {
        char ch;
        scanf("%d",&len);
        for(int j=0;j<len;j++)
            scanf(" %c",&s[j]);
        trie.insertt(len);
    }
    for(int len,i=1;i<=m;i++)
    {
        char ch;
        scanf("%d",&len);
        for(int j=0;j<len;j++)
            scanf(" %c",&s[j]);
        printf("%d\n",trie.cnt(len));
    }
}
