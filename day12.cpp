#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <string> 
#include<numeric>
#include <regex>

using namespace std;

struct instruct {
  string direc;
  int step;
}; 

struct boat {
    int xpos;
    int ypos;
};


int main(){
    std::vector<instruct> instructs;
    std::regex rgx("([A-Z]+)([0-9]+)");
    std::smatch matches;
    string line;
    ifstream myReadFile;
    myReadFile.open("day12.txt");
    if(myReadFile.is_open()){
        while (std::getline(myReadFile, line)){
            if(std::regex_search(line, matches, rgx)) {
                instruct i;
                i.direc = matches.str(1);
                i.step = std::stoi(matches.str(2));
                instructs.push_back(i);
            }


        }

        myReadFile.close();
    } 

    ///// PART 1 /////

    boat b;
    b.xpos = 10;
    b.ypos = 1;

    boat s;
    s.xpos = 0;
    s.ypos = 0;

    for (int i=0; i<instructs.size(); i++) {
        if (instructs[i].direc == "N") {
            b.ypos += instructs[i].step;
        }
        else if (instructs[i].direc == "S") {
            b.ypos -= instructs[i].step;
        }
        else if (instructs[i].direc == "E") {
            b.xpos += instructs[i].step;
        }
        else if (instructs[i].direc == "W") {
            b.xpos -= instructs[i].step;
        }
        else if (instructs[i].direc == "L") {
            int xchange = b.xpos - s.xpos;
            int ychange = b.ypos - s.ypos; 

            if (instructs[i].step == 90) {
                b.xpos = s.xpos - ychange;
                b.ypos = s.ypos + xchange;
            }
            else if (instructs[i].step == 180) {
                b.xpos = s.xpos - xchange;
                b.ypos = s.ypos - ychange;
            }
            else if (instructs[i].step == 270) {
                b.xpos = s.xpos + ychange;
                b.ypos = s.ypos - xchange;
            }
        }
        else if (instructs[i].direc == "R") {
            int xchange = b.xpos - s.xpos;
            int ychange = b.ypos - s.ypos;  

            if (instructs[i].step == 90) {
                b.xpos = s.xpos + ychange;
                b.ypos = s.ypos - xchange;
            }
            else if (instructs[i].step == 180) {
                b.xpos = s.xpos - xchange;
                b.ypos = s.ypos - ychange;
            }
            else if (instructs[i].step == 270) {
                b.xpos = s.xpos - ychange;
                b.ypos = s.ypos + xchange;
            }
        }
        else if (instructs[i].direc == "F") {
            int xchange = b.xpos - s.xpos;
            int ychange = b.ypos - s.ypos;
            s.xpos += instructs[i].step * xchange;
            b.xpos += instructs[i].step * xchange;
            s.ypos += instructs[i].step * ychange;
            b.ypos += instructs[i].step * ychange;                     
        }
        else {
            cout << "direction error" << endl;
        }
    }

    cout << abs(s.xpos) + abs(s.ypos) << endl;
    
}

