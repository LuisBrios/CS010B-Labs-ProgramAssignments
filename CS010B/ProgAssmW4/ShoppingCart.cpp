#include <iostream>
#include <vector>
using namespace std; 

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(){
    _customerName = "none";
    _currentDate = "January 1, 2016"; 
}

ShoppingCart::ShoppingCart(string usersName, string usersCurrDate){
    _customerName = usersName;
    _currentDate = usersCurrDate; 
}

string ShoppingCart::customerName() const{
    return _customerName;
}

string ShoppingCart::date() const{
    return _currentDate; 
}

void ShoppingCart::addItem(ItemToPurchase& insertedItem){    
    _cartItems.push_back(insertedItem);
}

void ShoppingCart::removeItem(string removedItem){
    unsigned int i;
    bool isInCart = false; 

    for (i = 0; (i < _cartItems.size() && isInCart == false); ++i){
        if (_cartItems.at(i).name() == removedItem){
            _cartItems.erase(_cartItems.begin() + i);
            isInCart = true; 
        } 
    }

    if (isInCart == false){
        cout << "Item not found in cart. Nothing removed." << endl << endl; 
    }
    else {
        cout << endl; 
    }
}

void ShoppingCart::modifyItem(ItemToPurchase modifiableItem){
    unsigned int i = 0;
    bool isInCart = false; 
    string modifyDesc; 
    string modifyName;
    int modifyPrice;
    int modifyQuantity; 
    int scrapData;
    
    for (i = 0; (i < _cartItems.size() && isInCart == false); ++i){
        if (_cartItems.at(i).name() == modifiableItem.name()){
            isInCart = true; 
        } 
    }

    if (isInCart == true){
        if (modifiableItem.description() == "none"){
            cin.ignore(); 
            cin >> modifyDesc;
            _cartItems.at(i-1).setDescription(modifyDesc);
        }
        if (modifiableItem.name() == "none"){
            cin.ignore();
            cin >> modifyName;
            _cartItems.at(i-1).setName(modifyName); 
        }
        if (modifiableItem.price() == 0){
            cin.ignore();
            cin >> modifyPrice; 
            _cartItems.at(i-1).setPrice(modifyPrice);
        }
        if (modifiableItem.quantity() == 0){
            cin >> modifyQuantity;
            _cartItems.at(i-1).setQuantity(modifyQuantity);
            cout << endl; 
        }
    }
    else {
        cin >> scrapData; 
        cout << "Item not found in cart. Nothing modified." << endl << endl;
    }
}

int ShoppingCart::numItemsInCart() const{
    unsigned int i;
    int sumQuantity = 0;
    for (i = 0; i < _cartItems.size(); ++i){
        sumQuantity += _cartItems.at(i).quantity(); 
    } 
    return sumQuantity; 
}

int ShoppingCart::costOfCart() const{
    unsigned int i;
    int priceOfItems = 0;
    for (i = 0; i < _cartItems.size(); ++i){
        priceOfItems += (_cartItems.at(i).price() * _cartItems.at(i).quantity()); 
    } 
    return priceOfItems; 
}
        
void ShoppingCart::printTotal() const{
    unsigned int i;
    unsigned int sizeOfCart;
    int totalPrice = 0;
    int numQuantity;

    numQuantity = numItemsInCart(); 
    sizeOfCart = (_cartItems.size());
    cout << endl << "OUTPUT SHOPPING CART" << endl;
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numQuantity << endl << endl; 

    if (sizeOfCart == 0){
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else {
        for (i = 0; i < sizeOfCart; ++i){
        cout << _cartItems.at(i).name() << " ";
        cout << _cartItems.at(i).quantity() << " @ $";
        cout << _cartItems.at(i).price() << " = $";
        cout << (_cartItems.at(i).quantity() * _cartItems.at(i).price()) << endl;
        }
    }
    totalPrice = costOfCart(); 
    cout << endl << "Total: $" << totalPrice << endl << endl; 
}

void ShoppingCart::printDescriptions() const{
    unsigned int i; 

    cout << endl << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl << endl; 
    cout << "Item Descriptions" << endl; 

    for (i = 0; i < _cartItems.size(); ++i){
        cout << _cartItems.at(i).name() << ": ";
        cout << _cartItems.at(i).description() << endl;
    }
    
    cout << endl; 
} 