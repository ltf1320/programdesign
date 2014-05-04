#include"stdio.h"
#include"stdlib.h"
#include"time.h"
#include"math.h"


const int NUM=40;//粒子数
const int DIM=3;//维数
const double c1=1.8;//参数
const double c2=1.8;//参数

double xmin=-1000000.0;//位置下限
double xmax=1000000.0;//位置上限
double gbestx[DIM];//全局最优位置
double gbestf;//全局最优适应度

struct particle  //定义一个粒子
{
    double x[DIM];//当前位置矢量
    double bestx[DIM];//历史最优位置
    double f;//当前适应度
    double bestf;//历史最优适应度
} swarm[NUM]; //定义粒子群

#define randf ((rand()%10000+rand()%10000*10000)/100000000.0) //产生-1随机浮点数

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


double f1(double x[])  //测试函数：超球函数
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

        for(int i=0; i<DIM; i++)//初始化全局最优
            gbestx[i]=randf*(xmax-xmin)+xmin;
        gbestf=100000000000000.0;
        for(int i=0; i<NUM; i++)  //初始化粒子群
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
                for(int j=0; j<DIM; j++)//进化方程
                    p1->x[j]+=c1*randf*(p1->bestx[j]-p1->x[j])
                              +c2*randf*(gbestx[j]-p1->x[j]);
                p1->f=f1(p1->x);
                if(p1->f<p1->bestf)  //改变历史最优
                {
                    for(int j=0; j<DIM; j++)
                        p1->bestx[j]=p1->x[j];
                    p1->bestf=p1->f;
                }
                if(p1->f<gbestf)  //改变全局最优
                {
                    for(int j=0; j<DIM; j++)
                        gbestx[j]=p1->x[j];
                    for(int j=0; j<DIM; j++)//把当前全局最优的粒子随机放到另一位置
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

