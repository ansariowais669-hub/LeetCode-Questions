# Search a 2D Matrix

## Problem Statement

You are given an `m x n` integer matrix `matrix` with the following properties:

- Each row is sorted in **ascending order** from left to right.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return `true` if `target` exists in the matrix. Otherwise, return `false`.

You must solve this problem with a time complexity better than a linear search.

## Examples

**Example 1:**

**Input:**
```cpp
matrix = [[1, 3, 5, 7],
          [10, 11, 16, 20],
          [23, 30, 34, 60]]
target = 3
```

**Output:**
```cpp
true
```

**Explanation:** The target `3` exists in the matrix at position `(0, 1)`.

**Example 2:**

**Input:**
```cpp
matrix = [[1, 3, 5, 7],
          [10, 11, 16, 20],
          [23, 30, 34, 60]]
target = 13
```

**Output:**
```cpp
false
```

**Explanation:** The target `13` does not exist in the matrix.

**Example 3:**

**Input:**
```cpp
matrix = [[1, 4, 7],
          [10, 13, 16],
          [20, 25, 30]]
target = 25
```

**Output:**
```cpp
true
```

**Explanation:** The target `25` exists in the matrix at position `(2, 1)`.

## Constraints

- `m == matrix.size()`
- `n == matrix[i].size()`
- `1 <= m, n <= 100`
- `-10^4 <= matrix[i][j], target <= 10^4`
- Each row is sorted in ascending order.
- The first integer of each row is greater than the last integer of the previous row.
