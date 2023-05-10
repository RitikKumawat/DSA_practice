#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> v){
    int s=0;
    int e=v.size()-1;

    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}

vector<int> add(vector<int> a1,int n, vector<int> a2, int m)
{
    vector<int> ans;
    int i=n-1;
    int j=m-1;
    int carry=0;
    while(i>=0 && j>=0){
        int val1 = a1[i];
        int val2 = a2[j];
        int sum = val1+val2+carry;

        carry = sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    //first case
    while(i>=0){
        int sum=a1[i]+carry;
        carry = sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
    }
    // second case
    while(j>=0){
        int sum=a2[j]+carry;
        carry = sum/10;
        sum=sum%10;
        ans.push_back(sum);
        j--;
    }
    // third case
    while(carry!=0){
        int sum=carry;
        carry = sum/10;
        sum=sum%10;
        ans.push_back(sum);
        
    }
return reverse(ans);
}
int main(){
vector<int> a1 = {1,1,3,4};
vector<int> a2 = {1,2,3};

vector<int> c = add(a1,4,a2,3);
for(auto i : c){
    cout<<i<<" ";
}

return 0;
}