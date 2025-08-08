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
    node*head =new node(arr[0]);
    node*mover=head;
    for(int i=1;i<arr.size();i++){
        node*temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head; 
}

int length(node*head){
    node*temp=head;
    int cnt=1;
    while(temp->next!=nullptr){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

node* insert_beg(node* head,int k){
    node*add=new node(k);
    add->next=head;
    head =add;
    return head;
}

node* insert_end(node*head,int k){
    node* add=new node(k);
    node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=add;
    return head;
}

node* insert_pos(node*head, int k, int n){
    int len=length(head);
    if(k>len) return nullptr;
    node*add=new node(k);
    int i=1;
    node*temp=head;
    while(i<n-1){
        temp=temp->next;
        i++;
    }
    add->next=temp->next;
    temp->next=add;
    return head;
}

void print(node*head){
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node*del_beg(node*head){
    if(head==NULL) return nullptr; 
    node*temp=head;
    head=head->next;
    delete temp;
    return head;
}

node*del_end(node*head){
    if(head==nullptr) return nullptr;
    node*temp=head;
    while((temp->next)->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    (temp->next)=nullptr;
    return head;
}

node*del_pos(node*head, int n){
    int len=length(head);
    if(n>len) return head;
    node*temp=head;
    node*mover=temp->next;
    int i=1;
    while(i<n-1){
        temp=temp->next;
        mover=mover->next;
        i++;
    }
    temp->next=mover->next;
    delete mover;
    return head;
}

node*del_ifex(node* head, int n){
    node*temp=head;
    node*mover=temp->next;
    while(temp->next!=nullptr){
        if((temp->next)->data==n){
            temp->next=(temp->next)->next;
            delete mover;
            return head;
        }
        temp=temp->next;
        mover=mover->next;
    }
    return head;
}

node*search(node*head, int n){
    node*temp=head;
    int i=1;
    while(temp->next!=nullptr){
        if(temp->data==n) {
            cout<<i<<" ";
        }
        temp=temp->next;
        i++;
    }
    return head;
}

node*merge(node* head1, node*head2){
    node*temp=head1;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=head2;
    return head1;
}

node*rev(node*head){
    node*temp=head;
    
}

int main(){
    vector<int> arr={5,3,4,8,9,4,1};
    vector<int> vec={4,9,2,3,1};
    node*head1=convert(arr);
    node*head2=convert(vec);
    // int k;
    // int n;
    // cin>>n;
    // head=search(head,k);
    // print(head);
    node* head=merge(head1,head2);
    print(head);
}
