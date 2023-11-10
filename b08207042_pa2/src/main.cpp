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
    vector<int> data(n, -1);
    int a, b;
    for(i=0;i<(n/2);i++){
        fin>>a>>b;
        data[a]=b;
        data[b]=a;
        i++;
    }

    //////////// initialization ////////////
    vector<vector<int>> table(n, vector<int>(n, -1));

    //////////// find maximum planar subset ////////////
    vector<vector<int>> MIS=maxPlanarSubset(data, table, n);

    //////////// write the output file ////////////
    fout<<MIS[0][n-1]<<endl;
    for(){}
    fin.close();
    fout.close();
    return 0;
}