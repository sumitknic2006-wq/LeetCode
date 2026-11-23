# LeetCode 155 — Min Stack

## Problem Statement

Design a stack that supports the following operations in constant time `O(1)`:

- `push(val)` — Push an element onto the stack.
- `pop()` — Remove the top element.
- `top()` — Return the top element.
- `getMin()` — Return the minimum element currently present in the stack.

The challenge is to retrieve the minimum element without traversing the entire stack.

## Approach: Two Stacks

I used two stacks to solve this problem.

### 1. Main Stack (`st`)

Stores every element inserted into the stack.

### 2. Minimum Stack (`minSt`)

Stores elements that are minimum candidates. Whenever a new element is smaller than or equal to the current minimum, it is pushed into `minSt`.

When an element is removed from the main stack, we check whether it is also the current minimum. If it is, we remove it from `minSt` too.

This allows us to retrieve the current minimum in constant time.

## C++ Solution

```cpp
class MinStack {
private:
    std::stack<int> st;
    std::stack<int> minSt;

public:
    MinStack() {
        // Stacks are automatically initialized empty in C++
    }
    
    void push(int val) {
        if (st.empty() || minSt.top() >= val) {
            minSt.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        int ele1 = st.top();
        st.pop(); // In C++, pop() returns void, so call top() first
        
        int ele2 = minSt.top();
        if (ele1 == ele2) {
            minSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
```

## Algorithm

### Push Operation

1. Check if the main stack is empty.
2. If empty, push the value into `minSt`.
3. Otherwise, compare the value with the current minimum.
4. If the value is smaller than or equal to the current minimum, push it into `minSt`.
5. Push the value into the main stack.

### Pop Operation

1. Store the top element of the main stack.
2. Remove the top element from the main stack.
3. Check if the removed element equals the top of `minSt`.
4. If equal, remove it from `minSt` too.

### Top Operation

Return the top element of the main stack using `st.top()`.

### GetMin Operation

Return the top element of `minSt` using `minSt.top()`.

## Dry Run

Operations:

```text
push(-2)
push(0)
push(-3)
getMin()
pop()
top()
getMin()
```

| Operation | Main Stack (`st`) | Min Stack (`minSt`) | Output |
|---|---|---|---|
| `push(-2)` | [-2] | [-2] | — |
| `push(0)` | [-2, 0] | [-2] | — |
| `push(-3)` | [-2, 0, -3] | [-2, -3] | — |
| `getMin()` | [-2, 0, -3] | [-2, -3] | -3 |
| `pop()` | [-2, 0] | [-2] | — |
| `top()` | [-2, 0] | [-2] | 0 |
| `getMin()` | [-2, 0] | [-2] | -2 |

**Output:**

```text
[null, null, null, null, -3, null, 0, -2]
```

## Handling Duplicate Minimum Values

The condition:

```cpp
minSt.top() >= val
```

is important because it handles duplicate minimum values.

For example, if we push:

```text
5, 3, 2, 2
```

The minimum stack will store:

```text
5, 3, 2, 2
```

When one `2` is popped, another `2` still remains in the minimum stack, so the minimum is still correctly returned as `2`.

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| `push()` | O(1) |
| `pop()` | O(1) |
| `top()` | O(1) |
| `getMin()` | O(1) |

**Auxiliary Space Complexity:** O(n)

In the worst case, both stacks can store up to `n` elements.

## C++ Concepts Used

- Stack data structure
- STL `stack`
- `push()`, `pop()`, and `top()`
- Maintaining a secondary data structure
- Duplicate value handling
- Constant-time minimum retrieval

## Key Takeaway

Using an additional stack to track minimum values avoids traversing the main stack whenever `getMin()` is called.

The main stack stores all elements, while the minimum stack maintains the current minimum efficiently. Both stacks work together to achieve O(1) time for every required operation.

**LeetCode:** 155 — Min Stack  
**Difficulty:** Medium  
**Topics:** Stack, Design