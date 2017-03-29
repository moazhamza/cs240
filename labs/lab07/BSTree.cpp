//
//  BSTree.h
//  cs240Labs
//
//  Created by Moaz Hamza on 3/16/17.
//  Copyright © 2017 Moaz Hamza. All rights reserved.
//

#include "BSTree.h"

#include <iostream>

using namespace std;

BSTree::BSTree(){
    root = nullptr;
}

void BSTree::deleteSubtree(Node *head){
    if(head->left) deleteSubtree(head->left);
    if(head->right) deleteSubtree(head->right);
    delete head;   
}

BSTree::~BSTree(){
    if(root){
        if(root->left) deleteSubtree(root->left);
        if(root->right) deleteSubtree(root->right);
        delete root;
    }
}

BSTree::Node* BSTree::preOrderTraverseAndCopy(Node *head){
    Node *newNode = new Node(head->value);
    if(head->left) newNode->left = preOrderTraverseAndCopy(head->left);
    if(head->right) newNode->right = preOrderTraverseAndCopy(head->right);
    return newNode;
}

BSTree::BSTree(const BSTree &oldtree){
    this->root = new BSTree::Node(oldtree.root->value);
    this->root->left = preOrderTraverseAndCopy(oldtree.root->left);
    this->root->right = preOrderTraverseAndCopy(oldtree.root->right);
}

bool BSTree::empty(){
    return root == nullptr;
}

bool BSTree::insert(int val){
    Node *curr = root;
    if(empty()){
        root = new BSTree::Node(val);
        return true;
    }
    else{
        while(curr){
            if(curr->value < val){
                if(curr->right) curr = curr->right;
                else{
                    curr->right = new BSTree::Node(val);
                    curr->right->parent = curr;
                    return true;
                }
            }
            else if(curr->value > val){
                if(curr->left) curr = curr->left;
                else{
                    curr->left = new BSTree::Node(val);
                    curr->left->parent = curr;
                    return true;
                }
            }
            else if(curr->value == val) return false;
        }
        
    }
    return false;
}

bool BSTree::find(int val){
    Node *curr = root;
    if(empty()) return false;
    else{
        while(curr){
            if(curr->value == val) return true;
            if(curr->value < val){
                if(curr->right) curr = curr->right;
                else return false;
            }
            else if(curr->value > val){
                if(curr->left) curr = curr->left;
                else return false;
            }
        }
    }
    return false;
}

void BSTree::inOrderTraversalAndFill(std::vector<int>& list, Node* curr){
    if(curr){
        inOrderTraversalAndFill(list, curr->left);
        list.push_back(curr->value);
        inOrderTraversalAndFill(list, curr->right);
    }
}

void BSTree::sortedArray(std::vector<int>& list){
    inOrderTraversalAndFill(list, root);
}

BSTree::Node *BSTree::findNode(int val){
    Node *curr = root;
    if(empty()) return curr;
    else{
        while(curr){
            if(curr->value == val) return curr;
            if(curr->value < val){
                if(curr->right) curr = curr->right;
                else return nullptr;
            }
            else if(curr->value > val){
                if(curr->left) curr = curr->left;
                else return nullptr;
            }
        }
    }
    return nullptr;
    
}

bool BSTree::remove(BSTree::Node *nodeToDelete){
    if(nodeToDelete == nullptr) return false;
    
    // Node has 2 children
    if(nodeToDelete->left && nodeToDelete->right){
        // Find successor
        Node *successor;
        if(nodeToDelete->right){
            successor = nodeToDelete->right;
            while(successor->left) successor = successor->left;
            nodeToDelete->value = successor->value;
            
        }
        else{
            successor = nodeToDelete->left;
            while(successor->right) successor = successor->right;
            nodeToDelete->value = successor->value;
        }
        delete successor;
        
    }
    
    // Node has 1 left child
    else if(nodeToDelete->left && nodeToDelete->right == nullptr){
        if(nodeToDelete == root) root = root->right;
        
        else if(nodeToDelete->parent->left == nodeToDelete) nodeToDelete->parent->left = nodeToDelete->left;
        
        else if(nodeToDelete->parent->right == nodeToDelete) nodeToDelete->parent->right = nodeToDelete->left;
        
        delete nodeToDelete;
        
    }
    
    // Node has 1 right child
    else if(nodeToDelete->right && nodeToDelete->left == nullptr){
        if(nodeToDelete == root) root = root->right;
        
        else if (nodeToDelete->parent->left == nodeToDelete) nodeToDelete->parent->left = nodeToDelete->right;
        
        else if(nodeToDelete->parent->right == nodeToDelete) nodeToDelete->parent->right = nodeToDelete->right;
        
        delete nodeToDelete;
        return true;
    }
    
    // Node has no children
    else if(nodeToDelete->left == nullptr && nodeToDelete->right == nullptr){
        if (nodeToDelete == root){
            delete root;
            root = nullptr;
        }
        if (nodeToDelete->parent->left == nodeToDelete){
            nodeToDelete->parent->left = nullptr;
        }
        if (nodeToDelete->parent->right == nodeToDelete){
            nodeToDelete->parent->right = nullptr;
        }
        delete nodeToDelete;
        return true;
        
    }
    return false;
}


bool BSTree::remove(int num){
    Node *nodeToDelete = findNode(num);
    if(nodeToDelete == nullptr) return false;
    
    // Node has 2 children
    if(nodeToDelete->left && nodeToDelete->right){
        // Find successor
        Node *successor;
        if(nodeToDelete->right){
            successor = nodeToDelete->right;
            while(successor->left) successor = successor->left;
            nodeToDelete->value = successor->value;
            if(successor->left) successor->left->parent = nodeToDelete;
            if(successor->right) successor->right->parent = nodeToDelete;
            return remove(successor);
        }
        else{
            successor = nodeToDelete->left;
            while(successor->right) successor = successor->right;
            nodeToDelete->value = successor->value;
            return remove(successor);
        }
        
    }
    
    // Node has 1 left child
    else if(nodeToDelete->left && nodeToDelete->right == nullptr){
        if(nodeToDelete == root) root = root->right;
        
        else if(nodeToDelete->parent->left == nodeToDelete) {
            nodeToDelete->parent->left = nodeToDelete->left;
            nodeToDelete->left->parent = nodeToDelete->parent;
            
        }
        else if(nodeToDelete->parent->right == nodeToDelete) {
            nodeToDelete->parent->right = nodeToDelete->left;
            nodeToDelete->left->parent = nodeToDelete->parent;
        }
        delete nodeToDelete;
        return true;
        
    }
    
    // Node has 1 right child
    else if(nodeToDelete->right && nodeToDelete->left == nullptr){
        if(nodeToDelete == root) root = root->right;
        
        else if (nodeToDelete->parent->left == nodeToDelete) {
            nodeToDelete->parent->left = nodeToDelete->right;
            nodeToDelete->right->parent = nodeToDelete->parent;

        }
        else if(nodeToDelete->parent->right == nodeToDelete){
            nodeToDelete->parent->right = nodeToDelete->right;
            nodeToDelete->right->parent = nodeToDelete->parent;
        }
        delete nodeToDelete;
        return true;
    }
    
    // Node has no children
    else if(nodeToDelete->left == nullptr && nodeToDelete->right == nullptr){
        if (nodeToDelete == root){
            delete root;
            root = nullptr;
        }
        else if (nodeToDelete->parent->left == nodeToDelete){
            nodeToDelete->parent->left = nullptr;
            delete nodeToDelete;
            
        }
        else if(nodeToDelete->parent->right == nodeToDelete){
            nodeToDelete->parent->right = nullptr;
            delete nodeToDelete;
        }
        return true;
        
    }
    return false;
}
