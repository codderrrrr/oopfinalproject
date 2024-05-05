#ifndef LIKES_H
#define LIKES_H
#include <iostream>
#include <string>
#include <fstream>
#include "post.h"
using namespace std;

class likes: virtual public post{
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
}
void likepost(){
    cout << "enter the id of post you want to like: " << endl;
    getline(cin,likepostid);
    fstream temp("temp.txt");
    
}   
};



#endif