#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> //unsure how to actually create an empty list or vector that can be added to.
#include <string> 
#include<numeric>

using namespace std;

int main(){
    std::vector<int> values;
    string line;
    ifstream myReadFile;
    myReadFile.open("day1.txt");
    if(myReadFile.is_open()){
        while (std::getline(myReadFile, line)){
            values.push_back(std::stoi(line));


        }

        myReadFile.close();
    } 
    
    ///// PART 1 /////

    bool done = false;

    for (int x = 0; x < values.size(); x++) {
        for (int y = x + 1; y < values.size(); y++) {
            if (values.at(x) + values.at(y) == 2020) {
                cout << values.at(x) * values.at(y) << endl;
                done = true;
                break;
             
            }
        }
        if (done == true) {
            break;
        }

    }  

    ///// PART 2 /////

    done = false;

    for (int x = 0; x < values.size(); x++) {
        for (int y = x + 1; y < values.size(); y++) {
            for (int z = y + 1; z < values.size(); z++) {
                if (values.at(x) + values.at(y) + values.at(z) == 2020) {
                    cout << values.at(x) * values.at(y) * values.at(z);
                    done = true;
                    break;
             
                    }
                }
            if (done == true) {
                break;
                }
        
            }
        if (done == true) {
            break;
            } 
        }
}