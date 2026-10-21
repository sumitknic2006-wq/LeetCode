# 🔢 1137. N-th Tribonacci Number

## 📌 Problem Statement

The Tribonacci sequence is defined as follows:

\[
T_0 = 0,\quad T_1 = 1,\quad T_2 = 1
\]

For \(n \geq 0\):

\[
T_{n+3} = T_n + T_{n+1} + T_{n+2}
\]

Given an integer `n`, return the value of \(T_n\).

---

## 💡 Examples

### Example 1

```text
Input: n = 4
Output: 4
```

Explanation:

```text
T0 = 0
T1 = 1
T2 = 1
T3 = 0 + 1 + 1 = 2
T4 = 1 + 1 + 2 = 4
```

### Example 2

```text
Input: n = 25
Output: 1389537
```

---

## 📏 Constraints

- `0 <= n <= 37`

---

# 🧠 Approach 1: Iteration (Three Variables)

This is your **main and efficient approach**.

Instead of calculating the same Tribonacci values repeatedly, we maintain the previous three values in variables.

```cpp
int f0 = 0;
int f1 = 1;
int f2 = 1;
```

- `f0` stores the previous third value.
- `f1` stores the previous second value.
- `f2` stores the previous value.

### Step 1: Handle Base Cases

```cpp
if(n == 0) return 0;
if(n == 1) return 1;
if(n == 2) return 1;
```

The first three Tribonacci values are already known, so we return them directly.

### Step 2: Calculate the Next Value

```cpp
int ans = f0 + f1 + f2;
```

The next Tribonacci number is the sum of the previous three numbers.

### Step 3: Update the Variables

```cpp
f0 = f1;
f1 = f2;
f2 = ans;
```

Move the three values forward by one position.

### Step 4: Return the Answer

After the loop finishes, `f2` contains the required Tribonacci number.

---

## 💻 C++ Code — Your Iterative Approach

```cpp
class Solution {
public:
    int tribonacci(int n) {

        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;

        int f0 = 0;
        int f1 = 1;
        int f2 = 1;

        for(int i = 3; i <= n; i++) {
            int ans = f0 + f1 + f2;

            f0 = f1;
            f1 = f2;
            f2 = ans;
        }

        return f2;
    }
};
```

---

## 🔍 Dry Run

Consider:

```text
n = 5
```

Initial values:

```text
f0 = 0
f1 = 1
f2 = 1
```

| `i` | Calculation | `ans` | Updated `(f0, f1, f2)` |
|---:|---|---:|---|
| 3 | `0 + 1 + 1` | 2 | `(1, 1, 2)` |
| 4 | `1 + 1 + 2` | 4 | `(1, 2, 4)` |
| 5 | `1 + 2 + 4` | 7 | `(2, 4, 7)` |

After the loop:

```text
f2 = 7
```

Output:

```text
7
```

Therefore, \(T_5 = 7\).

---

# 🔁 Approach 2: Recursion

This is the recursive approach from your code.

The idea is to calculate the current Tribonacci number by recursively calculating the previous three values.

\[
T_n = T_{n-1} + T_{n-2} + T_{n-3}
\]

### Base Cases

```cpp
if(n == 0) {
    return 0;
}

if(n == 1) {
    return 1;
}

if(n == 2) {
    return 1;
}
```

These conditions stop the recursion when the answer is already known.

### Recursive Call

```cpp
return tribonacci(n-1)
     + tribonacci(n-2)
     + tribonacci(n-3);
```

Each call generates three more recursive calls until it reaches a base case.

## 💻 C++ Code — Your Recursive Approach

```cpp
class Solution {
public:
    int tribonacci(int n) {

        if(n == 0) {
            return 0;
        }

        if(n == 1) {
            return 1;
        }

        if(n == 2) {
            return 1;
        }

        return tribonacci(n-1)
             + tribonacci(n-2)
             + tribonacci(n-3);
    }
};
```

---

## ⚠️ Why Can Recursion Cause TLE?

The recursive approach recalculates the same values many times.

For example:

```text
tribonacci(5)
├── tribonacci(4)
│   ├── tribonacci(3)
│   ├── tribonacci(2)
│   └── tribonacci(1)
├── tribonacci(3)
└── tribonacci(2)
```

Notice that `tribonacci(3)` is calculated more than once. As `n` grows, the number of repeated calls grows rapidly.

**Time Complexity:** \(O(3^n)\) is a simple upper bound for this recursive approach.

**Space Complexity:** \(O(n)\) for the maximum recursion stack depth.

This approach can become slow and may result in **Time Limit Exceeded (TLE)** for larger inputs because it does not store previously calculated answers.

---

# 📊 Approach Comparison

| Feature | Iterative Approach | Recursive Approach |
|---|---|---|
| Technique | Loop | Recursion |
| Repeated calculations | No | Yes |
| Time Complexity | \(O(n)\) | \(O(3^n)\) upper bound |
| Auxiliary Space | \(O(1)\) | \(O(n)\) |
| Risk of TLE | Low | High for larger inputs |
| Recommended | Yes | For learning recursion |

---

# ⏱️ Complexity Analysis

## Iterative Approach

### Time Complexity

The loop runs from `3` to `n`.

\[
O(n)
\]

### Space Complexity

Only three running values and one temporary variable are used.

\[
O(1)
\]

## Recursive Approach

### Time Complexity

Each non-base call can make three recursive calls. A simple upper bound is:

\[
O(3^n)
\]

### Space Complexity

The recursion depth grows linearly with `n`.

\[
O(n)
\]

---

# 🧩 Important Concepts

### 1. Base Cases

The first three values are predefined:

```text
T0 = 0
T1 = 1
T2 = 1
```

### 2. Recurrence Relation

```text
Tn = T(n-1) + T(n-2) + T(n-3)
```

### 3. Iteration

A loop calculates each new value exactly once.

### 4. Variable Shifting

```cpp
f0 = f1;
f1 = f2;
f2 = ans;
```

These assignments keep the previous three Tribonacci values ready for the next iteration.

### 5. Repeated Recursive Calls

Naive recursion recalculates values that have already been calculated. This is why it is inefficient compared with the iterative approach.

---

# 🎯 Key Takeaway

```text
Tribonacci:
T0 = 0
T1 = 1
T2 = 1

Tn = T(n-1) + T(n-2) + T(n-3)
```

- **Iterative approach:** Calculates each value once, with \(O(n)\) time and \(O(1)\) auxiliary space.
- **Recursive approach:** Easy to understand, but repeats calculations and can become very slow.

---

# 📌 LeetCode Information

- **Problem:** N-th Tribonacci Number
- **Problem Number:** 1137
- **Difficulty:** Easy
- **Topics:** Math, Dynamic Programming, Memoization
- **Language:** C++

## ⭐ Key Learning

> **When a recurrence depends on a fixed number of previous values, maintaining those values iteratively can avoid repeated recursive calculations and reduce auxiliary space to \(O(1)\).**