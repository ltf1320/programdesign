#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=20;
int arr[maxn];
char s1[maxn],s2[maxn],tp[maxn];
int now[maxn];
char res[10][maxn]={"light","EVEN","heavy"};

void even()
{
    for(int i=0;i<strlen(s1);i++)
        arr[s1[i]-'A']=1;
    for(int i=0;i<strlen(s2);i++)
        arr[s2[i]-'A']=1;
}

void down()
{
    memset(now,0,sizeof(now));
    for(int i=0;i<strlen(s1);i++)
    {
        if(arr[s1[i]-'A']!=1)
        {
            if(arr[s1[i]-'A']==2)
                arr[s1[i]-'A']=1;
            else arr[s1[i]-'A']=0;
        }
        now[s1[i]-'A']=1;
    }
    for(int i=0;i<strlen(s2);i++)
    {
        if(arr[s2[i]-'A']!=1)
        {
            if(arr[s2[i]-'A']==0)
                arr[s2[i]-'A']=1;
            else arr[s2[i]-'A']=2;
        }
        now[s2[i]-'A']=1;
    }
    for(int i=0;i<12;i++)
        if(!now[i])
            arr[i]=1;
}

void up()
{
    memset(now,0,sizeof(now));
    for(int i=0;i<strlen(s1);i++)
    {
        if(arr[s1[i]-'A']!=1)
        {
            if(arr[s1[i]-'A']==0)
                arr[s1[i]-'A']=1;
            else arr[s1[i]-'A']=2;
        }
        now[s1[i]-'A']=1;
    }
    for(int i=0;i<strlen(s2);i++)
    {
        if(arr[s2[i]-'A']!=1)
        {
            if(arr[s2[i]-'A']==2)
                arr[s2[i]-'A']=1;
            else arr[s2[i]-'A']=0;
        }
        now[s2[i]-'A']=1;
    }
    for(int i=0;i<12;i++)
        if(!now[i])
            arr[i]=1;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(arr,-1,sizeof(arr));
        for(int i=0;i<3;i++)
        {
            scanf("%s%s%s",s1,s2,tp);
            switch(tp[0])
            {
                case 'e':
                    even();break;
                case 'u':
                    up();break;
                case 'd':
                    down();break;
            }
        }
        for(int i=0;i<12;i++)
            if(arr[i]!=1)
            {
                printf("%c is the counterfeit coin and it is %s.\n",i+'A',res[arr[i]]);
                break;
            }
    }
    return 0;
}
