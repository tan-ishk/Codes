#include<iostream>
using namespace std;

class TrieNode{
    public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        this->ch = ch;
        isTerminal = false;
        for(int i = 0; i<26; i++)
            children[i] = NULL;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word){

        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // assume word will be in small
        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        //absent
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //recursive call
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
        
        //base case :
        if(word.length() == 0){
            return root->isTerminal;
        }

        // assume word will be in small
        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        //absent
        else{
            return false;
        }

        //recursive call
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }
};

int main(){

    Trie * node = new Trie();

    node->insertWord("onerepublic");

    cout<<"present or not : "<<node-> searchWord("onerepublic")<<"\n";
    cout<<"present or not : "<<node-> searchWord("theScript")<<"\n";
}