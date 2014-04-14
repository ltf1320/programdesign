#ifndef EXAMCLASS_H_INCLUDED
#define EXAMCLASS_H_INCLUDED
//a class with a int data and a pointer pointed to int
class examclass
{
    public:
        examclass(int *ptr_,int val_):ptr(ptr_),val(val_) {};
        int getInt() const {return val};
        int* getPtr() const {return ptr};
        int getPtrVal() const {return *ptr};
        void changeInt(int v) {val=v};
        void changePtrVal(int v) {*ptr=v};
    private:
        int val;
        int *ptr;
}

#endif // EXAMCLASS_H_INCLUDED
