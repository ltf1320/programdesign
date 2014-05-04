#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn=150+10;
const int maxl=50;
const int inf=20000;

int N,L;
char str[maxn][maxl];

struct Node
{
    Node *l,*r;
    int num;
    vector<int> has;
    Node()
    {
        l=0;
        r=0;
        num=0;
    }
    void clear()
    {
        if(l)
        {
            l->clear();
            l=0;
        }
        if(r)
        {
            r->clear();
            r=0;
        }
        num=0;
    }
};
Node root;


void insert(char *s)
{
    Node *now=&root;
    while(s)
    {
        now->num++;
        switch(s[0])
        {
        case '0':
            if(!now->l)
                now->l=new Node();
            now=now->l;
            break;
        case '1':
            if(!now->r)
                now->r=new Node();
            now=now->r;
            break;
        }
        s++;
    }
}

vector<Node *> vn[2];

int dfs(vector<Node*> a,int dep)
{
    if(a.size()==0)
        return 0;
    int flag=3;
    for(int i=0; i<a.size(); i++)
    {
        int ln=0,rn=0;
        for(int j=0; j<a[i]->has.size(); j++)
        {
            if(str[a[i]->has[j]][dep]=='0')
                ln++;
            else rn++;
        }
        int nln=0,nrn=0;
        if(a[i]->l)
            nln=a[i]->l->num;
        if(a[i]->r)
            nrn=a[i]->r->num;
        if(ln!=nln||rn!=nrn)
            flag&=2;
        if(ln!=nrn||rn!=nln)
            flag&=1;
    }
    int res=inf;
    if(flag&1)
    {
        vector<Node*> nx;
        for(int i=0; i<a.size(); i++)
        {
            if(a[i]->l)
            {
                a[i]->l->has.clear();
                nx.push_back(a[i]->l);
            }
            if(a[i]->r){
                a[i]->r->has.clear();
                nx.push_back(a[i]->r);
            }
            for(int j=0; j<a[i]->has.size(); j++)
            {
                if(str[a[i]->has[j]][dep]=='0')
                    a[i]->l->has.push_back(a[i]->has[j]);
                else a[i]->r->has.push_back(a[i]->has[j]);
            }
        }
        res=min(res,dfs(nx,dep+1));
    }
    if(flag&2)
    {
        vector<Node*> nx;
        for(int i=0; i<a.size(); i++)
        {
            if(a[i]->l)
            {
                a[i]->l->has.clear();
                nx.push_back(a[i]->l);
            }
            if(a[i]->r){
                a[i]->r->has.clear();
                nx.push_back(a[i]->r);
            }
            for(int j=0; j<a[i]->has.size(); j++)
            {
                if(str[a[i]->has[j]][dep]=='1')
                    a[i]->l->has.push_back(a[i]->has[j]);
                else a[i]->r->has.push_back(a[i]->has[j]);
            }
        }
        res=min(res,dfs(nx,dep+1))+1;
    }
    return res;
}

void input()
{
    scanf("%d%d",&N,&L);
    char tmp[maxl];
    for(int i=0;i<N;i++)
    {
        scanf("%s",tmp);
        insert(tmp);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%s",str[i]);
    }
}

void init()
{
    root.clear();
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        init();
        input();
        vector<Node*> a;
        a.push_back(&root);
        int res=dfs(a,0);
        printf("Case #%d: ",cas);
        if(res==inf)
            printf("NOT POSSIBLE\n");
        else printf("%d\n",res);
    }
    return 0;
}
