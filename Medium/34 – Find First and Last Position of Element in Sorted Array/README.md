
# LeetCode 34 – Find First and Last Position of Element in Sorted Array

## 1. Problem Statement

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If the target is not found in the array, return `[-1, -1]`.

You must write an algorithm with O(log n) runtime complexity.

**Important:**
- The array is sorted.
- Duplicate elements may exist.
- Return the first and last index of the target.
- If the target does not exist, return `[-1, -1]`.

## 2. Examples

### Example 1

**Input:**

```cpp
nums = [5,7,7,8,8,10]
target = 8
```

**Output:**

```cpp
[3,4]
```

**Explanation:**

The target `8` appears at indices 3 and 4.

- First occurrence = 3
- Last occurrence = 4

### Example 2

**Input:**

```cpp
nums = [5,7,7,8,8,10]
target = 6
```

**Output:**

```cpp
[-1,-1]
```

**Explanation:**

The target `6` does not exist in the array.

### Example 3

**Input:**

```cpp
nums = []
target = 0
```

**Output:**

```cpp
[-1,-1]
```

**Explanation:**

The array is empty, so the target cannot be found.

## 3. Constraints

- 0 ≤ nums.length ≤ 10⁵
- -10⁹ ≤ nums[i] ≤ 10⁹
- `nums` is a non-decreasing array.
- -10⁹ ≤ target ≤ 10⁹

## 4. Approach – Two Binary Searches

### Concept

We use Binary Search two times to find the first and last occurrence of the target.

**First Binary Search – Find Starting Position**

When we find the target:

```cpp
if(nums[mid] == target)
{
    First = mid;
    end = mid-1;
}
```

We store the current index in `First`, but instead of returning, we continue searching in the left half.

This helps us find an earlier occurrence.

**Second Binary Search – Find Ending Position**

When we find the target:

```cpp
if(nums[mid] == target)
{
    Last = mid;
    start = mid+1;
}
```

We store the current index in `Last`, but continue searching in the right half.

This helps us find a later occurrence.

### Why Do We Need Two Binary Searches?

A normal Binary Search returns as soon as it finds the target.

But this problem requires both the first and last occurrence.

Therefore:

- First search → Keep moving left after finding the target.
- Second search → Keep moving right after finding the target.

## 5. Step-by-Step Algorithm

### First Binary Search – Find First Occurrence

1. Initialize `start = 0` and `end = nums.size() - 1`.
2. Initialize `First = -1`.
3. Run a loop while `start <= end`.
4. Calculate the middle index.
5. If `nums[mid] == target`:
   - Store `mid` in `First`.
   - Move left using `end = mid - 1`.
6. If `nums[mid] < target`, move right using `start = mid + 1`.
7. Otherwise, move left using `end = mid - 1`.

### Second Binary Search – Find Last Occurrence

1. Reset `start = 0` and `end = nums.size() - 1`.
2. Initialize `Last = -1`.
3. Run a loop while `start <= end`.
4. Calculate the middle index.
5. If `nums[mid] == target`:
   - Store `mid` in `Last`.
   - Move right using `start = mid + 1`.
6. If `nums[mid] < target`, move right using `start = mid + 1`.
7. Otherwise, move left using `end = mid - 1`.

Finally, return:

```cpp
[First, Last]
```

## 6. C++ Solution – Your Code

```cpp
vector<int> searchRange(vector<int>& nums, int target) {
    int start = 0, end = nums.size()-1, First = -1, Last = -1;

    vector<int> ans(2);

    // Find starting
    while(start<=end)
    {
        int mid = start+(end-start)/2;

        if(nums[mid] == target)
        {
            First = mid;
            end = mid-1;
        }

        else if(nums[mid]<target)
        {
            start = mid+1;
        }

        else{
            end = mid-1;
        }
    }

    // Find ending
    start = 0, end = nums.size()-1;
    while(start<=end)
    {
        int mid = start+(end-start)/2;

        if(nums[mid] == target)
        {
            Last = mid;
            start = mid+1;
        }

        else if(nums[mid]<target)
        {
            start = mid+1;
        }

        else{
            end = mid-1;
        }
    }

    ans[0] = First;
    ans[1] = Last;

    return ans;
}
```

## 7. Dry Run – Find First Occurrence

**Input:**

```cpp
nums = [5,7,7,8,8,10]
target = 8
```

Initially:

```cpp
start = 0;
end = 5;
First = -1;
```

### Step-by-step execution

| Step | start | end | mid | nums[mid] | Action |
|---|---:|---:|---:|---:|---|
| 1 | 0 | 5 | 2 | 7 | start = 3 |
| 2 | 3 | 5 | 4 | 8 | First = 4, end = 3 |
| 3 | 3 | 3 | 3 | 8 | First = 3, end = 2 |

Now:

```cpp
start = 3;
end = 2;
```

The loop stops.

Therefore:

```cpp
First = 3;
```

### Understanding the Steps

**Step 1:**

```cpp
mid = 0 + (5-0)/2;
mid = 2;
```

```cpp
nums[2] = 7;
target = 8;
```

Since `7 < 8`, search the right half.

```cpp
start = mid+1;
start = 3;
```

**Step 2:**

```cpp
mid = 3 + (5-3)/2;
mid = 4;
```

```cpp
nums[4] = 8;
```

Target found.

```cpp
First = 4;
end = mid-1;
end = 3;
```

We continue searching left because an earlier occurrence may exist.

**Step 3:**

```cpp
mid = 3 + (3-3)/2;
mid = 3;
```

```cpp
nums[3] = 8;
```

Target found again.

```cpp
First = 3;
end = 2;
```

Now the loop stops.

**Final First Occurrence:**

```cpp
First = 3;
```

## 8. Dry Run – Find Last Occurrence

We reset the search boundaries:

```cpp
start = 0;
end = 5;
Last = -1;
```

### Step-by-step execution

| Step | start | end | mid | nums[mid] | Action |
|---|---:|---:|---:|---:|---|
| 1 | 0 | 5 | 2 | 7 | start = 3 |
| 2 | 3 | 5 | 4 | 8 | Last = 4, start = 5 |
| 3 | 5 | 5 | 5 | 10 | end = 4 |

Now:

```cpp
start = 5;
end = 4;
```

The loop stops.

Therefore:

```cpp
Last = 4;
```

### Understanding the Steps

**Step 1:**

```cpp
mid = 0 + (5-0)/2;
mid = 2;
```

```cpp
nums[2] = 7;
target = 8;
```

Since `7 < 8`, move right.

```cpp
start = mid+1;
start = 3;
```

**Step 2:**

```cpp
mid = 3 + (5-3)/2;
mid = 4;
```

```cpp
nums[4] = 8;
```

Target found.

```cpp
Last = 4;
start = mid+1;
start = 5;
```

We continue searching right because a later occurrence may exist.

**Step 3:**

```cpp
mid = 5 + (5-5)/2;
mid = 5;
```

```cpp
nums[5] = 10;
```

Since `10 > 8`, move left.

```cpp
end = mid-1;
end = 4;
```

Now the loop stops.

**Final Last Occurrence:**

```cpp
Last = 4;
```

## 9. Final Result

After both Binary Searches:

```cpp
First = 3;
Last = 4;
```

We store both positions in the answer vector:

```cpp
ans[0] = First;
ans[1] = Last;
```

Therefore:

```cpp
return [3,4];
```

**Final Output:**

```cpp
[3,4]
```

## 10. Important Operations Explained

### `First = -1, Last = -1`

Initially, both values are `-1`.

If the target is not found, they remain `-1`.

### `First = mid`

Stores the current target index as a possible first occurrence.

### `end = mid-1`

Moves the search range to the left half to find an earlier occurrence.

### `Last = mid`

Stores the current target index as a possible last occurrence.

### `start = mid+1`

Moves the search range to the right half to find a later occurrence.

### `start = 0, end = nums.size()-1`

Resets the search range before starting the second Binary Search.

### `vector<int> ans(2)`

Creates a vector with two positions:

- `ans[0]` → First occurrence.
- `ans[1]` → Last occurrence.

## 11. Why Do We Continue Searching After Finding the Target?

This is the most important concept in this problem.

In normal Binary Search:

```cpp
if(nums[mid] == target)
{
    return mid;
}
```

We return immediately after finding the target.

But here, duplicate elements may exist.

For the first occurrence, we need to check whether the target exists further left.

For the last occurrence, we need to check whether the target exists further right.

Therefore, we update the answer and continue searching instead of returning immediately.

## 12. Edge Cases

### Case 1 – Target Not Present

```cpp
nums = [1,2,3,4,5]
target = 6
```

Output:

```cpp
[-1,-1]
```

### Case 2 – Only One Occurrence

```cpp
nums = [1,2,3,4,5]
target = 3
```

Output:

```cpp
[2,2]
```

### Case 3 – All Elements Are Equal

```cpp
nums = [2,2,2,2,2]
target = 2
```

Output:

```cpp
[0,4]
```

### Case 4 – Empty Array

```cpp
nums = []
target = 0
```

Output:

```cpp
[-1,-1]
```

## 13. Time and Space Complexity

### Time Complexity: O(log n)

We perform Binary Search two times.

**First Binary Search:**

```cpp
O(log n)
```

**Second Binary Search:**

```cpp
O(log n)
```

Total:

```cpp
O(log n) + O(log n) = O(log n)
```

The constant factor of two is ignored in Big-O notation.

### Auxiliary Space Complexity: O(1)

We use only a fixed number of variables:

- `start`
- `end`
- `mid`
- `First`
- `Last`

The answer vector contains exactly two elements, so its space usage is also constant.

Therefore, auxiliary space complexity is:

```cpp
O(1)
```

## 14. Approach Comparison

| Feature | Normal Binary Search | Two Binary Searches |
|---|---|---|
| Purpose | Find target | Find first and last occurrence |
| Searches | One | Two |
| Duplicate Handling | Returns any matching index | Finds both boundaries |
| Time Complexity | O(log n) | O(log n) |
| Auxiliary Space | O(1) | O(1) |

## 15. Important Concepts Learned

- Arrays
- Binary Search
- Duplicate Elements
- First Occurrence
- Last Occurrence
- Search Space Reduction
- Two Independent Binary Searches
- Boundary Searching
- Vector
- Time Complexity Optimization

## 16. Key Takeaway

The main lesson from this problem is that Binary Search can be modified to find the boundaries of duplicate elements.

Instead of returning immediately when the target is found:

- First Occurrence → Store the index and move left.
- Last Occurrence → Store the index and move right.

**Remember:**

```cpp
First = mid;
end = mid-1;
```

Find the first occurrence.

```cpp
Last = mid;
start = mid+1;
```

Find the last occurrence.

This is an important Binary Search pattern that can also be used in many other problems involving first and last positions, lower bounds, and upper bounds.

## 17. LeetCode Information

- **Problem Number:** 34
- **Problem Name:** Find First and Last Position of Element in Sorted Array
- **Difficulty:** Medium
- **Topics:** Array, Binary Search
- **Language:** C++
- **Approach:** Two Binary Searches
- **Time Complexity:** O(log n)
- **Auxiliary Space Complexity:** O(1)
- **Status:** Solved
