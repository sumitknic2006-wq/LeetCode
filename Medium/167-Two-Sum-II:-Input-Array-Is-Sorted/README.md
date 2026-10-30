# 🎯 167. Two Sum II: Input Array Is Sorted

## 📌 Problem Statement

Given a **1-indexed array of integers `numbers`** that is already sorted in non-decreasing order, find two numbers such that they add up to a specific `target` number.

Let these two numbers be `numbers[index1]` and `numbers[index2]`, where:

- `1 <= index1 < index2 <= numbers.length`
- `numbers[index1] + numbers[index2] == target`

Return the indices of the two numbers as an integer array `[index1, index2]` of length 2.

You may not use the same element twice.

Your solution must use only constant extra space.

## 💡 Examples

### Example 1

**Input:**
```text
numbers = [2, 7, 11, 15], target = 9
```

**Output:**
```text
[1, 2]
```

**Explanation:**

`2 + 7 = 9`

The indices are `1` and `2` because the array is 1-indexed.

### Example 2

**Input:**
```text
numbers = [2, 3, 4], target = 6
```

**Output:**
```text
[1, 3]
```

**Explanation:**

`2 + 4 = 6`

The indices are `1` and `3`.

### Example 3

**Input:**
```text
numbers = [-1, 0], target = -1
```

**Output:**
```text
[1, 2]
```

**Explanation:**

`-1 + 0 = -1`

The indices are `1` and `2`.

## ⚙️ Constraints

- `2 <= numbers.length <= 3 * 10⁴`
- `-1000 <= numbers[i] <= 1000`
- `numbers` is sorted in non-decreasing order.
- `-1000 <= target <= 1000`
- The tests are generated such that exactly one solution exists.

## 🧠 Approach: Two Pointers

### Concept

Since the array is already sorted, we can use two pointers instead of checking every possible pair.

We maintain two pointers:

- `start`: Points to the first element of the array.
- `end`: Points to the last element of the array.

Calculate the sum of both elements and compare it with the target.

### Steps

1. Initialize `start = 0` and `end = numbers.size() - 1`.
2. Create an empty vector `ans`.
3. Continue the loop while `start < end`.
4. Calculate `numbers[start] + numbers[end]`.
5. If the sum equals `target`:
   - Store `start + 1` and `end + 1` in the answer.
   - Return the answer.
6. If the sum is greater than `target`, decrease `end`.
7. Otherwise, increase `start`.
8. Return `ans` if no pair is found.

## 💻 Code (C++)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;

        vector<int> ans;

        while (start < end) {
            if (numbers[start] + numbers[end] == target) {
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                return ans;
            }

            else if (numbers[start] + numbers[end] > target) {
                end--;
            }

            else {
                start++;
            }
        }

        return ans;
    }
};
```

## 🔍 Dry Run

**Input:**
```text
numbers = [2, 7, 11, 15]
target = 9
```

Initially:

```text
start = 0
end = 3
ans = []
```

| Step | `start` | `end` | Left Value | Right Value | Sum | Action |
|---:|---:|---:|---:|---:|---:|---|
| 1 | 0 | 3 | 2 | 15 | 17 | Sum > 9, decrement `end` |
| 2 | 0 | 2 | 2 | 11 | 13 | Sum > 9, decrement `end` |
| 3 | 0 | 1 | 2 | 7 | 9 | Target found |

### Step-by-Step Explanation

**Step 1:**

```text
numbers[start] + numbers[end]
= 2 + 15
= 17
```

Since `17 > 9`, we decrease `end`.

```text
end = 2
```

**Step 2:**

```text
2 + 11 = 13
```

Since `13 > 9`, we again decrease `end`.

```text
end = 1
```

**Step 3:**

```text
2 + 7 = 9
```

The sum equals the target.

We store:

```cpp
ans.push_back(start + 1);
ans.push_back(end + 1);
```

Therefore:

```text
ans = [1, 2]
```

**Final Output:**
```text
[1, 2]
```

## 🔑 Understanding Important Conditions

### 1. `while(start < end)`

Ensures that two different elements are selected. Both pointers must not point to the same element.

### 2. `numbers[start] + numbers[end] == target`

If the sum equals the target, we have found our answer.

### 3. `numbers[start] + numbers[end] > target`

Because the array is sorted, the rightmost value is the largest. If the sum is too large, decrease `end` to try a smaller value.

### 4. `numbers[start] + numbers[end] < target`

If the sum is too small, increase `start` to try a larger value.

### 5. `start + 1` and `end + 1`

The problem asks for **1-based indices**, but C++ vectors use 0-based indexing.

For example:

```text
C++ index:       0  1  2  3
Array values:    2  7 11 15
Problem index:   1  2  3  4
```

Therefore, we add `1` to both pointer positions.

## ⏱️ Complexity Analysis

- **Time Complexity:** O(n), because each pointer moves in only one direction and the total number of pointer movements is at most linear.
- **Auxiliary Space Complexity:** O(1), because only two pointers and a fixed-size answer vector are used.

## 🚀 Approach 2: Brute Force

### Concept

Check every possible pair using two nested loops.

1. Select the first element using `i`.
2. Select the second element using `j = i + 1`.
3. If their sum equals the target, return their 1-based indices.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (numbers[i] + numbers[j] == target) {
                    return {i + 1, j + 1};
                }
            }
        }

        return {};
    }
};
```

### Complexity Analysis

- **Time Complexity:** O(n²)
- **Auxiliary Space Complexity:** O(1)

## 📊 Approach Comparison

| Feature | Brute Force | Two Pointers |
|---|---|---|
| Technique | Nested loops | Two pointers |
| Time Complexity | O(n²) | O(n) |
| Auxiliary Space | O(1) | O(1) |
| Uses sorted property | No | Yes |
| Efficiency | Less efficient | Optimal |

## 📚 Important Concepts Learned

- Two-pointer technique
- Sorted arrays
- Array traversal
- Conditional statements
- 0-based and 1-based indexing
- In-place pointer movement
- Time and space complexity

## ✅ Key Takeaway

The Two Pointers approach is efficient because the array is already sorted.

- If the sum is greater than the target, move the right pointer left.
- If the sum is smaller than the target, move the left pointer right.
- If the sum matches the target, return both 1-based indices.

**Remember:** A sorted array often provides an opportunity to use Two Pointers instead of nested loops.

## 🏆 LeetCode Information

- **Problem:** 167. Two Sum II: Input Array Is Sorted
- **Difficulty:** Medium
- **Topics:** Array, Two Pointers, Binary Search
- **Language:** C++
- **Your Approach:** Two Pointers
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)
