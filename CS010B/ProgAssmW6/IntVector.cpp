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

int& IntVector::at(unsigned index){
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

int& IntVector::front(){
    return _data[0];
}

const int& IntVector::back() const{
    return _data[_size - 1];
}

int& IntVector::back(){
    return _data[_size - 1];
}

void IntVector::expand(){
    unsigned int i;
    int* _otherArray;
    if (_capacity == 0){
        _capacity = 1;
        _data = new int[_capacity];
        for (i = 0; i < _capacity; ++i){
            _data[i] = 0;
        }
    } 
    else {
        _capacity *= 2;
        _otherArray = new int[_capacity];
        for (i = 0; i < _capacity; ++i){
            _otherArray[i] = 0;
        }
        //Maybe change to _capacity/2
        for (i = 0; i < _size; ++i){
            _otherArray[i] = _data[i];
        }
        delete[] _data;
        _data = new int[_capacity];
        _data = _otherArray;
    }
}

void IntVector::expand(unsigned amount){
    unsigned int i;
    int* _otherArray;

    _capacity += amount;
    _otherArray = new int[_capacity];
    for (i = 0; i < _capacity; ++i){
        _otherArray[i] = 0;
    }
        //Maybe change to _capacity/2
    for (i = 0; i < _size; ++i){
        _otherArray[i] = _data[i];
    }
    delete[] _data;
    _data = new int[_capacity];
    _data = _otherArray;
}

void IntVector::insert(unsigned index, int value){
    unsigned int i;

    if((_size + 1) > _capacity){
        expand(); 
    }
    _size += 1;

    if (index >= _size){
        throw out_of_range("IntVector::insert_range_check");
    }

    for (i = (_size-1); i > index; --i){
        _data[i] = _data[i-1];
    }
    _data[index] = value; 
}

void IntVector::erase(unsigned index){
    unsigned int i;

    if (index >= _size){
        throw out_of_range("IntVector::erase_range_check");
    }

    for (i = index; i < _size; ++i){
        _data[i] = _data[i+1];
    }
    _size -= 1; 
}

void IntVector::assign(unsigned n, int value){
    unsigned int i; 

    if(n > _capacity){
        if (n > (_capacity * 2)){
            expand(n-_capacity);
        }
        else {
            expand(); 
        }
    }

    _size = n; 
    for (i = 0; i < _size; ++i){
        _data[i] = value; 
    }
}

void IntVector::reserve(unsigned n){
    if (n > _capacity){
        expand(n-_capacity); 
    }
}

void IntVector::resize(unsigned n, int value /*= 0*/){
    unsigned int i;

    if (n < _size){
        _size = n; 
    }
    else if (n > _size){
        if (n > _capacity){
            if (n > (_capacity * 2)){
                expand (n-_capacity); 
            }
            else {
                expand(); 
            }
        }
        for (i = _size; i < n; ++i){
            _data[i] = value;
            ++_size; 
        }
    }
}

void IntVector::push_back(int value){
    if(_size >= _capacity){
        expand(); 
    } 
    ++_size; 
    _data[_size - 1] = value; 
}

void IntVector::pop_back(){
    --_size; 
}

void IntVector::clear(){
    _size = 0;    
}