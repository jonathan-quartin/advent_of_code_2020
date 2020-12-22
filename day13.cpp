#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> 
#include <string> 
#include<numeric>
#include <regex>

using namespace std;



int main(){

    //// PART 1 ////
    /*
    std::vector<int> buses = {13, 37, 401, 17, 19, 23, 29, 613, 41};
    int depart = 1000340;
    int next = 0;
    int time = 1000;
    for (int x=0; x<buses.size(); x++) {
        int tempbus = buses[x];
        int temptime = tempbus - (depart % tempbus);
        if (temptime <= time) {
            next = tempbus;
            time = temptime;
        }

    }
    cout << next * time;
    */

    //// PART 2 ////

    std::vector<string> timestamps;
    string line;
    ifstream myReadFile;
    myReadFile.open("day13.txt");
    std::getline(myReadFile, line);
    std::getline(myReadFile, line);
    myReadFile.close();
    stringstream s_stream(line); //create string stream from the string
    while(s_stream.good()) {
        string substr;
        getline(s_stream, substr, ','); //get first string delimited by comma
        timestamps.push_back(substr);
    }
    

    std::vector<int> bus;
    std::vector<std::vector<int> > buses;
    for (int x=0; x<timestamps.size(); x++) {
        if (timestamps[x] != "x") {
            int a = std::stoi(timestamps[x]);
            bus.push_back(a);
            int b = (a - x) % a;
            if (b<0) {
                b += a;
            }
            bus.push_back(b);
            buses.push_back(bus);
            bus.clear();
        }
    }

    int t;
    long int b = 0;
    long int c = buses[0][0];
    for (int y=1; y<(buses.size()); y++) {
        bool found = false;
        while (!found) {
            long int d = b % buses[y][0];
            if (d == buses[y][1]) {
                c *= buses[y][0];
                break;
            }
            else {
                b += c;
            }
        }
    }
    cout << b;
   
}

