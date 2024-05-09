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
public:
    user(){
        name = "";
        password = "";
        userid = "";
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
                cout << "password not matched" << endl;
                continue;
            }
            name = n;
            return 1;
        }
        return 0;
    }
    else{
        cout << "couldnot open file" << endl;
        return 0;
    }
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
            if(signin.is_open() && info.is_open()){
                signin << "\n" << name << "-" << userid << "-" << password << "-";
                info << "\n" << userid << "-" << name;
                friend_ << "\n" << name << "-";
            }
            else{
                cout << "couldnot open file";
            }
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
        fstream user_("friends.txt");
        system("clear");
        cin.ignore();
        string extract;
        string friend_;
        string friend2_;
        if(user_.is_open()){
            while(!user_.eof()){
                getline(user_,extract);
                if(extract.substr(0,name.length())==name){
                    friend_ = extract.substr(name.length()+1);
                    break;
                }
            }
            int i = 0;
            cout << name << " has following friends:\n";
            cout << "---------------------------------------------------" << endl;
            while(friend_[i]!='\0'){
                friend2_ ="";
                while(friend_[i]!=' ' && friend_[i]!='\0'){
                    friend2_ += friend_[i];
                    i++;
                }
                while(friend_[i]==' '){
                    i++;
                }
                string temp;
                if(friend2_[0]=='s'){
                    fstream f("name.txt");
                    if(f.is_open()){
                        while(!f.eof()){
                            getline(f,temp);
                            if(temp.substr(0,2)==friend2_){
                                cout << temp.substr(3) << endl;
                            }
                        }
                    }
                    else{
                        cout << "file couldnot open" << endl;
                    }
                    f.close();
                }
            }
            i = 0;
            cout << endl <<  name << " has following pages he has liked:\n";
            cout << "---------------------------------------------------" << endl;
            while(friend_[i]!='\0'){
                friend2_ ="";
                while(friend_[i]!=' ' && friend_[i]!='\0'){
                    friend2_ += friend_[i];
                    i++;
                }
                while(friend_[i]==' '){
                    i++;
                }
                string temp;
                if(friend2_[0]=='p'){
                    fstream f2("page.txt");
                    if(f2.is_open()){
                        while(!f2.eof()){
                            getline(f2,temp);
                            if(temp.substr(0,2)==friend2_){
                                cout << temp.substr(3) << endl;
                            }
                        }
                    }
                    else{
                        cout << "file couldnot open" << endl;
                    }
                    f2.close();
                }
            }
        }
        else{
            cout << "file couldnot open" << endl;
        }
        user_.close();
    }
    void addfriend(){
        fstream friend_("friends.txt");
        fstream namesandid("name.txt");
        fstream temporaryfile("temp2.txt");
        string f;
        if(friend_.is_open() && temporaryfile.is_open() &&  namesandid.is_open()){
            string temp;
            string info;
            while(!friend_.eof()){
                getline(friend_,temp);
                if(temp.substr(0,name.length())==name)
                {
                    cout << "enter id of user you want to add friend: " << endl;
                    while(!namesandid.eof()){
                        getline(namesandid,info);
                        cout << info.substr(0,userid.length()) << ":\t" << info.substr(userid.length()+1) << endl;
                    }
                    cin.ignore();
                    getline(cin,f);
                    temp += " " + f;
                    temporaryfile << temp << endl; 
                    
                }
                else{
                    temporaryfile << temp << endl;
                }
            }
        }
        else{
            cout << "couldnot open file\n";
        }
        friend_.close();
        temporaryfile.close();
        fstream friend__("friends.txt");
        fstream temporaryfile_("temp2.txt");
        f = "";
        if(temporaryfile_.is_open() && friend__.is_open()){
            while(!temporaryfile_.eof()){
                getline(temporaryfile_,f);
                friend__ << f << endl;
            }
        }
        else{
            cout << "couldnot open file " << endl;
        }
        friend__.close();
        temporaryfile_.close();
    }
    string getuserid(){
        return userid;
    }
    
    string getname(){
        return name;
    }
};
#endif 
