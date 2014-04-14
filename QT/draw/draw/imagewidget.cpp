#include "imagewidget.h"

ImageWidget::ImageWidget(QWidget *parent) :
    QWidget(parent)
{
    nowGraph=0;
    bemoving=0;
    ctrlpressed=0;
    nowst=St_ChoseAndMove;
    //   graph.push_back(Factory::createLine(QPointF(10,10),QPointF(100,100)));
    resize(800,600);
}


void ImageWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    graph.paint(painter);
    if(!chosedGraphs.empty())
    {
        painter.setPen(Qt::red);
        chosedGraphs.paint(painter);
    }
    if(nowGraph)
    {
        painter.setPen(Qt::blue);
        nowGraph->paint(painter);
    }
    event->accept();
}

void ImageWidget::mousePressEvent(QMouseEvent *event)
{
    mouseStartPoint=QPointF(event->x(),event->y());
    //   qDebug()<< mouseStartPoint.x()<<" "<< mouseStartPoint.y();
    switch(nowst)
    {
    case St_ChoseAndMove:
        bemoving=true;
        iscopying=false;
        if(nowGraph)
        {
            delete nowGraph;
            nowGraph=0;
        }
        if(!ctrlpressed)
        {
            if(!chosedGraphs.isFit(mouseStartPoint))
                chosedGraphs.clear();
            if(chosedGraphs.empty())
            {
                //迭代器模式访问graphs的所有元素
                for(Graphs::iterator iter=graph.begin();iter!=graph.end();iter++)
                {
                    if((*iter)->isFit(mouseStartPoint))
                    {
                        chosedGraphs.push_back((*iter)->clone());
                        break;
                    }
                }
            }
            if(chosedGraphs.empty())
                bemoving=false;
            else
                nowGraph=Factory::createGraphs(chosedGraphs);
        }
        else
        {
            if(!chosedGraphs.isFit(mouseStartPoint))
            {
                bemoving=false;
                for(Graphs::iterator iter=graph.begin();iter!=graph.end();iter++)
                {
                    if((*iter)->isFit(mouseStartPoint))
                    {
                        chosedGraphs.push_back((*iter)->clone());
                        break;
                    }
                }
            }
            else
            {
                qDebug()<<"copying";
                iscopying=true;
                nowGraph=Factory::createGraphs(chosedGraphs);
            }
        }
        break;
    case St_DrawLine:
    case St_DrawRec:
    case St_DrawEllipse:
        break;

    }
    update();
}


void ImageWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QPointF npt=QPointF(event->x(),event->y());
    if(nowGraph)
    {
        delete nowGraph;
        nowGraph=0;
    }
    switch(nowst)
    {
    case St_ChoseAndMove:
        if(bemoving)
        {
            if(!iscopying)
                graph.remove(chosedGraphs);
            Graphs* newGraphs=Factory::createGraphs(chosedGraphs);
            chosedGraphs.clear();
            newGraphs->move(npt-mouseStartPoint);
            for(Graphs::iterator iter=newGraphs->begin();iter!=newGraphs->end();iter++)
            {
                graph.push_back(*iter);
                chosedGraphs.push_back((*iter)->clone());
            }
            bemoving=false;
        }
        break;
    case St_DrawLine:
        graph.push_back(Factory::createLine(mouseStartPoint,npt));
        break;
    case St_DrawRec:
        graph.push_back(Factory::createRectangle(mouseStartPoint,npt));
        break;
    case St_DrawEllipse:
        graph.push_back(Factory::createEllipse(mouseStartPoint,npt.x()-mouseStartPoint.x(),npt.y()-mouseStartPoint.y()));
        break;
    }
    update();
}

void ImageWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPointF npt=QPointF(event->x(),event->y());
    switch(nowst)
    {
    case St_ChoseAndMove:
        if(bemoving)
        {
            delete nowGraph;
            nowGraph=Factory::createGraphs(chosedGraphs);
            nowGraph->move(npt-mouseStartPoint);
        }
        break;
    case St_DrawLine:
        if(nowGraph)
            delete nowGraph;
        nowGraph=Factory::createGraphs();
        nowGraph->push_back(Factory::createLine(mouseStartPoint,npt));
        break;
    case St_DrawRec:
        if(nowGraph)
            delete nowGraph;
        nowGraph=Factory::createGraphs();
        nowGraph->push_back(Factory::createRectangle(mouseStartPoint,npt));
        break;
    case St_DrawEllipse:
        if(nowGraph)
            delete nowGraph;
        nowGraph=Factory::createGraphs();
        nowGraph->push_back(Factory::createEllipse(mouseStartPoint,npt.x()-mouseStartPoint.x(),npt.y()-mouseStartPoint.y()));
        break;
    }
    update();
}

void ImageWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Control:
        ctrlpressed=true;
        break;
    case Qt::Key_Delete:
        if(!bemoving&&!ctrlpressed)
        {
            graph.remove(chosedGraphs);
            chosedGraphs.clear();
            update();
        }
        break;
    }
}

void ImageWidget::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Control:
        ctrlpressed=false;
        break;
    case Qt::Key_Delete:
        break;
    }
}

void ImageWidget::changeState(State st)
{
    chosedGraphs.clear();
    nowst=st;
    update();
}

void ImageWidget::combine()
{
    if(chosedGraphs.size()<2) return;
    graph.remove(chosedGraphs);
    Graph* tmp=(Graph*)Factory::createGraphs(chosedGraphs);
    graph.push_back(tmp);
    chosedGraphs.clear();
    chosedGraphs.push_back(tmp->clone());
}

void ImageWidget::split()
{
    if(chosedGraphs.size()>1)
        QMessageBox::warning(this,"注意","拆分时只能选择一个连接块",QMessageBox::Yes);
    else
    {
        if(chosedGraphs.empty()) return;
        Graph* gr=*(chosedGraphs.begin());
        if(gr->getTypeId()==Graph::TGraphs)
        {
            Graphs *grs=Factory::createGraphs((Graphs*)gr);
            graph.remove(chosedGraphs);
            chosedGraphs.clear();
            for(Graphs::iterator iter=grs->begin();iter!=grs->end();iter++)
            {
                graph.push_back((*iter)->clone());
                chosedGraphs.push_back((*iter)->clone());
            }
            delete grs;
        }
    }
}


void ImageWidget::save()
{
    QString fileName;
    QString caption("保存");
    QString dir(QDir::currentPath());
    QString filter("*.sbmomo");
    fileName=QFileDialog::getSaveFileName(this,caption,dir,filter);
    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QDataStream stream(&file);
        graph.save(stream);
    }
}

void ImageWidget::read()
{
    QString fileName;
    QString caption("打开");
    QString dir(QDir::currentPath());
    QString filter("*.sbmomo");
    fileName=QFileDialog::getOpenFileName(this,caption,dir,filter);
    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QDataStream stream(&file);
        graph.clear();
        chosedGraphs.clear();
        graph.read(stream);
    }
}
