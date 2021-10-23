A sequence is special if it consists of a positive number of 0s, followed by a positive number of 1s, then a positive number of 2s.  
For example, [0,1,2] and [0,0,1,1,1,2] are special.  
In contrast, [2,1,0], [1], and [0,1,2,0] are not special.  
  
Given an array nums (consisting of only integers 0, 1, and 2), return the number of different subsequences that are special. Since the answer may be very large, return it modulo 10^9 + 7.  
  
A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements. Two subsequences are different if the set of indices chosen are different.  



### Constraints
1 <= nums.length <= 10^5  
0 <= nums[i] <= 2  

### Input 1
0 1 2 2  

### Output 1
3  

### Explanation 1
0 1 2 (first 2)  
0 1 2 (second 2)  
0 1 2 2 (both 2)  

### Input 2
0 1 2 0 1 2  

### Output 2
7  

### Explanation 2
0 1 2 (first 2)  
0 1 2 (second 2)  
0 1 2 2 (both 2)  
0 1 1 2 (both 1)  
0 0 1 2  
0 1 2 (first 0, second 1, second 2)  
0 1 2 (second 0, second 1, second 2)  

### Source
The problem can be found on [LeetCode](https://leetcode.com/problems/count-number-of-special-subsequences/).  