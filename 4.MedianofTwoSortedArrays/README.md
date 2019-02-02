There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example：
```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

Solution: recursive approach
If we understand the use of median for dividing, we are very close to the answer.

First let's cut A into two parts at a random position i:

          left_A             |        right_A
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
Since **A** has mm elements, so there are **m+1** kinds of cutting (i = 0∼m).  
And we know:
```
len(left_A)=i,len(right_A)=m−i.

Note: when i = 0, left_A is empty, and when i = m,right_A is empty.
```
With the same way, cut **B** into two parts at a random position j:

          left_B             |        right_B
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]

put left_A and left_B into one set, and put right_A and right_B into another set. Let's name them left_part and right_part:    

          left_part          |        right_part
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]

if we can ensure:
```
    1.len(left_part)=len(right_part)
    2.max(left_part)≤min(right_part)
```
then we divide all elements in **{A, B}** into two parts with equal length, and one part is always greater than the other. Then
```
median = (max(left_part)+min(right_part))/2
```
To ensure these two conditions, we just need to ensure:
```
    1.i+j=m−i+n−j (or: m - i + n - j + 1)
      if n>=m, we just need to set: i = 0 ~ m, j = (m+n+1)/2 - i
    2.B[j-1]<=A[i] and A[i-1]<=B[j]
```
So all we need to do is:
```
searching i in [0,m], to find an object i such that:
B[j-1]<=A[i] and A[i-1]<=B[j], where j = (m+n+1)/2 - i
```
And we can do a binary search following steps described below:
1.  set imin = 0, imax = m, then start searching in][imin, imax]
2.  set i = (imin+imax)/2, j = (m+n+1)/2 - i
3.  Now we have len(left_part) = len(right_part), and there are only 3 situations that we may encounter:  
    *   B[j-1]<=A[i] and A[i-1]<=B[j], means we have found the object i, so stop searching
    *   B[j-1]>A[i], means A[i] is too small, We must adjust i to get B[j-1]<=A[i]  
    can we increase i?  
        Yes, because when i is increased, j will be decreased.  
        So B[j-1] is decreased and A[i] is increased, and B[j-1]<=A[i] may be satisfied.
    cam we decrease i ?  
    No! because when i is decreased, j will be increased.
    So B[j-1] is increased and A[i] is decreased, and B[j-1]<=A[i] will never satisfied.  
    So, set imin = i+1, and goto 2
    *   A[i-1]>B[j], means A[i-1] is too big. And we must decrease i to get A[i-1]<=B[j].  
    so set imax = i - 1, and goto 2  

When the object i is found, the median is
```
max(A[i-1], B[j-1]), when m+n is odd

[max(A[i-1], B[j-1])+min(A[i], B[j])]/2, when m+n is even
``` 

Let's consider the edges values...FUCK, SKIP IT

## Reference
[LeetCode Solution](https://leetcode.com/problems/median-of-two-sorted-arrays/solution/)