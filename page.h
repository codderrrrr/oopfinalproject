#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <fstream>
#include "post.h"
using namespace std;
class page : public post{
    string pageid;
public:
    page(){
        pageid = "";
    }
    void homepage(){
        
    }
};

#endif