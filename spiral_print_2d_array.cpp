#include<iostream>
#include<vector>

using namespace std;

vector<int> printSpiral(vector<vector<int>> v){
    int row= v.size();
    int col = v[0].size();
    int total = row*col;
    int count=0;

    int startingRow =0;
    int startingCol =0;
    int endingCol =col-1;
    int endingRow =row-1;

    vector<int> ans ;
    while(count<total){
        //Starting Row
        for(int index=startingCol;index<=endingCol && count<total ;index++){
            ans.push_back(v[startingRow][index]);
            count++;
        }
        startingRow++;

        //Ending col
        for(int index=startingRow;index<=endingRow && count<total ;index++){
            ans.push_back(v[index][endingCol]);
            count++;
        }
        endingCol--;
        
        //Ending ROw
        for(int index = endingCol;index>=startingCol && count<total ;index--){
            ans.push_back(v[endingRow][index]);
            count++;
        }
        endingRow--;

        //starting col
        for(int index=endingRow;index>=startingRow && count<total ;index--){
            ans.push_back(v[index][startingCol]);
            count++;
        }
        startingCol++;


    }
    return ans;

}
int main(){
vector<vector<int>> v = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

vector<int> ans = printSpiral(v);

for(auto i: ans){
    cout<<i<<" ";
}


return 0;
}