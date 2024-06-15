#include <iostream>
using namespace std; 

#include "SortedSet.h"

SortedSet::SortedSet()
    :IntList(){}

SortedSet::SortedSet(const SortedSet& copySet) 
    :IntList(copySet){}

SortedSet::SortedSet(const IntList& copySet)
    :IntList(copySet){
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet(){
    clear();
}

bool SortedSet::in(int value){

    //cout << "Checking Value: " << value << endl; 

    for (IntNode* currNode = head; currNode != nullptr; currNode = currNode->next){
        if (currNode->value == value){
            //cout << value << " true..." << endl;
            return true;
        }
    }
    //cout << value << " FALSE" << endl;
    return false; 
}

SortedSet SortedSet::operator|(const SortedSet& superSet){
    SortedSet newSet;
    for (IntNode* currNode = this->head; currNode != nullptr; currNode = currNode->next){
        newSet.push_back(currNode->value);
    }
    for (IntNode* currNode = superSet.head; currNode != nullptr; currNode = currNode->next){
        newSet.push_back(currNode->value); 
    }
    return newSet; 
}

SortedSet SortedSet::operator&(const SortedSet& superSet){
    SortedSet newSet;
    for (IntNode* currNode = superSet.head; currNode != nullptr; currNode = currNode->next){
        if (this->in(currNode->value) == true){
            newSet.push_back(currNode->value); 
        } 
    }
    return newSet; 
}

void SortedSet::add(int value){
    if (!in(value)){
        //cout << "SEPARATOR" << endl;
        insert_ordered(value);
    }
}

void SortedSet::push_front(int value){
    add(value);
}

void SortedSet::push_back(int value){
    add(value);
}

void SortedSet::insert_ordered(int value){
    if (!in(value)){
        IntNode* newNode = new IntNode(value);
        if (head == nullptr || value <= head->value){
            newNode->next = head;
            head = newNode; 
            if(head->next == nullptr){
                tail = newNode; 
            }
        }
        else if (value >= tail->value){
            tail->next = newNode; 
            tail = newNode;  
        }
        else{
            IntNode* prevNode = head;
            IntNode* currNode = head->next;

            while(currNode != nullptr){
                if (prevNode->value <= value && value <= currNode->value){
                    newNode->next = currNode;
                    prevNode->next = newNode;
                    break;  
                }
                currNode = currNode->next;
                prevNode = prevNode->next; 
            }
        }
    }
}


SortedSet SortedSet::operator|=(const SortedSet& superSet){
    *this = *this | superSet;
    return *this; 
    
}

SortedSet SortedSet::operator&=(const SortedSet& superSet){
    *this = *this & superSet;
    return *this; 
}