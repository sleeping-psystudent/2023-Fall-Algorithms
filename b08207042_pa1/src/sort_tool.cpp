// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
//  Modify     [2023/9/12 Ming-Bang Fan]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>
#define ll long long 
// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    int key, j;
    for(int i=1;i<data.size();i++){
	    key=data[i];
	    j=i-1;
	    while(j>=0 && data[j]>key){
		    data[j+1]=data[j];
		    j--;
	    }
	    data[j+1]=key;
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data, int f){
    QuickSortSubVector(data, 0, data.size() - 1, f);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high, const int flag) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    // flag == 0 -> normal QS
    // flag == 1 -> randomized QS
    if(flag==0){
	    if(low<high){
	    	int q=Partition(data, low, high);
	    	QuickSortSubVector(data, low, q-1, 0);
	    	QuickSortSubVector(data, q+1, high, 0);
	    }
    }
    else if(flag==1){
	    if(low<high){
		    int q=RandomizedPartition(data, low, high);
		    QuickSortSubVector(data, low, q-1, 1);
		    QuickSortSubVector(data, q+1, high, 1);
	    }
    }
}
int SortTool::RandomizedPartition(vector<int>& data, int low, int high){
    // Function : RQS's Partition the vector 
    // TODO : Please complete the function
    //random
    int i=rand()%(high-low+1)+low;
    //exchange data[high] with data[i]
    int sw=data[high];
    data[high]=data[i];
    data[i]=sw;

    return Partition(data, low, high);
}

int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    int x=data[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
	    if(data[j]<=x){
		    i++;
		    //exchange data[i] with data[j]
		    int sw1=data[i];
		    data[i]=data[j];
		    data[j]=sw1;
	    }
    }
    //exchange data[i+1] with data[high]
    int sw2=data[i+1];
    data[i+1]=data[high];
    data[high]=sw2;

    return i+1;
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    if(low>=high) return;
    int q=(low+high)/2;
    MergeSortSubVector(data, low, q);
    MergeSortSubVector(data, q+1, high);
    Merge(data, low, q, q+1, high);
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    int i, j;
    int nL=middle2-low;
    int nR=high-middle1;
    //new arrays
    vector<int> L(nL);
    vector<int> R(nR);

    for(i=0;i<nL;i++) L[i]=data[low+i];
    for(j=0;j<nR;j++) R[j]=data[middle2+j];
    i=0;
    j=0;
    int k=low;
    while(i<nL && j<nR){
	    if(L[i]<=R[j]){
		    data[k]=L[i];
		    i++;
	    }
	    else{
		    data[k]=R[j];
		    j++;
	    }
	    k++;
    }
    while(i<nL){
	    data[k]=L[i];
	    i++;
	    k++;
    }
    while(j<nR){
	    data[k]=R[j];
	    j++;
	    k++;
    }
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
    int largest=root;
    int l=2*root+1;
    int r=2*root+2;
    if(l<heapSize && data[l]>data[root]) largest=l;
    else largest=root;
    if(r<heapSize && data[r]>data[largest]) largest=r;
    if(largest!=root){
	    swap(data[root], data[largest]);
	    MaxHeapify(data, largest);
    }
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
    for(int i=heapSize/2-1;i>=0;i--) MaxHeapify(data, i);
}
