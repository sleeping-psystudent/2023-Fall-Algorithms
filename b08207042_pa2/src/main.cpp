#include <iostream>
#include <fstream>
#include <algorithm>
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
    //sorting
    sort(result, result+MIS, compare);

    //output
    for(i=0;i<MIS;i++) fout<<result[i][0]<<" "<<result[i][1]<<endl;
    fin.close();
    fout.close();

    for(i=0;i<MIS;i++) {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}