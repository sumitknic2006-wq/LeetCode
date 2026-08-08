# 🔥 Longest Substring Without Repeating Characters

## 📌 Problem Statement

Given a string `s`, find the length of the **longest substring** without repeating characters.

### Example 1

```text
Input:  s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with a length of 3.
```

### Example 2

```text
Input:  s = "bbbbb"
Output: 1
Explanation: The answer is "b", with a length of 1.
```

### Example 3

```text
Input:  s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with a length of 3.
```

> **Note:** `"pwke"` is a subsequence, not a substring.

---

## 📏 Constraints

* `0 <= s.length <= 5 * 10⁴`
* `s` consists of English letters, digits, symbols and spaces.

---

## 💡 Approach

We use the **Sliding Window + Two Pointer** technique.

A window is maintained between two pointers:

```text
first  → left side of window
second → right side of window
```

A `vector<bool>` of size `256` is used to keep track of characters currently present inside the window.

### Algorithm

1. Initialize `first = 0` and `second = 0`.
2. Traverse the string using `second`.
3. If `s[second]` is already present in the current window:

   * Remove `s[first]`.
   * Move `first` forward.
   * Continue until the duplicate is removed.
4. Mark `s[second]` as present.
5. Calculate the current window length:

   ```cpp
   second - first + 1
   ```
6. Update the maximum length.
7. Move `second` forward.
8. Return the maximum length.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<bool> count(256, 0);

        int first = 0;
        int second = 0;
        int len = 0;

        while(second < s.size())
        {
            // Remove repeating characters
            while(count[s[second]])
            {
                count[s[first]] = 0;
                first++;
            }

            // Add current character
            count[s[second]] = 1;

            // Update maximum length
            len = max(len, second - first + 1);

            second++;
        }

        return len;
    }
};
```

---

## 🔍 Dry Run

For:

```text
s = "abcabcbb"
```

| Step | `first` | `second` | Window | `len` |
| ---- | ------: | -------: | ------ | ----: |
| 1    |       0 |        0 | `a`    |     1 |
| 2    |       0 |        1 | `ab`   |     2 |
| 3    |       0 |        2 | `abc`  |     3 |
| 4    |       1 |        3 | `bca`  |     3 |
| 5    |       2 |        4 | `cab`  |     3 |
| 6    |       3 |        5 | `abc`  |     3 |

Final Answer:

```text
3
```

---

## 🧠 Why Sliding Window?

Instead of checking every possible substring, we maintain a valid window containing **unique characters only**.

When a duplicate appears:

```text
abc + a
```

We shrink the window from the left:

```text
abc
 ↓
bc
 ↓
bca
```

Now the window again contains unique characters.

This allows us to solve the problem efficiently in **O(n)** time.

---

## ⏱️ Complexity Analysis

### Time Complexity

```text
O(n)
```

Each character is processed at most a constant number of times.

### Space Complexity

```text
O(1)
```

We use a fixed-size array of `256` characters.

---

## 🆚 Alternative Solution Using `unordered_set`

The same problem can also be solved using an `unordered_set`.

```cpp
unordered_set<char> st;

int left = 0;
int ans = 0;

for(int right = 0; right < s.size(); right++)
{
    while(st.count(s[right]))
    {
        st.erase(s[left]);
        left++;
    }

    st.insert(s[right]);

    ans = max(ans, right - left + 1);
}

return ans;
```

### Comparison

| Approach        | Data Structure |         Time | Space |
| --------------- | -------------- | -----------: | ----: |
| `vector<bool>`  | Fixed Array    |         O(n) |  O(1) |
| `unordered_set` | Hash Set       | O(n) Average |  O(n) |

---

## 📚 Concepts Used

* Two Pointers
* Sliding Window
* Hashing / Presence Tracking
* `vector<bool>`
* `unordered_set`
* Strings
* Time & Space Complexity

---

## 🎯 LeetCode Information

| Property       | Details                                            |
| -------------- | -------------------------------------------------- |
| Platform       | LeetCode                                           |
| Problem Number | **3**                                              |
| Problem Name   | **Longest Substring Without Repeating Characters** |
| Difficulty     | **Medium**                                         |
| Topic          | String                                             |
| Pattern        | Sliding Window                                     |
| Language       | C++                                                |

---

## ⭐ Key Takeaway

The most important pattern learned from this problem is:

```text
Two Pointers
      +
Sliding Window
      +
Character Tracking
      ↓
O(n) Solution
```

This **Sliding Window** pattern is extremely useful for solving substring and subarray problems efficiently.
