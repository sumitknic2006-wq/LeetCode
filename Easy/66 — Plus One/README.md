# LeetCode 66: Plus One

## 1. Problem Statement

You are given a large integer represented as an array of digits, where each element represents a digit of the number.

The digits are arranged from most significant to least significant.

Increment the number by one and return the resulting array of digits.

Since the number can be very large, we cannot safely convert the entire array into a normal integer.

## 2. Examples

### Example 1

```cpp
Input: digits = [1,2,3]
Output: [1,2,4]
```

**Explanation:** The array represents `123`. After adding one, it becomes `124`.

### Example 2

```cpp
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
```

**Explanation:** The array represents `4321`. After adding one, it becomes `4322`.

### Example 3

```cpp
Input: digits = [9]
Output: [1,0]
```

**Explanation:** Adding one to `9` results in `10`.

## 3. Constraints

- `1 <= digits.length <= 100`
- `0 <= digits[i] <= 9`
- `digits` does not contain leading zeros.

## 4. Approach: Carry Propagation (Right to Left)

I solved this problem using **right-to-left traversal and carry handling**.

The key idea is that adding `1` only affects the last digit and potentially the digits before it if they are all `9`.

### Step 1: Start from the Last Digit

```cpp
for(int i = n-1; i >= 0; i--)
```

We start from the last digit because it represents the units place.

### Step 2: Check if the Digit is Less Than 9

```cpp
if(digits[i] < 9)
{
    digits[i]++;
    return digits;
}
```

If the digit is less than `9`, simply increment it and return the array.

There is no carry to propagate further.

### Step 3: Handle Digit 9

```cpp
digits[i] = 0;
```

If the digit is `9`, adding one makes it `10`.

We store `0` at the current position and carry `1` to the previous digit.

### Step 4: Handle All Digits Being 9

If the loop finishes, every digit was `9`.

For example:

```text
[9,9,9] → [0,0,0]
```

We insert `1` at the beginning:

```cpp
digits.insert(digits.begin(),1);
```

The final result becomes:

```text
[1,0,0,0]
```

## 5. Algorithm

1. Calculate the size of the vector and store it in `n`.
2. Start traversing from the last index.
3. Check whether the current digit is less than `9`.
4. If it is less than `9`:
   - Increment the digit.
   - Return the updated vector.
5. If the current digit is `9`:
   - Change it to `0`.
   - Continue to the previous digit.
6. If all digits are `9`:
   - Insert `1` at the beginning of the vector.
7. Return the updated vector.

## 6. C++ Solution

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n-1; i >= 0; i--){

            // digit < 9
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }

            // digit = 9
            digits[i] = 0;
        }

        // all digits = 9
        digits.insert(digits.begin(), 1);

        return digits;
    }
};
```

## 7. Dry Run

### Example 1

**Input:**

```cpp
digits = [1,2,3]
```

Initial array:

```text
[1,2,3]
```

| Index | Digit | Condition | Action |
|---:|---:|---|---|
| 2 | 3 | 3 < 9 | Increment 3 to 4 and return |

**Final Output:**

```cpp
[1,2,4]
```

### Example 2: Carry Propagation

**Input:**

```cpp
digits = [1,2,9,9]
```

| Index | Digit | Condition | Action | Array |
|---:|---:|---|---|---|
| 3 | 9 | Not less than 9 | Set to 0 | `[1,2,9,0]` |
| 2 | 9 | Not less than 9 | Set to 0 | `[1,2,0,0]` |
| 1 | 2 | Less than 9 | Increment to 3 and return | `[1,3,0,0]` |

**Final Output:**

```cpp
[1,3,0,0]
```

### Example 3: All Digits Are 9

**Input:**

```cpp
digits = [9,9,9]
```

| Index | Digit | Action | Array |
|---:|---:|---|---|
| 2 | 9 | Set to 0 | `[9,9,0]` |
| 1 | 9 | Set to 0 | `[9,0,0]` |
| 0 | 9 | Set to 0 | `[0,0,0]` |

The loop finishes because every digit was `9`.

Now insert `1` at the beginning:

```cpp
digits.insert(digits.begin(), 1);
```

**Final Output:**

```cpp
[1,0,0,0]
```

## 8. Important C++ Concepts

### 1. Vector Traversal in Reverse

```cpp
for(int i = n-1; i >= 0; i--)
```

Traverses the vector from the last element to the first element.

This is useful for problems involving:

- Addition
- Carry propagation
- Digits
- Right-to-left processing

### 2. Early Return

```cpp
if(digits[i] < 9){
    digits[i]++;
    return digits;
}
```

Once the carry is resolved, we do not need to process the remaining digits.

This avoids unnecessary traversal.

### 3. insert()

```cpp
digits.insert(digits.begin(), 1);
```

Inserts the value `1` at the beginning of the vector.

It is useful when the result requires an additional digit, such as:

```text
999 + 1 = 1000
```

### 4. Carry Propagation

When a digit is `9`, adding one makes it `0` and passes the carry to the previous digit.

For example:

```text
1299 + 1

1299
   +1
----
1300
```

## 9. Edge Cases

| Input | Output | Explanation |
|---|---|---|
| `[1,2,3]` | `[1,2,4]` | Last digit increments |
| `[1,2,8]` | `[1,2,9]` | Digit becomes 9 |
| `[1,2,9]` | `[1,3,0]` | Carry moves one position |
| `[9,9]` | `[1,0,0]` | All digits are 9 |
| `[9]` | `[1,0]` | Single-digit carry |
| `[4,3,2,1]` | `[4,3,2,2]` | No carry required |

## 10. Complexity Analysis

### Time Complexity: O(n)

- In the best case, the loop stops at the last digit, giving O(1) time.
- In the worst case, all digits are `9`, and the entire array is traversed.
- Inserting a new digit at the beginning of a vector may also require shifting elements.

Therefore, the worst-case time complexity is **O(n)**.

### Auxiliary Space Complexity: O(1)

- Only one integer variable `n` and the loop index `i` are used.
- The digits are modified directly in the original vector.
- No separate digit array is created.

The vector may require additional memory when inserting a new leading digit, but no separate auxiliary data structure is used.

## 11. Key Concepts Learned

- Array / Vector Traversal
- Reverse Traversal
- Carry Propagation
- Digit Manipulation
- In-place Modification
- Early Return
- Handling Overflow in Digit Representation

## 12. Key Takeaway

The most important observation in this problem is that we only need to process digits from right to left.

```cpp
if(digits[i] < 9){
    digits[i]++;
    return digits;
}

digits[i] = 0;
```

- If the digit is less than `9`, increment it and stop.
- If the digit is `9`, convert it to `0` and continue carrying.
- If all digits are `9`, add an extra `1` at the beginning.

**Remember:** You don't need to convert the entire number into an integer. Working directly with the digits avoids integer overflow and makes the solution efficient.

## 13. LeetCode Information

- **Problem Number:** 66
- **Problem Name:** Plus One
- **Difficulty:** Easy
- **Topics:** Array, Math
- **Approach:** Reverse Traversal + Carry Propagation
- **Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(1)

---

**One problem at a time. One day at a time. Consistency is the key!**