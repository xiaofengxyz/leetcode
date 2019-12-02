//
//  main.cpp
//  MyCircularDeque
//
//  Created by 乔文琰 on 2019/12/2.
//  Copyright © 2019年 wenyan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// 方法一
//class MyCircularDeque {
//public:
//    /** Initialize your data structure here. Set the size of the deque to be k. */
//    MyCircularDeque(int k) {
//        _capacity = k;
//        _queue.reserve(k);
//    }
//
//    /** Adds an item at the front of Deque. Return true if the operation is successful. */
//    bool insertFront(int value) {
//        if (_curSize < _capacity) {
//            _queue.insert(begin(_queue), value);
//            _curSize++;
//            return true;
//        }
//        return false;
//    }
//
//    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
//    bool insertLast(int value) {
//        if (_curSize < _capacity) {
//            _queue.push_back(value);
//            _curSize++;
//            return true;
//        }
//        return false;
//    }
//
//    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
//    bool deleteFront() {
//        if (_curSize > 0) {
//            _queue.erase(begin(_queue));
//            _curSize--;
//            return true;
//        }
//        return false;
//    }
//
//    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
//    bool deleteLast() {
//        if (_curSize > 0) {
//            _queue.pop_back();
//            _curSize--;
//            return true;
//        }
//        return false;
//    }
//
//    /** Get the front item from the deque. */
//    int getFront() {
//        if (_curSize > 0) {
//            return _queue[0];
//        }
//        return -1;
//    }
//
//    /** Get the last item from the deque. */
//    int getRear() {
//        if (_curSize > 0) {
//            return _queue[_curSize-1];
//        }
//        return -1;
//    }
//
//    /** Checks whether the circular deque is empty or not. */
//    bool isEmpty() {
//        return _curSize <= 0;
//    }
//
//    /** Checks whether the circular deque is full or not. */
//    bool isFull() {
//        return _curSize >= _capacity;
//    }
//
//private:
//    vector<int> _queue;
//    int _capacity = 0;
//    int _curSize = 0;
//};

// 方法二
struct LinkNode{
    int value;
    LinkNode *pre;
    LinkNode *next;
    LinkNode(int x) : value(x), pre(NULL), next(NULL) {}
};

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        _capacity = k;
        _front = new LinkNode(0);
        _rear = _front;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (_curSize < _capacity) {
            
            auto node = new LinkNode(value);
            node->pre = _front;
            node->next = _front->next;
            
            if (_front->next != NULL) {
                _front->next->pre = node;
            }
            
            _front->next = node;

            if (_rear == _front) {
                _rear = node;
            }
            
            _curSize++;
            return true;
        }
        return false;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (_curSize < _capacity) {
            auto node = new LinkNode(value);
            _rear->next = node;
            node->pre = _rear;
            _rear = node;
            
            _curSize++;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (_curSize > 0) {
            auto node = _front->next;

            if (node->next != NULL) {
                 node->next->pre = _front;
            }
            _front->next = node->next;
            
            if (_rear == node) {
                _rear = _front;
            }
            
            delete node;
            _curSize--;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (_curSize > 0) {
            auto node = _rear;

            _rear = _rear->pre;
            _rear->next = NULL;
            
            delete node;
            
            _curSize--;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (_curSize > 0) {
            return _front->next->value;
        }
        return -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (_curSize > 0) {
            return _rear->value;
        }
        return -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return _curSize <= 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return _curSize >= _capacity;
    }
    
private:
    int _capacity = 0;
    int _curSize = 0;
    
    LinkNode* _front;
    LinkNode* _rear;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
