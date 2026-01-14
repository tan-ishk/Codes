#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class tree{

public:

    int val;
    tree* left;
    tree* right;

    tree(int data){
        val = data;
        right = nullptr;
        left = nullptr;
    }

};

tree* InsertValue(tree* &T){
    int x;
    cin>>x;
    
    T = new tree(x);
    // base case :
    if(x == -1){
        return nullptr;
    }

    cout<<"Enter the left value of "<<T -> val<<": \n";
    T -> left = InsertValue(T -> left);
    
    cout<<"Enter the right value of "<<T -> val<<": \n";
    T -> right = InsertValue(T -> right);

    return T;
}

void Display(tree* T) {
    
    queue<tree*> q;
    q.push(T);
    q.push(nullptr);

    while (!q.empty()){
        
        tree* temp = q.front();
        q.pop();
        
        if(temp == nullptr){
            cout<<"\n";
            if (!q.empty())
            {
                q.push(nullptr);
            }
            
        }
        
        else{
            cout<<temp -> val<<" ";
            if (temp ->left){
                q.push(temp->left);
            }

            if (temp ->right){
                q.push(temp->right);
            }
        }
        
    }
    
}

void inOrderTraversal(tree* T){

    // base case :
    if(T == nullptr){
        return;
    }

    inOrderTraversal(T->left);
    cout<<T -> val<<" ";
    inOrderTraversal(T->right);
}

void preOrderTraversal(tree* T){

    // base case :
    if(T == nullptr){
        return;
    }

    cout<<T -> val<<" ";
    preOrderTraversal(T->left);
    preOrderTraversal(T->right);
}

void postOrderTraversal(tree* T){

    // base case :
    if(T == nullptr){
        return;
    }

    postOrderTraversal(T->left);
    postOrderTraversal(T->right);
    cout<<T -> val<<" ";
}

void inOrderTraversalIterative(tree* T){

    /*   left, node, right   */

    stack<tree*> st;
    tree* temp = T;

    while (temp || !st.empty())
    {
        while (temp)
        {
            st.push(temp);
            temp = temp -> left;
        }

        temp = st.top();
        st.pop();
        cout<<temp -> val<<" ";
        
        temp = temp -> right;
        
    }
}
void preOrderTraversalIterative(tree* T){

    /*   left, node, right   */

    stack<tree*> st;
    tree* temp = T;

    while (temp || !st.empty())
    {
        while (temp)
        {
            st.push(temp);
            cout<<temp -> val<<" ";
            temp = temp -> left;
        }

        temp = st.top();
        st.pop();
        
        temp = temp -> right;
        
    }
}


int main(){
    tree* T = new tree(1);

    cout<<"Enter the values in pre order : (-1 to null) \n";
    InsertValue(T);
    cout<<"Level Order :\n";
    Display(T);

    cout<<"\nIn Order :\n";
    inOrderTraversal(T);
    cout<<"\nIn Order iterative :\n";
    inOrderTraversalIterative(T);
    cout<<"\npre Order iterative :\n";
    preOrderTraversalIterative(T);
    // cout<<"\npre Order :\n";
    // preOrderTraversal(T);
    // cout<<"\npost Order :\n";
    // postOrderTraversal(T);
}