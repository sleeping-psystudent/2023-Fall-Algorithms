#include "maxPlanarSubset.h"
#include <iostream>

int maxPlanarSubset(vector<int>& data, int num, int **result){
    // initialize MIS
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
            }
            //case 2: j>k>i
            else if(j>k && k>i){
                MIS[i][j]=MIS[i][k-1]+1+MIS[k+1][j-1];
            }
            //case 3: k==i
            else if(k==i){
                MIS[i][j]=MIS[i+1][j-1]+1;
            }

            i++;
            j++;
        }
    }

    trace(0, num-1, 0, data, num, result);
    return MIS[0][num-1];
}

void trace(int i, int j, int acc, vector<int>& data, int num, int **result){

}