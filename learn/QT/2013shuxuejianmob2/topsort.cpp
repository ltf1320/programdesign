#include "topsort.h"
#include <cstdio>
#include <Qdir>
#include <QtCore>
topSort::topSort(QString afileName,int picNum)
{
    char file[100];
    PicNum=picNum;
    fileName=afileName;
    for(int i=0;i<=PicNum;i++)
    {
        sprintf(file,"/%03d.bmp",i);
        pics[i].load(fileName+QString(file));
    }
    Hei=19;
    Wid=11;
    getMap();
    memset(vis,0,sizeof(vis));
    dosort(0,0);
}



bool topSort::Hcompare(const QImage &a, const QImage &b,int err)
{
    int ca,cb;
    int sum=0;
    for(int i=0;i<a.height();i++)
    {
        ca=a.pixelIndex(a.width()-1,i);
        cb=b.pixelIndex(0,i);
        if(abs(ca-cb)>0)
            sum++;
        if(sum>=err)
            return false;
    }
    //    qDebug()<<sum;
    return true;
}

bool topSort::Wcompare(const QImage &a, const QImage &b,int err)
{
    QSize sz=a.size();
    int ca,cb;
    int sum=0;
    for(int i=0;i<sz.width();i++)
    {
        ca=a.pixelIndex(i,sz.height()-1);
        cb=b.pixelIndex(i,0);
        if(abs(ca-cb)>127)
            sum++;
        if(sum>=err) return false;
    }
    //    qDebug()<<sum;
    return true;
}

void topSort::getMap()
{
    int ent=0;
    memset(map,0,sizeof(map));



    for(int i=0;i<=PicNum;i++)
    {
        bool flag1=1,flag2=1;
        for(int e=0;e<100;e++)
        {

            for(int j=0;j<=PicNum;j++)
            {
                if(i==j)continue;
                if(flag1&&Hcompare(pics[i],pics[j],e))
                {
                    map[0][i][j]=1;
                    qDebug()<<i<<" "<<j<<" "<<e;
                    ent++;
                    flag1=0;
                }
                if(flag2&&Wcompare(pics[i],pics[j],e))
                {
                    map[1][i][j]=1;
                    flag2=0;
                    //                ent++;
                }
            }
            if(!flag1&&!flag2) break;
        }
    }
    qDebug()<<ent;
}

bool topSort::judgeHStart(const QImage &a)
{
    QSize sz=a.size();
    int ca;
    for(int i=0;i<sz.height();i++)
    {
        ca=a.pixelIndex(0,i);
        if(ca!=255) return false;
    }
    return true;
}

bool topSort::judgeHEnd(const QImage &a)
{
    QSize sz=a.size();
    int ca;
    for(int i=0;i<sz.height();i++)
    {
        ca=a.pixelIndex(sz.width()-1,i);
        if(ca!=255)
            return false;
    }
    return true;
}


bool topSort::judgeWStart(const QImage &a)
{
    QSize sz=a.size();
    int ca;
    for(int i=0;i<sz.width();i++)
    {
        ca=a.pixelIndex(i,0);
        if(ca!=255) return false;
    }
    return true;
}

bool topSort::judgeWEnd(const QImage &a)
{
    QSize sz=a.size();
    int ca;
    for(int i=0;i<sz.width();i++)
    {
        ca=a.pixelIndex(i,sz.height()-1);
        if(ca!=255) return false;
    }
    return true;
}


void topSort::dosort(int i,int j)
{
    if(j>=Wid)
    {
        i++;j=0;
    }
    if(i>=Hei)
    {
        arrv.push_back(nArr);
        return;
    }
    for(int k=0;k<=PicNum;k++)
    {
        if(vis[k])continue;
        if(i==0)
        {
            if(!judgeWStart(pics[k]))continue;
        }
        else
        {
            if(!map[1][nArr.ss[i-1][j]][k])continue;
        }
        if(j==0)
        {
            if(!judgeHStart(pics[k]))continue;
        }
        else
        {
            if(!map[0][nArr.ss[i][j-1]][k])continue;
        }
        if(i==Hei-1)
            if(!judgeWEnd(pics[k]))continue;
        if(j==Wid-1)
            if(!judgeHEnd(pics[k]))continue;
        nArr.ss[i][j]=k;
        vis[k]=1;
        dosort(i,j+1);
        vis[k]=0;

    }

}
