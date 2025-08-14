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

node* convert(vector<int> &arr){
    node* head =new node(arr[0]);
    node* temp=head;
    for(int i=1;i<arr.size();i++){
        node* mover=new node(arr[i]);
        temp->next=mover;
        mover->back=temp;
        temp=temp->next;
    }
    temp->next=head;
    head->back=temp;
    return head;
}

void print(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

int length(node* head){
    node* mover=head;
    int len=1;
    while(mover->next!=head){
        len++;
        mover=mover->next;
    }
    return len;
}

node* ins_beg(node* head,int k){
    node* temp=new node(k);
    node* mover=head;
    while(mover->next!=head){
        mover=mover->next;
    }
    mover->next=temp;
    temp->next=head;
    head->back=temp;
    temp->back=mover;
    head=temp;
    return head;
}

node* ins_end(node* head, int k){
    node* temp=new node(k);
    node* mover=head;
    while(mover->next!=head){
        mover=mover->next;
    }
    mover->next=temp;
    temp->back=mover;
    temp->next=head;
    head->back=temp;
    return head;
}

node* ins_mid(node* head, int k, int n){
    node* temp=new node(k);
    int i=1;
    int len=length(head);
    node* mover=head;
    if(n%len==0) {
        head=ins_end(head,k);
        return head;
    }
    else if(n%len==1){
        head=ins_beg(head,k);
        return head;
    }
    while(i<n%len-1){
        i++;
        mover=mover->next;
    }

    temp->next=mover->next;
    (mover->next)->back=temp;
    temp->back=mover;
    mover->next=temp;
    return head;
}

node* del_beg(node* head){
    node* temp=head;
    (temp->back)->next=temp->next;
    (temp->next)->back=temp->back;
    head=temp->next;
    temp->back=nullptr;
    temp->next=nullptr;
    delete(temp);
    return head;
}

node* del_end(node* head){
    node* temp=head->back;
    (temp->back)->next=head;
    head->back=(temp->back);
    delete temp;
    return head;
}

node* del_mid(node* head, int k){
    node* temp=head;
    int i=1;
    int len=length(head);
    if(k%len==0){
        head=del_end(head);
        return head;
    }
    else if(k%len==1){
        head=del_beg(head);
        return head;
    }

    while(i<k%len){
        temp=temp->next;
        i++;
    }
    (temp->back)->next=temp->next;
    (temp->next)->back=temp->back;
    delete temp;
    return head;
}

node* del_val(node* head, int k){
    node* temp=head;
    if(temp->data==k){
        head=del_beg(head);
        return head;
    }
    while(temp->next!=head){
        if(temp->data==k){
            (temp->back)->next=temp->next;
            (temp->next)->back=temp->back;
            delete temp;
            return head;
        }
        temp=temp->next;
    }
    
    head=del_end(head);
    return head;
}

int search(node* head,int k){
    if(head==nullptr) return 0;
    node* temp=head;
    int i=1;
    while(temp->next!=head){
        if(temp->data==k) return i;
        i++;
        temp=temp->next;
    }
    if(temp->data==k) return i;
    return 0;
}

node* merge(node* head1, node* head2){
    node* temp1=head1;
    node* temp2=head2;
    while(temp1->next!=head1){
        temp1=temp1->next;
    }
    temp1->next=temp2;
    temp2->back=temp1;
    while(temp2->next!=head2){
        temp2=temp2->next;
    }
    temp2->next=head1;
    head1->back=temp2;
    return head1;
}

void print_rev(node* head){
    node* temp=head;
    do{
        temp=temp->back;
        cout<<temp->data<<" ";
    }while(temp->back!=head->back);
}

node* sort(node* head){
    node* tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    node* temp=head;
    while(temp->next!=tail->next){
        node* mover=temp;
        while(mover!=tail->next){
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

int main() {
    vector<int> arr={2,5,7,6,1,3,4};
    node* head1= new node(arr[0]);
    vector<int> vec={1,2,3,4};
    node* head2=new node(vec[0]);
    head1=convert(arr);
    // head2=convert(vec);
    // head1=merge(head1,head2);
    head1=sort(head1);
    print(head1);    
}