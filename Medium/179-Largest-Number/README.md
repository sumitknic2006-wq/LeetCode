# LeetCode 179: Largest Number

## 1. Problem Statement

Given a list of non-negative integers `nums`, arrange them such that they form the largest possible number and return it as a string.

Since the result can be very large, you need to return a string instead of an integer.

## 2. Examples

**Example 1:**

```cpp
Input: nums = [10,2]
Output: "210"
```

**Explanation:** The largest number can be formed by arranging the numbers as `"2"` followed by `"10"`.

**Example 2:**

```cpp
Input: nums = [3,30,34,5,9]
Output: "9534330"
```

**Explanation:** The correct arrangement is `9, 5, 34, 3, 30`.

**Example 3:**

```cpp
Input: nums = [0,0]
Output: "0"
```

**Explanation:** All numbers are zero, so return a single `"0"` instead of `"00"`.

## 3. Constraints

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 10^9`

## 4. Approach: Greedy Sorting + Custom Comparator

I solved this problem using **Greedy Sorting and a Custom Comparator**.

The main idea is to arrange numbers in an order that produces the largest possible concatenated number.

### Step 1: Convert Integers into Strings

First, convert every integer into a string using `to_string()`.

```cpp
vector<string> arr;

for(int num : nums)
{
    arr.push_back(to_string(num));
}
```

**Why?**

We need to concatenate numbers and compare different combinations. String conversion makes this possible.

### Step 2: Custom Sorting

This is the most important step.

```cpp
sort(arr.begin(), arr.end(), [](string a, string b) {
    return a + b > b + a;
});
```

For every pair of strings, compare:

- `a + b`
- `b + a`

If `a + b` is greater, place `a` before `b`.

**Example:**

Consider:

```text
a = "3"
b = "30"
```

Two possible combinations:

```text
a + b = "330"
b + a = "303"
```

Since `"330"` is greater than `"303"`, `"3"` should come before `"30"`.

### Step 3: Handle All Zeros

```cpp
if(arr[0] == "0")
{
    return "0";
}
```

If the first element is `"0"` after sorting, all numbers must be zero.

Therefore, return a single `"0"`.

### Step 4: Build the Final Answer

```cpp
string ans = "";

for(string s : arr)
{
    ans += s;
}
```

Concatenate all sorted strings to create the largest possible number.

Finally, return `ans`.

## 5. Algorithm

1. Create an empty string vector `arr`.
2. Traverse the input array.
3. Convert each integer into a string using `to_string()`.
4. Store all converted strings in `arr`.
5. Sort the strings using a custom comparator:
   - Compare `a + b` with `b + a`.
   - Place the combination that produces the larger value first.
6. Check whether the first string is `"0"`.
7. If it is `"0"`, return `"0"`.
8. Otherwise, concatenate all strings.
9. Return the final answer.

## 6. C++ Solution

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        for(int num : nums)
        {
            arr.push_back(to_string(num));
        }

        sort(arr.begin(), arr.end(), [](string a, string b) {
            return a + b > b + a;
        });

        if(arr[0] == "0")
        {
            return "0";
        }

        string ans = "";

        for(string s : arr)
        {
            ans += s;
        }

        return ans;
    }
};
```

## 7. Dry Run

**Input:**

```cpp
nums = [3,30,34,5,9]
```

### Step 1: Convert into Strings

```text
arr = ["3","30","34","5","9"]
```

### Step 2: Apply Custom Comparator

The comparator decides the order by comparing concatenated strings.

| a | b | a + b | b + a | Preferred Order |
|---|---|---|---|---|
| 3 | 30 | 330 | 303 | 3, 30 |
| 3 | 34 | 334 | 343 | 34, 3 |
| 5 | 9 | 59 | 95 | 9, 5 |
| 30 | 34 | 3034 | 3430 | 34, 30 |
| 9 | 34 | 934 | 349 | 9, 34 |

After sorting:

```text
arr = ["9","5","34","3","30"]
```

### Step 3: Check for Zeros

```cpp
if(arr[0] == "0")
```

Here, `arr[0]` is `"9"`, so continue.

### Step 4: Concatenate Strings

```text
"9" + "5" + "34" + "3" + "30"
```

**Final Output:**

```text
"9534330"
```

## 8. Important C++ Concepts

### 1. to_string()

Converts an integer into a string.

```cpp
to_string(num);
```

### 2. sort()

Sorts elements using the provided comparison rule.

```cpp
sort(arr.begin(), arr.end(), comparator);
```

### 3. Lambda Function

A lambda function allows us to define a custom comparison directly inside `sort()`.

```cpp
[](string a, string b) {
    return a + b > b + a;
}
```

### 4. String Concatenation

The `+` operator joins two strings.

```cpp
string ans = "9" + "5";
```

Result:

```text
"95"
```

## 9. Edge Cases

| Input | Output | Explanation |
|---|---|---|
| `[0]` | `"0"` | Single zero |
| `[0,0,0]` | `"0"` | All elements are zero |
| `[10,2]` | `"210"` | Custom ordering |
| `[3,30,34,5,9]` | `"9534330"` | Multiple numbers |
| `[9,99,999]` | `"999999"` | Similar prefixes |
| `[1,11,111]` | `"111111"` | Equal concatenation ordering |

## 10. Complexity Analysis

Let `n` be the number of elements and `k` be the maximum number of digits in an element.

**Time Complexity: O(n log n × k)**

- Converting integers to strings takes time proportional to their digit count.
- Sorting performs \(O(n \log n)\) comparisons.
- Each comparison creates and compares concatenated strings of length at most \(2k\).
- Building the final answer takes \(O(nk)\) time.

Therefore, the overall complexity is \(O(n \log n \times k)\).

**Auxiliary Space Complexity: O(n × k)**

- The string vector stores all converted numbers.
- The final answer requires space proportional to the total number of digits.
- Sorting may also use additional stack space.

## 11. Key Concepts Learned

- **Greedy Algorithm:** Choose the ordering that produces the largest concatenated result.
- **Custom Comparator:** Define a special sorting condition.
- **String Manipulation:** Convert integers into strings and concatenate them.
- **Lambda Function:** Write custom comparison logic inside `sort()`.
- **Sorting:** Arrange elements according to the required condition.

## 12. Key Takeaway

The most important observation in this problem is:

```cpp
return a + b > b + a;
```

Normal sorting is not sufficient because the goal is not to arrange numbers by their individual values.

Instead, we compare both possible concatenations to determine which order creates the largest number.

**Remember:** In problems involving the largest or smallest concatenated number, comparing `a + b` and `b + a` is a powerful technique.

## 13. LeetCode Information

- **Problem Number:** 179
- **Problem Name:** Largest Number
- **Difficulty:** Medium
- **Topics:** Array, String, Greedy, Sorting
- **Algorithm:** Greedy + Custom Comparator
- **Time Complexity:** O(n log n × k)
- **Auxiliary Space Complexity:** O(n × k)

---

**One problem at a time. One day at a time. Consistency is the key!**