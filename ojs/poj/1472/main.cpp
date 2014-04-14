#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int c[20];

void loop(int deep,int k)
{
    int ops=0;
    int t;
    char tmp[10];
    while(~scanf("%s",tmp))
    {
        switch(tmp[0])
        {
        case 'O':
            scanf("%d",&t);
            ops+=t;
            break;
        case 'L':
            scanf("%s",tmp);
            if(tmp[0]>='0'&&tmp[0]<='9')
            {
                sscanf(tmp,"%d",&t);
                loop(deep,k*t);
            }
            else
            {
                loop(deep+1,k);
            }
            break;
        case 'E':
            c[deep]+=ops*k;
            return;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    int k;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0; i<12; i++) c[i]=0;
        loop(0,1);
        printf("Program #%d\nRuntime = ",cas++);
        k=20;
        while(!c[k]) k--;
        if(k>1)
        {
            if(c[k]>1)
                printf("%d*n^%d",c[k],k);
            else printf("n^%d",k);
            k--;
            while(k>1)
            {
                if(c[k]>1)
                    printf("+%d*n^%d",c[k],k);
                else if(c[k]==1)
                    printf("+n^%d",k);
                k--;
            }
            if(c[1]&&c[0])
            {
                if(c[1]>1)
                    printf("+%d*n+%d",c[1],c[0]);
                else printf("+n+%d",c[0]);
            }
            else if(c[1])
            {
                if(c[1]>1)
                    printf("+%d*n",c[1]);
                else printf("+n");
            }
            else if(c[0])
                printf("+%d",c[0]);
        }
        else
        {
            if(c[1]&&c[0])
            {
                if(c[1]>1)
                    printf("%d*n+%d",c[1],c[0]);
                else printf("n+%d",c[0]);
            }
            else if(c[1])
            {
                if(c[1]>1)
                    printf("%d*n",c[1]);
                else printf("n");
            }
            else
                printf("%d",c[0]);
        }
        printf("\n\n");
    }
    return 0;
}
