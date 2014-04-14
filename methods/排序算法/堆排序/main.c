#include <stdio.h>
#include <stdlib.h>
void maxsort(float a[],int count);
void maxbuild(float a[],int count);
void heapify(float a[],int start,int count);

int main()
{
    freopen("in.txt","r",stdin);
    float a[100];
    float *p=a+1;
    int count=0;
    printf("please input the data,end up by 0\n");
    scanf("%f",p);
    while(*p++)
    {
        scanf("%f",p);
        count++;
    }
    maxbuild(a,count);
    maxsort(a,count);
    p=a+1;
    for(;count>0;count--)
        printf("%f\t",*p++);
    return 0;
}

void heapify(float a[],int start,int count)
{
    int m=start;
    int k,max;
    float t;
    while(1)
    {
        k=m*2;
        if(k>count)
            break;
        else if(k+1>count)
        {
            if(a[k]>a[m])
            {
                t=a[k];
                a[k]=a[m];
                a[m]=t;
            }
            break;
        }
        else
        {
            if(a[k]>a[k+1])
                max=k;
            else max=k+1;
            if(a[max]>a[m])
            {
                t=a[max];
                a[max]=a[m];
                a[m]=t;
            }
        }
        m=max;
    }
}

void maxbuild(float a[],int count)
{
    int i;
    for(i=count/2;i>0;i--)
        heapify(a,i,count);
}

void maxsort(float a[],int count)
{
    float t;
    while(count>1)
    {
        t=a[count];
        a[count]=a[1];
        a[1]=t;
        heapify(a,1,--count);
    }
}
