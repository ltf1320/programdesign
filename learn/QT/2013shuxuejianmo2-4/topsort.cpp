#include "topsort.h"
#include <cstdio>
#include <Qdir>
#include <QtCore>
#include "unionfind.h"
#include "picnode.h"
void topSort::resetJdisErr()
{
    jdis=254;
    err=3;
    //254,3   250,3  250,5

    ldis=10;
}

topSort::topSort(QString afileName,int picNum)
{
    resetJdisErr();
    char file[100];
    PicNum=picNum;
    fileName=afileName;
    for(int i=0;i<=PicNum;i++)
    {
        sprintf(file,"/%03d.bmp",i);
        pics[i].load(fileName+QString(file));
    }
    getMap();
    findLines();
    for(int i=0;i<linev.size();i++)
    {
        for(int j=0;j<Wid;j++)
        {
            if(linev[i][j]==-1)
                break;
            //ks++;
        }
    }
//    qDebug()<<"ks"<<ks;
    //    dosort();
}

bool topSort::judgeHqy(const QImage &a,int x,int i)
{
    bool flag=1;
    for(int j=max(0,i-15);j<min(a.height()-1,i+15);j++)
        if(a.pixelIndex(x,j)<255)
        {
            flag=0;
            break;
        }
    return flag;
}

int topSort::Hcompare(const QImage &a, const QImage &b)
{
    int ca,cb;
    int sum=0;
    for(int i=0;i<a.height();i++)
    {
        ca=a.pixelIndex(a.width()-1,i);
        cb=b.pixelIndex(0,i);
        if(abs(ca-cb)>jdis)
            sum++;
        /*
        if(ca<50&&judgeHqy(b,0,i))
            return err;
        if(cb<50&&judgeHqy(a,a.width()-1,i))
            return err;
        */
        if(sum>=err)
            return sum;
    }
    //    qDebug()<<sum;
    return sum;
}

int topSort::Wcompare(const QImage &a, const QImage &b)
{
    QSize sz=a.size();
    int ca,cb;
    int sum=0;
    for(int i=0;i<sz.width();i++)
    {
        ca=a.pixelIndex(i,sz.height()-1);
        cb=b.pixelIndex(i,0);
        if(abs(ca-cb)>jdis)
            sum++;
    }
    //    qDebug()<<sum;
    return sum;
}

void topSort::getMap()
{
    int ent=0;
    memset(map,0,sizeof(map));
    for(int i=0;i<=PicNum;i++)
    {
        judges[i][0]=judgeWStart(pics[i]);
        judges[i][1]=judgeWEnd(pics[i]);
        judges[i][2]=judgeHStart(pics[i]);
        judges[i][3]=judgeHEnd(pics[i]);
    }
    preJudgeLine();
//    Hcompare(pics[204],pics[21]);
//    judgeLine(78,67);
    for(int i=0;i<=PicNum;i++)
    {
        for(int j=0;j<=PicNum;j++)
        {
            if(i==18&&j==23)
            {
                i++;
                i--;
            }
            if(i==j)continue;
            if(!judges[j][2]&&judgeLine(i,j)&&Hcompare(pics[i],pics[j])<err)
//            if(!judges[j][2]&&Hcompare(pics[i],pics[j])<err)
            {
                map[0][i][j]=1;
                //                  qDebug()<<"H "<<i<<" "<<j;
                ent++;
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
//    qDebug()<<arrv.size();
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

void topSort::findLines()
{
    linev.clear();
    memset(pvis,0,sizeof(pvis));
    memset(indu,0,sizeof(indu));
    for(int i=0;i<=PicNum;i++)
        for(int j=0;j<=PicNum;j++)
        {
            if(map[0][i][j])
            {
                indu[j]++;
            }
        }
    for(int i=0;i<=PicNum;i++)
    {
        if(!pvis[i]&&!indu[i])
        {
            pvis[i]=1;
            nline.reset();
            nline[0]=i;
            findLine(i,1);
        }
    }
    for(int i=0;i<=PicNum;i++)
    {
        if(!pvis[i])
        {
            pvis[i]=1;
            nline.reset();
            nline[0]=i;
            findLine(i,1);
        }
    }
    int pv=linev.size();
    pv++;
//    qDebug()<<"size "<<linev.size();
}

void topSort::findLine(int picno,int x)
{
    pvis[picno]=1;
    if(x<Wid)
        for(int i=0;i<=PicNum;i++)
            if(!pvis[i]&&map[0][picno][i])
            {
                nline[x]=i;
                findLine(i,x+1);
                return;
            }
    linev.push_back(nline);
}


QList<picNode> topSort::findSameLine(int now)
{
    QList<picNode> lst;
    int kk;
    for(int i=0;i<linev.size();i++)
    {
        kk=linev[i][0];
        if(judgeLine(now,kk))
            lst.push_back(picNode(kk,0));
    }
    return lst;

}

QList<picNode> topSort::findMatch(int now, int dis)
{
    QList<picNode> lst;
    int kk;
    jdis=dis;
    for(int i=0;i<linev.size();i++)
    {
        kk=linev[i][0];
        lst.push_back(picNode(kk,Hcompare(pics[now],pics[kk])));
    }
    std::sort(lst.begin(),lst.end());
    return lst;
    resetJdisErr();
}


void topSort::preJudgeLine()
{
    for(int i=0;i<=PicNum;i++)
    {
        for(int j=0;j<pics[i].height();j++)
        {
            int cnt=0;
            for(int k=0;k<pics[i].width();k++)
            {
                cnt=cnt+pics[i].pixelIndex(k,j);
            }
            z[i][j]=cnt;
        }

    }
    for(int i=0;i<=PicNum;i++)
    {
        int flag=0;
        int tt1=0;
        int mm=0;
        for(int j=0;j<pics[i].height();j++)
        {
             if(flag==0)
            {

                if(z[i][j]>=18360)
                {
                    flag=1;
                    pp[i][tt1]=j;
                }
            }
            else
            {
                if(z[i][j]<18360)
                {
                    flag=0;
                    pp2[i][tt1]=j;
                    tt1++;
                }
            }
           /* if(z[i][j]>=18360)
            {
                mm++;
                if(flag==0)
                {
                    if(z[i][0]>=18360)
                    {
                        pp[i][tt1]=j-1;
                        flag=1;
                    }
                    //else
                    //{
                    flag=1;
                    pp[i][tt1]=j;
                    //}
                }
            }
            else
            {
                if(mm>4)
                {
                    if(i==151&&((j-pp[i][tt1])<=7))
                    {
                        flag=0;
                    }
                    else
                    {
                        flag=0;
                        pp2[i][tt1]=j;
                        tt1++;
                    }

                }
                else
                {
                    if(mm>0&&flag==1)
                    {
                        flag=0;
                    }
                    //   tt1--;
                }
                mm=0;
            }*/
        }
        if(z[i][pics[i].height()-1]>=18360) pp2[i][tt1++]=pics[i].height()+1;
        //    if(z[i][pics[i].height()-1]==18360)
        //     {
        //        pp2[i][tt1]=pics[i].height()-1;
        //    }
        tt[i]=tt1;
    }
    // qDebug()<<tt[151];
    /* for(int i=0;i<3;i++)
    {
        qDebug()<<pp[167][i]<<" "<<pp2[167][i];
    }
    for(int i=0;i<4;i++)
    {
        qDebug()<<pp[25][i]<<" "<<pp2[25][i];
    }*/

}


bool topSort::judgeLine(int a, int b)
{
    if(tt[a]==tt[b])
    {
        int tmp=0;
        for(int i=0;i<tt[a];i++)
        {

            if(abs(pp[a][i]-pp[b][i])<=ldis/*&&abs(pp2[a][i]-pp2[b][i])<=4*/)
            {
                tmp++;
            }

        }
        /*int k=0,l=0;
        while(k<tt[a]||l<tt[b])
        {
            if(pp2[a][k]-pp[a][k]>2&&(pp2[b][l]-pp[b][l]))
            {
                if(abs(pp[a][i]-pp[b][i])<=4&&abs(pp2[a][i]-pp2[b][i])<=4)
                {
                    tmp++;
                }
                k++;
                l++;
            }
            else
            {
                if(pp2[a][k]-pp[a][k]<=1)
                {
                    k++;

                }
                if(pp2[b][l]-pp[b][l]<=2)
                {
                    l++;
                }
        }*/
        if(tmp==tt[a])
        {
            return true;
        }
   /* }
    else
    {

        int tmp=0;
        for(int i=0;i<2;i++)
        {

            if(abs(pp[a][i]-pp[b][i])<=ldis&&abs(pp2[a][i]-pp2[b][i])<=4)
            {
                tmp++;
            }

        }
        if(tmp==2)
        {
            if(tt[a]==2&&tt[b]==3)
            {
                if(abs(pp[b][2]-pp2[b][1])==12)
                {
                    return true;
                }
            }
            else if(tt[a]==3&&tt[b]==2)
            {
                if(abs(pp[a][2]-pp2[a][1])==12)
                {
                    return true;
                }
            }
        }*/
    }
    return false;
}


QList<QList<LineArrange> > topSort::listSameLine()
{
    UnionFind unf;
    for(int i=0;i<linev.size();i++)
        for(int j=0;j<linev.size();j++)
        {
            if(i==j) continue;
            if(judgeLine(linev[i][0],linev[j][0]))
                unf.Union(i,j);
        }
    QList<int> fdlst=unf.getUnioned();
    QList<QList<LineArrange> > res;
    for(int i=0;i<fdlst.size();i++)
    {
        QList<LineArrange> now;
        for(int j=0;j<linev.size();j++)
            if(unf.find(j)==fdlst[i])
                now.push_back(linev[j]);
        res.push_back(now);
    }
    return res;
}


void topSort::getFinalMap()
{
    memset(fmap,0,sizeof(fmap));
    for(int i=0;i<linev.size();i++)
    {
        for(int j=0;j<linev.size();j++)
        {
            if(i==j) continue;
            if(judgeWLine(linev[i],linev[j]))
                fmap[i][j]=1;
        }
    }
    for(int i=0;i<linev.size();i++)
        if(judgeWLineStart(linev[i]))
        {
            memset(fvis,0,sizeof(fvis));
            ftopSort(i,0);
        }
    qDebug()<<fmap[10][2];
    qDebug()<<arrv.size();
}



bool topSort::judgeWLine(LineArrange &a,LineArrange &b)
{
    int sum=0;
    for(int i=0;i<Wid;i++)
    {
        sum+=Wcompare(pics[a[i]],pics[b[i]]);
        if(sum>50)
            return false;
    }
    return true;
}

bool topSort::judgeWLineStart(LineArrange &a)
{
    for(int i=0;i<Wid;i++)
        if(!judgeWStart(pics[a[i]]))
            return false;
    return true;
}

bool topSort::judgeWLineEnd(LineArrange &b)
{
    for(int i=0;i<Wid;i++)
        if(!judgeWEnd(pics[b[i]]))
            return false;
    return true;

}

void topSort::ftopSort(int now,int x)
{
    fvis[now]=1;
    nArr.ss[x]=linev[now];
    if(x==Hei-1)
    {
        arrv.push_back(nArr);
        return;
    }
    for(int i=0;i<linev.size();i++)
        if(!fvis[i]&&fmap[now][i])
        {
            ftopSort(i,x+1);
        }
}

/*
bool momo
void topSort::getFinalMap()
{
    if(linev.size()!=Hei) return;
    int flag[Hei];
    int pf[Hei];
    int ne[Hei];
    memset(flag,0,sizeof(flag));
    memset(pf,-1,sizeof(pf));
    memset(ne,-1,sizeof(ne));
    int cnt=0;
   // qDebug()<<linev.size();
    int res;
    for(int i=0;i<linev.size();i++)
    {
        for(int j=0;j<linev.size();j++)
        {
            if(flag[j]==0)
            {
                int a=linev[i][6];
                int b=linev[j][6];
                int yy;
                int bug=0;
                if(pp[b][0]==0)
                {
                    yy=181-pp[a][tt[a]-1]+pp[b][1];
                }
                else
                {
                    yy=181-pp[a][tt[a]-1]+pp[b][0];
                }

                if((181-pp[a][tt[a]-1])<=42)
                {
                    bug=1;
                }
                if(bug==1)
                {
                    if(yy>=66&&yy<=72)
                    {
                        flag[j]=1;
                        pf[j]=i;
                        ne[i]=j;
                        cnt++;
                        qDebug()<<i<<" "<<j;
                        qDebug()<<linev[i][0]<<"　"<<linev[j][0]<<yy;
                    }
                }
                //else
                //{
                if(((yy>=27)&&(yy<=31))||(yy>=128&&yy<=131)||(yy>=66&&yy<=74))
                {
                    flag[j]=1;
                    pf[j]=i;
                    ne[i]=j;
                    cnt++;

                    qDebug()<<"true"<<i<<" "<<j;
                    qDebug()<<linev[i][6]<<"　"<<linev[j][6]<<yy;
                }
                else
                {
                    qDebug()<<i<<" "<<j;
                    qDebug()<<linev[i][6]<<"　"<<linev[j][6]<<yy;
                }
               // }
            }
        }
    }
    for(int i=0;i<11;i++)
    {
        qDebug()<<pf[i]<<" "<<ne[i];
    }
    qDebug()<<cnt;
    int head;
    int tail;
    for(int i;i<Hei;i++)
    {
        if(pf[i]==-1)
        {
            head=i;
        }
        if(ne[i]==-1)
        {
            tail=i;
        }
    }
    int kn=0;
    for(int i=head;i!=tail;i++)
    {
        nArr.ss[kn++]=linev[i];
        i=ne[i];
    }
    kn++;
    kn--;
}
*/
