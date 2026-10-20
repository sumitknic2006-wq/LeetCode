# 🎯 2089. Find Target Indices After Sorting Array

## 📌 Problem Statement

You are given a **0-indexed integer array** `nums` and an integer `target`.

First, sort the array in non-decreasing order. Then, find all indices where the value equals `target`.

Return a list of these indices in increasing order.

If the target does not exist in the array, return an empty list.

---

## 💡 Examples

### Example 1

```text
Input:
nums = [1,2,5,2,3]
target = 2

Output:
[1,2]
```

After sorting:

```text
[1,2,2,3,5]
```

The target `2` appears at indices `1` and `2`.

### Example 2

```text
Input:
nums = [1,2,5,2,3]
target = 3

Output:
[3]
```

After sorting:

```text
[1,2,2,3,5]
```

The target `3` appears at index `3`.

### Example 3

```text
Input:
nums = [1,2,5,2,3]
target = 5

Output:
[4]
```

After sorting:

```text
[1,2,2,3,5]
```

The target `5` appears at index `4`.

---

## 📏 Constraints

- `1 <= nums.length <= 100`
- `1 <= nums[i], target <= 100`
- `nums` may contain duplicate elements.

---

# 🧠 Approach 1: Sorting + Linear Search

This is your original approach.

The idea is simple:

1. Sort the array.
2. Traverse the sorted array.
3. Whenever an element equals `target`, store its index.
4. Return all collected indices.

## Step 1: Sort the Array

```cpp
sort(nums.begin(), nums.end());
```

Sorting arranges the elements in non-decreasing order.

Example:

```text
Before sorting:
[1,2,5,2,3]

After sorting:
[1,2,2,3,5]
```

## Step 2: Create an Answer Vector

```cpp
vector<int> ans;
```

This vector stores the indices where `nums[i] == target`.

## Step 3: Traverse the Array

```cpp
for(int i = 0; i < nums.size(); i++)
{
    if(nums[i] == target)
    {
        ans.push_back(i);
    }
}
```

We check each element. If it matches the target, its index is added to `ans`.

## Step 4: Return the Answer

```cpp
return ans;
```

Because we traverse the sorted array from left to right, the collected indices are automatically in increasing order.

---

# 💻 C++ Solution — Your Implementation

```cpp
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```

---

# 🔍 Dry Run

Consider:

```text
nums = [1,2,5,2,3]
target = 2
```

### Step 1: Sort the Array

```text
[1,2,2,3,5]
```

### Step 2: Check Every Index

| Index `i` | `nums[i]` | Equals target? | Action        |
| --------: | --------: | -------------- | ------------- |
|         0 |         1 | No             | Skip          |
|         1 |         2 | Yes            | Add index `1` |
|         2 |         2 | Yes            | Add index `2` |
|         3 |         3 | No             | Skip          |
|         4 |         5 | No             | Skip          |

### Step 3: Final Answer

```text
ans = [1,2]
```

---

# 🚀 Approach 2: Sorting + Binary Search

Since the array is sorted, we can use binary search to find the first and last positions of the target.

C++ provides two useful functions:

- `lower_bound()` returns an iterator to the first element greater than or equal to the target.
- `upper_bound()` returns an iterator to the first element strictly greater than the target.

The indices between these two positions contain all occurrences of the target.

## 💻 Optimized C++ Code

```cpp
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int first = lower_bound(nums.begin(), nums.end(), target)
                    - nums.begin();

        int last = upper_bound(nums.begin(), nums.end(), target)
                   - nums.begin();

        vector<int> ans;

        for(int i = first; i < last; i++)
        {
            ans.push_back(i);
        }

        return ans;
    }
};
```

### Example

```text
Sorted array:
[1,2,2,3,5]

target = 2

lower_bound index = 1
upper_bound index = 3
```

The loop runs from index `1` up to, but not including, index `3`.

Therefore:

```text
Output = [1,2]
```

---

# 📊 Approach Comparison

| Feature                       | Approach 1    | Approach 2             |
| ----------------------------- | ------------- | ---------------------- |
| Sorting                       | Yes           | Yes                    |
| Searching                     | Linear search | Binary search          |
| Search complexity             | O(n)          | O(log n)               |
| Total time complexity         | O(n log n)    | O(n log n)             |
| Extra space, excluding output | O(1)          | O(1)                   |
| Ease of understanding         | Very easy     | Requires STL knowledge |

Both approaches have (O(n\log n)) overall time complexity because sorting dominates the search.

---

# ⏱️ Complexity Analysis

## Approach 1: Sorting + Linear Search

### Time Complexity

Sorting takes:

[
O(n\log n)
]

Traversing the array takes:

[
O(n)
]

Total:

[
O(n\log n)+O(n)=O(n\log n)
]

### Space Complexity

The answer vector stores up to `n` indices.

- Auxiliary space excluding output: (O(1)), assuming the sorting implementation's auxiliary stack is not counted.
- Output space: (O(n)).

## Approach 2: Sorting + Binary Search

### Time Complexity

- Sorting: (O(n\log n))
- Two binary searches: (O(\log n))
- Building the answer: (O(k)), where (k) is the number of target occurrences.

Total:

[
O(n\log n+\log n+k)=O(n\log n)
]

### Space Complexity

- Auxiliary space excluding output: (O(1)), excluding sorting implementation overhead.
- Output space: (O(k)).

---

# 🧩 Important Concepts

### 1. Sorting

```cpp
sort(nums.begin(), nums.end());
```

Arranges elements in non-decreasing order.

### 2. Linear Search

Checks each element one by one.

```cpp
if(nums[i] == target)
```

### 3. `lower_bound()`

Finds the first position where an element is greater than or equal to the target.

### 4. `upper_bound()`

Finds the first position where an element is strictly greater than the target.

### 5. Duplicate Elements

The target may appear multiple times, so we must collect every matching index, not just the first one.

---

# 🎯 Key Takeaway

Remember this pattern:

```text
Sort the array
      ↓
Find every target occurrence
      ↓
Store the corresponding indices
      ↓
Return the answer
```

Your original approach is correct and easy to understand. The binary search approach improves the searching phase, but the overall time complexity remains (O(n\log n)) because sorting is still required.

---

# 📌 LeetCode Information

- **Problem:** Find Target Indices After Sorting Array
- **Problem Number:** 2089
- **Difficulty:** Easy
- **Topics:** Array, Binary Search, Sorting
- **Language:** C++

## ⭐ Key Learning

> **Sort the array first, then collect every index where the value equals the target. Because the traversal is left to right, the resulting indices are already in increasing order.**
