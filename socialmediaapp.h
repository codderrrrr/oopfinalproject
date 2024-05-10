#ifndef APP_H
#define APP_H
#define ANSI_COLOR_RED     "\x1b[31m"

#include <iostream>
#include "user.h"
#include "post.h"
#include "likes.h"
#include "comments.h"
#include "page.h"
#include "memories.h"

class app : virtual public user, virtual public post, virtual public likes , virtual public comments, virtual public page, virtual public memories{
private:
    int choice;
    int choice2;
public:
    app() : user() {
    choice = 0;
}
    void run(){
    while (choice != 3) {
        const std::string ANSI_RESET = "\033[0m";
        const std::string ANSI_RED = "\033[31m";
        const std::string ANSI_GREEN = "\033[32m";
        const std::string ANSI_YELLOW = "\033[33m";
        const std::string ANSI_BLUE = "\033[34m";
        const std::string ANSI_MAGENTA = "\033[35m";
        const std::string ANSI_CYAN = "\033[36m";
        const std::string ANSI_WHITE = "\033[37m";
        const std::string ANSI_BRIGHT_BLACK = "\033[90m";
        const std::string ANSI_BRIGHT_RED = "\033[91m";
        const std::string ANSI_BRIGHT_GREEN = "\033[92m";
        const std::string ANSI_BRIGHT_YELLOW = "\033[93m";
        const std::string ANSI_BRIGHT_BLUE = "\033[94m";
        const std::string ANSI_BRIGHT_MAGENTA = "\033[95m";
        const std::string ANSI_BRIGHT_CYAN = "\033[96m";
        const std::string ANSI_BRIGHT_WHITE = "\033[97m";
        cout << ANSI_MAGENTA << "Enter:\n1) Sign-in\n2) Sign-up\n3) Exit\n" << ANSI_RESET;
        cin >> choice;
        if (choice == 1) {
            cout << ANSI_GREEN;
            if(SIGNIN()==1){
                settime();
                cout << ANSI_RED;
                home();
                while(1){
                cout << ANSI_WHITE;
                cout << "Press any key to continue..." << endl;
                cin.get(); 
                system("clear");
                cout << ANSI_CYAN << "enter\n1:display likes\n2:like a post\n3:comment\n4:display post\n5:user profile\n6:page profile\n7:view friends\n8:add friend\n9:display activity\n10:post activity\n11:display memory\n12:exit\n" << ANSI_RESET;
                cin >> choice2;
                if(choice2==1){
                    cout << ANSI_YELLOW;
                    cin.ignore();
                    displaylike();
                    cout << ANSI_RESET;
                }
                else if(choice2==2){
                    cout << ANSI_BRIGHT_RED;
                    cin.ignore();
                    likepost();
                    cout << ANSI_RESET;
                }
                else if(choice2==3){
                    cout << ANSI_BRIGHT_CYAN;
                    cin.ignore();
                    comment();
                    cout << ANSI_RESET;
                }
                else if(choice2==4){
                    cout << ANSI_BRIGHT_GREEN;
                    display();
                    cout << ANSI_RESET;
                }
                else if(choice2==5){
                    cout << ANSI_BRIGHT_YELLOW;
                    userprofile();
                    cout << ANSI_RESET;
                }
                else if(choice2==6){
                    cout << ANSI_BRIGHT_MAGENTA;
                    pageprofile();
                    cout << ANSI_RESET;
                }
                else if(choice2==7){
                    cout << ANSI_BRIGHT_YELLOW;
                    viewfriendlist();
                    cout << ANSI_RESET;
                }
                else if(choice2==8){
                    cout << ANSI_RED;
                    addfriend();
                    cout << ANSI_RESET;
                }
                else if(choice2==9){
                    cout << ANSI_BRIGHT_MAGENTA;
                    cin.ignore();
                    displayactiities();
                    cout << ANSI_RESET;
                }
                else if(choice2==10){
                    cout << ANSI_GREEN;
                    cin.ignore();
                    activity_();
                    cout << ANSI_RESET;
                }
                else if(choice2 == 11){
                    cout << ANSI_BRIGHT_CYAN;
                    viewmemory();
                    cout << ANSI_RESET;
                }
                else if(choice2 == 12){
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
            exit(0);
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    }
};

#endif 
