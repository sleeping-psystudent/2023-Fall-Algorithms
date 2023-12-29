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
    int d; //destination
    int w; //weight
};

/*
struct vertex{
    int idx;
    int sigma;
    int idx_ts;
    char loc; // b=source, e=sink, s=the rest
    struct vertex* front;
    struct vertex* back;
};*/

//////////// Undirected Acyclic Graph ////////////
int Find(int u, vector<int>& parent);
void Merge(int a, int b, vector<int>& parent, vector<int>& rank);
void CountSort(vector<edge>& data);
int KruskalMST(vector<edge>& data, vector<edge>& rmv, vector<edge>& rma, vector<int>& parent, vector<int>& rank);
//////////// Directed Acyclic Graph ////////////
/*
void degreeCal(vector<edge>& data1, vector<vertex>& data2, vector<int>& indegree, vector<int>& outdegree);
void ELS(vector<vertex>& data2, vertex* s1, vertex* s2, vector<int>& indegree, vector<int>& outdegree);
bool compareSigma(const vertex& v1, const vertex& v2);
int DAG(vector<edge>& data1, vector<vertex>& data2);
*/
#endif