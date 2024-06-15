#include <iostream>
#include <fstream>
using namespace std;

bool rCopy(const string& inpFile, const string& outFile);
bool rCopyHelper(const string& inpFile, const string& outFile, ostream& oFS, istream& inFS);


int main(int argc, char* argv[]){    
    string inputFile;
    string outputFile; 

    if (argc != 3){
        cout << endl << "Usage: myprog.exe inputFileName outputFileName" << endl; 
        return 1; 
    }

    inputFile = argv[1];
    outputFile = argv[2];

    rCopy(inputFile, outputFile); 

}

bool rCopy(const string& inpFile, const string& outFile){
    ifstream inFS;
    ofstream oFS; 

    inFS.open(inpFile); 
    if (!inFS.is_open()){
        cout << "Error opening " << inpFile << endl;
        cout << "Copy not completed" << endl;
        return false;
    }

    oFS.open(outFile);
    if(!oFS.is_open()){
        cout << "Error opening " << outFile << endl;
        cout << "Copy not completed" << endl;
        return false; 
    }

    rCopyHelper(inpFile, outFile, oFS, inFS);

    oFS.close();
    inFS.close();

    return true;
}

bool rCopyHelper(const string& inpFile, const string& outFile, ostream& oFS, istream& inFS){
    char ch = 'z';
    if (inFS.eof()){
        return true;
    }

    inFS.get(ch);
    if (rCopyHelper(inpFile, outFile, oFS, inFS) != true){
        oFS << ch; 
    }
    return false; 
}



