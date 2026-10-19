# 🔄 Permutations II

## 📌 Problem Statement

Given a collection of numbers `nums` that may contain duplicates, return all possible unique permutations in any order.

A permutation is an arrangement of all the elements in a particular order.

Since the input can contain duplicate values, the answer must not contain duplicate permutations.

## 💡 Examples

### Example 1

```text
Input:
nums = [1,1,2]

Output:
[[1,1,2],[1,2,1],[2,1,1]]
```

There are six possible arrangements if we treat the two occurrences of `1` as different positions, but only three unique permutations.

### Example 2

```text
Input:
nums = [1,2,3]

Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

All elements are distinct, so there are \(3! = 6\) unique permutations.

## 📏 Constraints

- `1 <= nums.length <= 8`
- `-10 <= nums[i] <= 10`

---

# 🧠 Approach 1: Recursion + Visited Array + Set

This is your first approach.

The main idea is to build a permutation one element at a time. A `visited` array tracks which indices have already been selected, and a `set` removes duplicate permutations.

### Step 1: Sort the Array

```cpp
sort(arr.begin(), arr.end());
```

Sorting places duplicate values next to each other.

For example:

```text
[2,1,1] → [1,1,2]
```

### Step 2: Track Used Elements

```cpp
vector<bool> visited(nums.size(), 0);
```

Initially, all positions are unvisited.

- `visited[i] == 0`: The element at index `i` has not been used in the current permutation.
- `visited[i] == 1`: The element at index `i` has already been used.

### Step 3: Build the Permutation

```cpp
if(visited[i] == 0)
{
    visited[i] = 1;
    temp.push_back(arr[i]);

    permut(arr, s, temp, visited);

    visited[i] = 0;
    temp.pop_back();
}
```

We select an unused element, recursively explore the next position, and then undo the selection using backtracking.

### Step 4: Base Case

```cpp
if(visited.size() == temp.size())
{
    s.insert(temp);
    return;
}
```

When the temporary vector contains all elements, a complete permutation has been generated.

The `set` stores only unique permutations.

## 💻 Approach 1 Code

```cpp
class Solution {
public:
    void permut(vector<int>& arr,
                set<vector<int>>& s,
                vector<int>& temp,
                vector<bool>& visited)
    {
        if(visited.size() == temp.size())
        {
            s.insert(temp);
            return;
        }

        for(int i = 0; i < visited.size(); i++)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                temp.push_back(arr[i]);

                permut(arr, s, temp, visited);

                visited[i] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        set<vector<int>> s;
        vector<int> temp;
        vector<bool> visited(nums.size(), 0);

        permut(nums, s, temp, visited);

        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
```

## 🔍 Dry Run — Approach 1

Input:

```text
nums = [1,1,2]
```

The recursion selects elements by index, not by value.

For example, these two selections are different internally:

```text
Index 0 → value 1
Index 1 → value 1
```

But they generate the same value sequence when their positions are exchanged.

Some generated paths are:

| Selected indices | Generated permutation |
|---|---|
| `0 → 1 → 2` | `[1,1,2]` |
| `0 → 2 → 1` | `[1,2,1]` |
| `1 → 0 → 2` | `[1,1,2]` |
| `1 → 2 → 0` | `[1,2,1]` |
| `2 → 0 → 1` | `[2,1,1]` |
| `2 → 1 → 0` | `[2,1,1]` |

The set removes the repeated vectors.

Final unique permutations:

```text
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

### Limitation

This approach is correct, but it may generate the same permutation multiple times before the set removes duplicates. The set also adds insertion and comparison overhead.

---

# 🔁 Approach 2: Swap + Recursion + Set

This is your second approach.

Instead of building a separate `temp` vector, we generate permutations by swapping elements directly inside the input array.

### Step 1: Fix the Current Position

```cpp
for(int i = index; i < arr.size(); i++)
```

The loop tries every element from `index` onward as the element for the current position.

### Step 2: Swap

```cpp
swap(arr[i], arr[index]);
```

The selected element moves to the current position.

### Step 3: Recursion

```cpp
permut(arr, s, index + 1);
```

The next recursive call fixes the next position.

### Step 4: Backtrack

```cpp
swap(arr[i], arr[index]);
```

After the recursive call, we restore the original arrangement so that the next candidate can be tried.

### Step 5: Store Unique Permutations

```cpp
if(index == arr.size())
{
    s.insert(arr);
    return;
}
```

When `index` reaches the array size, one complete permutation has been generated. The set removes duplicates.

## 💻 Approach 2 Code

```cpp
class Solution {
public:
    void permut(vector<int>& arr,
                set<vector<int>>& s,
                int index)
    {
        if(index == arr.size())
        {
            s.insert(arr);
            return;
        }

        for(int i = index; i < arr.size(); i++)
        {
            swap(arr[i], arr[index]);

            permut(arr, s, index + 1);

            swap(arr[i], arr[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        set<vector<int>> s;

        permut(nums, s, 0);

        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
```

## 🔍 Dry Run — Approach 2

Input:

```text
nums = [1,1,2]
```

Initially:

```text
[1,1,2]
 index = 0
```

### Step 1: First Position

The loop tries swapping each element with the element at index `0`.

- Swap index `0` with index `0`: `[1,1,2]`
- Swap index `1` with index `0`: `[1,1,2]`
- Swap index `2` with index `0`: `[2,1,1]`

Notice that swapping the two `1`s produces the same value arrangement.

### Step 2: Fix Remaining Positions

For the arrangement `[1,1,2]`, recursion explores:

```text
[1,1,2]
[1,2,1]
```

For the arrangement `[2,1,1]`, recursion explores:

```text
[2,1,1]
```

Repeated arrangements can still occur because equal values are swapped at different indices.

### Step 3: Set Removes Duplicates

The final set contains:

```text
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

### Limitation

The swap-based approach avoids creating a separate temporary permutation, but the `set` is still needed to remove duplicates. It may generate duplicate permutations during recursion.

---

# 🚀 Approach 3: Optimized Backtracking — Skip Duplicates

This approach avoids generating duplicate permutations in the first place.

Instead of using a `set`, we skip a duplicate value if the same value has already been considered at the current recursion level.

Because the array is sorted, duplicate values are adjacent.

### Core Condition

```cpp
if(i > index && nums[i] == nums[i - 1])
    continue;
```

This condition means:

- `i > index`: We are not considering the first candidate at this recursion level.
- `nums[i] == nums[i - 1]`: The current value equals the previous value.
- `continue`: Skip this duplicate choice at the current level.

This allows repeated values to appear in a permutation as many times as they appear in the input, but prevents equivalent choices from generating duplicate branches.

## 💻 Optimized Code

```cpp
class Solution {
public:
    void permut(vector<int>& nums,
                vector<vector<int>>& ans,
                int index)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++)
        {
            // Skip duplicate choices at this level
            if(i > index && nums[i] == nums[i - 1])
                continue;

            swap(nums[i], nums[index]);

            permut(nums, ans, index + 1);

            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        permut(nums, ans, 0);

        return ans;
    }
};
```

## 🔍 Why Does Duplicate Skipping Work?

Suppose:

```text
nums = [1,1,2]
```

At index `0`, both `1`s are possible candidates, but choosing either one produces the same value at the first position.

The condition skips the second `1` at this recursion level.

However, after choosing the first `1`, the next recursion level can still select the remaining `1`. Therefore, `[1,1,2]` remains a valid permutation.

The result is generated without storing duplicate permutations in a set.

**Important:** The condition must use `i > index`, not simply `i > 0`, because duplicate skipping is performed relative to the current recursion level.

---

# 📊 Approach Comparison

| Feature | Approach 1 | Approach 2 | Approach 3 |
|---|---|---|---|
| Main technique | Visited + recursion | Swap + recursion | Swap + duplicate skipping |
| Uses `temp` | Yes | No | No |
| Uses `visited` | Yes | No | No |
| Uses `set` | Yes | Yes | No |
| Duplicate handling | After generation | After generation | During generation |
| Recommended | Good for learning | Good for learning | Preferred |

---

# ⏱️ Complexity Analysis

Let:

- \(n\) be the array length.
- \(U\) be the number of unique permutations.

The maximum possible number of unique permutations is \(n!\), when all elements are distinct.

## Approach 1: Visited Array + Set

**Time Complexity:** A conservative upper bound is \(O(n \cdot n! \log(n!))\). The recursion can generate up to \(n!\) permutations, each of length \(n\), and set insertion performs comparisons.

**Space Complexity:** \(O(n \cdot n!)\) for storing permutations in the set, plus \(O(n)\) auxiliary space for recursion, `temp`, and `visited`.

## Approach 2: Swap + Set

**Time Complexity:** A conservative upper bound is \(O(n \cdot n! \log(n!))\), due to generating permutations and inserting them into the set.

**Space Complexity:** \(O(n \cdot n!)\) for the set, plus \(O(n)\) recursion stack space.

## Approach 3: Swap + Duplicate Skipping

**Time Complexity:** \(O(n \cdot n!)\) in the worst case, when all values are distinct. Duplicate skipping reduces unnecessary branches when values repeat.

**Auxiliary Space:** \(O(n)\) for the recursion stack, excluding the output.

**Output Space:** \(O(n \cdot U)\), where \(U\) is the number of unique permutations.

---

# 🧩 Important Concepts

### 1. Recursion

Each recursive call fixes one position and continues with the remaining positions.

### 2. Backtracking

```cpp
swap(nums[i], nums[index]);
permut(nums, ans, index + 1);
swap(nums[i], nums[index]);
```

Make a choice, explore it, and undo the choice before trying another candidate.

### 3. Visited Array

The first approach uses `visited` to ensure that the same array index is not selected twice in one permutation.

### 4. Set

A `set<vector<int>>` stores only unique vectors in sorted order.

### 5. Duplicate Skipping

Sorting the input allows us to identify duplicate values and skip equivalent choices at the same recursion level.

### 6. Permutations vs. Subsets

- **Subsets:** Elements may be selected or skipped; their relative order is not important.
- **Permutations:** Every element is used, and the order matters.

For example, `[1,2]` and `[2,1]` are different permutations.

---

# 🎯 Key Takeaway

For LeetCode 47, remember:

```text
Sort the array
      ↓
Fix one position at a time
      ↓
Swap a candidate into position
      ↓
Recurse for the next position
      ↓
Backtrack
      ↓
Skip duplicate choices to avoid repeated results
```

Your first two approaches are correct because the set removes duplicate permutations. The optimized approach is preferable because it skips duplicate branches during recursion instead of generating duplicate permutations and removing them afterward.

---

# 📌 LeetCode Information

- **Problem:** Permutations II
- **Problem Number:** 47
- **Difficulty:** Medium
- **Topics:** Array, Backtracking
- **Language:** C++

## ⭐ Key Learning

> **For unique permutations, sorting plus duplicate skipping during backtracking avoids the extra set and prevents duplicate permutations from being generated.**