# 🔥 Smallest Stable Index I

## 📌 Problem Statement

You are given an integer array `nums` of length `n` and an integer `k`.

For every index `i`, define its **instability score** as:

```text
max(nums[0..i]) - min(nums[i..n-1])
```

Where:

* `max(nums[0..i])` = maximum element from index `0` to `i`.
* `min(nums[i..n-1])` = minimum element from index `i` to `n-1`.

An index `i` is called **stable** if:

```text
instability score <= k
```

Return the **smallest stable index**.

If no stable index exists, return:

```text
-1
```

---

# 📥 Examples

### Example 1

```text
Input:
nums = [5,0,1,4]
k = 3

Output:
3
```

Explanation:

```text
Index 0:
max([5]) = 5
min([5,0,1,4]) = 0

5 - 0 = 5
```

Not stable because:

```text
5 > 3
```

---

```text
Index 1:
max([5,0]) = 5
min([0,1,4]) = 0

5 - 0 = 5
```

Not stable.

---

```text
Index 2:
max([5,0,1]) = 5
min([1,4]) = 1

5 - 1 = 4
```

Not stable.

---

```text
Index 3:
max([5,0,1,4]) = 5
min([4]) = 4

5 - 4 = 1
```

Since:

```text
1 <= 3
```

index `3` is stable.

Therefore:

```text
Output = 3
```

---

### Example 2

```text
Input:
nums = [3,2,1]
k = 1

Output:
-1
```

For every index:

```text
max prefix = 3
min suffix = 1
```

Therefore:

```text
3 - 1 = 2
```

Since:

```text
2 > 1
```

no index is stable.

Therefore:

```text
Output = -1
```

---

### Example 3

```text
Input:
nums = [0]
k = 0

Output:
0
```

At index `0`:

```text
max([0]) = 0
min([0]) = 0
```

Therefore:

```text
0 - 0 = 0
```

Since:

```text
0 <= 0
```

index `0` is stable.

---

# 📏 Constraints

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 10⁹`
* `0 <= k <= 10⁹`

---

# 💡 Approach 1 — Initial Approach

Your initial approach was:

```cpp
// int n = nums.size();

// int i = 0;
// while((0 <= i && i <= n-1)){
//     int result = max(nums[0], nums[i])
//                - min(nums[i], nums[n-1]);

//     if(result <= k){
//         return k;
//     }

//     i++;
// }

// return -1;
```

This approach tries to calculate the instability score for every index.

But the problem is that the actual formula is:

```text
max(nums[0..i]) - min(nums[i..n-1])
```

while the code calculates:

```text
max(nums[0], nums[i]) - min(nums[i], nums[n-1])
```

These are **not the same thing**.

---

# ❌ Why Initial Approach Fails?

Suppose:

```text
nums = [5,0,1,4]
```

For:

```text
i = 2
```

The required prefix is:

```text
nums[0..2] = [5,0,1]
```

Therefore:

```text
max = 5
```

And suffix:

```text
nums[2..3] = [1,4]
```

Therefore:

```text
min = 1
```

Actual instability score:

```text
5 - 1 = 4
```

But the initial code only checks:

```cpp
max(nums[0], nums[i])
```

which means:

```text
max(5,1) = 5
```

and:

```cpp
min(nums[i], nums[n-1])
```

which means:

```text
min(1,4) = 1
```

This particular case happens to give the correct result, but this is not guaranteed.

The problem requires checking **all elements in the prefix and suffix**, not just the endpoints.

---

# 🚨 Another Important Mistake

Your initial code has:

```cpp
if(result <= k){
    return k;
}
```

But the problem asks us to return the **index `i`**, not `k`.

It should be:

```cpp
return i;
```

So the initial approach has **two problems**:

### Problem 1

Incorrect calculation:

```cpp
max(nums[0], nums[i])
```

instead of:

```text
max(nums[0..i])
```

### Problem 2

Incorrect return value:

```cpp
return k;
```

instead of:

```cpp
return i;
```

---

# 💡 Approach 2 — Brute Force

Your second approach correctly follows the problem definition.

For every index `i`:

1. Find maximum from `0` to `i`.
2. Find minimum from `i` to `n-1`.
3. Calculate:

   ```text
   max - min
   ```
4. If the result is `<= k`, return `i`.
5. If no index satisfies the condition, return `-1`.

---

# 🧠 Step-by-Step Algorithm

For every index:

```cpp
for(int i = 0; i < n; i++)
```

we initialize:

```cpp
int maxi = nums[0];
int mini = nums[i];
```

Then calculate the maximum of the prefix:

```cpp
for(int j = 0; j <= i; j++)
{
    maxi = max(maxi, nums[j]);
}
```

This gives:

```text
max(nums[0..i])
```

Then calculate the minimum of the suffix:

```cpp
for(int j = i; j < n; j++)
{
    mini = min(mini, nums[j]);
}
```

This gives:

```text
min(nums[i..n-1])
```

Then:

```cpp
int result = maxi - mini;
```

If:

```cpp
result <= k
```

then the current index is stable.

Since we are traversing from left to right, the first stable index is automatically the **smallest stable index**.

Therefore:

```cpp
return i;
```

If the loop completes:

```cpp
return -1;
```

---

# 💻 C++ Solution

```cpp
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            int maxi = nums[0];
            int mini = nums[i];

            // Find maximum in nums[0..i]
            for(int j = 0; j <= i; j++)
            {
                maxi = max(maxi, nums[j]);
            }

            // Find minimum in nums[i..n-1]
            for(int j = i; j < n; j++)
            {
                mini = min(mini, nums[j]);
            }

            int result = maxi - mini;

            if(result <= k)
            {
                return i;
            }
        }

        return -1;
    }
};
```

---

# 🔍 Dry Run

Consider:

```text
nums = [5,0,1,4]
k = 3
```

---

## Index `i = 0`

Prefix:

```text
[5]
```

Maximum:

```text
maxi = 5
```

Suffix:

```text
[5,0,1,4]
```

Minimum:

```text
mini = 0
```

Instability:

```text
5 - 0 = 5
```

Check:

```text
5 <= 3 ❌
```

Continue.

---

## Index `i = 1`

Prefix:

```text
[5,0]
```

Maximum:

```text
maxi = 5
```

Suffix:

```text
[0,1,4]
```

Minimum:

```text
mini = 0
```

Instability:

```text
5 - 0 = 5
```

Check:

```text
5 <= 3 ❌
```

Continue.

---

## Index `i = 2`

Prefix:

```text
[5,0,1]
```

Maximum:

```text
maxi = 5
```

Suffix:

```text
[1,4]
```

Minimum:

```text
mini = 1
```

Instability:

```text
5 - 1 = 4
```

Check:

```text
4 <= 3 ❌
```

Continue.

---

## Index `i = 3`

Prefix:

```text
[5,0,1,4]
```

Maximum:

```text
maxi = 5
```

Suffix:

```text
[4]
```

Minimum:

```text
mini = 4
```

Instability:

```text
5 - 4 = 1
```

Check:

```text
1 <= 3 ✅
```

Therefore:

```text
return 3;
```

---

# 📊 Dry Run Table

| Index `i` | Prefix      | Prefix Max | Suffix      | Suffix Min | Score | Stable? |
| --------: | ----------- | ---------: | ----------- | ---------: | ----: | :-----: |
|         0 | `[5]`       |          5 | `[5,0,1,4]` |          0 |     5 |    ❌    |
|         1 | `[5,0]`     |          5 | `[0,1,4]`   |          0 |     5 |    ❌    |
|         2 | `[5,0,1]`   |          5 | `[1,4]`     |          1 |     4 |    ❌    |
|         3 | `[5,0,1,4]` |          5 | `[4]`       |          4 |     1 |    ✅    |

Final Answer:

```text
3
```

---

# 🧠 Why Do We Return `i` Immediately?

The problem asks for:

```text
Smallest Stable Index
```

We are checking indices in this order:

```text
0 → 1 → 2 → 3 → ...
```

Therefore, when we find:

```cpp
if(result <= k)
{
    return i;
}
```

we can immediately return `i`.

There is no need to check later indices because they will be larger.

---

# 🔍 Understanding Prefix and Suffix

This problem is based on two ranges.

For any index `i`:

```text
Prefix:
nums[0 ... i]

Suffix:
nums[i ... n-1]
```

For example:

```text
nums = [5, 0, 1, 4]
```

At:

```text
i = 2
```

we have:

```text
Prefix
↓
[5, 0, 1] | [4]
            ↑
          Suffix
          starts at i
```

So:

```text
Prefix Maximum = 5
Suffix Minimum = 1
```

Therefore:

```text
Instability = 5 - 1 = 4
```

---

# 🔥 Why Two Inner Loops?

For every `i`, we need:

```text
max(nums[0..i])
```

and:

```text
min(nums[i..n-1])
```

So we explicitly traverse both ranges.

### First Loop

```cpp
for(int j = 0; j <= i; j++)
```

checks:

```text
0 → i
```

and finds the maximum.

### Second Loop

```cpp
for(int j = i; j < n; j++)
```

checks:

```text
i → n-1
```

and finds the minimum.

This is why the approach is called a **Brute Force** approach.

---

# 🆚 Approach Comparison

| Approach                   | Prefix Max                | Suffix Min                  | Correct? |  Time |
| -------------------------- | ------------------------- | --------------------------- | :------: | ----: |
| Initial Approach           | ❌ Only `nums[0], nums[i]` | ❌ Only `nums[i], nums[n-1]` |     ❌    |  O(n) |
| Brute Force                | ✅ Complete prefix         | ✅ Complete suffix           |     ✅    | O(n²) |
| Prefix/Suffix Optimization | ✅ Precomputed             | ✅ Precomputed               |     ✅    |  O(n) |

Your second approach is **correct** and directly follows the problem statement.

---

# ⚡ Possible Optimized Approach

The brute-force solution can be optimized.

Instead of calculating:

```text
max(nums[0..i])
```

again and again, we can maintain a running maximum.

Similarly, we can precompute the suffix minimum.

For example:

```text
suffixMin[i] = min(nums[i], suffixMin[i+1])
```

Then each index can be checked in `O(1)`.

The optimized approach becomes:

```text
Build suffix minimum
        ↓
Traverse from left to right
        ↓
Maintain prefix maximum
        ↓
Calculate:
prefixMax - suffixMin[i]
        ↓
If <= k
        ↓
Return i
```

This reduces the time complexity from:

```text
O(n²)
```

to:

```text
O(n)
```

The official constraints for 3903 are small (`n <= 100`), so your brute-force solution is acceptable.

---

# ⏱️ Complexity Analysis

For your **second approach**:

### Outer Loop

```cpp
for(int i = 0; i < n; i++)
```

runs:

```text
n
```

times.

### First Inner Loop

```cpp
for(int j = 0; j <= i; j++)
```

can take up to:

```text
O(n)
```

time.

### Second Inner Loop

```cpp
for(int j = i; j < n; j++)
```

can also take up to:

```text
O(n)
```

time.

Therefore:

```text
O(n × (n + n))
```

which becomes:

```text
O(n²)
```

### Time Complexity

```text
O(n²)
```

### Space Complexity

Only a few variables are used:

```cpp
int n;
int maxi;
int mini;
int result;
```

Therefore:

```text
O(1)
```

---

# 📚 Concepts Used

* Arrays
* Array Traversal
* Prefix
* Suffix
* Maximum Element
* Minimum Element
* Nested Loops
* Brute Force
* Indexing
* `max()`
* `min()`
* Time Complexity
* Space Complexity

---

# 🎯 LeetCode Information

| Property       | Details                       |
| -------------- | ----------------------------- |
| Platform       | LeetCode                      |
| Problem Number | **3903**                      |
| Problem Name   | **Smallest Stable Index I**   |
| Difficulty     | **Easy**                      |
| Topic          | Array                         |
| Pattern        | Prefix + Suffix / Brute Force |
| Language       | C++                           |

The official problem defines the instability score as the maximum of the prefix minus the minimum of the suffix and asks for the smallest stable index.

---

# ⭐ Key Takeaway

The most important thing in this problem is understanding:

```text
max(nums[0..i])
```

and:

```text
min(nums[i..n-1])
```

For every index:

```text
             i
             ↓
[  Prefix  ] [ Suffix ]
     ↓           ↓
   MAX          MIN
      \          /
       \        /
        \      /
         MAX - MIN
             ↓
        <= k ?
        ↙     ↘
      YES      NO
       ↓        ↓
   return i   continue
```

### Your Brute Force Pattern

```text
For every index i:

    Find maximum from 0 → i

    Find minimum from i → n-1

    result = maximum - minimum

    If result <= k:
        return i

Return -1
```

### Remember

```text
Prefix → Maximum
Suffix → Minimum

Instability Score =
Prefix Maximum - Suffix Minimum
```

And because we scan from left to right:

```cpp
if(result <= k)
{
    return i;
}
```

gives us the **smallest stable index**.
