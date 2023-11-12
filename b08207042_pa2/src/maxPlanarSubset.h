#ifndef _MAXPLANARSUBSET_H
#define _MAXPLANARSUBSET_H

#include <vector>
using namespace std;

int maxPlanarSubset(vector<int>&, int, int**);
void trace(int, int, int*, vector<int>&, int, vector<vector<int>>, vector<vector<int>>, int**);
bool compare(const void*a, const void* b);

#endif