//
//  phonebook.h
//  Phonebook
//
//  Created by Rohit karki on 12/6/14.
//  Copyright (c) 2014 rohit karki. All rights reserved.
//

#ifndef __Phonebook__phonebook__
#define __Phonebook__phonebook__

#include <iostream>
#include <list>
#include <string>
#include <array>
#include <map>
#include "contact.h"

class Phonebook:public Contact{
    
public:
    
    Phonebook();
    
    
    map<char,int> getPhonebookIndex(){return phonebookIndex;};
    array<list<Contact>,26> getActualPhonebook(){return actualPhonebook;};
    
    
    
    void setPhonebookIndex(char _alphabet,int number){phonebookIndex[_alphabet]=number;};//sets up map with alphabets and corresponding number.
    void setActualPhonebook(Contact _record,int _index){actualPhonebook[_index].push_back(_record);}; //adds one contact to the list of an index of the array
    void setActualPhonebookList(list<Contact> _recordlist,int _index){actualPhonebook[_index]=_recordlist;}; //adds the whole list to index of the array
    
    
    bool contactExist(string name); // checks if contact exists.
    list<Contact>::iterator extractContact(string name); // returns the the contact object corresponding to name.
    void printAll(); // prints all the contacts.
    void searchContact(string name); // searches for a contact.
    void addContact(Contact _record);//adds a contact.
    void deleteContact(string name);//deletes a contact.
    void editContact(string name);//edits a contact.
    void displayByRelation(string _relation); //displays contact corresponding to relation.
    
    
private:
    map<char,int> phonebookIndex; // the indeces of phonebook.
    array<list<Contact>,26> actualPhonebook; // the actial directory
    
};

#endif /* defined(__Phonebook__phonebook__) */
