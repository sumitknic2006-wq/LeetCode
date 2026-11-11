# ⛰️ LeetCode 162 – Find Peak Element

## 1. Problem Statement

A peak element is an element that is strictly greater than its neighbors.

Given an integer array `nums`, find a peak element and return its index.

You may imagine that `nums[-1] = nums[n] = -∞`.

In other words:

- An element at the beginning of the array only needs to be greater than its right neighbor.
- An element at the end of the array only needs to be greater than its left neighbor.
- An element in the middle must be greater than both its neighbors.

You must write an algorithm that runs in **O(log n) time**.

**Important:** The array may contain multiple peaks. You can return the index of any peak element.

## 2. Examples

### Example 1

**Input:**

```cpp
nums = [1,2,3,1]
```

**Output:**

```cpp
2
```

**Explanation:**

`nums[2] = 3` is greater than its neighbors `2` and `1`.

Therefore, index `2` is a peak element.

### Example 2

**Input:**

```cpp
nums = [1,2,1,3,5,6,4]
```

**Output:**

```cpp
5
```

**Explanation:**

There are two peak elements:

- `nums[1] = 2`
- `nums[5] = 6`

Both are valid peaks.

Therefore, returning index `5` is correct.

## 3. Constraints

- `1 <= nums.length <= 1000`
- `-2³¹ <= nums[i] <= 2³¹ - 1`
- `nums[i] != nums[i + 1]` for all valid `i`.
- It is guaranteed that an answer exists.

## 4. Approach – Binary Search

### Concept

We use Binary Search to find a peak element without checking every element.

The main idea is to compare the middle element with its next element.

```cpp
nums[mid] > nums[mid+1]
```

There are two possible cases.

**Case 1: `nums[mid] > nums[mid+1]`**

This means the array is decreasing from `mid` towards the right.

A peak must exist at `mid` or somewhere on its left.

Therefore:

```cpp
end = mid;
```

We include `mid` in the search range because it may itself be a peak.

**Case 2: `nums[mid] < nums[mid+1]`**

This means the array is increasing towards the right.

A peak must exist somewhere on the right side.

Therefore:

```cpp
start = mid + 1;
```

We continue until:

```cpp
start == end
```

At this point, the remaining index is a peak element.

## 5. Step-by-Step Algorithm

1. Initialize `start = 0`.
2. Initialize `end = nums.size() - 1`.
3. Run a loop while `start < end`.
4. Calculate the middle index:
   ```cpp
   int mid = start + (end - start) / 2;
   ```
5. Compare `nums[mid]` with `nums[mid+1]`.
6. If `nums[mid] > nums[mid+1]`:
   ```cpp
   end = mid;
   ```
7. Otherwise:
   ```cpp
   start = mid + 1;
   ```
8. Repeat until `start == end`.
9. Return `start`.

## 6. C++ Solution – Your Code

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int start = 0 , end = nums.size()-1;

        while(start<end)
        {
            int mid = start+(end-start)/2;

            if(nums[mid]>nums[mid+1])
            {
                end = mid;
            }
            else
            {
                start = mid+1;
            }
        }     

        return start;
        
    }
};
```

**Your code is correct.** It uses an optimal Binary Search approach and does not need any major changes.

## 7. Dry Run – Your Approach

**Input:**

```cpp
nums = [1,2,3,1]
```

Initially:

```cpp
start = 0
end = 3
```

### Iteration 1

Calculate middle:

```cpp
mid = 0 + (3 - 0) / 2
mid = 1
```

Compare:

```cpp
nums[mid] > nums[mid+1]
2 > 3
```

Condition is false.

Therefore:

```cpp
start = mid + 1
start = 2
```

| Variable | Value |
|---|---:|
| start | 2 |
| end | 3 |
| mid | 1 |
| nums[mid] | 2 |
| nums[mid+1] | 3 |

### Iteration 2

Calculate middle:

```cpp
mid = 2 + (3 - 2) / 2
mid = 2
```

Compare:

```cpp
nums[mid] > nums[mid+1]
3 > 1
```

Condition is true.

Therefore:

```cpp
end = mid
end = 2
```

| Variable | Value |
|---|---:|
| start | 2 |
| end | 2 |
| mid | 2 |
| nums[mid] | 3 |
| nums[mid+1] | 1 |

Now:

```cpp
start = 2
end = 2
```

Since `start < end` is false, the loop stops.

Final result:

```cpp
return start;
```

**Output:**

```cpp
2
```

The peak element is `nums[2] = 3`.

## 8. Complete Dry Run Table

| Iteration | start | end | mid | nums[mid] | nums[mid+1] | Condition | Update |
|---|---:|---:|---:|---:|---:|---|---|
| 1 | 0 | 3 | 1 | 2 | 3 | `2 > 3` False | `start = 2` |
| 2 | 2 | 3 | 2 | 3 | 1 | `3 > 1` True | `end = 2` |
| End | 2 | 2 | - | - | - | Loop stops | Return 2 |

**Final Answer: `2`**

## 9. Important Operations Explained

### `int start = 0`

Stores the starting index of the search range.

### `int end = nums.size() - 1`

Stores the last index of the array.

### `while(start < end)`

Continues Binary Search until only one possible peak index remains.

We use `<` instead of `<=` because when both pointers become equal, we already have our answer.

### `int mid = start + (end - start) / 2`

Calculates the middle index safely.

### `nums[mid] > nums[mid+1]`

Checks whether the sequence is decreasing after the middle element.

If true, a peak exists at `mid` or on its left.

### `end = mid`

Moves the right boundary to `mid`.

We do not use `mid - 1` because `mid` itself may be the peak.

### `start = mid + 1`

Moves the left boundary towards the right because a peak must exist there when `nums[mid] < nums[mid+1]`.

### `return start`

When the loop stops, `start == end`.

Both point to the peak element's index.

## 10. Why Does This Binary Search Work?

Consider:

```cpp
nums = [1,2,3,4,5,3,1]
```

The array first increases and then decreases.

```text
1 → 2 → 3 → 4 → 5 → 3 → 1
                Peak
```

If the middle element is smaller than its next element, we move right because the sequence is increasing in that direction.

If the middle element is greater than its next element, we move left because a peak must exist at the middle or before it.

This works because adjacent elements are guaranteed to be different.

Also, the virtual boundary values are negative infinity, so a peak is guaranteed to exist.

## 11. Edge Cases

| Input | Expected Output | Explanation |
|---|---:|---|
| `[1]` | 0 | Single element is a peak |
| `[1,2]` | 1 | Last element is a peak |
| `[2,1]` | 0 | First element is a peak |
| `[1,2,3,1]` | 2 | Peak in the middle |
| `[1,2,3,4,5]` | 4 | Peak at the end |
| `[5,4,3,2,1]` | 0 | Peak at the beginning |

## 12. Time and Space Complexity

### Time Complexity: O(log n)

Binary Search reduces the search range approximately by half in every iteration.

For an array of size `n`:

- First iteration: approximately `n/2` elements.
- Second iteration: approximately `n/4` elements.
- Third iteration: approximately `n/8` elements.

Therefore:

```cpp
O(log n)
```

### Auxiliary Space Complexity: O(1)

We only use a few variables:

- `start`
- `end`
- `mid`

No additional array or data structure is required.

Therefore:

```cpp
O(1)
```

## 13. Important Concepts Learned

- Binary Search
- Peak Element
- Increasing and Decreasing Sequences
- Search Space Reduction
- Two-Pointer Boundaries
- Middle Index Calculation
- Boundary Conditions
- O(log n) Optimization

## 14. Key Takeaway

The main lesson from this problem is that Binary Search can find a peak element even when the array is not sorted.

We do not need to search for the exact maximum element.

Instead, we compare:

```cpp
nums[mid] > nums[mid+1]
```

**Remember:**

- If `nums[mid] > nums[mid+1]` → Move left using `end = mid`.
- Otherwise → Move right using `start = mid + 1`.
- When `start == end` → Return that index.

The important concept is that a peak is guaranteed to exist on the selected side.

## 15. LeetCode Information

- **Problem Number:** 162
- **Problem Name:** Find Peak Element
- **Difficulty:** Medium
- **Topics:** Array, Binary Search
- **Language:** C++
- **Approach:** Binary Search
- **Time Complexity:** O(log n)
- **Auxiliary Space Complexity:** O(1)
- **Status:** Solved