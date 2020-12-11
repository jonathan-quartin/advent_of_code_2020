#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <string> 
#include <set> 
#include<numeric>
#include <regex>

using namespace std;

int main(){
    int counter = 0;
    std::set<string> intersection;
    std::set<string> yes_list;
    std::vector<std::set<string> > group_list;
    std::regex person("([a-z]+)");
    std::smatch matches;
    string line;
    ifstream myReadFile;
    myReadFile.open("day6.txt");
    if(myReadFile.is_open()){
        while(!myReadFile.eof()){
            std::getline(myReadFile, line);
            if(line.length() != 0) {
                std::regex_search(line, matches, person);
                std::set<string> response;
                for (char c: matches.str(1)) {
                    response.insert(string{c});
                }
                //// PART 1 ////
                /*
                std::set_union(yes_list.begin(), yes_list.end(),
                response.begin(), response.end(),
                std::inserter(yes_list, yes_list.begin()));
                */

                //// PART 2 ////
                if (counter == 0) {
                    std::set_union(yes_list.begin(), yes_list.end(),
                    response.begin(), response.end(),
                    std::inserter(yes_list, yes_list.begin()));
                }
                else {
                    std::set_intersection(yes_list.begin(), yes_list.end(),
                    response.begin(), response.end(),
                    std::inserter(intersection, intersection.begin()));
                    yes_list.clear();
                    std::set_union(yes_list.begin(), yes_list.end(),
                    intersection.begin(), intersection.end(),
                    std::inserter(yes_list, yes_list.begin()));
                    intersection.clear();
                } 
                
                counter ++;

            }
            else {
                group_list.push_back(yes_list);
                yes_list.clear();
                counter = 0;

                
            }

        } 

    myReadFile.close();
    }

    int total = 0;

    for (int x=0; x < group_list.size(); x++) {
        total = total + group_list[x].size();
    } 
       
    cout << total;    
    
}

