# LeetCode 215: Kth Largest Element in an Array

## 1. Problem Statement

Given an integer array `nums` and an integer `k`, return the `k`th largest element in the array.

Note that it is the `k`th largest element in sorted order, not the `k`th distinct element.

## 2. Examples

### Example 1

```cpp
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```

**Explanation:** The second largest element is `5`.

### Example 2

```cpp
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```

**Explanation:** Sorted in ascending order:

`[1,2,2,3,3,4,5,5,6]`

The fourth largest element is `4`.

## 3. Constraints

- `1 <= k <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## 4. Approach: Sorting + Index Calculation

I solved this problem using **Sorting and Index Calculation**.

The main idea is to sort the array in ascending order and directly access the element at the required index.

### Step 1: Calculate the Array Size

```cpp
int n = nums.size();
```

Store the size of the array in `n`.

### Step 2: Sort the Array

```cpp
sort(nums.begin(), nums.end());
```

Sort the array in ascending order.

After sorting:

- Smallest element is at index `0`.
- Largest element is at index `n-1`.

### Step 3: Find the kth Largest Element

```cpp
return nums[n-k];
```

Since the array is sorted in ascending order, the kth largest element is located at index `n-k`.

We do not need to traverse the array again.

## 5. Algorithm

1. Calculate the size of the array and store it in `n`.
2. Sort the array in ascending order using `sort()`.
3. Calculate the required index using `n-k`.
4. Return `nums[n-k]`.

## 6. C++ Solution

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        return nums[n-k];
    }
};
```

## 7. Dry Run

**Input:**

```cpp
nums = [3,2,1,5,6,4]
k = 2
```

### Step 1: Calculate Size

```cpp
n = 6;
k = 2;
```

### Step 2: Sort the Array

```cpp
nums = [1,2,3,4,5,6]
```

### Step 3: Calculate Index

```cpp
index = n-k
index = 6-2
index = 4
```

### Step 4: Return Element

```cpp
nums[4] = 5
```

**Final Output:**

```cpp
5
```

## 8. Understanding the Index Calculation

For an ascending sorted array:

```text
Index:  0  1  2  3  4  5
Array: [1, 2, 3, 4, 5, 6]
```

| k | kth Largest | Index Calculation | Index |
|---:|---:|---|---:|
| 1 | 6 | `6 - 1` | 5 |
| 2 | 5 | `6 - 2` | 4 |
| 3 | 4 | `6 - 3` | 3 |
| 4 | 3 | `6 - 4` | 2 |
| 5 | 2 | `6 - 5` | 1 |
| 6 | 1 | `6 - 6` | 0 |

This is why the formula is:

```cpp
nums[n-k]
```

## 9. Important C++ Concepts

### 1. sort()

The STL `sort()` function sorts elements in ascending order by default.

```cpp
sort(nums.begin(), nums.end());
```

- `nums.begin()` points to the first element.
- `nums.end()` points just past the last element.

### 2. Array Indexing

After sorting, we can access the required element directly through its index.

```cpp
nums[n-k];
```

### 3. Mathematical Index Calculation

Instead of searching for the kth largest element, we calculate its position mathematically.

For an ascending sorted array:

\[
\text{Index} = n-k
\]

## 10. Edge Cases

| Input | k | Output | Explanation |
|---|---:|---:|---|
| `[1]` | 1 | 1 | Single element |
| `[3,2,1]` | 1 | 3 | Largest element |
| `[3,2,1]` | 3 | 1 | Smallest element |
| `[3,2,3,1,2,4,5,5,6]` | 4 | 4 | Duplicates are counted |
| `[5,5,5,5]` | 2 | 5 | All elements are equal |

## 11. Complexity Analysis

### Time Complexity: O(n log n)

- Sorting the array takes O(n log n).
- Accessing `nums[n-k]` takes O(1).
- Therefore, the overall time complexity is O(n log n).

### Auxiliary Space Complexity: O(log n)

- `sort()` typically uses O(log n) stack space.
- No additional array or data structure is created by your solution.

The original `nums` array is modified because it is sorted in place.

## 12. Alternative Approach: Min Heap

We can also solve this problem using a min heap of size `k`.

- Insert elements into the min heap.
- If its size exceeds `k`, remove the smallest element.
- After processing all elements, the top element of the heap is the kth largest.

This approach takes:

- **Time Complexity:** O(n log k)
- **Auxiliary Space Complexity:** O(k)

This can be more efficient than sorting the entire array when `k` is small.

## 13. Sorting vs Min Heap

| Approach | Time Complexity | Auxiliary Space | Concept |
|---|---|---|---|
| Sorting | O(n log n) | O(log n) | Sorting + Index |
| Min Heap | O(n log k) | O(k) | Priority Queue |
| Quickselect | O(n) average | O(1) auxiliary | Partitioning |

Your sorting solution is simple, readable, and correct.

## 14. Key Concepts Learned

- Array Sorting
- Ascending Order
- Index Calculation
- Handling Duplicate Elements
- STL `sort()`
- Sorting vs Heap Optimization
- kth Element Problems

## 15. Key Takeaway

The most important observation in this problem is that after sorting the array in ascending order, the kth largest element is located at index:

```cpp
n - k
```

Instead of searching manually, we can directly access the required element.

**Remember:** The problem asks for the kth largest element, not the kth distinct largest element. Duplicates must be counted.

## 16. LeetCode Information

- **Problem Number:** 215
- **Problem Name:** Kth Largest Element in an Array
- **Difficulty:** Medium
- **Topics:** Array, Sorting, Heap, Divide and Conquer, Quickselect
- **Your Approach:** Sorting + Index Calculation
- **Time Complexity:** O(n log n)
- **Auxiliary Space Complexity:** O(log n)

---

**One problem at a time. One day at a time. Consistency is the key!**