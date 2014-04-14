#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
 
#define randf ((rand()%10000+rand()%10000*10000)/100000000.0) //����-1���������
using namespace std;
typedef long long LL;
const int maxn=100000+100; 
const int NUM=40;//������
const int DIM=30;//ά��
const double c1=1.8;//����
const double c2=1.8;//����
 
double xmin=-10000.0;//λ������
double xmax=10000.0;//λ������
double gbestx[DIM];//ȫ������λ��
double gbestf;//ȫ��������Ӧ��
 
struct particle {//����һ������
    double x[DIM];//��ǰλ��ʸ��
    double bestx[DIM];//��ʷ����λ��
    double f;//��ǰ��Ӧ��
    double bestf;//��ʷ������Ӧ��
}swarm[NUM];//��������Ⱥ
 
int N;
struct Point
{
    double x,y;
    void read()
    {
        scanf("%lf%lf",&x,&y);
        xmin=min(xmin,x);
        xmin=min(xmin,y);
        xmax=max(xmax,x);
        xmax=max(xmax,y);
    }
    bool operator<(const Point &a)const
    {
        return (x+y)<(a.x+a.y);
    }
};
bool cmpx(const Point &a,const Point &b)
{
    return a.x<b.x;
}
bool cmpy(const Point &a,const Point &b)
{
    return a.y<b.y;
}
Point pts[maxn];
double f1(double x[]) {//���Ժ�����������
    double res=0;
    double nx,ny;
    for(int i=0;i<N;i++)
    {
        nx=pts[i].x-x[0];
        ny=pts[i].y-x[1];
        res=max(res,min(fabs(nx-ny),fabs(nx+ny)));
    }
    return res;
}
int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        pts[i].read();
    double res;
    for(int i=0; i<DIM; i++)//��ʼ��ȫ������
        gbestx[i]=randf*(xmax-xmin)+xmin;
    gbestf=100000000000000.0;
    for(int i=0; i<NUM; i++) {//��ʼ������Ⱥ
        particle* p1=&swarm[i];
        for(int j=0; j<DIM; j++)
            p1->x[j]=randf*(xmax-xmin)+xmin;
        p1->f=f1(p1->x);
        p1->bestf=100000000000000.0;
    }
    for(int t=0; t<5000; t++) {
        for(int i=0; i<NUM; i++) {
            particle* p1=&swarm[i];
            for(int j=0; j<DIM; j++)//��������
                p1->x[j]+=c1*randf*(p1->bestx[j]-p1->x[j])
                +c2*randf*(gbestx[j]-p1->x[j]);
            p1->f=f1(p1->x);
            if(p1->f<p1->bestf) {//�ı���ʷ����
                for(int j=0;j<DIM;j++)
                    p1->bestx[j]=p1->x[j];
                p1->bestf=p1->f;
            }
            if(p1->f<gbestf) {//�ı�ȫ������
                for(int j=0;j<DIM;j++)
                    gbestx[j]=p1->x[j];
                for(int j=0; j<DIM; j++)//�ѵ�ǰȫ�����ŵ���������ŵ���һλ��
                    p1->x[j]=randf*(xmax-xmin)+xmin;
                gbestf=p1->f;
            }
        }
    }
    printf("%.1f\n", gbestf);
}
