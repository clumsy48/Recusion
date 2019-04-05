#include <iostream>
#include <climits>
#include <map>
using namespace std;
map<pair<int,int>,int > mymap;
map<pair<int,int>,int > path;
int mat(int arr[],int start,int end){
    if(end<=start){
       // cout << "min " << start+1 << " " << end+1 << " " << 0 << endl;
        mymap[{start,end}] = 0;
        return mymap[{start,end}];
    } 
    if(start+1==end){
       // cout << "min " << start+1 << " " << end+1 << " " <<arr[start] * arr[end] * arr[end+1] << endl;
        mymap[{start,end}] = arr[start] * arr[end] * arr[end+1];
        path[{start,end}] = end;
        return mymap[make_pair(start,end)] ; 
    } 
    if(mymap.find(make_pair(start,end))!=mymap.end()){
        return mymap[{start,end}];
    }
    int j,minValue = INT_MAX;
    for(int i = end-1 ; i>=start ; i--){
        int localmin = mat(arr,start,i) + mat(arr,i+1,end) + arr[start]*arr[i+1]*arr[end+1];
        if( localmin < minValue){
            minValue =localmin;
            path[{start,end}] = i+1;
        }
   //   cout << start+1 << " " << end+1 << " " << minValue << endl;
    }
    
  //  cout << "min " << start+1 << " " << end+1 << " " <<minValue << endl;
    mymap[make_pair(start,end)] = minValue ;
    return mymap[make_pair(start,end)];
}
int main(){
   int arr[] = {5,4,6,2,7} ; 
   cout << mat(arr,0,sizeof(arr)/sizeof(arr[0])-2) << endl;
   string s = "" ; 
   for(int i=1;i<=4;i++){
       s = s + to_string(i);
   }
   for(auto i = path.rbegin();i!=path.rend();++i){
       cout <<(*i).first.first+1  << " " << (*i).first.second+1 << " "<< (*i).second << endl;
   }
  return 0;
}
