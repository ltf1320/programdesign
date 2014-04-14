#include "graph.h"

Graph::~Graph()
{

}

void Graphs::paint(QPainter &painter)
{
    foreach (Graph* gr, son) {
        gr->paint(painter);
    }
}

void Line::paint(QPainter &painter)
{
    painter.drawLine(a,b);
}

qreal Line::calDis(const QPointF &pt)
{
    qreal l1=getDis(a,pt);
    qreal l2=getDis(b,pt);
    qreal l=getDis(a,b);
    if(l1>l2)
    {
        std::swap(l1,l2);
        std::swap(a,b);
    }
    qreal coangle=(p2(l)+p2(l1)-p2(l2))/(2*l1*l);
    if(coangle<=0)
        return getDis(a,pt);
    else
    {
        return l1*sin(acos(coangle));
    }
}

bool Line::isFit(const QPointF &pt)
{
    if(calDis(pt)<derr)
        return true;
    return false;
}

bool Graphs::isFit(const QPointF &pt)
{
    foreach (Graph* gr, son) {
        if(gr->isFit(pt))
            return true;
    }
    return false;
}


void Graphs::move(const QPointF &v)
{
    foreach (Graph* gr, son) {
        gr->move(v);
    }
}

void Line::move(const QPointF &v)
{
    a+=v;
    b+=v;
}

Graphs::iterator::iterator(Graphs *f)
{
    fa=f;
}
Graph* Graphs::iterator::operator *()
{
    return fa->son[index];
}

void Graphs::iterator::operator ++()
{
    index++;
    if(index>=fa->son.size())
        index=-1;
}

void Graphs::iterator::operator ++(int)
{
    operator++();
}


bool Graphs::iterator::operator ==(iterator a)
{
    return fa==a.fa&&index==a.index;
}

bool Graphs::iterator::operator !=(iterator a)
{
    return !(*this==a);
}

Graphs::iterator Graphs::begin()
{
    iterator iter(this);
    if(!empty())
        iter.index=0;
    else iter.index=-1;
    return iter;
}

Graphs::iterator Graphs::end()
{
    iterator iter(this);
    iter.index=-1;
    return iter;
}

bool Graphs::empty()
{
    return son.empty();
}

bool Graphs::contains(Graph* gr)
{
    return son.contains(gr);
}

void Graphs::push_back(Graph *gr)
{
    son.push_back(gr);
}

void Graphs::remove(iterator iter)
{
    if(iter!=end()&&iter.fa==this)
    {
        delete son[iter.index];
        son.remove(iter.index);
    }
}

Graphs::iterator Graphs::find(Graph *gr)
{
    iterator iter(this);
    iter.index=-1;
    for(int i=0;i<son.size();i++)
        if(gr->operator ==(son[i]))
        {
            iter.index=i;
            break;
        }
    return iter;
}

void Graphs::clear()
{
    foreach (Graph* gr, son) {
        delete gr;
    }
    son.clear();
}

void Graphs::remove(Graphs &grs)
{
    for(iterator iter=grs.begin();iter!=grs.end();iter++)
    {
        iterator now=find(*iter);
        qDebug()<<now.index;
        if(now!=end())
        {
            remove(now);
        }
    }
}
int Graphs::size()
{
    return son.size();
}

Graphs::~Graphs()
{
    clear();
}

Line::~Line()
{

}


Graph* Graphs::clone()
{
    Graphs* grs=new Graphs();
    foreach (Graph* gr, son) {
        grs->push_back(gr->clone());
    }
    return (Graph*)grs;
}

Graph* Line::clone()
{
    Line* l=new Line(a,b);
    return (Graph*)l;
}

Rectangle::Rectangle(QPointF aa, QPointF bb)
{
    a.setX(std::min(aa.x(),bb.x()));
    a.setY(std::max(aa.y(),bb.y()));
    b.setX(std::max(aa.x(),bb.x()));
    b.setY(std::min(aa.y(),bb.y()));
}

qreal Rectangle::calDis(const QPointF &pt)
{
    qreal res;
    Line line=Line(QPointF(a.x(),a.y()),QPointF(a.x(),b.y()));
    res=line.calDis(pt);
    line=Line(QPointF(a.x(),a.y()),QPointF(b.x(),a.y()));
    res=std::min(res,line.calDis(pt));
    line=Line(QPointF(b.x(),a.y()),QPointF(b.x(),b.y()));
    res=std::min(res,line.calDis(pt));
    line=Line(QPointF(a.x(),b.y()),QPointF(b.x(),b.y()));
    res=std::min(res,line.calDis(pt));
    return res;
}


bool Rectangle::isFit(const QPointF &pt)
{
    if(calDis(pt)<derr)
        return true;
    else
        return false;
}

void Rectangle::paint(QPainter &painter)
{
    painter.drawRect(QRectF(a,b));

}

void Rectangle::move(const QPointF &v)
{
    a+=v;
    b+=v;
}

Rectangle::~Rectangle()
{

}

Graph* Rectangle::clone()
{
    Rectangle* rec=new Rectangle(a,b);
    return (Graph*)rec;
}

Ellipse::Ellipse(QPointF center, qreal rx, qreal ry)
{
    this->center=center;
    this->rx=rx;
    this->ry=ry;
}

qreal Ellipse::calDis(const QPointF &pt)
{
    QPointF mpt=QPointF(fabs(pt.x()-center.x()),fabs(pt.y()-center.y()));
    if(mpt.x()<eps)
        return abs(mpt.y()-ry);
    double k=mpt.y()/mpt.x();
    double px=sqrt(p2(rx)*p2(ry)/(p2(ry)+p2(rx)*p2(k)));
    double py=k*px;
    return getDis(mpt,QPointF(px,py));
}

bool Ellipse::isFit(const QPointF &pt)
{
    if(calDis(pt)<derr)
        return true;
    return false;
}

void Ellipse::move(const QPointF &v)
{
    center+=v;
}

void Ellipse::paint(QPainter &painter)
{
    painter.drawEllipse(center,rx,ry);
}

Ellipse::~Ellipse()
{

}

Graph* Ellipse::clone()
{
    Ellipse* el=new Ellipse(center,rx,ry);
    return (Graph*)el;
}

bool Graphs::operator ==(Graph *gr)
{
    if(gr->getTypeId()!=getTypeId())
        return false;
    Graphs* gg=(Graphs*)gr;
    if(son.size()!=gg->son.size())
        return false;
    for(int i=0;i<son.size();i++)
    {
        if(!(son[i]->operator ==(gg->son[i])))
            return false;
    }
    return true;
}

bool Line::operator ==(Graph* gr)
{
    if(gr->getTypeId()!=getTypeId())
        return false;
    Line* l=(Line*) gr;
    if(l->a==a&&l->b==b)
        return true;
    else
        return false;
}

bool Rectangle::operator ==(Graph* gr)
{
    if(gr->getTypeId()!=getTypeId())
        return false;
    Rectangle* rec=(Rectangle*)gr;
    if(rec->a==a&&rec->b==b)
        return true;
    else
        return false;
}

bool Ellipse::operator ==(Graph* gr)
{
    if(gr->getTypeId()!=getTypeId())
        return false;
    Ellipse* el=(Ellipse*)gr;
    if(el->center==center&&el->rx==rx&&el->ry==ry)
        return true;
    else return false;
}

int Graphs::getTypeId()
{
    return typeId;
}

int Line::getTypeId()
{
    return typeId;
}
int Rectangle::getTypeId()
{
    return typeId;
}
int Ellipse::getTypeId()
{
    return typeId;
}

void Graphs::save(QDataStream &stream)
{
    /*format:
     *int :the size of son
     *graphs list as deep first travel
     *for each graph:
     *the TypeId of the graph
     *graph
     */
    stream<<son.size();
    for(int i=0;i<son.size();i++)
    {
        stream<<(qint32)son[i]->getTypeId();
        son[i]->save(stream);
    }
}

void Graphs::read(QDataStream &stream)
{
    int size;
    TypeId tid;
    qint32 tt;
    stream>>size;
    Graph* tmp;
    for(int i=0;i<size;i++)
    {
        stream>>tt;
        tid=(TypeId)tt;
        switch(tid)
        {
        case TGraphs:
            tmp=(Graph*)(new Graphs());
            break;
        case TLine:
            tmp=(Graph*)(new Line());
            break;
        case TRectangle:
            tmp=(Graph*)(new Rectangle());
            break;
        case TEllipse:
            tmp=(Graph*)(new Ellipse());
            break;
        }
        tmp->read(stream);
        son.push_back(tmp);
    }
}

void Line::save(QDataStream &stream)
{
    stream<<a<<b;
}

void Line::read(QDataStream &stream)
{
    stream>>a>>b;
}

void Rectangle::save(QDataStream &stream)
{
    stream<<a<<b;
}
void Rectangle::read(QDataStream &stream)
{
    stream>>a>>b;
}

void Ellipse::save(QDataStream &stream)
{
    stream<<center<<rx<<ry;
}

void Ellipse::read(QDataStream &stream)
{
    stream>>center>>rx>>ry;
}
