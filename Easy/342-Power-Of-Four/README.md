# 🔥 Power of Four

## 📌 Problem Statement

Given an integer `n`, return `true` if it is a **power of four**. Otherwise, return `false`.

An integer `n` is a power of four if there exists an integer `x` such that:

```text
n = 4^x
```

where `x` is a non-negative integer.

### Examples

### Example 1

```text
Input:  n = 16
Output: true

Explanation:
16 = 4²
```

### Example 2

```text
Input:  n = 5
Output: false

Explanation:
5 is not a power of 4.
```

### Example 3

```text
Input:  n = 1
Output: true

Explanation:
4⁰ = 1
```

---

## 📏 Constraints

* `-2³¹ <= n <= 2³¹ - 1`

---

# 💡 Approach 1 — Using `pow()`

The first approach is to generate powers of `4` and compare them with `n`.

```cpp
if(n < 1)
{
    return false;
}

for(long long i = 0; i <= 20; i++)
{
    if(n == pow(4, i))
    {
        return true;
    }
}

return false;
```

### How It Works

We generate:

```text
4⁰ = 1
4¹ = 4
4² = 16
4³ = 64
4⁴ = 256
...
```

If any generated power is equal to `n`, we return `true`.

Otherwise, we return `false`.

### ⚠️ Note

`pow()` returns a floating-point value, so using it for exact integer-power checking is generally less preferable than an integer or bitwise solution.

---

# 💡 Approach 2 — Repeated Division

A power of four can be repeatedly divided by `4` until it becomes `1`.

```cpp
if(n < 1)
{
    return 0;
}

while(n != 1)
{
    if(n % 4 != 0)
    {
        return 0;
    }

    n /= 4;
}

return 1;
```

### Example

Consider:

```text
n = 64
```

We repeatedly divide by `4`:

```text
64 / 4 = 16
16 / 4 = 4
4 / 4 = 1
```

Since we finally reach `1`, the answer is:

```text
true
```

For:

```text
n = 20
```

```text
20 % 4 = 0
20 / 4 = 5

5 % 4 != 0
```

Therefore:

```text
false
```

---

# 💡 Approach 3 — Bitwise Operator

A power of four is also a power of two with an important property.

For example:

```text
4  = 100₂
16 = 10000₂
64 = 1000000₂
```

There is exactly **one `1` bit**, and that `1` appears at an **even position** starting from position `0`.

The code:

```cpp
if(n <= 0)
    return false;

int zero = 0;
int one = 0;

while(n != 0)
{
    if((n & 1) == 0)
        zero++;
    else
        one++;

    n >>= 1;
}

return (one == 1) && ((zero % 2) == 0);
```

### Explanation

The expression:

```cpp
n & 1
```

checks the last binary bit.

If it is:

```text
0 → even bit
1 → odd bit
```

Then:

```cpp
n >>= 1;
```

moves all bits one position to the right.

At the end:

```cpp
one == 1
```

ensures that `n` originally contained exactly one `1` bit.

And:

```cpp
zero % 2 == 0
```

ensures that the position of that `1` bit is even.

---

# 🚀 Approach 4 — Bitwise Optimization

The most concise solution is:

```cpp
if(n <= 0)
    return false;

return ((n & (n - 1)) == 0) && n % 3 == 1;
```

This is the optimized approach.

---

## 🧠 Why Does `n & (n - 1)` Work?

For a number that is a power of `2`, its binary representation contains exactly one `1`.

For example:

```text
4  = 100
8  = 1000
16 = 10000
```

Now consider:

```text
n = 16

16     = 10000
15     = 01111
----------------
16 & 15 = 00000
```

Therefore:

```cpp
(n & (n - 1)) == 0
```

checks whether `n` is a power of `2`.

But we need a **power of 4**, not just a power of 2.

---

## 🔍 Why `n % 3 == 1`?

Powers of four follow this pattern:

```text
4⁰ = 1
4¹ = 4
4² = 16
4³ = 64
4⁴ = 256
```

When divided by `3`:

```text
1 % 3 = 1
4 % 3 = 1
16 % 3 = 1
64 % 3 = 1
256 % 3 = 1
```

Therefore:

```cpp
n % 3 == 1
```

helps distinguish powers of `4` from other powers of `2`.

### Example

Consider:

```text
n = 8
```

Binary:

```text
1000
```

It is a power of `2`:

```cpp
8 & 7 == 0
```

But:

```text
8 % 3 = 2
```

So:

```cpp
(n & (n - 1)) == 0
```

is `true`, but:

```cpp
n % 3 == 1
```

is `false`.

Therefore:

```text
8 is NOT a power of 4.
```

---

# 💻 Final C++ Solution

```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n <= 0)
            return false;

        return ((n & (n - 1)) == 0) && n % 3 == 1;
    }
};
```

---

# 🔍 Dry Run

Let's take:

```text
n = 16
```

### Step 1 — Check Positive

```text
16 > 0
```

So we continue.

### Step 2 — Check Power of Two

```text
16     = 10000
15     = 01111
----------------
16 & 15 = 00000
```

Therefore:

```cpp
(n & (n - 1)) == 0
```

is `true`.

### Step 3 — Check Power of Four

```text
16 % 3 = 1
```

So:

```cpp
n % 3 == 1
```

is also `true`.

### Final Result

```text
true
```

---

# 🔍 Another Dry Run

Let's take:

```text
n = 8
```

Binary:

```text
8 = 1000
7 = 0111

8 & 7 = 0000
```

So it is a power of `2`.

But:

```text
8 % 3 = 2
```

Therefore:

```cpp
(n % 3 == 1)
```

is `false`.

### Final Result

```text
false
```

---

# 🆚 Approach Comparison

| Approach   | Technique            |      Time | Space |
| ---------- | -------------------- | --------: | ----: |
| Approach 1 | `pow()`              |      O(1) |  O(1) |
| Approach 2 | Repeated Division    | O(log₄ n) |  O(1) |
| Approach 3 | Bitwise Counting     | O(log₂ n) |  O(1) |
| Approach 4 | Bitwise Optimization |      O(1) |  O(1) |

> **Note:** Approach 4 is the most concise and efficient for this problem.

---

# ⏱️ Complexity Analysis

### Time Complexity

```text
O(1)
```

The optimized solution uses a fixed number of bitwise and arithmetic operations.

### Space Complexity

```text
O(1)
```

No extra data structure is used.

---

# 📚 Concepts Used

* Mathematics
* Powers of Four
* Binary Representation
* Bitwise AND `&`
* Bitwise Right Shift `>>`
* `n & (n - 1)` Pattern
* Modulo Operator `%`
* Number Theory
* Time & Space Complexity

---

# 🎯 LeetCode Information

| Property       | Details                 |
| -------------- | ----------------------- |
| Platform       | LeetCode                |
| Problem Number | **342**                 |
| Problem Name   | **Power of Four**       |
| Difficulty     | **Easy**                |
| Topic          | Math / Bit Manipulation |
| Pattern        | Bitwise Operations      |
| Language       | C++                     |

---

# ⭐ Key Takeaway

The most important bit manipulation pattern from this problem is:

```text
n & (n - 1)
```

It can be used to check whether a positive number is a **power of 2**.

For checking a power of `4`:

```cpp
(n & (n - 1)) == 0
```

checks that `n` is a power of `2`, while:

```cpp
n % 3 == 1
```

ensures that it is specifically a power of `4`.

### Final Pattern

```text
Positive Number
      ↓
Power of 2?
      ↓
n & (n - 1) == 0
      ↓
Power of 4?
      ↓
n % 3 == 1
      ↓
     true
```

This problem is a good introduction to **Bit Manipulation** and the `n & (n - 1)` technique, which is frequently useful in DSA.
