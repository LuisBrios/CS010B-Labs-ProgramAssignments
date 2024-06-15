#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   unsigned int i; 
   string inputFile;
   string outputFile;
   int csvNums; 
   char uselessStuff; 
   int numSum = 0; 
   vector<int> vIO;
   

   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1]; 
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   ifstream inFS; 
   inFS.open(inputFile); 
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if(!inFS.is_open()){
    cout << "error" << endl;
    return 1; 
   }
   // Read in integers from input file to vector.

   while(!inFS.eof()){
      inFS >> csvNums;   
      vIO.push_back(csvNums);
      inFS >> uselessStuff;
   }

   // Close input stream.
   inFS.close(); 
   
   // Get integer average of all values read in.

   for (i = 0; i < vIO.size(); ++i){
      numSum += vIO.at(i);
   }
   numSum /= vIO.size();

   // Convert each value within vector to be the difference between the original value and the average.
   
   for (i = 0; i < vIO.size(); ++i){
      vIO.at(i) -= numSum;
   } 

   // Create output stream and open/create output csv file.

   ofstream oFS; 
   oFS.open(outputFile); 

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   
   if(!oFS.is_open()){
      cout << "error" << endl;
      return 1; 
   }

   // Write converted values into ouptut csv file, each integer separated by a comma.

   for (i = 0; i < vIO.size(); ++i){
      oFS << vIO.at(i);
      if (i != (vIO.size()-1)){
         oFS << ", ";
      }
   }

   // Close output stream.
   oFS.close();

   return 0;
}