# Single Element in a Sorted Array

## Problem Statement

You are given a sorted integer array `nums` where every element appears **exactly twice**, except for one element that appears **only once**.

Find and return the element that appears only once.

Your solution must run in **O(log n)** time and use **O(1)** extra space.

### Example 1

**Input:**

```text
nums = [1,1,2,3,3,4,4,8,8]
```

**Output:**

```text
2
```

**Explanation:**

Every element appears twice except `2`, which appears only once.

---

### Example 2

**Input:**

```text
nums = [3,3,7,7,10,11,11]
```

**Output:**

```text
10
```

**Explanation:**

Every element appears twice except `10`.

---

### Example 3

**Input:**

```text
nums = [1]
```

**Output:**

```text
1
```

**Explanation:**

The array contains only one element, so that element is the single element.

---

## Constraints

* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^5`
* `nums` is sorted in **ascending order**.
* Every element appears exactly **twice**, except for one element that appears exactly once.
* The array contains an **odd number of elements**.

---

## Approach

A straightforward approach would be to iterate through the array and find the element without a pair, but that would take `O(n)` time.

Instead, we use **Binary Search**.

Because the array is sorted and all elements except one occur in pairs, the indices of paired elements follow a predictable pattern.

Before the single element:

```text
Index:  0  1  2  3  4  5
Value:  1  1  2  2  3  3
        ↑  ↑  ↑  ↑  ↑  ↑
       pair pair pair
```

The first element of every pair is normally at an **even index**, and the second element is at an **odd index**.

After the single element, this pattern is shifted:

```text
Index:  0  1  2  3  4  5  6
Value:  1  1  2  3  3  4  4
              ↑
           single
```

Now the pairs occur as:

```text
(0,1), (2,3), (4,5)
```

before the single element, but the pairing pattern changes after it.

At every step:

1. Calculate `mid`.
2. Check whether `nums[mid]` is the single element.
3. Determine whether `mid` is even or odd.
4. Compare `nums[mid]` with its neighboring element to determine which half contains the single element.
5. Eliminate half of the search space.

This allows the search to be performed in **O(log n)** time.

---

## Complexity

* **Time Complexity:** `O(log n)`
* **Space Complexity:** `O(1)`
