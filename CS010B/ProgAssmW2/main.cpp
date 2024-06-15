#include <fstream>
#include <iostream> 
#include <string>
#include <vector> 
#include <cstdlib>
using namespace std;

void readData(const string& fileName, vector<double>& vFA, vector<double>& vCLA);
double interpolation(double userFA, const vector<double>& vFA, const vector<double>& vCLA);
bool isOrdered(const vector<double>& vFA);
void reorder(vector<double>& vFA, vector<double>& vCLA);

int main(int argc, char* argv[]){
    string windTunnelFile = "";
    vector<double> vFlightAngle(0);
    vector<double> vCoLiftAngle(0); 
    double userFlightAngle = 0;
    string contOption = ""; 

    if (argc != 2){
        cout << endl << "Usage: myprog.exe inputFileName" << endl; 
        return 1; 
    }

    windTunnelFile = argv[1];

    readData(windTunnelFile, vFlightAngle, vCoLiftAngle);
    reorder(vFlightAngle, vCoLiftAngle);

    while (contOption != "No" && contOption != "no"){
        cout << "Please enter a flight-path angle: " << endl; 
        cin >> userFlightAngle; 

        cout << "Interpolated Num: " << interpolation(userFlightAngle, vFlightAngle, vCoLiftAngle) << endl;

        cout << "Would you like to calculate another angle? (Yes/No)" << endl;
        cin >> contOption; 

    }

    return 0;
}

void readData(const string& fileName, vector<double>& vFA, vector<double>& vCLA){
    ifstream inFS;
    double currNum = 0; 
    double currNum2 = 0; 

    inFS.open(fileName);

    if(!inFS.is_open()){
        cout << "Error opening " << fileName <<  endl;
        exit(1);
    }

    while (inFS >> currNum){
        vFA.push_back(currNum);
        inFS >> currNum2; 
        vCLA.push_back(currNum2);
    }

    //vFA.pop_back();
    //vCLA.pop_back();

    inFS.close();
}

void reorder(vector<double>& vFA, vector<double>& vCLA){
    unsigned int i;
    double varSwitch;

    for (i = 1; i < vFA.size(); ++i){
        if (vFA.at(i-1) > vFA.at(i)){
            varSwitch = vFA.at(i-1);
            vFA.at(i-1) = vFA.at(i);
            vFA.at(i) = varSwitch; 

            varSwitch = vCLA.at(i-1);
            vCLA.at(i-1) = vCLA.at(i);
            vCLA.at(i) = varSwitch;
            i = 0; 
        }
    }
}

bool isOrdered(const vector<double>& vFA){
    unsigned int i = 0;

    for (i = 1; i < vFA.size(); ++i){
        if (vFA.at(i-1) > vFA.at(i)){
            return false;
        }
    }
    return true; 
}

double interpolation(double userFA, const vector<double>& vFA, const vector<double>& vCLA){
    double interpolatedNum = 0;
    double prevNumIndx;
    double nextNumIndx;
    unsigned int i;

    for (i = 0; i < vFA.size(); ++i){
        if (userFA == vFA.at(i)){
            return vCLA.at(i); 
        }
    }

    for (i = 1; i < (vFA.size()); ++i){
        if ((userFA < vFA.at(i))){
            prevNumIndx = (i-1);
            nextNumIndx = (i);
            break;
        }
    }

    cout << prevNumIndx << endl;
    cout << nextNumIndx << endl;

    interpolatedNum = vCLA.at(prevNumIndx) + ((userFA - vFA.at(prevNumIndx))/(vFA.at(nextNumIndx)-vFA.at(prevNumIndx)))*(vCLA.at(nextNumIndx) - vCLA.at(prevNumIndx));
    return interpolatedNum; 

}

