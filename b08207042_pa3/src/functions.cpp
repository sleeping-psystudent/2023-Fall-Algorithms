#include <iostream>
#include <algorithm>
#include "functions.h"

//////////// Undirected Acyclic Graph ////////////

//Find Set, find the parent of vertex u
int Find(int u, vector<int>& parent){
    if(u!=parent[u]) parent[u]=Find(parent[u], parent);
    return parent[u];
}

//Merge Set, merge the set where vertex a belongs and another set where vertex b belongs
void Merge(int a, int b, vector<int>& parent, vector<int>& rank){
    a=Find(a, parent);
    b=Find(b, parent);

    if(rank[a]>rank[b]) parent[b]=a;
    else parent[a]=b;

    if(rank[a]==rank[b]) rank[b]++;
}

//Sorting -> Counting Sort
void CountSort(vector<edge>& data){
    int min_weight=-100;
    int max_weight=100;
    int range=max_weight-min_weight+1;

    vector<int> count(range, 0);
    vector<edge> output(data.size());

    for(const auto& e : data) count[e.w-min_weight]++;
    for(int i=range-2;i>=0;i--) count[i]+=count[i+1];
    for (int i=data.size()-1;i>=0;i--) {
        output[count[data[i].w-min_weight]-1]=data[i];
        count[data[i].w-min_weight]--;
    }

    for(size_t i=0;i<data.size();i++) data[i]=output[i];
}

//KruskalMST
int KruskalMST(vector<edge>& data, vector<int>& parent, vector<int>& rank){
    int i;
    int weightSum=0;
    int maxSum=0;

    for(i=0;i<data.size();i++){
        int u=data[i].u;
        int v=data[i].v;
        int set_u=Find(u, parent);
        int set_v=Find(v, parent);

        weightSum+=data[i].w;
        if(set_u!=set_v){
            maxSum+=data[i].w;
            Merge(set_u, set_v, parent, rank);
            data[i].u=-1;
        }
    }

    return weightSum-maxSum;
}

//////////// Directed Acyclic Graph ////////////

void degreeCal(vector<edge>& data1, vector<vertex>& data2, vector<int>& indegree, vector<int>& outdegree){
    int i;
    for(i=0;i<data1.size();i++){
        indegree[data1[i].v]++;
        outdegree[data1[i].u]++;
    }
    for(i=0;i<indegree.size();i++){
        vertex info={i, outdegree[i]-indegree[i], NULL, NULL};
        data2.push_back(info);
    }
}

void ELS(vector<vertex>& data, vertex s1, vertex s2, vector<int>& indegree, vector<int>& outdegree){
    int i;
    int count=0;
    vertex now1=s1;
    vertex now2=s2;

    for(i=0;i<data.size();i++){
        if(indegree[i]==0){
            now1->back=data[i];
            data[i].front=now1;
            now1->back=
        }
        else if(outdegree[i]==0){}
    }
    while
    
}