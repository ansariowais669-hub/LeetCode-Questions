Majority Element

Difficulty: Easy
Topics: Array, Sorting, Greedy, Boyer-Moore Voting Algorithm

Problem Statement

Given an array of integers nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times in the array.

You may assume that a majority element always exists in the given array.

Examples

Example 1:

Input: nums = [3, 2, 3]

Output: 3

Explanation:
The element 3 appears 2 times.
Since 2 > ⌊3/2⌋, 3 is the majority element.

Example 2:

Input: nums = [2, 2, 1, 1, 1, 2, 2]

Output: 2

Explanation:
The element 2 appears 4 times.
Since 4 > ⌊7/2⌋, 2 is the majority element.

Example 3:

Input: nums = [1]

Output: 1

Explanation:
The only element in the array appears once, so it is the majority element.

Example 4:

Input: nums = [5, 5, 5, 2, 2, 5, 3]

Output: 5

Explanation:
The element 5 appears 4 times.
Since 4 > ⌊7/2⌋, 5 is the majority element.
Constraints
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

It is guaranteed that a majority element exists in nums.

Approach 1: Sorting

Sort the array. Since the majority element appears more than n/2 times, it must occupy the middle position of the sorted array.

Alternatively, we can count consecutive equal elements after sorting.

Complexity
Time: O(n log n)
Space: O(1) auxiliary space (ignoring the sorting implementation)
Approach 2: Boyer-Moore Voting Algorithm

The Boyer-Moore Voting Algorithm maintains:

ans → current candidate for the majority element
freq → current candidate's frequency/count

For every element:

If freq == 0, choose the current element as the new candidate.
If the current element is equal to the candidate, increase freq.
Otherwise, decrease freq.

The idea is that every occurrence of a non-majority element can be paired with an occurrence of the majority element and effectively cancelled out.

Since the majority element occurs more than n/2 times, it cannot be completely cancelled by all the other elements. Therefore, the final candidate will be the majority element.

Complexity
Time: O(n)
Space: O(1)
