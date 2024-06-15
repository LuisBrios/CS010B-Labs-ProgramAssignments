#include "SortedSet.h"

#include <iostream>
using namespace std;

int main() {

   IntList list1; 

   cout << "List Created" << endl;

   SortedSet set1;

   cout << "Set1 Created" << endl;

   list1.push_back(3);
   list1.push_back(4); 
   list1.push_back(5); 

   cout << "Values 3-5 pushed into list." << endl;

   cout << "List 1: " << list1 << endl; 

   set1.push_back(0);
   set1.push_back(1);
   set1.push_back(3);
   set1.push_back(2);  

   cout << "Values 0-3 pushed (back) into set1." << endl;
   cout << "Set1: " << set1 << endl;

   SortedSet set2;

   cout << "Set2 Created" << endl;

   set2.push_front(5);
   set2.push_front(4);
   set2.push_front(6);

   cout << "Values 4-6 pushed (front) into set2." << endl;
   cout << "Set2: " << set2 << endl << endl; 

   //In test; might seem arbitrary, as push_front/back requires it.
   if (set1.in(2) == true){
      cout << "2 is inside set1." << endl;
   }
   else {
      cout << "2 isn't inside set1." << endl;
   }

   if (set2.in(7) == true){
      cout << "7 is inside set2." << endl;
   }
   else {
      cout << "7 isn't inside set2." << endl;
   }

   if (set1.in(0) == true){
      cout << "0 is inside set1." << endl;
   }
   else {
      cout << "0 isn't inside set1." << endl;
   }
   cout << endl; 

   //Add test. Also might seem arbitrary.
   
   //Should NOT work, as 6 is already in set2.
   set2.add(6);
   cout << "Set 2: " << set2 << endl; 
   set2.add(7);
   set2.add(8);
   cout << "Set 2: " << set2 << endl;
   cout << "Set 1 (For Next Test): " << set1 << endl << endl;

   cout <<"Super Set (Union | Operator)" << endl;
   SortedSet set3;
   set3 = set2 | set1; 
   cout << "Super Set 3: " << set3 << endl << endl; 

   cout << "Super Set (Union & Operator)" << endl;
   SortedSet NS1;
   SortedSet NS2;
   SortedSet NS3;

   NS1.push_back(2);
   NS1.push_back(3);
   NS1.push_back(4);
   NS1.push_back(7);
   NS1.push_back(8);

   NS2.push_back(2);
   NS2.push_back(3);
   NS2.push_back(5);
   NS2.push_back(7);
   NS2.push_back(8);
   NS2.push_back(10); 

   NS3 = NS2 & NS1;
   cout << "NS1 Data: " << NS1 << endl;
   cout << "NS2 Data: " << NS2 << endl;
   cout << "NS3 Data: " << NS3 << endl << endl;

   cout << "Super Set (Union |= Operator)" << endl;
   cout << "Using NS1 and NS2..." << endl;
   NS1 |= NS2;
   cout << "New NS1: " << NS1 << endl << endl; 

   cout << "Super Set (Union &= Operator)" << endl;
   cout << "Using NS1 and NS2..." << endl;
   NS2.push_front(50); 
   NS2.push_front(1); 
   cout << NS1 << endl << NS2 << endl; 
   NS1 &= NS2;
   cout << "New NS1: " << NS1 << endl << endl; 

   return 0;
}
