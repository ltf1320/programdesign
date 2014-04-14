#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
int M,K;
const int maxn=1000+10;
const int maxk=26;
char str1[maxn];
char str2[maxn];

LL cp[maxk][maxk];

void floyd()
{
    for(int i=0;i<maxk;i++)
        for(int j=0;j<maxk;j++)
            for(int k=0;k<maxk;k++)
                if(cp[j][i]+cp[i][k]<cp[j][k])
                    cp[j][k]=cp[j][i]+cp[i][k];
}

int main()
{
    freopen("in.txt","r",stdin);
    char f,t;
    LL w, res;
    int len;
    while(~scanf("%s%s",str1,str2))
    {
        len=strlen(str1);
        cin>>M>>K;
        for(int i=0;i<maxk;i++)
            for(int j=0;j<maxk;j++)
                if(i==j)cp[i][j]=0;
                else cp[i][j]=K;
        for(int i=0;i<M;i++)
        {
            getchar();
            cin>>f>>t>>w;
            cp[f-'a'][t-'a']=min(cp[f-'a'][t-'a'],w);
        }
        floyd();
        res=0;
        for(int i=0;i<len;i++)
            res+=cp[str1[i]-'a'][str2[i]-'a'];
        cout<<res<<endl;
    }
    return 0;
}
