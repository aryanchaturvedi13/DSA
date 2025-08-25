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
        long long n;
        cin>>n;
        vector<long long>coeff;
        coeff=sum_of_pow(n);
        long long cost=0;
        for(int i=0;i<coeff.size();i++){
            long long pow3_i_plus_1 = (long long)pow(3, i+1);
            long long pow3_i_minus_1 = (i-1 >= 0) ? (long long)pow(3, i-1) : 1;
            long long k = pow3_i_plus_1 + i * pow3_i_minus_1;
            cost += coeff[i] * k;
        }
        cout<<cost<<endl;
    }
    return 0;
}