/*
 * LeetCode 136: Single Number
 * https://leetcode.com/problems/single-number/
 *
 * Every element appears twice except one. Find that one.
 * Constraint: O(n) time, O(1) extra space.
 *
 * Approach: XOR all elements.
 *   a ^ a = 0, a ^ 0 = a, and XOR is commutative/associative,
 *   so every pair cancels and only the single number remains.
 *
 * Time:  O(n)
 * Space: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    vector<int> a = {2, 2, 1};
    vector<int> b = {4, 1, 2, 1, 2};
    vector<int> c = {1};

    cout << singleNumber(a) << "\n";  // 1
    cout << singleNumber(b) << "\n";  // 4
    cout << singleNumber(c) << "\n";  // 1
    return 0;
}
