# 🗑️ 27. Remove Element

## 📌 Problem Statement

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in-place.

The relative order of the elements may change. Then return the number of elements in `nums` that are not equal to `val`.

Let the number of remaining elements be `k`. To be accepted:

- The first `k` elements of `nums` must contain the elements that are not equal to `val`.
- The remaining elements of the array do not matter.
- Return `k`.

## 💡 Examples

### Example 1

**Input:**
```text
nums = [3, 2, 2, 3], val = 3
```

**Output:**
```text
2
```

**Explanation:**

Remove both occurrences of `3`. The first two elements can be `[2, 2]`.

### Example 2

**Input:**
```text
nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2
```

**Output:**
```text
5
```

**Explanation:**

There are five elements that are not equal to `2`.

One valid first-five-elements result is `[0, 1, 4, 0, 3]`. Their order does not have to be preserved.

## ⚙️ Constraints

- `0 <= nums.length <= 100`
- `0 <= nums[i] <= 50`
- `0 <= val <= 100`

## 🧠 Approach 1: Two Pointers (Replace from End)

### Concept

We use two pointers:

- `start`: Begins at the first element and moves forward.
- `end`: Begins at the last element and moves backward.

If `nums[start] == val`, replace it with `nums[end]` and decrease `end`. Otherwise, increase `start`.

When the loop finishes, `start` represents the number of valid elements.

### Steps

1. Initialize `start = 0` and `end = nums.size() - 1`.
2. Continue while `start <= end`.
3. If `nums[start] == val`, replace it with `nums[end]` and decrement `end`.
4. Otherwise, increment `start`.
5. Return `start`.

**Important:** When an element is replaced, do not immediately increment `start`. The new value at that position must be checked because it might also equal `val`.

## 💻 Code (C++)

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            if (nums[start] == val) {
                nums[start] = nums[end];
                end--;
            }
            else {
                start++;
            }
        }

        return start;
    }
};
```

## 🔍 Dry Run

**Input:**
```text
nums = [3, 2, 2, 3], val = 3
```

Initially:

```text
start = 0
end = 3
```

| Step | `start` | `end` | `nums[start]` | Action |
|---:|---:|---:|---:|---|
| 1 | 0 | 3 | 3 | Replace with `nums[3] = 3`; decrement `end` |
| 2 | 0 | 2 | 3 | Replace with `nums[2] = 2`; decrement `end` |
| 3 | 0 | 1 | 2 | Not equal to `val`; increment `start` |
| 4 | 1 | 1 | 2 | Not equal to `val`; increment `start` |

The loop stops because `start > end`.

The array may now be:

```text
[2, 2, 2, 3]
```

The elements after the first `k` positions do not matter.

```text
k = start = 2
```

**Final Output:**
```text
2
```

## 🔑 Understanding Important Operations

### 1. `nums[start] == val`

Checks whether the current element needs to be removed from the valid portion.

### 2. `nums[start] = nums[end]`

Replaces the unwanted element with an element from the end. This avoids shifting every element to the left.

### 3. `end--`

Shrinks the unprocessed range from the right.

### 4. `start++`

Moves forward only when the current element is valid.

### 5. `return start`

When the loop finishes, `start` equals the count of valid elements. The valid portion is `nums[0]` through `nums[start - 1]`.

## ⏱️ Complexity Analysis

- **Time Complexity:** O(n), because each pointer moves through the array at most linearly.
- **Auxiliary Space Complexity:** O(1), because the algorithm modifies the array in-place and uses only two pointers.

## 🚀 Approach 2: Slow and Fast Pointers

### Concept

If you want to preserve the relative order of the remaining elements, use a separate write pointer `k`.

Traverse the array once. Whenever `nums[i] != val`, copy it to `nums[k]` and increment `k`.

### 💻 Code (C++)

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
```

### Complexity Analysis

- **Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(1)
- **Relative order:** Preserved

## 📊 Approach Comparison

| Feature | Replace from End | Slow and Fast Pointers |
|---|---|---|
| Time Complexity | O(n) | O(n) |
| Auxiliary Space | O(1) | O(1) |
| Relative order | Not guaranteed | Preserved |
| Best use | Order does not matter | Order should be preserved |

## 📚 Important Concepts Learned

- Two-pointer technique
- In-place array modification
- Swapping/replacing elements
- Loop boundaries
- Removing elements without extra arrays
- Time and space complexity

## ✅ Key Takeaway

Your approach is efficient because it replaces unwanted elements with elements from the end rather than shifting the entire array.

**Remember:** The problem does not require the relative order to be preserved, so the replace-from-end approach is valid. The returned integer tells LeetCode how many elements at the beginning of the array should be considered.

## 🏆 LeetCode Information

- **Problem:** 27. Remove Element
- **Difficulty:** Easy
- **Topics:** Array, Two Pointers
- **Language:** C++
- **Your Approach:** Two Pointers — Replace from End
- **Alternative Approach:** Slow and Fast Pointers
