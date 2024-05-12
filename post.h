/*
    File: post.h
    Author: saad waqar

    Description:
    This header file defines the post class, which represents a post made by a user on a social media app.
    It provides functionalities to view, interact with, and manage posts within the application.
    Dependencies: user.h
*/
#ifndef POST_H
#define POST_H

#include <string>
#include <fstream>
using namespace std;


class post :virtual public user{
string postid;
public:
post() : user(){
    postid = "";
}
void home() {
    system("clear");
    cout << "   _   " << endl;
    cout << "  | |  " << endl;
    cout << "  | |__   ___  _ __ ___   ___   _ __   __ _  __ _  ___" << endl;
    cout << "  | '_ \\ / _ \\| '_ ` _ \\ / _ \\ | '_ \\ / _` |/ _` |/ _ \\" << endl;
    cout << "  | | | | (_) | | | | | |  __/ | |_) | (_| | (_| |  __/" << endl;
    cout << "  |_| |_|\\___/|_| |_| |_|\\___| | .__/ \\__,_|\\__, |\\___|" << endl;
    cout << "                                | |          __/ |" << endl;
    cout << "                                |_|         |___/ " << endl;                                                
    fstream signin("friends.txt");
    if(signin.is_open()){
        string extract,friendextract,friends,timeextract,day,month,year,d = getday(),m = getmonth(),y = getyear();
        string n = getname();
        string id = getuserid();
        while(getline(signin,extract))
        {
            if(extract.substr(0,n.length())==n){
                extract = extract.substr(n.length()+1);
                int i = 0;
                while(extract[i]!='\0'){
                    friendextract = "";
                    while(extract[i]!=' ' && extract[i]!='\0'){
                        friendextract = friendextract + extract[i];
                        i++;
                    }
                    i++;
                    fstream post_("post.txt");
                    fstream time_("posttime.txt");
                    if(post_.is_open() && time_.is_open()){
                        while(getline(post_,friends) && getline(time_,timeextract)){
                            day = "";
                            month = "";
                            year = "";
                            if(friends.substr(0,friendextract.length())==friendextract && timeextract.substr(0,friendextract.length())==friendextract){
                                timeextract = timeextract.substr(friendextract.length()+1);
                                int i = 0;
                                while(timeextract[i]!='\0'){
                                    while(timeextract[i]!=' ' && timeextract[i]!='\0'){
                                        day += timeextract[i];
                                        i++;
                                    }
                                    i++;
                                    while(timeextract[i]!=' ' && timeextract[i]!='\0'){
                                        month += timeextract[i];
                                        i++;
                                    }
                                    i++;
                                    while(timeextract[i]!=' ' && timeextract[i]!='\0'){
                                        year += timeextract[i];
                                        i++;
                                    }
                                }
                                int pday = stoi(d) -1;
                                string previousday = to_string(pday);
                                if((day == d || day == previousday) && month == m && year == y){
                                    friends = friends.substr(friendextract.length()+1);
                                    int j = 0;
                                    cout << friendextract << " posted:\n\t\t";
                                    while(friends[j]!='-'){
                                        cout << friends[j];
                                        j++;
                                    } 
                                    cout << endl;
                                }
                            }
                        }
                    }
                    else{
                        cout << "couldnot open file" << endl;
                    }
                    post_.close();
                    time_.close();
                }
            }
        }
    }
    else{
        cout << "couldnot open" << endl;
    }
    signin.close();
}

void addpost(){
    cin.ignore();
    fstream post_("post.txt");
    int postno = 0;
    string extract;
    if(post_.is_open()){
        while(getline(post_,extract)){
            postno++;
        }
        postno++;
    }
    else{
        cout << "couldnot open file." << endl;
    }
    post_.close();
    string postid_ = "post" + to_string(postno);
    cout << postid_ << endl;
    string texttopost;
    cout << "enter post:" << endl;
    getline(cin,texttopost);
    fstream posttime_("posttime.txt", ios::app);
    fstream posts_("post.txt" , ios::app);
    fstream postmemory_("postmemory.txt" , ios::app);
    if(posts_.is_open() && posttime_.is_open() && postmemory_.is_open()){
        posts_ << endl << getuserid() << "-" << texttopost << "-" << postid_ << "-";
        posttime_ << endl << getuserid() << "-" << getday() << " " << getmonth() << " " << getyear();
        postmemory_ << endl << getuserid() << "-" << getday() << "-" << getmonth() << "-" << getyear() << "-" << texttopost << "-";
    }
    else{
        cout << "couldnot open file\n";
    }
    posttime_.close();
    posts_.close();
    postmemory_.close();
}
void display(){
    cin.ignore();
    cout << "enter id of post you want to display post with comments:" << endl;
    getline(cin,postid);
    if(postid.length()<5){
        cout << "enter valid postid" << endl;
        return ;
    }
    fstream posts_("post.txt");
    string extract;
    string matchpostid = "";
    string userid = "";
    string display = "";
    if(posts_.is_open()){
        while(getline(posts_,extract)){
            int i= 0;
            matchpostid = "", userid = "", display = "";
                while(extract[i]!='-'){
                userid += extract[i];
                i++;
            }
            i++;
            while(extract[i]!='-'){
                display += extract[i];
                i++;
            }
            i++;
            while(extract[i]!='-'){
                matchpostid += extract[i];
                i++;
            }
            if(matchpostid==postid)
            {
                cout << userid << " posted:\n\t\t"<< display << endl;
                break;
            }
        }
    }
    else{
        cout << "couldnot ope file\n";
    }
    posts_.close();
    cout << "\n\nComments:\n";
    string comment_;
    string uid = getuserid();
    fstream comment("comments.txt");
    if(comment.is_open()){
            while(!comment.eof()){
            comment_ = "";
            getline(comment,comment_);
            if(comment_.substr(0,postid.length())==postid){
            comment_ = comment_.substr(postid.length()+1);
            cout << comment_.substr(0,uid.length()) << endl;
            comment_ = comment_.substr(uid.length()+1);
            cout << "\t" << comment_ << endl;
        }
        }
    }
    else{
        cout << "file is not able to open" << endl;
    } 
    comment.close();
}
virtual ~post(){

}
};

#endif