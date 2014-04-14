#include"iostream"
#define INF -99999999
using namespace std;
int d[110],next[110][110],son[110],bro[110],c[110],f[110],n,k,maxt[2][110][210],r;
void Zh(int p)
{
    f[p]=1;
    for(int i=0; i<d[p]; i++) if (!f[next[p][i]])
        {
            bro[next[p][i]]=son[p];
            son[p]=next[p][i];
            Zh(next[p][i]);
        }
    memset(maxt,-1,sizeof(maxt));
}
void Inp(void)
{
    int i,j,k;
    memset(d,0,sizeof(d));
    for(i=1; i<=n; i++)
        scanf("%d",&c[i]);
    for(i=0; i<n-1; i++)
    {
        scanf("%d%d",&j,&k);
        next[j][d[j]++]=k;
        next[k][d[k]++]=j;
    }
    memset(bro,0,sizeof(bro));
    memset(son,0,sizeof(son));
    memset(f,0,sizeof(f));
    Zh(1);
}
int Loop(int b,int p,int m) //b==0 back to root b==1 no need to root
{
    int i,mt;
    if (maxt[b][p][m]!=-1) return maxt[b][p][m];
    if (!p) return maxt[b][p][m]=0;
    if (m==0) return maxt[b][p][m]=max(Loop(b,bro[p],m),c[p]);
    if (b==0)
    {
        mt=Loop(0,bro[p],m);
        if (m>=2)
        {
            mt=max(mt,c[p]+Loop(0,bro[p],m-2));
            mt=max(mt,c[p]+Loop(0,son[p],m-2));
        }
        for(i=0; i<=m-4; i++) mt=max(mt,Loop(0,bro[p],i)+Loop(0,son[p],m-4-i)+c[p]);
        return maxt[b][p][m]=mt;
    }
    else
    {
        mt=Loop(1,bro[p],m);
        mt=max(mt,c[p]+Loop(1,son[p],m-1));
        if (m>=2) mt=max(mt,c[p]+Loop(1,bro[p],m-2));
        for(i=0; i<=m-4; i++) mt=max(mt,Loop(1,bro[p],i)+Loop(0,son[p],m-4-i)+c[p]);
        for(i=0; i<=m-3; i++) mt=max(mt,Loop(0,bro[p],i)+Loop(1,son[p],m-3-i)+c[p]);
        return maxt[b][p][m]=mt;
    }
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        Inp();
        r=Loop(1,1,k);
        printf("%d\n",r);
    }
    return 0;
}
