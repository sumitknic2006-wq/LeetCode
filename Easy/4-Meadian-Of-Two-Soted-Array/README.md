# 📊 4. Median of Two Sorted Arrays

## 📌 Problem Statement

Given two sorted arrays `nums1` and `nums2` of sizes `m` and `n`, return the median of the two sorted arrays.

The overall run time complexity should be \(O(\log(m+n))\).

The median is the middle value of a sorted list. If the total number of elements is even, the median is the average of the two middle values.

## 💡 Examples

### Example 1

**Input:**
```text
nums1 = [1, 3]
nums2 = [2]
```

**Output:**
```text
2.00000
```

**Explanation:**

The combined sorted array is `[1, 2, 3]`.

There are 3 elements, so the middle element is `2`.

### Example 2

**Input:**
```text
nums1 = [1, 2]
nums2 = [3, 4]
```

**Output:**
```text
2.50000
```

**Explanation:**

The combined sorted array is `[1, 2, 3, 4]`.

There are 4 elements, so the median is the average of the two middle elements:

`(2 + 3) / 2.0 = 2.5`

### Example 3

**Input:**
```text
nums1 = [0, 0]
nums2 = [0, 0]
```

**Output:**
```text
0.00000
```

**Explanation:**

The combined sorted array is `[0, 0, 0, 0]`.

The two middle elements are `0` and `0`, so the median is `0`.

## ⚙️ Constraints

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-10⁶ <= nums1[i], nums2[i] <= 10⁶`
- Both `nums1` and `nums2` are sorted in non-decreasing order.

## 🧠 Approach 1: Merge Elements and Sort

### Concept

First, copy all elements from both arrays into a new vector `ans`. Then sort the combined vector and find its median.

### Steps

1. Create an empty vector `ans`.
2. Traverse `nums1` and insert each element into `ans`.
3. Traverse `nums2` and insert each element into `ans`.
4. Sort `ans` in ascending order.
5. Calculate `n = ans.size()`.
6. If `n` is odd, return the middle element `ans[n / 2]`.
7. If `n` is even, return the average of the two middle elements.

## 💻 Code (C++)

```cpp
class Solution {
public:
    double findMedianSortedArrays(
        vector<int>& nums1,
        vector<int>& nums2
    ) {
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++) {
            ans.push_back(nums2[i]);
        }

        sort(ans.begin(), ans.end());

        int n = ans.size();

        if (n % 2 != 0) {
            return ans[n / 2];
        }
        else {
            return (ans[(n / 2) - 1] + ans[n / 2]) / 2.0;
        }
    }
};
```

## 🔍 Dry Run

**Input:**
```text
nums1 = [1, 2]
nums2 = [3, 4]
```

### Step 1: Copy elements from `nums1`

```text
ans = [1, 2]
```

### Step 2: Copy elements from `nums2`

```text
ans = [1, 2, 3, 4]
```

### Step 3: Sort the combined array

```text
ans = [1, 2, 3, 4]
n = 4
```

### Step 4: Check whether the length is odd or even

```cpp
if (n % 2 != 0)
```

Since `4 % 2 == 0`, the length is even.

### Step 5: Calculate the median

```cpp
return (ans[(n / 2) - 1] + ans[n / 2]) / 2.0;
```

Substituting the values:

```text
ans[(4 / 2) - 1] = ans[1] = 2
ans[4 / 2]       = ans[2] = 3

median = (2 + 3) / 2.0
       = 5 / 2.0
       = 2.5
```

**Final Output:**
```text
2.50000
```

## 🔑 Understanding Important Operations

### 1. `push_back()`

Adds an element to the end of the vector.

```cpp
ans.push_back(nums1[i]);
```

### 2. `sort()`

Sorts all elements in ascending order.

```cpp
sort(ans.begin(), ans.end());
```

### 3. Odd-length array

For an odd number of elements, the median is at index `n / 2`.

Example:

```text
[1, 2, 3]
```

Median = `ans[1]` = `2`.

### 4. Even-length array

For an even number of elements, the median is the average of the two middle elements.

Example:

```text
[1, 2, 3, 4]
```

Median = `(2 + 3) / 2.0` = `2.5`.

**Why use `2.0` instead of `2`?**

Integer division would discard the fractional part. Dividing by `2.0` ensures floating-point division.

## ⏱️ Complexity Analysis

Let `m` be the length of `nums1` and `n` be the length of `nums2`.

- **Time Complexity:** \(O((m+n)\log(m+n))\), because all elements are copied and the combined array is sorted.
- **Auxiliary Space Complexity:** \(O(m+n)\), because the combined vector stores all elements.

This approach is straightforward, but it does not meet the problem's required logarithmic time complexity.

## 🚀 Approach 2: Binary Search on Partition (Optimal)

### Concept

The optimal approach uses binary search on the **smaller array**. Instead of combining and sorting every element, we find a partition that divides the combined arrays into left and right halves.

The partition must satisfy:

- Every element on the left is less than or equal to every element on the right.
- The left half contains the same number of elements as the right half, or one extra element if the total length is odd.

### 💻 Code (C++)

```cpp
class Solution {
public:
    double findMedianSortedArrays(
        vector<int>& nums1,
        vector<int>& nums2
    ) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }

                return (
                    static_cast<double>(max(left1, left2)) +
                    min(right1, right2)
                ) / 2.0;
            }
            else if (left1 > right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};
```

### Complexity Analysis

- **Time Complexity:** \(O(\log(\min(m,n)))\)
- **Auxiliary Space Complexity:** \(O(1)\)

## 📊 Approach Comparison

| Feature | Merge + Sort | Binary Search |
|---|---|---|
| Time Complexity | O((m+n) log(m+n)) | O(log(min(m,n))) |
| Auxiliary Space | O(m+n) | O(1) |
| Difficulty | Easy | Advanced |
| Meets required time | No | Yes |
| Best use | Learning the median logic | Optimal solution |

## 📚 Important Concepts Learned

- Vector operations
- Combining arrays
- Sorting
- Odd and even cases
- Median calculation
- Floating-point division
- Binary search
- Partitioning two sorted arrays
- Time and space complexity

## ✅ Key Takeaway

Your solution correctly calculates the median by combining and sorting both arrays. It is a good first approach for understanding the problem.

However, LeetCode #4 specifically requires \(O(\log(m+n))\) time. To meet that requirement, use binary search on the smaller array rather than sorting the combined array.

## 🏆 LeetCode Information

- **Problem:** 4. Median of Two Sorted Arrays
- **Difficulty:** Hard
- **Topics:** Array, Binary Search, Divide and Conquer
- **Language:** C++
- **Your Approach:** Merge + Sort
- **Optimal Approach:** Binary Search on Partition
