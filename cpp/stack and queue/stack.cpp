#include<bits/stdc++.h>
#include "ll.h"
using namespace std;

//using arrays
class stImpl1{
    int topIdx = -1;
    int st[10];
public:
    void push(int x){
        topIdx = topIdx + 1;
        st[topIdx] = x;
    }
    int top(){
        if(topIdx == -1) return 0;
        return st[topIdx];
    }
    int size(){
        return topIdx + 1;
    }
    void pop(){
        topIdx = topIdx - 1;
    }
};

//using vector
class stImpl2{
    int topidx=-1;
    vector<int> st;
public:
    void push(int x){
        st.push_back(x);
        topidx=topidx+1;
    }
    int top(){
        if(topidx==-1) return 0;
        return st[topidx];
    }
    int size(){
        if(topidx==-1) return 0;
        return topidx+1;
    }
    void pop() {
        if(topidx==-1) return;
        topidx=topidx-1;
    }
};

//using linkedlists
class stImpl3{
    int topidx=-1;





};


int main(){
    int arr[] = {2, 4, 5, 68, 1,6};
    stImpl2 st;
    for(auto i: arr){
        st.push(i);
    }
    cout << st.top();
}