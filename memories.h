#ifndef MEMORIES_H
#define MEMORIES_H

#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include "user.h"
using namespace std;

class memories : virtual private user{
string memories_;
string activity;
string day;
string month;
string year;
public:
void memory(){
    cout << "enter your feeling:" << "\t";
    getline(cin,activity);
    cout << "enter memory:" << endl;
    getline(cin,memories_);
    cout << "enter day" << endl;
    getline(cin,day);
    cout << "enter month" << endl;
    getline(cin,month);
    cout << "enter year" << endl;
    getline(cin,year);
    fstream memory("memories.txt", ios::app);
    if(memory.is_open()){
        memory << "\n" <<  getuserid() << "-" << getname() << " is feeling " << activity << "-" << memories_ << "-" << day << "-" << month << "-" << year << "-";
    }
    else{
        cout << "couldnot open file" << endl;
    }
    memory.close();
} 
void displaymemories(){
    fstream memory("memories.txt");
    string id = getuserid();
    if(memory.is_open()){
        string m;
        while(getline(memory,m)){
            if(m.substr(0,id.length())==id){
                m = m.substr(id.length()+1);
                int i = 0;
                while(m[i]!='-'){
                    cout << m[i];
                    i++;
                }
                i++;
                cout << "\n\t";
                while(m[i]!='-'){
                    cout << m[i];
                    i++;
                }
                i++;
                cout << '\n';
                while(m[i+1]!='\0'){
                    cout << m[i];
                    i++;
                }
                cout << endl;
            }
        }
    }
    else{
        cout << "couldnot open file\n";
    }
    memory.close();
}
};

#endif