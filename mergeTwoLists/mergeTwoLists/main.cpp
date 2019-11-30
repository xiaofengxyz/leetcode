//
//  main.cpp
//  mergeTwoLists
//
//  Created by 乔文琰 on 2019/11/29.
//  Copyright © 2019年 wenyan. All rights reserved.
//

#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    
    if (l2 == nullptr) {
        return l1;
    }
    
    ListNode* h = new ListNode(0);   //头结点
    ListNode* l = h;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val > l2->val) {
            l->next = l2;
            l2 = l2->next;
        }
        else {
            l->next = l1;
            l1 = l1->next;
        }
        
        l = l->next;
    }

    l->next = l1 != nullptr ? l1 : l2;
    
    return h->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    auto l11 = new ListNode(1);
    auto l12 = new ListNode(2);
    auto l13 = new ListNode(4);
    l11->next = l12;
    l12->next = l13;
    
    auto l21 = new ListNode(1);
    auto l22 = new ListNode(3);
    auto l23 = new ListNode(4);
    l21->next = l22;
    l22->next = l23;
    
    auto l = mergeTwoLists(l11, l21);
    while (l != nullptr) {
        std::cout << l->val << ",";
        l = l->next;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}

