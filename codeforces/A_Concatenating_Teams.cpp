#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    cin>>m>>n;
    string A[m];
    string B[n];
    for(int i=0;i<m;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];
    
    vector<string> concat;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            concat.push_back(A[i]+B[j]);
        }
    }
    int st=m+n;
    sort(concat.begin(),concat.end());
    set<string> notpecu;
    for(int i=0;i<concat.size();i++){
        for(int j=0;j<concat.size();j++){
            if(i!=j && concat[i]==concat[j]){
                st-=2;
                notpecu.insert(concat[i]);
            }
        }
    }
    for(int i=0;i<m;i++){
        for(auto j:notpecu){
            if(j.find(A[i])!=string::npos){
                m--;
            }
        }
    }

    cout<<st-m<<" "<<m<<endl;
    return 0;
}