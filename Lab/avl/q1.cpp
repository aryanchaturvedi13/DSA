#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        int balanceFactor;
        int height;
        Node* left;
        Node* right;
    Node(int val){
        this->val=val;
        this->balanceFactor=0;
        this->height=1;
        this->left=nullptr;
        this->right=nullptr;
    }
};

class AVLTree{
    private:
        Node* root=nullptr;

        int height(Node* n){
            return n ? n->height : 0;
        }

        int updateHeights(Node* n){
            if(!n) return 0;
            int lh = height(n->left);
            int rh = height(n->right);
            n->height = max(lh,rh) + 1;
            n->balanceFactor = rh - lh;
            return n->height;
        }

        Node* rightRotation(Node* y){
            Node* x = y->left;
            Node* T2 = x->right;
            x->right = y;
            y->left = T2;
            updateHeights(y);
            updateHeights(x);
            return x;
        }

        Node* leftRotation(Node* x){
            Node* y = x->right;
            Node* T2 = y->left;
            y->left = x;
            x->right = T2;
            updateHeights(x);
            updateHeights(y);
            return y;
        }

        Node* rebalance(Node* node){
            if(!node) return node;
            updateHeights(node);
            if(node->balanceFactor < -1){ 
                if(node->left && node->left->balanceFactor > 0){
                    node->left = leftRotation(node->left);
                }
                return rightRotation(node);
            }else if(node->balanceFactor > 1){ 
                if(node->right && node->right->balanceFactor < 0){
                    node->right = rightRotation(node->right);
                }
                return leftRotation(node);
            }
            return node;
        }

        Node* insertNode(Node* node, int val){
            if(!node) return new Node(val);
            if(val < node->val) node->left = insertNode(node->left, val);
            else if(val > node->val) node->right = insertNode(node->right, val);
            else return node;
            return rebalance(node);
        }

        Node* minValueNode(Node* node){
            Node* cur = node;
            while(cur && cur->left) cur = cur->left;
            return cur;
        }

        Node* maxValueNode(Node* node){
            Node* cur = node;
            while(cur && cur->right) cur = cur->right;
            return cur;
        }

        Node* deleteNode(Node* node, int val){
            if(!node) return node;
            if(val < node->val) node->left = deleteNode(node->left, val);
            else if(val > node->val) node->right = deleteNode(node->right, val);
            else{
                if(!node->left || !node->right){
                    Node* temp = node->left ? node->left : node->right;
                    if(!temp){
                        temp = node;
                        node = nullptr;
                    }else{
                        *node = *temp;
                    }
                    delete temp;
                }else{
                    Node* temp = minValueNode(node->right);
                    node->val = temp->val;
                    node->right = deleteNode(node->right, temp->val);
                }
            }
            if(!node) return node;
            return rebalance(node);
        }

        bool searchNode(Node* node, int val){
            if(!node) return false;
            if(node->val == val) return true;
            if(val < node->val) return searchNode(node->left, val);
            return searchNode(node->right, val);
        }

        Node* findNode(Node* node, int val){
            if(!node) return nullptr;
            if(node->val == val) return node;
            if(val < node->val) return findNode(node->left, val);
            return findNode(node->right, val);
        }

        void inorder(Node* node){
            if(!node) return;
            inorder(node->left);
            cout<<node->val<<" ";
            inorder(node->right);
        }

        void preorder(Node* node){
            if(!node) return;
            cout<<node->val<<" ";
            preorder(node->left);
            preorder(node->right);
        }

        void postorder(Node* node){
            if(!node) return;
            postorder(node->left);
            postorder(node->right);
            cout<<node->val<<" ";
        }

        void levelorder(Node* node){
            if(!node) return;
            queue<Node*> q;
            q.push(node);
            while(!q.empty()){
                Node* cur=q.front(); q.pop();
                cout<<cur->val<<" ";
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }

        void rangeUtil(Node* node, int L, int R){
            if(!node) return;
            if(L < node->val) rangeUtil(node->left, L, R);
            if(L <= node->val && node->val <= R) cout<<node->val<<" ";
            if(R > node->val) rangeUtil(node->right, L, R);
        }

    public:
        void insertValue(int val){
            root = insertNode(root, val);
        }

        void deleteValue(int val){
            root = deleteNode(root, val);
        }

        bool searchValue(int val){
            return searchNode(root, val);
        }

        int findPredecessor(int value){
            Node* cur = root;
            Node* predecessor = nullptr;
            while(cur){
                if(value > cur->val){
                    predecessor = cur;
                    cur = cur->right;
                }else if(value < cur->val){
                    cur = cur->left;
                }else{
                    if(cur->left) predecessor = maxValueNode(cur->left);
                    break;
                }
            }
            if(!predecessor) throw runtime_error("No predecessor");
            return predecessor->val;
        }

        int findSuccessor(int value){
            Node* cur = root;
            Node* successor = nullptr;
            while(cur){
                if(value < cur->val){
                    successor = cur;
                    cur = cur->left;
                }else if(value > cur->val){
                    cur = cur->right;
                }else{
                    if(cur->right) successor = minValueNode(cur->right);
                    break;
                }
            }
            if(!successor) throw runtime_error("No successor");
            return successor->val;
        }

        void printInorder(){
            inorder(root);
            cout<<"\n";
        }

        void printPostorder(){
            postorder(root);
            cout<<"\n";
        }

        void printPreorder(){
            preorder(root);
            cout<<"\n";
        }

        void printLevelorder(){
            levelorder(root);
            cout<<"\n";
        }

        void getRange(int L, int R){
            rangeUtil(root, L, R);
            cout<<"\n";
        }
};
int main() {
    AVLTree t;

    t.insertValue(44);
    t.insertValue(17);
    t.insertValue(78);
    t.insertValue(32);

    t.printInorder(); 

    if(t.searchValue(50)) cout<<50<<"\n";
    else cout<<"NOTFOUND\n"; 
    t.insertValue(50);

    try{ cout<<t.findPredecessor(50)<<"\n"; } 
    catch(exception &e){ cout<<e.what()<<"\n"; }

     cout<<t.findSuccessor(50)<<"\n"; 

    int count=0;
    for(int i=18;i<=60;i++) if(t.searchValue(i)) count++;
    cout<<count<<"\n";

    t.deleteValue(44);

    t.printLevelorder(); 

    return 0;
}
