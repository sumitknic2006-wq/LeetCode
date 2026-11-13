# 🔍 LeetCode 540 – Single Element in a Sorted Array

## 1. Problem Statement

You are given a sorted array consisting of integers where every element appears exactly twice, except for one element that appears only once.

Find and return the single element that appears only once.

Your solution must run in **O(log n) time and O(1) space**.

## 2. Examples

### Example 1

**Input:**

```cpp
nums = [1,1,2,3,3,4,4,8,8]
```

**Output:**

```cpp
2
```

**Explanation:**

Every element appears twice except `2`, which appears only once.

### Example 2

**Input:**

```cpp
nums = [3,3,7,7,10,11,11]
```

**Output:**

```cpp
10
```

**Explanation:**

Every element appears twice except `10`.

## 3. Constraints

- `1 <= nums.length <= 10^5`
- `nums.length` is odd.
- `-10^5 <= nums[i] <= 10^5`
- All elements in `nums` appear exactly twice except one element, which appears exactly once.
- The array is sorted in ascending order.

## 4. Approach – Binary Search + Index Parity

### Concept

We use Binary Search to find the element that appears only once.

The important observation is that before the single element, all pairs start at an even index.

For example:

```cpp
nums = [1,1,2,3,3,4,4,8,8]
```

Index arrangement:

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|---|
| Value | 1 | 1 | 2 | 3 | 3 | 4 | 4 | 8 | 8 |

**Before the single element:**

Pairs are arranged as:

- Index `0, 1`
- Index `3, 4` after accounting for the single element? No. Before the single element, the pairs begin at even indices; after it, the alignment changes.

More precisely:

- Before the single element, pairs begin at even indices: `(0,1)`.
- After the single element, pairs begin at odd indices: `(3,4)`, `(5,6)`, `(7,8)`.

We use this change in index alignment to identify which half contains the single element.

### Important Observation

We always make `mid` an even index.

```cpp
if(mid % 2 == 1)
{
    mid--;
}
```

Now `mid` points to the first index of a potential pair.

We compare:

```cpp
nums[mid] == nums[mid+1]
```

**Case 1: Both elements are equal**

The pair is correctly aligned.

```cpp
start = mid + 2;
```

The single element must be on the right side.

**Case 2: Both elements are not equal**

The pair alignment has changed, or the single element is at `mid`.

```cpp
end = mid;
```

The single element is at `mid` or somewhere on the left side.

We continue until `start == end`.

Finally, return `nums[start]`.

## 5. Step-by-Step Algorithm

1. Initialize `start = 0`.
2. Initialize `end = nums.size() - 1`.
3. Run a loop while `start < end`.
4. Calculate the middle index:
   ```cpp
   int mid = start + (end - start) / 2;
   ```
5. If `mid` is odd, decrement it:
   ```cpp
   if(mid % 2 == 1)
       mid--;
   ```
6. Compare `nums[mid]` with `nums[mid+1]`.
7. If both are equal:
   ```cpp
   start = mid + 2;
   ```
8. Otherwise:
   ```cpp
   end = mid;
   ```
9. Continue until `start == end`.
10. Return `nums[start]`.

## 6. C++ Solution – Corrected Binary Search

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int start = 0, end = nums.size() - 1;

        while(start < end)
        {
            int mid = start + (end - start) / 2;

            // Make mid an even index
            if(mid % 2 == 1)
            {
                mid--;
            }

            // Check whether the pair is correctly aligned
            if(nums[mid] == nums[mid+1])
            {
                start = mid + 2;
            }
            else
            {
                end = mid;
            }
        }

        return nums[start];
    }
};
```

**Why this correction?**

- It avoids accessing `nums[mid-1]`.
- It does not need separate first-element or last-element checks.
- It maintains correctly aligned pairs.
- It satisfies the required O(log n) time complexity.

## 7. Dry Run – Corrected Approach

**Input:**

```cpp
nums = [1,1,2,3,3,4,4,8,8]
```

Initially:

```cpp
start = 0
end = 8
```

### Iteration 1

Calculate middle:

```cpp
mid = 0 + (8 - 0) / 2
mid = 4
```

`mid` is already even.

Compare:

```cpp
nums[mid] == nums[mid+1]
3 == 4
```

Condition is false.

Update:

```cpp
end = mid;
end = 4;
```

| Variable | Value |
|---|---:|
| start | 0 |
| end | 4 |
| mid | 4 |
| nums[mid] | 3 |
| nums[mid+1] | 4 |

### Iteration 2

Calculate middle:

```cpp
mid = 0 + (4 - 0) / 2
mid = 2
```

`mid` is even.

Compare:

```cpp
nums[mid] == nums[mid+1]
2 == 3
```

Condition is false.

Update:

```cpp
end = mid;
end = 2;
```

| Variable | Value |
|---|---:|
| start | 0 |
| end | 2 |
| mid | 2 |
| nums[mid] | 2 |
| nums[mid+1] | 3 |

### Iteration 3

Calculate middle:

```cpp
mid = 0 + (2 - 0) / 2
mid = 1
```

`mid` is odd, so make it even:

```cpp
mid--;
mid = 0;
```

Compare:

```cpp
nums[mid] == nums[mid+1]
1 == 1
```

Condition is true.

Update:

```cpp
start = mid + 2;
start = 2;
```

| Variable | Value |
|---|---:|
| start | 2 |
| end | 2 |
| mid | 0 |
| nums[mid] | 1 |
| nums[mid+1] | 1 |

Now:

```cpp
start = 2
end = 2
```

Since `start < end` is false, the loop stops.

Final statement:

```cpp
return nums[start];
```

**Output:**

```cpp
2
```

## 8. Complete Dry Run Table

| Iteration | start | end | mid before adjustment | mid after adjustment | Comparison | Update |
|---|---:|---:|---:|---:|---|---|
| 1 | 0 | 8 | 4 | 4 | `3 == 4` False | `end = 4` |
| 2 | 0 | 4 | 2 | 2 | `2 == 3` False | `end = 2` |
| 3 | 0 | 2 | 1 | 0 | `1 == 1` True | `start = 2` |
| End | 2 | 2 | - | - | Loop stops | Return `nums[2]` |

**Final Answer: `2`**

## 9. Important Operations Explained

### `int start = 0, end = nums.size() - 1`

Defines the Binary Search range.

### `while(start < end)`

Continues searching until only one possible index remains.

### `int mid = start + (end - start) / 2`

Calculates the middle index.

### `if(mid % 2 == 1)`

Checks whether the middle index is odd.

### `mid--`

Converts an odd middle index into an even index.

This ensures that `mid` represents the beginning of a potential pair.

### `nums[mid] == nums[mid+1]`

Checks whether the two elements form a correctly aligned pair.

### `start = mid + 2`

If the pair is correct, the single element must be on the right.

### `end = mid`

If the pair is not correct, the single element is at `mid` or somewhere on the left.

### `return nums[start]`

Returns the single element when the search range is reduced to one index.

## 10. Why Does Index Parity Work?

Consider:

```cpp
nums = [1,1,2,3,3,4,4,8,8]
```

Before the single element:

```text
Index:  0  1
Value:  1  1
```

Pairs start at even indices.

After the single element:

```text
Index:  3  4
Value:  3  3

Index:  5  6
Value:  4  4

Index:  7  8
Value:  8  8
```

Pairs now start at odd indices.

This happens because the single element shifts the alignment of all subsequent pairs by one position.

Therefore, index parity helps us determine which half contains the single element.

## 11. Edge Cases

| Input | Expected Output | Explanation |
|---|---:|---|
| `[1]` | 1 | Only one element |
| `[1,1,2]` | 2 | Single element at the end |
| `[1,2,2]` | 1 | Single element at the beginning |
| `[1,1,2,3,3]` | 2 | Single element in the middle |
| `[3,3,7,7,10,11,11]` | 10 | Single element in the middle |

## 12. Time and Space Complexity

### Time Complexity: O(log n)

Binary Search reduces the search range approximately by half during every iteration.

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

## 13. Alternative Approach – Your Original Parity Logic

Your original approach also uses index parity, but it checks both the left and right neighbors of `mid`.

The main problem is that this condition can access an invalid index:

```cpp
if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
```

When `mid == 0`, `nums[mid-1]` is invalid.

Your original code needs boundary protection and careful handling of pair alignment. The corrected approach above is simpler because it always compares an even index with its next index.

## 14. Approach Comparison

| Feature | Original Approach | Corrected Approach |
|---|---|---|
| Technique | Binary Search + Parity | Binary Search + Parity |
| Pair Checking | Left and right neighbors | Current and next element |
| Boundary Checks | Requires careful handling | No separate edge checks |
| Search Range | `0` to `n-2` | `0` to `n-1` |
| Time Complexity | Intended O(log n) | O(log n) |
| Auxiliary Space | O(1) | O(1) |
| Recommendation | Needs boundary correction | Simpler and safer |

## 15. Important Concepts Learned

- Binary Search
- Index Parity
- Even and Odd Indices
- Sorted Arrays
- Pair Alignment
- Search Space Reduction
- Boundary Conditions
- O(log n) Optimization

## 16. Key Takeaway

The main lesson from this problem is that Binary Search can be optimized using index parity.

Before the single element, pairs start at even indices. After the single element, pairs start at odd indices.

**Remember:**

- Make `mid` even.
- Compare `nums[mid]` with `nums[mid+1]`.
- If equal → Search right using `start = mid + 2`.
- If not equal → Search left using `end = mid`.
- When `start == end` → Return `nums[start]`.

## 17. LeetCode Information

- **Problem Number:** 540
- **Problem Name:** Single Element in a Sorted Array
- **Difficulty:** Medium
- **Topics:** Array, Binary Search
- **Language:** C++
- **Approach:** Binary Search + Index Parity
- **Time Complexity:** O(log n)
- **Auxiliary Space Complexity:** O(1)
- **Status:** Solved (after boundary correction)