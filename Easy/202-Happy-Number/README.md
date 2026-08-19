# 🔥 Happy Number

## 📌 Problem Statement

Write an algorithm to determine if a number `n` is a **Happy Number**.

A number is called a **Happy Number** if we repeatedly replace the number by the **sum of the squares of its digits**, and eventually reach:

```text id="3j2d7h"
1
```

If the process enters a cycle and never reaches `1`, then the number is **not a Happy Number**.

---

# 🧠 What is a Happy Number?

Suppose:

```text id="wq5x8k"
n = 19
```

Calculate the sum of squares of its digits:

```text id="f7w0k4"
1² + 9²
= 1 + 81
= 82
```

Now:

```text id="8n0t5j"
82
```

Again:

```text id="t3q9x6"
8² + 2²
= 64 + 4
= 68
```

Again:

```text id="0f5j4s"
68
```

```text id="6r0l8v"
6² + 8²
= 36 + 64
= 100
```

Again:

```text id="o9v3w4"
100
```

```text id="a0s6u2"
1² + 0² + 0²
= 1
```

We reached `1`.

Therefore:

```text id="0d2h6u"
19 is a Happy Number.
```

---

# 📥 Examples

### Example 1

```text id="5b2r7y"
Input:
n = 19

Output:
true
```

Explanation:

```text id="t1s5y5"
19
 ↓
82
 ↓
68
 ↓
100
 ↓
1
```

Since the process reaches `1`:

```text id="8r3x0y"
true
```

---

### Example 2

```text id="q3m6q9"
Input:
n = 2

Output:
false
```

The process eventually enters a cycle and never reaches `1`.

---

## 📏 Constraints

* `1 <= n <= 2³¹ - 1`

---

# 💡 Approach 1 — Initial Approach

The initial approach repeatedly calculates the sum of the squares of the digits.

### Code

```cpp id="6j1g7k"
// while(n != 1)
// {
//     int ans = 0;

//     while(n != 0)
//     {
//         int rem = n % 10;

//         ans = ans + rem * rem;

//         n = n / 10;
//     }

//     n = ans;
// }

// return true;
```

---

# 🧠 How Approach 1 Works

For every number:

1. Extract each digit.
2. Find the square of the digit.
3. Add all squared digits.
4. Replace `n` with that sum.
5. Repeat until `n == 1`.

For example:

```text id="u5b3e2"
n = 19
```

First:

```text id="3okj1y"
1² + 9² = 82
```

Then:

```text id="z2v9s6"
8² + 2² = 68
```

Then:

```text id="y5h6o4"
6² + 8² = 100
```

Then:

```text id="h5h8y2"
1² + 0² + 0² = 1
```

So we return:

```text id="r8f1q7"
true
```

---

# ❌ Problem with Initial Approach

The problem is that the loop:

```cpp id="6r3r1u"
while(n != 1)
```

only stops when `n` becomes `1`.

But what if `n` **never becomes 1**?

The process can enter a **cycle**.

For example, some numbers eventually reach a repeating sequence:

```text id="6q0x3c"
4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 → ...
```

Notice:

```text id="4c5y7v"
4
```

appears again.

Then:

```text id="5q5k9d"
4 → 16 → 37 → ...
```

will repeat forever.

Therefore, this code:

```cpp id="3f7d2v"
while(n != 1)
```

can run indefinitely.

This can cause:

```text id="1h4p9j"
Time Limit Exceeded (TLE)
```

---

# 🚨 Why Does TLE Happen?

The problem is **not** that calculating the square of each digit is slow.

The real problem is:

> We don't know whether the sequence will ever reach `1`.

If the sequence enters a cycle:

```text id="r2j5y9"
A → B → C → D → A → B → C → D → ...
```

the loop continues forever.

Therefore, we need a way to detect whether a number has already appeared.

---

# 💡 Approach 2 — Using `unordered_set`

To detect a cycle, we use:

```cpp id="v5g0n7"
unordered_set<int> ans;
```

The set stores all numbers that we have already seen.

### Main Idea

Before processing `n`, check:

```cpp id="w7x6f4"
if(ans.count(n))
```

If `n` already exists in the set, it means:

```text id="5t7g3p"
The same number appeared before
          ↓
A cycle exists
          ↓
It will never reach 1
          ↓
Return false
```

---

# 💻 C++ Solution

```cpp id="x2f6s7"
class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> seen;

        while(n != 1)
        {
            // Number already appeared → cycle exists
            if(seen.count(n))
            {
                return false;
            }

            // Store current number
            seen.insert(n);

            int sum = 0;

            // Calculate sum of squares of digits
            while(n != 0)
            {
                int rem = n % 10;

                sum = sum + rem * rem;

                n = n / 10;
            }

            n = sum;
        }

        return true;
    }
};
```

> **Note:** Aapke original code mein `unordered_set<int> ans` ke baad andar `int ans = 0` likha gaya tha. C++ mein same scope mein dono variables ka naam `ans` nahi rakh sakte. Isliye README code mein set ka naam `seen` aur sum ka naam `sum` rakha gaya hai.

---

# 🧠 Algorithm

1. Create an empty set:

   ```cpp id="x8q0cz"
   unordered_set<int> seen;
   ```

2. Continue until:

   ```cpp id="d4e8uy"
   n == 1
   ```

3. Check whether `n` has already appeared:

   ```cpp id="3v6v9g"
   if(seen.count(n))
   ```

4. If it already exists:

   ```cpp id="e8v2n5"
   return false;
   ```

5. Otherwise, store it:

   ```cpp id="3v9q8d"
   seen.insert(n);
   ```

6. Calculate the sum of squares of its digits.

7. Assign that sum back to `n`.

8. If eventually:

   ```text id="1f5k6m"
   n == 1
   ```

   return `true`.

---

# 🔍 Dry Run — Happy Number

Consider:

```text id="1x8q0v"
n = 19
```

Initially:

```text id="w8z6w3"
seen = {}
```

### Step 1

```text id="2q9k5m"
n = 19
```

19 is not in the set.

Insert:

```text id="0k9w5x"
seen = {19}
```

Calculate:

```text id="7t5y8p"
1² + 9² = 82
```

So:

```text id="h0d5r4"
n = 82
```

---

### Step 2

```text id="v9z7d1"
n = 82
```

Not present.

```text id="k4v8s2"
seen = {19, 82}
```

Calculate:

```text id="1j4m6v"
8² + 2²
= 64 + 4
= 68
```

So:

```text id="q4h6j8"
n = 68
```

---

### Step 3

```text id="2k7n5v"
n = 68
```

Insert:

```text id="4s8m3d"
seen = {19, 82, 68}
```

Calculate:

```text id="n4x5z2"
6² + 8²
= 36 + 64
= 100
```

So:

```text id="r6f7s2"
n = 100
```

---

### Step 4

```text id="2q6h8v"
n = 100
```

Insert:

```text id="6s4f1k"
seen = {19, 82, 68, 100}
```

Calculate:

```text id="q5j3m8"
1² + 0² + 0²
= 1
```

Now:

```text id="3k7m9q"
n = 1
```

Loop stops.

Return:

```text id="p4f7y1"
true
```

---

# 🔍 Dry Run — Unhappy Number

Consider:

```text id="x5z3q8"
n = 2
```

The sequence eventually becomes:

```text id="7r2m8p"
2
↓
4
↓
16
↓
37
↓
58
↓
89
↓
145
↓
42
↓
20
↓
4
```

Notice that:

```text id="m8q4x1"
4
```

has appeared before.

Therefore:

```text id="6w9j2k"
seen.count(4) == true
```

So:

```cpp id="2s5n7f"
return false;
```

---

# 📊 Dry Run Table

For `n = 2`:

| Step | `n` | Sum of Digit Squares | `seen`        |
| ---: | --: | -------------------: | ------------- |
|    1 |   2 |                    4 | `{2}`         |
|    2 |   4 |                   16 | `{2,4}`       |
|    3 |  16 |                   37 | `{2,4,16}`    |
|    4 |  37 |                   58 | `{2,4,16,37}` |
|    5 |  58 |                   89 | `{... ,58}`   |
|    6 |  89 |                  145 | `{... ,89}`   |
|    7 | 145 |                   42 | `{... ,145}`  |
|    8 |  42 |                   20 | `{... ,42}`   |
|    9 |  20 |                    4 | `{... ,20}`   |
|   10 |   4 |       Already exists | Cycle         |

Therefore:

```text id="e8x5v7"
false
```

---

# 🔍 How Digit Square Sum Works

The code:

```cpp id="4w7k2m"
int rem = n % 10;
sum = sum + rem * rem;
n = n / 10;
```

extracts digits one by one.

For example:

```text id="j5r9q2"
n = 123
```

### First digit

```text id="w3q7h4"
123 % 10 = 3
```

Square:

```text id="7p5k3z"
3 × 3 = 9
```

Then:

```text id="y6f8r2"
n = 123 / 10
n = 12
```

Next digit:

```text id="4m7j9x"
12 % 10 = 2
```

Square:

```text id="6k2f8m"
2 × 2 = 4
```

Finally:

```text id="x4v9n1"
1 × 1 = 1
```

Total:

```text id="h6z3q8"
9 + 4 + 1 = 14
```

---

# 🆚 Approach Comparison

| Approach         | Cycle Detection |                          Time |    Space |
| ---------------- | --------------- | ----------------------------: | -------: |
| Initial Approach | ❌ No            |          Can run indefinitely |     O(1) |
| `unordered_set`  | ✅ Yes           | O(log n) / bounded iterations | O(log n) |

The initial approach can get **TLE** because it doesn't detect cycles.

The `unordered_set` approach solves this problem by remembering previously visited numbers.

---

# ⏱️ Complexity Analysis

Let `d` be the number of digits in the current number.

Calculating the sum of squares takes:

```text id="3x9v6m"
O(d)
```

Since after repeatedly calculating digit-square sums the values become small, the number of iterations is bounded for the given integer range.

The practical complexity is commonly described as:

```text id="9x2k4v"
O(log n)
```

for the digit-processing work over the sequence.

### Space Complexity

The set stores previously encountered values:

```text id="p7y3m5"
O(log n)
```

for the bounded sequence under the problem constraints.

---

# 📚 Concepts Used

* Number Manipulation
* Digit Extraction
* `%` Modulo Operator
* Integer Division
* Sum of Squares
* Hash Set
* `unordered_set`
* Cycle Detection
* Infinite Loop Prevention
* TLE Prevention
* Time & Space Complexity

---

# 🎯 LeetCode Information

| Property       | Details           |
| -------------- | ----------------- |
| Platform       | LeetCode          |
| Problem Number | **202**           |
| Problem Name   | **Happy Number**  |
| Difficulty     | **Easy**          |
| Topic          | Math / Hash Table |
| Pattern        | Cycle Detection   |
| Language       | C++               |

---

# ⭐ Key Takeaway

The most important concept in this problem is **cycle detection**.

The process is:

```text id="1p8y7r"
Number
  ↓
Square Every Digit
  ↓
Add Them
  ↓
New Number
  ↓
Repeat
  ↓
Does it become 1?
 ↙          ↘
Yes          No
 ↓            ↓
true       Check Cycle
              ↓
       Number Repeated?
          ↙       ↘
        Yes        No
         ↓          ↓
       false      Continue
```

### Most Important Logic

```cpp id="9k2m6q"
if(seen.count(n))
{
    return false;
}
```

This line prevents the infinite loop.

If the same number appears again, the sequence has entered a cycle.

### Remember

```text id="8m4q2v"
n → sum of squares of digits → new n
```

If:

```text id="c4v8x1"
new n == 1
```

then:

```text id="7j5k3m"
Happy Number
```

If a number repeats:

```text id="x9q2v6"
Cycle Detected
     ↓
Not Happy
```

This problem is an important example of using a **Hash Set for cycle detection** and understanding why simply using `while(n != 1)` can result in **TLE**.
