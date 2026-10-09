# Best Time to Buy and Sell Stock

## Problem Statement

You are given an array `prices` where `prices[i]` represents the price of a stock on the `i`-th day.

You want to maximize your profit by choosing **a single day to buy one stock and a different day in the future to sell that stock**.

Return the maximum profit you can achieve from this transaction.

If you cannot achieve any profit, return `0`.

### Example 1

**Input:**

```text
prices = [7,1,5,3,6,4]
```

**Output:**

```text
5
```

**Explanation:**

Buy the stock on day 2 at a price of `1` and sell it on day 5 at a price of `6`.

The maximum profit is `6 - 1 = 5`.

Note that you must buy before you sell.

---

### Example 2

**Input:**

```text
prices = [7,6,4,3,1]
```

**Output:**

```text
0
```

**Explanation:**

The stock price continuously decreases. No profitable transaction is possible, so the maximum profit is `0`.

---

### Example 3

**Input:**

```text
prices = [2,4,1]
```

**Output:**

```text
2
```

**Explanation:**

Buy the stock on day 1 at a price of `2` and sell it on day 2 at a price of `4`.

The maximum profit is `4 - 2 = 2`.

---

### Example 4

**Input:**

```text
prices = [3,2,6,5,0,3]
```

**Output:**

```text
4
```

**Explanation:**

Buy the stock at a price of `2` and sell it later at a price of `6`.

The maximum profit is `6 - 2 = 4`.

---

## Constraints

* `1 <= prices.length <= 10^5`
* `0 <= prices[i] <= 10^4`

## Approach: Single Pass

The problem can be solved efficiently by traversing the array once while maintaining two variables:

* `bestBuy`: The minimum stock price encountered so far.
* `maxProfit`: The maximum profit found so far.

### Algorithm

1. Initialize `bestBuy` with the first stock price and `maxProfit` with `0`.
2. Traverse the array from left to right.
3. If the current price is lower than `bestBuy`, update `bestBuy`.
4. Otherwise, calculate the profit by subtracting `bestBuy` from the current price.
5. Update `maxProfit` if the calculated profit is greater than the current maximum.
6. Return `maxProfit`.

## Complexity Analysis

* **Time Complexity:** `O(n)` — The array is traversed once.
* **Space Complexity:** `O(1)` — Only two variables are maintained, excluding the input array.
