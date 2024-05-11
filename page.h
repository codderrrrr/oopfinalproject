/*
    File: page.h
    Author: saad waqar

    Description:
    This header file defines the page class, representing a page within the social media app.
    It enables users to view page profiles and posts, as well as interact with page content.
    No dependencies.
*/


#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class page{
string pageid;
public:
// void home(){

// }
void pageprofile(){
    cin.ignore();
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
                cout << "\t\t\t\tPAGE NAME: " << name.substr(3) << endl;
                break;
            }
        }
    }
    else{
        cout << "file couldnot open " << endl;
    }
    page_.close();
    fstream posts_("post.txt");
    if(posts_.is_open()){
        cout << "page " << name.substr(3)  << " posted:\n";
        while(!posts_.eof()){
            getline(posts_,post);
            if(post.substr(0,2)==pageid){
                cout << "\t" << post.substr(3,post.length()-10) << endl;  
            }
        }
    }
    else{
        cout << "couldnot open file: " << endl;
    }
    posts_.close();
}
};

#endif