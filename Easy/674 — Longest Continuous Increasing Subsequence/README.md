# LeetCode 674 — Longest Continuous Increasing Subsequence

## Problem Statement

Given an unsorted array of integers `nums`, return the length of the longest continuous strictly increasing subsequence.

A continuous increasing sequence must satisfy:

`nums[i] < nums[i + 1]`

for every adjacent pair in the sequence.

The sequence must be continuous, meaning elements cannot be skipped.

## Examples

### Example 1

**Input:**
```cpp
nums = [1,3,5,4,7]
```

**Output:**
```cpp
3
```

**Explanation:**

The longest continuous increasing sequence is `[1,3,5]`, whose length is `3`.

Although `[1,3,5,7]` is increasing, it is not continuous because the element `4` separates `5` and `7`.

### Example 2

**Input:**
```cpp
nums = [2,2,2,2,2]
```

**Output:**
```cpp
1
```

**Explanation:**

Since the sequence must be strictly increasing, equal elements cannot extend the sequence. Therefore, the longest increasing sequence has length `1`.

## Approach: Single Traversal and Counting

I used a single traversal to find the longest continuous strictly increasing sequence.

I maintain two variables:

- `currentLength` — tracks the length of the current increasing sequence.
- `maxLength` — stores the maximum increasing sequence length found so far.

I start traversing the array from index `1` and compare each element with its previous element.

### Case 1: Strictly Increasing

If `nums[i-1] < nums[i]`:

- Increment `currentLength`.
- Update `maxLength` using `max()`.

### Case 2: Increasing Sequence Breaks

If `nums[i-1] >= nums[i]`:

- Reset `currentLength` to `1`, because the current element starts a new sequence.

After traversing the array, return `maxLength`.

## C++ Solution

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLength = 1;
        int currentLength = 1;

        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i-1]<nums[i])
            {
                currentLength++;
                maxLength = max(currentLength,maxLength);
            }
            else{
                currentLength = 1;
            }
        }
        return maxLength;
    }
};
```

## Algorithm

1. Initialize `maxLength = 1`.
2. Initialize `currentLength = 1`.
3. Traverse the array starting from index `1`.
4. Compare the current element with the previous element.
5. If `nums[i-1] < nums[i]`:
   - Increment `currentLength`.
   - Update `maxLength = max(maxLength, currentLength)`.
6. Otherwise:
   - Reset `currentLength = 1`.
7. Return `maxLength`.

## Dry Run

**Input:**

```cpp
nums = [1,3,5,4,7]
```

| Index | Element | Comparison | `currentLength` | `maxLength` |
|---|---:|---|---:|---:|
| 0 | 1 | Initial element | 1 | 1 |
| 1 | 3 | 1 < 3 | 2 | 2 |
| 2 | 5 | 3 < 5 | 3 | 3 |
| 3 | 4 | 5 < 4 (False) | 1 | 3 |
| 4 | 7 | 4 < 7 | 2 | 3 |

**Output:** `3`

The longest continuous increasing sequence is `[1,3,5]`.

## Continuous Subsequence vs. Increasing Subsequence

A continuous increasing sequence cannot skip elements.

For example, in:

`[1,3,5,4,7]`

- `[1,3,5]` is continuous and increasing.
- `[1,3,5,7]` is increasing but not continuous.

This problem requires a continuous increasing sequence, so we cannot skip elements.

## C++ Concepts Used

- Array traversal
- Comparison of adjacent elements
- Counting technique
- Strictly increasing sequences
- Conditional statements
- `max()` function
- Resetting counters

## Complexity Analysis

### Time Complexity: O(n)

We traverse the array once, comparing each element with its previous element. Each comparison and update takes constant time.

### Auxiliary Space Complexity: O(1)

Only two integer variables, `currentLength` and `maxLength`, are used. No additional data structure is required.

## Key Takeaway

Whenever we need to find the longest continuous increasing sequence, we can compare adjacent elements and maintain a current counter and a maximum counter.

- If the next element is greater, extend the current sequence.
- If it is smaller or equal, reset the current sequence to `1`.
- Update the maximum whenever the current sequence becomes longer.

This approach solves the problem efficiently in a single traversal.

**LeetCode:** 674 — Longest Continuous Increasing Subsequence  
**Difficulty:** Easy  
**Topics:** Array