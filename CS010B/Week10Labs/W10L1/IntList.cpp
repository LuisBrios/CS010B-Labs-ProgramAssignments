#include "IntList.h"
#include <iostream>

bool IntList::bubbleUp() {
    return(bubbleUp(head));
}

bool IntList::bubbleUp(IntNode *curr) {    
    bool swappedOrNot;
    if (curr == nullptr || curr->next == nullptr){
        return false; 
    }

    swappedOrNot = bubbleUp(curr->next);

    if (curr->value > curr->next->value){
        swap(curr->value, curr->next->value);
        return true;
    }

    return swappedOrNot;
}
