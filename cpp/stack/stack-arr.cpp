#include<bits/stdc++.h>
using namespace std;

//using arrays
class stImpl{
    int topidx = -1;
    int st[10];
public:
    void print(){
        int i=topidx;
        while(i>=0){
            cout<<st[i]<<" ";
            i--;
        }
    }
    void push(int x){
        topidx = topidx + 1;
        st[topidx] = x;
    }
    int peek(){
        if(topidx == -1) return 0;
        return st[topidx];
    }
    int size(){
        return topidx + 1;
    }
    void pop(){
        topidx = topidx - 1;
    }
    bool isempty(){
        if(size()!=10) return 1;
        else return 0;
    }
    bool isfull(){
        if(size()<10) return 0;
        else if(size()==10) return 1;
    }
};





void rev_arr(int arr[]){
    stImpl st;
    int top=0;
    for(int i=0;i<10;i++){
        st.push(arr[i]);
        top++;
    }
    for(int i=0;i<10;i++){
        int k=st.peek();
        arr[i]=k;
        st.pop();
    }
}

//using vector
// class stImpl2{
//     int topidx=-1;
//     vector<int> st;
// public:
//     void print(){
//         int i=topidx;
//         while(i>=0){
//             cout<<st[i]<<" ";
//             i--;
//         }
//     }
//     void push(int x){
//         st.push_back(x);
//         topidx=topidx+1;
//     }
//     int top(){
//         if(topidx==-1) return 0;
//         return st[topidx];
//     }
//     int size(){
//         if(topidx==-1) return 0;
//         return topidx+1;
//     }
//     void pop() {
//         if(topidx==-1) return;
//         topidx=topidx-1;
//     }
// };

int main(){
    int arr[] = {2, 4, 5, 68, 1,6,5,7,9,10};
    stImpl st;
    for(auto i: arr){
        st.push(i);
    }
}