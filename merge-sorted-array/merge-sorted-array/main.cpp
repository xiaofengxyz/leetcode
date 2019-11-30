//
//  main.cpp
//  merge-sorted-array
//
//  Created by 乔文琰 on 2019/11/30.
//  Copyright © 2019年 wenyan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i1 = m - 1;
    int i2 = n - 1;
    int i = m + n - 1;
    while (i1 >= 0 && i2 >= 0) {
        nums1[i--] = nums1[i1] > nums2[i2] ? nums1[i1--] : nums2[i2--];
    }
    
    while (i1 >= 0) {
        nums1[i--] = nums1[i1--];
    }
    while (i2 >= 0) {
        nums1[i--] = nums2[i2--];
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge(nums1, 3, nums2, 3);
    
    for (int i = 0; i < nums1.size(); i++) {
        std::cout << nums1[i] << ",";
    }
    std::cout << "\n";
    return 0;
}
