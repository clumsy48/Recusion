//knapsack
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int maxValue(int value[],int weight[],int n,int kw){
    if(n<=0) return 0;
    if(kw<0) return 0;
    
    if(weight[n-1]<=kw)
       return max(maxValue(value,weight,n-1,kw-weight[n-1])+value[n-1],maxValue(value,weight,n-1,kw));
    else return maxValue(value,weight,n-1,kw);
}
int main()
{
    int value[] = {60,100,120};
    int weight[] = {10,20,30}; 
    int kw = 50;
    cout << maxValue(value,weight,3,kw) << endl;
    return 0;
}
