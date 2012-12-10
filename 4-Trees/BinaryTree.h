//
//  BinaryTree.h
//  4-Trees
//
//  Created by Moshe Berman on 12/10/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef __Trees_BinaryTree_h
#define __Trees_BinaryTree_h

struct Node {
    Node *left, *right;
    int value;
};

typedef Node* NodePointer;

#endif
