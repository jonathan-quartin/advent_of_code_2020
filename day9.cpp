#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> //unsure how to actually create an empty list or vector that can be added to.
#include <string> 
#include<numeric>

using namespace std;

int main(){
    long int invalid;
    std::vector<int> values;
    string line;
    ifstream myReadFile;
    myReadFile.open("day9.txt");
    if(myReadFile.is_open()){
        while (std::getline(myReadFile, line)){
            values.push_back(std::stol(line));


        }

        myReadFile.close();
    } 
    
    ///// PART 1 /////

    for (int x = 25; x < values.size(); x++) {
        bool match = false;
        for (int y = x - 25; y < x - 1; y++) {
            for (int z = y + 1; z < x; z++) {
                if (values[y] + values[z] == values[x]) {
                    match = true;
                    break;
                }
            }
            if (match == true) {
                break;
            }
                 
        }
        if (match == false) {
            invalid = values[x];
            break;
        }

    }  

    long int sum = 0;
    int lower = 0;
    int upper = 0;
    while (sum != invalid) {
        if (sum < invalid) {
            sum += values[upper];
            upper += 1;
        }
        else if (sum > invalid) {
            sum -= values[lower];
            lower += 1;
        }
    }

    std::vector<int> contig;

    for (int x = lower; x < upper; x++) {
        contig.push_back(values[x]);
    }
    
    long int large = *max_element(contig.begin(), contig.end());
    long int small = *min_element(contig.begin(), contig.end());

    cout << large + small;

}