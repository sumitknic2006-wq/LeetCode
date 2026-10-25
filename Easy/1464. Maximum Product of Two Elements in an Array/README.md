# 🎯 1464. Maximum Product of Two Elements in an Array

## 📌 Problem Statement

Given the array of integers `nums`, choose two different indices `i` and `j` such that the product `(nums[i] - 1) * (nums[j] - 1)` is maximized.

Return the maximum possible product.

## 💡 Examples

### Example 1

**Input:**
```text
nums = [3, 4, 5, 2]
```

**Output:**
```text
12
```

**Explanation:**

The two largest elements are `5` and `4`.

`(5 - 1) * (4 - 1) = 4 * 3 = 12`

### Example 2

**Input:**
```text
nums = [1, 5, 4, 5]
```

**Output:**
```text
16
```

**Explanation:**

The two largest elements are `5` and `5`.

`(5 - 1) * (5 - 1) = 4 * 4 = 16`

### Example 3

**Input:**
```text
nums = [3, 7]
```

**Output:**
```text
12
```

**Explanation:**

`(7 - 1) * (3 - 1) = 6 * 2 = 12`

## ⚙️ Constraints

- `2 <= nums.length <= 500`
- `1 <= nums[i] <= 10³`

## 🧠 Approach 1: Brute Force

### Concept

Check every possible pair of elements using two nested loops.

1. The outer loop selects the first element using index `i`.
2. The inner loop selects the second element using index `j = i + 1`.
3. Calculate `(nums[i] - 1) * (nums[j] - 1)`.
4. Update `ans` whenever a larger product is found.
5. Return the maximum product.

### 💻 Code (C++)

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int curr = (nums[i] - 1) * (nums[j] - 1);
                ans = max(ans, curr);
            }
        }

        return ans;
    }
};
```

## 🔍 Dry Run — Brute Force

**Input:**
```text
nums = [3, 4, 5, 2]
```

| `i` | `j` | Pair | Product | `ans` |
|---:|---:|---|---:|---:|
| 0 | 1 | (3, 4) | 6 | 6 |
| 0 | 2 | (3, 5) | 8 | 8 |
| 0 | 3 | (3, 2) | 2 | 8 |
| 1 | 2 | (4, 5) | 12 | 12 |
| 1 | 3 | (4, 2) | 3 | 12 |
| 2 | 3 | (5, 2) | 4 | 12 |

**Final Output:**
```text
12
```

## 🧠 Approach 2: Sorting

### Concept

Sort the array in ascending order. After sorting, the two largest elements will be at the last two indices.

1. Calculate `n = nums.size() - 1`.
2. Sort the array using `sort(nums.begin(), nums.end())`.
3. The largest element is `nums[n]`.
4. The second-largest element is `nums[n - 1]`.
5. Calculate their product after subtracting `1` from each.

### 💻 Code (C++)

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() - 1;

        sort(nums.begin(), nums.end());

        int ans = (nums[n] - 1) * (nums[n - 1] - 1);

        return ans;
    }
};
```

### 🔍 Dry Run — Sorting

**Input:**
```text
nums = [3, 4, 5, 2]
```

After sorting:

```text
nums = [2, 3, 4, 5]
```

Now:

```text
n = nums.size() - 1 = 3

nums[n]     = nums[3] = 5
nums[n - 1] = nums[2] = 4
```

Calculate:

```text
ans = (5 - 1) * (4 - 1)
    = 4 * 3
    = 12
```

**Final Output:**
```text
12
```

### ⏱️ Complexity Analysis

- **Time Complexity:** O(n log n), because sorting dominates the runtime.
- **Auxiliary Space:** Depends on the sorting implementation; `std::sort` typically uses O(log n) stack space.

## 🚀 Approach 3: One-Pass Maximum Tracking

### Concept

Instead of sorting the entire array, find the largest and second-largest elements in a single traversal.

Maintain two variables:

- `max1`: Largest element found so far.
- `max2`: Second-largest element found so far.

For each number:

1. If `num > max1`, move `max1` into `max2` and update `max1`.
2. Otherwise, if `num > max2`, update `max2`.
3. After traversing the array, return `(max1 - 1) * (max2 - 1)`.

### 💻 Code (C++)

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;

        for (int num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            }
            else if (num > max2) {
                max2 = num;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};
```

### 🔍 Dry Run — One Pass

**Input:**
```text
nums = [3, 4, 5, 2]
```

Initially:

```text
max1 = INT_MIN
max2 = INT_MIN
```

| Current number | Action | `max1` | `max2` |
|---:|---|---:|---:|
| 3 | Update largest | 3 | INT_MIN |
| 4 | Move 3 to second-largest | 4 | 3 |
| 5 | Move 4 to second-largest | 5 | 4 |
| 2 | No update | 5 | 4 |

Finally:

```text
(max1 - 1) * (max2 - 1)
= (5 - 1) * (4 - 1)
= 4 * 3
= 12
```

**Final Output:**
```text
12
```

### ⏱️ Complexity Analysis

- **Time Complexity:** O(n), because the array is traversed once.
- **Auxiliary Space:** O(1), because only two variables are maintained.

## 📊 Approach Comparison

| Feature | Brute Force | Sorting | One Pass |
|---|---|---|---|
| Technique | Check every pair | Sort array | Track top two |
| Time | O(n²) | O(n log n) | O(n) |
| Auxiliary space | O(1), excluding output | Typically O(log n) | O(1) |
| Modifies input? | No | Yes | No |
| Efficiency | Lowest | Better | Best |

## 📚 Important Concepts Learned

- Nested loops
- Sorting an array
- Finding the largest and second-largest elements
- Greedy-style tracking
- `INT_MIN`
- Range-based `for` loops
- Time and space complexity

## ✅ Key Takeaway

The problem only requires the two largest elements because subtracting `1` preserves their order for the given positive integers.

- **Brute Force:** Easy to understand, but O(n²).
- **Sorting:** Simple and efficient, but O(n log n) and modifies the array.
- **One Pass:** Most efficient, with O(n) time and O(1) auxiliary space.

For an optimized solution, the **One-Pass Maximum Tracking** approach is the best choice.

## 🏆 LeetCode Information

- **Problem:** 1464. Maximum Product of Two Elements in an Array
- **Difficulty:** Easy
- **Topics:** Array, Sorting
- **Language:** C++
- **Approaches:** Brute Force, Sorting, One-Pass Maximum Tracking
