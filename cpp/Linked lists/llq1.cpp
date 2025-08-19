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

node* add(node* head1,node* head2){
    node* t1=head1;
    node* t2=head2;
    node* sum=new node(0);
    node* curr=sum;
    while(t1 && t2){
        int carry=0;
        node* temp=new node((t1->data+t2->data)%10);
        curr->next=temp;
        t1=t1->next;
        t2=t2->next;
        curr=curr->next;

    while(t1){
        node* temp=new node(t1->data);
        curr->next=temp;
        t1=t1->next;
        curr=curr->next;
    }

    while(t2){
        node* temp=new node(t2->data);
        curr->next=temp;
        t2=t2->next;
        curr=curr->next;
    }

    return sum->next;
    }   
}

int main() {
    vector<int> arr={2,4,5};
    vector<int> vec={1,2,4,8};
    node* head1=new node(arr[0]);
    node* head2=new node(vec[0]);
    head1=convert(arr);
    head2=convert(vec);
    
    node* head=add(head1,head2);
    print(head);

}