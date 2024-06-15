#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum (string filename);

int main() {
   string filename;
   int sum;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;

   sum = fileSum(filename);

    if (sum == 1){
        return 1;
    }

   cout << "Sum: " << sum << endl;

   return 0;
}

int fileSum (string filename){
    
    ifstream inFS;

    inFS.open(filename); 

   if (!inFS.is_open()){
      cout << "Error opening " << filename << endl;
      return 1;
   }

   int numSum = 0; 
   int currNum = 0; 
   while (inFS >> currNum){
      numSum += currNum; 
   }
   inFS.close(); 
   return numSum;

}
