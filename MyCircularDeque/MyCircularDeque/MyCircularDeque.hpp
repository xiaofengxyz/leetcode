//
//  MyCircularDeque.hpp
//  MyCircularDeque
//
//  Created by 乔文琰 on 2019/12/2.
//  Copyright © 2019年 wenyan. All rights reserved.
//

#ifndef MyCircularDeque_hpp
#define MyCircularDeque_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k);
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value);
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value);
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront();
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast();
    
    /** Get the front item from the deque. */
    int getFront();
    
    /** Get the last item from the deque. */
    int getRear();
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty();
    
    /** Checks whether the circular deque is full or not. */
    bool isFull();
    
private:
    vector<int> _queue;
    int _capacity = 0;
};

#endif /* MyCircularDeque_hpp */
