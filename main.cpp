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
}
void SIGNUP(){

}
};
class app : public user{
    int choice;
    public:
    app() : user(){
        choice = 0;
    }
    void run(){
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
};
int main(){
     app a;
     a.run();
}