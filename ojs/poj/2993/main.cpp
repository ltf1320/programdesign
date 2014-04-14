#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=20;
char piece[maxn][maxn];

char p[50];
inline void printLine()
{
    printf("+---+---+---+---+---+---+---+---+\n");
}
int main()
{
    freopen("in.txt","r",stdin);
    char type,c,ch;
    int r;
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            if((i+j)%2)
                piece[i][j]='.';
            else piece[i][j]=':';
    //white
    for(int i=0;i<7;i++)
        getchar();
    while((type=getchar())!='\n')
    {
        if(type>=97&&type<=122)
        {
            scanf("%d%c",&r,&ch);
            piece[r][type-'a'+1]='P';
            if(ch=='\n') break;
        }
        else
        {
            scanf("%c%d%c",&c,&r,&ch);
            piece[r][c-'a'+1]=type;
            if(ch=='\n') break;
        }
    }
    //black
    for(int i=0;i<7;i++)
        getchar();
    while((type=getchar())!='\n')
    {
        if(type>=97&&type<=122)
        {
            scanf("%d%c",&r,&ch);
            piece[r][type-'a'+1]='p';
            if(ch=='\n') break;
        }
        else
        {
            scanf("%c%d%c",&c,&r,&ch);
            piece[r][c-'a'+1]=tolower(type);
            if(ch=='\n') break;
        }
    }
    //print
    printLine();
    for(int i=8;i>0;i--)
    {
        for(int j=1;j<=8;j++)
            if((i+j)%2) printf("|.%c.",piece[i][j]);
            else printf("|:%c:",piece[i][j]);
        printf("|\n");
        printLine();
    }
    return 0;
}
