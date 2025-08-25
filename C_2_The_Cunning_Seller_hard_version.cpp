#include <bits/stdc++.h>
using namespace std;

vector<long long> sum_of_pow(long long n){
    vector<long long> coeff;
    int k=1;
    while(n>=k){
        k=k*3;
    }
    k=k/3;
    while(k>=1){
        coeff.push_back(n/k);
        n=n%k;
        k=k/3;
    }
    reverse(coeff.begin(),coeff.end());
    return coeff;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        
    }
    return 0;
}