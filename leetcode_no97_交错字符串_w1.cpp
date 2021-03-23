/* ------------------------------------------------------------------|
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
提示：a + b 意味着字符串 a 和 b 连接。

 

示例 1：


输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true
示例 2：

输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出：false
示例 3：

输入：s1 = "", s2 = "", s3 = ""
输出：true
 

提示：

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1、s2、和 s3 都由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/interleaving-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	动态规划法
*   时间复杂度O(mn)
*   空间复杂度O(n)
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6.1 MB, 在所有 C++ 提交中击败了91.50%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isInterleave(string s1, string s2, string s3) {
    int l1 = s1.size();
    int l2 = s2.size();
    int l3 = s3.size();

    if (!l1 && !l2 && !l3) {
        return true;
    }
    if (!l1) {
        return s2 == s3;
    }
    if (!l2) {
        return s1 == s3;
    }
    if (l3 - l2 - l1) {
        return false;
    }

    vector<bool> f(l2 + 1, 0);
    f[0] = 1;
    for (int i = 0; i <= l1; ++i) {
        for (int j = 0; j <= l2; ++j) {
            int k = i + j - 1;
            //因为是按行更新的，到了第i行只会对j进行操作，而第i行的状态仅和i-1行有关
            //因此f[i][j] = f[i-1][j] && s1[i-1] == s3[k] || f[i][j]
            //又因为f[i][j]之前有没来过，因此是0，所以f[i][j]只取决于前面的判断
            //即f[i][j] = f[i-1][j] && s1[i-1] == s3[k]
            //并且从二维缩到一维，当前f[j]就代表了i-1时候的f[j]
            //因此直接操作f[j]即可
            if (i > 0) {
                f[j] = f[j] && (s1[i - 1] == s3[k]);
            }
            if (j > 0) {
                f[j] = f[j] || (f[j - 1] && (s2[j - 1] == s3[k]));
            }
        }
    }
    return f[l2];
    //vector<vector<bool>> f(l1 + 1, vector<bool>(l2 + 1, 0));
    //f[0][0] = 1;
    //for (int i = 0; i <= l1; ++i) {
    //    for (int j = 0; j <= l2; ++j) {
    //        int k = i + j - 1;
    //        if (i > 0) {
    //            f[i][j] = f[i][j] || (f[i - 1][j] && (s1[i - 1] == s3[k]));
    //        }
    //        if (j > 0 ) {
    //            f[i][j] = f[i][j] || (f[i][j - 1] && (s2[j - 1] == s3[k]));
    //        }
    //    }
    //}
    //return f[l1][l2];
}

int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    bool flag = isInterleave(s1, s2, s3);
    cout << flag;
}