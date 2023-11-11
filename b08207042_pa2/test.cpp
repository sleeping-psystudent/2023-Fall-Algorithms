#include <iostream>
#include <vector>
using namespace std;

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
    vector<vector<int>> table(n, vector<int>(n, 0));
	int j, k;
	int sub;
    for(sub=1;sub<n;sub++){
        i=0;
        j=i+sub;
        while(j<n){
            k=data[j];
            table[i][j]=table[i][j-1];
        	//cout<<i<<","<<j<<","<<k<<" ";
            //case 1: k>j>i or j>i>k
            if(k>j || i>k){
                MIS[i][j]=MIS[i][j-1];
            }
            //case 2: j>k>i
            else if(j>k && k>i){
                MIS[i][j]=MIS[i][k-1]+1+MIS[k+1][j-1];
                table[i][j]=k; //Case 2的table應該不是這個
            }
            //case 3: k==i
            else if(k==i){
                MIS[i][j]=MIS[i+1][j-1]+1;
                table[i][j]=i;
            }
            i++;
            j++;
        }
        //cout<<endl;
    }
    
    /*
    cout<<MIS[0][n-1]<<endl;
    for(j=0;j<n;j++){
        for(i=0;i<n;i++) cout<<MIS[i][j]<<" ";
        cout<<endl;
    }*/

    cout<<table[0][n-1]<<endl;
    for(j=0;j<n;j++){
        for(i=0;i<n;i++) cout<<table[i][j]<<" ";
        cout<<endl;
    }
}