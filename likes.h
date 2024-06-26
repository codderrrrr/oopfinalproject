/*
    File: likes.h
    Author: saad waqar

    Description:
    This header file defines the likes class, which manages post likes within the social media app.
    It provides functionalities to view likes on posts, like/unlike posts, and limit the number of likes per post.
    Dependencies: user.h, post.h
*/


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
likes() : post() , user(){
    likepostid = "";
}
void displaylike(){
    cout << "enter postid to view like" << endl;
    getline(cin,likepostid);
    if(likepostid.length()<5){
        cout << "enter valid postid" << endl;
        return ;
    }
    fstream post_("post.txt");
    if(post_.is_open()){
        string postextract;
        int stop = 0;
        while(getline(post_,postextract)){
            int i = 0;
            if(postextract.find(likepostid)!= string::npos){
                int i = 0;
                cout << "POSTED BY:\t";
                while(postextract[i]!='-'){
                    cout << postextract[i];
                    i++;
                }
                i++;
                cout << "\n\t\t\"";
                while(postextract[i]!='-'){
                    cout << postextract[i];
                    i++;
                }
                cout << "\""<<endl;
                break;
            }
        }
    }
    else{
        cout << "couldnot open file\n";
    }
    post_.close();
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
    if(likepostid.length()<5){
        cout << "enter valid postid" << endl;
        return ;
    }
    fstream likes_("likes.txt");
    int friendscount = 0;
    bool lessthanten;
    if(likes_.is_open()){
        string extract;
        while(getline(likes_,extract)){
            if(extract.substr(0,likepostid.length())==likepostid){
                int i = 0;
                extract = extract.substr(likepostid.length()+1);
                while(extract[i]!='\0'){
                    while(extract[i]==' '){
                        i++;
                    }
                    while(extract[i]!=' ' && extract[i]!='\0'){
                        i++;
                    }
                    friendscount++;
                    if(extract[i]!='\0'){
                        i++;
                    }
                }
                if(friendscount>10){
                    lessthanten = false;
                }
                else{
                    lessthanten = true;
                }
                break;
            }
        }
    }
    else{
        cout << "couldnot open file" << endl;
    }
    likes_.close();
    if(lessthanten){
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
        temp.close();
        rename("temp.txt","likes.txt");
        remove("temp.txt");
    }
    else{
        cout << "post has more than 10 likes.\n";
    }
}   
virtual ~likes(){}
};



#endif