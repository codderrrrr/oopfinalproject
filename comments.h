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
// void displaypost(string postid){
//     fstream comment("comments.text");
//     string uid = getuserid();
//     if(comment.is_open()){
//         getline(comment,comment_);
//         if(comment_.substr(0,postid.length())==postid){
//             //cout << comment_.substr(postid.length()+2,postid.length()+uid.length()+3) << endl;
//             //cout << comment_.substr(postid.length()+uid.length()+2);
//         }
//     }
//     else{
//         cout << "file is not able to open" << endl;
//     }
// }
};

#endif