#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;


int minimumParentheses(string pattern) {
    // Write your code here.
    // pattern is the given string.
    stack<char> st;
    st.push(pattern[0]);
    for(int i=1;i<pattern.size();i++){
        if(pattern[i]==')' && st.top()=='('){
            st.pop();
        }
        else{
            st.push(pattern[i]);
        }
    }
    return st.size();
    
}

int main(){
string pattern = ")((()";
cout<<minimumParentheses(pattern);


vector<vector<int>> arr = { {1,2,3,4},
                            {2,3,4,5}};



return 0;
}