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

//Calculate indegree, outdegree, and sigma
void degreeCal(vector<edge>& data1, vector<vertex>& data2, vector<int>& indegree, vector<int>& outdegree){
    int i;
    for(i=0;i<data1.size();i++){
        indegree[data1[i].v]++;
        outdegree[data1[i].u]++;
    }
    for(i=0;i<indegree.size();i++){
        data2[i].idx=i;
        data2[i].sigma=outdegree[i]-indegree[i];
        data2[i].front=NULL;
        data2[i].back=NULL;
    }
}

//Algorithm by E, L, S
void ELS(vector<vertex>& data2, vertex* s1, vertex* s2, vector<int>& indegree, vector<int>& outdegree){
    int i;
    int count=0;
    vertex* now1=s1;
    vertex* now2=s2;
    vector<vertex> rest(data2.size());

    for(i=0;i<data2.size();i++){
        //source s1<-s1u
        if(indegree[i]==0){
            now1->back=&data2[i];
            data2[i].front=now1;
            now1=now1->back;
            //cout<<"source: "<<now1->idx<<" "<<now1->sigma<<endl;
        }
        //sink s2<-us2
        else if(outdegree[i]==0){
            now2->front=&data2[i];
            data2[i].back=now2;
            now2=now2->front;
            //cout<<"sink: "<<now2->idx<<" "<<now2->sigma<<endl;
        }
        else{
            rest[count].idx=data2[i].idx;
            rest[count].sigma=data2[i].sigma;
            rest[count].idx_ts=data2[i].idx_ts;
            rest[count].front=NULL;
            rest[count].back=NULL;
            //cout<<"count: "<<rest[count].idx<<" "<<rest[count].sigma<<endl;
            count++;
        }
    }

    //neither source nor sink
    if(count!=0){
        //sorting by sigma
        sort(rest.begin(), rest.begin()+count, compareSigma);
        //maximum s1<-s1u
        for(i=0;i<count;i++){
            now1->back=&data2[rest[i].idx];
            data2[rest[i].idx].front=now1;
            now1=now1->back; 
            //cout<<"rest: "<<rest[i].idx<<" "<<rest[i].sigma<<endl;
            //cout<<"max: "<<now1->idx<<" "<<now1->sigma<<endl;
        }
    }
    //s<-s1s2
    now1->back=now2;
    now2->front=now1;

    //topolofical sort index
    vertex* now=s1->back;
    for(i=0;i<data2.size();i++){
        now->idx_ts=i;
        now=now->back;
    }

}

//Nonincreasing
bool compareSigma(const vertex& v1, const vertex& v2){
    return v1.sigma>v2.sigma;
}

//Find out backward edge
int DAG(vector<edge>& data1, vector<vertex>& data2){
    int i, u, v;
    int weightSum=0;
    int maxSum=0;

    for(i=0;i<data1.size();i++){
        u=data2[data1[i].u].idx_ts;
        v=data2[data1[i].v].idx_ts;
        weightSum+=data1[i].w;
        //not backward edge
        if(u<v){
            maxSum+=data1[i].w;
            data1[i].u=-1;
        }
    }
    return weightSum-maxSum;
}