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
//  Delete a node
//

void deleteNodeFromTree(int num, NodePointer tree){
    
    if (tree == NULL) {
        std::cout << "There's no number " << num << " in the tree.\n";
    }

    //
    //  The value we're deleting is smaller than this node,
    //  so move to the left of the tree, where smaller
    //  numbers are places.
    //
    
    else if(num < tree->value){
        deleteNodeFromTree(num, tree->left);
    }
    
    //
    //  The value we're deleting is larger than this node,
    //  so move to the right of the tree, where larger
    //  numbers are places.
    //
    
    else if(num > tree->value){
        deleteNodeFromTree(num, tree->right);
    }
    
    //
    //  Don't actually delete the node, cheat and use
    //  a flag to pretend that the node is deleted.
    //
    
    else{
        tree->isDeleted = true;
    }
}

//
//  Print a node, but only if it's not deleted
//

void printNode(NodePointer node){
    if(!node->isDeleted){
        std::cout << node->value << " ";
    }
}

//
//  Some binary tree traversal/print methods
//

void preorder(NodePointer node){
    
    if(node->left){
        preorder(node->left);
    }
    
    if(node->right){
        preorder(node->right);
    }
    
    printNode(node);
}

void inorder(NodePointer node){
    
    if(node->left){
        inorder(node->left);
    }
    
    printNode(node);

    if(node->right){
        inorder(node->right);
    }
}

void postorder(NodePointer node){
    
    printNode(node);
    
    if(node->left){
        postorder(node->left);
    }
    if(node->right){
    postorder(node->right);
    }
}

//
//  Counts the number of nodes in a tree
//

int countNodesInTree(NodePointer tree){
    return countNodesInTree(tree->left) + countNodesInTree(tree->right);
}

//
//  Print the nodes in the tree.
//

void printNodesInSubtreeTree(NodePointer tree){
    
    if (tree) {
        if (tree->left && tree->right) {
            std::cout << "Node has two children. " << std::endl;
        }
        else if(!tree->left && !tree->right) {
            std::cout << "Node has zero children. " << std::endl;
        }
        else{
            std::cout << "Node has one child. " <<std::endl;
        }
    }

    if(tree->left){
        printNodesInSubtreeTree(tree->left);
    }
    if(tree->right){
        printNodesInSubtreeTree(tree->right);
    }
}


#endif
