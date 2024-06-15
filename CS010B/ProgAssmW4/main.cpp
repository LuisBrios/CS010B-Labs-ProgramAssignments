#include <iostream>
using namespace std; 

#include "ShoppingCart.h" 

void printMenu(ShoppingCart& randomObj){
    cout << "MENU" << endl; 
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl; 
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option: " << endl; 
}

int main() {
    ShoppingCart storeObj;
    ItemToPurchase itemObj; 
    string nameOfCustomer = "";
    string currentDate = "";
    char userChoice = 'p'; 
    string itemName;
    string itemDesc;
    int itemPricing = 0;
    int itemAmnt = 0; 

    cout << "Enter customer's name: " << endl;
    getline(cin, nameOfCustomer);
    cout << "Enter today's date: " << endl << endl;
    getline(cin, currentDate);
    storeObj = ShoppingCart(nameOfCustomer, currentDate); 

    cout << "Customer name: " << storeObj.customerName() << endl;
    cout << "Today's date: " << storeObj.date() << endl << endl; 

    printMenu(storeObj);
    while (userChoice != 'q'){
        cin >> userChoice; 
        if (userChoice != 'q' and userChoice != 'a' and userChoice != 'd' and userChoice != 'c' and userChoice != 'i' and userChoice != 'o'){
            cout << "Choose an option: " << endl; 
        }
        if (userChoice == 'o'){
            storeObj.printTotal(); 
            printMenu(storeObj); 
        }
        else if (userChoice == 'i'){
            storeObj.printDescriptions();
            printMenu(storeObj); 
        }
        else if (userChoice == 'a'){
            cout << endl << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name: " << endl;
            cin.ignore();
            getline(cin, itemName);  
            cout << "Enter the item description: " << endl;
            getline(cin, itemDesc);
            cout << "Enter the item price: " << endl;
            cin >> itemPricing;
            cout << "Enter the item quantity: " << endl << endl;
            cin >> itemAmnt;
            itemObj = ItemToPurchase(itemName, itemDesc, itemPricing, itemAmnt);
            storeObj.addItem(itemObj);
            printMenu(storeObj); 
        }
        else if (userChoice == 'd'){
            cout << endl << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: " << endl;
            cin.ignore(); 
            getline(cin, itemName);
            storeObj.removeItem(itemName);
            printMenu(storeObj); 
        }
        else if (userChoice == 'c'){
            cout << endl << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name: " << endl;
            cin.ignore();
            getline(cin, itemName);
            cout << "Enter the new quantity: " << endl; 
            itemObj = ItemToPurchase(itemName, itemName, 3, 0);
            storeObj.modifyItem(itemObj);
            printMenu(storeObj);
        }
    }


    return 0; 
}