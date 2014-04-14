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
    dosort();

}



bool topSort::Hcompare(const QImage &a, const QImage &b,int err)
{
    int ca,cb;
    int sum=0;
    for(int i=0;i<a.height();i++)
    {
        ca=a.pixelIndex(a.width()-1,i);
        cb=b.pixelIndex(0,i);
        if(abs(ca-cb)>127)
            sum++;
        if(sum>=err)
            return false;
    }
    //    qDebug()<<sum;
    return sum<err;
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
        if(sum>=err)
            return false;
    }
    //    qDebug()<<sum;
    return sum<err;
}

void topSort::getMap()
{
    int ent=0;
    memset(map,0,sizeof(map));
    Wcompare(pics[0],pics[33],40);
    for(int i=0;i<=PicNum;i++)
    {
        judges[i][0]=judgeWStart(pics[i]);
        judges[i][1]=judgeWEnd(pics[i]);
        judges[i][2]=judgeHStart(pics[i]);
        judges[i][3]=judgeHEnd(pics[i]);
    }

    for(int i=0;i<=PicNum;i++)
    {
        bool flag1=!judges[i][3],flag2=!judges[i][1];
        for(int e=0;e<20;e++)
        {
            if(!flag1&&!flag2) break;
            for(int j=0;j<=PicNum;j++)
            {
                if(i==j)continue;
                if(flag1&&!judges[j][2]&&Hcompare(pics[i],pics[j],e))
                {
                    map[0][i][j]=1;
                    qDebug()<<"H "<<i<<" "<<j<<" "<<e;
                    ent++;
                    flag1=0;
                }
                if(e<10&&flag2&&!judges[j][0]&&Wcompare(pics[i],pics[j],e))
                {
                    map[1][i][j]=1;
                    flag2=0;
                    qDebug()<<"W "<<i<<" "<<j<<" "<<e;
                }
            }
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


void topSort::dosort()
{
    arrv.clear();
    getPieces();
}


void topSort::getPieces()
{
    memset(pvis,0,sizeof(pvis));
    for(int i=0;i<=PicNum;i++)
        if(!pvis[i])
        {
            memset(nArr.ss,-1,sizeof(nArr.ss));
            dfs(i,0,0);
            arrv.push_back(nArr);
        }
    qDebug()<<arrv.size();
}


void topSort::dfs(int picno,int x, int y)
{
    pvis[picno]=1;
    nArr.ss[x][y]=picno;
    for(int i=0;i<=PicNum;i++)
        if(!pvis[i]&&map[0][picno][i])
        {
            if(x>0&&nArr.ss[x-1][y]!=-1&&!map[1][nArr.ss[x-1][y]][i]) continue;
            dfs(i,x,y+1);
            break;
        }
    for(int i=0;i<=PicNum;i++)
        if(!pvis[i]&&map[1][picno][i])
        {
            if(y>0&&nArr.ss[x][y-1]!=-1&&!map[0][nArr.ss[x][y-1]][i]) continue;
            dfs(i,x+1,y);
            break;
        }
}
