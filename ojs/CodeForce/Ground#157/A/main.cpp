#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;



int main()
{
 //   freopen("input.txt","r",stdin);
    char str[100];
    int flag;
    for(int i=0; i<8; i++)
    {
        scanf("%s",str);
        if(str[0]=='W') flag=0;
        else flag=1;
        for(int j=1; j<8; j++)
        {
            if(flag&&str[j]=='B')
            {
                printf("NO\n");
                return 0;
            }
            if(!flag&&str[j]=='W')
            {
                printf("NO\n");
                return 0;
            }
            flag=!flag;
        }
    }
    printf("YES\n");
    return 0;
}
