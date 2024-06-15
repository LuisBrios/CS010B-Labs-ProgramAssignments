#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &out, const IntList &nodeList){
   IntNode *currNode =nodeList.head;
   out << currNode;
   return out;
}

ostream & operator<<(ostream &out, IntNode *currNode){
   if (currNode == nullptr){
      return out;
   }
   if (currNode->next == nullptr){
      out << currNode->value;
      return out;
   }
   else {
      out << currNode->value << " ";
      currNode = currNode->next;
      operator << (out, currNode);
      return out;
   }
}

bool IntList::exists(int value) const{
   IntNode *currNode = head;
   if (exists(currNode, value)){
      return true;
   }
   else {
      return false;
   }
}

bool IntList::exists(IntNode *currNode, int value) const{
   if (currNode == nullptr){
      return false;
   }
   if (currNode->value == value){
      return true;
   }
   currNode = currNode->next;
   if (exists(currNode, value)){
      return true;
   }
   else {
      return false; 
   }
}