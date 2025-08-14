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

node* convert(vector<int> &arr){
    node* head=new node(arr[0]);
    node* temp=head;
    for(int i=1;i<arr.size();i++){
        node* mover=new node(arr[i]);
        temp->next=mover;
        temp=temp->next;
    }
    temp->next=head;
    return head;
}

void print(node* head){
    node* temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
}

int length(node* head){ //TC=O(n)
    node* mover=head;
    int len=1;
    while(mover->next!=head){
        len++;
        mover=mover->next;
    }
    return len;
}

node* ins_beg(node* head, int k){ //TC=O(1)
    node* temp=new node(k);
    node* mover=head;
    while(mover->next!=head){
        mover=mover->next;
    }
    mover->next=temp;
    temp->next=head;
    head=temp;    
    return head;
}

node* ins_end(node* head, int k){ //TC=O(n)
    node* temp=new node(k);
    node* mover=head;
    while(mover->next!=head){
        mover=mover->next;
    }
    temp->next=head;
    mover->next=temp;
    return head;
}

node* ins_mid(node* head, int k, int n){ //TC=O(n) worst case
    node* temp=new node(k);
    int len=length(head);
    node* mover=head;
    if(n%len==1) {
        head=ins_beg(head,k);
        return head;
    }

    else if(n%len==0){
        head=ins_end(head,k);
        return head;
    }

    int i=1;
    while(mover->next!=head){
        if(i==n%len-1) break;
        mover=mover->next;
        i++;
    }
    temp->next=mover->next;
    mover->next=temp;
    return head;
}

node* del_beg(node* head){ //TC=O(n)
    if(head->next==head) return head;
    node* temp=head;
    node* mover=head;
    while(mover->next!=head){
        mover=mover->next;
    }
    mover->next=temp->next;
    head=temp->next;
    temp->next=nullptr;
    delete temp;
    return head;
}

node* del_end(node* head){ //TC=O(n)
    node* temp=head;
    node* mover=head;
    while((mover->next)->next!=head){
        mover=mover->next;
    }
    mover->next=temp;
    return head;
}

node* del_mid(node* head, int k){ //TC=O(n) worst case
    int len=length(head);
    if(k%len==1){
        head=del_beg(head);
        return head;
    }
    else if(k%len==0){
        head=del_end(head);
        return head;
    }
    int i=1;
    node* temp=head;
    while((temp->next)->next!=head){
        node* mover=temp->next;
        if(i==k%len-1){
            temp->next=mover->next;
            delete mover;
            return head;
        }
        temp=temp->next;
        i++;
    }
    return nullptr;
}

node* del_val(node* head, int k){ //TC=O(n) worst case
    node* temp=head;
    while(temp->next!=head){
        node* mover=temp->next;
        if(mover->data==k){
            temp->next=mover->next;
            delete(mover);
            return head;
        }
        temp=temp->next;
    }
    node* mover=head;
    temp->next=mover->next;
    head=mover->next;
    delete(mover);
    return head;
}

int search(node* head, int k){ //TC=O(n)
    node* temp=head;
    int i=1;
    while(temp->next!=head){
        if(temp->data==k){
            return i;
        }
        temp=temp->next;
        i++;
    }
    int len=length(head);
    return len;
}

node* merge(node* head1,node* head2){ //TC=O(n)
    node* temp1=head1;
    while(temp1->next!=head1){
        temp1=temp1->next;
    }
    temp1->next=head2;
    node* temp2=head2;
    while(temp2->next!=head2){
        temp2=temp2->next;
    }
    temp2->next=head1;
    return head1;
}

node* sort(node* head){ //TC=O(n square)
    if(head->next==head || head==nullptr) return head;

    node* temp=head;
    while(temp->next!=head){
        node* mover=temp->next;
        while(mover!=head){
            if(mover->data<temp->data){
                int x=mover->data;
                mover->data=temp->data;
                temp->data=x;
            }
            mover=mover->next;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={5,2,4,9,7,3};
    vector<int> vec={3,7,8,4,5};
    node* head1=new node(arr[0]);
    head1=convert(arr);
    node* head2=new node(vec[0]);
    head2=convert(vec);
    // node* head=merge(head1,head2);
    head1=sort(head1);
    head2=sort(head2);
    print(head2);
}