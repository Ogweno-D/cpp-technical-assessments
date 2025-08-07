//
// Created by OG on __/08/202_.
//

#include <iostream>
#include <ostream>
using namespace std;
#include <vector>

int countUniqueSumWays(int result, const vector<int>&arr);
int main()
{

  int result = 0;
  int a=0;

  cout << "Enter the target sum: " <<endl;
  cin >> result;
  cout << "Enter the number of elements in the array: " << endl;
  cin >> a;

  vector<int> arr(a);
  cout << "Enter the elements of the array, separated by spaces:" << endl;
  for (int i = 0; i < a; i++)
  {
    cin >> arr[i];
  }

  int ways = countUniqueSumWays(result, arr);
  cout << "Number of unique ways to make sum " << result << " : " <<ways<< endl;

  /// The sample output
  // Enter the target sum:
  // 3
  // Enter the number of elements in the array:
  // 5
  // Enter the elements of the array, separated by spaces:
  // 1 3 4 2 5
  // Number of unique ways to make sum 3 : 3
}

/// Dynamic Programming Scenario
///
/// vector <int>dp is initialized to result+1 since the vector needs the indices from 0 to the result.
///
/// Hence,result+1
/// E,g if result = 4, the indices needed are {0,1,2,3,4}  which are 5;
int countUniqueSumWays(const int result, const vector<int>&arr)
{
  vector<int>dp(result+1,0); // result= 4, initial ways=0
  // To start off::
  // one way to form a sum of 0 (using no numbers)
  dp[0]=1; // 0 // dp[i] to store the number of unique ways to form the sum i

  for (const int num : arr) // loop through the array // arr[1] = 2
  {
    // update the dp array from current[i] upto the result.
    // if the condition == false then the number is skipped! {Amazing optimization, right?}
    for (int i = num; i <= result; i++) // i=2, 2<=4 = true
    {
      // Number of ways to make sum (i) is the sum of
      // existing ways plus the ways to make the sum (i-num)
      dp[i] += dp[i - num]; // dp[2] += dp[2-2] = dp[0] // since num(arr[1] =2) //
    }
  }
  return dp[result];
}

