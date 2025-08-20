#include<bits/stdc++.h>
#include "sll.h"
using namespace std;
int st[10];

//using arrays
class stImpl1{
    int topidx = -1;
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
    int top(){
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
    int top=0;
    for(int i=0;i<10;i++){
        st.push(arr[i]);
        top++;
    }
    for(int i=0;i<10;i++){
        int k=st.top();
        arr[i]=k;
        st.pop();
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
    int top(){
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

//for strings 
class stImpl4{
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
    int top(){
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
    bool ispalin(){
        node* head2=rev(head);
        node* temp1=head;
        node* temp2=head2;
        while(temp1 && temp2){
            if(temp1->data!=temp2->data) return false;
        }
        return true;
    }


};


int main(){
    // int arr[] = {2, 4, 5, 68, 1,6,5,7,9,10};
    // stImpl1 st;
    // for(auto i: arr){
    //     st.push(i);
    // }
    // rev_arr(arr);
    // for(auto i:arr) cout<<i<<" ";
    // st.print();
    char arr[]={'a','f','g','g','f','a'};
    stImpl4 st;
    for(auto i:arr) st.push(i);
    st.ispalin();

}