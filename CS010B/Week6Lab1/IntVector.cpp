#include <iostream>
#include <stdexcept>
using namespace std;

#include "IntVector.h"

IntVector::IntVector(unsigned capacity /*= 0*/, int value /*= 0*/){
    unsigned i; 
    _capacity = capacity;
    _size = capacity;
    _data = nullptr; 
    if (_capacity != 0){
        _data = new int[_capacity];
        for (i = 0; i < _capacity; ++i){
            _data[i] = value;
        }
    }
}

IntVector::~IntVector(){
    delete[] _data;
    _data = nullptr;  
}

unsigned IntVector::size() const{
    return _size; 
}

unsigned IntVector::capacity() const{
    return _capacity; 
}

bool IntVector::empty() const{
    if (_size == 0){
        return true;
    }
    else {
        return false; 
    }
}

const int& IntVector::at(unsigned index) const{
    if (index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}

const int& IntVector::front() const{
    return _data[0];
}

const int& IntVector::back() const{
    return _data[_size - 1];
}