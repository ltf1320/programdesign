#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p,e,i,d;
    int m1,time=0;
    scanf("%d%d%d%d",&p,&e,&i,&d);
    while(!(p==-1&&e==-1&&i==-1&&d==-1))
    {
        ++time;
        p=p%23;
        e=e%28;
        i=i%33;
        m1=p;
        while(1)
        {
            if((m1%28==e)&&(m1%33==i)&&(m1!=d))
                break;
            m1+=23;   //放在后面防止第一次就被漏过  24,29,34,0
        }
        if(m1<d)    //m1有可能小于d...... 24,29,34,2
            m1+=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",time,m1-d);
        scanf("%d%d%d%d",&p,&e,&i,&d);
    }
    return 0;
}


