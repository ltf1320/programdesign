#include<iostream>
#include   <vector>
using namespace std;

int main()
{

    int newBF;

    int oldBF;

    int t;

    int search;

    int max;

    cout<<"��������������Ů������"<<endl;
    cin>>max;

    int   *nextm=new   int[max+1];  //�����¸�׷��Ůʿ�ĺ���

    int   *nextw=new   int[max+1];//Ůʿ���ܵ�������

    vector<vector<int>   >   man(max,   vector<int>(max));//������Ůʿ��ϲ���̶�˳��

    vector<vector<int>   >   woman(max,   vector<int>(max+1));//Ů����������ϲ���̶�˳��

    for(int i=0; i<max+1; i++)///

        nextm[i]=0;

    for(int i=0; i<max; i++)

        nextw[i]=max;//�������ʼ

    for(int i=0; i<max; i++)

    {

        cout<<"��"<<i<<"λ��ʿϲ��Ů��˳��Ϊ��"<<endl;

        for(int j=0; j<max; j++)

            cin>>man[i][j];

    }

    for(int i=0; i<max; i++)

    {

        cout<<"��"<<i<<"λŮʿϲ������˳��Ϊ��"<<endl;

        for(int j=0; j<max; j++)

            cin>>woman[i][j];

        woman[i][max]=max;
    }
    bool changeBF(vector<vector<int>   > woman,int,int,int,int);
    for(int j=0; j<max; j++)
    {
        t=man[j][nextm[j]];//Ҫ׷���Ů����
        if(nextw[t]==j)
        {
            //ʲôҲ����
        }
        else
        {
            newBF=j;
            oldBF=nextw[t];
            if(changeBF(woman,t,newBF,oldBF,max))
            {
                nextm[oldBF]++;
                nextw[t]=newBF;
                if(oldBF>j)
                {
//ʲôҲ����
                }
                else
                {
                    j=oldBF;//ǰ�����ѱ��������Һ���С��Ӧ������������Ů��
                    j--;
                }
            }
            else
            {
                nextm[j]++;//���󲻳ɹ�������׷����һλϲ����Ů��
                j--;
            }
        }
    }
    for(int  j=0; j<max; j++)
    {
        cout<<"��"<<j<<"λ��ʿ"<<"��Ů����"<<man[j][nextm[j]]<<endl;
    }
}
bool changeBF(vector<vector<int>   > woman,int i,int newBF,int oldBF,int max)
{
    int temp1;
    int temp2;
    for(int j=0; j<=max; j++)
    {
        if(woman[i][j]==newBF)
        {
            temp1=j;
            break;
        }
    }

    for(int j=0; j<=max; j++)

    {

        if(woman[i][j]==oldBF)

        {

            temp2=j;
            break;

        }
    }

    return(temp1<temp2);//�Ƚ�ǰ�������ε������Ⱥ�
}
