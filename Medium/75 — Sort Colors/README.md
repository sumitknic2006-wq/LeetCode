# 🎨 LeetCode 75 – Sort Colors

## 1. Problem Statement

Given an array `nums` containing `n` objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order:

- Red (`0`)
- White (`1`)
- Blue (`2`)

We must sort the array without using the library's sort function.

**Important:** You must solve this problem in one pass and use only constant extra space.

## 2. Examples

### Example 1

**Input:**

```cpp
nums = [2,0,2,1,1,0]
```

**Output:**

```cpp
[0,0,1,1,2,2]
```

**Explanation:**

- `0` represents red.
- `1` represents white.
- `2` represents blue.

After sorting, all `0`s come first, followed by `1`s and then `2`s.

### Example 2

**Input:**

```cpp
nums = [2,0,1]
```

**Output:**

```cpp
[0,1,2]
```

**Explanation:**

The array is rearranged in ascending order.

### Example 3

**Input:**

```cpp
nums = [0]
```

**Output:**

```cpp
[0]
```

**Explanation:**

The array contains only one element, so it is already sorted.

## 3. Constraints

- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is either `0`, `1`, or `2`.

## 4. Approach – Dutch National Flag Algorithm

### Concept

We use three pointers to sort the array in a single traversal.

The three pointers are:

```cpp
int start = 0;
int mid = 0;
int end = nums.size() - 1;
```

Their responsibilities:

- `start` → Maintains the position where the next `0` should go.
- `mid` → Checks the current element.
- `end` → Maintains the position where the next `2` should go.

We divide the array into four regions:

| Region | Meaning |
|---|---|
| `0` to `start-1` | All elements are `0` |
| `start` to `mid-1` | All elements are `1` |
| `mid` to `end` | Elements not processed yet |
| `end+1` to `n-1` | All elements are `2` |

We check `nums[mid]` and perform one of three operations.

### Case 1: `nums[mid] == 0`

If the current element is `0`, swap it with `nums[start]`.

```cpp
swap(nums[mid], nums[start]);
start++;
mid++;
```

**Why increase both pointers?**

- The current `0` is placed in the correct region.
- The element brought from `start` is already in the processed `1` region or is the same position.
- Therefore, both pointers can move forward.

### Case 2: `nums[mid] == 1`

If the current element is `1`, it is already in the correct middle region.

```cpp
mid++;
```

Only `mid` moves forward.

### Case 3: `nums[mid] == 2`

If the current element is `2`, swap it with `nums[end]`.

```cpp
swap(nums[mid], nums[end]);
end--;
```

**Important:** We do not increase `mid` here.

The element swapped from the end has not been checked yet. We must examine it before moving forward.

## 5. Step-by-Step Algorithm

1. Initialize three pointers:
   ```cpp
   int start = 0, mid = 0, end = nums.size()-1;
   ```
2. Run a loop while `mid <= end`.
3. Check the current element `nums[mid]`.
4. If it is `0`:
   - Swap `nums[mid]` and `nums[start]`.
   - Increment `start`.
   - Increment `mid`.
5. If it is `1`:
   - Increment `mid`.
6. If it is `2`:
   - Swap `nums[mid]` and `nums[end]`.
   - Decrement `end`.
7. Continue until `mid > end`.
8. The array is now sorted in-place.

## 6. C++ Solution – Your Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, mid = 0, end = nums.size()-1;

        while(mid<=end)
        {
            if(nums[mid] == 0)
            {
                int temp = nums[mid];
                nums[mid] = nums[start];
                nums[start] = temp;
                start++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                int temp = nums[mid];
                nums[mid] = nums[end];
                nums[end] = temp;
                end--;
            }
        }
    }
};
```

**Your solution is correct.** It sorts the array in-place using three pointers without using an additional array or sorting function.

## 7. Dry Run – Your Approach

**Input:**

```cpp
nums = [2,0,2,1,1,0]
```

Initially:

```cpp
start = 0
mid = 0
end = 5
```

### Iteration 1

Current element:

```cpp
nums[mid] = nums[0] = 2
```

Condition:

```cpp
nums[mid] == 2
```

Swap:

```cpp
nums[mid] ↔ nums[end]
```

Array becomes:

```cpp
[0,0,2,1,1,2]
```

Update:

```cpp
end--;
end = 4;
```

`mid` remains `0` because the swapped element must be checked.

### Iteration 2

Current element:

```cpp
nums[mid] = nums[0] = 0
```

Condition:

```cpp
nums[mid] == 0
```

Swap:

```cpp
nums[mid] ↔ nums[start]
```

Array remains:

```cpp
[0,0,2,1,1,2]
```

Update:

```cpp
start++;
mid++;
```

New values:

```cpp
start = 1
mid = 1
end = 4
```

### Iteration 3

Current element:

```cpp
nums[mid] = nums[1] = 0
```

Swap:

```cpp
nums[mid] ↔ nums[start]
```

Array remains:

```cpp
[0,0,2,1,1,2]
```

Update:

```cpp
start++;
mid++;
```

New values:

```cpp
start = 2
mid = 2
end = 4
```

### Iteration 4

Current element:

```cpp
nums[mid] = nums[2] = 2
```

Swap:

```cpp
nums[mid] ↔ nums[end]
```

Array becomes:

```cpp
[0,0,1,1,2,2]
```

Update:

```cpp
end--;
end = 3;
```

`mid` remains `2`.

### Iteration 5

Current element:

```cpp
nums[mid] = nums[2] = 1
```

Since the element is `1`:

```cpp
mid++;
```

New values:

```cpp
start = 2
mid = 3
end = 3
```

### Iteration 6

Current element:

```cpp
nums[mid] = nums[3] = 1
```

Since the element is `1`:

```cpp
mid++;
```

New values:

```cpp
start = 2
mid = 4
end = 3
```

Now:

```cpp
mid > end
```

The loop stops.

**Final Sorted Array:**

```cpp
[0,0,1,1,2,2]
```

## 8. Complete Dry Run Table

| Iteration | start | mid | end | nums[mid] | Operation | Array |
|---|---:|---:|---:|---:|---|---|
| Initial | 0 | 0 | 5 | 2 | Initial state | `[2,0,2,1,1,0]` |
| 1 | 0 | 0 | 5 | 2 | Swap with end | `[0,0,2,1,1,2]` |
| 2 | 0 | 0 | 4 | 0 | Swap with start | `[0,0,2,1,1,2]` |
| 3 | 1 | 1 | 4 | 0 | Swap with start | `[0,0,2,1,1,2]` |
| 4 | 2 | 2 | 4 | 2 | Swap with end | `[0,0,1,1,2,2]` |
| 5 | 2 | 2 | 3 | 1 | Increment mid | `[0,0,1,1,2,2]` |
| 6 | 2 | 3 | 3 | 1 | Increment mid | `[0,0,1,1,2,2]` |
| End | 2 | 4 | 3 | - | Loop stops | `[0,0,1,1,2,2]` |

**Final Answer:**

```cpp
[0,0,1,1,2,2]
```

## 9. Important Operations Explained

### `int start = 0`

Tracks the position where the next `0` should be placed.

### `int mid = 0`

Tracks the current element that needs to be checked.

### `int end = nums.size()-1`

Tracks the position where the next `2` should be placed.

### `while(mid <= end)`

Continues processing elements that have not yet been classified.

### Swapping with `start`

```cpp
int temp = nums[mid];
nums[mid] = nums[start];
nums[start] = temp;
```

Places `0` at the beginning of the unprocessed region.

### `mid++`

Moves to the next element when the current element is already correctly classified.

### Swapping with `end`

```cpp
int temp = nums[mid];
nums[mid] = nums[end];
nums[end] = temp;
```

Places `2` at the end of the unprocessed region.

### `end--`

Reduces the unprocessed region from the right.

## 10. Why Don't We Increment `mid` When We Find `2`?

This is one of the most important concepts in this problem.

Consider:

```cpp
nums = [2,0,1]
```

Initially:

```cpp
start = 0
mid = 0
end = 2
```

We find:

```cpp
nums[mid] = 2
```

Swap it with the last element:

```cpp
[1,0,2]
```

Now:

```cpp
end = 1
```

But `nums[mid]` is now `1`, which came from the end of the array.

If we increment `mid` immediately, we would skip checking this element.

Therefore, we keep `mid` unchanged.

Next iteration checks `1` and moves `mid` forward.

**Remember:** When `nums[mid] == 2`, only `end` decreases.

## 11. Edge Cases

| Input | Expected Output | Explanation |
|---|---|---|
| `[0]` | `[0]` | Only one element |
| `[1]` | `[1]` | Only one element |
| `[2]` | `[2]` | Only one element |
| `[2,0,1]` | `[0,1,2]` | All three colors |
| `[0,0,0]` | `[0,0,0]` | All zeros |
| `[1,1,1]` | `[1,1,1]` | All ones |
| `[2,2,2]` | `[2,2,2]` | All twos |
| `[2,1,0]` | `[0,1,2]` | Reverse order |

## 12. Time and Space Complexity

### Time Complexity: O(n)

Let `n` be the size of the array.

We use one `while` loop to process the elements.

Each iteration moves at least one of the pointers:

- `mid` increases when the current element is `0` or `1`.
- `end` decreases when the current element is `2`.

Therefore, every element is processed a constant number of times.

**Time Complexity:**

```cpp
O(n)
```

### Auxiliary Space Complexity: O(1)

We only use a few variables:

- `start`
- `mid`
- `end`
- `temp`

No additional array or data structure is created.

All sorting is performed directly in the original array.

**Auxiliary Space Complexity:**

```cpp
O(1)
```

## 13. Alternative Approach – Two-Pass Counting

Another approach is to count the occurrences of `0`, `1`, and `2`, then overwrite the original array.

### C++ Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int count0 = 0, count1 = 0, count2 = 0;

        for(int num : nums)
        {
            if(num == 0)
                count0++;
            else if(num == 1)
                count1++;
            else
                count2++;
        }

        int index = 0;

        while(count0--)
            nums[index++] = 0;

        while(count1--)
            nums[index++] = 1;

        while(count2--)
            nums[index++] = 2;
    }
};
```

### Complexity Analysis

- **Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(1)
- **Passes:** Two passes through the array.

This approach is also correct, but the Dutch National Flag Algorithm is more efficient in terms of traversal because it sorts the array in a single pass.

## 14. Approach Comparison

| Feature | Dutch National Flag | Counting Approach |
|---|---|---|
| Technique | Three Pointers | Frequency Counting |
| Traversals | One pass | Two passes |
| Time Complexity | O(n) | O(n) |
| Auxiliary Space | O(1) | O(1) |
| In-place | Yes | Yes |
| Main Concept | Partitioning | Counting Frequencies |

## 15. Important Concepts Learned

- Arrays
- Three Pointers
- Two-Pointer Technique
- Dutch National Flag Algorithm
- In-place Sorting
- Swapping Elements
- Partitioning
- Single-Pass Algorithm
- Constant Auxiliary Space

## 16. Key Takeaway

The main lesson from this problem is that three pointers can be used to sort an array containing only three distinct values in a single pass.

**Remember:**

- `0` → Swap with `start`, increment `start` and `mid`.
- `1` → Increment `mid`.
- `2` → Swap with `end`, decrement `end`.
- When `mid > end` → Sorting is complete.

The most important condition to remember is:

```cpp
while(mid <= end)
```

And the most important detail is:

**Do not increment `mid` when swapping with `end`, because the swapped element has not been checked yet.**

## 17. LeetCode Information

- **Problem Number:** 75
- **Problem Name:** Sort Colors
- **Difficulty:** Medium
- **Topics:** Array, Two Pointers, Sorting
- **Language:** C++
- **Approach:** Dutch National Flag Algorithm
- **Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(1)
- **Status:** Solved