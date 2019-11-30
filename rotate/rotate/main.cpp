//
//  main.cpp
//  rotate
//
//  Created by 乔文琰 on 2019/11/28.
//  Copyright © 2019年 wenyan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//void rotate(vector<int>& nums, int k) {
//
//    if (nums.size() <= 1) {
//        return;
//    }
//    if (k >= nums.size()) {
//        k = k % nums.size();
//    }
//    if (k <= 0) {
//        return;
//    }
//
//    for (int i = 0; i < k;  i++) {
//        int flag = nums[nums.size()-1];
//        memcpy(&nums[1], &nums[0], (nums.size()-1) * sizeof(int));
//        nums[0] = flag;
//    }
//}

void reverse(vector<int>& nums)
{
    int middle = nums.size() / 2;
    if (nums.size() % 2 == 0) {
        int flag = nums[middle];
        nums[middle] = nums[middle + 1];
        nums[middle + 1] = flag;
        
        for (int i = 0; i < middle; i++) {
            int flag = nums[i];
            nums[i] = nums[nums.size() - i + 1];
            nums[nums.size() - i + 1] = flag;
        }
    }
}

void rotate(vector<int>& nums, int k) {
    
    if (nums.size() <= 1) {
        return;
    }
    if (k >= nums.size()) {
        k = k % nums.size();
    }
    if (k <= 0) {
        return;
    }
    
    int middle = nums.size() / 2;
    for (int i = 0; i < middle; i++) {
        int flag = nums[i];
        nums[i] = nums[nums.size() - i - 1];
        nums[nums.size() - i - 1] = flag;
        
    }
    
    middle = (nums.size() - k) / 2;
    for (int i = k; i < k + middle; i++) {
        int flag = nums[i];
        nums[i] = nums[nums.size() - i - 1 + k];
        nums[nums.size() - i - 1 + k] = flag;
    }
    
    middle = k / 2;
    for (int i = 0; i < middle; i++) {
        int flag = nums[i];
        nums[i] = nums[k - i - 1];
        nums[k - i - 1] = flag;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {-1,-100,3,99};
    rotate(nums, 2);
    
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << ",";
    }
    std::cout << "\n";
    return 0;
}


