#include"stdio.h"
#include"stdlib.h"
#include"time.h"
#include"math.h"


const int NUM=40;//������
const int DIM=3;//ά��
const double c1=1.8;//����
const double c2=1.8;//����

double xmin=-1000000.0;//λ������
double xmax=1000000.0;//λ������
double gbestx[DIM];//ȫ������λ��
double gbestf;//ȫ��������Ӧ��

struct particle  //����һ������
{
    double x[DIM];//��ǰλ��ʸ��
    double bestx[DIM];//��ʷ����λ��
    double f;//��ǰ��Ӧ��
    double bestf;//��ʷ������Ӧ��
} swarm[NUM]; //��������Ⱥ

#define randf ((rand()%10000+rand()%10000*10000)/100000000.0) //����-1���������

inline double p2(double x)
{
    return x*x;
}

int N;
struct Node
{
    double x,y,z;
};
Node nds[100];


double f1(double x[])  //���Ժ�����������
{
    double dis=0;
    for(int i=0;i<N;i++)
    {
        dis+=p2(x[0]*nds[i].x+x[1]*nds[i].y+x[2]*nds[i].z)/(p2(x[0])+p2(x[1])+p2(x[2]));
    }
    return dis;
}

int main()
{
   // freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%lf%lf%lf",&nds[i].x,&nds[i].y,&nds[i].z);

        for(int i=0; i<DIM; i++)//��ʼ��ȫ������
            gbestx[i]=randf*(xmax-xmin)+xmin;
        gbestf=100000000000000.0;
        for(int i=0; i<NUM; i++)  //��ʼ������Ⱥ
        {
            particle* p1=&swarm[i];
            for(int j=0; j<DIM; j++)
                p1->x[j]=randf*(xmax-xmin)+xmin;
            p1->f=f1(p1->x);
            p1->bestf=100000000000000.0;
        }
        for(int t=0; t<5000; t++)
        {
            for(int i=0; i<NUM; i++)
            {
                particle* p1=&swarm[i];
                for(int j=0; j<DIM; j++)//��������
                    p1->x[j]+=c1*randf*(p1->bestx[j]-p1->x[j])
                              +c2*randf*(gbestx[j]-p1->x[j]);
                p1->f=f1(p1->x);
                if(p1->f<p1->bestf)  //�ı���ʷ����
                {
                    for(int j=0; j<DIM; j++)
                        p1->bestx[j]=p1->x[j];
                    p1->bestf=p1->f;
                }
                if(p1->f<gbestf)  //�ı�ȫ������
                {
                    for(int j=0; j<DIM; j++)
                        gbestx[j]=p1->x[j];
                    for(int j=0; j<DIM; j++)//�ѵ�ǰȫ�����ŵ���������ŵ���һλ��
                        p1->x[j]=randf*(xmax-xmin)+xmin;
                    gbestf=p1->f;
                }
            }
        }
        printf("Case %d:",cas);
        for(int i=0;i<DIM;i++)
            printf(" %.6f",gbestx[i]);
        puts("");
    }
    return 0;
}

