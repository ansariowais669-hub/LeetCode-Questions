# Spiral Matrix

**Difficulty:** Medium

## Problem Statement

Given an `m x n` matrix, return all the elements of the matrix in spiral order.

Spiral order means traversing the matrix starting from the top-left corner, moving from left to right, then top to bottom, then right to left, and finally bottom to top. Repeat this process for the remaining inner elements until all elements have been visited.

## Examples

### Example 1

**Input:**
```cpp
matrix = [[1,2,3],[4,5,6],[7,8,9]]
```

**Output:**
```cpp
[1,2,3,6,9,8,7,4,5]
```

**Explanation:**

The elements are traversed in the following order:

- Top row: `1, 2, 3`
- Right column: `6, 9`
- Bottom row: `8, 7`
- Left column: `4`
- Inner element: `5`

### Example 2

**Input:**
```cpp
matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
```

**Output:**
```cpp
[1,2,3,4,8,12,11,10,9,5,6,7]
```

**Explanation:**

The elements are traversed in spiral order, starting from the outer boundary and proceeding inward.

### Example 3

**Input:**
```cpp
matrix = [[1,2],[3,4],[5,6]]
```

**Output:**
```cpp
[1,2,4,6,5,3]
```

**Explanation:**

The traversal starts at the top row, continues down the right column, then moves left along the bottom row, and finally moves up the left column.

## Constraints

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `-100 <= matrix[i][j] <= 100`
