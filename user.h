#ifndef USER_H
#define USER_H

#include <string>
#include <fstream>
using namespace std;

class user{
private:
    string name;
    string password;
    string userid;
    string friends;
    int no;

public:
    user(){
        name = "";
        password = "";
        userid = "";
        fstream signin("signin.txt");
        int lines = 0;
        while(!signin.eof()){
            string temp;
            getline(signin,temp);
            lines++;
        }
        no = lines;
        signin.close();
    }
    bool SIGNIN(){
        fstream signin("signin.txt");
         if (signin.is_open()) {
        string n,p,id;
        int authenticate = 0;
        bool match = false;
        int lines = 0;
        cin.ignore();
        cout << "enter name:" << endl;
        getline(cin,name);
        cout << "enter id" << endl;
        getline(cin,userid);
        cout << "enter password" << endl;
        getline(cin,password);
        for (int i = 0; i < no; i++) {
            char ip;
            n = "";
            p = "";
            id = "";
            friends = "";
            while(signin.get(ip)){
                if(ip == '\n'){
                    continue;
                }
                else if(ip!='-'){
                    n += ip;
                }
                else{
                    break;
                }
            }
            while(signin.get(ip)){
                if(ip!='-'){
                    id += ip;
                }
                else{
                    break;
                }
            }
            while(signin.get(ip)){
                if(ip!='-'){
                    p += ip;
                }
                else{
                    break;
                }
            }
            while(signin.get(ip)){
                if(ip!='-'){
                    friends += ip;
                }
                else{
                    break;
                }
            }
            if(userid.length()==id.length())
            {
                int i = 0;
                while(i < userid.length()){
                    if(userid[i]==id[i]){
                        i++;
                    }
                    else{
                        break;
                    }
                }
                if(i==userid.length()){
                    authenticate++;
                }
                else{
                    continue;
                }
            }
            if(password.length()==p.length())
            {
                int i = 0;
                while(i < password.length()){
                    if(password[i]==p[i]){
                        i++;
                    }
                    else{
                        break;
                    }
                }
                if(i==password.length()){
                    authenticate++;
                }
                else{
                    continue;
                }
            }
            if(authenticate==2){
                cout << "login" << endl;
                match = true;
                signin.close();
                return 1;
            }
        }
        if(!match){
            cout << "invalid password or id" << endl;
            return 0;
            signin.close();
        }
    }
    else{
        cout << "file couldnot open" << endl;
    }
    }
    void SIGNUP(){
        cout << no << endl;
        cin.ignore();
    cout << "enter name:" << endl;
    getline(cin,name);
    cout << "enter id" << endl;
    getline(cin,userid);
    cout << "enter password" << endl;
    getline(cin,password);
    fstream signin("signin.txt");
    if (signin.is_open()) {
        string n,p,id;
        int authenticate = 0;
        bool match = false;
        int lines = 0;
        for (int j = 0; j < no; j++) {
            char ip;
            n = "";
            p = "";
            id = "";
            while(signin.get(ip)){
                if(ip == '\n'){
                    continue;
                }
                else if(ip!='-'){
                    n += ip;
                }
                else{
                    break;
                }
            }
            while(signin.get(ip)){
                if(ip!='-'){
                    id += ip;
                }
                else{
                    break;
                }
            }
            while(signin.get(ip)){
                if(ip!='-'){
                    p += ip;
                }
                else{
                    break;
                }
            }
            if(userid.length()==id.length())
            {
                unsigned int i = 0;
                while(i < userid.length()){
                    if(userid[i]==id[i]){
                        i++;
                    }
                    else{
                        break;
                    }
                }
                if(i== userid.length()){
                    authenticate++;
                }
                else{
                    continue;
                }
            }
            if(password.length()==p.length())
            {
                unsigned int i = 0;
                while( i < password.length()){
                    if(password[i]==p[i]){
                        i++;
                    }
                    else{
                        break;
                    }
                }
                if(i==password.length()){
                    authenticate++;
                }
                else{
                    continue;
                }
            }
            if(authenticate==2){
                cout << "already exist in database." << endl;
                match = true;
                signin.close();
                break;
            }
        }
        if(!match){
            signin.close();
            fstream signin("signin.txt",ios::app);
            if(signin.is_open()){
                signin << endl;
                signin << name;
                signin << "-";
                signin << userid;
                signin << "-";
                signin << password;
                signin << "-";
            }
        }
    }
    else{
        cout << "file couldnot open" << endl;
    }
    }
    int getno(){
        return no;
    }
    void userprofile(){
        system("clear");
        cout << endl << endl;
        cout << "\t\t\t\tNAME : " << name << endl;
        cout << "\t\t\t\tUSERID: " << userid << endl;
        fstream posts("post.txt");
        string post;
        if(posts.is_open()){
            while(!posts.eof()){
                getline(posts,post);
                if(post.substr(0,userid.length())==userid){
                    cout << endl << name << "posted" << post.substr(userid.length()+1,post.length()-10) << endl << endl;
                }
            }
        }
        else{
            cout << "couldnot open file" << endl;
        }
        posts.close();
    }
    string getuserid(){
        return userid;
    }
    string getfriends(){
        return friends;
    }
};
#endif 
