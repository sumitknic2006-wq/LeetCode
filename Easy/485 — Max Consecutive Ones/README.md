# LeetCode 485 — Max Consecutive Ones

## Problem Statement

Given a binary array `nums`, return the maximum number of consecutive `1`s in the array.

A consecutive sequence is a group of adjacent `1`s without any `0` in between.

## Examples

### Example 1

**Input:**
```cpp
nums = [1,1,0,1,1,1]
```

**Output:**
```cpp
3
```

**Explanation:**

The first two elements form two consecutive `1`s, while the last three elements form three consecutive `1`s.

The maximum consecutive count is `3`.

### Example 2

**Input:**
```cpp
nums = [1,0,1,1,0,1]
```

**Output:**
```cpp
2
```

**Explanation:**

The longest consecutive sequence of `1`s is `[1,1]`, which has a length of `2`.

## Approach: Counting Consecutive Ones

I used a single traversal to count consecutive `1`s and maintain the maximum length found so far.

I maintain two variables:

- `currentLength` — tracks the current consecutive sequence of `1`s.
- `MaxLength` — stores the maximum consecutive sequence length found so far.

### Case 1: Current Element Is 1

If `nums[i] == 1`:

- Increment `currentLength`.
- Update `MaxLength` using `max()`.

### Case 2: Current Element Is 0

If `nums[i] == 0`:

- Reset `currentLength` to `0`, because the consecutive sequence is broken.

After traversing the entire array, return `MaxLength`.

## C++ Solution

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int MaxLength = 0;
        int currentLength = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                currentLength++;
                MaxLength = max(MaxLength,currentLength);
            }
            else{
                currentLength = 0;
            }
        }
        return MaxLength;
    }
};
```

## Algorithm

1. Initialize `MaxLength = 0`.
2. Initialize `currentLength = 0`.
3. Traverse the array from index `0` to `n-1`.
4. If the current element is `1`:
   - Increment `currentLength`.
   - Update `MaxLength = max(MaxLength, currentLength)`.
5. If the current element is `0`:
   - Reset `currentLength = 0`.
6. Return `MaxLength`.

## Dry Run

### Input

```cpp
nums = [1,1,0,1,1,1]
```

| Index | Element | `currentLength` | `MaxLength` |
|---|---:|---:|---:|
| 0 | 1 | 1 | 1 |
| 1 | 1 | 2 | 2 |
| 2 | 0 | 0 | 2 |
| 3 | 1 | 1 | 2 |
| 4 | 1 | 2 | 2 |
| 5 | 1 | 3 | 3 |

**Output:** `3`

The longest consecutive sequence of `1`s is the final group of three elements.

## C++ Concepts Used

- Array traversal
- Counting technique
- Consecutive elements
- Conditional statements
- `max()` function
- Resetting counters
- Maintaining current and maximum values

## Complexity Analysis

### Time Complexity: O(n)

We traverse the array exactly once. Every element is processed in constant time.

### Auxiliary Space Complexity: O(1)

Only two integer variables, `MaxLength` and `currentLength`, are used. No additional data structure is required.

## Key Takeaway

Whenever we need to find the longest consecutive sequence of a particular value, we can maintain a current counter and a maximum counter.

- Increase the current count when the required value appears.
- Reset the current count when the sequence breaks.
- Update the maximum whenever the current sequence becomes longer.

This approach solves the problem efficiently in a single traversal.

**LeetCode:** 485 — Max Consecutive Ones  
**Difficulty:** Easy  
**Topics:** Array