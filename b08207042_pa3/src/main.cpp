#include <iostream>
#include <fstream>
#include <algorithm>
#include "Undirected.h"
#include "Directed.h"

using namespace std;

struct edge {
    int u; // beginning
    int v; // destination
    int w; // weight
};

int main(int argc, char*argv[]){
    int i;

    //////////// read the input file ////////////
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2],ios::out);
    char type;
    fin>>type;
    int vec_num, edge_num;
    fin>>vec_num;
    fin>>edge_num;

    vector<edge> edge_set;
    int a, b, c;
    for(i=0;i<edge_num;i++){
        fin>>a>>b>>c;
        edge data={a, b, c};
        edge_set.push_back(data);
    }

    //////////// which type to execute ////////////
    if(type=='u'){

    }
    else if(type=='d'){

    }
}