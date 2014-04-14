#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED

class Book
{
    public:
        friend std::ostream& operator<<(std::ostream& out,const Book& book);
        Book(const std::string isbn_,const std::string name_,const std::string au,float price_,int year_=0,size_t number_=0,size_t borrowed_=0):isbn(isbn_),name(name_),author(au),price(price_),number(number_),borrowed(borrowed_),year(year_){};
        virtual void borrow(size_t num)
        {
            if(num>number)
                throw std::runtime_error("out of range");
            number-=num;
            borrowed+=num;
        }
        virtual void back(size_t num)
        {
            if(num>borrowed)
                throw std::runtime_error("out of range");
            number+=num;
            borrowed-=num;
        }
        virtual void buy(size_t num)
        {
            number+=num;
        }
        virtual void destroy(size_t num)
        {
            if(num>number)
                throw std::runtime_error("out of range");
            number-=num;
            std::cout<<"the value is "<<num*price<<std::endl;
        }
        virtual std::string get_author(){return author;}
        virtual std::string get_name(){return name;}
        virtual std::string get_isbn(){return isbn;}
        virtual size_t get_number(){return number;}
        virtual float get_price(){return price;}
        virtual size_t get_borrowed(){return borrowed;}
        virtual int get_year(){return year;}
        virtual ~Book() {};
    private:
        std::string author;
        std::string name;
        size_t number;
        float price;
        size_t borrowed;
        std::string isbn;
        int year;
};

std::ostream& operator<<(std::ostream& out,const Book& book)
{
    std::cout<<book.isbn<<" "<<book.name<<" "<<book.author<<" "<<book.number<<std::endl;
    return out;
}

class AudioBook : public Book
{
    public:
//        friend std::ostream& operator<<(std::ostream& out,const AudioBook& book);
        AudioBook(const std::string isbn_,const std::string name_,const std::string au,float price_,size_t audio_lenth_,int year_=0,size_t number_=0,size_t borrowed_=0):Book(isbn_,name_,au,price_,number_,borrowed_,year_),audio_lenth(audio_lenth_) {};
        size_t get_audio_lenth(){return audio_lenth;}
    private:
        size_t audio_lenth;
};



#endif // BOOKS_H_INCLUDED
