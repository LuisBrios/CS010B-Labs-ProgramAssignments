#include <iostream>
using namespace std; 

#include "IntVector.h"

int main (){
    IntVector testArr1;
    IntVector testArr2(5);
    IntVector testArr3(10, 3); 

    cout << "RESERVE TEST" << endl;

    cout << "ARR3 Size: " << testArr3.size() << endl << "Current Capacity: " << testArr3.capacity() << endl;
    testArr3.reserve(50); 
    cout << "ARR3 Size: " << testArr3.size() << endl << "Reserved: " << testArr3.capacity() << endl;

    cout << endl;

    cout << "ARR2 Size: " << testArr2.size() << endl << "Current Capacity: " << testArr2.capacity() << endl;
    testArr2.reserve(10);
    cout << "ARR2 Size: " << testArr2.size() << endl << "Reserved: " << testArr2.capacity() << endl;

    cout << endl;

    cout << "ARR1 Size: " << testArr1.size() << endl << "Current Capacity: " << testArr1.capacity() << endl;
    testArr1.reserve(5); 
    cout << "ARR1 Size: " << testArr1.size() << endl << "Reserved: " << testArr1.capacity() << endl;

    cout << endl << endl;

    cout << "RESIZE TEST" << endl;

    cout << "ARR3 Size: " << testArr3.size() << endl << "Current Capacity: " << testArr3.capacity() << endl;
    testArr3.resize(51, 3); 
    cout << "ARR3 Size: " << testArr3.size() << endl << "Reserved: " << testArr3.capacity() << endl;
    cout << "Extra Value: " << testArr3.at(50) << endl;

    cout << endl;

    cout << "ARR2 Size: " << testArr2.size() << endl << "Current Capacity: " << testArr2.capacity() << endl;
    testArr2.resize(10);
    cout << "ARR2 Size: " << testArr2.size() << endl << "Reserved: " << testArr2.capacity() << endl;

    cout << endl;

    cout << "ARR1 Size: " << testArr1.size() << endl << "Current Capacity: " << testArr1.capacity() << endl;
    testArr1.resize(2, 10); 
    cout << "ARR1 Size: " << testArr1.size() << endl << "Reserved: " << testArr1.capacity() << endl;
    cout << "Front Value: " << testArr1.front() << endl; 

    cout << endl << endl;

    cout << "CLEAR TEST" << endl;

    cout << "ARR2 Size: " << testArr2.size() << endl << "Capacity: " << testArr2.capacity() << endl;
    testArr2.clear();
    cout << "ARR2 Size: " << testArr2.size() << endl << "Capacity: " << testArr2.capacity() << endl;

    cout << endl << endl;

    cout << "EMPTY TEST" << endl;
    cout << testArr1.empty() << endl;
    cout << testArr2.empty() << endl;
    cout << testArr3.empty() << endl;

    cout << endl << endl; 

    cout << "AT, FRONT, & INSERT TEST" << endl;
    testArr1.insert(0, 50);
    cout << "(TA1 Front: " << testArr1.front() << endl;
    cout << "At 0: " << testArr1.at(0) << endl;

    cout << endl;

    testArr2.insert(0, 3);
    cout << "TA2 Empty? " << testArr2.empty() << endl;
    cout << "Back: " <<  testArr2.back() << endl; 

    cout << endl; 

    cout << "Pushbacking: " << endl;
    testArr1.push_back(31);
    testArr2.push_back(32); 
    testArr3.push_back(33);

    cout << "Info of Objects: " << endl;
    cout << testArr1.back() << endl;
    cout << testArr2.back() << endl;
    cout << testArr3.back() << endl;

    cout << endl;

    cout << "Popbacking: " << endl;
    testArr1.pop_back();
    testArr2.pop_back(); 
    testArr3.pop_back();

    cout << "Info of Objects: " << endl;
    cout << testArr1.back() << endl;
    cout << testArr2.back() << endl;
    cout << testArr3.back() << endl;

    cout << endl;

    cout << "ASSIGNING: " << endl; 

    testArr3.assign(123, 21);
    cout << "Capacity: " << testArr3.capacity() << endl;
    cout << "Size: " << testArr3.size() << endl;
    cout << "Front: " << testArr3.front() << endl; 

    cout << endl;

    cout << "New Front: Number 30" << endl; 
    testArr3.insert(0, 30);
    cout << "Front: " << testArr3.front() << endl;
    cout << "Size: " << testArr3.size() << endl; 
    cout << "Erasing Index 0: " << endl;

    cout << endl; 

    testArr3.erase(0);
    cout << "Front: " << testArr3.front() << endl;
    cout << "Size: " << testArr3.size() << endl; 
    cout << endl; 

}