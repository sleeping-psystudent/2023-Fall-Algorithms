#include <iostream>
#include <fstream>
#include <algorithm>
#include "functions.h"

using namespace std;

int main(int argc, char*argv[]){
    int i;

    //////////// read the input file ////////////
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2],ios::out);
    char type;
    fin>>type;
    int ver_num, edge_num;
    fin>>ver_num;
    fin>>edge_num;

    vector<int> parent_indegree(ver_num, 0);
    vector<int> rank_outdegree(ver_num, 0);

    vector<edge> edge_set;
    int a, b, c;
    for(i=0;i<edge_num;i++){
        fin>>a>>b>>c;
        edge info={a, b, c};
        edge_set.push_back(info);
    }

    //////////// which type to execute ////////////
    int ans;
    vector<edge> remain;
    vector<edge> remove;

    if(type=='u'){
        for(i=0;i<ver_num;i++) parent_indegree[i]=i; //parent
        CountSort(edge_set);
        ans=KruskalMST(edge_set, remove, remain, parent_indegree, rank_outdegree);
    }
    /*
    else if(type=='d'){
        vector<vertex> ver_set(ver_num);
        degreeCal(edge_set, ver_set, parent_indegree, rank_outdegree);

        vertex* s1=new vertex();
        s1->idx=-1;
        s1->sigma=0;
        s1->loc='b';
        s1->idx_ts=0;
        s1->front=NULL;
        s1->back=NULL;
        vertex* s2=new vertex();
        s2->idx=1;
        s2->sigma=0;
        s2->loc='e';
        s2->idx_ts=0;
        s2->front=NULL;
        s2->back=NULL;

        ELS(ver_set, s1, s2, parent_indegree, rank_outdegree);
        ans=DAG(edge_set, ver_set);
    }*/
    else if(type=='d'){
        for(i=0;i<ver_num;i++) parent_indegree[i]=i; //parent
        CountSort(edge_set);
        ans=KruskalMST(edge_set, remove, remain, parent_indegree, rank_outdegree);

        //create adj list by remain
        vector<vector<vertex>> adjList(ver_num);
        for(i=0;i<remain.size();i++){
            adjList[remain[i].u].push_back({remain[i].v, remain[i].w});
        }

        //put positive edges back to the graph
        for(i=0;i<remove.size();i++){
            if(remove[i].w>0){
                if(DFS()==false){

                }
            }
        }
    }

    //for testing
    cout<<ans<<endl;
    for(i=0;i<remove.size();i++) cout<<remove[i].u<<" "<<remove[i].v<<" "<<remove[i].w<<endl;


    //////////// write the output file ////////////
/*    
    fout<<ans<<endl;
    for(i=0;i<edge_num;i++){
        if(edge_set[i].u==-1) continue;
        else fout<<edge_set[i].u<<" "<<edge_set[i].v<<" "<<edge_set[i].w<<endl;
    }
    

    fin.close();
    fout.close();
*/
}