#ifndef COMMENTS_H
#define COMMENTS_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class comments{
string id;
string comment_;
public:
void comment(){
    cout << "enter id of post you want to comment on:" << endl;
    getline(cin,id);
    getline(cin,comment_);
    fstream comment("comments.txt" , ios::app);
    if(comment.is_open()){
        comment << endl << id << "-" << comment_ << endl;
    }
    else{
        cout << "cannot open file\n";
    }
    comment.close();
}
void displaypost(string postid){
    fstream comment("comments.text");
    if(comment.is_open()){
        getline(comment,comment_);
        if(comment_.substr(0,postid.length())==postid){
            cout << comment_.substr(postid.length()+2,comment_.length()-2);
        }
    }
    else{
        cout << "file is not able to open" << endl;
    }
}
};

#endif