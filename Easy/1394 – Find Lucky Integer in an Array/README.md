# LeetCode 1394 – Find Lucky Integer in an Array

## 1. Problem Statement

Given an array of integers `arr`, a lucky integer is an integer whose frequency in the array is equal to its value.

Return the largest lucky integer in the array. If no lucky integer exists, return `-1`.

**Important:**

- Frequency means the number of times an element appears in the array.
- The element's value must be equal to its frequency.
- If multiple lucky integers exist, return the largest one.

## 2. Examples

### Example 1

**Input:**

```cpp
arr = [2,2,3,4]
```

**Output:**

```cpp
2
```

**Explanation:**

- Number 2 appears 2 times → Lucky integer.
- Number 3 appears 1 time → Not lucky.
- Number 4 appears 1 time → Not lucky.

Therefore, the largest lucky integer is `2`.

### Example 2

**Input:**

```cpp
arr = [1,2,2,3,3,3]
```

**Output:**

```cpp
3
```

**Explanation:**

- Number 1 appears 1 time → Lucky.
- Number 2 appears 2 times → Lucky.
- Number 3 appears 3 times → Lucky.

The largest lucky integer is `3`.

### Example 3

**Input:**

```cpp
arr = [2,2,2,3,3]
```

**Output:**

```cpp
-1
```

**Explanation:**

- Number 2 appears 3 times → Not lucky.
- Number 3 appears 2 times → Not lucky.

No lucky integer exists, so return `-1`.

## 3. Constraints

- 1 ≤ arr.length ≤ 500
- 1 ≤ arr[i] ≤ 500

## 4. Approach – Hash Map + Frequency Counting

### Concept

We use an `unordered_map` to calculate the frequency of every element.

A hash map stores data in key-value pairs:

- `key` → The array element.
- `value` → How many times that element appears.

For example:

```cpp
arr = [2,2,3,4]
```

After frequency counting:

```cpp
freq[2] = 2
freq[3] = 1
freq[4] = 1
```

Now we check every key-value pair.

If:

```cpp
key == count
```

Then the number is a lucky integer.

We update `max_lucky` to store the largest lucky integer.

### Step-by-Step Algorithm

1. Calculate the size of the array using `arr.size()`.
2. Create an `unordered_map<int, int> freq`.
3. Initialize `max_lucky = -1`.
4. Traverse the array and increase the frequency of every element:
   ```cpp
   freq[arr[i]]++;
   ```
5. Traverse the hash map using a range-based for loop.
6. Extract the key and its frequency:
   ```cpp
   int key = pair.first;
   int count = pair.second;
   ```
7. Check whether `key == count`.
8. If true, update:
   ```cpp
   max_lucky = max(key, max_lucky);
   ```
9. Return `max_lucky`.

## 5. C++ Solution – Your Code

```cpp
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> freq;
        int max_lucky = -1;

        // Harek element ka freq nikal liye hjai.
        for(int i = 0;i<n;i++)
        {
            freq[arr[i]]++;
        }

        // check to the lucky number
        for(auto &pair : freq)
        {
            int key = pair.first;
            int count = pair.second;

            // agar equal key and count then max_lucky updated
            if(key == count)
            {
                max_lucky = max(key,max_lucky);
            }
        }

        return max_lucky;
    }
};
```

## 6. Dry Run – Your Approach

**Input:**

```cpp
arr = [2,2,3,4,2,3,3]
```

Initially:

```cpp
unordered_map<int, int> freq;
int max_lucky = -1;
```

### First Loop – Frequency Counting

We traverse the array and count every element.

| Index | arr[i] | Operation | Frequency Map      |
| ----- | -----: | --------- | ------------------ |
| 0     |      2 | freq[2]++ | {2: 1}             |
| 1     |      2 | freq[2]++ | {2: 2}             |
| 2     |      3 | freq[3]++ | {2: 2, 3: 1}       |
| 3     |      4 | freq[4]++ | {2: 2, 3: 1, 4: 1} |
| 4     |      2 | freq[2]++ | {2: 3, 3: 1, 4: 1} |
| 5     |      3 | freq[3]++ | {2: 3, 3: 2, 4: 1} |
| 6     |      3 | freq[3]++ | {2: 3, 3: 3, 4: 1} |

Final frequency map:

```cpp
freq = {
    2 : 3,
    3 : 3,
    4 : 1
};
```

### Second Loop – Check Lucky Integer

Now we check each key-value pair.

| key | count | key == count? | max_lucky |
| --: | ----: | ------------- | --------: |
|   2 |     3 | False         |        -1 |
|   3 |     3 | True          |         3 |
|   4 |     1 | False         |         3 |

**Note:** `unordered_map` does not guarantee iteration order. The table shows one possible order; the final answer remains the same.

Final result:

```cpp
return 3;
```

**Output:**

```cpp
3
```

## 7. Important Operations Explained

### `unordered_map<int, int> freq;`

Creates a hash map that stores each number and its frequency.

### `freq[arr[i]]++;`

Increases the frequency of the current array element by 1.

If the key does not exist, `unordered_map` creates it with an initial value of 0 before incrementing.

### `for(auto &pair : freq)`

A range-based loop that visits every key-value pair in the hash map.

### `pair.first`

Returns the key, which represents the array element.

### `pair.second`

Returns the value, which represents the frequency of that element.

### `key == count`

Checks whether the number is lucky.

### `max(key, max_lucky)`

Keeps the largest lucky integer found so far.

## 8. Why Do We Initialize `max_lucky = -1`?

The problem requires returning `-1` if no lucky integer exists.

Therefore, we initialize:

```cpp
int max_lucky = -1;
```

If no element satisfies:

```cpp
key == count
```

The value remains `-1`.

If a lucky integer is found, we update it with the largest valid value.

## 9. Time and Space Complexity

### Time Complexity: O(n) Average

Let `n` be the size of the array.

- First loop: O(n) average time for frequency counting.
- Second loop: O(k), where `k` is the number of distinct elements.
- Since `k ≤ n`, total average time complexity is O(n).

**Note:** Hash map operations are O(1) on average, but can take O(n) in the worst case due to collisions. Thus, the worst-case time complexity of this implementation can be O(n²).

### Auxiliary Space Complexity: O(k)

The hash map stores one entry for every distinct element.

- `k` = number of distinct elements.
- In the worst case, `k = n`.

Therefore:

```cpp
O(n)
```

## 10. Alternative Approach – Frequency Array

Since the constraints specify:

```cpp
1 <= arr[i] <= 500
```

We can use a frequency array instead of an `unordered_map`.

### C++ Code

```cpp
class Solution {
public:
    int findLucky(vector<int>& arr) {

        vector<int> freq(501, 0);

        for(int num : arr)
        {
            freq[num]++;
        }

        for(int i = 500; i >= 1; i--)
        {
            if(freq[i] == i)
            {
                return i;
            }
        }

        return -1;
    }
};
```

### Concept

1. Create a frequency array of size 501.
2. Count the frequency of each number.
3. Traverse from 500 down to 1.
4. If `freq[i] == i`, return `i`.
5. If no lucky integer is found, return `-1`.

### Why Traverse Backwards?

The problem asks for the largest lucky integer.

By traversing from 500 down to 1, the first matching value is automatically the largest lucky integer.

### Complexity Analysis

- **Time Complexity:** O(n + 500) = O(n), since 500 is a constant.
- **Auxiliary Space Complexity:** O(1), since the frequency array has a fixed size of 501.

## 11. Approach Comparison

| Feature            | Your Hash Map Approach | Frequency Array      |
| ------------------ | ---------------------- | -------------------- |
| Data Structure     | unordered_map          | vector               |
| Frequency Counting | Yes                    | Yes                  |
| Time Complexity    | O(n) average           | O(n + 500)           |
| Auxiliary Space    | O(k)                   | O(1)                 |
| Largest Value      | Using max()            | Reverse traversal    |
| Best Use           | General integer ranges | Small bounded values |

## 12. Important Concepts Learned

- Arrays
- Hash Maps
- `unordered_map`
- Frequency Counting
- Key-Value Pairs
- Range-Based For Loop
- `pair.first` and `pair.second`
- `max()` Function
- Frequency Array Optimization

## 13. Key Takeaway

The main lesson from this problem is that a hash map makes frequency counting easy and efficient.

Instead of repeatedly counting each element using nested loops, we store its frequency in a hash map.

Then we simply compare:

```cpp
key == count
```

If they are equal, the number is lucky.

**Remember:**

- Hash Map → Count frequencies.
- Key → Array element.
- Value → Frequency.
- `key == count` → Lucky integer.
- `max()` → Find the largest lucky integer.

Your solution uses a general-purpose frequency-counting technique that is useful in many array problems.

## 14. LeetCode Information

- **Problem Number:** 1394
- **Problem Name:** Find Lucky Integer in an Array
- **Difficulty:** Easy
- **Topics:** Array, Hash Table, Counting
- **Language:** C++
- **Approach:** Hash Map + Frequency Counting
- **Average Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(k), where k is the number of distinct elements
- **Status:** Solved
