#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <string> 
#include<numeric>
#include <regex>

using namespace std;


int trees(std::vector<string> values, std::vector<int> slope, int length) {
    int row = 0;
    int column = 0;
    int tree = 0;
    while (row <= values.size()) {
        row = row + slope[0];
        column = (column + slope[1]) % length;
        if (values[row][column] == '#') {
            tree++;
        } 
    
    }
    // cout << tree << endl;

    return tree;
}

int main(){
    string line;
    std::vector<string> values;
    std::vector<std::vector<int> > slopes;
    slopes = {{1,1},{1,3},{1,5},{1,7},{2,1}};
    ifstream myReadFile;
    myReadFile.open("day3.txt");
    if(myReadFile.is_open()){
        while (std::getline(myReadFile, line)){
            values.push_back(line);
        }

        myReadFile.close();
    } 

    int length = values[0].size();
    long int total = 1;

    for (int x=0; x < slopes.size(); x++) {
        total = total * trees(values, slopes.at(x), length);
        cout << total << endl; 
    }
    cout << total;

}

