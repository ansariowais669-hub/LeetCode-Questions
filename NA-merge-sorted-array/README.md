# Merge Sorted Arrays

## Problem Statement

You are given two sorted integer arrays `A` and `B`.

- `A` contains `m` valid elements followed by `n` empty positions represented by extra space at the end.
- `B` contains `n` valid elements.
- Both arrays are sorted in **non-decreasing order**.

Merge all elements of `B` into `A` so that `A` becomes one sorted array in **non-decreasing order**.

The merged array must be stored **inside `A` itself**.

You may assume that `A` has enough space to hold all `m + n` elements.

### Function Signature

```cpp
void merge(vector<int>& A, int m, vector<int>& B, int n);
