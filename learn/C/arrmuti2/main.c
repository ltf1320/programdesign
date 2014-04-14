#include <stdio.h>


int main()
{
    int arr0[100][100],arr1[100][100],arr2[100][100];
    int height[3],weight[3];
    int i,j,k;
    printf("please input the size of A arr:height weight\n");
    scanf("%d",height);
    scanf("%d",weight);
    printf("please input A arr:\n");
    for(i=0;i!=*height;++i)
        for(j=0;j!=*weight;++j)
            scanf("%d",&arr0[i][j]);
    printf("please input the size of B arr:height/weight\n");
    scanf("%d",&height[1]);
    scanf("%d",&weight[1]);
    if(weight[0]!=height[1])
    {
        printf("erro:these two array can not multiplicate\n");
        return -1;
    }
    printf("please input B arr:\n");
    for(i=0;i!=height[1];++i)
        for(j=0;j!=weight[1];++j)
            scanf("%d",&arr1[i][j]);
    height[2]=height[0];
    weight[2]=weight[1];
    for(i=0;i!=height[2];++i)
        for(j=0;j!=weight[2];++j)
        {
            arr2[i][j]=0;
            for(k=0;k!=weight[0];++k)
                arr2[i][j]+=arr0[i][k]*arr1[k][j];
        }
    for(i=0;i!=height[2];++i)
    {
        printf("\n");
        for(j=0;j!=weight[2];++j)
            printf("%d\t",arr2[i][j]);
    }
    return 0;
}
