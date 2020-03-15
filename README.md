# Problem Solving Study

## CheatSheets
### C++
#### Data structures
##### Linked list
##### Dynamic array
##### Map
#### Algorithms
##### std::find
    int search(vector<int>& nums, int target) {
        auto i = find(nums.begin(), nums.end(), target);
        return i == nums.end() ? -1 : i - nums.begin();
    }
- type of target needs operator==
- O(n)


### Python
#### Data structures
##### Linked list
##### Dynamic array
##### Map

## Algorithmic Problem Solving Strategies
### Book1
### Book2

## LeetCode
### top_interview_questions
#### search-in-rotated-sorted-array (https://leetcode.com/problems/search-in-rotated-sorted-array/)
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        int rot = left;
        left = 0, right = size - 1;
        while (left <= right) {
            int idx = (left + right) / 2;
            int rotIdx = (idx + rot) % size;
            if (nums[rotIdx] == target) return rotIdx;
            if (nums[rotIdx] < target) left = idx + 1;
            else right = idx - 1;
        }
        return -1;
    }
- how to binary search
- how to adjust index properly
    int search(vector<int>& nums, int target) {
        auto i = find(nums.begin(), nums.end(), target);
        return i == nums.end() ? -1 : i - nums.begin();
    }
- how to use std::find

