#include <bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node* next;
    node* back;

    node(int data1,node* next1, node* prev1){
        data=data1;
        next=next1;
        back=prev1;
    }

    node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

node* convert(vector<int> & arr){
    node* head=new node(arr[0]);
    node* prev=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        temp->back=prev;
        prev->next=temp;
        temp=temp->next;
        prev=prev->next;
    }
    return head;
}

void print(node* head){ //TC=O(n)
    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int length(node* head){ //TC=O(n)
    int len=0;
    node* temp=head;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}

bool isempty(node* head){//TC=O(1)
    if(head==nullptr) return 1;
    else return 0;
}

node* del_head(node * head){ //TC=O(1)
    if(head==nullptr)return nullptr;
    node * temp=head;
    head=head->next;
    head->back=nullptr;
    delete(temp);
    temp=nullptr;
    return head;
}

node * del_tail(node* head){ //TC=O(n)
    if(head==nullptr||head->next==nullptr) return head;
    node* temp=head;
    node* mover=temp->next;
    while((temp->next)->next!=nullptr){
        temp=temp->next;
        mover=mover->next;
    }
    temp->next=nullptr;
    mover->back=nullptr;
    delete(mover);
    mover=nullptr;
    return head;
}

node* del_mid (node* head, int k){ //TC=O(n) worst case 
    if(head==nullptr || head->next==nullptr) return nullptr;
    else if(length(head)<k) return nullptr;
    node* temp=head;
    int i=1;
    while(i<k){
        temp=temp->next;
        i++;
    }
    if(i==1){
        (temp->next)->back=nullptr;
        head=temp->next;
        temp->next=nullptr;
        delete(temp);
        temp=nullptr;
        return head;
    }

    else if(i==k){
        (temp->back)->next=nullptr;
        temp->back=nullptr;
        delete(temp);
        temp=nullptr;
        return head;
    }

    (temp->next)->back=temp->back;
    (temp->back)->next=temp->next;
    delete(temp);
    temp=nullptr;
    return head;
}

node* del_val(node* head, int k){ //TC=O(n) worst case 
    node*temp=head;
    if(k==head->data) {
        head=del_head(head);
        return head;
    }
    while(temp->next!=nullptr){
        node*mover=temp->next;
        if(mover->data==k){
            temp->next=mover->next;
            (mover->next)->back=temp;
            delete mover;
            mover=nullptr;
            return head;
        }
        temp=temp->next;
    }
    return head;
}

node* ins_beg(node* head,int k){ //TC=O(1)
    node* temp=new node(k);
    temp->next=head;
    head->back=temp;
    head=temp;
    return head;
}

node* ins_end(node* head,int k){ //TC=O(n)
    node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    node* add=new node(k);
    temp->next=add;
    add->back=temp;
    return head;
}

node* ins_mid(node* head, int k,int n){ //TC=O(n) worst case
    node* temp=head;
    int i=1;
    if(k>length(head)) return head;
    while(temp->next!=nullptr){
        if(i==k){
            node* add=new node(n);
            (temp->back)->next=add;
            add->back=temp->back;
            add->next=temp;
            temp->back=add;
            return head;
        }
        temp=temp->next;
        i++;
    }

}

int search(node* head,int k){ //TC=O(n)
    node* temp=head;
    int i=1;
    while(temp){
        if(temp->data==k) return i;
        i++;
        temp=temp->next;
    }
    return 0;
}

node* merge(node* head1, node* head2){ //TC=O(n)
    node* temp=head1;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=head2;
    head2->back=temp;
    return head1;
}

node* sort(node* head){ //TC=O(n square)
    node* temp=head;
    while(temp){
        node*mover=temp;
        while(mover){
            if(mover->data<temp->data){
                int x=0;
                x=mover->data;
                mover->data=temp->data;
                temp->data=x;
            }
            mover=mover->next;
        }
        temp=temp->next;
    }
    return head;
}

void print_rev(node* head){ //TC=O(2n)
    node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->back;
    }
}

int main() {
    vector<int> arr={6,8,2,4,1,5,3};
    vector<int> vec{9,5,4,2,3};
    node* head1=new node(arr[0]);
    node* head2=new node (vec[0]);
    head1= convert(arr);
    head2= convert(vec);
    // int k;
    // cin>>k;
    // int n;
    // cin>>n;
    // head1=sort(head1);
    // head2=sort(head2);
    // print(head1);
    // print_rev(head2);
    node* head=del_val(head2,3);
    print(head);
}