# LeetCode 2529: Maximum Count of Positive Integer and Negative Integer

## 1. Problem Statement

Given an array `nums` sorted in non-decreasing order, return the maximum count between the number of positive integers and the number of negative integers.

Zero is neither positive nor negative, so it should not be counted.

## 2. Examples

**Example 1:**

```cpp
Input: nums = [-2,-1,-1,1,2,3]
Output: 3
```

**Explanation:**
- Negative integers: `-2, -1, -1` → 3
- Positive integers: `1, 2, 3` → 3

Maximum count = 3.

**Example 2:**

```cpp
Input: nums = [-3,-2,-1,0,0,1,2]
Output: 3
```

**Explanation:**
- Negative integers: 3
- Positive integers: 2
- Zeros: 2 (ignored)

Maximum count = 3.

**Example 3:**

```cpp
Input: nums = [5,20,66,1314]
Output: 4
```

**Explanation:** All elements are positive, so the maximum count is 4.

## 3. Constraints

- `1 <= nums.length <= 2000`
- `-2000 <= nums[i] <= 2000`
- `nums` is sorted in non-decreasing order.

## 4. Approach: Linear Traversal + Counting

I solved this problem using a simple linear traversal.

The main idea is to count positive and negative integers separately and return whichever count is greater.

We maintain two variables:

- `count0`: Stores the count of positive integers.
- `count1`: Stores the count of negative integers.

### Step 1: Initialize Counters

```cpp
int count0 = 0;
int count1 = 0;
```

Both counters start at zero.

### Step 2: Traverse the Array

```cpp
for(int i = 0; i < n; i++)
```

Visit every element of the array.

### Step 3: Count Positive and Negative Integers

```cpp
if(nums[i] > 0)
{
    count0++;
}
else if(nums[i] < 0)
{
    count1++;
}
```

- If the element is greater than zero, increment `count0`.
- If the element is smaller than zero, increment `count1`.
- If the element is zero, do nothing.

### Step 4: Return Maximum Count

```cpp
return max(count0, count1);
```

The `max()` function returns the larger count.

## 5. Algorithm

1. Calculate the size of the array and store it in `n`.
2. Initialize `count0 = 0` and `count1 = 0`.
3. Traverse the array using a `for` loop.
4. If the current element is positive, increment `count0`.
5. If the current element is negative, increment `count1`.
6. Ignore zero elements.
7. Return `max(count0, count1)`.

## 6. C++ Solution

```cpp
class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int n = nums.size();

        int count0 = 0;
        int count1 = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0){
                count0++;
            }
            else if(nums[i] < 0){
                count1++;
            }
        }

        return max(count0, count1);
    }
};
```

## 7. Dry Run

**Input:**

```cpp
nums = [-2,-1,-1,1,2,3]
```

Initial values:

```cpp
count0 = 0;
count1 = 0;
```

| Index | nums[i] | Condition | count0 (Positive) | count1 (Negative) |
|---:|---:|---|---:|---:|
| 0 | -2 | Negative | 0 | 1 |
| 1 | -1 | Negative | 0 | 2 |
| 2 | -1 | Negative | 0 | 3 |
| 3 | 1 | Positive | 1 | 3 |
| 4 | 2 | Positive | 2 | 3 |
| 5 | 3 | Positive | 3 | 3 |

After traversal:

```cpp
count0 = 3;
count1 = 3;
```

Now:

```cpp
return max(3, 3);
```

**Final Output:**

```cpp
3
```

## 8. Important C++ Concepts

### 1. Linear Traversal

A `for` loop is used to visit every element of the array.

```cpp
for(int i = 0; i < n; i++)
```

### 2. Conditional Statements

We use `if` and `else if` to identify positive and negative numbers.

```cpp
if(nums[i] > 0)
```

```cpp
else if(nums[i] < 0)
```

### 3. max() Function

The `max()` function returns the greater of two values.

```cpp
max(count0, count1);
```

## 9. Edge Cases

| Input | Output | Explanation |
|---|---:|---|
| `[-5,-3,-1]` | 3 | All negative |
| `[1,2,3,4]` | 4 | All positive |
| `[0,0,0]` | 0 | All zeros |
| `[-2,-1,0,1,2]` | 2 | Equal positive and negative counts |
| `[-3,-2,-1,0,0,1,2]` | 3 | More negative numbers |

## 10. Complexity Analysis

**Time Complexity: O(n)**

- We traverse the array exactly once.
- Each element is checked in constant time.
- Therefore, the overall time complexity is O(n).

**Auxiliary Space Complexity: O(1)**

- Only three variables are used: `n`, `count0`, and `count1`.
- No additional data structure is required.

## 11. Alternative Approach: Binary Search

Since the input array is already sorted, we can also solve this problem using binary search.

- Find the first non-negative element to determine the number of negative elements.
- Find the first positive element to determine the number of positive elements.
- Return the maximum of both counts.

This approach takes O(log n) time and O(1) auxiliary space.

## 12. Key Concepts Learned

- Array Traversal
- Linear Search
- Counting Positive and Negative Integers
- Conditional Statements
- C++ STL `max()` Function
- Basic Binary Search Optimization

## 13. Key Takeaway

This problem demonstrates how a simple array traversal can solve a counting problem efficiently.

The most important conditions are:

```cpp
if(nums[i] > 0)
{
    count0++;
}
else if(nums[i] < 0)
{
    count1++;
}
```

**Remember:** Zero is neither positive nor negative, so it must be ignored.

## 14. LeetCode Information

- **Problem Number:** 2529
- **Problem Name:** Maximum Count of Positive Integer and Negative Integer
- **Difficulty:** Easy
- **Topics:** Array, Binary Search, Counting
- **Your Approach:** Linear Traversal + Counting
- **Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(1)

---

**One problem at a time. One day at a time. Consistency is the key!**