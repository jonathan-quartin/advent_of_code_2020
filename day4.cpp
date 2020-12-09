#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <string> 
#include<numeric>
#include <regex>

using namespace std;

int main(){
    bool valid = true;
    std::vector<string> field;
    std::vector<std::vector<string> > passport;
    std::vector<std::vector<std::vector<string> > > passports;
    std::regex cid("(cid):([a-zA-Z0-9!@#$&()\\-`.+,/\"]+)");
    std::regex byr("(byr):([0-9]+)");
    std::regex iyr("(iyr):([0-9]+)");
    std::regex eyr("(eyr):([0-9]+)");
    std::regex hgt("(hgt):([0-9]+)([a-z]+)");
    std::regex hcl("(hcl):#([a-z0-9]+)");
    std::regex ecl("(ecl):([a-z]+)");
    std::regex pid("(pid):([0-9]+)");
    std::smatch matches;
    string line;
    ifstream myReadFile;
    myReadFile.open("day4.txt");
    if(myReadFile.is_open()){
        while(!myReadFile.eof()){
            std::getline(myReadFile, line);
            if(line.length() != 0 && valid == true) {
                string tmp; // A string to store the word on each iteration.
                stringstream str_strm(line);
                while (str_strm >> tmp && valid == true) {
                /*    if(std::regex_search(tmp, matches, cid)) {
                        if (matches.str(1) == "cid") {
                            field.push_back(matches.str(1));
                            field.push_back(matches.str(2));
                            passport.push_back(field);   
                        }
                    } */
                    if(std::regex_search(tmp, matches, byr)) {
                        int a = std::stoi(matches.str(2));
                        if (a >= 1920 && a <= 2002) {
                            field.push_back(matches.str(1));
                            field.push_back(matches.str(2));
                            passport.push_back(field);   
                        }
                        else {
                            valid = false;
                        }
                    }
                    else if(std::regex_search(tmp, matches, iyr)) {
                        int a = std::stoi(matches.str(2));
                        if (a >= 2010 && a <= 2020) {
                            field.push_back(matches.str(1));
                            field.push_back(matches.str(2));
                            passport.push_back(field);   
                        }
                        else {
                            valid = false;
                        }
                    }
                    else if(std::regex_search(tmp, matches, eyr)) {
                        int a = std::stoi(matches.str(2));
                        if (a >= 2020 && a <= 2030) {
                            field.push_back(matches.str(1));
                            field.push_back(matches.str(2));
                            passport.push_back(field);   
                        }
                        else {
                            valid = false;
                        }
                    }
                    else if(std::regex_search(tmp, matches, hgt)) {
                        int a = std::stoi(matches.str(2));
                        if (matches.str(3) == "cm" && a >= 150 && a <= 193) {
                            field.push_back(matches.str(1));
                            field.push_back(matches.str(2));
                            field.push_back(matches.str(3));
                            passport.push_back(field);   
                        }
                        else if (matches.str(3) == "in" && a >= 59 && a <= 76) {
                            field.push_back(matches.str(1));
                            field.push_back(matches.str(2));
                            field.push_back(matches.str(3));
                            passport.push_back(field);   
                        }
                        else {
                            valid = false;
                        }
                    }
                    else if(std::regex_search(tmp, matches, hcl)) {
                        if (matches.str(2).size() == 6) {
                            field.push_back(matches.str(1));
                            field.push_back(matches.str(2));
                            passport.push_back(field);   
                        }
                        else {
                            valid = false;
                        }
                    }
                    else if(std::regex_search(tmp, matches, ecl)) {
                        string a = matches.str(2);
                        if (a == "amb" || a == "blu" || a == "brn" || a == "gry" || a == "grn" || a == "hzl" || a == "oth") {
                            field.push_back(matches.str(1));
                            field.push_back(matches.str(2));
                            passport.push_back(field);   
                        }
                        else {
                            valid = false;
                        }
                    }
                    else if(std::regex_search(tmp, matches, pid)) {
                        if (matches.str(2).size() == 9) {
                            field.push_back(matches.str(1));
                            field.push_back(matches.str(2));
                            passport.push_back(field);   
                        }
                        else {
                            valid = false;
                        }
                    }
                    field.clear();

                }
            
            }
            else {
                if (valid == false){
                    passport.clear();
                    valid = true;
                }
                else{
                    passports.push_back(passport);
                    passport.clear();
                }

                
            }

        } 

    myReadFile.close();
    }

    int valids = 0;

    for (int x=0; x < passports.size(); x++) {
        if (passports[x].size() == 7) {
            valids++;
        };
    } 
       
    cout << valids;    
    
}

