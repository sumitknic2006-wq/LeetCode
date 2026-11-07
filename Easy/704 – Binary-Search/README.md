
# LeetCode 704 – Binary Search

## 1. Problem Statement

Given an array of integers `nums` sorted in ascending order and an integer `target`, write a function to search for `target` in `nums`.

If `target` exists in the array, return its index. Otherwise, return `-1`.

**Important:** You must write an algorithm with O(log n) runtime complexity.

## 2. Examples

### Example 1

**Input:**

```cpp
nums = [-1,0,3,5,9,12]
target = 9
```

**Output:**

```cpp
4
```

**Explanation:**

The target `9` exists at index `4`.

### Example 2

**Input:**

```cpp
nums = [-1,0,3,5,9,12]
target = 2
```

**Output:**

```cpp
-1
```

**Explanation:**

The target `2` does not exist in the array.

## 3. Constraints

- 1 ≤ nums.length ≤ 10⁴
- -10⁴ < nums[i], target < 10⁴
- All the integers in `nums` are unique.
- `nums` is sorted in ascending order.

## 4. Approach – Binary Search (Iterative)

### Concept

Binary Search is an efficient searching algorithm used on a **sorted array**.

Instead of checking every element one by one, we repeatedly divide the search range into two halves.

We use three variables:

- `start` – Starting index of the search range.
- `end` – Ending index of the search range.
- `mid` – Middle index of the search range.

At every iteration, we compare `nums[mid]` with `target`.

There are three possible conditions:

**Condition 1: Target Found**

```cpp
if(nums[mid] == target)
```

If the middle element is equal to the target, return `mid`.

**Condition 2: Search Right Half**

```cpp
else if(nums[mid] < target)
```

If the middle element is smaller than the target, the target can only be in the right half.

Update:

```cpp
start = mid + 1;
```

**Condition 3: Search Left Half**

```cpp
else
```

If the middle element is greater than the target, the target can only be in the left half.

Update:

```cpp
end = mid - 1;
```

Continue until the target is found or the search range becomes empty.

### Step-by-Step Algorithm

1. Calculate the size of the array using `nums.size()`.
2. Initialize `start = 0`.
3. Initialize `end = n - 1`.
4. Run a loop while `start <= end`.
5. Calculate the middle index:
   ```cpp
   mid = start + (end - start) / 2;
   ```
6. If `nums[mid] == target`, return `mid`.
7. If `nums[mid] < target`, update `start = mid + 1`.
8. Otherwise, update `end = mid - 1`.
9. If the loop finishes without finding the target, return `-1`.

## 5. C++ Solution – Your Code

```cpp
class Solution {
public:

    int binary(vector<int>& nums, int n, int target)
    {
        int start = 0, end = n-1;

        while(start<=end)
        {
            int mid = start+(end-start)/2;

            if(nums[mid] == target){
                return mid;
            }

            else if(nums[mid]<target)
            {
                start = mid+1;
            }

            else{
                end = mid-1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        return binary(nums,nums.size(),target);
    }
};
```

## 6. Dry Run – Your Approach

**Input:**

```cpp
nums = [-1,0,3,5,9,12]
target = 9
```

Initially:

```cpp
start = 0
end = 5
target = 9
```

### Step-by-step execution

| Step | start | end | mid | nums[mid] | Comparison | Action |
|---|---:|---:|---:|---:|---|---|
| 1 | 0 | 5 | 2 | 3 | 3 < 9 | start = 3 |
| 2 | 3 | 5 | 4 | 9 | 9 == 9 | Return 4 |

### Understanding Each Step

**Step 1:**

```cpp
start = 0;
end = 5;

mid = 0 + (5 - 0) / 2;
mid = 2;
```

Now:

```cpp
nums[mid] = nums[2] = 3;
target = 9;
```

Since:

```cpp
3 < 9
```

The target must be in the right half.

Update:

```cpp
start = mid + 1;
start = 3;
```

**Step 2:**

```cpp
start = 3;
end = 5;

mid = 3 + (5 - 3) / 2;
mid = 4;
```

Now:

```cpp
nums[mid] = nums[4] = 9;
target = 9;
```

Since:

```cpp
nums[mid] == target
```

The target is found.

```cpp
return mid;
return 4;
```

**Final Output:**

```cpp
4
```

## 7. Dry Run – Target Not Found

**Input:**

```cpp
nums = [-1,0,3,5,9,12]
target = 2
```

| Step | start | end | mid | nums[mid] | Comparison | Action |
|---|---:|---:|---:|---:|---|---|
| 1 | 0 | 5 | 2 | 3 | 3 > 2 | end = 1 |
| 2 | 0 | 1 | 0 | -1 | -1 < 2 | start = 1 |
| 3 | 1 | 1 | 1 | 0 | 0 < 2 | start = 2 |

Now:

```cpp
start = 2;
end = 1;
```

The loop condition:

```cpp
start <= end
```

becomes false.

Therefore:

```cpp
return -1;
```

**Final Output:**

```cpp
-1
```

## 8. Important Operations Explained

### `int start = 0, end = n-1;`

Initializes the search range from the first index to the last index.

### `while(start <= end)`

The loop continues while the search range is valid.

We use `<=` because the search must also check the case where only one element remains.

### `int mid = start + (end-start)/2;`

Calculates the middle index.

This formula is preferred over:

```cpp
int mid = (start + end) / 2;
```

because `start + end` could overflow for very large integer indices.

### `nums[mid] == target`

Checks whether the target is present at the middle index.

### `start = mid + 1`

Eliminates the left half, including the middle element, because the middle value is smaller than the target.

### `end = mid - 1`

Eliminates the right half, including the middle element, because the middle value is greater than the target.

### `return -1`

Indicates that the target does not exist in the array.

## 9. Why Does Binary Search Require a Sorted Array?

Binary Search works because the array is sorted.

For example:

```cpp
nums = [1,3,5,7,9,11,13]
target = 11
```

If the middle element is `7`, we know:

- Every element on its left is smaller than `7`.
- Every element on its right is greater than `7`.

Since `11 > 7`, we can safely eliminate the left half.

Without a sorted array, this decision would not be reliable.

## 10. Time and Space Complexity

### Time Complexity: O(log n)

In every iteration, we eliminate approximately half of the remaining search range.

For example:

```text
16 → 8 → 4 → 2 → 1
```

Therefore, the number of iterations grows logarithmically with the array size.

**Time Complexity: O(log n)**

### Auxiliary Space Complexity: O(1)

Your implementation is iterative and uses only a few variables:

- `start`
- `end`
- `mid`
- `n`

No additional array or data structure is required.

**Auxiliary Space Complexity: O(1)**

## 11. Approach Comparison

| Feature | Linear Search | Binary Search |
|---|---|---|
| Technique | Sequential Search | Divide and Conquer |
| Requirement | Unsorted or sorted array | Sorted array |
| Time Complexity | O(n) | O(log n) |
| Auxiliary Space | O(1) | O(1) |
| Searching | One element at a time | Eliminates half the range |
| Efficiency | Slower for large arrays | Faster for large arrays |

## 12. Important Concepts Learned

- Arrays
- Binary Search
- Iterative Approach
- Divide and Conquer
- Two Search Boundaries
- Middle Index Calculation
- Sorted Array
- `while` Loop
- Search Space Reduction
- Time Complexity Optimization

## 13. Key Takeaway

The main lesson from this problem is that **Binary Search reduces the search space by half in every iteration**.

Instead of checking every element, we compare the target with the middle element and decide which half to search next.

**Remember:**

- `nums[mid] == target` → Return `mid`.
- `nums[mid] < target` → Search right half.
- `nums[mid] > target` → Search left half.
- Search range becomes empty → Return `-1`.

**Complexity:**

- Linear Search → O(n)
- Binary Search → O(log n)

Binary Search is one of the most important searching algorithms in DSA and is frequently used in problems involving sorted arrays and search spaces.

## 14. LeetCode Information

- **Problem Number:** 704
- **Problem Name:** Binary Search
- **Difficulty:** Easy
- **Topics:** Array, Binary Search
- **Language:** C++
- **Approach:** Iterative Binary Search
- **Time Complexity:** O(log n)
- **Auxiliary Space Complexity:** O(1)
- **Status:** Solved
