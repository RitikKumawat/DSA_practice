#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int main(){
/*
Input {-3,0,1,-3,1,1,1,-3,10,0}
output {true}

explaination
we have elements and their frequencies
        -3                  3
        0                   2
        1                   4
        10                  1

here we can see that the frequencies are unique so return true
otherwise return false
*/
int arr[10]={-3,0,1,-3,1,1,1,-3,10,0};
unordered_map<int,int> mp;
unordered_set<int> set;
for(auto num:arr){
    mp[num]++;
}
for(auto it:mp){
    int freq = it.second;
    set.insert(freq);
}
if(set.size()==mp.size()){
    cout<<"True"<<endl;
}
else{
    cout<<"False"<<endl;
}
return 0;
}