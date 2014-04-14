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
    getMap();
    memset(vis,0,sizeof(vis));
    dosort(0);
}



bool topSort::compare(const QImage &a, const QImage &b,int err)
{
    QSize sz=a.size();
    int ca,cb;
    int sum=0;
    for(int i=0;i<sz.height();i++)
    {
        ca=a.pixelIndex(sz.width()-1,i);
        cb=b.pixelIndex(0,i);
        if(abs(ca-cb)>127)
            sum++;
    }
//    qDebug()<<sum;
    return sum<err;
}

void topSort::getMap()
{
    int ent=0;
    memset(map,0,sizeof(map));
    for(int i=0;i<=PicNum;i++)
        for(int j=0;j<=PicNum;j++)
        {
            if(i==j)continue;
            if(judgeStart(pics[j]))
                continue;
            if(judgeEnd(pics[i]))
                continue;
            if(compare(pics[i],pics[j],150))
            {
                map[i][j]=1;
                qDebug()<<i<<" "<<j;
                ent++;
            }
        }
    qDebug()<<ent;
}

bool topSort::judgeStart(const QImage &a)
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

bool topSort::judgeEnd(const QImage &a)
{
    QSize sz=a.size();
    int ca;
    for(int i=0;i<sz.height();i++)
    {
        ca=a.pixelIndex(sz.width()-1,i);
        if(ca!=255) return false;
    }
    return true;
}

void topSort::dosort(int n)
{
    if(n>PicNum)
    {
        arrv.push_back(nArr);
        return;
    }
    for(int i=0;i<=PicNum;i++)
    {
        if(vis[i])continue;
        int indu=0;
        for(int j=0;j<=PicNum;j++)
            if(!vis[j]&&map[j][i])
                indu++;
        if(indu==0)
        {
            vis[i]=1;
            nArr.ss[n]=i;
            dosort(n+1);
            vis[i]=0;
        }
    }
}
