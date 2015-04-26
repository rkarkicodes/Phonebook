//  main.cpp
//  Phonebook
//
//  Created by Rohit Karki on 12/5/14.
//  Copyright (c) 2014 rohit karki. All rights reserved.
//

#include <iostream>
#include <list>
#include <string>
#include <array>
#include <map>
#include <typeinfo>
#include "contact.h"
#include "phonebook.h"
#include "tinyxml2.h"
using namespace tinyxml2;
using namespace std;

Phonebook setupPhonebook(XMLElement *_people,Phonebook p){
    //extracts info from xml and stores in the phonebook.
   
    XMLElement *cRecord=_people->FirstChildElement();
    for( cRecord; cRecord!=NULL; cRecord=cRecord->NextSiblingElement()){
        Contact record(cRecord->Attribute("name"),cRecord->Attribute("email"),cRecord->Attribute("relation"),(cRecord->Attribute("phoneNumber")));
        p.addContact(record);
    };
    return p;
}

int main(int argc, const char * argv[])
{
    Phonebook p;
    XMLDocument doc;
    bool load=doc.LoadFile("contact.xml");
//    cout<<load<<endl;
    
    
    XMLElement *people = doc.FirstChildElement();
    p=setupPhonebook(people,p); // calling setup phonebook function.
    
    char command;
    do{
        

        cout<<"P(Print all)| A(add) | S(search) | E (edit) | D(delete) | R(Display by Relation)| Q(Quit)"<<endl;
        cin>>command;
        
        if(command=='P' or command =='p'){
            p.printAll();
        }else if(command=='a' or command =='A'){
            //add
            string name,email,relation,phone;
            cout<<"Enter Name "<<endl;
            cin>>name;
            //getline(cin,name);
            cout<<"Enter Email "<<endl;
            
            cin>>email;
            cout<<"Enter Relation "<<endl;
            //getline(cin,relation);
            cin>>relation;
            cout<<"Enter Phone no. "<<endl;
            //getline(cin,phone);
            cin>>phone;
            
            p.addContact(Contact(name,email,relation,phone));
            cout<<"Contact added"<<endl;
        
        }else if(command=='s' or command =='S'){
            //search
            string searchName;
            cout<<"Enter name"<<endl;
            cin>>searchName;
            
            p.searchContact(searchName);
        
        }else if(command=='e' or command =='E'){
            //editt
            string editName;
            cout<<"Enter name"<<endl;
            cin>>editName;
            
            p.editContact(editName);
            
            
        }else if(command=='d' or command =='D'){
            
            //delete
            string deleteName;
            cout<<"Enter name"<<endl;
            cin>>deleteName;
            p.deleteContact(deleteName);
            
        }else if(command=='r' or command =='R'){
            //display by relation.
            string relation;
            cout<<"Enter relation "<<endl;
            cin>>relation;
            
            p.displayByRelation(relation);
            
        }else if(command=='q' or command =='Q'){
            
            
            people->DeleteChildren(); // deletes the existing xml file.
            
            for(int i=0; i<p.getActualPhonebook().size();i++){  // extracts all the contacts from the phonebook array and stores in the xml file.
                list<Contact> listIndex = p.getActualPhonebook()[i];
                
                if(listIndex.size()>0){
                    
                    list<Contact>:: iterator it = listIndex.begin();
                    for (it;it!=listIndex.end();it++){
                        
                        XMLElement *element=doc.NewElement("contact");
                        element->SetAttribute("name",it->getName().c_str());
                        element->SetAttribute("email",it->getEmail().c_str());
                        element->SetAttribute("relation",it->getRelation().c_str());
                        element->SetAttribute("phoneNumber",it->getPhoneNumber().c_str());
                        people->InsertEndChild((element));
                    }
                }
            }
            doc.SaveFile("contact.xml");
            break;
        }else{
            cout<<"Enter a valid command."<<endl;
        }
    }while(command!='q' or command!='Q');
};

