# 🔥 Alternating Sum of an Array

## 📌 Problem Statement

Given an integer array `nums`, calculate its **alternating sum**.

The alternating sum is calculated by:

* Adding the elements at **even indices**
* Subtracting the elements at **odd indices**

The pattern is:

```text
+  -  +  -  +  -  ...
```

For example:

```text
nums = [1, 2, 3, 4]
```

The alternating sum is:

```text
1 - 2 + 3 - 4
```

```text
= -2
```

So the answer is:

```text
-2
```

---

# 📥 Examples

### Example 1

```text
Input:
nums = [1, 2, 3, 4]

Output:
-2

Explanation:
1 - 2 + 3 - 4 = -2
```

---

### Example 2

```text
Input:
nums = [5, 4, 3, 2, 1]

Output:
3

Explanation:
5 - 4 + 3 - 2 + 1 = 3
```

---

### Example 3

```text
Input:
nums = [10]

Output:
10

Explanation:
There is only one element at index 0.

10 is added because index 0 is even.
```

---

## 📏 Constraints

The exact constraints depend on the LeetCode 3701 problem statement/version being used.

For this implementation, the important requirements are:

* `nums` is an integer array.
* The array contains at least one element.
* Each element is an integer.

---

# 💡 Approach

The solution uses a simple **index-based traversal**.

We maintain one variable:

```cpp
int sum = 0;
```

Then traverse the complete array.

For every index:

### Even Index

If:

```cpp
i % 2 == 0
```

then add the element:

```cpp
sum += nums[i];
```

### Odd Index

Otherwise:

```cpp
sum -= nums[i];
```

Therefore, the operation pattern becomes:

```text
Index:     0   1   2   3   4   5
Operation: +   -   +   -   +   -
```

---

# 🧠 Algorithm

1. Find the size of the array:

   ```cpp
   int n = nums.size();
   ```

2. Initialize:

   ```cpp
   int sum = 0;
   ```

3. Traverse the array:

   ```cpp
   for(int i = 0; i < n; i++)
   ```

4. Check whether the index is even:

   ```cpp
   if(i % 2 == 0)
   ```

5. If even, add:

   ```cpp
   sum += nums[i];
   ```

6. Otherwise, subtract:

   ```cpp
   sum -= nums[i];
   ```

7. Return `sum`.

---

# 💻 C++ Solution

```cpp
class Solution {
public:
    int alternatingSum(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                sum += nums[i];
            }
            else
            {
                sum -= nums[i];
            }
        }

        return sum;
    }
};
```

---

# 🔍 Dry Run

Consider:

```text
nums = [1, 2, 3, 4]
```

Initially:

```text
sum = 0
```

### Index 0

```text
nums[0] = 1
```

Index is even:

```text
sum = 0 + 1
sum = 1
```

---

### Index 1

```text
nums[1] = 2
```

Index is odd:

```text
sum = 1 - 2
sum = -1
```

---

### Index 2

```text
nums[2] = 3
```

Index is even:

```text
sum = -1 + 3
sum = 2
```

---

### Index 3

```text
nums[3] = 4
```

Index is odd:

```text
sum = 2 - 4
sum = -2
```

### Final Answer

```text
-2
```

---

# 📊 Dry Run Table

For:

```text
nums = [1, 2, 3, 4]
```

| Index | `nums[i]` | Index Type | Operation | `sum` |
| ----: | --------: | ---------- | --------- | ----: |
|     0 |         1 | Even       | `0 + 1`   |     1 |
|     1 |         2 | Odd        | `1 - 2`   |    -1 |
|     2 |         3 | Even       | `-1 + 3`  |     2 |
|     3 |         4 | Odd        | `2 - 4`   |    -2 |

Final:

```text
-2
```

---

# 🔍 Another Example

Consider:

```text
nums = [5, 4, 3, 2, 1]
```

The operations are:

```text
5 - 4 + 3 - 2 + 1
```

Step by step:

```text
5 - 4 = 1
1 + 3 = 4
4 - 2 = 2
2 + 1 = 3
```

Therefore:

```text
Output = 3
```

---

# 🧠 Understanding `i % 2`

The condition:

```cpp
i % 2 == 0
```

checks whether the index is even.

### Even Indices

```text
0
2
4
6
8
...
```

At these indices:

```text
+
```

### Odd Indices

```text
1
3
5
7
9
...
```

At these indices:

```text
-
```

So:

```text
Index       0   1   2   3   4
            ↓   ↓   ↓   ↓   ↓
Operation   +   -   +   -   +
```

---

# 🔄 Visual Representation

```text
nums = [10, 20, 30, 40, 50]

          +    -    +    -    +
          ↓    ↓    ↓    ↓    ↓

          10 - 20 + 30 - 40 + 50

               ↓

               30
```

Therefore:

```text
10 - 20 + 30 - 40 + 50 = 30
```

---

# ⚡ Why Is This Approach Efficient?

We don't need:

* Sorting
* Extra arrays
* Nested loops
* Any complex data structure

We simply traverse the array once and perform addition/subtraction based on the index.

Therefore, the solution is very efficient.

---

# ⏱️ Complexity Analysis

## Time Complexity

```text
O(n)
```

We traverse every element exactly once.

Where:

```text
n = nums.size()
```

---

## Space Complexity

```text
O(1)
```

Only one extra variable:

```cpp
int sum = 0;
```

is used.

No extra array or data structure is created.

---

# 🆚 Alternative Approach

The same logic can also be written using a sign variable.

```cpp
int sum = 0;
int sign = 1;

for(int i = 0; i < nums.size(); i++)
{
    sum += sign * nums[i];

    sign = -sign;
}

return sum;
```

Here:

```text
sign = 1  → Add
sign = -1 → Subtract
```

The pattern becomes:

```text
+1 → -1 → +1 → -1 → +1
```

However, the given solution using:

```cpp
i % 2
```

is very straightforward and easy to understand.

---

# 📚 Concepts Used

* Arrays
* Array Traversal
* Indexing
* Even/Odd Index
* Modulo Operator `%`
* Addition
* Subtraction
* Single Loop
* Time Complexity
* Space Complexity

---

# 🎯 LeetCode Information

| Property       | Details                                 |
| -------------- | --------------------------------------- |
| Platform       | LeetCode                                |
| Problem Number | **3701**                                |
| Problem Name   | **Alternating Sum of an Array**         |
| Difficulty     | Easy                                    |
| Topic          | Array                                   |
| Pattern        | Array Traversal / Alternating Operation |
| Language       | C++                                     |

---

# ⭐ Key Takeaway

The main pattern to remember is:

```text
Even Index → Add
Odd Index  → Subtract
```

Using:

```cpp
if(i % 2 == 0)
    sum += nums[i];
else
    sum -= nums[i];
```

The complete pattern is:

```text
nums[0] - nums[1] + nums[2] - nums[3] + nums[4] ...
```

### Final Pattern

```text
Array
  ↓
Traverse Each Element
  ↓
Check Index
  ↓
Even → +
Odd  → -
  ↓
Return Sum
```

This is a simple but important **array traversal + index-based condition** pattern that is useful in many DSA problems.
