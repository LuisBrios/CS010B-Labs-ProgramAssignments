#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList(){
    head = nullptr; 
    tail = nullptr; 
}

//Prof ex
IntList::~IntList(){
    for (IntNode* n = head; n != nullptr;){
       IntNode* nextOne = n -> next;
       delete n; 
       n = nextOne;  
    }
}

void IntList::push_front(int value){
    IntNode *n = new IntNode(value); 
    n->next = head;
    head = n;  

    if (tail == nullptr){
        tail = n; 
    }
}

void IntList::pop_front(){
    
    if (empty() == false){
        IntNode *n = new IntNode(head->value);
        n->next = head; 
        head = n->next->next; 
        delete n;
    }

    if (empty()){
        tail = nullptr;
    }
}

bool IntList::empty() const{
    if (head == nullptr){
        return true; 
    }
    else {
        return false; 
    }
}

const int& IntList::front() const{
    return head->value; 
}

const int& IntList::back() const{
    return tail->value; 
}

ostream& operator<<(ostream& out, const IntList& intNodes){
    IntNode* currNode = intNodes.head; 
    
    if (currNode != nullptr){
        out << currNode -> value; 
        for (currNode = intNodes.head->next; currNode != nullptr; currNode = currNode->next){
            out << " " << currNode->value;
        }
    }
    return out;
}

IntList::IntList(const IntList& cpy){
    head = nullptr;
    tail = nullptr; 

    for (const IntNode* p = cpy.head; p != nullptr; p = p->next){
        push_back(p->value);
    }
}

IntList& IntList::operator=(const IntList &rhs){
    if (this != &rhs){
        clear();
        for (const IntNode* p = rhs.head; p != nullptr; p = p->next){
            push_back(p->value);
        }
    }
    return *this; 
}

void IntList::push_back(int value){
    IntNode* newNode = new IntNode(value);
    if (empty() == false){
        tail->next = newNode;
        tail = newNode; 
    }
    else {
        head = newNode;
        tail = newNode; 
    }
}

void IntList::clear(){
    while (head != nullptr){
        pop_front(); 
    }
}

void IntList::selection_sort(){
    IntNode* currNode = head; 
    IntNode* compareNode = head; 
    int tempVal; 
    
    while (currNode != nullptr){
        while (compareNode != nullptr){
            if (currNode->value > compareNode->value){
                tempVal = currNode->value; 
                currNode->value = compareNode->value;
                compareNode->value = tempVal;
            }
            compareNode = compareNode->next; 
        }
        compareNode = currNode->next;
        currNode = currNode->next; 
    }
}

void IntList::insert_ordered(int value){
    if (head == nullptr || value <= head->value){
        push_front(value); 
    }
    else if (value >= tail->value){
        push_back(value); 
    }
    else{
        IntNode* newNode = new IntNode(value); 
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

void IntList::remove_duplicates(){
    if (head != nullptr){
    IntNode* prevNode = head;
    IntNode* currNode = head->next;
    IntNode* compareNode = head; 
        while(compareNode != nullptr){
            while(currNode != nullptr){
                if (compareNode->value == currNode->value){
                    prevNode->next = currNode->next; 
                    if (currNode->next == nullptr){
                        tail = prevNode; 
                    }
                    delete currNode;
                    currNode = prevNode->next;
                }
                else{
                    prevNode = prevNode->next; 
                    currNode = currNode->next; 
                }
            }

            compareNode = compareNode->next;
            
            if (compareNode == nullptr){
                break; 
            }

            prevNode = compareNode;  
            currNode = compareNode->next;

            if (currNode == nullptr){
                break;
            }
            //cout << "CompareNode: " << compareNode->value << endl; 
            //cout << "PrevNode: " << prevNode->value << endl;
            //cout << "currNode: " << currNode->value << endl << endl;
        } 
    }
}

IntNode* IntList::min(IntNode* ){
    return nullptr; 
}

void IntList::copy(const IntList& cpy){    
}