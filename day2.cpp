#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> //unsure how to actually create an empty list or vector that can be added to.
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

    for (int x=0; x < policies.size(); x++) {
        int c = counter(policies.at(x).password, policies.at(x).digit);
        if (policies.at(x).low <= c && c <= policies.at(x).high) {
            valids++;
        };
    }
    
    cout << valids;    
    
}

