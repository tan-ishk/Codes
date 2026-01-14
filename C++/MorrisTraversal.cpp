Node* find(Node* root){
        
        Node* temp = root->left;
        while (temp->right != NULL && temp->right != root) {
            temp = temp->right;
        }
        return temp;
    }
    
    vector<int> inOrder(Node* root) {
        Node* curr = root;
        vector<int> v;
        
        while(curr != NULL){
            
            if(curr->left == NULL){
                v.push_back(curr->data);
                curr = curr->right;
            }
            
            else{
                Node* prev = find(curr);
                
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                
                else{
                    prev->right = NULL;
                    v.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return v;
    }