#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


int max_freq(vector<int> a){
    unordered_map<int,int> m;
    int maxFreq=0;
    int maxans=0;
    for(int i=0;i<a.size();i++){
        m[a[i]]++;
        maxFreq = max(m[a[i]],maxFreq);

    }
    for(int i=0;i<a.size();i++){
        if(maxFreq==m[a[i]]){
            maxans=a[i];
            break;
        }
    }
    return maxans;
}

int main(){
vector<int> a = {1,2,3,4,1,2,1,4,4,4};

cout<<max_freq(a)<<endl;


return 0;
}