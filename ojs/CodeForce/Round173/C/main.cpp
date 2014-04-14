#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;
const int maxn=1000000+100;
int main()
{
    int n1=0,n2=0,l1,l2;
    char s1[maxn],s2[maxn];
    scanf("%s",s1);
    scanf("%s",s2);
    l1=strlen(s1);
    l2=strlen(s2);
    if(l1!=l2)
    {
        printf("NO\n");
        return 0;
    }
    for(int i=0;i<l1;i++)
        if(s1[i]=='1') n1++;
    for(int i=0;i<l2;i++)
        if(s2[i]=='1') n2++;
    if((n1==0&&n2==0)||(n1&&n2)) printf("YES\n");
    else printf("NO\n");
    return 0;
}
