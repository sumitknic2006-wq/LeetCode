# LeetCode 11 – Container With Most Water

## 1. Problem Statement

You are given an integer array `height` of length `n`.

There are `n` vertical lines drawn such that the two endpoints of the ith line are `(i, 0)` and `(i, height[i])`.

Find two lines that, together with the x-axis, form a container that holds the maximum amount of water.

Return the maximum amount of water a container can store.

**Important:** You cannot slant the container.

## 2. Examples

### Example 1

**Input:**

```cpp
height = [1,8,6,2,5,4,8,3,7]
```

**Output:**

```cpp
49
```

**Explanation:**

The lines at index 1 and index 8 have heights 8 and 7.

- Width = 8 - 1 = 7
- Height = min(8, 7) = 7
- Area = 7 × 7 = 49

Therefore, the maximum water that can be stored is 49.

### Example 2

**Input:**

```cpp
height = [1,1]
```

**Output:**

```cpp
1
```

**Explanation:**

- Width = 1
- Height = 1
- Area = 1 × 1 = 1

## 3. Constraints

- n == height.length
- 2 ≤ n ≤ 10⁵
- 0 ≤ height[i] ≤ 10⁴

## 4. Approach 1 – Brute Force

### Concept

In the brute force approach, we check every possible pair of vertical lines.

For each pair `(i, j)`:

1. Calculate the width: `j - i`.
2. Find the minimum height: `min(height[i], height[j])`.
3. Calculate the area: `width × minimum height`.
4. Update the maximum area.

### Formula

```cpp
area = min(height[i], height[j]) * (j - i);
```

### C++ Code – Brute Force

```cpp
int n = height.size();

int temp = 0;

for(int i = 0; i < n; i++)
{
    for(int j = i + 1; j < n; j++)
    {
        int hei = min(height[i], height[j]);

        int curr = hei * (j - i);

        temp = max(temp, curr);
    }
}

return temp;
```

### Dry Run

**Input:**

```cpp
height = [1,8,6,2]
```

We check all possible pairs.

| i | j | Heights | Width | Area |
| - | - | ------- | ----: | ---: |
| 0 | 1 | 1, 8    |     1 |    1 |
| 0 | 2 | 1, 6    |     2 |    2 |
| 0 | 3 | 1, 2    |     3 |    3 |
| 1 | 2 | 8, 6    |     1 |    6 |
| 1 | 3 | 8, 2    |     2 |    4 |
| 2 | 3 | 6, 2    |     1 |    2 |

Maximum area = 6.

**Output:**

```cpp
6
```

### Complexity Analysis

- **Time Complexity:** O(n²), because we check every possible pair.
- **Auxiliary Space Complexity:** O(1), because we use only a few variables.

**Limitation:** For large arrays, checking every pair becomes too slow.

## 5. Approach 2 – Two Pointers (Optimal)

### Concept

Instead of checking every possible pair, we use two pointers:

- `start` points to the first element.
- `end` points to the last element.

Initially, we calculate the area using these two boundaries.

Then we move the pointer that has the smaller height.

**Why do we move the smaller height pointer?**

The area of the container is:

```cpp
area = min(height[start], height[end]) * (end - start);
```

The water level is limited by the shorter line.

If we move the taller line inward:

- Width decreases.
- The limiting height cannot increase beyond the shorter line.
- Therefore, the area cannot improve.

But if we move the shorter line:

- Width decreases.
- We may find a taller line.
- The limiting height may increase enough to produce a larger area.

That is why we always move the pointer with the smaller height.

### Step-by-Step Algorithm

1. Calculate the size of the array `n`.
2. Initialize `start = 0` and `end = n-1`.
3. Initialize `temp = 0` to store the maximum area.
4. Run a loop while `start < end`.
5. Calculate the minimum height using `min()`.
6. Calculate the current area using `height × width`.
7. Update the maximum area.
8. If `height[start] < height[end]`, increment `start`.
9. Otherwise, decrement `end`.
10. Return `temp`.

## 6. C++ Solution – Your Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {

        // BrutesForce Approach

        // int n = height.size();

        // int temp = 0;
        // for(int i = 0;i<n;i++)
        // {
        //     for(int j = n-1;j>0;j--)
        //     {
        //         if(i<j){
        //             int hei = min(height[i],height[j]);
        //             int curr = hei*(j-i);
        //             temp = max(temp,curr);
        //         }
        //     }
        // }
        // return temp;

        // two pointer approach

        int n = height.size();

        int start = 0, end = n-1;

        int temp = 0;

        while(start<end){

            int hei = min(height[start],height[end]);
            int curr = hei*(end-start);

            temp = max(curr,temp);

            if(height[start]<height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return temp;
    }
};
```

**Note:** Your brute force code is also logically correct. Its inner loop checks some unnecessary pairs, but `if(i<j)` prevents invalid pairs from being used. The cleaned-up version in Approach 1 avoids that extra checking.

## 7. Dry Run – Two Pointer Approach

**Input:**

```cpp
height = [1,8,6,2,5,4,8,3,7]
```

Initially:

```cpp
start = 0
end = 8
temp = 0
```

### Step-by-step execution

| Step | start | end | Heights | Width | Area | Maximum |
| ---- | ----: | --: | ------- | ----: | ---: | ------: |
| 1    |     0 |   8 | 1, 7    |     8 |    8 |       8 |
| 2    |     1 |   8 | 8, 7    |     7 |   49 |      49 |
| 3    |     1 |   7 | 8, 3    |     6 |   18 |      49 |
| 4    |     1 |   6 | 8, 8    |     5 |   40 |      49 |
| 5    |     1 |   5 | 8, 4    |     4 |   16 |      49 |
| 6    |     1 |   4 | 8, 5    |     3 |   15 |      49 |
| 7    |     1 |   3 | 8, 2    |     2 |    4 |      49 |
| 8    |     1 |   2 | 8, 6    |     1 |    6 |      49 |

### Understanding the first few steps

**Step 1:**

```cpp
start = 0, end = 8

hei = min(1, 7) = 1
curr = 1 * (8 - 0) = 8
temp = 8
```

Since `height[start] < height[end]`, we move `start++`.

**Step 2:**

```cpp
start = 1, end = 8

hei = min(8, 7) = 7
curr = 7 * (8 - 1) = 49
temp = 49
```

Since `height[start] > height[end]`, we move `end--`.

The remaining steps follow the same process.

**Final Output:**

```cpp
49
```

## 8. Important Operations Explained

### `min(height[start], height[end])`

Finds the shorter boundary because the water level cannot exceed the shorter line.

### `end - start`

Calculates the distance between the two lines, which represents the container's width.

### `hei * (end - start)`

Calculates the amount of water that the current container can hold.

### `temp = max(curr, temp)`

Stores the maximum area found so far.

### `start++`

Moves the left pointer forward when the left line is shorter.

### `end--`

Moves the right pointer backward when the right line is shorter or both heights are equal.

## 9. Time and Space Complexity

### Brute Force

- **Time Complexity:** O(n²)
- **Auxiliary Space Complexity:** O(1)

### Two Pointers

- **Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(1)

**Why O(n)?**

Both pointers move toward each other. Each pointer moves at most n-1 times, so the total number of iterations is linear.

**Why O(1) space?**

We only use:

- `n`
- `start`
- `end`
- `temp`
- `hei`
- `curr`

No additional array or data structure is required.

## 10. Approach Comparison

| Feature         | Brute Force          | Two Pointers           |
| --------------- | -------------------- | ---------------------- |
| Technique       | Nested Loops         | Two Pointers           |
| Time            | O(n²)                | O(n)                   |
| Auxiliary Space | O(1)                 | O(1)                   |
| Checks          | All pairs            | Smart pointer movement |
| Efficiency      | Slow for large input | Optimal                |

## 11. Important Concepts Learned

- Arrays
- Brute Force
- Two Pointers
- Greedy Pointer Movement
- `min()` and `max()`
- Width and Height Calculation
- Space Optimization
- Time Complexity Optimization

## 12. Key Takeaway

The most important learning from this problem is understanding **why we move the smaller height pointer**.

The shorter line limits the water level. Moving the taller line cannot improve the current area because the width decreases while the limiting height stays the same or becomes smaller.

By moving the shorter line, we get a chance to find a taller boundary and potentially increase the area.

**Remember:**

- Brute Force → Check every pair → O(n²)
- Two Pointers → Move the smaller height → O(n)

This problem is an important example of optimizing a brute force solution using the Two Pointers technique.

## 13. LeetCode Information

- **Problem Number:** 11
- **Problem Name:** Container With Most Water
- **Difficulty:** Medium
- **Topics:** Array, Two Pointers, Greedy
- **Language:** C++
- **Approaches:** Brute Force + Two Pointers
- **Optimal Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(1)
- **Status:** Solved
