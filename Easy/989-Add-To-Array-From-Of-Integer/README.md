# ➕ 989. Add to Array-Form of Integer

## 📌 Problem Statement

The array-form of an integer `num` is an array representing its digits in left-to-right order.

For example, `num = [1, 2, 0, 0]` represents the integer `1200`.

Given an integer array `num` and an integer `k`, return the array-form of the integer `num + k`.

## 💡 Examples

### Example 1

**Input:**
```text
num = [1, 2, 0, 0], k = 34
```

**Output:**
```text
[1, 2, 3, 4]
```

**Explanation:**

`1200 + 34 = 1234`

Therefore, the result is `[1, 2, 3, 4]`.

### Example 2

**Input:**
```text
num = [2, 7, 4], k = 181
```

**Output:**
```text
[4, 5, 5]
```

**Explanation:**

`274 + 181 = 455`

Therefore, the result is `[4, 5, 5]`.

### Example 3

**Input:**
```text
num = [2, 1, 5], k = 806
```

**Output:**
```text
[1, 0, 2, 1]
```

**Explanation:**

`215 + 806 = 1021`

Therefore, the result is `[1, 0, 2, 1]`.

## ⚙️ Constraints

- `1 <= num.length <= 10⁴`
- `0 <= num[i] <= 9`
- `num` does not contain leading zeros, except for the number `0` itself.
- `1 <= k <= 10⁴`
- The integer represented by `num` can be much larger than a standard integer type can store.

## 🧠 Approach: Digit-by-Digit Addition

### Concept

We add `k` to the array from **right to left**, just like normal addition.

Instead of converting the entire array into an integer, we process one digit at a time.

### Steps

1. Create an empty vector `ans` to store the result digits.
2. Initialize `i = num.size() - 1`, pointing to the last digit.
3. Continue while `i >= 0` or `k > 0`.
4. If `i >= 0`, add `num[i]` to `k` and decrement `i`.
5. Store the last digit using `k % 10`.
6. Remove the processed digit and carry using `k /= 10`.
7. Reverse `ans` because digits were added from right to left.
8. Return `ans`.

## 💻 Code (C++)

```cpp
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;

        int i = num.size() - 1;

        while (i >= 0 || k > 0) {
            if (i >= 0) {
                k += num[i];
                i--;
            }

            ans.push_back(k % 10);
            k /= 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```

## 🔍 Dry Run

**Input:**
```text
num = [1, 2, 0, 0]
k = 34
```

Initially:

```text
ans = []
i = 3
k = 34
```

| Step | `num[i]` | `k` before digit extraction | `k % 10` | `k /= 10` | `ans` |
|---:|---:|---:|---:|---:|---|
| 1 | 0 | 34 | 4 | 3 | `[4]` |
| 2 | 0 | 3 | 3 | 0 | `[4, 3]` |
| 3 | 2 | 2 | 2 | 0 | `[4, 3, 2]` |
| 4 | 1 | 1 | 1 | 0 | `[4, 3, 2, 1]` |

After processing all digits, the result vector is in reverse order.

```text
ans = [4, 3, 2, 1]
```

After reversing:

```text
ans = [1, 2, 3, 4]
```

**Final Output:**
```text
[1, 2, 3, 4]
```

## 🔑 Understanding the Important Operations

### 1. `k += num[i]`

Adds the current digit of `num` to `k`. The remaining value of `k` also carries information from the addition.

### 2. `k % 10`

Extracts the last digit of the current sum.

For example:

```text
34 % 10 = 4
```

### 3. `k /= 10`

Removes the last digit and keeps the remaining value for the next iteration.

For example:

```text
34 / 10 = 3
```

### 4. `while (i >= 0 || k > 0)`

The loop continues if either:
- There are still digits left in `num`, or
- `k` still has digits to process.

This ensures that remaining digits and carry are not lost.

### 5. `reverse(ans.begin(), ans.end())`

Since we process digits from right to left, `ans` initially contains the answer in reverse order. Reversing restores the correct left-to-right order.

## ⏱️ Complexity Analysis

Let `n` be the number of digits in `num` and `d` be the number of digits in `k`.

- **Time Complexity:** O(n + d), including the final reversal.
- **Auxiliary Space Complexity:** O(1), excluding the output vector.
- **Output Space Complexity:** O(n + d) in the worst case.

The algorithm avoids converting the complete number into a built-in integer, so it also works when the represented number is too large for standard integer types.

## 📚 Important Concepts Learned

- Array traversal from right to left
- Digit-by-digit addition
- Modulo operator `%`
- Integer division `/`
- Carry handling
- Vectors in C++
- Reversing an array
- Avoiding integer overflow

## ✅ Key Takeaway

The key idea is to add digits from right to left using `k` to keep track of the remaining value and carry. Extract each result digit with `k % 10`, update `k` with `k /= 10`, and reverse the result at the end.

This method handles very large numbers without converting the entire array into an integer.

## 🏆 LeetCode Information

- **Problem:** 989. Add to Array-Form of Integer
- **Difficulty:** Easy
- **Topics:** Array, Math, Simulation
- **Language:** C++
- **Approach:** Digit-by-Digit Addition
