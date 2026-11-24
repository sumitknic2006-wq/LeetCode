# LeetCode 520 — Detect Capital

## Problem Statement

We define the usage of capitals in a word to be correct if one of the following conditions is satisfied:

1. All letters in the word are uppercase, such as `"USA"`.
2. All letters in the word are lowercase, such as `"leetcode"`.
3. Only the first letter is uppercase, such as `"Google"`.

Given a string `word`, return `true` if the capitalization is correct; otherwise, return `false`.

## Examples

### Example 1

**Input:**
```cpp
word = "USA"
```

**Output:**
```cpp
true
```

### Example 2

**Input:**
```cpp
word = "FlaG"
```

**Output:**
```cpp
false
```

### Example 3

**Input:**
```cpp
word = "leetcode"
```

**Output:**
```cpp
true
```

## Approach: Counting Uppercase Letters

I used a counting approach to solve the problem.

First, I traverse the string and count the number of uppercase letters using `isupper()`.

After counting, I check three possible valid capitalization patterns:

- If the uppercase count equals the string length, all letters are uppercase.
- If the uppercase count is zero, all letters are lowercase.
- If the uppercase count is exactly one and the first character is uppercase, only the first letter is capitalized.

If any of these conditions is satisfied, I return `true`. Otherwise, I return `false`.

## C++ Solution

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {

      int n = word.length();
      int capitalCount = 0;

        // Count uppercase letters
        for(int i = 0; i < n; i++) {

            if(isupper(word[i])) {
                capitalCount++;
            }
        }

        // Case 1: All letters capital
        if(capitalCount == n) {
            return true;
        }

        // Case 2: All letters small
        if(capitalCount == 0) {
            return true;
        }

        // Case 3: Only first letter capital
        if(capitalCount == 1 && isupper(word[0])) {
            return true;
        }

        return false;
        
    }
};
```

## Algorithm

1. Find the length of the string and store it in `n`.
2. Initialize `capitalCount = 0`.
3. Traverse the entire string.
4. If a character is uppercase, increment `capitalCount`.
5. Check whether all letters are uppercase.
6. Check whether all letters are lowercase.
7. Check whether exactly one uppercase letter exists and it is the first character.
8. If any condition is satisfied, return `true`.
9. Otherwise, return `false`.

## Dry Run

### Input: `word = "USA"`

| Index | Character | Uppercase? | Count |
|---|---|---|---:|
| 0 | U | Yes | 1 |
| 1 | S | Yes | 2 |
| 2 | A | Yes | 3 |

`capitalCount = 3`

`n = 3`

Since `capitalCount == n`, all letters are uppercase.

**Output:** `true`

### Input: `word = "FlaG"`

| Index | Character | Uppercase? | Count |
|---|---|---|---:|
| 0 | F | Yes | 1 |
| 1 | l | No | 1 |
| 2 | a | No | 1 |
| 3 | G | Yes | 2 |

`capitalCount = 2`

`n = 4`

None of the three valid capitalization conditions are satisfied.

**Output:** `false`

## C++ Concepts Used

- String traversal
- Counting technique
- Conditional statements
- `isupper()` character function
- Boolean return values
- Logical validation

## Complexity Analysis

### Time Complexity: O(n)

We traverse the string once to count uppercase letters. The remaining conditions take constant time.

### Auxiliary Space Complexity: O(1)

Only a few integer variables are used, regardless of the string length.

## Key Takeaway

Instead of checking every capitalization pattern individually, counting uppercase letters makes the problem easy to solve.

By checking the uppercase count against the string length, zero, and one (with the first character uppercase), we can determine whether the word follows a valid capitalization rule in a single traversal.

**LeetCode:** 520 — Detect Capital  
**Difficulty:** Easy  
**Topics:** String