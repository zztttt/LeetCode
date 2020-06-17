Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:
```
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```
Example 2:
```
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
```
Example 3:
```
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
```

```
input: abcd  dict:[ab, cd]
dp[5]: 1 0 0 0 0
dp[i]表示 s[0:i-1]子串是否满足条件。
判断dp[j]==true是因为取的子串是s[j:i-1]
for(i: 1~4)
    for(j: 0~i-1)
        tmp=substr(j, i-j)// s[j:i-1]
        // dp[j]看s[0:j-1] 是否满足，再看s[j:i-1]是否存在于dict
        if(dp[j] && found) 
            dp[i]=true //表示s[0:i-1]符合条件
1.  i = 1, j = 0, tmp=a,  dp:10000
2.  i = 2, j = 0, tmp=ab, dp:10100
3.  i = 2, j = 1, tmp=b
4.  i = 3, j = 0, tmp=abc
5.  i = 3, j = 1, tmp=bc 
6.  i = 3, j = 2, tmp=c
7.  i = 4, j = 0, tmp=abcd
8.  i = 4, j = 1, tmp=bcd
9.  i = 4, j = 2, tmp=cd, dp:10101 finish

```