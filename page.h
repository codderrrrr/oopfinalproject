#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class page{
string pageid;
public:
void pageprofile(){
    cout << "enter id of page: " << endl;
    getline(cin,pageid);
    string post;
    string name;
    fstream page_("page.txt");
    if(page_.is_open()){
        while(!page_.eof())
        {
            getline(page_,name);
            if(name.substr(0,2)==pageid){
                cout << "PAGE NAME: " << name.substr(3) << endl;
            }
        }
    }
}
};

#endif