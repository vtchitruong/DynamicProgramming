Determine if it is possible to make string a equal to string b.  
Two following operations can be performed:  
1. Capitalize zero or more of string a's lowercase letters.
2. Delete all of the remaining lowercase letters in string a.  

Return YES or NO.

### Constraints
1 <= n <= 10 (number of queries)  
1 <= |a|, |b| <= 1000 (size of strings)  

### Sample Input
1  
daBcd  
ABC  

### Sample Output
YES  

### Explanation
daBcd -> daBc -> daBC -> dABC -> ABC => YES  

Another case:  
a = AbcDE  
b = AFDE  
=> return NO due to letter F.  

### Source
The problem can be found at [Hackerrank](https://www.hackerrank.com/challenges/abbr/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming).





