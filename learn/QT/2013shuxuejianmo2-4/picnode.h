#ifndef PICNODE_H
#define PICNODE_H

class picNode
{
public:
    picNode();
    picNode(int no,int d);
    int picno,dif;
    bool operator<(const picNode &a)const ;

};

#endif // PICNODE_H
