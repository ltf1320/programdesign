#ifndef OPEN_FILE_H_INCLUDED
#define OPEN_FILE_H_INCLUDED

bool open_file(std::ifstream &in,std::ofstream &out,const std::string &filename)
{
    in.close();
    out.close();
    in.clear();
    out.clear();
    out.open(filename.c_str(),std::ofstream::app);
    in.open(filename.c_str());
    return in&&out?1:0;
}

#endif // OPEN_FILE_H_INCLUDED
