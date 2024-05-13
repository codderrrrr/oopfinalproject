/*
    File: user.h
    Author: saad waqar

    Description:
    This header file defines the user class, representing a user of the social media app.
    It handles user authentication, profile management, friend-related functionalities, and user interactions.
    No dependencies.
*/


#ifndef USER_H
#define USER_H

#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class user{
private:
    string name;
    string password;
    string userid;
    string day;
    string month;
    string year;
public:
    user()
    {
        name = "";
        password = "";
        userid = "";
        day = "";
        month = "";
        year = "";
    }
    void settime(){
        time_t currentTime = time(nullptr);
        tm* now = localtime(&currentTime);
        int d = now->tm_mday;
        int m = now->tm_mon + 1;
        int y = now->tm_year + 1900; 
        day = to_string(d);
        month = to_string(m);
        year = to_string(y);
    }
    bool SIGNIN() {
    cin.ignore();
    string textreader,n,p,id;
    fstream signin("signin.txt");
    if(signin.is_open()){
        cout << "enter id:\t";
        getline(cin,userid);
        cout << "enter password:\t";
        getline(cin,password);
        while(!signin.eof()){
            n = "", p = "", id = "";
            textreader = "";
            getline(signin,textreader);
            int i = 0;
            while(textreader[i]!='\0'){
                while(textreader[i]!='-'){
                    n += textreader[i];
                    i++;
                }
                i++;
                while(textreader[i]!='-'){
                    id += textreader[i];
                    i++;
                }
                i++;
                while(textreader[i]!='-'){
                    p += textreader[i];
                    i++;
                }
                i++;
            }
            int j = 0;
            if(id!=userid){
                continue;
            }
            if(p!=password){
                continue;
            }
            name = n;
            signin.close();
            return 1;
        }
        cout << "password or userid not matched\n";
        return 0;
    }
    else{
        cout << "couldnot open file" << endl;
        return 0;
    }
}
string getday(){
    return day;
}
string getmonth(){
    return month;
}
string getyear(){
    return year;
}
bool alreadyindb() {
    cin.ignore();
    string textreader,n,p,id;
    fstream signin("signin.txt");
    if(signin.is_open()){
        cout << "enter id:\t";
        getline(cin,userid);
        while(!signin.eof()){
            n = "", p = "", id = "";
            textreader = "";
            getline(signin,textreader);
            int i = 0;
            while(textreader[i]!='\0'){
                while(textreader[i]!='-'){
                    n += textreader[i];
                    i++;
                }
                i++;
                while(textreader[i]!='-'){
                    id += textreader[i];
                    i++;
                }
                i++;
                while(textreader[i]!='-'){
                    p += textreader[i];
                    i++;
                }
                i++;
            }
            if(userid==id){
                return 1;
            }
        }
        cout << userid << endl;
        signin.close();
        return 0;
    }
    else{
        cout << "couldnot open file" << endl;
        return 0;
    }
}
    void SIGNUP(){
        if(alreadyindb()==0){
            cout << "enter name:\t";
            getline(cin,name);
            cout << "enter password:\t";
            getline(cin,password);
            fstream signin("signin.txt", ios::app);
            fstream info("name.txt", ios::app);
            fstream friend_("friends.txt", ios::app);
            fstream fri_end("userfriends.txt", ios::app);
            if(signin.is_open() && info.is_open()){
                signin << "\n" << name << "-" << userid << "-" << password << "-";
                info << "\n" << userid << "-" << name;
                friend_ << "\n" << name << "-";
                fri_end << "\n" << name << "-";
            }
            else{
                cout << "couldnot open file";
            }
            signin.close();
            info.close();
            friend_.close();
            fri_end.close();
        }
        else{
            cout << "data already in database" << endl;
        }

    }
    void userprofile(){
        system("clear");
        cin.ignore();
        cout << endl << endl;
        cout << "\t\t\t\tNAME : " << name << endl;
        cout << "\t\t\t\tUSERID: " << userid << endl;
        fstream posts("post.txt");
        string post;
        if(posts.is_open()){
            while(!posts.eof()){
                getline(posts,post);
                if(post.substr(0,userid.length())==userid){
                    cout << endl << name << "\n\t\t" <<  "posted" << post.substr(userid.length()+1,post.length()-userid.length()-1-7) << endl << endl;
                }
            }
        }
        else{
            cout << "couldnot open file" << endl;
        }
        posts.close();
    }
    void viewfriendlist(){
        cin.ignore();
        cout << "the friend list of " << name << "is:\n" << endl;
        fstream friend_("userfriends.txt");
        if(friend_.is_open()){
            string name = getname();
            string line;
            while(getline(friend_,line)){
                if(line.substr(0,name.length())==name){
                    line = line.substr(name.length()+1);
                    int i = 0;
                    while(line[i]!='\0'){
                        while(line[i]!=' ' && line[i]!='\0'){
                            cout << line[i];
                            i++;
                        }
                        if(line[i]!='\0'){
                            i++;
                        }
                       // i++;
                        cout << endl;
                    }
                }
            }
            friend_.close();
        }
        else{
            cout << "couldnot open file\n";
        }
    }
    void addfriend(){
        cin.ignore();
        fstream friends_("userfriends.txt");
        ofstream tfaf("temptoaddfriend.txt");
        string add;
        cout << "enter userid you want to add as friend" << endl;
        getline(cin,add);
        if(friends_.is_open() && tfaf.is_open()){
            string extract;
            while(getline(friends_,extract)){
                if(extract.substr(0,name.length())==name){
                    if(extract[extract.length()-2]!='-')
                    {
                        extract += " " + add;
                        tfaf << extract << endl; 
                    }
                    else if(extract[extract.length()-2]=='-'){
                        extract += add;
                        tfaf << extract << endl;
                    }
                }
                else{
                    tfaf << extract << endl;
                }
            }
        } 
        friends_.close();
        tfaf.close();
        rename("temptoaddfriend.txt", "userfriends.txt");
        remove("temptoaddfriend.txt");
    }
    string getuserid(){
        return userid;
    }
    
    string getname(){
        return name;
    }
    virtual ~user(){

    }
};
#endif 
