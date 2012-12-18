//
//  BinaryTree.h
//  4-Trees
//
//  Created by Moshe Berman on 12/10/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef __Trees_BinaryTree_h
#define __Trees_BinaryTree_h

//
//  Define a Node and a pointer type
//

struct Node {
    Node *left, *right, *parent;
    int value;
    bool isDeleted;
};

typedef Node* NodePointer;

//
//  This method allocates a node
//  for a binary tree. The child
//  nodes and the value pointers
//  are initialized to NULL.
//

NodePointer makeNode(){
    
    NodePointer node = new Node;
    
    node->left = NULL;
    node->right = NULL;
    node->value = NULL;
    node->isDeleted = NULL;
    
    return node;
}

//
//  This method takes a number
//  and makes it the root value
//  of a new binary tree.
//

NodePointer makeTree(int x){
    
    NodePointer treeRoot = makeNode();
    treeRoot -> value = x;
    return treeRoot;
}

//
//  Set the left node, taking both
//  a NULL tree, and an occupied
//  left child into account.
//

void setLeft(NodePointer node, int x){
    
    if (node == NULL) {
        std::cout << "Cannot set child of NULL node pointer." << std::endl;
        return;
    }
    
    if(node->left != NULL){
        std::cout << "Cannot set left of node. It's already set." << std::endl;
        return;
    }

    
    node->left = makeTree(x);
    node->left->parent = node;
    
}

//
//  Set the right node, taking both
//  a NULL tree, and an occupied
//  right child into account.
//

void setRight(NodePointer node, int x){
    
    if (node == NULL) {
        std::cout << "Cannot set child of NULL node pointer." << std::endl;
        return;
    }
    
    if(node->right != NULL){
        std::cout << "Cannot set right of node. It's already set." << std::endl;
        return;
    }
    
    
    node->right = makeTree(x);
    node->right->parent = node;
    
}

//
//  Insert a node into a tree
//

void insert(NodePointer tree, int x){
    
    //
    //  If the tree is NULL
    //  then create a new one
    //  with the value x inside.
    //
    
    if (tree == NULL) {
        tree = makeTree(x);
        return;
    }
    
    
    NodePointer p, q;
    
    p = q = tree;
    
    //
    //  Find the node closest in value to
    //  the value of x. 
    //
    
    while (x != p->value && q != NULL) {
        p = q;
        
        if (x < p->value) {
            q = p->left;
        }
        else {
            q = p->right;
        }
    }
    
    //
    //  If the value is already in the tree, we
    //  don't want to insert it into the tree.
    //  Print out a message instead.
    //
    
    if (x == p->value) {
        std::cout << "The value " << x << " is already in the tree." << std::endl;
        return;
    }
    
    //
    //  Put x into the correct
    //  leaf node of the tree
    //
    
    if(x < p->value){
        setLeft(p, x);
    }
    else{
        setRight(p, x);
    }
    
}

//
//  Some binary tree traversal methods
//

void printPreTrav(NodePointer node){
    printPreTrav(node->left);
    printPreTrav(node->right);
    
    //
    //  TODO: some action goes here,
    // in our case, print.
    //
    
    std::cout << node->value << "\n";
}

void inTrav(NodePointer node){
    inTrav(node->left);
    
    //
    //  TODO: some action goes here,
    // in our print.
    //
    
    std::cout << node->value << "\n";
    
    inTrav(node->right);
}

void postTrav(NodePointer node){
    
    //
    //  TODO: some action goes here,
    // in our case, print.
    //
    
    std::cout << node->value << "\n";
    
    postTrav(node->left);
    postTrav(node->right);
}

//
//
//



#endif
