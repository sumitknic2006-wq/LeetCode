# 🎯 Combination Sum II

## 📌 Problem Statement

Given a collection of candidate numbers `candidates` and a target integer `target`, find all unique combinations in `candidates` where the chosen numbers sum to `target`.

Each number in `candidates` may be used **at most once** in each combination.

The solution must not contain duplicate combinations.

### Important Points

- A candidate can be selected only once in a combination.
- The input may contain duplicate numbers.
- Duplicate combinations must not appear in the answer.
- The order of combinations in the answer does not matter.

---

## 💡 Examples

### Example 1

```text
Input:
candidates = [10,1,2,7,6,1,5]
target = 8

Output:
[
  [1,1,6],
  [1,2,5],
  [1,7],
  [2,6]
]
```

### Example 2

```text
Input:
candidates = [2,5,2,1,2]
target = 5

Output:
[
  [1,2,2],
  [5]
]
```

---

## 📏 Constraints

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

---

# 🧠 Approach: Backtracking + Sorting + Duplicate Skipping

Your solution uses **recursion and backtracking** to generate combinations while ensuring that each candidate is used at most once.

The input is sorted first so that duplicate values are adjacent. This makes it possible to skip duplicate choices at the same recursion level.

## Step 1: Sort the Array

```cpp
sort(candidates.begin(), candidates.end());
```

For example:

```text
Before: [10,1,2,7,6,1,5]
After:  [1,1,2,5,6,7,10]
```

Sorting helps with duplicate handling and allows us to stop exploring a branch when the remaining target becomes negative.

## Step 2: Base Case — Target Becomes Zero

```cpp
if(target == 0)
{
    s.push_back(temp);
    return;
}
```

When the target reaches zero, the current combination is valid.

We add `temp` to the answer and return.

## Step 3: Stop When Target Is Negative

```cpp
if(target < 0)
{
    return;
}
```

All candidates are positive. Once the target becomes negative, adding more numbers cannot bring the sum back to the target.

Therefore, we stop that recursive branch.

## Step 4: Loop Through Candidates

```cpp
for(int i = index; i < n; i++)
```

The loop starts from `index`, which prevents the algorithm from selecting an earlier position again.

## Step 5: Skip Duplicate Choices

```cpp
if(i > index && candidates[i] == candidates[i - 1])
    continue;
```

This condition avoids generating duplicate combinations.

- `i > index` means the current candidate is not the first choice at this recursion level.
- `candidates[i] == candidates[i - 1]` means the current value duplicates the previous value.
- `continue` skips that duplicate choice at the same recursion level.

**Important:** This does not prevent using two equal values in a combination when they occur at different positions. For example, `[1,1,6]` remains a valid combination.

## Step 6: Choose, Recurse, and Backtrack

```cpp
temp.push_back(candidates[i]);

comb(candidates, i + 1, n,
     target - candidates[i], s, temp);

temp.pop_back();
```

- `push_back()` selects the current candidate.
- `i + 1` moves to the next index, ensuring that the same array position cannot be reused.
- The target is reduced by the selected value.
- `pop_back()` removes the candidate after exploring that branch.

This is the core backtracking pattern.

---

# 💻 C++ Solution — Your Implementation

```cpp
class Solution {
public:

    void comb(vector<int>& candidates, int index, int n,
              int target, vector<vector<int>>& s,
              vector<int>& temp)
    {
        if(target == 0)
        {
            s.push_back(temp);
            return;
        }

        if(target < 0)
        {
            return;
        }

        for(int i = index; i < n; i++)
        {
            if(i > index && candidates[i] == candidates[i - 1])
                continue;

            temp.push_back(candidates[i]);

            comb(candidates, i + 1, n,
                 target - candidates[i], s, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> s;
        vector<int> temp;

        comb(candidates, 0, candidates.size(),
             target, s, temp);

        return s;
    }
};
```

---

# 🔍 Dry Run

Consider:

```text
candidates = [1,1,2,5,6,7,10]
target = 8
```

The array is already sorted.

We choose candidates one by one and subtract each selected value from the target.

## Combination 1: `[1,1,6]`

| Selected number | Remaining target | Current combination |
|---|---:|---|
| Start | 8 | `[]` |
| Select `1` | 7 | `[1]` |
| Select second `1` | 6 | `[1,1]` |
| Select `6` | 0 | `[1,1,6]` |

Since the target becomes zero, `[1,1,6]` is added to the answer.

## Combination 2: `[1,2,5]`

| Selected number | Remaining target | Current combination |
|---|---:|---|
| Start | 8 | `[]` |
| Select `1` | 7 | `[1]` |
| Select `2` | 5 | `[1,2]` |
| Select `5` | 0 | `[1,2,5]` |

This is another valid combination.

## Combination 3: `[1,7]`

| Selected number | Remaining target | Current combination |
|---|---:|---|
| Start | 8 | `[]` |
| Select `1` | 7 | `[1]` |
| Select `7` | 0 | `[1,7]` |

The target reaches zero, so `[1,7]` is added.

## Combination 4: `[2,6]`

| Selected number | Remaining target | Current combination |
|---|---:|---|
| Start | 8 | `[]` |
| Select `2` | 6 | `[2]` |
| Select `6` | 0 | `[2,6]` |

This combination is also valid.

### Final Output

```text
[
  [1,1,6],
  [1,2,5],
  [1,7],
  [2,6]
]
```

The exact output order may differ, which is acceptable.

---

# 🌳 Recursion Tree

A simplified view of the search process:

```text
target = 8
   |
   ├── Choose 1
   |     |
   |     ├── Choose 1
   |     |     └── Choose 6 → [1,1,6]
   |     |
   |     ├── Choose 2
   |     |     └── Choose 5 → [1,2,5]
   |     |
   |     └── Choose 7 → [1,7]
   |
   └── Choose 2
         └── Choose 6 → [2,6]
```

The real recursion tree also explores unsuccessful branches, which are stopped when no valid combination can be formed.

---

# ⚠️ Why Is `i + 1` Important?

Your recursive call uses:

```cpp
comb(candidates, i + 1, n,
     target - candidates[i], s, temp);
```

This is essential because each candidate position can be used only once.

For example:

```text
candidates = [2,3,6,7]
target = 7
```

After selecting `2`, the next recursive call starts at the next index. It cannot select the same `2` again.

This is different from **Combination Sum (LeetCode 39)**, where the same candidate may be reused.

---

# ⚠️ Why Do We Skip Duplicates?

Suppose:

```text
candidates = [1,1,2]
target = 3
```

If we choose the first `1` at a recursion level, choosing the second `1` as an alternative first choice would explore an equivalent set of combinations.

The condition:

```cpp
if(i > index && candidates[i] == candidates[i - 1])
    continue;
```

skips the second `1` as an alternative at that same level.

However, after choosing the first `1`, the recursive call starts at the next index, where the second `1` can still be selected.

This allows valid combinations such as `[1,1,2]` when the target is `4`, while avoiding duplicate combinations.

---

# 📊 Complexity Analysis

Let \(n\) be the number of candidates.

### Time Complexity

In the worst case, backtracking can explore exponentially many subsets. A loose upper bound is:

\[
O(n \cdot 2^n)
\]

This accounts for exploring up to \(2^n\) candidate subsets and copying combinations into the output. Sorting additionally costs \(O(n\log n)\).

Duplicate skipping and early termination can significantly reduce the work on many inputs, but they do not eliminate the exponential worst case.

### Space Complexity

- Recursion stack: \(O(n)\)
- Temporary combination: \(O(n)\)
- Output storage: depends on the number and lengths of valid combinations.

Auxiliary space, excluding the returned output, is \(O(n)\).

---

# 🧩 Important Concepts

### 1. Backtracking

Choose an element, explore the recursive branch, then undo the choice.

```cpp
temp.push_back(candidates[i]);
comb(...);
temp.pop_back();
```

### 2. Sorting

Sorting makes duplicate values adjacent and supports duplicate skipping.

### 3. Duplicate Skipping

```cpp
if(i > index && candidates[i] == candidates[i - 1])
    continue;
```

This prevents duplicate combinations without requiring a `set`.

### 4. Each Element Used Once

```cpp
comb(candidates, i + 1, ...);
```

Advancing the index ensures that a selected position is not reused.

### 5. Target Reduction

```cpp
target - candidates[i]
```

Each selected candidate reduces the remaining target.

---

# 🎯 Key Takeaway

For **Combination Sum II**, remember:

```text
Sort the candidates
       ↓
Choose a candidate
       ↓
Reduce the target
       ↓
Recurse from the next index
       ↓
Skip duplicate choices
       ↓
Backtrack
```

Your solution correctly uses sorting, backtracking, `i + 1`, and duplicate skipping. It does not need a `set` because duplicate choices are handled during recursion.

---

# 📌 LeetCode Information

- **Problem:** Combination Sum II
- **Problem Number:** 40
- **Difficulty:** Medium
- **Topics:** Array, Backtracking
- **Language:** C++

## ⭐ Key Learning

> **Combination Sum II uses backtracking to find unique combinations, with each candidate position used at most once. Sorting and skipping duplicates at the same recursion level prevent repeated combinations.**