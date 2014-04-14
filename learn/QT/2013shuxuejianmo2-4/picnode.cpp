#include "picnode.h"

picNode::picNode()
{

}

picNode::picNode(int no, int d):picno(no),dif(d)
{

}

bool picNode::operator<(const picNode &a)const
{
    return dif<a.dif;
}
