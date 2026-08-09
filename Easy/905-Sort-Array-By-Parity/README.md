# 🔥 Sort Array By Parity

## 📌 Problem Statement

Given an integer array `nums`, move all the **even integers** to the beginning of the array followed by all the **odd integers**.

Return **any array** that satisfies this condition.

In other words:

```text
Even Numbers → Odd Numbers
```

The relative order of the even numbers and odd numbers does **not** need to be preserved.

---

## 📥 Examples

### Example 1

```text
Input:  nums = [3,1,2,4]

Output: [2,4,3,1]

Explanation:
[2,4] are even numbers and [3,1] are odd numbers.
Any answer that satisfies the condition is accepted.
```

### Example 2

```text
Input:  nums = [0]

Output: [0]

Explanation:
0 is an even number.
```

---

## 📏 Constraints

* `1 <= nums.length <= 5000`
* `0 <= nums[i] <= 5000`

---

## 💡 Approach

We use the **Two Pointer / Partitioning** technique.

We maintain a pointer:

```text
j → position where the next even number should be placed
```

The pointer `i` traverses the complete array.

### How it works

* If `nums[i]` is **even**:

  * Swap `nums[i]` with `nums[j]`.
  * Increment `j`.
* If `nums[i]` is **odd**:

  * Do nothing.
  * Continue moving `i`.

At the end:

```text
[ Even Numbers | Odd Numbers ]
```

---

## 🧠 Algorithm

1. Initialize:

   ```cpp
   int n = nums.size();
   int j = 0;
   ```

2. Traverse the array using `i`.

3. Check whether the current number is even:

   ```cpp
   nums[i] % 2 == 0
   ```

4. If it is even:

   ```cpp
   swap(nums[i], nums[j]);
   j++;
   ```

5. Continue until all elements are processed.

6. Return the modified array.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int n = nums.size();

        int j = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }

        return nums;
    }
};
```

---

## 🔍 Dry Run

Consider:

```text
nums = [3, 1, 2, 4]
```

Initially:

```text
j = 0
```

### Step 1

```text
i = 0
nums[i] = 3
```

`3` is odd.

No swap.

```text
[3, 1, 2, 4]
 j
```

---

### Step 2

```text
i = 1
nums[i] = 1
```

`1` is odd.

No swap.

```text
[3, 1, 2, 4]
 j
```

---

### Step 3

```text
i = 2
nums[i] = 2
```

`2` is even.

Swap:

```cpp
swap(nums[2], nums[0]);
```

Array becomes:

```text
[2, 1, 3, 4]
```

Now:

```text
j = 1
```

---

### Step 4

```text
i = 3
nums[i] = 4
```

`4` is even.

Swap:

```cpp
swap(nums[3], nums[1]);
```

Array becomes:

```text
[2, 4, 3, 1]
```

Now:

```text
j = 2
```

### Final Result

```text
[2, 4, 3, 1]
```

All even numbers are at the beginning and all odd numbers are at the end.

---

## 🆚 Alternative Approach — Brute Force

The problem can also be solved using two nested loops.

```cpp
int n = nums.size();

for(int i = 0; i < n; i++)
{
    for(int j = i + 1; j < n; j++)
    {
        if(nums[j] % 2 == 0)
        {
            swap(nums[i], nums[j]);
        }
    }
}

return nums;
```

### Problem With This Approach

The nested loops make the solution slower because we may compare many pairs of elements.

---

## ⚡ Optimized vs Brute Force

| Approach    | Technique    |  Time | Space |
| ----------- | ------------ | ----: | ----: |
| Brute Force | Nested Loops | O(n²) |  O(1) |
| Optimized   | Two Pointer  |  O(n) |  O(1) |

The **Two Pointer** approach is preferred because it processes the array in a single traversal.

---

## ⏱️ Complexity Analysis

### Time Complexity

```text
O(n)
```

We traverse the array only once.

### Space Complexity

```text
O(1)
```

No extra array is used. The original array is modified **in-place**.

---

## 📚 Concepts Used

* Arrays
* Two Pointers
* Array Partitioning
* In-place Algorithm
* `swap()`
* Modulo Operator `%`
* Even and Odd Numbers
* Time & Space Complexity

---

## 🎯 LeetCode Information

| Property       | Details                     |
| -------------- | --------------------------- |
| Platform       | LeetCode                    |
| Problem Number | **905**                     |
| Problem Name   | **Sort Array By Parity**    |
| Difficulty     | **Easy**                    |
| Topic          | Array                       |
| Pattern        | Two Pointers / Partitioning |
| Language       | C++                         |

---

## ⭐ Key Takeaway

The important pattern learned from this problem is:

```text
Two Pointers
      +
Partitioning
      +
In-Place Swapping
      ↓
O(n) Time
O(1) Space
```

Whenever a problem asks you to separate elements into two groups, such as:

```text
Even / Odd
Positive / Negative
0 / Non-Zero
Valid / Invalid
```

the **Two Pointer + Partitioning** technique can often provide an efficient solution.
