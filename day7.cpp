#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <tuple> 
#include <string> 
#include<numeric>
#include <regex>
#include <map>

using namespace std;

struct inside_elt {
  int number;
  string name;
}; 

std::map<string, std::vector<inside_elt > > suitcases;


//// PART 1 ////
/*
int searcher(string suitcase) {
    if (suitcase == "shinygold") {
        return 1;
    }
    if (suitcases[suitcase].size() == 0) {
        return 0;
    }
    else {
        int sum = 0;
        for (int x=0; x < suitcases[suitcase].size(); x++) {
            sum = sum + searcher(suitcases[suitcase][x].name);
        }
        return sum;
    }
}
*/

//// PART 2 ////
int bag_counter(string suitcase, int amount) {
    if (suitcases[suitcase].size() == 0) {
        return 0;
    }  
    else {
        int sum = 0; 
        for (int x=0; x < suitcases[suitcase].size(); x++) {
            int new_amount = amount * suitcases[suitcase][x].number;
            sum = sum + new_amount;
            int b = bag_counter(suitcases[suitcase][x].name, new_amount);
            sum = sum + b;
        }
        return sum;
    }    
}

int main(){
    std::vector<string> suitcase_list;
    std::regex bag("([a-z]+)bagscontain");
    std::regex contents("([1-9])([a-z]+)bag([a-z]*),");
    std::regex last("([1-9])([a-z]+)bag([a-z]*).");
    std::smatch matches;
    string line;
    ifstream myReadFile;
    myReadFile.open("day7.txt");
    if(myReadFile.is_open()){
        while(std::getline(myReadFile, line)){
            string tmp; // A string to store the word on each iteration.
            stringstream str_strm(line);
            int counter = 0;
            string outer;
            string inner;
            std::vector<string> inners;
            while (str_strm >> tmp) {
                if (counter < 4){
                    outer.append(tmp);           
                }
                else if (counter == 4){
                    if (tmp == "no") {
                        inner.append(tmp);
                        counter++;
                    }
                    else {
                        inner.append(tmp);
                    }
                }
                else if (counter > 4){
                    int b = (counter + 1) % 4;
                    if (b == 0) {
                        inner.append(tmp);
                        inners.push_back(inner);
                        inner.clear();
                    }
                    else {
                        inner.append(tmp);
                    }
                }
                counter++; 
            }    
            std::vector<inside_elt> b;
            for (int x=0; x < inners.size(); x++) {
                if(std::regex_search(inners[x], matches, contents)) {
                    inside_elt a = {std::stoi(matches.str(1)), matches.str(2)};
                    b.push_back(a);
                }
                else if (std::regex_search(inners[x], matches, last)) {
                    inside_elt a = {std::stoi(matches.str(1)), matches.str(2)};
                    b.push_back(a);
                }
                    
            }
            if(std::regex_search(outer, matches, bag)) {
                string a = matches.str(1);
            
            suitcases[a] = b;
            suitcase_list.push_back(a);
            } 
        }
    myReadFile.close();
    }

    int valids = 0;

    //// PART 1 ////
    /*
    for (int x=0; x < suitcase_list.size(); x++) {
        int a = searcher(suitcase_list[x]);
        if (a) {
            valids++;
        }
    }

    cout << valids - 1; //// subtract 1 to not include the shiny gold bag itself in the searcher function
    */

   //// PART 2 ////

   cout << bag_counter("shinygold", 1);



    
   
    
}

