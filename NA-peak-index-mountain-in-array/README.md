# Peak Index in a Mountain Array

## Problem Statement

You are given an integer array `nums` that is guaranteed to be a **mountain array**.

A mountain array is an array where:

- `nums[0] < nums[1] < ... < nums[i]`
- `nums[i] > nums[i+1] > ... > nums[n-1]`

for some index `i`, where `i` is the **peak index**.

Your task is to find and return the **peak index** `i`.

You must solve the problem using **binary search**.

### Example 1

**Input:**
```text
nums = [0, 2, 5, 3, 1]
