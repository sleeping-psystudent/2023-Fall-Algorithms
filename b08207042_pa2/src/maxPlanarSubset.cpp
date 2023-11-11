#include "maxPlanarSubset.h"
#include <iostream>

vector<vector<int>> maxPlanarSubset(vector<int>& data, vector<vector<int>>& table, int num){
    // initialize MIS
    vector<vector<int>> MIS(num, vector<int>(num, 0));

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
    return MIS;
}

/*
12
0 4
1 9
2 6
3 10
5 7
8 11
0

0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
1 0 0 0 0 0 0 0 0 0 0 0 
1 0 0 0 0 0 0 0 0 0 0 0 
1 1 1 0 0 0 0 0 0 0 0 0 
2 1 1 1 1 1 0 0 0 0 0 0 
2 1 1 1 1 1 0 0 0 0 0 0 
2 2 1 1 1 1 0 0 0 0 0 0 
2 2 2 2 1 1 0 0 0 0 0 0 
3 2 2 2 2 2 1 1 1 0 0 0
*/