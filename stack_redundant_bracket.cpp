#include<iostream>
#include<stack>

using namespace std;

bool is_redundant_bracket(string str){
    stack<int> st;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
            st.push(ch);
        else{
            if(ch==')'){
                bool isRedundant = true;
                while(st.top()!='('){
                    char top = st.top();
                    if(top=='+' || top=='-' || top=='*' || top=='/'){
                        isRedundant=false;
                    }
                    st.pop();
                }
                if(isRedundant==true)
                    return true;
                st.pop();
                
            }
            
        }
    }
    return false;
}
int main(){
string str = "((a+b))";

if(is_redundant_bracket(str)){
    cout<<"Redundant Brackets"<<endl;
}
else{
    cout<<"NOt Redundant Brackets"<<endl;
}
return 0;
}