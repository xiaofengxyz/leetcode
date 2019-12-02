//
//  main.cpp
//  twoSum
//
//  Created by 乔文琰 on 2019/12/1.
//  Copyright © 2019年 wenyan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> subMap;
    for (int i = 0; i < nums.size(); i++) {
        int sub = target - nums[i];
        if (subMap.find(sub) == subMap.end()) {
            subMap.insert(map<int, int>::value_type(sub, i));
        }
    }
    
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++) {
        
        if (subMap.find(nums[i]) != subMap.end()) {
            int index = subMap[nums[i]];
            if (i != index) {
                ret.push_back(i);
                ret.push_back(index);
                break;
            }
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    
    vector<int> nums = {3,2,3};
    auto ret = twoSum(nums, 6);
    for (int i = 0; i < ret.size(); i++) {
        std::cout << ret[i] << ",";
    }
    std::cout << "\n";
    return 0;
}
