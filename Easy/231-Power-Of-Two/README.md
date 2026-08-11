# 🔥 Power of Two

## 📌 Problem Statement

Given an integer `n`, return `true` if it is a **power of two**. Otherwise, return `false`.

An integer `n` is a power of two if there exists an integer `x` such that:

```text
n = 2^x
```

where `x` is a non-negative integer.

### Examples

### Example 1

```text
Input:  n = 1
Output: true

Explanation:
2⁰ = 1
```

### Example 2

```text
Input:  n = 16
Output: true

Explanation:
16 = 2⁴
```

### Example 3

```text
Input:  n = 3
Output: false

Explanation:
3 is not a power of two.
```

---

## 📏 Constraints

* `-2³¹ <= n <= 2³¹ - 1`

---

# 💡 Approach 1 — Count Set Bits

The first approach uses **Bit Manipulation** to count the number of `1` bits in the binary representation of `n`.

```cpp
if(n < 0)
{
    return false;
}

int count = 0;

while(n != 0)
{
    count = count + (n & 1);
    n = n >> 1;
}

return count == 1;
```

### How It Works

Every power of two has exactly **one `1` bit** in its binary representation.

For example:

```text
1  = 0001
2  = 0010
4  = 0100
8  = 1000
16 = 10000
```

Each number contains exactly one `1`.

So we count the number of set bits.

If:

```text
count == 1
```

then the number is a power of two.

---

## 🔍 Understanding the Bit Operations

### `n & 1`

This checks the **last bit** of `n`.

```text
Last bit = 1 → Set bit
Last bit = 0 → Not set
```

### `n >> 1`

This shifts all bits one position to the right.

For example:

```text
8 = 1000
```

After:

```cpp
n >> 1
```

we get:

```text
0100 = 4
```

Therefore, the loop checks every bit one by one.

---

# 💡 Approach 2 — Optimized Bitwise Approach

The optimized solution uses the important bit manipulation pattern:

```cpp
n & (n - 1)
```

### Code

```cpp
if(n <= 0)
    return false;

return (n & (n - 1)) == 0;
```

This is the **preferred approach** because it is shorter and more efficient.

---

# 🧠 Why Does `n & (n - 1)` Work?

A power of two contains exactly **one `1` bit**.

For example:

```text
2  = 0010
4  = 0100
8  = 1000
16 = 10000
```

Now take:

```text
n = 8
```

Binary representation:

```text
8 = 1000
7 = 0111
```

Perform AND:

```text
  1000
& 0111
------
  0000
```

Therefore:

```cpp
(n & (n - 1)) == 0
```

is `true`.

---

## ❌ Why Does It Fail for Non-Powers of Two?

Consider:

```text
n = 10
```

Binary:

```text
10 = 1010
 9 = 1001
```

Now:

```text
  1010
& 1001
------
  1000
```

The result is not zero.

Therefore:

```cpp
(n & (n - 1)) == 0
```

is `false`.

So `10` is not a power of two.

---

# 💻 Final C++ Solution

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n <= 0)
            return false;

        return (n & (n - 1)) == 0;
    }
};
```

---

# 🔍 Dry Run — `n = 16`

Binary representation:

```text
16 = 10000
15 = 01111
```

Perform:

```text
  10000
& 01111
-------
  00000
```

Therefore:

```cpp
(16 & 15) == 0
```

is `true`.

### Final Answer

```text
true
```

---

# 🔍 Dry Run — `n = 10`

Binary representation:

```text
10 = 1010
 9 = 1001
```

Perform:

```text
  1010
& 1001
------
  1000
```

The result is:

```text
1000 != 0000
```

Therefore:

```text
false
```

---

# 🔍 Dry Run — `n = 1`

```text
1 = 0001
0 = 0000
```

Perform:

```text
  0001
& 0000
------
  0000
```

Therefore:

```text
true
```

This is correct because:

```text
2⁰ = 1
```

---

# 🆚 Approach Comparison

| Approach   | Technique      |      Time | Space |
| ---------- | -------------- | --------: | ----: |
| Approach 1 | Count Set Bits | O(log₂ n) |  O(1) |
| Approach 2 | `n & (n - 1)`  |      O(1) |  O(1) |

The **bitwise optimization** is preferred because it checks the condition directly without looping through all bits.

---

# ⏱️ Complexity Analysis

## Approach 1

### Time Complexity

```text
O(log₂ n)
```

We check every bit of `n`.

### Space Complexity

```text
O(1)
```

Only a few variables are used.

---

## Approach 2

### Time Complexity

```text
O(1)
```

Only a fixed number of bitwise operations are performed.

### Space Complexity

```text
O(1)
```

No extra data structure is required.

---

# 📚 Concepts Used

* Mathematics
* Binary Representation
* Bit Manipulation
* Set Bits
* Bitwise AND `&`
* Bitwise Right Shift `>>`
* `n & (n - 1)` Pattern
* Powers of Two
* Time & Space Complexity

---

# 🎯 LeetCode Information

| Property       | Details                 |
| -------------- | ----------------------- |
| Platform       | LeetCode                |
| Problem Number | **231**                 |
| Problem Name   | **Power of Two**        |
| Difficulty     | **Easy**                |
| Topic          | Math / Bit Manipulation |
| Pattern        | Bitwise Operations      |
| Language       | C++                     |

---

# ⭐ Key Takeaway

The most important concept from this problem is:

```cpp
n & (n - 1)
```

For a **positive number**, if:

```cpp
(n & (n - 1)) == 0
```

then the number is a **power of two**.

### Why?

Because a power of two has exactly **one set bit**.

```text
1  → 0001
2  → 0010
4  → 0100
8  → 1000
16 → 10000
```

When we subtract `1`, all bits after the only `1` become `1`, and the original `1` becomes `0`.

Therefore:

```text
Power of Two
      ↓
Exactly One Set Bit
      ↓
n & (n - 1) == 0
      ↓
     true
```

This `n & (n - 1)` pattern is one of the most important **Bit Manipulation techniques in DSA**.
