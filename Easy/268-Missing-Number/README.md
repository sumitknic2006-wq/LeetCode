# 🔢 268. Missing Number

## 📌 Problem Statement

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

## 💡 Examples

### Example 1

**Input:**
```text
nums = [3, 0, 1]
```

**Output:**
```text
2
```

**Explanation:**

The numbers should be `[0, 1, 2, 3]`.

The number `2` is missing from the array.

### Example 2

**Input:**
```text
nums = [0, 1]
```

**Output:**
```text
2
```

**Explanation:**

The numbers should be `[0, 1, 2]`.

The number `2` is missing.

### Example 3

**Input:**
```text
nums = [9, 6, 4, 2, 3, 5, 7, 0, 1]
```

**Output:**
```text
8
```

**Explanation:**

The numbers should range from `0` to `9`. The number `8` is missing.

## ⚙️ Constraints

- `n == nums.length`
- `1 <= n <= 10⁴`
- `0 <= nums[i] <= n`
- All the numbers of `nums` are unique.

## 🧠 Approach 1: Mathematical Formula

### Concept

The sum of the first `n` natural numbers starting from `0` is:

`total = n * (n + 1) / 2`

Because exactly one number is missing, subtracting the actual array sum from the expected sum gives the missing number.

### Steps

1. Calculate `n = nums.size()`.
2. Calculate the expected sum using `n * (n + 1) / 2`.
3. Traverse the array and calculate the actual sum.
4. Subtract the actual sum from the expected sum.
5. Return the result.

## 💻 Code (C++)

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int total = n * (n + 1) / 2;

        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
        }

        return total - sum;
    }
};
```

## 🔍 Dry Run

**Input:**
```text
nums = [3, 0, 1]
```

### Step 1: Calculate the array size

```text
n = nums.size()
n = 3
```

### Step 2: Calculate the expected sum

```text
total = n * (n + 1) / 2
      = 3 * (3 + 1) / 2
      = 3 * 4 / 2
      = 6
```

The complete range `[0, 3]` should have a sum of `6`.

### Step 3: Calculate the actual sum

Initially:

```text
sum = 0
```

| `i` | `nums[i]` | Calculation | `sum` |
|---:|---:|---|---:|
| 0 | 3 | 0 + 3 | 3 |
| 1 | 0 | 3 + 0 | 3 |
| 2 | 1 | 3 + 1 | 4 |

Final actual sum:

```text
sum = 4
```

### Step 4: Find the missing number

```text
missing = total - sum
        = 6 - 4
        = 2
```

**Final Output:**
```text
2
```

## 🔑 Understanding Important Operations

### 1. `nums.size()`

Returns the number of elements in the array.

### 2. Mathematical formula

```cpp
int total = n * (n + 1) / 2;
```

This calculates the sum of all integers from `0` through `n`.

### 3. Actual sum

```cpp
sum = sum + nums[i];
```

Adds every element of the given array.

### 4. Find the difference

```cpp
return total - sum;
```

Since exactly one number is missing, the difference equals that number.

## ⏱️ Complexity Analysis

- **Time Complexity:** O(n), because the array is traversed once.
- **Auxiliary Space Complexity:** O(1), because only a few variables are used.

## 🚀 Approach 2: XOR

### Concept

The XOR operator (`^`) has two useful properties:

- `x ^ x = 0`
- `x ^ 0 = x`

If we XOR all numbers from `0` through `n` and all elements in the array, every number that appears in both sets cancels out. Only the missing number remains.

### 💻 Code (C++)

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            missing ^= i ^ nums[i];
        }

        return missing;
    }
};
```

### Complexity Analysis

- **Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(1)

## 📊 Approach Comparison

| Feature | Mathematical Formula | XOR |
|---|---|---|
| Technique | Expected sum − actual sum | XOR cancellation |
| Time Complexity | O(n) | O(n) |
| Auxiliary Space | O(1) | O(1) |
| Main concept | Arithmetic | Bit manipulation |
| Difficulty | Easy to understand | Requires XOR understanding |

## 📚 Important Concepts Learned

- Array traversal
- Mathematical formulas
- Summation
- Missing element detection
- XOR bitwise operator
- Time and space complexity

## ✅ Key Takeaway

The Mathematical Formula approach is simple and efficient. Calculate the expected sum of `[0, n]`, calculate the actual sum of the array, and subtract the two.

**Remember:** Both the Mathematical Formula and XOR approaches take O(n) time and O(1) auxiliary space. Your submitted approach is correct.

## 🏆 LeetCode Information

- **Problem:** 268. Missing Number
- **Difficulty:** Easy
- **Topics:** Array, Hash Table, Math, Binary Search, Bit Manipulation
- **Language:** C++
- **Your Approach:** Mathematical Formula
- **Alternative Approach:** XOR
