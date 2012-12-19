//
//  Set.h
//  4-Trees
//
//  Created by Moshe Berman on 12/19/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef __Trees_Set_h
#define __Trees_Set_h

#include <vector>

class Instruction {
public:
    int number;
    string instruction;
};

class Set {
public:
    vector<int> numbers;
    vector<Instruction> Instructions;
};

#endif
