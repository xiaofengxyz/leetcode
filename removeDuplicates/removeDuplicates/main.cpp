//
//  main.cpp
//  removeDuplicates
//
//  Created by 乔文琰 on 2019/11/27.
//  Copyright © 2019年 wenyan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int removeDuplicates(vector<int>& nums)
{
    if (nums.size() <= 0) {
        return 0;
    }
    int index = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[index] != nums[i]){
            nums[index + 1] = nums[i];
            index++;
        }
    }
    return index + 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {};
    std::cout << removeDuplicates(nums) << "\n";
    
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << ",";
    }
    std::cout << "\n";
    return 0;
}


