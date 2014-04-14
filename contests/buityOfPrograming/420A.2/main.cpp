#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
int N;
int AN1,AN;

char str[maxn][maxn*100];

void init()
{
    str[0][0]='0';
    str[0][1]=0;
    str[1002][0]='1';
    str[1002][1]=0;
}
char *get(const char *a,const char *b)
{
    int i=0,n1=0;
    char *res=new char[maxn*100];
    while(a[i]==b[i])
    {
        if(!a[i]) break;
        res[i]=a[i];
        if(a[i]=='1') n1++;
        i++;
    }
    if(b[i+1]==0)
    {
        res[i]='0';
        i++;
        while(a[i]&&a[i]=='1') {res[i]='1';i++;n1++;}
        res[i++]='1';
        n1++;
        res[i]=0;
    }
    else if(b[i+1]=='0')
    {
        if(a[i+1]=='0')
        {
            res[i++]='0';
            res[i++]='1';
            n1++;
            res[i]=0;
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
                    res[i++]='1';n1++;
                    res[i]=0;
                    break;
                }
                if(a[i]==0)
                {
                    res[i++]='1';n1++;
                    res[i]=0;
                    break;
                }
                res[i++]='1';
            }
        }
        else if(a[i+1]==0)
        {
            res[i]=a[i];i++;
            res[i++]='1';
            n1++;
            res[i]=0;
        }
    }
    AN+=i;
    AN1+=n1;
    return res;
}

void insert(int n)
{
    char *tt;
    int l,r;
    l=n-1;
    while(str[l][0]==0)
        l--;
    r=n+1;
    while(str[r][0]==0)
        r++;
    tt=get(str[l],str[r]);
    strcpy(str[n],tt);
    delete tt;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T,tmp;
    int cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        memset(str,0,sizeof(str));
        init();
        AN=2;
        AN1=1;
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&tmp);
            tmp++;
            insert(tmp);
        }
        printf("Case #%d: %d %d\n",cas,AN,AN1);
    }
    return 0;
}
