# 🔎 LeetCode 35 – Search Insert Position

## 1. Problem Statement

Given a sorted array of distinct integers `nums` and a target value, return the index if the target is found.

If the target is not found, return the index where it would be inserted in order to maintain the sorted array.

You must write an algorithm with **O(log n) runtime complexity**.

## 2. Examples

### Example 1

**Input:**

```cpp
nums = [1,3,5,6]
target = 5
```

**Output:**

```cpp
2
```

**Explanation:**

The target `5` is already present at index `2`.

### Example 2

**Input:**

```cpp
nums = [1,3,5,6]
target = 2
```

**Output:**

```cpp
1
```

**Explanation:**

The target `2` is not present.

It should be inserted between `1` and `3` to maintain sorted order.

Therefore, the insertion index is `1`.

### Example 3

**Input:**

```cpp
nums = [1,3,5,6]
target = 7
```

**Output:**

```cpp
4
```

**Explanation:**

The target `7` is greater than every element.

Therefore, it should be inserted at the end of the array.

### Example 4

**Input:**

```cpp
nums = [1,3,5,6]
target = 0
```

**Output:**

```cpp
0
```

**Explanation:**

The target `0` is smaller than every element.

Therefore, it should be inserted at index `0`.

## 3. Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` contains distinct values sorted in ascending order.
- `-10^4 <= target <= 10^4`

## 4. Approach – Binary Search

### Concept

We use Binary Search to find the target element in a sorted array.

If the target exists, we return its index.

If the target does not exist, we return the position where it should be inserted.

We maintain two pointers:

- `start` → Starting index of the search range.
- `end` → Ending index of the search range.

We calculate the middle index:

```cpp
int mid = start + (end - start) / 2;
```

There are three possible cases.

**Case 1: Target found**

If:

```cpp
nums[mid] == target
```

We return the middle index:

```cpp
return mid;
```

**Case 2: Middle element is greater than target**

If:

```cpp
nums[mid] > target
```

The target must be on the left side.

Therefore:

```cpp
end = mid - 1;
```

**Case 3: Middle element is smaller than target**

If:

```cpp
nums[mid] < target
```

The target must be on the right side.

Therefore:

```cpp
start = mid + 1;
```

When the loop finishes, the target is not present.

At this point, `start` represents the correct insertion position.

Therefore:

```cpp
return start;
```

## 5. Step-by-Step Algorithm

1. Initialize `start = 0`.
2. Initialize `end = nums.size() - 1`.
3. Run a loop while `start <= end`.
4. Calculate the middle index:
   ```cpp
   int mid = start + (end - start) / 2;
   ```
5. Check whether `nums[mid] == target`.
6. If true, return `mid`.
7. If `nums[mid] > target`, update:
   ```cpp
   end = mid - 1;
   ```
8. Otherwise, update:
   ```cpp
   start = mid + 1;
   ```
9. Continue until the search range becomes empty.
10. Return `start` as the insertion position.

## 6. C++ Solution – Your Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;

        while(start<=end)
        {
            int mid = start+(end-start)/2;

            if(nums[mid] == target)
            {
                return mid;
            }

            else if(nums[mid]>target){
                end = mid-1;
            }

            else{
                start = mid+1;
                
            }
        }
        return start;
    }
};
```

**Your code is correct.** No changes are required for the given constraints.

## 7. Dry Run – Your Approach

**Input:**

```cpp
nums = [1,3,5,6]
target = 2
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

Check:

```cpp
nums[mid] == target
3 == 2
```

False.

Next condition:

```cpp
nums[mid] > target
3 > 2
```

True.

Update:

```cpp
end = mid - 1
end = 0
```

| Variable | Value |
|---|---:|
| start | 0 |
| end | 0 |
| mid | 1 |
| nums[mid] | 3 |
| target | 2 |

### Iteration 2

Calculate middle:

```cpp
mid = 0 + (0 - 0) / 2
mid = 0
```

Check:

```cpp
nums[mid] == target
1 == 2
```

False.

Next condition:

```cpp
nums[mid] > target
1 > 2
```

False.

Therefore, execute the `else` block:

```cpp
start = mid + 1
start = 1
```

| Variable | Value |
|---|---:|
| start | 1 |
| end | 0 |
| mid | 0 |
| nums[mid] | 1 |
| target | 2 |

Now:

```cpp
start = 1
end = 0
```

Since `start <= end` is false, the loop stops.

Final statement:

```cpp
return start;
```

**Output:**

```cpp
1
```

The target `2` should be inserted at index `1`.

## 8. Complete Dry Run Table

| Iteration | start | end | mid | nums[mid] | Comparison | Update |
|---|---:|---:|---:|---:|---|---|
| 1 | 0 | 3 | 1 | 3 | `3 > 2` | `end = 0` |
| 2 | 0 | 0 | 0 | 1 | `1 < 2` | `start = 1` |
| End | 1 | 0 | - | - | Loop stops | Return 1 |

**Final Answer: `1`**

## 9. Important Operations Explained

### `int start = 0`

Stores the starting index of the array.

### `int end = nums.size() - 1`

Stores the last valid index of the array.

### `while(start <= end)`

Continues searching while the search range is valid.

### `int mid = start + (end - start) / 2`

Calculates the middle index.

This formula avoids potential integer overflow compared with `(start + end) / 2`.

### `nums[mid] == target`

Checks whether the target is found.

If true, return the index immediately.

### `end = mid - 1`

Moves the search range towards the left.

### `start = mid + 1`

Moves the search range towards the right.

### `return start`

Returns the correct insertion position when the target is not found.

This is the most important part of your solution.

## 10. Why Do We Return `start`?

Consider:

```cpp
nums = [1,3,5,6]
target = 4
```

The target `4` is not present.

After Binary Search finishes:

```cpp
start = 2
end = 1
```

The target belongs between `3` and `5`.

Therefore, its insertion position is index `2`.

```cpp
return start;
```

Output:

```cpp
2
```

**Important observation:**

When Binary Search finishes without finding the target:

- All elements before `start` are smaller than the target.
- All elements from `start` onwards are greater than the target.

Therefore, `start` is the correct insertion index.

## 11. Edge Cases

| Input | Target | Expected Output | Explanation |
|---|---:|---:|---|
| `[1,3,5,6]` | 5 | 2 | Target exists |
| `[1,3,5,6]` | 2 | 1 | Insert in the middle |
| `[1,3,5,6]` | 7 | 4 | Insert at the end |
| `[1,3,5,6]` | 0 | 0 | Insert at the beginning |
| `[1]` | 1 | 0 | Single element found |
| `[1]` | 2 | 1 | Insert after the element |

## 12. Time and Space Complexity

### Time Complexity: O(log n)

Binary Search divides the search range approximately in half during each iteration.

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

No additional data structure is required.

Therefore:

```cpp
O(1)
```

## 13. Alternative Approach – Lower Bound

C++ provides a built-in function called `lower_bound()`.

It returns an iterator pointing to the first element that is not less than the target.

This is exactly the required insertion position.

### C++ Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
```

### Complexity Analysis

- **Time Complexity:** O(log n)
- **Auxiliary Space Complexity:** O(1) for this operation.

Your manual Binary Search solution is useful for understanding how the algorithm works internally.

## 14. Approach Comparison

| Feature | Your Binary Search | `lower_bound()` |
|---|---|---|
| Technique | Manual Binary Search | STL Binary Search |
| Target Found | Returns its index | Returns its iterator position |
| Target Not Found | Returns `start` | Returns insertion position |
| Time Complexity | O(log n) | O(log n) |
| Auxiliary Space | O(1) | O(1) |
| Learning Value | Understands Binary Search | Understands STL |

## 15. Important Concepts Learned

- Binary Search
- Sorted Arrays
- Search Space Reduction
- Lower Bound Concept
- Insertion Position
- `start` and `end` Pointers
- Middle Index Calculation
- C++ STL `lower_bound()`

## 16. Key Takeaway

The main lesson from this problem is that Binary Search can be used not only to find an element but also to find its correct insertion position.

**Remember:**

- `nums[mid] == target` → Return `mid`.
- `nums[mid] > target` → Search left.
- `nums[mid] < target` → Search right.
- Target not found → Return `start`.

The most important line in your solution is:

```cpp
return start;
```

It gives the correct insertion position after the search range becomes empty.

## 17. LeetCode Information

- **Problem Number:** 35
- **Problem Name:** Search Insert Position
- **Difficulty:** Easy
- **Topics:** Array, Binary Search
- **Language:** C++
- **Approach:** Iterative Binary Search
- **Time Complexity:** O(log n)
- **Auxiliary Space Complexity:** O(1)
- **Status:** Solved