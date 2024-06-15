#include <iostream>
using namespace std; 

#include "ItemToPurchase.h" 

ItemToPurchase::ItemToPurchase(){
    _description = "none"; 
    _name = "none"; 
    _price = 0; 
    _quantity = 0; 
}

ItemToPurchase::ItemToPurchase(string inputName, string inputDesc, int inputPrice, int inputQuantity){
    _description = inputDesc;
    _name = inputName;
    _price = inputPrice; 
    _quantity = inputQuantity; 
}

void ItemToPurchase::setName(string inputName){
    _name = inputName; 
}

string ItemToPurchase::name() const{
    return _name; 
}

void ItemToPurchase::setPrice(int inputPrice){
    _price = inputPrice; 
}

int ItemToPurchase::price() const{
    return _price; 
}

void ItemToPurchase::setQuantity(int inputQuantity){
    _quantity = inputQuantity;
}

int ItemToPurchase::quantity() const{
    return _quantity;
}

void ItemToPurchase::setDescription(string inputDesc){
    _description = inputDesc; 
}

string ItemToPurchase::description() const{
    return _description; 
}

void ItemToPurchase::printItemCost() const{
    int itemSubtotal = 0;

    itemSubtotal = (_quantity * _price);
    cout << _name << " " << _quantity << " @ $" << _price << " = $" << itemSubtotal << endl;    
} 

void ItemToPurchase::printItemDescription() const{
    cout << _name << ": " << _description << endl; 
}
