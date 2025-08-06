#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    int gcd,lcm;
    vector <int> div;

    for(int i=1;i<=min(a,b);i++){
       if(a%i==0 && b%i==0) div.push_back(i);
    }

    gcd=div.back();
    lcm=(a*b)/gcd;
    cout<<"gcd:"<<gcd<<" ,lcm:"<<lcm<<endl;
}