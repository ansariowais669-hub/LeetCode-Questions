# Product of Array Except Self

## Problem Statement

Given an integer array `nums`, return an array `answer` such that:

* `answer[i]` is equal to the product of all the elements of `nums` **except `nums[i]`**.
* The product of any prefix or suffix of `nums` is guaranteed to fit within a **32-bit integer**.

You must solve the problem **without using division**.

Your solution should run in **O(n)** time complexity.

### Example 1

**Input:**

```text
nums = [1,2,3,4]
```

**Output:**

```text
[24,12,8,6]
```

**Explanation:**

* `answer[0] = 2 × 3 × 4 = 24`
* `answer[1] = 1 × 3 × 4 = 12`
* `answer[2] = 1 × 2 × 4 = 8`
* `answer[3] = 1 × 2 × 3 = 6`

---

### Example 2

**Input:**

```text
nums = [-1,1,0,-3,3]
```

**Output:**

```text
[0,0,9,0,0]
```

**Explanation:**

For each index, calculate the product of every element except the element at that index.

* `answer[0] = 1 × 0 × (-3) × 3 = 0`
* `answer[1] = (-1) × 0 × (-3) × 3 = 0`
* `answer[2] = (-1) × 1 × (-3) × 3 = 9`
* `answer[3] = (-1) × 1 × 0 × 3 = 0`
* `answer[4] = (-1) × 1 × 0 × (-3) = 0`

---

## Constraints

* `2 <= nums.length <= 10^5`
* `-30 <= nums[i] <= 30`
* The product of any prefix or suffix of `nums` is guaranteed to fit in a **32-bit integer**.
* Division is **not allowed**.

---

## Approach

The solution can be obtained using **prefix products** and **suffix products**.

### Prefix Product

For every index `i`, store the product of all elements **to the left** of `i`.

For example:

```text
nums = [1, 2, 3, 4]

Prefix:
[1, 1, 2, 6]
```

### Suffix Product

Traverse the array from right to left while maintaining a `suffix` product.

For every index `i`, multiply the prefix product already stored in `ans[i]` by the product of all elements to its right.

This allows the answer to be calculated in **O(n)** time without using division.

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` extra space, excluding the output array.
