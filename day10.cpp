#include <iostream>
#include <sstream>
#include <fstream>
#include <vector> //unsure how to actually create an empty list or vector that can be added to.
#include <string> 
#include<numeric>
#include <map>


using namespace std;

long int combs (std::vector<int>* v, int pointer, std::map<int,long int>& reps) {
    long int sum = 0;
    if (reps[pointer] != 0) {
        sum = reps[pointer];
    }
    else if (pointer == 0) {
        sum = 1;
    }
    else if (pointer == 1) {
        sum = 1;
    }
    else {
        if ((*v)[pointer] - (*v)[pointer-3] == 3) {
            sum = combs(v, pointer - 3, reps) + combs(v, pointer - 2, reps) + combs(v, pointer - 1, reps);
        }
        else if ((*v)[pointer] - (*v)[pointer-2] <= 3){
            sum = combs(v, pointer - 2, reps) + combs(v, pointer - 1, reps);
        }
        else {
            sum = combs(v, pointer - 1, reps);  
        }
    }
    reps[pointer] = sum;
    return sum;

}

int diff(std::vector<int> v, int sub) {
    int count = 0;
    for (int x=0; x<(v.size()-1); x++) {
        if (v[x+1] - v[x] == sub) {
            count++;
        } 
    }
    return count;

}


  


int main(){
    std::vector<int> v;
    std::map<int,long int> reps;
    v.push_back(0);
    string line;
    ifstream myReadFile;
    myReadFile.open("day10.txt");
    if(myReadFile.is_open()){
        while (std::getline(myReadFile, line)){
            v.push_back(std::stoi(line));
            reps[std::stoi(line)] = 0;


        }

        myReadFile.close();
    } 
    
    sort(v.begin(), v.end());
    
    ///// PART 1 /////

    cout << (diff(v, 1)) * (diff(v, 3) + 1) << endl;


    ///// PART 2 /////
    cout << combs(&v, v.size()-1, reps) << endl;





}