#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
class user{
string name;
string password;
string userid;
public:
user(){
    name = "";
    password = "";
    userid = "";
}
void SIGNIN(){
    fstream signin("signin.txt");
    if (signin.is_open()) {
        string n,p,id;
        int authenticate = 0;
        bool match = false;
        int lines = 0;
        while(!signin.eof()){
            string temp;
            getline(signin,temp);
            lines++;
        }
        signin.seekg(0, ios::beg);
        cin.ignore();
        cout << "enter name:" << endl;
        getline(cin,name);
        cout << "enter id" << endl;
        getline(cin,userid);
        cout << "enter password" << endl;
        getline(cin,password);
        for (int i = 0; i < lines; i++) {
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
                break;
            }
        }
        if(!match){
            cout << "invalid password or id" << endl;
            signin.close();
        }
    }
    else{
        cout << "file couldnot open" << endl;
    }
}
void SIGNUP(){
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
        while(!signin.eof()){
            string temp;
            getline(signin,temp);
            lines++;
        }
        signin.seekg(0, ios::beg);
        for (int j = 0; j < lines; j++) {
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
                signin.close();
            }
            else{
                cout << "file couldnot be opened.\n";
            }
        }
    }
    else{
        cout << "file couldnot open" << endl;
    }
}
};
class app : public user{
    int choice;
    public:
    app() : user(){
        choice = 0;
    }
    void run(){
        while(choice != 3){
            cout << "enter:\n1)sign-in\n2)sign-up\n3)exit\n";
            cin >> choice;
            if(choice==1){
            SIGNIN();
        }
        else if(choice==2){
            SIGNUP();
        }
        else if(choice == 3){
            exit(0);
        } 
        else{
            run();
        }
        }
    }
};
int main(){
     app a;
     a.run();
}