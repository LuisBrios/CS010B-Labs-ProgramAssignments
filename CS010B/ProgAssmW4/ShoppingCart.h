#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include <vector>
using namespace std; 

#include "ItemToPurchase.h"

class ShoppingCart{
    public:
        ShoppingCart();
        ShoppingCart(string usersName, string usersCurrDate);
        string customerName() const;
        string date() const;
        void addItem(ItemToPurchase& insertedItem);
        void removeItem(string removedItem);
        void modifyItem(ItemToPurchase modifiableItem);
        int numItemsInCart() const;
        int costOfCart() const;
        void printTotal() const;
        void printDescriptions() const; 
    private:
        string _customerName;
        string _currentDate; 
        vector<ItemToPurchase> _cartItems;
};

#endif