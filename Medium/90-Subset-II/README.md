# 🔢 Subsets II

## 📌 Problem Statement

Given an integer array `nums` that may contain duplicate elements, return all possible subsets (the power set).

The solution set must **not contain duplicate subsets**. You may return the solution in any order.

A subset can contain any number of elements from the array, including zero elements and all elements.

### Example

```text
Input: nums = [1,2,2]

Output:
[[],[1],[1,2],[1,2,2],[2],[2,2]]
```

The subset `[1,2]` should appear only once, even though the input contains two occurrences of `2`.

---

## 💡 Examples

### Example 1

```text
Input:
nums = [1,2,2]

Output:
[[],[1],[1,2],[1,2,2],[2],[2,2]]
```

### Example 2

```text
Input:
nums = [0]

Output:
[[],[0]]
```

---

## 📏 Constraints

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`

---

# 🧠 Approach 1: Recursion + Set

This is the initial approach used in the submitted code.

The main idea is to generate every possible subset using **recursion**, then use a `set` to remove duplicate subsets.

### Step 1: Sort the Array

```cpp
sort(nums.begin(), nums.end());
```

Sorting places duplicate elements next to each other.

For example:

```text
Before: [2,1,2]
After:  [1,2,2]
```

### Step 2: Use Include and Not Include

For every element, we have two choices:

1. **Not Include:** Skip the current element.
2. **Include:** Add the current element to the temporary subset.

```cpp
// Not include
subset(nums, index + 1, n, s, temp);

// Include
temp.push_back(nums[index]);
subset(nums, index + 1, n, s, temp);
temp.pop_back();
```

The `pop_back()` operation performs **backtracking**. It removes the element after exploring the include branch so that the next branch starts with the correct subset.

### Step 3: Base Case

```cpp
if(index == n)
{
    s.insert(temp);
    return;
}
```

When `index == n`, all elements have been considered. Insert the generated subset into the set.

### Step 4: Remove Duplicate Subsets

```cpp
set<vector<int>> s;
```

A C++ `set` stores unique elements. Since the elements are vectors, identical subsets are stored only once.

Finally:

```cpp
vector<vector<int>> ans(s.begin(), s.end());
return ans;
```

This converts the set into the required return type.

---

## 💻 Approach 1 Code — Your Implementation

```cpp
class Solution {
public:

    void subset(vector<int>& nums, int index, int n,
                set<vector<int>>& s, vector<int>& temp)
    {
        if(index == n)
        {
            s.insert(temp);
            return;
        }

        // Not include
        subset(nums, index + 1, n, s, temp);

        // Include
        temp.push_back(nums[index]);
        subset(nums, index + 1, n, s, temp);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        set<vector<int>> s;
        vector<int> temp;

        subset(nums, 0, nums.size(), s, temp);

        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
```

---

# 🔍 Dry Run

Consider:

```text
nums = [1,2,2]
```

After sorting:

```text
[1,2,2]
```

At every index, recursion explores both the not-include and include choices.

Some generated subsets are:

| Choices | Generated subset |
|---|---|
| Skip `1`, skip both `2`s | `[]` |
| Include `1` only | `[1]` |
| Include first `2` only | `[2]` |
| Include second `2` only | `[2]` |
| Include both `2`s | `[2,2]` |
| Include `1` and one `2` | `[1,2]` |
| Include `1` and both `2`s | `[1,2,2]` |

Notice that `[2]` and `[1,2]` can be generated more than once because the two `2`s are distinct positions in the input.

The `set` removes these duplicates.

### Final Output

```text
[
  [],
  [1],
  [1,2],
  [1,2,2],
  [2],
  [2,2]
]
```

The order is determined by the set's lexicographical ordering. LeetCode accepts any output order.

---

# ⚠️ Limitation of This Approach

Your approach is **correct**, but it generates all \(2^n\) include/exclude combinations before removing duplicate subsets.

For example, if the array contains many repeated values, multiple recursion paths can produce the same subset.

The `set` prevents duplicate results, but it adds extra time and memory overhead.

A more efficient approach is to **avoid generating duplicate subsets in the first place**.

---

# 🚀 Approach 2: Backtracking with Duplicate Skipping

Instead of using a set, sort the array and skip repeated elements at the same recursion level.

### Core Logic

```cpp
if(i > index && nums[i] == nums[i - 1])
    continue;
```

This condition means:

- `i > index`: We are not at the first candidate of the current recursion level.
- `nums[i] == nums[i - 1]`: The current value duplicates the previous value.
- `continue`: Skip this duplicate choice at the same level.

Important: this does **not** prevent selecting both copies of a duplicate value. It only prevents generating the same subset through equivalent choices at the same recursion level.

### Code

```cpp
class Solution {
public:
    void backtrack(vector<int>& nums, int start,
                   vector<int>& temp,
                   vector<vector<int>>& ans)
    {
        ans.push_back(temp);

        for(int i = start; i < nums.size(); i++)
        {
            // Skip duplicates at the same recursion level
            if(i > start && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);

            backtrack(nums, i + 1, temp, ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;

        backtrack(nums, 0, temp, ans);

        return ans;
    }
};
```

---

## 🔍 Dry Run — Optimized Approach

Input:

```text
nums = [1,2,2]
```

First, add the empty subset:

```text
[]
```

Then explore each choice:

```text
[]
├── [1]
│   ├── [1,2]
│   │   └── [1,2,2]
├── [2]
│   └── [2,2]
```

At the top-level recursion, the second `2` is skipped because the first `2` has already been considered at that level.

Therefore, the final unique subsets are:

```text
[]
[1]
[1,2]
[1,2,2]
[2]
[2,2]
```

---

# 📊 Approach Comparison

| Feature | Recursion + Set | Backtracking + Duplicate Skipping |
|---|---|---|
| Generates all include/exclude combinations | Yes | No |
| Removes duplicates using | `set` | Duplicate-skipping condition |
| Extra set required | Yes | No |
| General time complexity | \(O(n2^n \log(2^n))\) upper bound | \(O(n2^n)\) upper bound |
| Auxiliary space | Recursion + set storage | Recursion + current subset |
| Recommended | Good for understanding | Preferred approach |

The complexity bounds above are conservative. Actual costs depend on the number and lengths of distinct subsets, as well as the cost of vector comparisons and copying.

---

# ⏱️ Complexity Analysis

## Approach 1: Recursion + Set

### Time Complexity

There are \(2^n\) possible include/exclude combinations.

Inserting each generated subset into a `set` requires comparisons, and comparing vectors may take up to \(O(n)\) time.

A conservative upper bound is:

\[
O(n \cdot 2^n \cdot \log(2^n))
\]

Since \(\log(2^n)=O(n)\), this can be expressed as:

\[
O(n^2 \cdot 2^n)
\]

This is an upper bound for the general case, not an exact cost for every input.

### Space Complexity

The recursion depth is \(O(n)\), but the set can store up to \(2^n\) subsets, with up to \(n\) elements per subset.

Therefore, the total space can be:

\[
O(n \cdot 2^n)
\]

excluding the input array.

## Approach 2: Backtracking with Duplicate Skipping

### Time Complexity

In the worst case, when all elements are distinct, there are \(2^n\) subsets. Copying each subset can take up to \(O(n)\) time.

\[
O(n \cdot 2^n)
\]

### Space Complexity

- Recursion stack: \(O(n)\)
- Temporary subset: \(O(n)\)
- Output: up to \(O(n \cdot 2^n)\)

The auxiliary space excluding the output is \(O(n)\).

---

# 🧩 Important Concepts

### 1. Recursion

Recursion calls the same function with a smaller problem, here by moving to the next index.

### 2. Backtracking

```cpp
temp.push_back(nums[i]);
backtrack(...);
temp.pop_back();
```

Choose an element, explore its possibilities, and undo the choice.

### 3. Power Set

An array of length \(n\) with distinct elements has \(2^n\) possible subsets.

For example, an array of three distinct elements has:

\[
2^3 = 8
\]

subsets.

### 4. Duplicate Handling

There are two common methods:

- **Set method:** Generate subsets, then remove duplicates.
- **Skip method:** Avoid duplicate choices during recursion.

### 5. Sorting

Sorting makes duplicate values adjacent, which allows this condition to work:

```cpp
if(i > start && nums[i] == nums[i - 1])
    continue;
```

---

# 🎯 Key Takeaway

For **LeetCode 90 — Subsets II**, remember:

```text
Sort the array
      ↓
Generate subsets using recursion
      ↓
Handle duplicate values
      ↓
Return only unique subsets
```

Your original solution using **Recursion + `set<vector<int>>` is correct**. For a more efficient and commonly preferred backtracking solution, skip duplicate values at the same recursion level instead of generating duplicates and removing them afterward.

---

# 📌 LeetCode Information

- **Problem:** Subsets II
- **Problem Number:** 90
- **Difficulty:** Medium
- **Topics:** Array, Backtracking, Bit Manipulation
- **Language:** C++

## ⭐ Key Learning

> **Generate every subset using recursion, and handle duplicates either by storing unique subsets in a set or by skipping duplicate choices during backtracking.**