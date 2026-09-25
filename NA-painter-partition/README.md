# 🖌️ Allocate Boards to Painters

## Problem Statement

You are given an integer array `boards` of size `n`, where `boards[i]` represents the time required to paint the `i`-th board.

You are also given an integer `m`, representing the number of painters available.

Each painter can only paint a **contiguous sequence of boards**. All painters work simultaneously.

Your task is to divide the boards among the `m` painters such that:

- Every board is assigned to exactly one painter.
- Each painter receives a contiguous sequence of boards.
- All boards must be painted.
- The **maximum time taken by any single painter is minimized**.

Return the minimum possible value of the maximum painting time.

If it is impossible to assign the boards because there are more painters than boards, return `-1`.

---

## Examples

### Example 1

**Input:**
```text
boards = [40, 30, 10, 20]
m = 2
