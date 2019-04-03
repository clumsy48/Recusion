//knapsack
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;
map<pair<int,int>,int > mymap;
set<int> myset;
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
void printStones(int weight[],int kw,int n){
     int i,j;
    for(i=n,j=kw;i>=0,j>=0;){
        int x = mymap[{i,j}];
        int y = mymap[{i-1,j}];
        int z = mymap[{i,j-1}];
       // cout << "i "<< i << " " <<" j " << j << endl;
     //   cout << "x " << x << " y " << y << " z " << z << endl; 
        if(y==z && y==0){ //base case when no up and left exists
            if(x!=0){
                myset.insert(i); // last value
//cout << i << "\n";
            } 
            break; 
        }if(y==z){
            if(x>y){
                myset.insert(i);
//cout << i << "\n";
                j = j-weight[i-1];
            } 
            j--; // can up down or left {here , going up}
        }else if(y>z){
            if(x>y){
                 myset.insert(i);
               //  cout << i << "\n";
                 j = j-weight[i-1]; // decrease bag size and go up
            }else i--; // go left
            
        }else if(y<z){
            if(x>z){
                myset.insert(j);
             // cout << j << "\n"; 
              j = j-weight[i-1]; // decrease bag size and decrease bag size
            }else j--; // go up
        }
    }
}
int main()
{
    int weight[] = {1,2,3,2,2};
    int value[] = {8,4,0,8,0}; 
    int kw = 4;
    int n = sizeof(value)/sizeof(int);
    cout << "maxValue " << maxValue(value,weight,n,kw) << endl;
  //  for(auto i=mymap.begin();i!=mymap.end();++i) cout << (*i).first.first <<" " << (*i).first.second << " " << (*i).second << endl;
    printStones(weight,kw,n);
    for(auto i=myset.begin();i!=myset.end();++i) cout << *i << " ";
    return 0;
}
