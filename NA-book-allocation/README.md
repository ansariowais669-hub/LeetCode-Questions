## 🧩 Problem — Allocate Books

### Problem Statement

You are given an array `arr` of `n` books, where `arr[i]` represents the number of pages in the `i`-th book.

You are also given `m` students. The books must be allocated to the students according to the following rules:

- Each student must be assigned at least one book.
- Each book must be assigned to exactly one student.
- The books must be allocated **contiguously**.
- A student can be assigned multiple consecutive books.
- The goal is to **minimize the maximum number of pages assigned to any single student**.

Return the minimum possible value of the maximum number of pages assigned to a student.

If it is impossible to allocate the books to all `m` students, return `-1`.

---

### Example 1

**Input:**
```text
arr = [15, 17, 20]
n = 3
m = 2
