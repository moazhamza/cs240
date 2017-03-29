//
//  BSTree.h
//  cs240Labs
//
//  Created by Moaz Hamza on 3/16/17.
//  Copyright © 2017 Moaz Hamza. All rights reserved.
//

#ifndef BSTREE_H
#define BSTREE_H

#include <vector>

class BSTree{
private:
    /* Helper node class */
    class Node{
    public:
        Node(int n){
            value = n;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }
        ~Node(){left = nullptr; right = nullptr;}
        int value;
        Node *left;
        Node *right;
        Node *parent;
    };
    
    Node *root;
    Node *preOrderTraverseAndCopy(Node *);
    void inOrderTraversalAndFill(std::vector<int>&, Node*);
    Node *findNode(int);
    bool remove(Node*);
    void deleteSubtree(Node*);
    
public:
    /* Default Constructor */
    BSTree();
    
    /* Deep copy of a BSTree object using preorder
     * traversal
     */
    BSTree(const BSTree&);
    
    /* BSTree destructor */
    ~BSTree();
    
    /* Returns true if tree is empty, false if not */
    bool empty();
    
    /* Inserts val into the tree and returns true if successful */
    bool insert(int);
    
    /* Returns true if val is in the tree*/
    bool find(int);
    
    /* Fills vector list with the tree values in sorted
     * order
     */
    void sortedArray(std::vector<int>&);
    
    /* Removes num from the tree if it was found. Returns
     * true if it finds the value and false if the value
     * is not in the tree
     */
    bool remove(int);

    void printTree();
    
};

#endif /* BSTree.h */
