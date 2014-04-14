#include<stdio.h>
#include<string.h>
#define exp 1e-16
struct node
{
    int x,y;
} p[710];
int main()
{
    int n;
    int max,m;
    while(scanf("%d",&n),n)
    {
        int i,j,l;
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&p[i].x,&p[i].y);
        }
        max=0;
        int x1,y1,x2,y2;
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                m=2;
                for(l=j+1; l<n; l++)
                {
                    if((p[l].y-p[j].y)*(p[i].x-p[j].x)==(p[i].y-p[j].y)*(p[l].x-p[j].x))
                    {
                        m++;
                    }
                }
                if(m>max)
                {
                    max=m;
                }
            }
        }
        printf("%d\n",max);
    }
}
