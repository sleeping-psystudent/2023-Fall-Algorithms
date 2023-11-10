#include <iostream>
#include <fstream>
#include "maxPlanarSubset.h"

using namespace std;

int main(int argc, char* argv[]){
    int i, j;

    //////////// read the input file ////////////
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2],ios::out);
    int n;
    fin>>n;
    vector<vector<int>> data(n/2, vector<int>(2));
    int a, b;
    i=0;
    while(i<(n/2)){
        fin>>a>>b;
        data[i].push_back(a);
        data[i].push_back(b);
    }

    //////////// initialization ////////////
    vector<vector<int>> table(n, vector<int>(n, 0));

    //////////// find maximum planar subset ////////////
    maxPlanarSubset(data, table);

    //////////// write the output file ////////////
    fout<<
    for(){}
    fin.close();
    fout.close();
    return 0;
}