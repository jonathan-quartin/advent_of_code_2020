#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <string> 
#include <map>
#include<numeric>
#include <regex>

using namespace std;



int main(){
    std::map<long int, long int > locs;
    std::vector<long int> ord_vals;
    string line;
    long int counter = 0;
    ifstream myReadFile;
    myReadFile.open("day15.txt");
    std::getline(myReadFile, line);
    myReadFile.close();
    stringstream s_stream(line); //create string stream from the string
    while(s_stream.good()) {
        string substr;
        getline(s_stream, substr, ','); //get first string delimited by comma
        long int instance = std::stol(substr);
        ord_vals.push_back(instance);
        counter++;       
    }
    
    for (long int x=1; x<ord_vals.size(); x++) {
        locs[ord_vals[x-1]] = x;
    }

    while (counter < 30000000) {
        long int a = ord_vals[counter-1];
        if (locs.count(a) == 0) {
            ord_vals.push_back(0);
            locs[a] = counter;
        }
        else {
            int diff = counter - locs[a]; 
            ord_vals.push_back(diff); 
            locs[a] = counter;          
        }
        counter++;
    }
    cout << ord_vals[ord_vals.size()-1];
   
}

