#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50000+10;
const int inf=0x3f3f3f3f;
char str[maxn];
char P[maxn];
int lenS,lenP;
int main()
{
    freopen("in.txt","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    int res=inf,now;
    while(T--)
    {
        cas++;
        res=inf;
        scanf("%s",str);
        scanf("%s",P);
        lenS=strlen(str);
        lenP=strlen(P);
        for(int i=0;i<lenS-lenP+1;i++){
            now=0;
            for(int j=0;j<lenP;j++)
                if(str[i+j]!=P[j]) now++;
            res=min(now,res);
        }
        printf("Case #%d: %d\n",cas,res);
    }
    return 0;
}
