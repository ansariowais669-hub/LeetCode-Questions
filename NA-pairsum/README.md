# Two Sum — Sorted Array

## Problem Statement

Given a **sorted** array of integers `nums` and an integer `target`, find two elements in the array whose sum is equal to `target`.

You must use **two different elements** from the array.

Return the two elements whose sum equals `target`.

### Example 1

**Input:**

```text
nums = [2, 7, 11, 15]
target = 9
```

**Output:**

```text
[2, 7]
```

**Explanation:**

`2 + 7 = 9`, so the required pair is `[2, 7]`.

---

### Example 2

**Input:**

```text
nums = [1, 3, 4, 6, 8, 10]
target = 14
```

**Output:**

```text
[4, 10]
```

**Explanation:**

`4 + 10 = 14`, so the required pair is `[4, 10]`.

---

### Example 3

**Input:**

```text
nums = [2, 3, 5, 8, 12]
target = 11
```

**Output:**

```text
[3, 8]
```

**Explanation:**

`3 + 8 = 11`, so the required pair is `[3, 8]`.

---

## Constraints

* `2 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`
* `-10^9 <= target <= 10^9`
* `nums` is sorted in **non-decreasing order**.
* Exactly one valid pair exists.
* The two elements must come from different positions in the array.

---

## Approach

Since the array is already sorted, we can use the **Two Pointer** technique.

* Initialize one pointer at the beginning of the array.
* Initialize another pointer at the end of the array.
* Calculate the sum of the two elements:

  * If `sum < target`, move the left pointer to the right.
  * If `sum > target`, move the right pointer to the left.
  * If `sum == target`, we have found the required pair.

### Algorithm

```text
left = 0
right = nums.length - 1

while left < right:
    sum = nums[left] + nums[right]

    if sum == target:
        return [nums[left], nums[right]]
    else if sum < target:
        left++
    else:
        right--
```

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` excluding the output array.

## Key Concept

> **Two Pointers on a Sorted Array**

The sorted order allows us to eliminate multiple possibilities at every step instead of checking every possible pair.
