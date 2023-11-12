#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void trace(int, int, int*, vector<int>&, int, vector<vector<int>>, vector<vector<int>>, int**);

int main() {
	int n;
    cin>>n;
    vector<int> data(n, -1);
    int a, b;
    int i;
    for(i=0;i<(n/2);i++){
        cin>>a>>b;
        data[a]=b;
        data[b]=a;
    }
    //for(i=0;i<n;i++) cout<<data[i]<<" ";

	vector<vector<int>> MIS(n, vector<int>(n, 0));
    vector<vector<int>> dirt(n, vector<int>(n, -1));
    vector<vector<int>> table(n, vector<int>(n, -1));
	int j, k;
	int sub;
    for(sub=1;sub<n;sub++){
        i=0;
        j=i+sub;
        while(j<n){
            k=data[j];
        	//cout<<i<<","<<j<<","<<k<<" ";
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
        //cout<<endl;
    }
    
    
    cout<<MIS[0][n-1]<<endl;
    /*for(j=0;j<n;j++){
        for(i=0;i<n;i++) cout<<MIS[i][j]<<" ";
        cout<<endl;
    }

    cout<<dirt[0][n-1]<<endl;
    for(j=0;j<n;j++){
        for(i=0;i<n;i++) cout<<dirt[i][j]<<" ";
        cout<<endl;
    }

    cout<<table[0][n-1]<<endl;
    for(j=0;j<n;j++){
        for(i=0;i<n;i++) cout<<table[i][j]<<" ";
        cout<<endl;
    }*/

    int** result=new int*[(n/2)];
    int* acc=new int;
    *acc=0;
    trace(0, n-1, acc, data, n, dirt, table, result);

    for(i=*acc-1;i>=0;i--) cout<<result[i][0]<<" "<<result[i][1]<<endl;

    for (i=0; i<*acc; i++) {
        delete[] result[i];
    }
    delete[] result;
    delete acc;

}

void trace(int i, int j, int* acc, vector<int>& data, int num, vector<vector<int>> dirt, vector<vector<int>> table, int** result){
    if(table[i][j]==-1) return;
    //cout<<i<<","<<j<<","<<table[i][j]<<","<<dirt[i][j]<<endl;

    int k=data[j];
    //cout<<k<<endl;
    result[*acc]=new int[2];
    result[*acc][0]=k;
    result[*acc][1]=j;
    *acc+=1;

    if(dirt[i][j]==2){
        if(0<=i && i<num && 0<=k-1 && k-1<num) trace(i, k-1, acc, data, num, dirt, table, result);
        if(0<=k+1 && k+1<num && 0<=j-1 && j-1<num) trace(k+1, j-1, acc, data, num, dirt, table, result);
    }
    else if(dirt[i][j]==3){
        if(0<=i+1 && i+1<num && 0<=j-1 && j-1<num) trace(i+1, j-1, acc, data, num, dirt, table, result);
    }
}