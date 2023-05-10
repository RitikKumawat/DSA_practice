#include<iostream>
#include<math.h>
using namespace std;
int main(){
int n;
cout<<"Enter a number you want to convert into binary"<<endl;
cin>>n;
int ans=0;
int rem;
int i=0;
while(n!=0){
    rem=n%2;
    ans+=rem*(pow(10,i));
    n=n/2;
    i++;
}
cout<<ans<<endl;
int m;
cout<<"Enter binary number you want to convert into decimal"<<endl;
cin>>m;
int a=0;
int j=0;
while(m!=0){
    int r=m%10;
    m=m/10;
    a+=r*(pow(2,j));
    j++;
}
cout<<a<<endl;
return 0;
}