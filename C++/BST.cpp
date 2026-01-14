#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Tree{
    
public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};

void Display(Tree* root){
    //base case:
    if(root == NULL){
        return;
    }

    Display(root->left);
    cout<<root->data<<" ";
    Display(root->right);

    return;
}

void LevelOrderTraversal(Tree* root){

    queue<Tree*>q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();

        for(int i = 0; i<size; ++i){
            Tree* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }

        cout<<"\n";
    }

}

// Helper function to insert into BST
Tree* insertIntoBST(Tree* root, int val) {
    if (root == NULL) {
        return new Tree(val);
    }

    if (val < root->data) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Convert array to BST
Tree* ArrToBST(vector<int> &v) {
    Tree* root = NULL;
    for (int i = 0; i < v.size(); i++) {
        root = insertIntoBST(root, v[i]);
    }
    return root;
}

int main(){

    // Tree* tree;
    vector<int> v = {50, 20, 35, 30, 45, 40, 80, 70, 65, 60, 55};
    Tree* tree = ArrToBST(v);

    Display(tree);
    cout<<"\n";
    LevelOrderTraversal(tree);

}