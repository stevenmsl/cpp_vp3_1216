#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

using namespace sol1216;
using namespace std;

/*takeaways
  - check cpp_lps_516 for explanation on how to
    find the longest palindromic subsequence
*/

bool Solution::isValid(string &s, int k)
{
  const int n = s.size();
  /*
    - dp[i][j] stores the max length of the
      palindrome contains in s[i]..s[j]
  */
  auto dp = vector<vector<int>>(n, vector<int>(n, 0));
  for (auto i = n - 1; i >= 0; i--)
  {
    /*a char is a palindrome */
    dp[i][i] = 1;
    for (auto j = i + 1; j < n; j++)
    {
      if (s[i] == s[j])
        /* first char is s[i], and last char is s[j]
           - so the length is 1 + 1 + in-between [i+1..j-1]
        */
        dp[i][j] = dp[i + 1][j - 1] + 2;
      else
        /* look at the string that has one-less char,
           and record which one's palindromic length
           is longer
           - [i+1..j] or [i..j-1]
        */
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    }
  }

  auto maxLen = dp[0][n - 1];
  
  /*see if we can remove less than k chars so the leftover 
    string is a palindrome 
  */
  return n - maxLen <= k;
}