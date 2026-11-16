# LeetCode 53: Maximum Subarray

## Problem Statement

Given an integer array `nums`, find the contiguous subarray (containing at least one number) that has the largest sum, and return its sum.

A subarray is a continuous, non-empty part of an array.

## Examples

**Example 1:**

```cpp
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
```

**Explanation:** The subarray `[4,-1,2,1]` has the largest sum: `4 + (-1) + 2 + 1 = 6`.

**Example 2:**

```cpp
Input: nums = [1]
Output: 1
```

**Example 3:**

```cpp
Input: nums = [5,4,-1,7,8]
Output: 23
```

**Explanation:** The entire array has the maximum sum.

## Constraints

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Approach: Kadane's Algorithm

I solved this problem using **Kadane's Algorithm**, an efficient approach based on Dynamic Programming.

The main idea is to find the maximum subarray sum ending at each position while maintaining the overall maximum sum.

I use two variables:

- `currsum`: Stores the maximum sum of a subarray ending at the current element.
- `maxsum`: Stores the maximum subarray sum found so far.

### Key Logic

For every element, there are two choices:

1. Start a new subarray from the current element.
2. Extend the existing subarray by adding the current element.

We choose whichever gives the larger sum:

```cpp
currsum = max(num, currsum + num);
```

Then update the overall maximum:

```cpp
maxsum = max(maxsum, currsum);
```

## Algorithm

1. Initialize `maxsum` with `INT_MIN`.
2. Initialize `currsum` with `0`.
3. Traverse the array using a for-each loop.
4. For each element:
   - Calculate the maximum between the current element and the extended subarray sum.
   - Update `currsum`.
   - Update `maxsum`.
5. Return `maxsum`.

## C++ Solution

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int currsum = 0;

        for(int num : nums)
        {
            currsum = max(num, currsum + num);
            maxsum = max(maxsum, currsum);
        }

        return maxsum;
    }
};
```

## Dry Run

**Input:**

```cpp
nums = [-2,1,-3,4,-1,2,1,-5,4]
```

Initial values:

```cpp
maxsum = INT_MIN;
currsum = 0;
```

| num | currsum = max(num, currsum + num) | maxsum |
|---:|---:|---:|
| -2 | -2 | -2 |
| 1 | 1 | 1 |
| -3 | -2 | 1 |
| 4 | 4 | 4 |
| -1 | 3 | 4 |
| 2 | 5 | 5 |
| 1 | 6 | 6 |
| -5 | 1 | 6 |
| 4 | 5 | 6 |

**Final Answer:**

```cpp
6
```

The maximum-sum subarray is `[4,-1,2,1]`.

## Edge Cases

| Input | Output | Explanation |
|---|---:|---|
| `[-1]` | -1 | Single negative element |
| `[-5,-2,-8]` | -2 | All elements are negative |
| `[1,2,3,4]` | 10 | All elements are positive |
| `[0,0,0]` | 0 | All elements are zero |
| `[-2,1,-3,4,-1,2,1,-5,4]` | 6 | Maximum contiguous subarray |

## Complexity Analysis

**Time Complexity: O(n)**

- The array is traversed only once.
- Each element is processed in constant time.

**Auxiliary Space Complexity: O(1)**

- Only two variables, `currsum` and `maxsum`, are used.
- No additional data structure is required.

## Important Concepts Learned

- **Kadane's Algorithm:** Efficiently finds the maximum sum of a contiguous subarray.
- **Dynamic Programming:** Uses the result of the previous position to calculate the current result.
- **Greedy Decision:** Chooses between starting a new subarray and extending the existing one.
- **Array Traversal:** Processes each element exactly once.

## Key Takeaway

The most important decision in Kadane's Algorithm is:

```cpp
currsum = max(num, currsum + num);
```

If starting a new subarray gives a better sum than extending the previous one, we start fresh.

**Important:** Initializing `maxsum` with `INT_MIN` ensures that the solution also works when every element in the array is negative.

## LeetCode Information

- **Problem Number:** 53
- **Problem Name:** Maximum Subarray
- **Difficulty:** Medium
- **Topics:** Array, Divide and Conquer, Dynamic Programming
- **Algorithm:** Kadane's Algorithm
- **Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(1)

---

**One problem at a time. One day at a time. Consistency is the key!**