#include <bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node*next;
    
    node (int data1, node*next1){
        data=data1;
        next=next1;
    }

    node (int data1){
        data=data1;
        next=nullptr;
    }
};

node* convert(vector<int> &arr){ //TC=O(n)
    node*head =new node(arr[0]);
    node*mover=head;
    for(int i=1;i<arr.size();i++){
        node*temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head; 
}

void print(node*head){ //TC=O(n)
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    vector<int> arr={2,4,5};
    vector<int> vec={1,2,4};
    node* head1=new node(arr[0]);
    node* head2=new node(vec[0]);
    head1=convert(head1);
    head2=convert(head2);
}