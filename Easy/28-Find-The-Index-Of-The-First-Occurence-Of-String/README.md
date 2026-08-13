# 🔥 Find the Index of the First Occurrence in a String

## 📌 Problem Statement

Given two strings `haystack` and `needle`, return the index of the **first occurrence** of `needle` in `haystack`.

If `needle` is not part of `haystack`, return:

```text
-1
```

In other words, we need to find the first position where the complete `needle` string occurs inside the `haystack` string.

---

## 📥 Examples

### Example 1

```text
Input:  haystack = "sadbutsad"
        needle   = "sad"

Output: 0

Explanation:
" sad buts ad"
  ↑
The first occurrence of "sad" starts at index 0.
```

### Example 2

```text
Input:  haystack = "leetcode"
        needle   = "leeto"

Output: -1

Explanation:
"leeto" does not occur in "leetcode".
```

### Example 3

```text
Input:  haystack = "hello"
        needle   = "ll"

Output: 2

Explanation:
"hello"
  ↑
"ll" starts at index 2.
```

---

## 📏 Constraints

* `1 <= haystack.length, needle.length <= 10⁴`
* `haystack` and `needle` consist of only lowercase English characters.

---

# 💡 Approach 1 — Brute Force

The first approach checks every possible starting position in `haystack`.

For every index `i`, we compare the characters of `needle` with the corresponding characters of `haystack`.

### Code

```cpp
int n = haystack.size();
int m = needle.size();

for(int i = 0; i <= n - m; i++)
{
    int first = i;
    int second = 0;

    while(second < m)
    {
        if(haystack[first] != needle[second])
        {
            break;
        }
        else
        {
            first++;
            second++;
        }
    }

    if(second == m)
    {
        return first - second;
    }
}

return -1;
```

---

## 🧠 How Brute Force Works

Suppose:

```text
haystack = "hello"
needle   = "ll"
```

We start checking from every possible position.

```text
Index:     0 1 2 3 4
haystack:  h e l l o
```

At index `0`:

```text
h != l
```

So we move to index `1`.

At index `1`:

```text
e != l
```

Move to index `2`.

At index `2`:

```text
l == l
l == l
```

Complete `needle` is matched.

Therefore:

```text
Answer = 2
```

---

# 💡 Approach 2 — KMP Algorithm

The second approach uses the **KMP (Knuth-Morris-Pratt)** string matching algorithm.

KMP improves the searching process by avoiding unnecessary character comparisons.

The main idea is to create an array called:

```text
LPS
```

LPS stands for:

> **Longest Proper Prefix which is also a Suffix**

---

# 🧠 What is LPS?

For every position in the `needle`, `lps[i]` stores the length of the longest proper prefix of the substring `needle[0...i]` that is also a suffix.

For example:

```text
needle = "ababaca"
```

Its LPS array is:

```text
[0, 0, 1, 2, 3, 0, 1]
```

Let's understand one position:

```text
"abab"
```

Prefix:

```text
"ab"
```

Suffix:

```text
"ab"
```

They are equal, so:

```text
lps[3] = 2
```

---

# 🔍 LPS Construction

Your code uses:

```cpp
void lpsfind(vector<int>& lps, string s)
{
    int pre = 0;
    int suf = 1;

    while(suf < s.size())
    {
        if(s[pre] == s[suf])
        {
            lps[suf] = pre + 1;
            suf++;
            pre++;
        }

        else
        {
            if(pre == 0)
            {
                lps[suf] = 0;
                suf++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }
}
```

### Two Pointers

```text
pre → prefix pointer
suf → suffix/current pointer
```

Initially:

```text
pre = 0
suf = 1
```

---

## 🔄 LPS Matching Case

If:

```cpp
s[pre] == s[suf]
```

then we found a matching prefix and suffix.

So:

```cpp
lps[suf] = pre + 1;
```

Then both pointers move forward:

```cpp
pre++;
suf++;
```

---

## ❌ LPS Mismatch Case

If:

```cpp
s[pre] != s[suf]
```

there are two cases.

### Case 1 — `pre == 0`

There is no previous prefix to fall back to.

So:

```cpp
lps[suf] = 0;
suf++;
```

### Case 2 — `pre != 0`

Instead of starting from the beginning, we use the previously calculated LPS value:

```cpp
pre = lps[pre - 1];
```

This is the main reason KMP is efficient.

---

# 🚀 KMP Searching

After building the LPS array, we search for `needle` inside `haystack`.

```cpp
int first = 0;
int second = 0;

while(second < needle.size() && first < haystack.size())
{
    if(needle[second] == haystack[first])
    {
        second++;
        first++;
    }

    else
    {
        if(second == 0)
        {
            first++;
        }

        else
        {
            second = lps[second - 1];
        }
    }
}
```

Here:

```text
first  → haystack pointer
second → needle pointer
```

---

# 🧠 Why KMP Is Faster?

Suppose we have:

```text
haystack = "ababababca"
needle   = "ababca"
```

A normal approach may repeatedly compare characters that were already matched.

KMP remembers the matching prefix using the LPS array.

When a mismatch occurs:

```cpp
second = lps[second - 1];
```

we don't move `first` backward.

Instead, we move the `needle` pointer to the position suggested by LPS.

This avoids unnecessary comparisons.

---

# 💻 Complete C++ Solution — KMP

```cpp
class Solution {
public:

    void lpsfind(vector<int>& lps, string s)
    {
        int pre = 0;
        int suf = 1;

        while(suf < s.size())
        {
            // Match
            if(s[pre] == s[suf])
            {
                lps[suf] = pre + 1;
                suf++;
                pre++;
            }

            // Not Match
            else
            {
                if(pre == 0)
                {
                    lps[suf] = 0;
                    suf++;
                }
                else
                {
                    pre = lps[pre - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle)
    {
        // Create LPS array
        vector<int> lps(needle.size(), 0);

        lpsfind(lps, needle);

        int first = 0;
        int second = 0;

        // Search needle inside haystack
        while(second < needle.size() &&
              first < haystack.size())
        {
            // Matched
            if(needle[second] == haystack[first])
            {
                second++;
                first++;
            }

            // Not matched
            else
            {
                if(second == 0)
                {
                    first++;
                }
                else
                {
                    second = lps[second - 1];
                }
            }
        }

        // Answer exists
        if(second == needle.size())
        {
            return first - second;
        }

        return -1;
    }
};
```

---

# 🔍 KMP Dry Run

Consider:

```text
haystack = "hello"
needle   = "ll"
```

### Step 1 — Create LPS

For:

```text
needle = "ll"
```

LPS becomes:

```text
[0, 1]
```

---

### Step 2 — Search

Initially:

```text
first = 0
second = 0
```

Compare:

```text
haystack[0] = h
needle[0]   = l
```

Mismatch.

Since:

```text
second == 0
```

move:

```text
first++
```

---

Next:

```text
haystack[1] = e
needle[0]   = l
```

Mismatch again.

Move:

```text
first++
```

---

Next:

```text
haystack[2] = l
needle[0]   = l
```

Match:

```text
first = 3
second = 1
```

Next:

```text
haystack[3] = l
needle[1]   = l
```

Match:

```text
first = 4
second = 2
```

Now:

```text
second == needle.size()
```

So the complete string has been found.

---

## 🎯 Finding the Starting Index

At the end:

```cpp
return first - second;
```

Why?

Because `first` has moved past the matched substring.

For:

```text
first = 4
second = 2
```

Therefore:

```text
4 - 2 = 2
```

So:

```text
Answer = 2
```

---

# 📊 LPS Example

For:

```text
needle = "ababaca"
```

The LPS array is:

```text
Index:  0 1 2 3 4 5 6
String: a b a b a c a
LPS:    0 0 1 2 3 0 1
```

This array tells KMP how far the pattern can safely jump after a mismatch.

---

# 🆚 Approach Comparison

| Approach    | Technique                       |     Time | Space |
| ----------- | ------------------------------- | -------: | ----: |
| Brute Force | Character-by-Character Matching | O(n × m) |  O(1) |
| KMP         | LPS + Pattern Matching          | O(n + m) |  O(m) |

Where:

```text
n = haystack.length()
m = needle.length()
```

KMP is preferred when we want an efficient string-search algorithm.

---

# ⏱️ Complexity Analysis

## Brute Force

### Time Complexity

```text
O(n × m)
```

In the worst case, many characters may be compared repeatedly.

### Space Complexity

```text
O(1)
```

No extra data structure is required.

---

## KMP

### LPS Construction

```text
O(m)
```

### String Searching

```text
O(n)
```

### Total Time Complexity

```text
O(n + m)
```

### Space Complexity

```text
O(m)
```

because we create the LPS array of size `m`.

---

# 📚 Concepts Used

* Strings
* String Matching
* Brute Force
* KMP Algorithm
* Knuth-Morris-Pratt
* LPS Array
* Prefix and Suffix
* Two Pointers
* Pattern Matching
* Character Comparison
* Time & Space Complexity

---

# 🎯 LeetCode Information

| Property       | Details                                                |
| -------------- | ------------------------------------------------------ |
| Platform       | LeetCode                                               |
| Problem Number | **28**                                                 |
| Problem Name   | **Find the Index of the First Occurrence in a String** |
| Difficulty     | **Easy**                                               |
| Topic          | String                                                 |
| Pattern        | String Matching / KMP                                  |
| Language       | C++                                                    |

---

# ⭐ Key Takeaway

The most important concept in this problem is the **KMP Algorithm**.

The key idea is:

```text
Pattern
   ↓
Build LPS Array
   ↓
Compare Characters
   ↓
Mismatch?
   ↓
Use LPS Instead of Starting Again
   ↓
O(n + m)
```

The most important line in KMP is:

```cpp
second = lps[second - 1];
```

Instead of moving backward in `haystack`, we use the information already stored in the LPS array.

### Remember

```text
LPS =
Longest Proper Prefix
       that is also
Longest Suffix
```

KMP is an important **string matching pattern** in DSA and is useful when we need to efficiently search one string inside another.
