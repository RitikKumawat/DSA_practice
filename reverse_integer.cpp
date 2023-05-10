#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter a number to reverse"<<endl;
cin>>n;
int ans=0;
int rem;
while(n!=0){
    rem=n%10;
    ans=(ans*10)+rem;
    n=n/10;
}
cout<<ans<<endl;
return 0;
}