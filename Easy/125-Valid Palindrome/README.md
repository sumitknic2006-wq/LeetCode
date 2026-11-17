# LeetCode 125: Valid Palindrome

## 1. Problem Statement

Given a string `s`, determine whether it is a palindrome, considering only alphanumeric characters and ignoring cases.

A palindrome is a string that reads the same forward and backward.

- Ignore spaces and punctuation.
- Ignore uppercase and lowercase differences.
- Consider only letters and digits.

## 2. Examples

**Example 1:**

```text
Input: s = "A man, a plan, a canal: Panama"
Output: true
```

**Explanation:** After removing non-alphanumeric characters and converting letters to lowercase, the string becomes `"amanaplanacanalpanama"`, which is a palindrome.

**Example 2:**

```text
Input: s = "race a car"
Output: false
```

**Explanation:** After cleaning, the string becomes `"raceacar"`, which is not a palindrome.

**Example 3:**

```text
Input: s = " "
Output: true
```

**Explanation:** An empty string after removing non-alphanumeric characters is considered a palindrome.

## 3. Constraints

- `1 <= s.length <= 2 * 10^5`
- `s` consists only of printable ASCII characters.

## 4. Your Approach: Recursion + Two Pointers

You used recursion to compare characters from both ends of the string.

You maintain two indices:

- `index`: Starts from the beginning.
- `n`: Starts from the end.

### Main Logic

**Step 1: Base Case**

```cpp
if(index >= n)
{
    return true;
}
```

If the pointers meet or cross, all required comparisons have passed.

**Step 2: Skip Non-Alphanumeric Characters**

```cpp
if(!isalnum(s[index]))
{
    return print(s,index+1,n);
}
```

If the left character is not a letter or digit, move the left pointer forward.

```cpp
if(!isalnum(s[n]))
{
    return print(s,index,n-1);
}
```

If the right character is not a letter or digit, move the right pointer backward.

**Step 3: Compare Characters**

```cpp
if(tolower(s[index]) != tolower(s[n]))
{
    return false;
}
```

Convert both characters to lowercase before comparing them.

**Step 4: Recursive Call**

```cpp
return print(s,index+1,n-1);
```

If both characters match, move both pointers inward.

### Important Note About Your Code

Your recursive logic is correct for this problem's input characters. However, a string can contain up to 200,000 characters. Deep recursion can consume a large amount of call-stack memory and potentially cause stack overflow.

For that reason, the iterative two-pointer approach is recommended.

## 5. Recommended Approach: Iterative Two Pointers

Instead of using recursive function calls, we can solve the problem using a `while` loop.

We use two pointers:

- `left`: Starts at index `0`.
- `right`: Starts at the last index.

### Algorithm

1. Initialize `left = 0` and `right = s.size() - 1`.
2. Run a loop while `left < right`.
3. Skip non-alphanumeric characters from the left.
4. Skip non-alphanumeric characters from the right.
5. Convert both characters to lowercase.
6. If the characters do not match, return `false`.
7. Otherwise, move both pointers inward.
8. If all comparisons pass, return `true`.

## 6. C++ Solution (Recommended)

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right)
        {
            if(!isalnum(static_cast<unsigned char>(s[left])))
            {
                left++;
            }
            else if(!isalnum(static_cast<unsigned char>(s[right])))
            {
                right--;
            }
            else
            {
                if(tolower(static_cast<unsigned char>(s[left])) !=
                   tolower(static_cast<unsigned char>(s[right])))
                {
                    return false;
                }

                left++;
                right--;
            }
        }

        return true;
    }
};
```

## 7. Dry Run

**Input:**

```text
s = "A man, a plan, a canal: Panama"
```

After ignoring spaces and punctuation and converting to lowercase:

```text
amanaplanacanalpanama
```

We compare characters from both ends.

| Step | Left Character | Right Character | Comparison | Result |
|---:|---|---|---|---|
| 1 | a | a | a == a | Match |
| 2 | m | m | m == m | Match |
| 3 | a | a | a == a | Match |
| 4 | n | n | n == n | Match |
| 5 | a | a | a == a | Match |
| 6 | p | p | p == p | Match |
| 7 | l | l | l == l | Match |
| 8 | a | a | a == a | Match |
| 9 | n | n | n == n | Match |

All the required character comparisons match.

**Final Output:**

```text
true
```

## 8. Important C++ Functions

### isalnum()

Checks whether a character is an alphabet or a digit.

```cpp
isalnum(s[left])
```

Returns a non-zero value if the character is alphanumeric; otherwise, returns zero.

### tolower()

Converts an uppercase alphabet character into lowercase.

```cpp
tolower(s[left])
```

For safe use with C++ character-classification functions, we pass an `unsigned char` value.

### static_cast

Converts the character to `unsigned char` before passing it to `isalnum()` or `tolower()`.

```cpp
static_cast<unsigned char>(s[left])
```

## 9. Edge Cases

| Input | Output | Explanation |
|---|---|---|
| `"A"` | true | Single character |
| `"aA"` | true | Case is ignored |
| `"race a car"` | false | Characters do not match |
| `" "` | true | No alphanumeric characters |
| `"., "` | true | Only punctuation and spaces |
| `"0P"` | false | Different characters |
| `"Madam"` | true | Palindrome ignoring case |

## 10. Complexity Analysis

### Your Recursive Approach

- **Time Complexity: O(n)** — Each character is processed at most once.
- **Auxiliary Space Complexity: O(n)** — Recursive calls consume call-stack space in the worst case.

### Recommended Iterative Approach

- **Time Complexity: O(n)** — The two pointers traverse the string from opposite ends.
- **Auxiliary Space Complexity: O(1)** — Only two pointers and temporary character values are used.

## 11. Recursive vs Iterative Approach

| Comparison | Recursive | Iterative |
|---|---|---|
| Technique | Function calls | While loop |
| Time Complexity | O(n) | O(n) |
| Auxiliary Space | O(n) | O(1) |
| Stack Overflow Risk | Possible for long strings | No recursion risk |
| Recommendation | Good for recursion practice | Better for this problem |

## 12. Key Concepts Learned

- **Two Pointers:** Compare elements from opposite ends.
- **Recursion:** Solve a problem by repeatedly calling the same function with smaller input.
- **Character Handling:** Use `isalnum()` and `tolower()`.
- **String Traversal:** Skip spaces and special characters.
- **Case Insensitivity:** Compare characters without considering uppercase or lowercase differences.

## 13. Key Takeaway

The main observation in this problem is that we do not need to create a new cleaned string.

We can directly compare characters using two pointers while skipping non-alphanumeric characters.

**Remember:** The iterative two-pointer approach achieves O(n) time and O(1) auxiliary space, making it the recommended solution for this problem.

## 14. LeetCode Information

- **Problem Number:** 125
- **Problem Name:** Valid Palindrome
- **Difficulty:** Easy
- **Topics:** Two Pointers, String
- **Your Approach:** Recursion + Two Pointers
- **Recommended Approach:** Iterative Two Pointers
- **Time Complexity:** O(n)
- **Recommended Auxiliary Space:** O(1)

---

**One problem at a time. One day at a time. Consistency is the key!**