# LeetCode 53: Maximum Subarray

## 1. Problem Statement

Given an integer array `nums`, find the contiguous subarray (containing at least one number) that has the largest sum, and return its sum.

**Note:** A subarray is a continuous part of an array.

## 2. Example

**Example 1:**

```text
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]

Output: 6
```

**Explanation:**

The subarray `[4,-1,2,1]` has the maximum sum.

`4 + (-1) + 2 + 1 = 6`

**Example 2:**

```text
Input: nums = [1]

Output: 1
```

**Example 3:**

```text
Input: nums = [5,4,-1,7,8]

Output: 23
```

**Explanation:**

The entire array has the maximum sum.

## 3. Constraints

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## 4. Approach: Kadane's Algorithm

Kadane's Algorithm is used to find the maximum sum of a contiguous subarray.

We maintain two variables:

- `currsum`: Stores the maximum subarray sum ending at the current element.
- `maxsum`: Stores the maximum subarray sum found so far.

### Main Logic

For every element, we have two choices:

1. Start a new subarray from the current element.
2. Add the current element to the existing subarray.

We choose the maximum:

```cpp
currsum = max(num, currsum + num);
```

Then update the overall maximum:

```cpp
maxsum = max(maxsum, currsum);
```

## 5. Algorithm

1. Initialize `maxsum = INT_MIN`.
2. Initialize `currsum = 0`.
3. Traverse the array using a for-each loop.
4. For every element:
   - Calculate `max(num, currsum + num)`.
   - Update `currsum`.
   - Update `maxsum`.
5. Return `maxsum`.

## 6. C++ Code

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

## 7. Dry Run

**Input:**

```text
nums = [-2,1,-3,4,-1,2,1,-5,4]
```

Initial values:

```text
maxsum = INT_MIN
currsum = 0
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

**Final Output:**

```text
6
```

The maximum-sum subarray is:

```text
[4, -1, 2, 1]
```

Its sum is `6`.

## 8. Important Concepts

- **Kadane's Algorithm:** Finds the maximum sum of a contiguous subarray.
- **Greedy Approach:** At every element, choose between starting fresh and extending the current subarray.
- **Dynamic Programming:** `currsum` represents the best subarray sum ending at the current position.
- **Contiguous Subarray:** Elements must be next to each other.

## 9. Edge Cases

| Input | Output | Reason |
|---|---:|---|
| `[-1]` | -1 | Single negative element |
| `[-5,-2,-8]` | -2 | All elements are negative |
| `[1,2,3,4]` | 10 | All elements are positive |
| `[0,0,0]` | 0 | All elements are zero |
| `[-2,1,-3,4,-1,2,1,-5,4]` | 6 | Maximum contiguous subarray |

## 10. Complexity Analysis

**Time Complexity: O(n)**

- The array is traversed only once.
- Each element is processed in constant time.

**Auxiliary Space Complexity: O(1)**

- Only two variables, `currsum` and `maxsum`, are used.
- No additional data structure is required.

## 11. Key Takeaway

Kadane's Algorithm teaches us how to solve the Maximum Subarray problem efficiently.

The most important decision is:

```cpp
currsum = max(num, currsum + num);
```

If extending the current subarray gives a smaller sum than starting fresh, we start a new subarray.

**Remember:** Do not initialize `maxsum` with `0`, because an array containing only negative numbers would then produce an incorrect answer.

## 12. LeetCode Information

- **Problem Number:** 53
- **Problem Name:** Maximum Subarray
- **Difficulty:** Medium
- **Topic:** Array, Divide and Conquer, Dynamic Programming
- **Algorithm:** Kadane's Algorithm
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)