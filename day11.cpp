#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> //unsure how to actually create an empty list or vector that can be added to.
#include <string> 
#include<numeric>
#include <map>
#include <tuple>

using namespace std;

//// Come back and clean this one up ////

int main(){
    std::tuple<int,int> loc;
    std::map<std::tuple<int,int>,char> pos;
    string line;
    int counter = 0;
    int a = 0;
    int t = 0;
    int v = 0;
    ifstream myReadFile;
    myReadFile.open("day11.txt");
    if(myReadFile.is_open()){
        std::getline(myReadFile, line);
        a = line.size();
        while (line.size()){
            for (int x=0; x<line.size(); x++) {
                loc = {counter,x};
                pos[loc] = line[x];

            }
            counter++;
            std::getline(myReadFile, line);
        }

        myReadFile.close();
    } 
    ///// PART 1 /////
    for (int x=-1; x<a+1; x++) {
        loc = {-1,x};
        pos[loc] = '.';
        loc = {counter,x};
        pos[loc] = '.';
    }
    for (int x=0; x<counter; x++) {
        loc = {x,-1};
        pos[loc] = '.';
        loc = {x, a};
        pos[loc] = '.';

    }
    std::map<std::tuple<int,int>,char> pos2;
    bool same = false;
    int iter = 0;
    while (!same) {
        for (int x=0; x<counter; x++) {
            for (int y=0; y<a; y++) {
                loc = {x,y};
                if (pos[loc] == '.') {
                    pos2[loc] = '.';
                }
                else if (pos[loc] == 'L') {
                    bool seats = false;
                    for (int z=-1; z<2; z++) {
                        for (int w=-1; w<2; w++) {
                            t = z;
                            v = w;
                            if (t!=0 || v!=0) {
                                bool found = false;
                                while (x+t != -1 && x+t != counter && y+v != -1 && y+v != a && found == false) {
                                    if (pos[{x+t, y+v}] == '#') {
                                        seats = true;
                                        found = true;
                                    }
                                    else if (pos[{x+t, y+v}] == 'L') {
                                        found = true;
                                    }
                                    t += z;
                                    v += w;
                                }   
                            }
                            else {

                            }

                        }
                        if (seats) {
                            break;
                        }
                    }
                    if (!seats) {
                        pos2[loc] = '#';
                    }
                    else {
                        pos2[loc] = 'L';
                    }
                }
                else if (pos[loc] == '#') {
                    int occ = 0;
                    for (int z=-1; z<2; z++) {
                        for (int w=-1; w<2; w++) {
                            t = z;
                            v = w;
                            if (t!=0 || v!=0) {
                                bool found = false;
                                while (x+t != -1 && x+t != counter && y+v != -1 && y+v != a && found == false) {
                                    if (pos[{x+t, y+v}] == '#') {
                                        occ++;
                                        found = true;
                                    }
                                    else if (pos[{x+t, y+v}] == 'L') {
                                        found = true;
                                    }
                                    t += z;
                                    v += w;
                                }   
                            }  
                        }
                    }
                    if (occ >= 5) {
                        pos2[loc] = 'L';
                    }
                    else {
                        pos2[loc] = '#';
                    }
                }
                else {
                    cout << "error" << endl;
                }
            }
        }
        bool same = true;
        for (int x=0; x<counter; x++) {
            for (int y=0; y<a; y++) {
                loc = {x,y};
                if (same) {
                    if (pos[loc] != pos2[loc]) {
                        same = false;
                    }
                }
                pos[loc] = pos2[loc];
            
            }
        }
        if (same) {
            int taken = 0;
            for (int x=0; x<counter; x++) {
                for (int y=0; y<a; y++) {
                    loc = {x,y};
                    if (pos[loc] == '#') {
                        taken++;
                    }
                }
            }
            cout << taken << endl;
            break;
        }
        iter++;
    }

    ///// PART 2 /////


}