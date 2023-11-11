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
    }

    //////////// find maximum planar subset ////////////
    int** result=new int*[(n/2)];

    int MIS=maxPlanarSubset(data, n, result);

    //////////// write the output file ////////////
    fout<<MIS<<endl;
    //for(){}
    fin.close();
    fout.close();
    return 0;
}