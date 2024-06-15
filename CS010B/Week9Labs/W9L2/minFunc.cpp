#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0){
        return nullptr;
    }
    else if (arrSize == 1){
        return arr; 
    }
    const int* minNum = min(arr+1, arrSize-1); 
    if (*arr < *minNum){
        return (arr);
    }
    else {
        return minNum;
    }
}