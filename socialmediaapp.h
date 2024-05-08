#ifndef APP_H
#define APP_H

#include <iostream>
#include "user.h"
#include "post.h"
#include "likes.h"
#include "comments.h"
#include "page.h"
//#include <conio.h>
class app : virtual public user, virtual public post, virtual public likes , virtual public comments, virtual public page{
private:
    int choice;
    int choice2;
public:
    app() : user() {
    choice = 0;
}
    void run(){
    while (choice != 3) {
        std::cout << "Enter:\n1) Sign-in\n2) Sign-up\n3) Exit\n";
        std::cin >> choice;
        if (choice == 1) {
            if(SIGNIN()==1){
                home();
                cout << "Press any key to continue..." << std::endl;
                cin.get(); 
                while(1){
                cout << "enter\n1:display likes\n2:like a post\n3:comment\n4:display post\n5:user profile\n6:page profile\n7:view friends\n8:exit\n";
                cin >> choice2;
                if(choice2==1){
                    cin.ignore();
                    displaylike();
                }
                else if(choice2==2){
                    cin.ignore();
                    likepost();
                }
                else if(choice2==3){
                    cin.ignore();
                    comment();
                }
                else if(choice2==4){
                    display();
                }
                else if(choice2==5){
                    userprofile();
                }
                else if(choice2==6){
                    pageprofile();
                }
                else if(choice2==7){
                    viewfriendlist();
                }
                else if(choice2==8){
                    addfriend();
                }
                else if(choice2=9){
                    break;
                }
                else{
                    cout << "invalid option:" << endl;
                }
                }
            }
        } else if (choice == 2) {
            SIGNUP();
        } else if (choice == 3) {
            std::exit(0);
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    }
};

#endif 
