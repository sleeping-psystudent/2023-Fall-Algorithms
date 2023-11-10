#include "maxPlanarSubset.h"
#include <iostream>

vector<vector<int>> maxPlanarSubset(vector<int>& data, vector<vector<int>>& table, int num){
    // initialize MIS
    vector<vector<int>> MIS(num, vector<int>(num, 0));

    int i, j, k;
    for(j=0;j<num;j++){
        k=data[j];
        for(i=0;i<j;i++){
            //case 1: i<k<j
            if() MIS[i][j]=MIS[i][j-1];
            //case 2: else
            else if((i<=k && k<j) && MIS[i][k-1]+1+MIS[k+1][j-1]>MIS[i][j-1]){
                MIS[i][j]=MIS[i][k-1]+1+MIS[k+1][j-1];
                table[i][j]=2;
            }
            //case 3: 
            else MIS[i][j]=MIS[i+1][j-1]+1;
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
1 0 0 0 0 0 0 0 0 0 0 0 
1 1 0 0 0 0 0 0 0 0 0 0 
1 1 1 0 0 0 0 0 0 0 0 0 
2 1 1 1 0 0 0 0 0 0 0 0 
2 1 1 1 1 0 0 0 0 0 0 0 
3 2 2 1 1 1 0 0 0 0 0 0 
3 2 2 1 1 1 1 0 0 0 0 0 
3 2 2 1 1 1 1 1 0 0 0 0 
3 3 2 1 1 1 1 1 1 0 0 0 
3 3 2 1 1 1 1 1 1 1 0 0 
3 3 2 1 1 1 1 1 1 1 1 0 
*/