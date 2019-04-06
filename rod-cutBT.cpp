/******************************************************************************
rod - cutting
length of ROD - n

*******************************************************************************/
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;
int solve(int arr[],int n,int len){ 
    vector<int> vi(len+1);
    vector<vector<int> > val(n+1,vi);
    for(int i=0;i<n+1;++i) val[i][0] = 0;
    for(int i=0;i<len+1;++i) val[0][i] = 0;
    //val jth column length 0f available rod , ith row avaialblae piece  
    for(int i=1;i<=n;++i){  // 
        //int curMax = INT_MIN;
        for(int j=1;j<=len;++j){ // length 0f current rod
            if(i<=j){
                val[i][j] = max(arr[i-1]+val[i][j-i],val[i-1][j]);
            }else{
                val[i][j] = val[i-1][j];
            }
        }
        
    }
    return val[n][len];
}

int main()
{
    int arr[] = {2,5,7,8};
    int n = sizeof(arr)/sizeof(int);
    int len = 5;
    cout << solve(arr,n,len) << endl;

    return 0;
}
