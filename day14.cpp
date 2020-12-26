#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <string> 
#include <map> 
#include<numeric>
#include <regex>
#include <bitset>
#include <stdlib.h> 

using namespace std;

// Very messy day. My structs were not ideal for the problem, 
//and caused me to have very messy indexing issues. Come back and clean up if you dare...

struct maskmem {
    std::vector<int> mems;
};

struct memvals {
    std::vector<string> vals;
    long int final = 1; // got used for different purposes for part 2
};

long int BinaryToDecimal(string n) {
   long int decimalNumber = 0;
   long int base = 1;
   int temp = n.length();
   while (temp) {
      long int lastDigit = n.at(temp-1) - 48;
      temp -= 1;
      decimalNumber += lastDigit*base;
      base = base*2;
   }
   return decimalNumber;
}

// function for part 2
std::vector<string> get_locs(string bin, int pointer) {
    std::vector<string> locs;
    if (pointer >= bin.size()) {
        locs.push_back(bin);
        return locs;
    }
    else {
        if (bin[pointer] == '0' || bin[pointer] == '1') {
            locs = get_locs(bin, pointer+1);
            return locs;
        }   
        else {
            string bin0 = bin;
            string bin1 = bin;
            bin0[pointer] = '0';
            bin1[pointer] = '1';
            std::vector<string> locs0 = get_locs(bin0, pointer+1);    
            std::vector<string> locs1 = get_locs(bin1, pointer+1); 
            for (int x=0; x<locs0.size(); x++) {
                locs.push_back(locs0[x]);
                locs.push_back(locs1[x]);
            } 
            return locs;
        }     
    }
}

int main(){
    std::vector<std::tuple<string, maskmem > > masks;
    std::map<long int, memvals> memory;
    std::map<long int, long int> memory2;
    std::vector<int> memkeys;
    std::regex rgx("mask (\\=) ([0-9A-Z]+)");
    std::regex rgx2("mem\\[([0-9]+)\\] = ([0-9]+)");
    std::smatch matches;
    std::smatch matches2;
    string line;
    ifstream myReadFile;
    myReadFile.open("day14.txt");
    if(myReadFile.is_open()){
        std::getline(myReadFile, line);
        while (line.size() != 0){
            if(std::regex_search(line, matches, rgx)) {
                string t = matches.str(2);
                maskmem m;
                std::getline(myReadFile, line);
                while (std::regex_search(line, matches2, rgx2)) {
                    long int a = std::stoi(matches2.str(1));
                    long int b = std::stoi(matches2.str(2));
                    std::string s = std::bitset< 36 >( b ).to_string();
                    m.mems.push_back(a);
                    if ( memory.find(a) == memory.end() ) {
                        memvals n;
                        n.vals.push_back(s);
                        memory[a] = n;
                        memkeys.push_back(a);
                    } 
                    else {
                        memory[a].vals.push_back(s);      
                    }
                    std::getline(myReadFile, line);
                }
                std::tuple<string, maskmem > mask = {t, m};
                masks.push_back(mask);
            }


        }

        myReadFile.close();
    }

//// PART 1 ////
/*
    for(int y=0; y<masks.size(); y++) {
        for(int x=0; x<get<1>(masks[y]).mems.size(); x++) {
            long int m = get<1>(masks[y]).mems[x];
            memvals *a = &memory[m];
            string b = get<0>(masks[y]);
            string c = (*a).vals[(*a).vals.size()-1];
            for (int z=0; z<b.size(); z++) {
                if (b[z] == 'X') {
                }
                else if (b[z] == '0') {
                    c[z] = b[z];
                }
                else if (b[z] == '1') {
                    c[z] = b[z];
                }
            }
            long int d = BinaryToDecimal(c);
            (*a).final = d;
        }        
    }

    long int total = 0;

    for (int x=0; x<memkeys.size(); x++) {
        total += memory[memkeys[x]].final;
    }

    cout << total;
*/

//// PART 2 ////
    for(int y=0; y<masks.size(); y++) {
        for(int x=0; x<get<1>(masks[y]).mems.size(); x++) {
            long int m = get<1>(masks[y]).mems[x];
            memvals *a = &memory[m];
            string b = get<0>(masks[y]);
            std::string m_str = std::bitset< 36 >( m ).to_string();
            std::vector<string> locations;
            for (int z=0; z<b.size(); z++) {
                if (b[z] == 'X') {
                    m_str[z] = 'X';
                }
                else if (b[z] == '0') {
                }
                else if (b[z] == '1') {
                    m_str[z] = '1';
                }
            }
            locations = get_locs(m_str, 0);
            for (int z=0; z<locations.size(); z++) {
                long int d = BinaryToDecimal(locations[z]);
                memory2[d] = BinaryToDecimal((*a).vals[(*a).final - 1]);
            }
            (*a).final++;
        }        
    }
    long int total = 0;
    for(std::map<long int, long int>::iterator iter = memory2.begin(); iter != memory2.end(); ++iter) {
        total += iter->second;
    }
    cout << total;;

}

