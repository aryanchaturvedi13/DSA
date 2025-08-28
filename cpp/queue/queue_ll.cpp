#include <bits/stdc++.h>
#include "ll.h"

class qImptl{
    node* head=new node(0);
public:
    void enqueue(int k){
        node* mover=head;
        while(mover->next!=nullptr){
            mover=mover->next;
        }
        node* temp=new node(k);
        mover->next=temp;
    }
    void dequeue(){
        head=del_beg(head);
    }
    void peek(){
        cout<<(head->next)->data;
    }
    bool isempty(){
        if(head==nullptr) return true;
        else return false;
    }
    void display(){
        node* temp=head->next;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    int arr[]={5,7,9,6,4,7,2,3,4};
    qImptl q;
    for(auto i:arr) q.enqueue(i);
    q.display();
    q.dequeue();
    q.display();
}