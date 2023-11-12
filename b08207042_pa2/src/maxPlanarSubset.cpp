#include "maxPlanarSubset.h"
#include <iostream>

int maxPlanarSubset(vector<int>& data, int num, int **result){
    // initialize
    vector<vector<int>> MIS(num, vector<int>(num, 0));
    vector<vector<int>> dirt(num, vector<int>(num, -1));
    vector<vector<int>> table(num, vector<int>(num, -1));

    int i, j, sub, k;
    for(sub=1;sub<num;sub++){
        i=0;
        j=i+sub;
        while(j<num){
            k=data[j];
            //case 1: k>j>i or j>i>k
            if(k>j || i>k){
                MIS[i][j]=MIS[i][j-1];
                dirt[i][j]=1;
                table[i][j]=table[i][j-1];
            }
            //case 2: j>k>i
            else if(j>k && k>i){
                MIS[i][j]=MIS[i][k-1]+1+MIS[k+1][j-1];
                dirt[i][j]=2;
                table[i][j]=k;
            }
            //case 3: k==i
            else if(k==i){
                MIS[i][j]=MIS[i+1][j-1]+1;
                dirt[i][j]=3;
                table[i][j]=k;
            }

            i++;
            j++;
        }
    }

    int* acc=new int;
    *acc=0;
    trace(0, num-1, acc, data, num, dirt, table, result);
    delete acc;
    return MIS[0][num-1];
}

void trace(int i, int j, int* acc, vector<int>& data, int num, vector<vector<int>> dirt, vector<vector<int>> table, int **result){
    if(table[i][j]==-1) return;

    if(dirt[i][j]==1){
        if(0<=j-1 && j-1<num) trace(i, j-1, acc, data, num, dirt, table, result);
    }
    else{
        int k=data[j];
        result[*acc]=new int[2];
        result[*acc][0]=min(k, j);
        result[*acc][1]=max(k, j);
        *acc+=1;
        if(dirt[i][j]==2){
            if(0<=i && i<num && 0<=k-1 && k-1<num) trace(i, k-1, acc, data, num, dirt, table, result);
            if(0<=k+1 && k+1<num && 0<=j-1 && j-1<num) trace(k+1, j-1, acc, data, num, dirt, table, result);
        }
        else if(dirt[i][j]==3){
            if(0<=i+1 && i+1<num && 0<=j-1 && j-1<num) trace(i+1, j-1, acc, data, num, dirt, table, result);
        }
    }
}

bool compare(const void* a, const void* b){
    return ((int *)a)[0]<((int *)b)[0];
}