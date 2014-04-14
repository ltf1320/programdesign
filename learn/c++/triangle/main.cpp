/*
#include<stdio.h>
int main()
{
    freopen("in.txt","r",stdin);
    int x[3],y[3];
    while(scanf("%d%d%d%d%d%d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2])!=EOF)
    {
        int s=0,i,j,p,a;
        double k1,k2,k3,b1,b2,b3,y1,y2,y3;
        for(i=0; i<3; i++)
            for(j=i+1; j<3; j++)
                if(x[i]>x[j])
                {
                    a=x[i];
                    x[i]=x[j];
                    x[j]=a;
                    p=y[i];
                    y[i]=y[j];
                    y[j]=p;
                }
        //≈≈–Ú£ø
        if(x[0]!=x[1])
        {
            k1=(0.0+y[1]-y[0])/(x[1]-x[0]);
            b1=y[0]-k1*x[0];
        }
        if(x[1]!=x[2])
        {
            k2=(0.0+y[2]-y[1])/(x[2]-x[1]);
            b2=y[1]-k2*x[1];
        }

        if(x[0]!=x[2])
        {
            k3=(0.0+y[2]-y[0])/(x[2]-x[0]);
            b3=y[0]-k3*x[0];
        }
        for(i=x[0]+1; i<=x[1]; i++)
        {
            y1=k1*i+b1;
            y3=k3*i+b3;
            if(y1>y3)
            {
                a=y1;
                y1=y3;
                y3=a;
            }
            if(y1!=(int)y1)
                j=(int)y1;
            else j=(int)y1+1;
            for(; j<y3; j++)
                s++;
        }
        for(i=x[1]+1; i<x[2]; i++)
        {
            y2=k2*i+b2;
            y3=k3*i+b3;
            if(y2>y3)
            {
                a=y2;
                y2=y3;
                y3=a;
            }
            if(y2!=(int)y2)
                j=(int)y2;
            else j=(int)y2+1;
            for(; j<y3; j++)
                s++;
        }
        printf("%d\n",s);
    }
}

*/

#include <stdio.h>


int main()
{
    freopen("in.txt","r",stdin);
    int x[3],y[3];
    int s,i,j,p;
    double k1,k2,k3,b1,b2,b3,y1,y2,y3,a;
    while(scanf("%d%d%d%d%d%d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2])!=EOF)
    {
        s=0;
        if(x[0]==0&&y[0]==0&&x[1]==0&&y[1]==0&&x[2]==0&&y[2]==0) break;
        for(i=0; i<3; i++)
            for(j=i+1; j<3; j++)
                if(x[i]>x[j])
                {
                    a=x[i];
                    x[i]=x[j];
                    x[j]=a;
                    p=y[i];
                    y[i]=y[j];
                    y[j]=p;
                }
        if(x[0]!=x[1])
        {
            k1=(0.0+y[1]-y[0])/(x[1]-x[0]);
            b1=y[0]-k1*x[0];
        }
        if(x[1]!=x[2])
        {
            k2=(0.0+y[2]-y[1])/(x[2]-x[1]);
            b2=y[1]-k2*x[1];
        }
        if(x[0]!=x[2])
        {
            k3=(0.0+y[2]-y[0])/(x[2]-x[0]);
            b3=y[0]-k3*x[0];
        }
        for(i=x[0]+1; i<=x[1]; i++)
        {
            y1=k1*i+b1;
            y3=k3*i+b3;
            if(y1>y3)
            {
                a=y1;
                y1=y3;
                y3=a;
            }
            y3-=1E-13;
            s+=(int)(y3-y1);
        }
        for(i=x[1]+1; i<x[2]; i++)
        {
            y2=k2*i+b2;
            y3=k3*i+b3;
            if(y2>y3)
            {
                a=y2;
                y2=y3;
                y3=a;
            }
            y3-=1E-13;
            s+=(int)(y3-y2);
        }
        printf("%d\n",s);
    }
}
