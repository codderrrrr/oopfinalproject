#ifndef APP_H
#define APP_H

#include "user.h"
#include "page.h"
#include "post.h"
#include "likes.h"
class app : virtual public user, virtual public post, virtual public likes{
private:
    int choice;
public:
    app() : user() {
    choice = 0;
}
    void run(){
    while (choice != 3) {
        std::cout << "Enter:\n1) Sign-in\n2) Sign-up\n3) Exit\n";
        std::cin >> choice;

        if (choice == 1) {
            SIGNIN();
            home();
            displaylike();
            likepost();
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
