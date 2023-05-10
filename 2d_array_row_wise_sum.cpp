#include<iostream>
#include<vector>



using namespace std;

//ROw wise
void printSum(vector<vector<int>> v ){
    for(int row=0;row<3;row++){
        int sum=0;
        for(int col=0;col<3;col++){
            sum+= v[row][col];
        }
        cout<<sum<<" ";
    }
}

//Column wise
void PrintCOlwise(vector<vector<int>> v){
    for(int col=0;col<3;col++){
        int sum=0;
        for(int row=0;row<3;row++){
            sum+=v[row][col];
        }
        cout<<sum<<" ";
    }
}

// Maximum row sum 
void largestRowSum(vector<vector<int>> v){
    int maxi = INT_MIN;
    int ans=-1;
    for(int row=0;row<3;row++){
        int sum=0;
        for(int col=0;col<3;col++){
            sum+=v[row][col];
        }
        if(sum>maxi){
            maxi=sum;
            ans = row;
        }
    }
    cout<<"Max Sum:"<<maxi<<" at index:"<<ans<<endl;
}

int main(){

vector<vector<int>> v = {
    {3,4,11},
    {2,12,1},
    {7,8,7}
};

printSum(v);
cout<<endl;
PrintCOlwise(v);
cout<<endl;
largestRowSum(v);
return 0;
}