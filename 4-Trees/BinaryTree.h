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
    Node *left, *right;
    int value;
};

typedef Node* NodePointer;

//
//  Some binary tree traversal methods
//

void preTrav(NodePointer node){
    preTrav(node->left);
    preTrav(node->right);
    
    //
    //  TODO: some action goes here
    //
}

void inTrav(NodePointer node){
    inTrav(node->left);
    
    //
    //  TODO: some action goes here
    //
    
    inTrav(node->right);
}

void postTrav(NodePointer node){
    
    //
    //  TODO: Some action goes here
    //
    
    postTrav(node->left);
    postTrav(node->right);
}

#endif
