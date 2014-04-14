#ifndef TQ_H_INCLUDED
#define TQ_H_INCLUDED

class TQ
{
public:
    bool openfile(std::string filename)
    {
        inf.close();
        inf.clear();
        inf.open(filename.c_str());
        if(inf)
        {
            fileopen=true;
            return 1;
        }
        else return 0;
    }
    TQ(std::string filename)
    {
        if(!openfile(filename))
            throw std::runtime_error("openfile error");
        else fileopen=true;
    }
    void findword(std::string key)
    {
        if(!fileopen)
            throw std::runtime_error("file haven't opened");
        std::string tempstring;
        unsigned line(0);
        while(1)
        {
            getline(inf,tempstring);
            ++line;
            std::istringstream tword(tempstring);
            std::string word;
            while(1)
            {
                tword>>word;
                if(word==key)
                    keyline[line]=tempstring;
                if(!tword)
                {
                    if(tword.eof())
                        break;
                    else if(tword.bad()||tword.fail())
                        throw std::runtime_error("read line error");
                }
            }
            if(!inf)
            {
                if(inf.eof())
                    break;
                else if(inf.bad()||inf.fail())
                    throw std::runtime_error("read file error");
            }
        }
        std::cout<<key<<" occurs "<<keyline.size()<<" time(s)"<<std::endl<<std::endl;
        for(std::map<int,std::string>::iterator iter=keyline.begin(); iter!=keyline.end(); ++iter)
        {
            std::cout<<"(line:"<<iter->first<<") "<<iter->second<<std::endl;
        }
        std::cout<<"write to a file? y/n"<<std::endl;
        char f;
        while(std::cin>>f)
            if(f=='y')
            {
                std::cout<<"please input file name"<<std::endl;
                std::string outfilename;
                std::cin>>outfilename;
                std::ofstream outfile(outfilename.c_str());
                if(!outfile)
                    throw std::runtime_error("can not open the file");
                outfile<<key<<" occurs "<<keyline.size()<<" time(s)"<<std::endl;;
                for(std::map<int,std::string>::iterator iter=keyline.begin(); iter!=keyline.end(); ++iter)
                {
                    outfile<<"(line:"<<iter->first<<") "<<iter->second<<std::endl;
                }
                break;
            }
            else if(f=='n')
                break;
            else std::cerr<<"please input y/n"<<std::endl;
    }
private:
    std::ifstream inf;
    std::map<int,std::string> keyline;
    std::pair<int,std::string> tem;
    bool fileopen;

};

#endif // TQ_H_INCLUDED
