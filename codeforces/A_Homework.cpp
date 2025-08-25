#include <bits/stdc++.h>
using namespace std;


struct node{
    public:
    char data;
    node*next;
    
    node (char data1, node*next1){
        data=data1;
        next=next1;
    }

    node (char data1){
        data=data1;
        next=nullptr;
    }
};

node* convert(string s){
    node*head =new node(s[0]);
    node*mover=head;
    for(char i=1;i<s.size();i++){
        node*temp=new node(s[i]);
        mover->next=temp;
        mover=temp;
    }
    return head; 
}

node* insert_beg(node* head,char k){
    node*add=new node(k);
    add->next=head;
    head =add;
    return head;
}

node* insert_end(node*head,char k){ 
    node* add=new node(k);
    node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=add;
    return head;
}

void print(node*head){
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n,m;
        string a,b,c;
        cin>>n;
        cin>>a;
        cin>>m;
        cin>>b;
        cin>>c;

        node* head=convert(a);
        for(int j=0;j<m;j++){
            if(c[j]=='D'){
                head=insert_end(head,b[j]);
            }
            else if(c[j]=='V'){
                head=insert_beg(head,b[j]);
            }
        }
        print(head);
        delete head;
    }
    return 0;
}