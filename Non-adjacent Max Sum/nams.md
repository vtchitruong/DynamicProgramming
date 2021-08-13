Find the maximum sum of the subset of non-adjacent elements with the maximum sum.
The subset with more than 1 element is valid.
The maximum sum is 0 in case all elements are negative.

### Constraints
1 <= n <= 10^5  
-10^4 <= a[i] <= 10^4

### Sample Input
5  
-2 1 3 -4 5

### Sample Output
8

### Explanation
| Subsets | Sum |
| --- | --- |
| [-2 3 5] | 8 |
| [-2 3] | 1 |
| [-2 -4] | -6 |
| [-2 5] | 3 |
| [1 -4] | -3 |
| [1 5] | 6 |
| [3 5] | 8 |

### Source
The problem can be found on [Hackerrank](https://www.hackerrank.com/challenges/max-array-sum/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dynamic-programming).
