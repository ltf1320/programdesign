#include "arrange.h"
#include <cstring>
int& LineArrange::operator[](int index)
{
    return ss[index];
}


void LineArrange::reset()
{
    memset(ss,-1,sizeof(ss));
}

void Arrange::reset()
{
    for(int i=0;i<MaxLineNum;i++)
        ss[i].reset();
}
