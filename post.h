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
        string extract,friendextract,friends;
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
                    if(post_.is_open()){
                        while(getline(post_,friends)){
                            if(friends.substr(0,friendextract.length())==friendextract){
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
                    else{
                        cout << "couldnot open file" << endl;
                    }
                    post_.close();
                }
            }
        }
    }
}

void display(){
    cout << "enter id of post you want to display post with comments:" << endl;
    cin.ignore();
    getline(cin,postid);
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
}
};

#endif