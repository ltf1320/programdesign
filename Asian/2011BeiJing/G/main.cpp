#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=1000+10;
int N;
char cmd[100+10][50];

struct Star
{
    float x,y,z;
    void rotate(int &a,int &b,int &c,int &d)
    {

    }
};
Star st[maxn];

void input()
{
    int rep=1;
    scanf("%d",&N);
    gets(cmd[0]);
    for(int i=0; rep; i++)
    {
        gets(cmd[i]);
        if(cmd[i][0]=='r') rep++;
        if(cmd[i][0]=='e') rep--;
    }
    for(int i=0; i<N; i++)
        scanf("%f%f%f",&st[i].x,&st[i].y,&st[i].z);
}
int nl;
void repeat(int n)
{
    int k,tmpx,tmpy,tmpz,tmpd;
    int knl=nl;
    while(n--)
    {
        nl=knl;
        while(cmd[nl][1]!='n')
        {
            switch(cmd[nl][1])
            {
            case 'e':
                k=0;
                while(cmd[nl][k]!=' ')
                    k++;
                k++;
                sscanf(cmd[nl]+k,"%d",&tmpx);
                nl++;
                repeat(tmpx);
                break;
            case 'r':
                k=0;
                while(cmd[nl][k]!=' ')
                    k++;
                k++;
                sscanf(cmd[nl]+k,"%d%d%d",&tmpx,&tmpy,&tmpz);
                for(int i=0; i<N; i++)
                {
                    st[i].x+=tmpx;
                    st[i].y+=tmpy;
                    st[i].z+=tmpz;
                }
                break;
            case 'c':
                k=0;
                while(cmd[nl][k]!=' ')
                    k++;
                k++;
                sscanf(cmd[nl]+k,"%d%d%d",&tmpx,&tmpy,&tmpz);
                for(int i=0; i<N; i++)
                {
                    st[i].x*=tmpx;
                    st[i].y*=tmpy;
                    st[i].z*=tmpz;
                }
                break;
            case 'o':
                k=0;
                while(cmd[nl][k]!=' ')
                    k++;
                k++;
                sscanf(cmd[nl]+k,"%d%d%d%d",&tmpx,&tmpy,&tmpz,&tmpd);
                for(int i=0;i<N;i++)
                    st[i].rotate(tmpx,tmpy,tmpz,tmpd);
                break;
            }
        }
    }
}

void work()
{
    nl=0;
    repeat(1);
    for(int i=0;i<N;i++)
        printf("%.1f%.1f%.1f",st[i].x,st[i].y,st[i].z);
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        input();
        work();
    }
    return 0;
}
