# TECHNICAL ASSESSMENT QUESTIONS IN C++

## 1. Unique Sum Ways

### Problem Statement
Given a number "result" and an array of numbers, find how many unique ways the array's numbers can be added to match the "result."

### Key Concepts
- Recursion/Backtracking
- Dynamic Programming optimization

### Solution 1: Recursive Backtracking

**Algorithm:**
1. We define a function countUniqueWaysRecursive that takes the target result, the input array, the current currentIndex, and a reference to our count variable.
2. The function's **base cases** are crucial for stopping the recursion:

   * If target == 0, it means we've found a valid combination, so we increment count.
   * If target < 0 or currentIndex >= array.size(), it means we've overshot the target or run out of numbers, so we return.3. **Base Cases:**
     - If `currentSum == target`: increment counter
     - If `currentSum > target` or `currentIndex >= array.length`: invalid path
3. The recursive steps involve two main branches:

    * **Include**: We call the function recursively with target - array[currentIndex] and the same currentIndex. This is the key to allowing repeated use of the same number (e.g., 2 + 2 + 2 = 6).
    * **Exclude**: We call the function recursively with the same target but with currentIndex + 1. This moves to the next number in the array.
   
4. To handle uniqueness and avoid counting permutations as separate ways (e.g., 1+2 and 2+1), we sort the input array first. This ensures that we always process numbers in a consistent order.

**Complexity:**
- Time: O(2^N) worst case
- Space: O(N) for recursion stack + O(NumCombinations × N) for unique combinations

### Solution 2: Dynamic Programming

**Algorithm:**
1. Initialize DP array `dp[result + 1]` with `dp[0] = 1`
2. For each number num in input array:
    - Iterate from `j = result` down to `num`
    - Update `dp[j] = dp[j] + dp[j - num]`
3. Return `dp[result]`

**Complexity:**
- Time: O(N × Result)
- Space: O(Result)

---