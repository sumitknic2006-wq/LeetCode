# 🔥 Find the Kth Largest Integer in the Array

## 📌 Problem Statement

You are given an array of strings `nums`, where each string represents a **positive integer**.

Return the string that represents the **kth largest integer** in `nums`.

### Important

The numbers are given as strings because they can be **very large**, and they may not fit inside normal integer data types.

For example:

```text id="l6q2d9"
"2"
"11"
"100"
```

As numbers:

```text id="7h5d7k"
2 < 11 < 100
```

So the correct numerical ordering is:

```text id="8v0k4n"
"2" < "11" < "100"
```

---

## 📥 Examples

### Example 1

```text id="4m5b3s"
Input:
nums = ["3","6","7","10"]
k = 4

Output:
"3"
```

Explanation:

Sorted numerically:

```text id="8cq6js"
3 < 6 < 7 < 10
```

The 4th largest integer is:

```text id="f74f9z"
3
```

---

### Example 2

```text id="0bl3qm"
Input:
nums = ["2","21","12","1"]
k = 3

Output:
"2"
```

Numerical order:

```text id="3h1z5a"
1 < 2 < 12 < 21
```

The 3rd largest integer is:

```text id="kr5v8f"
2
```

---

### Example 3

```text id="1z4i7q"
Input:
nums = ["0","0"]
k = 2

Output:
"0"
```

---

## 📏 Constraints

* `1 <= k <= nums.length <= 10⁴`
* `1 <= nums[i].length <= 100`
* `nums[i]` consists of only digits.
* `nums[i]` does not contain leading zeros.
* `nums[i]` represents a positive integer.
* The integers in `nums` may be very large.

---

# 💡 Approach 1 — Custom Sorting

Since the numbers are stored as strings, we **cannot directly compare them using normal string sorting**.

For example:

```text id="h2h9r8"
"10" < "2"
```

in lexicographical/string comparison, but numerically:

```text id="y4y9n0"
10 > 2
```

So we need a custom comparator.

### Main Idea

To compare two positive integers represented as strings:

1. Compare their lengths.
2. If lengths are different:

   * The longer string represents the larger number.
3. If lengths are equal:

   * Compare them lexicographically.

For example:

```text id="9n5w8m"
"123" and "45"
```

Lengths:

```text id="0hx9qq"
3 > 2
```

Therefore:

```text id="t8kq3p"
123 > 45
```

If the lengths are equal:

```text id="3r8q9c"
"123" and "456"
```

then normal string comparison works:

```text id="1m5t3s"
"123" < "456"
```

---

## 💻 C++ Solution — Sorting

```cpp id="5gjwz8"
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {

        int n = nums.size();

        sort(nums.begin(), nums.end(), [](string a, string b) {

            // Compare lengths
            if(a.size() != b.size())
                return a.size() < b.size();

            // Same length → lexicographical comparison
            return a < b;
        });

        return nums[n - k];
    }
};
```

---

# 🧠 Understanding the Comparator

The comparator is:

```cpp id="8p0r3q"
[](string a, string b)
```

It tells `sort()` how two strings should be ordered.

### Case 1 — Different Lengths

```cpp id="x3q4ka"
if(a.size() != b.size())
    return a.size() < b.size();
```

Example:

```text id="c0t7m2"
a = "100"
b = "25"
```

Lengths:

```text id="h1l6z3"
a.size() = 3
b.size() = 2
```

Therefore:

```text id="f2f4m6"
"25" < "100"
```

---

### Case 2 — Same Length

If both numbers have the same number of digits:

```cpp id="1ih9st"
return a < b;
```

Example:

```text id="9c9n3u"
a = "123"
b = "456"
```

Since both have 3 digits:

```text id="1m1n1a"
123 < 456
```

So:

```text id="3bd4xq"
"123" < "456"
```

---

# 🔍 Why `nums[n-k]`?

After sorting, the array is in **ascending order**.

For example:

```text id="q8f2kw"
nums = ["2", "5", "7", "10"]
```

Indices:

```text id="qv91sd"
Index:   0    1    2     3
Value:   2    5    7    10
```

For:

```text id="v3f5f4"
k = 1
```

The largest element is at:

```text id="q8z2pk"
n - k
= 4 - 1
= 3
```

So:

```text id="x4p4jg"
nums[3] = "10"
```

For:

```text id="1m1v94"
k = 2
```

we get:

```text id="6m1q6p"
n - k
= 4 - 2
= 2
```

Therefore:

```text id="h9m8sx"
nums[2] = "7"
```

So the formula is:

```cpp id="x7d8uk"
nums[n - k]
```

---

# 🔍 Dry Run

Consider:

```text id="z1d0g4"
nums = ["3", "6", "7", "10"]
k = 4
```

### Step 1 — Sort

Using our custom comparator:

```text id="z8j9z3"
["3", "6", "7", "10"]
```

Already sorted:

```text id="t0y5y5"
3 < 6 < 7 < 10
```

So:

```text id="0h8z1r"
n = 4
k = 4
```

### Step 2 — Find Index

```text id="b6k5y8"
n - k
= 4 - 4
= 0
```

Therefore:

```text id="m2j6kt"
nums[0] = "3"
```

### Final Answer

```text id="q1j8l5"
"3"
```

---

# 💡 Approach 2 — Reverse Traversal

There is another simple approach after sorting.

Instead of directly using:

```cpp id="6f8qxy"
nums[n-k]
```

we can start from the largest element and move backwards.

```cpp id="r6e3x9"
int j = 1;

for(int i = n - 1; i >= 0; i--)
{
    if(j == k)
        return nums[i];

    j++;
}
```

### How It Works

After sorting:

```text id="6s5c2q"
[smallest ... largest]
```

We start from:

```text id="4b8h1s"
n - 1
```

which is the largest element.

Then:

```text id="n8b4g1"
j = 1 → largest
j = 2 → second largest
j = 3 → third largest
...
```

When:

```cpp id="3p4p9y"
j == k
```

we return the current element.

---

# 🔍 Dry Run — Reverse Traversal

Suppose:

```text id="5z7x2s"
nums = ["3", "6", "7", "10"]
k = 2
```

After sorting:

```text id="3q8t6b"
["3", "6", "7", "10"]
```

Start:

```text id="j0y1g8"
i = 3
j = 1
```

### First Iteration

```text id="6y9g6q"
j = 1
```

Not equal to `k`.

Increment:

```text id="q4k7l9"
j = 2
i = 2
```

### Second Iteration

Now:

```text id="8m3d4k"
j == k
```

Return:

```text id="b8n4y1"
nums[2] = "7"
```

Final answer:

```text id="v6w8k3"
"7"
```

---

# 🆚 Approach Comparison

| Approach                        | Technique             |       Time | Extra Space |
| ------------------------------- | --------------------- | ---------: | ----------: |
| Custom Sort + Index             | Sorting               | O(n log n) |   O(log n)* |
| Custom Sort + Reverse Traversal | Sorting + Two Pointer | O(n log n) |   O(log n)* |

`*` The extra space shown is for the sorting implementation's stack/auxiliary requirements; the algorithm itself does not create another array.

The two approaches have the **same overall complexity** because both require sorting.

---

# ⏱️ Complexity Analysis

Let:

```text id="0v2r4m"
n = number of elements
L = maximum length of a number
```

### Sorting Complexity

The array contains `n` strings, and sorting performs approximately:

```text id="a4p0o9"
O(n log n)
```

comparisons.

Each comparison can take up to:

```text id="w4l7k3"
O(L)
```

time because strings may need to be compared character by character.

Therefore, a more precise complexity is:

```text id="0e2r1p"
O(n log n × L)
```

### Space Complexity

The solution does not create another array.

Sorting may use:

```text id="5w8x2s"
O(log n)
```

auxiliary stack space depending on the sorting implementation.

---

# 📚 Concepts Used

* Strings
* Arrays
* Custom Comparator
* `sort()`
* Lexicographical Comparison
* String Length Comparison
* Sorting
* Kth Largest Element
* Array Indexing
* Reverse Traversal
* Lambda Function
* Time & Space Complexity

---

# 🎯 LeetCode Information

| Property       | Details                                       |
| -------------- | --------------------------------------------- |
| Platform       | LeetCode                                      |
| Problem Number | **1985**                                      |
| Problem Name   | **Find the Kth Largest Integer in the Array** |
| Difficulty     | **Medium**                                    |
| Topic          | Array / String / Sorting                      |
| Pattern        | Custom Sorting                                |
| Language       | C++                                           |

---

# ⭐ Key Takeaway

The most important concept in this problem is how to compare **very large integers stored as strings**.

### Numerical String Comparison

```text id="pj3x2j"
Different Length
      ↓
Longer Length = Larger Number
```

If lengths are equal:

```text id="m7v9z3"
Lexicographical Comparison
```

So:

```text id="k1g2d8"
"9" < "10" < "100" < "1000"
```

even though normal string sorting would not always give the correct numerical order.

### Final Pattern

```text id="v2s5k9"
String Numbers
      ↓
Compare Length
      ↓
Same Length?
      ↓
Lexicographical Compare
      ↓
Sort Ascending
      ↓
Kth Largest = nums[n - k]
```

This problem is a good example of using a **custom comparator with `sort()`** when numbers are too large to fit into normal integer data types.
