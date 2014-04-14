#ifndef ARRANGE_H
#define ARRANGE_H
#include "b2.h"


class LineArrange
{
public:
    int ss[MaxLineNum+1];
    int& operator[](int index);
    void reset();
};

class Arrange
{
public:
    LineArrange ss[MaxLineNum+1];
    void reset();
};
#endif // ARRANGE_H
