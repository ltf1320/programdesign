#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
int N;
int AN1,AN;
struct Tree
{
    Tree *l,*r;
    char *str;
    int now;
    Tree(int n):l(0),r(0),str(0),now(n){}
    void reset()
    {
        if(l){l->reset();delete l;l=0;}
        if(r){r->reset();delete r;r=0;}
        if(str) delete str;
    }
    void init()
    {
        str=new char[maxn];
        str[0]='0';
        str[1]=0;
        now=-1;
        r=new Tree(maxn);
        r->str=new char[maxn];
        r->str[0]='1';
        r->str[1]=0;
    }
};
Tree head;
char *get(const char *a,const char *b)
{
    int i=0,n1=0;
    char *res=new char[maxn];
    while(a[i]==b[i])
    {
        res[i]=a[i];
        if(a[i]=='1') n1++;
        i++;
    }
    if(b[i+1]==0)
    {
        res[i]='0';
        while(a[i]!='1') {res[i]='1';i++;n1++;}
        res[i]='1';
        n1++;
        res[i+1]=0;
    }
    else if(b[i+1]=='0')
    {
        if(a[i+1]=='0')
        {
            res[i]='0';
            res[i+1]='1';
            n1++;
            res[i+2]=0;
        }
        else if(a[i+1]=='1')
        {
            res[i]='0';
            res[i+1]='1';n1++;
            i+=2;
            while(true)
            {
                if(a[i]=='0')
                {
                    res[i]='1';n1++;
                    break;
                }
                if(a[i+1]==0)
                {
                    res[i+1]=1;n1++;
                    res[i+2]=0;
                    break;
                }
            }
        }
        else if(a[i+1]==0)
        {
            res[i]=a[i];
            res[i+1]='1';
            n1++;
            res[i+2]=0;
        }
    }
    AN+=i;
    AN1+=n1;
    return res;
}



int main()
{
    int T,tmp;
    scanf("%d",&T);
    while(T--)
    {
        head.reset();
        AN=2;
        AN1=0;
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&tmp);
            insert(tmp);
        }
    }
    return 0;
}
