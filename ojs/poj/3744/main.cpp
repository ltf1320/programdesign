//���ж���dp����һ�ο�������1000000�����飬MLE��
//�ڶ��ο���һ����TLE�ˣ�������1000000��ʱ��
//ֻ����һ��10��һ��3�����飬����T�ˣ�ͬ��
//ʹ�þ�������ˣ�����T(û�и�num����
//�����ˣ�����T
//�뵽�����е��ƹ�ʽ������AC��...���˰��첻��dp����ѧ��..


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int num[11];


int main()
{
    freopen("in.txt","r",stdin);
    int n;
    double p;
    double res;
    while(~scanf("%d%lf",&n,&p))
    {
        res=1;
        num[0]=0;
        for(int i=1;i<=n;++i)
            scanf("%d",&num[i]);
        sort(num,num+n+1);
        for(int i=1;i<=n;++i)
            res=(1-p)*res*(1-pow(p-1,num[i]-num[i-1]-1))/(2-p);
        printf("%.7f\n",res);
    }
    return 0;
}
