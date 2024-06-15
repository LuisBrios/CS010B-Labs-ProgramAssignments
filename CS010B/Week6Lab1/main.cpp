#include <iostream>
using namespace std; 

#include "IntVector.h"

int main (){
    IntVector testArr1;
    IntVector testArr2(7);
    IntVector testArr3(10, 4); 

    cout << "SIZE TEST" << endl;
    cout << testArr1.size() << endl; 
    cout << testArr2.size() << endl;
    cout << testArr3.size() << endl; 

    cout << endl;

    cout << "CAPACITY TEST" << endl;
    cout << testArr1.capacity() << endl;
    cout << testArr2.capacity() << endl;
    cout << testArr3.capacity() << endl;

    cout << endl;

    cout << "EMPTY TEST" << endl;
    cout << testArr1.empty() << endl;
    cout << testArr2.empty() << endl;
    cout << testArr3.empty() << endl;

    cout << endl; 

    cout << "FRONT TEST" << endl;
    //segmentation error; attempts to access NULLPTR dereferenced. 
    //cout << testArr1.front() << endl;
    cout << testArr2.front() << endl;
    cout << testArr3.front() << endl;

    cout << endl;

    cout << "BACK TEST" << endl;
    //segmentation error; attempts to access NULLPTR dereferenced. 
    //cout << testArr1.back() << endl;
    cout << testArr2.back() << endl;
    cout << testArr3.back() << endl;

    cout << "AT TEST" << endl;
    cout << testArr3.at(10) << endl;

}