#include <iostream>
using namespace std;

int main() {
int t;
cin >> t;
int l1,l2,l3,b1,b2,b3;
for(int i = 0; i < t; i++) {
  cin>>l1>>b1>>l2>>b2>>l3>>b3;
  if(l1==l2==l3 && b1+b2+b3==l1) cout<<"yes\n";
  else if(l1==b1 &&l2==b2 && l3==b3) cout<<"no\n";
  
}
    return 0;
}