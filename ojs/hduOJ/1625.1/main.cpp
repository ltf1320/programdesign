#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=50+10;

void rev(int* m,int l)
{
    int t;
    for(int i=0; i<l/2; ++i)
    {
        t=m[i];
        m[i]=m[l-i-1];
        m[l-i-1]=t;
    }
}

struct LNI
{
    int num[maxn];
    int n;
    int f;
    int read()
    {
        memset(num,0,sizeof(num));
        char *tem;
        tem=new char[maxn];
        if(scanf("%s",tem)==EOF) return EOF;
        change(tem);
        rev(num,n);
//反过来存，加减乘法会快，除法会略慢，若只有除法，可以正着存
        delete [] tem;
        return 0;
    }
    void change(char *tem)
    {
        f=1;
        if(*tem=='-')
        {
            f=-1;
            tem++;
        }
        while(*tem=='0')
            tem++;
        int l=strlen(tem);
        int p=l%4;
        int k=-1;
        if(p)
        {
            k++;
            num[k]=tem[0]-'0';
            for(int i=1; i<p; ++i)
            {
                num[k]=num[k]*10+tem[i]-'0';
            }
        }
        for(int i=p; i<l; ++i)
        {
            if(i%4==p)
            {
                k++;
                num[k]=tem[i]-'0';
            }
            else
            {
                num[k]=num[k]*10+tem[i]-'0';
            }
        }
        n=(l-1)/4+1;
    }
    void print()
    {
        rev(num,n);
        int i=0;
        if(f<0) putchar('-');
        printf("%d",num[i++]);
        for(; i<n; ++i)
            printf("%04d",num[i]);
        printf("\n");
    }
    LNI& operator ++(int)
    {
        int jw;
        int i=1;
        num[0]+=1;
        jw=num[0]/10000;
        while(jw)
        {
            num[i]+=jw;
            jw=num[i]/10000;
        }
        return *this;
    }
};

LNI operator-(LNI a,LNI b);
LNI operator/(LNI a,int n);


LNI operator+(LNI a,LNI b)
{
    LNI res;
    if(a.f*b.f==1)
    {
        res.f=a.f;
    }
    else
    {
        if(a.f<0)
        {
            a.f=1;
            return b-a;
        }
        else
        {
            b.f=1;
            return a-b;
        }
    }
    memset(res.num,0,sizeof(res.num));
    int jw=0;
    res.n=max(a.n,b.n);
    for(int i=0; i<res.n; ++i)
    {
        if(i<a.n && i<b.n)
        {
            res.num[i]=a.num[i]+b.num[i]+jw;
            jw=res.num[i]/10000;
            res.num[i]%=10000;
        }
        else if(i>=a.n)
        {
            res.num[i]=b.num[i]+jw;
            jw=res.num[i]/10000;
            res.num[i]%=10000;
        }
        else if(i>=b.n)
        {
            res.num[i]=a.num[i]+jw;
            jw=res.num[i]/10000;
            res.num[i]%=10000;
        }
    }
    if(jw)
    {
        res.num[res.n]=jw;
        res.n++;
    }
    return res;
}

bool operator<(const LNI &a,const LNI &b)
{
    if(a.f!=b.f) return a.f<b.f;
    if(a.n!=b.n) return a.f>0?(a.n<b.n):(a.n>b.n);
    for(int i=0; i<a.n; ++i)
        if(a.num[i]!=b.num[i]) return a.f>0?(a.num[i]<b.num[i]):(a.num[i]>b.num[i]);
    return 0;
}

LNI operator-(LNI a,LNI b)
{
    LNI res;
    if(a.f*b.f==-1)
    {
        b.f*=-1;
        return a+b;
    }
    res.f=a.f;
    if((a<b&&a.f>0)||(b<a&&a.f<0))
    {
        LNI t=a;
        a=b;
        b=t;
        res.f=-1*a.f;
    }
    memset(res.num,0,sizeof(res.num));
    int jw=0;
    res.n=max(a.n,b.n);
    for(int i=0; i<res.n; ++i)
    {
        if(i<a.n && i<b.n)
        {
            res.num[i]=a.num[i]-b.num[i]+jw;
            jw=0;
            if(res.num[i]<0)
            {
                jw=-1;
                res.num[i]+=10000;
            }
        }
        else if(i>=b.n)
        {
            res.num[i]=a.num[i]+jw;
            jw=0;
            if(res.num[i]<0)
            {
                jw=-1;
                res.num[i]+=10000;
            }
        }
    }
    while(res.num[res.n-1]==0)
        res.n--;
    return res;
}

LNI operator*(LNI a,LNI b)
{
    LNI res;
    res.f=a.f*b.f;
    memset(res.num,0,sizeof(res.num));
    int jw,k;
    for(int i=0; i<a.n; ++i)
    {
        for(int j=0; j<b.n; ++j)
        {
            res.num[i+j]+=a.num[i]*b.num[j];
            jw=res.num[i+j]/10000;
            res.num[i+j]%=10000;
            k=1;
            while(jw)
            {
                res.num[i+j+k]+=jw;
                jw=res.num[i+j+k]/10000;
                res.num[i+j+k]%=10000;
                k++;
            }
        }
    }
    int n=a.n+b.n-1;
    while(res.num[n++]);
    res.n=n-1;
    return res;
}




int mp[300];
int N,M,P;
int code;
struct Node
{
    Node *fail;
    Node *next[maxn];
    int code;
    bool end;
    Node()
    {
        fail=NULL;
        for(int i=0;i<maxn;i++)
            next[i]=NULL;
        end=0;
    }
};
Node Tree;


void insert(const char *s)
{
    int i=0;
    Node *now=&Tree;
    while(s[i])
    {
        if(now->next[mp[s[i]]]==NULL)
        {
            now->next[mp[s[i]]]=new Node();
            now->next[mp[s[i]]]->code=code++;
        }
        now=now->next[mp[s[i]]];
        i++;
    }
    now->end=1;
}

void BuildAC()
{
    Node *now,*tmp;
    queue<Node*> que;
    que.push(&Tree);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<N;i++)
            if(now->next[i]!=NULL)
            {
                que.push(now->next[i]);
                tmp=now->fail;
                while(tmp!=NULL&&tmp->next[i]==NULL)
                    tmp=tmp->fail;
                if(tmp==NULL)
                    now->next[i]->fail=&Tree;
                else if(tmp->next[i]!=NULL)
                {
                    if(tmp->next[i]->end)
                        now->next[i]->end=1;
                    now->next[i]->fail=tmp->next[i];
                }
            }
    }
}

struct Mat
{
    LNI m[maxn][maxn];
    Mat operator*(const Mat &a)
    {
        Mat res;
        for(int i=0;i<code;i++)
            for(int j=0;j<code;j++)
            {
                res.m[i][j].n=1;
                memset(res.m[i][j].num,0,sizeof(res.m[i][j]));
                for(int k=0;k<code;k++)
                    res.m[i][j]=res.m[i][j]+m[i][k]*a.m[k][j];
            }
        return res;
    }
    Mat operator^(int n)
    {
        Mat res;
        Mat now=*this;
        for(int i=0;i<code;i++)
        {
            memset(res.m[i][i].num,0,sizeof(res.m[i][i].num));
            res.m[i][i].num[0]=1;
            res.m[i][i].n=1;
        }
        while(n)
        {
            if(n&1) res=res*now;
            now=now*now;
            n>>=1;
        }
        return res;
    }
    void print()
    {
        for(int i=0;i<code;i++){
            for(int j=0;j<code;j++)
                printf("%d ",m[i][j]);
            printf("\n");
        }
    }
};

void work()
{
    Mat dp;
    Node *now,*tmp;
    memset(dp.m,0,sizeof(dp.m));
    queue<Node *> que;
    que.push(&Tree);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<N;i++)
        {
            if(now->next[i]!=NULL)
            {
                if(!now->next[i]->end)
                {
                    que.push(now->next[i]);
                    dp.m[now->code][now->next[i]->code]++;
                }
                continue;
            }
            tmp=now->fail;
            while(tmp!=NULL&&tmp->next[i]==NULL)
                tmp=tmp->fail;
            if(tmp==NULL)
                dp.m[now->code][0]++;
            else if(!tmp->next[i]->end)
                dp.m[now->code][tmp->next[i]->code]++;
        }
    }
    dp.print();
    dp=dp^M;
    LNI res;
    res.n=1;
    memset(res.num,0,sizeof(res.num));
    for(int i=0;i<code;i++)
    {
        res=res+dp.m[0][i];
    }
    res.print();
}

void init()
{
    memset(mp,-1,sizeof(mp));
    Tree.code=0;
    code=1;
}

void input()
{
    char tmp[maxn];
    char ch;
    scanf("%d%d%d",&N,&M,&P);
    ch=getchar();
    for(int i=0;i<N;i++)
    {
        ch=getchar();
        mp[ch]=i;
    }
    getchar();
    for(int i=0;i<P;i++)
    {
        scanf("%s",tmp);
        insert(tmp);
    }
    BuildAC();
}

int main()
{
    freopen("in.txt","r",stdin);
    init();
    input();
    work();
    return 0;
}
