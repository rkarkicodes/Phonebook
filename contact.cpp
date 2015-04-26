//  contact.cpp
//  Phonebook
//  Created by Rohit Karki on 12/7/14.
//  Copyright (c) 2014 rohit karki. All rights reserved.


#include "contact.h"

Contact::Contact(){
    name=" ";
    email=" ";
    relation=" ";
    phoneNumber=" ";
}

Contact::Contact(string _name,string _email,string _relation,string _phoneNumber){
    
    name=changeCase(_name);
    email=changeCase(_email);
    relation=changeCase(_relation);
    phoneNumber=_phoneNumber;
}

string Contact::changeCase(string _a){
    
    char firstLetter= _a[0];
    firstLetter=tolower(firstLetter);
    string lowered=firstLetter + _a.substr(1,-1);
    return lowered;
}

void Contact::printInfo(Contact _record){
    printf("-------%s------- \n Name:%s\n Email:%s\n Relation:%s\n Phone Number:%s\n",_record.getName().c_str(),_record.getName().c_str(),_record.getEmail().c_str(),_record.getRelation().c_str(),_record.getPhoneNumber().c_str());
}