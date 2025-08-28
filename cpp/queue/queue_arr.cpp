#include <bits/stdc++.h>
using namespace std;

class qImptl{
    int q[15];
    int size=0;
    int head=0;
    int length(){
        return size;
    }
public:
    void enqueue(int k){
        if(size>=15){
            cout<<"array full";
            return;
        }
        q[size]=k;
        size++;
    }
    void dequeue(){
        if(size==0){
            cout<<"array empty";
            return;
        }
        head++;
    }
    void peek(){
        cout<<q[head]<<endl;
    }
    void display(){
        for(int i=head;i<size;i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
    bool isempty(){
        if(size==0) return true;
    }
    bool isfull(){
        if(size==15) return true;
    }
};



int main(){
    int arr[]={5,8,6,1,2,3,1,4};
    qImptl q;
    for(auto i:arr) q.enqueue(i);
    q.display();
    q.peek();
    q.dequeue();
    q.display();
    q.peek();
    return 0;
}