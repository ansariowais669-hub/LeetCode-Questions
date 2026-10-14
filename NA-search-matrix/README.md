# Spiral Matrix

## Problem Statement

Given an `m x n` matrix, return all elements of the matrix in **spiral order**.

Spiral order means traversing the matrix starting from the top-left corner, moving from left to right, then top to bottom, right to left, and bottom to top. Continue moving inward in a spiral pattern until every element has been visited.

## Examples

**Example 1:**

**Input:**
```cpp
mat = [[1, 2, 3],
       [4, 5, 6],
       [7, 8, 9]]
```

**Output:**
```cpp
[1, 2, 3, 6, 9, 8, 7, 4, 5]
```

**Explanation:**

The elements are traversed in the following order:

- Top row: `1 → 2 → 3`
- Right column: `6 → 9`
- Bottom row: `8 → 7`
- Left column: `4`
- Center element: `5`

**Example 2:**

**Input:**
```cpp
mat = [[1, 2, 3, 4],
       [5, 6, 7, 8],
       [9, 10, 11, 12]]
```

**Output:**
```cpp
[1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
```

**Explanation:**

The matrix is traversed clockwise, starting from the top-left corner and moving inward until all elements have been visited.

**Example 3:**

**Input:**
```cpp
mat = [[1, 2],
       [3, 4]]
```

**Output:**
```cpp
[1, 2, 4, 3]
```

**Explanation:**

The traversal starts at `1`, moves right to `2`, down to `4`, and then left to `3`.

**Example 4:**

**Input:**
```cpp
mat = [[1, 2, 3, 4]]
```

**Output:**
```cpp
[1, 2, 3, 4]
```

**Explanation:**

Since the matrix contains only one row, the elements are returned from left to right.

## Constraints

- `m == mat.size()`
- `n == mat[i].size()`
- `1 <= m, n <= 10`
- `-100 <= mat[i][j] <= 100`
- All elements of `mat` are unique.

## Expected Complexity

- **Time Complexity:** `O(m * n)` — every matrix element is visited once.
- **Space Complexity:** `O(1)` auxiliary space, excluding the output vector.
