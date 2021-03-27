### LeetCode_No.97_-交错字符串
* 题目描述


给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。\
两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：\
s = s1 + s2 + ... + sn\
t = t1 + t2 + ... + tm\
|n - m| <= 1\
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...\
提示：a + b 意味着字符串 a 和 b 连接.。\
* 示例 1：

      输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
      输出：true
* 示例 2：

      输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
      输出：false
* 示例 3：

      输入：s1 = "", s2 = "", s3 = ""
      输出：true
 

* 提示：

      0 <= s1.length, s2.length <= 100
      0 <= s3.length <= 200
      s1、s2、和 s3 都由小写英文字母组成

### 解法思路
* 动态规划法
* f[i][j] = f[i+1][j-1] && (s[i] == s[j])

  * 时间复杂度O(mn)
  * 空间复杂度O(mn)

执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户\
内存消耗：6.1 MB, 在所有 C++ 提交中击败了91.50%的用户

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/interleaving-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
