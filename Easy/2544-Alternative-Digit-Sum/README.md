# 🔥 Alternating Digit Sum

## 📌 Problem Statement

Given a positive integer `n`, calculate the **alternating digit sum** of `n`.

The digits are added and subtracted alternately, starting with the **most significant digit**.

For example:

```text
n = 521
```

The alternating digit sum is:

```text
5 - 2 + 1 = 4
```

So the answer is:

```text
4
```

---

## 📥 Examples

### Example 1

```text
Input:  n = 521
Output: 4

Explanation:
5 - 2 + 1 = 4
```

### Example 2

```text
Input:  n = 111
Output: 1

Explanation:
1 - 1 + 1 = 1
```

### Example 3

```text
Input:  n = 886996
Output: 0

Explanation:
8 - 8 + 6 - 9 + 9 - 6 = 0
```

---

## 📏 Constraints

* `1 <= n <= 10⁹`

---

## 💡 Approach

The main challenge is that using:

```cpp
n % 10
```

gives us the digits from **right to left**, while the problem asks us to perform the alternating sum from **left to right**.

Therefore, we first reverse the number.

### Steps

1. Reverse the given number.
2. Extract digits from the reversed number.
3. Maintain an index `i`.
4. If the index is even:

   ```text
   Add the digit
   ```
5. If the index is odd:

   ```text
   Subtract the digit
   ```
6. Return the final answer.

---

## 🧠 Why Do We Reverse the Number?

Suppose:

```text
n = 521
```

Directly extracting digits gives:

```text
1 → 2 → 5
```

But we need:

```text
5 → 2 → 1
```

So first we reverse:

```text
521 → 125
```

Now extracting digits from the reversed number gives:

```text
5 → 2 → 1
```

which allows us to perform:

```text
5 - 2 + 1
```

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int alternateDigitSum(int n) {

        int reverse = 0;

        // Reverse the number
        while(n != 0)
        {
            int rem = n % 10;

            reverse = reverse * 10 + rem;

            n = n / 10;
        }

        int ans = 0;
        int i = 0;

        // Calculate alternating digit sum
        while(reverse != 0)
        {
            int rem = reverse % 10;

            // Even index → Add
            if(i % 2 == 0)
            {
                ans = ans + rem;
                i++;
            }

            // Odd index → Subtract
            else
            {
                ans = ans - rem;
                i++;
            }

            reverse = reverse / 10;
        }

        return ans;
    }
};
```

---

## 🔍 Dry Run

Consider:

```text
n = 521
```

### Step 1 — Reverse the Number

Initially:

```text
reverse = 0
```

Extract digits:

```text
521 % 10 = 1
reverse = 0 * 10 + 1 = 1
```

Then:

```text
52 % 10 = 2
reverse = 1 * 10 + 2 = 12
```

Then:

```text
5 % 10 = 5
reverse = 12 * 10 + 5 = 125
```

So:

```text
reverse = 125
```

---

### Step 2 — Calculate Alternating Sum

Now:

```text
reverse = 125
```

#### Index 0

```text
digit = 5
```

Index is even:

```text
ans = 0 + 5
ans = 5
```

#### Index 1

```text
digit = 2
```

Index is odd:

```text
ans = 5 - 2
ans = 3
```

#### Index 2

```text
digit = 1
```

Index is even:

```text
ans = 3 + 1
ans = 4
```

### Final Answer

```text
4
```

---

## 📊 Dry Run Table

For:

```text
n = 521
```

| Index | Digit | Operation | `ans` |
| ----: | ----: | --------- | ----: |
|     0 |     5 | `0 + 5`   |     5 |
|     1 |     2 | `5 - 2`   |     3 |
|     2 |     1 | `3 + 1`   |     4 |

Final:

```text
4
```

---

## 🔍 Another Example

Consider:

```text
n = 886996
```

The alternating sum is:

```text
8 - 8 + 6 - 9 + 9 - 6
```

Calculate step by step:

```text
8 - 8 = 0
0 + 6 = 6
6 - 9 = -3
-3 + 9 = 6
6 - 6 = 0
```

Therefore:

```text
Output = 0
```

---

## ⏱️ Complexity Analysis

### Time Complexity

```text
O(log₁₀ n)
```

The number contains approximately `log₁₀(n)` digits.

We traverse the digits twice:

1. Once to reverse the number.
2. Once to calculate the alternating sum.

Therefore, the overall complexity is still:

```text
O(log₁₀ n)
```

### Space Complexity

```text
O(1)
```

Only a few integer variables are used.

---

## 🧠 Important Logic

The key condition is:

```cpp
if(i % 2 == 0)
```

### Even Index

```text
0, 2, 4, 6, ...
```

We **add** the digit.

### Odd Index

```text
1, 3, 5, 7, ...
```

We **subtract** the digit.

So the pattern becomes:

```text
+  -  +  -  +  -
```

---

## 🆚 Alternative Concept

Another possible way to solve this problem is to convert the number into a string and directly traverse it from left to right.

For example:

```cpp
string s = to_string(n);

int ans = 0;

for(int i = 0; i < s.size(); i++)
{
    int digit = s[i] - '0';

    if(i % 2 == 0)
        ans += digit;
    else
        ans -= digit;
}

return ans;
```

This approach avoids explicitly reversing the number because a string allows us to access digits from left to right directly.

---

## ⚡ Comparison

| Approach         | Technique                         |     Time |    Space |
| ---------------- | --------------------------------- | -------: | -------: |
| Current Approach | Reverse Number + Digit Extraction | O(log n) |     O(1) |
| String Approach  | String + Index                    | O(log n) | O(log n) |

The current approach is completely based on **integer operations** and uses **O(1) extra space**.

---

## 📚 Concepts Used

* Number Manipulation
* Digit Extraction
* `%` Modulo Operator
* `/` Integer Division
* Number Reversal
* Even/Odd Index
* Alternating Sum
* Loops
* Time & Space Complexity

---

## 🎯 LeetCode Information

| Property       | Details                   |
| -------------- | ------------------------- |
| Platform       | LeetCode                  |
| Problem Number | **2544**                  |
| Problem Name   | **Alternating Digit Sum** |
| Difficulty     | **Easy**                  |
| Topic          | Math                      |
| Pattern        | Digit Manipulation        |
| Language       | C++                       |

---

## ⭐ Key Takeaway

The important pattern in this problem is:

```text
Extract Digits
      ↓
Reverse / Process in Correct Order
      ↓
Check Index
      ↓
Even Index → +
Odd Index  → -
      ↓
Alternating Digit Sum
```

For example:

```text
521

5 → +
2 → -
1 → +

5 - 2 + 1 = 4
```

This problem is useful for learning **digit extraction, number reversal, modulo operation, integer division, and index-based alternating operations**.
