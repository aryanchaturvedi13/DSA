#include<bits/stdc++.h>
#include "sll.h"
using namespace std;
int st[10];

//using arrays
class stImpl1{
    int topIdx = -1;
public:
    void print(){
        int i=topIdx;
        while(i>=0){
            cout<<st[i]<<" ";
            i--;
        }
    }
    void push(int x){
        topIdx = topIdx + 1;
        st[topIdx] = x;
    }
    int peek(){
        if(topIdx == -1) return 0;
        return st[topIdx];
    }
    int size(){
        return topIdx + 1;
    }
    void pop(){
        topIdx = topIdx - 1;
    }
    bool isempty(){
        for(auto i:st){
            if(i!=0) return 1;
        }
        return 0; 
    }
    bool isfull(){
        int n=sizeof(st[n])/sizeof(st[0]);
        if(n==10) return 1;
        else return 0;
    }
};

void rev_arr(int arr[]){
    stImpl1 st;
    for(int i=0;i<10;i++){
        st.push(arr[i]);
    }
    int top=-1;
    for(auto i:st){
        top++;
    }


}


//using vector
class stImpl2{
    int topidx=-1;
    vector<int> st;
public:
    void print(){
        int i=topidx;
        while(i>=0){
            cout<<st[i]<<" ";
            i--;
        }
    }
    void push(int x){
        st.push_back(x);
        topidx=topidx+1;
    }
    int peek(){
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
    node* high=new node(0);
    node* head=high;
public:
    void printst(){
        head=rev(head);
        node* temp=head;
        while(temp->next!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    bool isempty(){
        if(head==nullptr) return 1;
        else return 0;
    }
    void push(int x){
        node* temp=new node(x);
        high->next=temp;
        high=high->next;
    }
    int peek(){
        if(head==nullptr) return 0;
        return high->data;
    }
    int size(){
        if(head==nullptr) return 0;
        node* temp=head;
        int i=1;
        while(temp){
            i++;
            temp=temp->next;
        }
        return i;
    }
    void pop(){
        node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        node* mover=high;
        high=temp;
        delete mover;
        mover=nullptr;
    }


};


int main(){
    int arr[] = {2, 4, 5, 68, 1,6};
    stImpl1 st;
    for(auto i: arr){
        st.push(i);
    }
    // st.rev_arr();
    st.print();
}