#include<stdio.h>
  int len1,len2,f[1005][1005],min;
  char s1[1005],s2[1005];
int main()
{
    freopen("in.txt","r",stdin);
  while(scanf("%d",&len1)!=EOF)
  {
    scanf("%s",s1+1);
    scanf("%d %s",&len2,s2+1);
    for(int i=1;i<=len1;i++)
    {
      f[i][0]=i;
    }
    for(int i=1;i<=len2;i++)
    {
      f[0][i]=i;
    }
    f[0][0]=0;
    for(int i=1;i<=len1;i++)
    {
      for(int j=1;j<=len2;j++)
      {
         min=99999;
         if(s1[i]==s2[j])
         {
           if(f[i-1][j-1]<min)
             min=f[i-1][j-1];
         }
         else
         {
           if(f[i-1][j-1]+1<min)
             min=f[i-1][j-1]+1;
           if(f[i-1][j]+1<min)
             min=f[i-1][j]+1;
           if(f[i][j-1]+1<min)
             min=f[i][j-1]+1;
         }
         f[i][j]=min;
      }
    }
    printf("%d\n",f[len1][len2]);
  }

  return 0;
}
