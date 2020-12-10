#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <string> 
#include<numeric>
#include <regex>

using namespace std;

// First two functions are identical- one for B and F, the other for L and R

string bf_to_bin (string str) {
    string bin;
    for (int x = 0; x < str.size(); x++) {
        if (str[x] == 'F') {
            bin.push_back(0);
        }
        else if (str[x] == 'B') {
            bin.push_back(1);
        }
        else {
            cout << "not a string of F and B";
        }
    }
    return bin;
}; 

string lr_to_bin (string str) {
    string bin;
    for (int x = 0; x < str.size(); x++) {
        if (str[x] == 'L') {
            bin.push_back(0);
        }
        else if (str[x] == 'R') {
            bin.push_back(1);
        }
        else {
            cout << "not a string of L and R";
        }
    }
    return bin;
}; 

int bin_to_int (string bin) {
    int total = 0;
    for (int x=0; x < bin.size(); x++) {
        total = total + (bin[x] * pow(2, x));

    }
    return total;
}


int main(){
    std::vector<int> seat_ids;
    std::regex row_col("([BF]+)([LR]+)");
    std::smatch matches;
    string line;
    ifstream myReadFile;
    myReadFile.open("day5.txt");
    if(myReadFile.is_open()){
        while (std::getline(myReadFile, line)){
            if(std::regex_search(line, matches, row_col)) {
                string row = matches.str(1);
                reverse(row.begin(), row.end()); 
                string column = matches.str(2);
                reverse(column.begin(), column.end());  
                int p = bin_to_int(bf_to_bin(row));
                int q = bin_to_int(lr_to_bin(column));
                int r = (p * 8) + q; 
                seat_ids.push_back(r);
            }


        }

        myReadFile.close();
    } 
//// PART 1 ////

    cout << *max_element(seat_ids.begin(),seat_ids.end()) << endl;

//// PART 2 ////

    std::sort (seat_ids.begin(), seat_ids.end());
    for (int x=0; x < seat_ids.size(); x++) {
        if (seat_ids[x+1] - seat_ids[x] != 1) {
            cout << seat_ids[x] + 1;
            break;
        }

    }
    
}

