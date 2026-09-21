# Majority Element

## Problem Statement

Given an array of integers `nums` of size `n`, return the **majority element**.

The majority element is the element that appears **more than** `⌊n / 2⌋` times in the array.

You may assume that the majority element **always exists** in the array.

---

## Examples

### Example 1

**Input:**

```cpp
nums = [3, 2, 3]
```

**Output:**

```cpp
3
```

---

### Example 2

**Input:**

```cpp
nums = [2, 2, 1, 1, 1, 2, 2]
```

**Output:**

```cpp
2
```

---

### Example 3

**Input:**

```cpp
nums = [1]
```

**Output:**

```cpp
1
```

---

### Example 4

**Input:**

```cpp
nums = [5, 5, 5, 2, 2, 5, 3]
```

**Output:**

```cpp
5
```

---

## Constraints

* `1 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`
* The majority element always exists in `nums`.

---

## Follow-up

Can you solve the problem in **O(n)** time and **O(1)** extra space?
