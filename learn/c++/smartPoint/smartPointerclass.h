#ifndef SMARTPOINTERCLASS_H_INCLUDED
#define SMARTPOINTERCLASS_H_INCLUDED
class Hasptr;
//a smart pointer for int
class Counter
{
    private:
        friend class Hasptr;
        friend std::ostream& operator<<(std::ostream& out,const Hasptr &hasptr);
        size_t count;
        Counter(int *p):ptr(p),count(1){};
        int *ptr;
        ~Counter() {delete ptr;};
};



//a exam class use smart pointer
class Hasptr
{
    public:
        friend std::ostream& operator<<(std::ostream& out,const Hasptr &hasptr);
        Hasptr(int val_,int *p):val(val_),ptr(new Counter(p)) {};
        int getInt() const {return val;};
        int getPtrVal() const {return *ptr->ptr;};
        int* getPointer() const {return ptr->ptr;};
        void setInt(int val_) {val=val_;};
        void setPtrVal(int val_) {*ptr->ptr=val_;};
        Hasptr(const Hasptr &orig):ptr(orig.ptr),val(orig.val)
        {
            ptr->count++;
        }
        Hasptr& operator=(const Hasptr &orig)
        {
            val=orig.val;
            ptr->count--;
            ptr=orig.ptr;
            ptr->count++;
            return *this;
        }
        ~Hasptr(){if(ptr->count==0) delete ptr;
                    else ptr->count--;}
    private:
        Counter *ptr;
        int val;
};

std::ostream& operator<<(std::ostream& out,const Hasptr &hasptr)
{
    out<<"The int is "<<hasptr.val<<"\t"<<"The value of ptr is "<<*hasptr.ptr->ptr;
    return out;
}
#endif // SMARTPOINTERCLASS_H_INCLUDED
