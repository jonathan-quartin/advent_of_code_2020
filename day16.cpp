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
    std::regex rgx("([a-z]+): ([1-9]+)-([1-9]+) or ([1-9]+)-([1-9]+)");
    std::map<string, std::vector<int> > fields;
    std::map<int, std::vector<int> > tickets;
    int ticket_numb = 0;
    std::smatch matches;
    ifstream myReadFile;
    string line;
    if (myReadFile.open("day16.txt")) {
        while (std::getline(myReadFile, line)) {
            if (std::regex_search(line, matches, rgx)) {
                fields[matches.str(1)] = {matches.str(2), matches.str(3), matches(4), matches(5)};
            }
            else if (line == "your ticket:" || line == "nearby tickets:") {
                std::getline(myReadFile, line);
                while (line.size() != 0) {
                    tickets[ticket_numb];
                    stringstream s_stream(line); //create string stream from the string
                    while(s_stream.good()) {
                        string substr;
                        getline(s_stream, substr, ','); //get first string delimited by comma
                        int val = std::stoi(substr);
                        tickets[ticket_numb].push_back(val);       
                    }
                    std::getline(myReadFile, line);
                    ticket_numb++;
                }
            }
        }
    }
    myReadFile.close();

    int total = 0;
    for (int x=0; x<ticket_numb; x++) {
        for (int y=0; y<ticket[ticket_numb].size(); y++) {
            for(std::map<int, std::vector<int> >::iterator iter = memory2.begin(); iter != memory2.end(); ++iter) {
                total += iter->second;
            }
        }
    }
   
}

