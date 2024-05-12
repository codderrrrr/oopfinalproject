/*
    File: memories.h
    Author: saad waqar

    Description:
    This header file defines the memories class, which manages memories and activities shared by users.
    It provides functionalities to view, record, and manage user activities and associated feelings.
    Dependencies: user.h
*/


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
string dayofmemory;
string monthofmemory;
string yearofmemory;
public:
memories() : user(){
    memories_ = "";
    activity = "";
    dayofmemory = "";
    monthofmemory = "";
    yearofmemory = "";
}
void viewmemory(){
    cin.ignore();
    fstream postmemory("postmemory.txt");
    if(postmemory.is_open()){
        string d = getday();
        string m = getmonth();
        string y = getyear();
        string postextract;
        while(getline(postmemory,postextract)){
            int i = 0;
            string dayofmemory,monthofmemory,yearofmemory,userid;
            while(postextract[i]!='\0' && postextract[i]!='-'){
                userid += postextract[i];
                i++;
            }
            i++;
            while(postextract[i]!='-'){
                dayofmemory += postextract[i];
                i++;
            }
            i++;
            while(postextract[i]!='-'){
                monthofmemory += postextract[i];
                i++;
            }
            i++;
            while(postextract[i]!='-'){
                yearofmemory += postextract[i];
                i++;
            }
            i++;
            if(dayofmemory==d && monthofmemory==m){
                while(postextract[i]!='-'){
                    cout << postextract[i];
                    i++;
                }
                cout << endl;
                cout << "\t\t\tmemory from: " << dayofmemory << "-" << monthofmemory << "-" << yearofmemory << endl << endl;
            }
        }
    }
    else{
        cout << "coulnot open file " << endl;
    }
    postmemory.close();
}
void activity_(){
    cout << "enter your feeling:" << "\t";
    getline(cin,activity);
    cout << "enter memory:" << endl;
    getline(cin,memories_);
    cout << "enter dayofmemory" << endl;
    getline(cin,dayofmemory);
    cout << "enter monthofmemory" << endl;
    getline(cin,monthofmemory);
    cout << "enter yearofmemory" << endl;
    getline(cin,yearofmemory);
    fstream memory("memories.txt", ios::app);
    if(memory.is_open()){
        memory << "\n" <<  getuserid() << "-" << getname() << " is feeling " << activity << "-" << memories_ << "-" << dayofmemory << "-" << monthofmemory << "-" << yearofmemory << "-";
    }
    else{
        cout << "couldnot open file" << endl;
    }
    memory.close();
} 
void displayactiities(){
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
virtual ~memories(){}
};

#endif