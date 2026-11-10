# 🔍 LeetCode 153 – Find Minimum in Rotated Sorted Array

## 1. Problem Statement

Suppose an array of length `n`, sorted in ascending order, is rotated between 1 and `n` times.

For example, the array:

```cpp
[0,1,2,4,5,6,7]
```

might become:

```cpp
[4,5,6,7,0,1,2]
```

Given the rotated sorted array `nums`, return the minimum element of this array.

You must write an algorithm that runs in **O(log n) time**.

## 2. Examples

### Example 1

**Input:**

```cpp
nums = [3,4,5,1,2]
```

**Output:**

```cpp
1
```

**Explanation:**

The original sorted array was `[1,2,3,4,5]`.

After rotation, the array becomes `[3,4,5,1,2]`.

The minimum element is `1`.

### Example 2

**Input:**

```cpp
nums = [4,5,6,7,0,1,2]
```

**Output:**

```cpp
0
```

**Explanation:**

The minimum element in the rotated array is `0`.

### Example 3

**Input:**

```cpp
nums = [11,13,15,17]
```

**Output:**

```cpp
11
```

**Explanation:**

The array is not rotated. Therefore, the first element is the minimum.

## 3. Constraints

- `1 <= nums.length <= 5000`
- `-5000 <= nums[i] <= 5000`
- All the integers of `nums` are unique.
- `nums` is sorted and then rotated between `1` and `n` times.

## 4. Approach – Binary Search

### Concept

We use Binary Search to find the minimum element in a rotated sorted array.

Normally, in a sorted array, the minimum element is at index `0`.

But after rotation, the minimum element may move somewhere in the middle or at the end.

For example:

```cpp
nums = [4,5,6,7,0,1,2]
```

Here:

- First part: `[4,5,6,7]`
- Second part: `[0,1,2]`

The minimum element is the first element of the second part.

We compare:

```cpp
nums[mid] >= nums[0]
```

**Case 1: `nums[mid] >= nums[0]`**

This means the middle element belongs to the first sorted portion.

So, the minimum element must be on the right side.

```cpp
start = mid + 1;
```

**Case 2: `nums[mid] < nums[0]`**

This means the middle element belongs to the second sorted portion.

It may be the minimum element, so we store it in `ans` and search towards the left.

```cpp
ans = nums[mid];
end = mid - 1;
```

We continue until the search range becomes empty.

Finally, return `ans`.

## 5. Step-by-Step Algorithm

1. Initialize `start = 0`.
2. Initialize `end = nums.size() - 1`.
3. Initialize `ans = nums[0]`.
4. Run a loop while `start <= end`.
5. Calculate the middle index:
   ```cpp
   int mid = start + (end - start) / 2;
   ```
6. Check whether `nums[mid] >= nums[0]`.
7. If true, move towards the right:
   ```cpp
   start = mid + 1;
   ```
8. Otherwise:
   - Store `nums[mid]` in `ans`.
   - Move towards the left using `end = mid - 1`.
9. Return `ans`.

## 6. C++ Solution – Your Code

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int start = 0, end = nums.size()-1, ans = nums[0];

        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid]>=nums[0])
            {
                start = mid+1;
            }

            else{
                ans = nums[mid];
                end = mid-1;
            }
        }
        return ans;
    }
};
```

**Your approach is correct.** It uses the first element as a reference to identify the two sorted portions of the rotated array.

## 7. Dry Run – Your Approach

**Input:**

```cpp
nums = [4,5,6,7,0,1,2]
```

Initial values:

```cpp
start = 0
end = 6
ans = nums[0] = 4
```

### Iteration 1

Calculate middle:

```cpp
mid = 0 + (6 - 0) / 2
mid = 3
```

Check:

```cpp
nums[mid] >= nums[0]
7 >= 4
```

Condition is true.

Update:

```cpp
start = mid + 1
start = 4
```

| Variable | Value |
|---|---:|
| start | 4 |
| end | 6 |
| mid | 3 |
| nums[mid] | 7 |
| ans | 4 |

### Iteration 2

Calculate middle:

```cpp
mid = 4 + (6 - 4) / 2
mid = 5
```

Check:

```cpp
nums[mid] >= nums[0]
1 >= 4
```

Condition is false.

Update:

```cpp
ans = nums[mid]
ans = 1

end = mid - 1
end = 4
```

| Variable | Value |
|---|---:|
| start | 4 |
| end | 4 |
| mid | 5 |
| nums[mid] | 1 |
| ans | 1 |

### Iteration 3

Calculate middle:

```cpp
mid = 4 + (4 - 4) / 2
mid = 4
```

Check:

```cpp
nums[mid] >= nums[0]
0 >= 4
```

Condition is false.

Update:

```cpp
ans = nums[mid]
ans = 0

end = mid - 1
end = 3
```

| Variable | Value |
|---|---:|
| start | 4 |
| end | 3 |
| mid | 4 |
| nums[mid] | 0 |
| ans | 0 |

Now:

```cpp
start = 4
end = 3
```

Since `start > end`, the loop stops.

Final result:

```cpp
return ans;
```

**Output:**

```cpp
0
```

## 8. Complete Dry Run Table

| Iteration | start | end | mid | nums[mid] | Condition | ans |
|---|---:|---:|---:|---:|---|---:|
| Initial | 0 | 6 | - | - | - | 4 |
| 1 | 0 | 6 | 3 | 7 | `7 >= 4` True | 4 |
| 2 | 4 | 6 | 5 | 1 | `1 >= 4` False | 1 |
| 3 | 4 | 4 | 4 | 0 | `0 >= 4` False | 0 |
| End | 4 | 3 | - | - | Loop stops | 0 |

**Final Answer: `0`**

## 9. Important Operations Explained

### `int start = 0`

Stores the starting index of the search range.

### `int end = nums.size() - 1`

Stores the ending index of the search range.

### `int ans = nums[0]`

Initially assumes that the first element is the minimum.

This also handles an array that has not been rotated.

### `int mid = start + (end - start) / 2`

Calculates the middle index.

This formula avoids the potential integer overflow associated with `(start + end) / 2`.

### `nums[mid] >= nums[0]`

Checks whether the middle element belongs to the first sorted portion.

If true, we search towards the right.

### `ans = nums[mid]`

Stores the current possible minimum element.

### `end = mid - 1`

Moves the search range towards the left to find a potentially smaller element.

## 10. Why Do We Initialize `ans = nums[0]`?

Consider an array that is not rotated:

```cpp
nums = [11,13,15,17]
```

The minimum element is already at index `0`.

All elements satisfy:

```cpp
nums[mid] >= nums[0]
```

Therefore, the algorithm keeps moving `start` towards the right.

No smaller element is found, so `ans` remains `11`.

Thus, the function returns:

```cpp
11
```

This is why initializing `ans` with `nums[0]` is important.

## 11. Edge Cases

| Input | Expected Output | Explanation |
|---|---:|---|
| `[1]` | 1 | Only one element |
| `[2,1]` | 1 | Minimum is at the last index |
| `[3,1,2]` | 1 | Minimum is in the middle |
| `[4,5,6,7,0,1,2]` | 0 | Rotated sorted array |
| `[11,13,15,17]` | 11 | Array is not rotated |

**Note:** The LeetCode constraints guarantee that the array contains at least one element. If you reuse this function outside those constraints, add an empty-array check before accessing `nums[0]`.

## 12. Time and Space Complexity

### Time Complexity: O(log n)

Binary Search divides the search range approximately in half during each iteration.

For an array of size `n`:

- First iteration: search approximately `n/2` elements.
- Second iteration: search approximately `n/4` elements.
- Third iteration: search approximately `n/8` elements.

Therefore, the time complexity is:

```cpp
O(log n)
```

### Auxiliary Space Complexity: O(1)

We only use a few variables:

- `start`
- `end`
- `mid`
- `ans`

No additional data structure is used.

Therefore:

```cpp
O(1)
```

## 13. Important Concepts Learned

- Binary Search
- Rotated Sorted Array
- Two Sorted Portions
- Search Space Reduction
- Middle Index Calculation
- Conditional Search
- Minimum Element Identification
- Constant Auxiliary Space

## 14. Key Takeaway

The main lesson from this problem is that Binary Search can also be applied to rotated sorted arrays.

Instead of searching linearly, we compare the middle element with the first element to identify which sorted portion contains it.

**Remember:**

- `nums[mid] >= nums[0]` → Search right.
- `nums[mid] < nums[0]` → Store the possible minimum and search left.
- `ans = nums[0]` → Handles an unrotated array.
- Binary Search → Reduces the search range by half.

## 15. LeetCode Information

- **Problem Number:** 153
- **Problem Name:** Find Minimum in Rotated Sorted Array
- **Difficulty:** Medium
- **Topics:** Array, Binary Search
- **Language:** C++
- **Approach:** Binary Search
- **Time Complexity:** O(log n)
- **Auxiliary Space Complexity:** O(1)
- **Status:** Solved
