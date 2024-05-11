#ifndef COMMENTS_H
#define COMMENTS_H

#include <iostream>
#include <string>
#include <fstream>
#include "user.h"
using namespace std;

class comments: virtual public user{
string id;
string comment_;
public:
void comment(){
    cout << "enter id of post you want to comment on:" << endl;
    getline(cin,id);
    int commentcount = 0;
    bool islessthanten;
    string extract;
    fstream comments_("comments.txt");
    if(comments_.is_open()){
        while(getline(comments_,extract)){
            if(extract.substr(0,id.length())==id){
                commentcount++;
            }
        }
        if(commentcount>=10){
            islessthanten = false;
        }
        else{
            islessthanten = true;
        }
    }
    else{
        cout << "couldnot open file\n";
    }
    comments_.close();
    if(islessthanten){
        getline(cin,comment_);
        string uid = getuserid();
        fstream comment("comments.txt" , ios::app);
        if(comment.is_open()){
            comment << endl << id << "-" << uid << "-" << comment_;
        }
        else{
            cout << "cannot open file\n";
        }
        comment.close();
    }
    else{
        cout << "the post has more than 10 comments" << endl;
    }
}
};

#endif