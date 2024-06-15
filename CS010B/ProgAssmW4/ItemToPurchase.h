#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <iostream>
using namespace std; 

class ItemToPurchase{
    public:
        ItemToPurchase();
        ItemToPurchase(string inputName, string inputDesc, int inputPrice, int inputQuantity);
        void setName(string inputName);
        string name() const;
        void setPrice(int inputPrice);
        int price() const;
        void setQuantity(int inputQuantity);
        int quantity() const; 
        void setDescription(string inputDesc);
        string description() const; 
        void printItemCost() const; 
        void printItemDescription() const; 
    private:
        string _description;
        string _name;
        int _price;
        int _quantity; 
};

#endif