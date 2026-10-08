# Sort Colors

## Problem Statement

Given an integer array `nums` containing only `0`, `1`, and `2`, sort the array **in-place** so that all `0`s come first, followed by all `1`s, and then all `2`s.

You must not use the built-in sorting function.

Try to solve the problem using the **Dutch National Flag (DNF) Algorithm** in **one pass** with constant extra space.

### Example 1

**Input:**

```text
nums = [2,0,2,1,1,0]
```

**Output:**

```text
[0,0,1,1,2,2]
```

**Explanation:**

The array contains:

* Two `0`s
* Two `1`s
* Two `2`s

After sorting, they appear in the order `0 → 1 → 2`.

---

### Example 2

**Input:**

```text
nums = [2,0,1]
```

**Output:**

```text
[0,1,2]
```

---

### Example 3

**Input:**

```text
nums = [2,2,0,0,1,1,2,0]
```

**Output:**

```text
[0,0,0,1,1,2,2,2]
```

---

### Example 4

**Input:**

```text
nums = [0]
```

**Output:**

```text
[0]
```

---

## Constraints

* `1 <= nums.length <= 300`
* `nums[i]` is either `0`, `1`, or `2`.
* The array must be sorted **in-place**.
* Do not use the built-in sorting function.

---

## Approach 1: Counting

One way to solve the problem is to count the number of `0`s, `1`s, and `2`s.

### Steps

1. Traverse the array and count the occurrences of each value.
2. Traverse the array again.
3. Fill the array with all the `0`s first.
4. Then fill all the `1`s.
5. Finally, fill all the `2`s.

### Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## Approach 2: Dutch National Flag Algorithm

The **Dutch National Flag Algorithm** sorts the array in a single pass using three pointers:

```text
low        mid              high
 ↓          ↓                 ↓
[ 0s ] [ unknown elements ] [ 2s ]
```

* `low` → position where the next `0` should be placed.
* `mid` → current element being examined.
* `high` → position where the next `2` should be placed.

### Case 1: `nums[mid] == 0`

Swap the current element with the element at `low`.

```cpp
swap(nums[low], nums[mid]);
low++;
mid++;
```

### Case 2: `nums[mid] == 1`

`1` belongs in the middle, so simply move `mid` forward.

```cpp
mid++;
```

### Case 3: `nums[mid] == 2`

Swap the current element with the element at `high` and decrease `high`.

```cpp
swap(nums[mid], nums[high]);
high--;
```

We do **not** increment `mid` here because the element swapped from `high` has not been examined yet.

The algorithm continues until:

```cpp
mid > high
```

At that point, the array is completely sorted.

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`
* **Number of passes:** `1`
