# 🔥 Sort Vowels in a String

## 📌 Problem Statement

Given a string `s`, sort the **vowels** in the string in ascending order while keeping all **consonants** at their original positions.

The vowels are:

```text
Lowercase:
a, e, i, o, u

Uppercase:
A, E, I, O, U
```

### Important Rules

* Only vowels are sorted.
* Consonants remain at their original positions.
* Uppercase vowels come before lowercase vowels in the sorted result.
* The relative positions of vowels in the string remain the same; only the vowel characters are replaced with sorted vowels.

---

# 📥 Examples

### Example 1

```text
Input:
s = "lEetcOde"

Output:
"lEOtcede"
```

The vowels are:

```text
E, O, e
```

Sorted:

```text
E, O, e
```

Consonants remain in their original positions.

---

### Example 2

```text
Input:
s = "lYmpH"

Output:
"lYmpH"
```

There are no vowels, so the string remains unchanged.

---

### Example 3

```text
Input:
s = "aeiou"

Output:
"aeiou"
```

The vowels are already sorted.

---

## 📏 Constraints

* `1 <= s.length <= 10⁵`
* `s` consists only of English letters.

---

# 💡 Approach

The main idea is to separate the vowels from the consonants.

We use:

```cpp
vector<int> lower(26, 0);
vector<int> upper(26, 0);
```

These arrays store the **frequency of lowercase and uppercase vowels**.

### Why two arrays?

Because uppercase and lowercase vowels need to be handled separately.

```text
lower → a, e, i, o, u
upper → A, E, I, O, U
```

---

# 🧠 Step-by-Step Algorithm

### Step 1 — Create Frequency Arrays

```cpp
vector<int> lower(26, 0);
vector<int> upper(26, 0);
```

`lower[i]` stores the frequency of lowercase character:

```text
'a' + i
```

Similarly:

```text
upper[i]
```

stores the frequency of uppercase character:

```text
'A' + i
```

---

### Step 2 — Find All Vowels

We traverse the complete string:

```cpp
for(int i = 0; i < s.size(); i++)
```

For lowercase vowels:

```cpp
if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
```

we increase their frequency:

```cpp
lower[s[i] - 'a']++;
```

Then we replace the vowel with:

```text
#
```

For example:

```text
"hello"
```

becomes:

```text
"h#ll#"
```

The `#` acts as a **placeholder for a vowel position**.

---

# 🔍 Why `s[i] = '#'`?

We need to remember the exact positions where vowels existed.

For example:

```text
s = "lEetcOde"
```

After replacing vowels:

```text
l#etc#d#
```

Now we know:

```text
# → vowel position
```

while all other characters are consonants and should remain unchanged.

---

# 💡 Step 3 — Create Sorted Vowel String

After counting all vowels, we create:

```cpp
string ans;
```

First, we add uppercase vowels in alphabetical order.

```cpp
for(int i = 0; i < 26; i++)
{
    char c = 'A' + i;

    while(upper[i])
    {
        ans += c;
        upper[i]--;
    }
}
```

Then we add lowercase vowels:

```cpp
for(int i = 0; i < 26; i++)
{
    char c = 'a' + i;

    while(lower[i])
    {
        ans += c;
        lower[i]--;
    }
}
```

So `ans` contains all vowels in sorted order.

---

# 🧠 Why Uppercase First?

According to ASCII ordering:

```text
'A' < 'E' < 'I' < 'O' < 'U'
```

and lowercase letters come after uppercase letters.

Therefore, the sorted vowel order is:

```text
A E I O U a e i o u
```

For example:

```text
Input vowels:
e O A a U

Sorted:
A O U a e
```

---

# 💻 Complete C++ Solution

```cpp
class Solution {
public:

    string sortVowels(string s) {

        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Count vowels
        for(int i = 0; i < s.size(); i++)
        {
            // Lowercase vowels
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                lower[s[i] - 'a']++;
                s[i] = '#';
            }

            // Uppercase vowels
            else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            {
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }

        string ans;

        // Uppercase vowels
        for(int i = 0; i < 26; i++)
        {
            char c = 'A' + i;

            while(upper[i])
            {
                ans += c;
                upper[i]--;
            }
        }

        // Lowercase vowels
        for(int i = 0; i < 26; i++)
        {
            char c = 'a' + i;

            while(lower[i])
            {
                ans += c;
                lower[i]--;
            }
        }

        int first = 0;
        int second = 0;

        // Replace '#' with sorted vowels
        while(second < ans.size())
        {
            if(s[first] == '#')
            {
                s[first] = ans[second];
                second++;
            }

            first++;
        }

        return s;
    }
};
```

---

# 🔍 Dry Run

Consider:

```text
s = "lEetcOde"
```

### Step 1 — Find Vowels

Original:

```text
l E e t c O d e
```

Vowels:

```text
E, e, O, e
```

Frequency:

```text
Uppercase:
E → 1
O → 1

Lowercase:
e → 2
```

After replacing vowels:

```text
l # # t c # d #
```

---

# 🔍 Step 2 — Create Sorted Vowel String

Uppercase vowels:

```text
E, O
```

Lowercase vowels:

```text
e, e
```

So:

```text
ans = "EOee"
```

---

# 🔍 Step 3 — Replace `#`

Current string:

```text
l # # t c # d #
```

Sorted vowels:

```text
E O e e
```

Replace each `#` from left to right:

```text
l # # t c # d #
↓
l E O t c e d e
```

Final:

```text
"lEOtcede"
```

---

# 📊 Dry Run Table

| Position | Original | After Processing |
| -------: | :------: | :--------------: |
|        0 |    `l`   |        `l`       |
|        1 |    `E`   |        `E`       |
|        2 |    `e`   |        `O`       |
|        3 |    `t`   |        `t`       |
|        4 |    `c`   |        `c`       |
|        5 |    `O`   |        `e`       |
|        6 |    `d`   |        `d`       |
|        7 |    `e`   |        `e`       |

Final result:

```text
lEOtcede
```

---

# 🧠 Important Part — Frequency Array

Suppose:

```text
s = "banana"
```

The lowercase vowel is:

```text
a
```

We calculate:

```cpp
lower['a' - 'a']++;
```

which becomes:

```cpp
lower[0]++;
```

So:

```text
lower[0] = 3
```

because `a` occurs 3 times.

Similarly:

```text
e → index 4
i → index 8
o → index 14
u → index 20
```

---

# 🔍 Character to Array Index

### Lowercase

```text
'a' - 'a' = 0
'e' - 'a' = 4
'i' - 'a' = 8
'o' - 'a' = 14
'u' - 'a' = 20
```

### Uppercase

```text
'A' - 'A' = 0
'E' - 'A' = 4
'I' - 'A' = 8
'O' - 'A' = 14
'U' - 'A' = 20
```

This allows us to use a fixed array of size `26`.

---

# 💡 Why `while(upper[i])`?

Suppose:

```text
upper[4] = 3
```

This means:

```text
E occurs 3 times
```

So:

```cpp
while(upper[i])
{
    ans += c;
    upper[i]--;
}
```

adds:

```text
EEE
```

to `ans`.

The same logic is used for lowercase vowels.

---

# 🔄 Final Reconstruction

We use two pointers:

```cpp
int first = 0;
int second = 0;
```

Here:

```text
first  → original string position
second → sorted vowel position
```

Whenever we find:

```cpp
s[first] == '#'
```

we replace it with:

```cpp
s[first] = ans[second];
```

Then:

```cpp
second++;
```

The consonants are never changed.

---

# 🆚 Alternative Approach

A simpler approach is to:

1. Extract all vowels into a separate string.
2. Sort the vowel string.
3. Traverse the original string.
4. Replace vowels using the sorted vowel string.

Example:

```cpp
string vowels;

for(char c : s)
{
    if(isVowel(c))
        vowels += c;
}

sort(vowels.begin(), vowels.end());

int j = 0;

for(int i = 0; i < s.size(); i++)
{
    if(isVowel(s[i]))
    {
        s[i] = vowels[j++];
    }
}
```

This approach is easier to understand, but sorting takes extra time.

Your approach uses a **frequency array**, so it avoids sorting.

---

# ⚡ Approach Comparison

| Approach         | Technique       |       Time | Extra Space |
| ---------------- | --------------- | ---------: | ----------: |
| Sorting Vowels   | Extract + Sort  | O(n log n) |        O(n) |
| Current Approach | Frequency Array |       O(n) |        O(n) |

Your frequency-array approach is more efficient in terms of time because the alphabet size is fixed.

---

# ⏱️ Complexity Analysis

Let:

```text
n = length of string
```

### Step 1 — Count Vowels

We traverse the string once:

```text
O(n)
```

### Step 2 — Build Sorted Vowels

We traverse 26 uppercase positions and 26 lowercase positions:

```text
O(26 + 26)
```

Since `26` is constant:

```text
O(1)
```

### Step 3 — Replace Vowels

We traverse the string:

```text
O(n)
```

### Total Time Complexity

```text
O(n) + O(1) + O(n)
```

Therefore:

```text
O(n)
```

### Space Complexity

We use:

```text
lower[26]
upper[26]
ans
```

The two frequency arrays use constant space, while `ans` can contain up to `n` vowels.

Therefore:

```text
O(n)
```

---

# 📚 Concepts Used

* Strings
* Arrays
* Frequency Array
* Character Manipulation
* ASCII
* Uppercase & Lowercase
* Vowel Detection
* String Traversal
* Two Pointers
* Counting Frequency
* Sorting Concept
* In-place Replacement
* Time & Space Complexity

---

# 🎯 LeetCode Information

| Property       | Details                     |
| -------------- | --------------------------- |
| Platform       | LeetCode                    |
| Problem Number | **2785**                    |
| Problem Name   | **Sort Vowels in a String** |
| Difficulty     | **Medium**                  |
| Topic          | String                      |
| Pattern        | Frequency Array             |
| Language       | C++                         |

---

# ⭐ Key Takeaway

The main idea of this problem is:

```text
Original String
      ↓
Find Vowels
      ↓
Count Frequencies
      ↓
Replace Vowels with #
      ↓
Create Sorted Vowel String
      ↓
Replace # from Left to Right
      ↓
Final String
```

The most important concepts from this problem are:

### 1. Frequency Array

```cpp
vector<int> lower(26, 0);
vector<int> upper(26, 0);
```

### 2. Character → Array Index

```cpp
s[i] - 'a'
s[i] - 'A'
```

### 3. Preserve Original Positions

```cpp
s[i] = '#';
```

### 4. Reconstruct Sorted Vowels

```cpp
s[first] = ans[second];
```

### 5. Efficient Complexity

```text
Time  → O(n)
Space → O(n)
```

This is a good example of using a **frequency array instead of sorting** when the possible characters belong to a fixed-size alphabet.
