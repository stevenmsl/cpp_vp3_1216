#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1216;

/*
Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.
*/
tuple<string, int, bool>
testFixture1()
{
  return make_tuple("abcdeca", 2, true);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::isValid(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  return 0;
}