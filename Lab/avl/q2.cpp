#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        int height;
        int size;  
        long long sum; 
        int balanceFactor;
        Node* left;
        Node* right;

    Node(int val){
        this->val=val;
        this->height=1;
        this->size=1;
        this->sum=val;
        this->balanceFactor=0;
        this->left=nullptr;
        this->right=nullptr;
    }
};

class AVLTree{
    private:
        Node* root=nullptr;

        int height(Node* n){ return n ? n->height : 0; }
        int getSize(Node* n){ return n ? n->size : 0; }
        long long getSum(Node* n){ return n ? n->sum : 0; }

        void update(Node* n){
            if(!n) return;
            int lh=height(n->left), rh=height(n->right);
            n->height=max(lh,rh)+1;
            n->balanceFactor=rh-lh;
            n->size=getSize(n->left)+getSize(n->right)+1;
            n->sum=getSum(n->left)+getSum(n->right)+n->val;
        }

        Node* rightRotate(Node* y){
            Node* x=y->left;
            Node* T2=x->right;
            x->right=y;
            y->left=T2;
            update(y);
            update(x);
            return x;
        }

        Node* leftRotate(Node* x){
            Node* y=x->right;
            Node* T2=y->left;
            y->left=x;
            x->right=T2;
            update(x);
            update(y);
            return y;
        }

        Node* rebalance(Node* node){
            update(node);
            if(node->balanceFactor < -1){
                if(node->left && node->left->balanceFactor > 0)
                    node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            else if(node->balanceFactor > 1){
                if(node->right && node->right->balanceFactor < 0)
                    node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            return node;
        }

        Node* insertNode(Node* node,int val){
            if(!node) return new Node(val);
            if(val < node->val) node->left = insertNode(node->left,val);
            else if(val > node->val) node->right = insertNode(node->right,val);
            else return node;
            return rebalance(node);
        }

        int rankUtil(Node* node,int x){
            if(!node) return 0;
            if(x <= node->val) return rankUtil(node->left,x);
            else return getSize(node->left)+1+rankUtil(node->right,x);
        }

        int selectUtil(Node* node,int k){
            if(!node) return -1;
            int leftSize=getSize(node->left);
            if(k == leftSize+1) return node->val;
            else if(k <= leftSize) return selectUtil(node->left,k);
            else return selectUtil(node->right,k-leftSize-1);
        }

        long long prefixSum(Node* node,int x){
            if(!node) return 0;
            if(x < node->val) return prefixSum(node->left,x);
            else return getSum(node->left)+node->val+prefixSum(node->right,x);
        }

    public:
        void insertValue(int val){
            root=insertNode(root,val);
        }

        int rankOf(int x){
            return rankUtil(root,x);
        }

        int selectK(int k){
            if(k<=0 || k>getSize(root)) return -1;
            return selectUtil(root,k);
        }

        long long rangeSum(int L,int R){
            long long rSum = prefixSum(root,R);
            long long lSum = prefixSum(root,L-1);
            return rSum - lSum;
        }
};

int main(){
    AVLTree t;
    t.insertValue(5);
    t.insertValue(1);
    t.insertValue(9);
    t.insertValue(3);

    cout<<t.rankOf(4)<<"\n";       
    int sel = t.selectK(3);        
    if(sel==-1) cout<<"INVALID\n";  
    else cout<<sel<<"\n";
    cout<<t.rangeSum(2,8)<<"\n";   

    return 0;
}