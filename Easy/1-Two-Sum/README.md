# 🎯 1. Two Sum

## 📌 Problem Statement

You are given an array of integers `nums` and an integer `target`. Return the **indices of the two numbers** such that they add up to `target`.

You may assume that each input has exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

## 💡 Examples

### Example 1

**Input:**
```text
nums = [2, 7, 11, 15], target = 9
```

**Output:**
```text
[0, 1]
```

**Explanation:**

`nums[0] + nums[1] = 2 + 7 = 9`

Since the sum equals the target, we return indices `[0, 1]`.

### Example 2

**Input:**
```text
nums = [3, 2, 4], target = 6
```

**Output:**
```text
[1, 2]
```

**Explanation:**

`nums[1] + nums[2] = 2 + 4 = 6`

Therefore, the answer is `[1, 2]`.

### Example 3

**Input:**
```text
nums = [3, 3], target = 6
```

**Output:**
```text
[0, 1]
```

**Explanation:**

`nums[0] + nums[1] = 3 + 3 = 6`

Both elements have the same value, but they are at different indices.

## ⚙️ Constraints

- `2 <= nums.length <= 10⁴`
- `-10⁹ <= nums[i] <= 10⁹`
- `-10⁹ <= target <= 10⁹`
- Only one valid answer exists.

## 🧠 Approach 1: Brute Force

### Concept

We use two nested loops to check every possible pair of elements.

- The outer loop selects the first element using index `i`.
- The inner loop selects the second element using index `j = i + 1`.
- We calculate `nums[i] + nums[j]`.
- If the sum equals `target`, we store both indices in the answer vector.
- Finally, we return the answer.

### 💻 Code (C++)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }

        return ans;
    }
};
```

## 🔍 Dry Run

**Input:**
```text
nums = [2, 7, 11, 15]
target = 9
```

Initially:

```text
ans = []
```

| `i` | `j` | `nums[i]` | `nums[j]` | Sum | Result |
|---:|---:|---:|---:|---:|---|
| 0 | 1 | 2 | 7 | 9 | Match found |
| 0 | 2 | 2 | 11 | 13 | No match |
| 0 | 3 | 2 | 15 | 17 | No match |
| 1 | 2 | 7 | 11 | 18 | No match |
| 1 | 3 | 7 | 15 | 22 | No match |
| 2 | 3 | 11 | 15 | 26 | No match |

When `i = 0` and `j = 1`:

```cpp
if (nums[0] + nums[1] == target)
```

```text
2 + 7 == 9
```

The condition is true, so:

```cpp
ans.push_back(0);
ans.push_back(1);
```

Final output:

```text
[0, 1]
```

## ⏱️ Complexity Analysis

### Time Complexity: O(n²)

We use two nested loops to check possible pairs. In the worst case, the number of comparisons grows quadratically with the array size.

### Space Complexity: O(1) Auxiliary Space

The algorithm uses only a constant amount of extra working space, excluding the returned answer vector. The answer vector itself requires O(1) space here because the problem guarantees exactly one valid pair.

## 🚀 Approach 2: Optimized Using Hash Map

### Concept

Instead of checking every pair, we can use an `unordered_map` to find the required complement in approximately constant average time.

For each number:

1. Calculate `complement = target - nums[i]`.
2. Check whether the complement already exists in the hash map.
3. If it exists, return the complement's index and the current index.
4. Otherwise, store the current number and its index.

### 💻 Code (C++)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
```

### Example Dry Run

```text
nums = [2, 7, 11, 15]
target = 9
```

- `i = 0`, number = `2`, complement = `9 - 2 = 7`. The map is empty, so store `{2: 0}`.
- `i = 1`, number = `7`, complement = `9 - 7 = 2`. The map contains `2` at index `0`.
- Return `{0, 1}`.

### Complexity

- **Time:** O(n) average
- **Space:** O(n)

## 📊 Approach Comparison

| Feature | Brute Force | Hash Map |
|---|---|---|
| Technique | Nested loops | Hash map lookup |
| Time Complexity | O(n²) | O(n) average |
| Extra Space | O(1), excluding output | O(n) |
| Best for | Understanding the basic approach | Efficient solution |

## 📚 Important Concepts Learned

- Array traversal
- Nested loops
- Index-based access
- Conditional statements
- Vectors in C++
- Brute force technique
- Hash map and complement lookup
- Time and space complexity

## ✅ Key Takeaway

The Brute Force approach checks every possible pair and is easy to understand, but it takes **O(n²)** time. The Hash Map approach improves the average time complexity to **O(n)** by checking whether the required complement has already been seen.

**Practice goal:** Understand both approaches and be able to explain why `j` starts at `i + 1`, so the same element is never used twice.

## 🏆 LeetCode Information

- **Problem:** 1. Two Sum
- **Difficulty:** Easy
- **Topic:** Array, Hash Table
- **Language:** C++
- **Solved Approach:** Brute Force
- **Optimized Approach:** Hash Map
