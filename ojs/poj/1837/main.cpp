/*
һ����̬�滮�����������⣬��������ϵľ��������
����Ӧ�ÿ��Ƿֽ׶ε����⣬��Ϊ�����ϵ�����������ͬ��������ֻ�ܹ�һ�Σ���ѡÿһ�ι�������Ϊһ���׶ο���
����ǳ�ʼ״̬������״̬��ȷ����
    �ʼû���κ����������ƽ��ƽ��ģ�
    ����״̬Ҳ��ƽ��ģ�
    ���м�ÿ�ιҹ����״̬δ֪��
״̬��ʾ������ȷ����
    �����뵽��һ����������ʾ��ƽ��״̬������������Ϊ1��ʾ��ʼʱ��ƽ��
    Ȼ���Դ������ʾ�м�������Դﵽ��״̬�ĸ���
    ���õ����������ֵ��ý��

״̬ת�Ʒ���:f[i][v]+=f[i-1][v+gouma[k]*zhong[i]]
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
    int C,G;
    int gouma[35],zhong[30];
    cin>>C>>G;
    for(int i=0;i<C;++i)
        cin>>gouma[i];
    for(int i=0;i<G;++i)
        cin>>zhong[i];
    int balance[30002],tem[30002];
    memset(balance,0,sizeof(balance));
    balance[15000]=1;
    for(int i=0;i<G;++i)
    {
        memcpy(tem,balance,sizeof(balance));
        memset(balance,0,sizeof(balance));
        for(int j=-5000;j<=5000;++j)
            for(int k=0;k<C;++k)
                balance[j+15000]+=tem[j+15000-zhong[i]*gouma[k]];
    }
    cout<<balance[15000]<<endl;
    return 0;
}

