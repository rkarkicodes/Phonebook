//
//  contact.h
//  Phonebook
//
//  Created by Rohit karki on 12/5/14.
//  Copyright (c) 2014 rohit karki. All rights reserved.
//

#ifndef __Phonebook__contact__
#define __Phonebook__contact__

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Contact{ //base class.
    
public:
    
    Contact();
    
    Contact(std::string _name,std::string _email,std::string _relation,string _phoneNumber);
    
    string getName(){return name;};
    string getRelation(){return relation;};
    string getEmail(){return email;};
    string getPhoneNumber(){return phoneNumber;};
    
    void setname(string _name){name=_name;};
    void setRelation(string _relation){relation=_relation;};
    void setemail(string _email){email=_email;};
    void setPhoneNumber(string _phoneNumber){phoneNumber=_phoneNumber;};
    
    virtual void printInfo(Contact _record); // virtual function
    string changeCase(string _a); // changes every entry into lower case.
    
    
    
    
private:
    std::string name,email,relation,phoneNumber;
    
};



#endif /* defined(__Phonebook__contact__) */
