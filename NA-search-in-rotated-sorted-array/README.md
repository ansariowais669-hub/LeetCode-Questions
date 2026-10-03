# Search in Rotated Sorted Array

## Problem Statement

You are given an integer array `nums` that was originally sorted in **ascending order** but has been rotated at an unknown pivot.

For example:

```text
[0,1,2,4,5,6,7] → [4,5,6,7,0,1,2]
```

Given the rotated sorted array `nums` and an integer `target`, return the **index** of `target` if it exists in `nums`. Otherwise, return `-1`.

You must write an algorithm with **O(log n)** time complexity.

### Example 1

**Input:**

```text
nums = [4,5,6,7,0,1,2]
target = 0
```

**Output:**

```text
4
```

**Explanation:**

The target `0` is present at index `4`.

---

### Example 2

**Input:**

```text
nums = [4,5,6,7,0,1,2]
target = 3
```

**Output:**

```text
-1
```

**Explanation:**

The target `3` does not exist in the array.

---

### Example 3

**Input:**

```text
nums = [1]
target = 1
```

**Output:**

```text
0
```

**Explanation:**

The array contains only one element, and it is equal to the target.

---

## Constraints

* `1 <= nums.length <= 5000`
* `-10^4 <= nums[i] <= 10^4`
* All values of `nums` are **unique**.
* `nums` is sorted in ascending order and then rotated at an unknown pivot.
* `-10^4 <= target <= 10^4`

---

## Approach

A normal binary search cannot be directly applied because the array has been rotated.

However, at any point during binary search, **at least one half of the current search range will always be sorted**.

### Step 1: Find the Middle

Calculate:

```cpp
mid = st + (end - st) / 2;
```

If:

```cpp
nums[mid] == target
```

return `mid`.

### Step 2: Identify the Sorted Half

If:

```cpp
nums[st] <= nums[mid]
```

then the **left half is sorted**.

Otherwise, the **right half is sorted**.

### Step 3: Determine Which Half Contains the Target

If the left half is sorted, check whether the target lies within:

```text
nums[st] <= target <= nums[mid]
```

If it does, search the left half. Otherwise, search the right half.

Similarly, if the right half is sorted, check whether:

```text
nums[mid] <= target <= nums[end]
```

If it does, search the right half. Otherwise, search the left half.

This allows us to eliminate half of the search space during every iteration.

---

## Complexity

* **Time Complexity:** `O(log n)`
* **Space Complexity:** `O(1)`
