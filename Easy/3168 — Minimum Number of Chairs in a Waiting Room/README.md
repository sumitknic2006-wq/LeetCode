# LeetCode 3168 — Minimum Number of Chairs in a Waiting Room

## Problem Statement

You are given a string `s` representing events in a waiting room.

- `'E'` represents a person entering the waiting room.
- `'L'` represents a person leaving the waiting room.

Return the minimum number of chairs required so that every person entering the waiting room has a chair available.

## Example

**Input:**
```cpp
s = "EEEELE"
```

**Output:**
```cpp
4
```

**Explanation:**

Four people enter the waiting room before anyone leaves. Therefore, at least four chairs are required.

## Approach — Greedy / Counting

We use two variables:

- `current`: Tracks the current number of people inside the waiting room.
- `maxPerson`: Stores the maximum number of people present simultaneously.

### Algorithm

1. Initialize `current = 0` and `maxPerson = 0`.
2. Traverse the string character by character.
3. If the current character is `'E'`:
   - Increment `current`.
   - Update `maxPerson` using `max(maxPerson, current)`.
4. Otherwise, if the character is `'L'`, decrement `current`.
5. Return `maxPerson`.

The maximum occupancy represents the minimum number of chairs required.

## C++ Solution

```cpp
class Solution {
public:
    int minimumChairs(string s) {
        int maxPerson = 0;
        int current = 0;

        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == 'E')
            {
                current++;
                maxPerson = max(maxPerson,current); 
            }
            else{
                current--;
            }
        }
        return maxPerson;
    }
};
```

## Dry Run

**Input:**
```cpp
s = "EEEELE"
```

| Character | Operation | Current | MaxPerson |
|---|---|---:|---:|
| E | Enter | 1 | 1 |
| E | Enter | 2 | 2 |
| E | Enter | 3 | 3 |
| E | Enter | 4 | 4 |
| L | Leave | 3 | 4 |
| E | Enter | 4 | 4 |

**Output:**
```cpp
4
```

## Complexity Analysis

**Time Complexity: O(n)**

We traverse the string once, where `n` is the length of the string. Each iteration performs constant-time operations.

**Space Complexity: O(1)**

We use only two additional variables, `current` and `maxPerson`.

## Key Takeaway

This problem demonstrates how to use simple counting to track the maximum number of simultaneously active elements.

Whenever a problem involves people entering and leaving, maintaining a running count and tracking its maximum can be an effective solution.

## Problem Details

- **LeetCode Number:** 3168
- **Problem Name:** Minimum Number of Chairs in a Waiting Room
- **Difficulty:** Easy
- **Topics:** String, Greedy, Counting