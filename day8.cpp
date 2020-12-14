#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <string> 
#include<numeric>
#include <regex>

using namespace std;

struct instruct {
    string command;
    int value;
    bool exec;
}; 

struct pointer {
    int location;
    int accumulator;
};

int loop_finder(std::vector<instruct> instructs, pointer& p, int x) {
    if (instructs[x].command == "jmp") {
        instructs[x].command = "nop";
    }
    else if (instructs[x].command == "nop") {
        instructs[x].command = "jmp";
    }
    bool term = false;
    bool loop = false;
    while (loop == false && term == false) {
        instruct a = instructs[p.location];
        if (a.exec == true) {
            loop = true;
        }
        else {
            instructs[p.location].exec = true;
            if (a.command == "acc") {
                p.accumulator += a.value;
                p.location++;

            }
            else if (a.command == "jmp") {
                p.location += a.value;

            }
            else if (a.command == "nop") {
                p.location++;                

            }
            
            if (p.location >= instructs.size()) {
                term = true;
            }
        }   
    }
    return term;
};


int main(){
    std::vector<instruct> instructs;
    std::regex pos("([a-z]+)\\s\\+([0-9]+)");
    std::regex neg("([a-z]+)\\s\\-([0-9]+)");
    std::smatch matches;
    string line;
    ifstream myReadFile;
    myReadFile.open("day8.txt");
    if(myReadFile.is_open()){
        while (std::getline(myReadFile, line)){
            if(std::regex_search(line, matches, pos)) {
                instruct i = {matches.str(1), std::stoi(matches.str(2)), false};
                instructs.push_back(i);
            }
            else if(std::regex_search(line, matches, neg)) {
                instruct i = {matches.str(1), - std::stoi(matches.str(2)), false};
                instructs.push_back(i);
            }
            else {
                cout << "error with regex" << endl;
            }


        }

        myReadFile.close();
    } 

    pointer p = {0, 0};

    //// PART 1 //// 
    loop_finder(instructs, p, 0);
    cout << p.accumulator << endl;    


    //// PART 2 ////

    for (int x=0; x < instructs.size(); x++) {
        pointer p = {0, 0};
        string a = instructs[x].command;
        if (a != "acc") {
            if (loop_finder(instructs, p, x)) {
                cout << p.accumulator;
                break;
            }

        }
    }


    
}

