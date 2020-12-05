#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <string> 
#include<numeric>
#include <regex>

using namespace std;

struct policy {
  int low;
  int high;
  char digit;
  string password;
}; 

///// Function for PART 1 /////

int counter(string pw, char d) {
    int k = 0;
    for (int x=0; x < pw.size(); x++) {
        if (pw.at(x) == d) {
            k++;
        };
    }
    return k;
}


int main(){
    std::vector<policy> policies;
    std::regex rgx("([0-9]+)-([0-9]+) ([a-z]): ([a-z]+)");
    std::smatch matches;
    string line;
    ifstream myReadFile;
    myReadFile.open("day2.txt");
    if(myReadFile.is_open()){
        while (std::getline(myReadFile, line)){
            if(std::regex_search(line, matches, rgx)) {
                policy p = {std::stoi(matches.str(1)), std::stoi(matches.str(2)), matches.str(3)[0], matches.str(4)};
                policies.push_back(p);
            }


        }

        myReadFile.close();
    } 

    int valids = 0;

    ///// PART 1 /////

    /*
    for (int x=0; x < policies.size(); x++) {
        int c = counter(policies.at(x).password, policies.at(x).digit);
        if (policies.at(x).low <= c && c <= policies.at(x).high) {
            valids++;
        };
    } 
    */

    
    ///// PART 2 /////

    for (int x=0; x < policies.size(); x++) {
        char b = policies.at(x).digit;
        char c = policies.at(x).password[policies.at(x).low-1];
        char d = policies.at(x).password[policies.at(x).high-1];
        if (b == c ^ b == d) {
            valids++;
        }
    }   
    
    cout << valids;    
    
}

