#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s){
    string scndString = s;
    if(scndString.size() > 1){
        swap(s.at(0), s.at(s.size()-1));
        scndString = s.substr(1, s.size()-2); 
        flipString(scndString);
        s = s.at(0) + scndString + s.at(s.size()-1);
    }
}

