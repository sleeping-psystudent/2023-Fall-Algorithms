#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <vector>
using namespace std;

struct edge{
    int u; // beginning
    int v; // destination
    int w; // weight
};

struct vertex{
    int idx;
    int sigma;
    vertex* front;
    vertex* back;
};

//////////// Undirected Acyclic Graph ////////////
int Find(int u, vector<int>& parent);
void Merge(int a, int b, vector<int>& parent, vector<int>& rank);
void CountSort(vector<edge>& data);
int KruskalMST(vector<edge>& data, vector<int>& parent, vector<int>& rank);
//////////// Directed Acyclic Graph ////////////
void degreeCal(vector<edge>& data1, vector<vertex>& data2, vector<int>& indegree, vector<int>& outdegree);


#endif