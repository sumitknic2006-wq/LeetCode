# 🔄 Next Permutation

## 📌 Problem Statement

Given an array of integers `nums`, rearrange the numbers into the **lexicographically next greater permutation** of numbers.

If such an arrangement is not possible, rearrange it into the **lowest possible order**, i.e., sort it in ascending order.

The rearrangement must be done **in-place** and use only constant extra memory.

### What is a Permutation?

A permutation is simply a different arrangement of the same elements.

For example:

```text
[1, 2, 3]

Permutations:
[1, 2, 3]
[1, 3, 2]
[2, 1, 3]
[2, 3, 1]
[3, 1, 2]
[3, 2, 1]
```

The next permutation after:

```text
[1, 2, 3]
```

is:

```text
[1, 3, 2]
```

---

## 💡 Examples

### Example 1

```text
Input:
nums = [1,2,3]

Output:
[1,3,2]
```

### Example 2

```text
Input:
nums = [3,2,1]

Output:
[1,2,3]
```

Because `[3,2,1]` is already the largest permutation.

### Example 3

```text
Input:
nums = [1,1,5]

Output:
[1,5,1]
```

---

## 📏 Constraints

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 100`
* The rearrangement must be performed **in-place**.
* Only constant extra space should be used.

---

# 🧠 Approach 1: Find Pivot Manually

The next permutation algorithm can be implemented manually using **three main steps**.

### Step 1: Find the Pivot

Start from the right side and find the first index `i` such that:

```cpp
nums[i] < nums[i + 1]
```

This index is called the **pivot**.

Why from the right?

Because we want to make the **smallest possible increase** in the current permutation.

---

### Step 2: Find the Next Larger Element

After finding the pivot, again traverse from the right side.

Find the first element greater than:

```cpp
nums[pivot]
```

Then swap them.

Since we are searching from the right, this gives us the **smallest number greater than the pivot**.

---

### Step 3: Reverse the Remaining Part

After swapping, the part after the pivot is still in descending order.

To get the **smallest possible permutation**, reverse that portion.

```text
pivot + 1 → n - 1
```

---

## 🔍 Example Dry Run

Consider:

```text
nums = [1,2,3]
```

### Step 1: Find Pivot

Start from right:

```text
3 > 2
```

So:

```text
pivot = 1
nums[pivot] = 2
```

Array:

```text
[1, 2, 3]
     ↑
   pivot
```

---

### Step 2: Find Next Larger Element

From the right:

```text
3 > 2
```

So swap:

```text
[1, 3, 2]
```

---

### Step 3: Reverse After Pivot

The part after pivot is:

```text
[2]
```

Nothing changes.

Final result:

```text
[1,3,2]
```

---

# 🔍 Another Dry Run

Consider:

```text
nums = [1,2,5,4,3]
```

### Step 1: Find Pivot

Start from right:

```text
4 > 3 ❌
5 > 4 ❌
2 < 5 ✅
```

Therefore:

```text
pivot = 1
```

Array:

```text
[1, 2, 5, 4, 3]
     ↑
   pivot
```

---

### Step 2: Find Next Larger Element

We need an element greater than:

```text
nums[pivot] = 2
```

Starting from right:

```text
3 > 2
```

Swap:

```text
[1,3,5,4,2]
```

---

### Step 3: Reverse the Suffix

Reverse:

```text
[5,4,2]
```

into:

```text
[2,4,5]
```

Final answer:

```text
[1,3,2,4,5]
```

This is the next lexicographically greater permutation.

---

# ⚠️ Special Case: No Pivot

Suppose:

```text
nums = [3,2,1]
```

Check from right:

```text
2 < 1 ❌
3 < 2 ❌
```

No pivot exists.

That means the array is already the **largest permutation**.

Therefore, the next permutation is the smallest permutation:

```text
[1,2,3]
```

So we simply reverse the entire array.

---

# 💻 Approach 1 Code — Manual Implementation

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Find the pivot
        int pivot = -1;

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot exists
        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the next larger element
        for(int i = n - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 3: Reverse the suffix
        int i = pivot + 1;
        int j = n - 1;

        while(i <= j) {
            swap(nums[i++], nums[j--]);
        }
    }
};
```

---

# 🚀 Approach 2: Using STL `next_permutation()`

C++ provides a built-in function:

```cpp
next_permutation(nums.begin(), nums.end());
```

This directly rearranges the array into its next lexicographical permutation.

If the array is already the largest permutation, it rearranges the array into the smallest permutation.

### Code

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
```

---

# ⚙️ How `next_permutation()` Works

Internally, STL follows essentially the same algorithm:

```text
1. Find pivot
       ↓
2. Find next greater element
       ↓
3. Swap
       ↓
4. Reverse suffix
```

So:

```cpp
next_permutation(nums.begin(), nums.end());
```

is basically a concise implementation of the manual algorithm.

---

# 📊 Approach Comparison

| Approach                 | Time Complexity | Space Complexity | Difficulty |
| ------------------------ | --------------: | ---------------: | ---------- |
| Manual Pivot Approach    |            O(n) |             O(1) | Medium     |
| STL `next_permutation()` |            O(n) |             O(1) | Easy       |

---

# ⏱️ Complexity Analysis

## Manual Approach

### Time Complexity

We perform at most three traversals:

```text
Find pivot        → O(n)
Find next greater → O(n)
Reverse suffix    → O(n)
```

Therefore:

```text
O(n) + O(n) + O(n) = O(n)
```

### Space Complexity

Only a few variables are used:

```cpp
pivot
i
j
```

Therefore:

```text
O(1)
```

---

## STL Approach

```cpp
next_permutation(nums.begin(), nums.end());
```

The STL algorithm also works in:

```text
Time:  O(n)
Space: O(1)
```

---

# 🧩 Important Concepts

### 1. Lexicographical Order

The ordering is similar to dictionary ordering.

For example:

```text
[1,2,3]
[1,3,2]
[2,1,3]
```

Here:

```text
[1,3,2]
```

comes immediately after:

```text
[1,2,3]
```

---

### 2. Pivot

The pivot is the first element from the right satisfying:

```cpp
nums[i] < nums[i + 1]
```

It identifies the position where we can make the permutation larger.

---

### 3. Suffix

The elements after the pivot form the suffix.

Before swapping, this suffix is in **descending order**.

After swapping, we reverse it to make it as small as possible.

---

### 4. In-Place Algorithm

The array itself is modified.

No additional array is required.

Therefore:

```text
Space Complexity = O(1)
```

---

# 🧠 Why Do We Find the Pivot From Right?

Suppose:

```text
[1,2,5,4,3]
```

The suffix:

```text
[5,4,3]
```

is already in descending order.

We cannot get a larger permutation by rearranging only this suffix because it is already the maximum arrangement of those elements.

Therefore, we move left until we find:

```text
2 < 5
```

So `2` becomes the pivot.

This allows us to make the **smallest possible increase**.

---

# 🎯 Key Takeaway

The most important pattern for **Next Permutation** is:

```text
Find Pivot
    ↓
Find Next Greater Element
    ↓
Swap
    ↓
Reverse Suffix
```

Remember these three steps:

```text
1️⃣ Pivot
2️⃣ Next Greater
3️⃣ Reverse
```

And when no pivot exists:

```text
Reverse the entire array
```

---

# 🔥 Final Code

### Manual Implementation

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // Find pivot
        int pivot = -1;

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // No pivot → largest permutation
        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find next greater element
        for(int i = n - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Reverse suffix
        int i = pivot + 1;
        int j = n - 1;

        while(i <= j) {
            swap(nums[i++], nums[j--]);
        }
    }
};
```

### STL Implementation

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
```

---

# 📌 LeetCode Information

* **Problem:** Next Permutation
* **Problem Number:** 31
* **Difficulty:** Medium
* **Topic:** Array
* **Concept:** Two Pointers / Greedy / Permutation
* **Language:** C++

---

## ⭐ Key Learning

> **Next Permutation is a classic example of a Greedy + Two Pointer technique where we make the smallest possible change from the right side to obtain the next lexicographically greater arrangement.**
