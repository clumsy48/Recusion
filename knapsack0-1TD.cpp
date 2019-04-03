//knapsack
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
map<pair<int,int>,int > mymap;
int maxValue(int value[],int weight[],int n,int kw){
    if(n<=0) return 0;
    if(kw<0) return 0;
    if(mymap.find(make_pair(n,kw))!=mymap.end()){
        return mymap[{n,kw}];
    }
    int x=0,y=0;
    if(weight[n-1]<=kw){
        
          x = maxValue(value,weight,n-1,kw-weight[n-1])+value[n-1];
       
          y = maxValue(value,weight,n-1,kw);
          mymap[{n,kw}] =  max(x,y);
          return mymap[{n,kw}];
    } 
    mymap[{n,kw}] = maxValue(value,weight,n-1,kw);
    return mymap[{n,kw}];
}
int main()
{
    int weight[] = {1,2,3,2,2};
    int value[] = {8,4,0,8,3}; 
    int kw = 4;
    cout << maxValue(value,weight,5,kw) << endl;
    return 0;
}
