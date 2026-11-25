# LeetCode 1446 — Consecutive Characters

## Problem Statement

The power of a string is defined as the maximum length of a non-empty substring that contains only one unique character.

Given a string `s`, return its power.

### Example 1

**Input:**
```cpp
s = "leetcode"
```

**Output:**
```cpp
2
```

**Explanation:**

The longest substring containing only one unique character is `"ee"`, whose length is `2`.

### Example 2

**Input:**
```cpp
s = "abbcccddddeeeeedcba"
```

**Output:**
```cpp
5
```

**Explanation:**

The longest consecutive substring containing only one unique character is `"eeeee"`, whose length is `5`.

## Approach: String Traversal and Counting

I used a simple traversal approach to find the maximum consecutive sequence of identical characters.

I maintain two variables:

- `currentLength` — tracks the length of the current consecutive character sequence.
- `maxlength` — stores the maximum consecutive length found so far.

I start traversing the string from index `1` and compare each character with the previous character.

### Case 1: Characters are Equal

If `s[i] == s[i-1]`, the current consecutive sequence continues.

- Increment `currentLength`.
- Update `maxlength` using `max()`.

### Case 2: Characters are Different

If the characters are different, the current sequence ends.

- Reset `currentLength` to `1`, because the current character starts a new sequence.

After traversing the entire string, return `maxlength`.

## C++ Solution

```cpp
class Solution {
public:
    int maxPower(string s) {
        int maxlength = 1;
        int currentLength = 1;

        for(int i = 1;i<s.size();i++)
        {
            // equal --> currentlength increases one and update maxlenlength 
            if(s[i] == s[i-1])
            {
                currentLength++;
                maxlength = max(currentLength,maxlength);
            }
            
            // not equal -> phir se new character ke currentlength = 1 se --> start
            else{
                currentLength = 1;
            }
        }
        return maxlength;
    }
};
```

## Algorithm

1. Initialize `maxlength = 1`.
2. Initialize `currentLength = 1`.
3. Traverse the string starting from index `1`.
4. Compare the current character with the previous character.
5. If both characters are equal:
   - Increment `currentLength`.
   - Update `maxlength` using `max()`.
6. Otherwise, reset `currentLength` to `1`.
7. Return `maxlength`.

## Dry Run

**Input:**
```cpp
s = "leetcode"
```

| Index | Character | Comparison | `currentLength` | `maxlength` |
|---:|:---:|---|---:|---:|
| 0 | l | Initial character | 1 | 1 |
| 1 | e | Different from l | 1 | 1 |
| 2 | e | Equal to previous e | 2 | 2 |
| 3 | t | Different from e | 1 | 2 |
| 4 | c | Different from t | 1 | 2 |
| 5 | o | Different from c | 1 | 2 |
| 6 | d | Different from o | 1 | 2 |

**Output:** `2`

The longest consecutive sequence is `"ee"`.

## C++ Concepts Used

- String traversal
- Consecutive element comparison
- Counting technique
- `max()` function
- Conditional statements
- Maintaining current and maximum values

## Complexity Analysis

### Time Complexity: O(n)

We traverse the string once, comparing each character with the previous character.

### Auxiliary Space Complexity: O(1)

Only two integer variables, `maxlength` and `currentLength`, are used. No additional data structure is required.

## Key Takeaway

By comparing each character with its previous character, we can identify consecutive sequences efficiently.

Whenever characters match, we extend the current sequence. Whenever they differ, we reset the count and start a new sequence.

This approach finds the maximum consecutive character length in a single traversal without using extra memory.

**LeetCode:** 1446 — Consecutive Characters  
**Difficulty:** Easy  
**Topics:** String