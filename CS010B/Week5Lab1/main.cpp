#include <iostream>
#include <fstream>

using namespace std; 


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize){
   int i = 0;
   double avgNum = 0.0;
   int zeroCount = 0;
   for (i = 0; i < arraySize; ++i){
      avgNum += array[i];
      //if (array[i] == 0){
      //   zeroCount += 1;
      //}
   }
   arraySize -= zeroCount;
   avgNum /= arraySize;
   return avgNum;
}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index){
   int i = 0;
   for (i = index; i < (arraySize-1); ++i){
      array[i] = array[i+1];
   }
   arraySize -= 1; 
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize){
   int i = 0; 
   for (i = 0; i < (arraySize-1); ++i){
      cout << array[i] << ", ";
   }
   cout << array[i]; 
}

const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   ifstream inFS;
   double currNum = 0.0;
   int nonConstSize = 0;  
   double anArray[ARR_CAP];
   unsigned int i = 0;
   // verify file name provided on command line
   if (argc != 2){
      cout << "Two files needed." << endl;
      return 1; 
   }
   
   // open file and verify it opened
   inFS.open(argv[1]);
   if (!inFS.is_open()){
      return 1; 
   }

   // Declare an array of doubles of size ARR_CAP (AT TOP).

   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   while (inFS >> currNum){
      anArray[i] = currNum; 
      ++i;
      ++nonConstSize;
   }

   while (i < ARR_CAP){
      anArray[i] = 0;
      ++i;
   }

   // Call the mean function passing it this array and output the 
   // value returned.

   cout << "Mean: " << mean(anArray, nonConstSize) << endl << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.

   cout << "Enter index of value to be removed (0 to " << (nonConstSize - 1) << ") : ";
   cin >> i; 
   cout << endl; 
	
   // Call the display function to output the array.

   cout << "Before removing value: ";
   display(anArray, nonConstSize);
   cout << endl << endl;
   
   // Call the remove function to remove the value at the index
   // provided by the user.

   remove(anArray, nonConstSize, i);
    
   // Call the display function again to output the array
   // with the value removed.

   cout << "After removing value: ";
   display(anArray, nonConstSize);
   cout << endl << endl;
   
   // Call the mean function again to get the new mean

   cout << "Mean: " << mean(anArray, nonConstSize) << endl;

	return 0;
}