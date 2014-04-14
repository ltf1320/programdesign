#include <stdio.h>
const int inf=100000000;
const int N=100005;
const int M=105;
int v[M],lw[M],rw[M],h[N];
int min(int a,int b)
{
    return (a<b)?a:b;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,c,i,j,k;
    int lh=-1;
    while(scanf("%d%d",&n,&c)!=EOF)
    {
        int mh=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&h[i]);
            mh=(h[i]>mh)?h[i]:mh;
        }
        v[1]=inf;
        for(i=h[1]; i<=mh; i++) //从h1循环到maxh
            v[i]=(i-h[1])*(i-h[1]);
        //计算出第一个电线杆增加的所有高度的花费

        //lw:自己升高,rw:下一个升高
        lw[ h[1] ]=v[h[1]]-h[1]*c;
        for(j=h[1]+1; j<=mh; j++)
        {
            lw[j]=v[j]-j*c;
            if(lw[j-1]<=v[j]-j*c)
            {
                lh=j-1;
                break;
            }
        }
        rw[mh]=v[mh]+mh*c;
        for(j=mh-1; j>=h[1]; j--)
            rw[j]=min(v[j]+j*c,rw[j+1]);

        for(i=2; i<=n; i++)
        {
            for(j=h[i]; j<=mh; j++)
            {
                v[j]=inf;
                if(j>=h[i-1])
                {
                    if(lh!=-1&&j>lh)
                        v[j]=j*c+lw[lh];
                    else
                     v[j]=j*c+lw[j];
                }
                v[j]=min(v[j],(j>=h[i-1]?-j*c+rw[j]:-j*c+rw[h[i-1]]));
                v[j]+=(j-h[i])*(j-h[i]);
            }
            lw[ h[i] ]=v[h[i]]-h[i]*c;
            lh=-1;
            for(j=h[i]+1; j<=mh; j++)
            {
                lw[j]=v[j]-j*c;
                if(lw[j-1]<=v[j]-j*c)
                {
                    lh=j-1;
                    break;
                }
            }
            rw[mh]=v[mh]+mh*c;
            for(j=mh-1; j>=h[i]; j--)
                rw[j]=min(v[j]+j*c,rw[j+1]);

        }
        int ans=inf;
        for(i=h[n]; i<=mh; i++)
        {
            if(v[i]<ans) ans=v[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
