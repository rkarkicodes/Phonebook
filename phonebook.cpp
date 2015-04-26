//  phonebook.cpp
//  Phonebook
//
//  Created by Rohit karki on 12/6/14.
//  Copyright (c) 2014 rohit karki. All rights reserved.
//

#include "phonebook.h"
#include "contact.h"
#include <typeinfo>
#include <locale>
Phonebook::Phonebook(){
    
    getActualPhonebook();
    string alpha= "abcdefghijklmnopqrstuvwxyz";
    for (int i=0;i < alpha.length();i++){
    setPhonebookIndex(alpha[i], i);
    };
};

bool Phonebook::contactExist(string name){
    bool a;
    int index=getPhonebookIndex()[name[0]];// index of the phonebook
    
    list<Contact> listIndex = getActualPhonebook()[index];
    list<Contact>:: iterator it = listIndex.begin();
    for (it;it!=listIndex.end();it++){
        if (it->getName()==name){
            a=1; // found
            
            break;
        }
    }
    return a;
};

list<Contact>::iterator Phonebook:: extractContact(string name){
    
    int index=getPhonebookIndex()[name[0]];// index of the phonebook
    
    list<Contact> listIndex = getActualPhonebook()[index];
    list<Contact>:: iterator it = listIndex.begin();

    for (it;it!=listIndex.end();it++){
        if (it->getName()==name){
            
            break;
        }
    }
    return it;

};

void Phonebook::addContact(Contact _record){
    
    int index=getPhonebookIndex()[_record.getName()[0]];
    setActualPhonebook(_record,index);
};

void Phonebook::searchContact(string name){
    
    if (contactExist(name)==1){
        cout<<"\t!!!!!FOUND!!!!!"<<endl;
        Phonebook::printInfo(*extractContact(name));
    }else{
        cout<<"Contact doesn't exist"<<endl;
    }
};


void Phonebook::deleteContact(string name){
    
    if (contactExist(name)==1){
        Phonebook::printInfo(*extractContact(name));
        char a;
        cout<<"Are you sure you want to delete above record?(Y|N)"<<endl;
        cin>>a;
        if(a=='y' or a=='Y'){
            int index=getPhonebookIndex()[name[0]];// index of the phonebook
            list<Contact> listIndex = getActualPhonebook()[index];
            list<Contact>:: iterator it = listIndex.begin();
            cout<<listIndex.size()<<endl;
            for (it;it!=listIndex.end();it++){
                
                if (it->getName()==name){
                    
                    listIndex.erase(it);
                    
                    break;
                }
            }
            setActualPhonebookList(listIndex,index);
            cout<<"Deletion Complete!!"<<endl;
            
        }
        
    }else{
        cout<<"Contact doesn't exist"<<endl;
    }
}

void Phonebook::editContact(string name){

    char command;
    if (contactExist(name)==1){
        Phonebook::printInfo(*extractContact(name));
        
        do{
            
            cout<<"What would you like to edit? N (name)| E (email) | R(relation) | P(phone no.)| Q (quit)"<<endl;
            
            cin>>command;
            if(command=='N' or command=='n'){
                //name
                string newName;
                cout<<"enter new Name";
                cin>>newName;
                int index=getPhonebookIndex()[name[0]];// index of the phonebook
                list<Contact> listIndex = getActualPhonebook()[index];
                list<Contact>:: iterator it = listIndex.begin();
                for (it;it!=listIndex.end();it++){
                    if (it->getName()==name){
                        
                        it->setname(newName);
                        name=newName;
                        setActualPhonebookList(listIndex, index);
                        //break;
                    }
                }
            }else if (command=='E' or command=='e'){
                //email
                string newEmail;
                cout<<"enter new email";
                cin>>newEmail;
                int index=getPhonebookIndex()[name[0]];// index of the phonebook
                list<Contact> listIndex = getActualPhonebook()[index];
                list<Contact>:: iterator it = listIndex.begin();
                for (it;it!=listIndex.end();it++){
                    if (it->getName()==name){
                        
                        it->setemail(newEmail);
                        setActualPhonebookList(listIndex, index);
                        //break;
                    }
                }
                
            }else if (command=='R' or command=='r'){
                //rela
                
                string newRelation;
                cout<<"enter new relationship";
                cin>>newRelation;
                int index=getPhonebookIndex()[name[0]];// index of the phonebook
                list<Contact> listIndex = getActualPhonebook()[index];
                list<Contact>:: iterator it = listIndex.begin();
                for (it;it!=listIndex.end();it++){
                    if (it->getName()==name){
                        
                        it->setRelation(newRelation);
                        setActualPhonebookList(listIndex, index);
                        //break;
                    }
                }
            }else if (command=='P' or command=='p'){
                //ph..
                string newPhone;
                
                cout<<"enter new phone no.";
                cin>>newPhone;
                int index=getPhonebookIndex()[name[0]];// index of the phonebook
                list<Contact> listIndex = getActualPhonebook()[index];
                list<Contact>:: iterator it = listIndex.begin();
                for (it;it!=listIndex.end();it++){
                    if (it->getName()==name){
                        it->setPhoneNumber(newPhone);
                        setActualPhonebookList(listIndex, index);
                        //break;
                    }
                }
                
            }else if (command=='q' or command=='Q'){
                break;
                
                
            }else{
                cout<<"enter a valid command"<<endl;
            }
            
        }while(command!='q' or command!='Q');
    }else{
        cout<<"Contact doesn't exist"<<endl;
    }
}

void Phonebook::printAll(){
    int count=0;
    
    for(int i=0; i<getActualPhonebook().size();i++){
        
        list<Contact> listIndex = getActualPhonebook()[i];
        
        if(listIndex.size()>0){

            list<Contact>:: iterator it = listIndex.begin();
            for (it;it!=listIndex.end();it++){
                count+=1;
                printInfo(*it);
            }
        }
    }
    cout<<"\t[Total Contacts:"<<count<<"]\t"<<endl;
}


void Phonebook::displayByRelation(string _relation){
    
    Contact::changeCase(_relation);
    int count=0;
    for(int i=0; i<getActualPhonebook().size();i++){
        list<Contact> listIndex = getActualPhonebook()[i];
        if(listIndex.size()>0){
            list<Contact>:: iterator it = listIndex.begin();
            for (it;it!=listIndex.end();it++){
                if(it->getRelation()==_relation){
                    count+=1;
                    printInfo(*it);
                }
            }
        }
    }
    if(count==0){cout<<"You don't have any "<<_relation<<" in your phonebook."<<endl;}
    
    else{
        
        cout<<"Number of "<<_relation<<": "<<count<<endl;
        
    };
}
    
    
    
    
    
    
    
    
    
    



