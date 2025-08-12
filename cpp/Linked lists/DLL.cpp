#include <bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node* next;
    node* prev;

    node(int data1,node* next1, node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }

    node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};

node* convert(vector<int> &arr){
    node* head=new node(arr[0]);
    node* temp=head;
    node* mover=head->next;
    for(int i=0;i<arr.size();i++){
        temp->data=arr[i];
        mover->prev=temp;
        temp->next=mover;
        cout<<"hi";
        temp=temp->next;
        mover=mover->next;
    }
    return head;
}

void print(node* head){
    node* temp=head;
    while(temp->next!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    vector<int> arr={1,2,3,4,5,6};
    node* head=new node(arr[0]);
    head= convert(arr);
    print(head);
}