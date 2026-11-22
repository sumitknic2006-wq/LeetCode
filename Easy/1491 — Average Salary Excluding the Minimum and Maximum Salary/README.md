# LeetCode 1491 — Average Salary Excluding the Minimum and Maximum Salary

## Problem Statement

You are given an array of unique integers `salary`, where `salary[i]` represents the salary of an employee.

Return the average salary of employees excluding the minimum and maximum salary.

The returned average must be a floating-point value.

## Example

**Input:**
```cpp
salary = [4000, 3000, 1000, 2000]
```

**Output:**
```cpp
2500.00000
```

**Explanation:**

After sorting the array:

`[1000, 2000, 3000, 4000]`

Exclude:
- Minimum salary = `1000`
- Maximum salary = `4000`

Remaining salaries:

`2000 + 3000 = 5000`

Average:

`5000 / 2 = 2500`

## Approach: Sorting

I used the sorting approach to arrange all salaries in ascending order.

After sorting:
- The first element is the minimum salary.
- The last element is the maximum salary.
- All elements between them are the salaries that need to be included in the average.

I traverse the array from index `1` to `n-2`, calculate their sum, and divide it by `n-2`.

## C++ Solution

```cpp
class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int sum = 0;

        sort(salary.begin(),salary.end());
        for(int i = 1;i<n-1;i++)
        {
            sum = sum + salary[i];
        }

        double avg = double(sum)/(n-2);
        return avg;
    }
};
```

## Algorithm

1. Store the size of the array in `n`.
2. Initialize `sum = 0`.
3. Sort the salary array in ascending order.
4. Start the loop from index `1` to `n-2`.
5. Add each salary to `sum`, excluding the minimum and maximum.
6. Divide `sum` by `n-2`.
7. Return the calculated average.

## Dry Run

**Input:**

`salary = [4000, 3000, 1000, 2000]`

### Step 1: Sorting

`[1000, 2000, 3000, 4000]`

### Step 2: Loop Execution

| Index | Value | Action | Sum |
|---|---:|---|---:|
| 0 | 1000 | Skipped | 0 |
| 1 | 2000 | Added | 2000 |
| 2 | 3000 | Added | 5000 |
| 3 | 4000 | Skipped | 5000 |

### Step 3: Average Calculation

- Total remaining salary = `5000`
- Number of remaining employees = `n - 2 = 2`

`Average = 5000 / 2 = 2500.0`

**Output:** `2500.00000`

## C++ Concepts Used

- **Vector:** Stores all the salary values.
- **Sorting:** `sort()` arranges salaries in ascending order.
- **Loop:** Iterates through the salaries excluding the first and last elements.
- **Type Casting:** `double(sum)` converts the sum to a floating-point value for division.
- **Average Calculation:** Calculates the arithmetic mean of the remaining salaries.

## Complexity Analysis

### Time Complexity: O(n log n)

- Sorting the array takes `O(n log n)`.
- Traversing the remaining salaries takes `O(n)`.
- Overall complexity is `O(n log n)`.

### Auxiliary Space Complexity: O(log n)

- `std::sort()` typically uses `O(log n)` stack space.
- Only a few extra variables (`n`, `sum`, `avg`) are used.

## Key Takeaway

Sorting makes it easy to exclude the minimum and maximum salary. Once the array is sorted, we can skip the first and last elements, calculate the sum of the remaining values, and divide by the number of remaining employees.
