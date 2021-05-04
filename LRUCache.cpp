#include <bits/stdc++.h>
#include <string>
using namespace std;

struct Node{
    int val;
    int key;
    Node* left = NULL;
    Node* right = NULL;
};

map<int, Node*> lru;
int totalSize = 0;
Node* head = new Node();
Node* tail = new Node();
    
void init(int capacity) {
    totalSize = capacity;
    head->right = tail;
    tail->left = head;
}
    
Node* getNewNode(int key, int val){
    Node* temp = new Node();
    temp->val = val;
    temp->key = key;
    return temp;    
}
    
void adjust(int key, int val){
    Node* temp = lru[key];
    // cout<<"Adjusting : "<<temp->key<<endl;
    temp->left->right = temp->right;
    temp->right->left = temp->left;
    Node* oldFirstNode = head->right;
    head->right = temp;
    temp->left = head;
    temp->right = oldFirstNode;
    oldFirstNode->left = temp;
    temp->val = val;
}
    
    
    
int get(int key) {
    if(lru.find(key) == lru.end()){
        return -1;
    }
    adjust(key, lru[key]->val);
    return lru[key]->val;
}
    
void removeTail(){
    Node* temp = tail->left;
    temp->left->right = temp->right;
    temp->right->left = temp->left;
    cout<<"Removing tail : "<<temp->key<<endl;
    lru.erase(temp->key);
}
    
    
void put(int key, int val) {
    if(totalSize <= 0){
        return;
    }

    if(lru.find(key) != lru.end()){
        adjust(key, val);
        return;
    }

    if(lru.size() >= totalSize){
        removeTail();
    }

    Node* newNode = getNewNode(key, val);
    // cout<<"inserting New Node : "<<newNode->data<<endl;
    Node* oldFirstNode = head->right;
    head->right = newNode;
    newNode->left = head;
    newNode->right = oldFirstNode;
    oldFirstNode->left = newNode;
    lru[key] = newNode; 
}

int main() {
    // cout<<"HELLO";
   init(2);
}
