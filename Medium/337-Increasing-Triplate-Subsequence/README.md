# LeetCode 334 – Increasing Triplet Subsequence

## 1. Problem Statement

Given an integer array `nums`, return `true` if there exists a triple of indices `(i, j, k)` such that:

- `i < j < k`
- `nums[i] < nums[j] < nums[k]`

If no such indices exist, return `false`.

**Important:** The three elements must appear in increasing index order, and their values must also be strictly increasing.

You do not need to find the actual triplet. You only need to check whether it exists.

## 2. Examples

### Example 1

**Input:**

```cpp
nums = [1,2,3,4,5]
```

**Output:**

```cpp
true
```

**Explanation:**

There are multiple increasing triplets, such as:

- `[1, 2, 3]`
- `[2, 3, 4]`
- `[3, 4, 5]`

Therefore, return `true`.

### Example 2

**Input:**

```cpp
nums = [5,4,3,2,1]
```

**Output:**

```cpp
false
```

**Explanation:**

The array is in decreasing order. No three elements satisfy the strictly increasing condition.

Therefore, return `false`.

### Example 3

**Input:**

```cpp
nums = [2,1,5,0,4,6]
```

**Output:**

```cpp
true
```

**Explanation:**

One valid increasing triplet is:

```cpp
[0, 4, 6]
```

Their indices are:

```cpp
3 < 4 < 5
```

And their values satisfy:

```cpp
0 < 4 < 6
```

Therefore, return `true`.

## 3. Constraints

- 1 ≤ nums.length ≤ 5 × 10⁵
- -2³¹ ≤ nums[i] ≤ 2³¹ - 1

## 4. Approach – Greedy + Two Variables

### Concept

We need to find three elements in increasing order:

```cpp
first < second < third
```

Instead of checking every possible triplet, we maintain only two variables:

- `first`: Stores the smallest element found so far.
- `second`: Stores the smallest possible second element that is greater than a previous first element.

When we find an element greater than both `first` and `second`, we have found an increasing triplet.

We immediately return `true`.

### Why Do We Use Greedy?

Greedy means making a locally beneficial choice at every step.

Here, we try to keep:

- `first` as small as possible.
- `second` as small as possible while remaining greater than a valid earlier `first`.

Smaller values give us a better chance of finding a third element later.

### Step-by-Step Algorithm

1. Initialize `first = INT_MAX`.

2. Initialize `second = INT_MAX`.

3. Traverse the array using a range-based for loop.

4. For every element `num`:

   **Condition 1:**

   ```cpp
   if(num <= first)
   ```

   Update `first = num`.

   **Condition 2:**

   ```cpp
   else if(num <= second)
   ```

   Update `second = num`.

   **Condition 3:**

   ```cpp
   else
   ```

   If neither condition is true, then:

   ```cpp
   num > second > first
   ```

   So, an increasing triplet exists. Return `true`.

5. If the loop finishes without finding a triplet, return `false`.

## 5. C++ Solution – Your Code

```cpp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int first = INT_MAX;
        int second = INT_MAX;

        for(int num : nums)
        {
            // first minimum --> first element, sabse chota element
            if(num <= first)
            {
                first = num;
            }

            // second minimum --> second element mila lekin first se bada
            else if(num <= second)
            {
                second = num;
            }

            // Third element lekin first and second se bada.
            else{
                return true;
            }
        }

        return false;
    }
};
```

## 6. Dry Run – Your Approach

**Input:**

```cpp
nums = [2,1,5,0,4,6]
```

Initially:

```cpp
first = INT_MAX
second = INT_MAX
```

### Step-by-step execution

| Step | num | Condition      | first |  second | Result        |
| ---- | --: | -------------- | ----: | ------: | ------------- |
| 1    |   2 | num <= first   |     2 | INT_MAX | Update first  |
| 2    |   1 | num <= first   |     1 | INT_MAX | Update first  |
| 3    |   5 | num <= second  |     1 |       5 | Update second |
| 4    |   0 | num <= first   |     0 |       5 | Update first  |
| 5    |   4 | num <= second  |     0 |       4 | Update second |
| 6    |   6 | Else condition |     0 |       4 | Return true   |

### Understanding Each Step

**Step 1: num = 2**

```cpp
2 <= INT_MAX
```

Condition 1 is true.

```cpp
first = 2;
second = INT_MAX;
```

**Step 2: num = 1**

```cpp
1 <= 2
```

Condition 1 is true.

We update the smallest value:

```cpp
first = 1;
second = INT_MAX;
```

**Step 3: num = 5**

```cpp
5 <= 1  // false
5 <= INT_MAX  // true
```

Condition 2 is true.

```cpp
first = 1;
second = 5;
```

Now we have a valid increasing pair:

```cpp
1 < 5
```

**Step 4: num = 0**

```cpp
0 <= 1
```

Condition 1 is true.

```cpp
first = 0;
second = 5;
```

Notice that `second` remains 5. The earlier valid pair `(1, 5)` still exists in the original array.

**Step 5: num = 4**

```cpp
4 <= 0  // false
4 <= 5  // true
```

Condition 2 is true.

```cpp
first = 0;
second = 4;
```

Now we have:

```cpp
0 < 4
```

**Step 6: num = 6**

```cpp
6 <= 0  // false
6 <= 4  // false
```

Both conditions are false, so the `else` block executes.

```cpp
return true;
```

We have found the triplet:

```cpp
[0, 4, 6]
```

**Final Output:**

```cpp
true
```

## 7. Why Does the Algorithm Work?

The important idea is that `first` and `second` represent the best possible values for building an increasing triplet.

Whenever a smaller first element appears, we update `first`.

Whenever an element is greater than `first` but smaller than or equal to `second`, we update `second`.

When an element is greater than `second`, a valid earlier `first` and `second` already exist.

Therefore:

```cpp
first < second < num
```

This guarantees an increasing subsequence of length 3.

**Important observation:** Updating `first` later does not invalidate an earlier `second`. The earlier valid `first` appeared before that `second` in the original array. The variables store candidate values, not necessarily the exact elements of the final triplet.

## 8. Important Conditions Explained

### `int first = INT_MAX;`

Initially, we assign the maximum possible integer value.

This ensures that the first array element can update `first`.

### `if(num <= first)`

Checks whether the current element is smaller than or equal to the smallest candidate.

If yes, update `first`.

### `else if(num <= second)`

This condition executes only when:

```cpp
num > first
```

It updates `second` with the smallest possible value greater than `first`.

### `else`

If both previous conditions are false, then:

```cpp
num > second
```

Since `second` was established after a valid earlier `first`, we have found an increasing triplet.

### `for(int num : nums)`

This is a range-based for loop.

It visits every element of the array one by one without manually managing an index.

## 9. Why Do We Use `<=` Instead of `<`?

This is important because the problem requires a **strictly increasing** subsequence.

For example:

```cpp
nums = [1,1,2,2,3]
```

The algorithm updates equal values instead of treating them as a new increasing element.

The valid triplet is:

```cpp
[1,2,3]
```

Using `<=` ensures duplicate values do not incorrectly count as increasing.

## 10. Time and Space Complexity

### Time Complexity: O(n)

We traverse the array exactly once.

Each element requires only a few comparisons and assignments.

Therefore:

```cpp
O(n)
```

### Auxiliary Space Complexity: O(1)

We only use two variables:

- `first`
- `second`

No additional array or data structure is required.

Therefore:

```cpp
O(1)
```

## 11. Approach Comparison

| Feature         | Brute Force        | Greedy – Your Approach |
| --------------- | ------------------ | ---------------------- |
| Technique       | Three Nested Loops | Two Variables          |
| Time Complexity | O(n³)              | O(n)                   |
| Auxiliary Space | O(1)               | O(1)                   |
| Traversal       | Multiple loops     | Single loop            |
| Efficiency      | Slow               | Optimal                |

## 12. Important Concepts Learned

- Arrays
- Greedy Algorithm
- Increasing Subsequence
- Maintaining Minimum Values
- Range-Based For Loop
- `INT_MAX`
- Strictly Increasing Sequence
- Single-Pass Traversal
- Time Complexity Optimization

## 13. Key Takeaway

The main lesson from this problem is that we do not need to store the complete increasing subsequence.

We only need to maintain two useful candidate values:

- `first` – smallest possible first element.
- `second` – smallest possible second element greater than a valid earlier first element.

When we find a third element greater than `second`, we return `true`.

**Remember:**

```cpp
first < second < third
```

- Brute Force → Check every triplet → O(n³)
- Greedy → Maintain two minimum candidates → O(n)

This is a useful example of how a greedy strategy can optimize a problem that initially looks like a three-loop search.

## 14. LeetCode Information

- **Problem Number:** 334
- **Problem Name:** Increasing Triplet Subsequence
- **Difficulty:** Medium
- **Topics:** Array, Greedy
- **Language:** C++
- **Approach:** Greedy + Two Variables
- **Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(1)
- **Status:** Solved
