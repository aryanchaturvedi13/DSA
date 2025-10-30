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

#include <iostream>
int find_gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return find_gcd(b, a % b);
}

int main() {
    int a = 54;
    int b = 24;
    int result = find_gcd(a, b);
    return 0;
}