# Aggressive Cows

You are given an array `stalls` of size `N`, where `stalls[i]` represents the position of the `i-th` stall on a straight line.

You are also given an integer `C`, representing the number of cows that must be placed in the stalls.

Your task is to place all `C` cows in different stalls such that the **minimum distance between any two cows is as large as possible**.

Return the **largest possible minimum distance** between any two cows.

## Examples

### Example 1

Input:
stalls = [1, 2, 8, 4, 9]
C = 3

Output:
3

Explanation:

First, sort the stalls:

[1, 2, 4, 8, 9]

One optimal placement is:

Cows at positions: 1, 4, 8

Distances between consecutive cows are:

4 - 1 = 3
8 - 4 = 4

Therefore, the minimum distance is 3.

It is not possible to place 3 cows such that the minimum distance is 4 or more.

Hence, the answer is 3.


### Example 2

Input:
stalls = [10, 1, 2, 7, 5]
C = 3

Output:
4

Explanation:

After sorting:

[1, 2, 5, 7, 10]

One optimal placement is:

Cows at positions: 1, 5, 10

Distances are:

5 - 1 = 4
10 - 5 = 5

The minimum distance is 4.

Therefore, the largest possible minimum distance is 4.


### Example 3

Input:
stalls = [1, 3, 7, 9, 10]
C = 3

Output:
4

Explanation:

Place the cows at:

1, 7, 10

The distances are:

7 - 1 = 6
10 - 7 = 3

This gives a minimum distance of 3.

However, another placement is:

1, 5, 9

But 5 is not a stall.

The optimal valid placement is:

1, 3, 9

Distances:

3 - 1 = 2
9 - 3 = 6

So the minimum is 2.

Therefore, the answer is 2.


## Constraints

- 2 <= N <= 10^5
- 2 <= C <= N
- 0 <= stalls[i] <= 10^9
- All stall positions are distinct.


## Approach

The key idea is to use **Binary Search on the Answer**.

We binary search the possible minimum distance.

For a candidate distance `D`, check whether it is possible to place all `C` cows such that every two consecutive cows are at least `D` distance apart.

To perform this check, use a greedy approach:

1. Place the first cow in the first stall.
2. Move from left to right.
3. Whenever the current stall is at least `D` away from the last cow, place another cow.
4. If we can place `C` cows, then distance `D` is possible.
5. Otherwise, distance `D` is not possible.

If distance `D` is possible, try a larger distance.

If distance `D` is not possible, try a smaller distance.


## Function Signature

```cpp
int getDistance(vector<int>& stalls, int C);
