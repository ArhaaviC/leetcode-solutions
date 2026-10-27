/*
 * LeetCode 704: Binary Search
 * ---------------------------------------------------------------
 * PROBLEM:
 *   Given a SORTED (ascending) array `nums` and a `target`, return the
 *   index of target. If it doesn't exist, return -1.
 *
 * IDEA:
 *   Because the array is sorted, one comparison with the middle element
 *   lets us throw away half of the array:
 *     - nums[mid] == target -> found it
 *     - nums[mid] >  target -> target must be on the LEFT  (everything right of mid is bigger)
 *     - nums[mid] <  target -> target must be on the RIGHT (everything left of mid is smaller)
 *   Repeat on the remaining half until found or nothing is left.
 *
 * DRY RUN: nums = [-1, 0, 3, 5, 9, 12], target = 9
 *   st=0, end=5 -> mid=2 (3)  < 9 -> st=3
 *   st=3, end=5 -> mid=4 (9) == 9 -> return 4
 *
 * COMPLEXITY:
 *   Time  : O(log n)  - the search range halves every iteration
 *   Space : O(1)      - only a few int variables
 */
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;                        // left boundary of the search range
        int end = (int)nums.size() - 1;    // right boundary (inclusive)

        // `<=` (not `<`) so a range with exactly ONE element (st == end)
        // still gets checked.
        while (st <= end) {
            // Same as (st + end) / 2, but st + end can overflow int
            // for very large arrays. This form never does.
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return mid;                // found: return the INDEX, not the value
            } else if (nums[mid] > target) {
                end = mid - 1;             // mid is already ruled out, so skip it (-1)
            } else {
                st = mid + 1;              // mid is already ruled out, so skip it (+1)
            }
        }

        // WHY -1?
        // The loop only stops when st > end, i.e. the search range is EMPTY.
        // That means every position was ruled out and the target is not in
        // the array. We return -1 as the "not found" signal because it can
        // never be a valid index (valid indices are 0 .. n-1), so the caller
        // can never confuse it with a real answer.
        return -1;
    }
};