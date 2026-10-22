# 🍾 1518. Water Bottles

## 📌 Problem Statement

You are given two integers:

- `numBottles`: The number of full water bottles you initially have.
- `numExchange`: The number of empty water bottles required to exchange for one full water bottle.

You can drink a full water bottle, which turns it into an empty bottle.

You can exchange empty bottles for full bottles and drink them. Find the **maximum number of water bottles you can drink**.

---

## 💡 Examples

### Example 1

```text
Input:
numBottles = 9
numExchange = 3

Output:
13
```

Explanation:

- Drink the initial 9 bottles.
- Exchange 9 empty bottles for 3 full bottles and drink them.
- Exchange the resulting 3 empty bottles for 1 full bottle and drink it.

Total bottles consumed:

```text
9 + 3 + 1 = 13
```

### Example 2

```text
Input:
numBottles = 15
numExchange = 4

Output:
19
```

Explanation:

- Drink the initial 15 bottles.
- Exchange 12 empty bottles for 3 full bottles.
- Drink those 3 bottles, leaving 6 empty bottles.
- Exchange 4 empty bottles for 1 full bottle.
- Drink it, leaving 3 empty bottles, which are insufficient for another exchange.

Total bottles consumed:

```text
15 + 3 + 1 = 19
```

---

## 📏 Constraints

- `1 <= numBottles <= 100`
- `2 <= numExchange <= 100`

---

# 🧠 Approach: Simulation + Greedy

This is your original approach.

The idea is to simulate the bottle exchange process until the number of available empty bottles is insufficient for another exchange.

We maintain two important values:

- `count`: Total number of bottles consumed.
- `numBottles`: The number of empty bottles currently available for exchange.

## Step 1: Initialize the Total Count

```cpp
int count = numBottles;
```

Initially, all the bottles are full, and we can drink all of them.

Therefore, the initial total is equal to `numBottles`.

For example:

```text
numBottles = 9

count = 9
```

## Step 2: Check Whether an Exchange Is Possible

```cpp
while(numBottles >= numExchange)
```

We continue exchanging bottles while the number of available empty bottles is at least `numExchange`.

If fewer empty bottles are available, we cannot exchange them for another full bottle.

## Step 3: Calculate the Number of New Bottles

```cpp
int newBottles = numBottles / numExchange;
```

Integer division calculates how many full bottles can be obtained from the current empty bottles.

For example:

```text
numBottles = 9
numExchange = 3

newBottles = 9 / 3 = 3
```

We can exchange 9 empty bottles for 3 full bottles.

## Step 4: Update the Total Count

```cpp
count = count + newBottles;
```

The newly exchanged bottles will also be consumed.

Therefore, we add them to the total number of bottles drunk.

For example:

```text
Previous count = 9
New bottles = 3

count = 9 + 3 = 12
```

## Step 5: Calculate the Remaining Empty Bottles

```cpp
numBottles = numBottles % numExchange + newBottles;
```

This is the most important line in your solution.

It combines two things:

**1. Remaining empty bottles after exchange**

```cpp
numBottles % numExchange
```

**2. Empty bottles obtained after drinking the newly exchanged bottles**

```cpp
newBottles
```

Therefore:

```text
Remaining empty bottles =
Unused empty bottles + Newly consumed bottles
```

For example:

```text
numBottles = 10
numExchange = 3

Unused empty bottles = 10 % 3 = 1
New bottles = 10 / 3 = 3

Updated numBottles = 1 + 3 = 4
```

We now have 4 empty bottles available for the next exchange.

---

# 💻 C++ Solution — Your Implementation

```cpp
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        // All drink Bottle ka count.
        int count = numBottles;

        while(numBottles >= numExchange)
        {
            // Exchange Bottles
            int newBottles = numBottles / numExchange;

            // Jo Exchange Bottle hai.
            // Usko drink kar liye hai. To usko count ker liye hai.
            count = count + newBottles;

            // ExtraEmpty Bottles + Exchange Bottles
            // drink ker liye hai.
            numBottles = numBottles % numExchange + newBottles;
        }

        return count;
    }
};
```

---

# 🔍 Dry Run

Consider:

```text
numBottles = 9
numExchange = 3
```

### Step 1: Initialize

```text
count = 9
numBottles = 9
numExchange = 3
```

We have drunk 9 bottles. After drinking, we have 9 empty bottles.

### Step 2: First Exchange

The loop condition is true:

```text
9 >= 3
```

Calculate the new bottles:

```text
newBottles = 9 / 3 = 3
```

Update the total:

```text
count = 9 + 3 = 12
```

Update the empty bottles:

```text
numBottles = 9 % 3 + 3
           = 0 + 3
           = 3
```

We now have 3 empty bottles.

### Step 3: Second Exchange

The loop condition is still true:

```text
3 >= 3
```

Calculate the new bottles:

```text
newBottles = 3 / 3 = 1
```

Update the total:

```text
count = 12 + 1 = 13
```

Update the empty bottles:

```text
numBottles = 3 % 3 + 1
           = 0 + 1
           = 1
```

We now have 1 empty bottle.

### Step 4: Stop the Loop

Check the condition:

```text
1 >= 3
```

This is false, so the loop stops.

### Final Answer

```text
count = 13
```

The maximum number of bottles drunk is **13**.

---

# 📊 Dry Run Table

For `numBottles = 9` and `numExchange = 3`:

| Step | Empty Bottles Before Exchange | New Bottles | Total Consumed | Empty Bottles After Drinking |
|---|---:|---:|---:|---:|
| Initial | 9 | — | 9 | 9 |
| First exchange | 9 | 3 | 12 | 3 |
| Second exchange | 3 | 1 | 13 | 1 |
| Stop | 1 | 0 | 13 | 1 |

Final output:

```text
13
```

---

# ⚙️ How Does the Formula Work?

Your formula is:

```cpp
numBottles = numBottles % numExchange + newBottles;
```

Suppose:

```text
numBottles = 10
numExchange = 3
```

We can exchange 9 of the 10 empty bottles for 3 full bottles.

```text
10 / 3 = 3
10 % 3 = 1
```

After drinking the 3 new bottles, we receive 3 additional empty bottles.

Therefore:

```text
Updated empty bottles = 1 + 3 = 4
```

The formula correctly tracks both the unused empty bottles and the bottles consumed in the current exchange.

---

# 📊 Approach Comparison

| Feature | Simulation Approach |
|---|---|
| Main technique | Greedy + Simulation |
| Uses a loop | Yes |
| Tracks total bottles | `count` |
| Tracks available empty bottles | `numBottles` |
| Uses division and remainder | Yes |
| Extra data structure required | No |

---

# ⏱️ Complexity Analysis

Let:

- \(B\) be the initial number of bottles.
- \(E\) be the number of empty bottles required per exchange.

### Time Complexity

Each iteration exchanges bottles and updates the remaining empty bottles.

Since `numExchange >= 2`, the number of empty bottles decreases as the process continues, and the loop runs only logarithmically many times in the initial bottle count.

The time complexity is:

\[
O(\log B)
\]

### Space Complexity

Only a few integer variables are used:

```cpp
int count;
int newBottles;
```

No additional array or data structure is required.

Therefore:

\[
O(1)
\]

---

# 🧩 Important Concepts

### 1. Simulation

We simulate the actual bottle exchange process step by step.

### 2. Greedy Approach

Whenever an exchange is possible, we exchange as many empty bottles as possible in that iteration.

### 3. Integer Division

```cpp
numBottles / numExchange
```

Calculates the number of complete exchanges possible.

### 4. Modulo Operator

```cpp
numBottles % numExchange
```

Calculates the empty bottles left over after complete exchanges.

### 5. Loop Condition

```cpp
while(numBottles >= numExchange)
```

The process stops when we cannot exchange the remaining empty bottles.

---

# 🎯 Key Takeaway

Remember this pattern:

```text
Initialize total count
        ↓
Check if exchange is possible
        ↓
Calculate new bottles
        ↓
Add new bottles to total
        ↓
Update remaining empty bottles
        ↓
Repeat until exchange is impossible
```

Your solution correctly simulates the bottle exchange process using division, modulo, and a `while` loop.

---

# 📌 LeetCode Information

- **Problem:** Water Bottles
- **Problem Number:** 1518
- **Difficulty:** Easy
- **Topics:** Math, Simulation
- **Language:** C++

## ⭐ Key Learning

> **Use integer division to calculate how many bottles can be exchanged, modulo to calculate the unused empty bottles, and a running total to count every bottle consumed.**