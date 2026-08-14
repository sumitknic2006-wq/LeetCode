# 🔥 Maximum Product of Two Digits

## 📌 Problem Statement

Given an integer `n`, find the **maximum product of two digits** in the decimal representation of `n`.

In other words, we need to select any two digits from `n` such that their product is maximum.

---

## 📥 Examples

### Example 1

```text
Input:  n = 31
Output: 3

Explanation:
The digits are 3 and 1.

3 × 1 = 3
```

### Example 2

```text
Input:  n = 22
Output: 4

Explanation:
The digits are 2 and 2.

2 × 2 = 4
```

### Example 3

```text
Input:  n = 124
Output: 8

Explanation:
The digits are 1, 2 and 4.

Possible products:

1 × 2 = 2
1 × 4 = 4
2 × 4 = 8

Maximum product = 8
```

---

## 📏 Constraints

* `10 <= n <= 10⁹`

---

## 💡 Approach

We don't need to generate all possible pairs of digits.

The maximum product will always be obtained by multiplying the **two largest digits**.

So we maintain two variables:

```cpp
max1 → largest digit
max2 → second largest digit
```

While traversing every digit:

* If the current digit is greater than `max1`:

  * `max1` becomes `max2`
  * Current digit becomes `max1`
* Otherwise, if the current digit is greater than `max2`:

  * Update `max2`

At the end:

```cpp
max1 * max2
```

gives the maximum product.

---

## 🧠 Algorithm

1. Initialize:

   ```cpp
   int max1 = 0;
   int max2 = 0;
   ```

2. Extract the last digit using:

   ```cpp
   n % 10
   ```

3. Remove the last digit using:

   ```cpp
   n / 10
   ```

4. Compare the extracted digit with `max1`.

5. If the digit is greater than `max1`:

   ```cpp
   max2 = max1;
   max1 = digit;
   ```

6. Otherwise, check whether it is greater than `max2`:

   ```cpp
   max2 = digit;
   ```

7. Continue until all digits are processed.

8. Return:

   ```cpp
   max1 * max2;
   ```

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int maxProduct(int n) {

        int max2 = 0;
        int max1 = 0;

        if(n < 10)
        {
            return n;
        }

        while(n > 0)
        {
            int digit = n % 10;

            n = n / 10;

            if(digit > max1)
            {
                max2 = max1;
                max1 = digit;
            }
            else
            {
                if(digit > max2)
                {
                    max2 = digit;
                }
            }
        }

        return max1 * max2;
    }
};
```

---

# 🔍 Dry Run

Consider:

```text
n = 124
```

Initially:

```text
max1 = 0
max2 = 0
```

### Step 1

Extract digit:

```text
124 % 10 = 4
```

`4 > max1`

So:

```text
max2 = 0
max1 = 4
```

Now:

```text
max1 = 4
max2 = 0
```

---

### Step 2

Remaining number:

```text
12
```

Extract:

```text
12 % 10 = 2
```

`2` is not greater than `max1`, but:

```text
2 > max2
```

So:

```text
max2 = 2
```

Now:

```text
max1 = 4
max2 = 2
```

---

### Step 3

Remaining number:

```text
1
```

Extract:

```text
1 % 10 = 1
```

`1` is not greater than `max1` or `max2`.

So no change.

```text
max1 = 4
max2 = 2
```

---

### Final Answer

```text
max1 * max2

= 4 * 2

= 8
```

Therefore:

```text
Output = 8
```

---

# 📊 Dry Run Table

For:

```text
n = 124
```

| Digit | `max1` | `max2` | Action                     |
| ----: | -----: | -----: | -------------------------- |
|     4 |      4 |      0 | `4` becomes largest        |
|     2 |      4 |      2 | `2` becomes second largest |
|     1 |      4 |      2 | No change                  |

Final:

```text
4 × 2 = 8
```

---

# 🔍 Another Example

Consider:

```text
n = 9875
```

The digits are:

```text
9, 8, 7, 5
```

The two largest digits are:

```text
9 and 8
```

Therefore:

```text
9 × 8 = 72
```

Output:

```text
72
```

---

# 🧠 Why Do We Need Only Two Variables?

We don't need to store every digit.

For the maximum product, we only need:

```text
Largest digit
      +
Second largest digit
```

For example:

```text
n = 583921
```

Even though there are many digits, only:

```text
8 and 9
```

matter.

Therefore:

```text
8 × 9 = 72
```

This makes the solution efficient and uses constant extra space.

---

# 🆚 Alternative Approach

Another approach is to store all digits in a vector and then sort them.

```cpp
vector<int> digits;

while(n > 0)
{
    digits.push_back(n % 10);
    n /= 10;
}

sort(digits.begin(), digits.end());

return digits[digits.size() - 1] *
       digits[digits.size() - 2];
```

However, sorting is unnecessary because we only need the two largest digits.

Our approach finds them directly in a single traversal.

---

# ⚡ Comparison

| Approach         | Technique           |       Time | Space |
| ---------------- | ------------------- | ---------: | ----: |
| Sorting          | Store + Sort Digits | O(d log d) |  O(d) |
| Current Approach | Track Two Maximums  |       O(d) |  O(1) |

Where:

```text
d = number of digits in n
```

The current approach is better because it does not require an extra array or sorting.

---

# ⏱️ Complexity Analysis

### Time Complexity

```text
O(d)
```

where `d` is the number of digits in `n`.

We visit every digit exactly once.

Since the number of digits is limited:

```text
d = O(log₁₀ n)
```

Therefore:

```text
Time = O(log₁₀ n)
```

### Space Complexity

```text
O(1)
```

Only two variables are used to store the largest and second-largest digits.

---

# 📚 Concepts Used

* Number Manipulation
* Digit Extraction
* `%` Modulo Operator
* Integer Division
* Finding Maximum
* Finding Second Maximum
* Greedy Approach
* Single Traversal
* Time & Space Complexity

---

# 🎯 LeetCode Information

| Property       | Details                           |
| -------------- | --------------------------------- |
| Platform       | LeetCode                          |
| Problem Number | **1464**                          |
| Problem Name   | **Maximum Product of Two Digits** |
| Difficulty     | **Easy**                          |
| Topic          | Math                              |
| Pattern        | Digit Manipulation / Greedy       |
| Language       | C++                               |

---

# ⭐ Key Takeaway

The important idea in this problem is:

```text
Find Largest Digit
       +
Find Second Largest Digit
       ↓
Multiply Them
       ↓
Maximum Product
```

The two variables:

```cpp
int max1 = 0;
int max2 = 0;
```

allow us to find the two largest digits without storing the complete number or sorting anything.

### Important Pattern

```text
Current Digit
     ↓
Is digit > max1?
   ↙          ↘
 Yes           No
 ↓              ↓
max2=max1    digit > max2?
max1=digit       ↓
              max2=digit
```

This is a useful **single-pass / constant-space technique** for problems involving the largest and second-largest values.
