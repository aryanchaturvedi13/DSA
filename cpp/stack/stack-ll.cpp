#include<bits/stdc++.h>
#include "sll.h"

//using linkedlists
template<typename T>
class stImpl{
    node<T>* high=new node<T>(T());
    node<T>* head=high;
public:
    void print(){
        head=rev(head);
        node<T>* temp=head;
        while(temp->next!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        head=rev(head);
    }
    bool isempty(){
        if(head==nullptr) return 1;
        else return 0;
    }
    void push(T x){
        node<T>* temp=new node<T>(x);
        high->next=temp;
        high=high->next;
    }
    T top(){
        if(head==nullptr) return 0;
        return high->data;
    }
    T size(){
        if(head==nullptr) return 0;
        node<T>* temp=head;
        int i=1;
        while(temp){
            i++;
            temp=temp->next;
        }
        return i;
    }
    void pop(){
        node<T>* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        node<T>* mover=high;
        high=temp;
        delete mover;
        mover=nullptr;
    }
};