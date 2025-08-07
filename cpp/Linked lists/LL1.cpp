#include<iostream>
#include <vector>
using namespace std;

struct node{
    public:
    int data;
    node* next;

    node (int data1, node* next1){
        data=data1;
        next=next1;
    }
    node(int data1){
        data=data1;
        next=nullptr;
    }
};

node* convert(vector<int>& arr){
    node*head=new node(arr[0]);
    node* mover=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int length(node * head){
    int cnt=0;
    node* temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

int main(){
    vector<int> arr={2,5,8,9,4,1};
    node* head=new node(arr[0]);
    int x=length(head);
    cout<<x;
}