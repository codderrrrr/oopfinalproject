#ifndef LIKES_H
#define LIKES_H
#include <iostream>
#include <string>
#include <fstream>
#include "post.h"
#include "user.h"
using namespace std;

class likes: virtual public post , virtual public user{
    string likepostid;
public:
void displaylike(){
    cout << "enter postid to like" << endl;
    getline(cin,likepostid);
    fstream LIKE("likes.txt");
    if(LIKE.is_open()){
          while(!LIKE.eof()){
            string temp;
            getline(LIKE,temp);
            if(temp.substr(0, 5) == likepostid){
                int i = 0;
                while(temp[i]!='-'){
                    i++;
                }
                if(temp[i+1]=='\0'){
                    cout << "post is not liked by anyone" << endl;
                }
                else{
                    string s = temp.substr(6);
                    cout << "liked by " << endl;
                    int i = 0;
                    while(s[i]!='\0'){
                        if(s[i]!=' '){
                            cout << s[i];
                        }
                        else{
                            cout << endl;
                        }
                        i++;
                    }
                    cout << endl;
                }
                break;
            }
        }
    }
    else{
        cout << "couldnot open file" << endl;
    }
    LIKE.close();
}
void likepost(){
    cout << "enter the id of post you want to like: " << endl;
    getline(cin,likepostid);
    fstream temp("temp.txt");
    fstream like_("likes.txt");
    while(!like_.eof()){
        string line = "";
        getline(like_,line);
        if(line.substr(0,5)==likepostid){
            if(line[line.length()-1]!='-'){
                line += " " + getuserid();
                temp << line << endl;
            }
            else{
                line += getuserid();
               temp << line << endl;
            }
        }
        else{
            temp << line << endl;
        }
    }
    like_.close();
    temp.seekg(0, std::ios::beg);
    fstream like("likes.txt");
    while(!temp.eof()){
        string line = "";
        getline(temp,line);
        like << line;
        like << endl;
    }
    temp.close();
    like.close();
}   
};



#endif