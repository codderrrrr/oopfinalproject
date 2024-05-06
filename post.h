#ifndef POST_H
#define POST_H

#include <string>
#include <fstream>
using namespace std;

class post :virtual public user{
string postid;
public:
post(){
    postid = "";
}
void home() {
        string ftemp = getfriends();
        string temp;
        system("clear");
        int i = 0;
        while(ftemp[i]!='\0') {
            temp = "";
            while (ftemp[i] != ' ' && ftemp[i] != '\0') {
                temp += ftemp[i];
                i++;
            }
            i++;
            fstream post("post.txt");
            if (post.is_open()) {
                string exist;
                while (!post.eof()) {
                    getline(post,exist);
                    if (exist.substr(0, temp.length()) == temp) {
                        cout << exist.substr(0, temp.size()) << "posted ";
                        cout << exist.substr(temp.length()+1, exist.length()-10) << endl;
                    }
                }
                post.close();
            } else {
                cout << "file couldnot open" << endl;
            }
        }
    }
void display(){
    cout << "enter id of post you want to display post with comments:" << endl;
    cin.ignore();
    getline(cin,postid);
    string comment_;
    fstream comment("comments.txt");
    if(comment.is_open()){
            while(!comment.eof()){
            comment_ = "";
            getline(comment,comment_);
            if(comment_.substr(0,postid.length())==postid){
            cout << comment_.substr(postid.length()+1) << endl;
        }
        }
    }
    else{
        cout << "file is not able to open" << endl;
    } 
}
};

#endif