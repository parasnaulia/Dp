function climbStairsWithMemo(n, memo = []) {
      if (n <= 2) {
          return n;
      }
  
      if (memo[n]) {
          return memo[n];
      }
  
      memo[n] = climbStairsWithMemo(n - 1, memo) + climbStairsWithMemo(n - 2, memo);
  
      return memo[n];
  }
  
  // Example usage
  const n = 5;
  console.log(`Number of distinct ways to climb ${n} steps: ${climbStairsWithMemo(n)}`);
  