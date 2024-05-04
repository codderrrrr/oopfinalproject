#ifndef APP_H
#define APP_H

#include "user.h"

class app : public user {
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
