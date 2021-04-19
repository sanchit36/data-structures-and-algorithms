#include <bits/stdc++.h>
using namespace std;

class Job
{
public:
  int profit;
  int deadline;

  Job(int deadline, int profit)
  {
    this->deadline = deadline;
    this->profit = profit;
  }
};

bool comp(Job a, Job b)
{
  return (a.profit > b.profit);
}

int jobScheduling(Job arr[], int n)
{
  sort(arr, arr + n, comp);

  cout << "*********\n";
  for (int i = 0; i < n; i++)
  {
    cout << i + 1 << " Profit: " << arr[i].profit << " Deadline: " << arr[i].deadline << endl;
  }
  cout << "*********\n";

  int result[n];
  int slot[n] = {0};

  for (int i = 0; i < n; i++)
  {
    for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
    {
      if (slot[j] == 0)
      {
        result[j] = i;
        slot[j] = 1;
        break;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++)
    if (slot[i])
      sum += arr[result[i]].profit;

  return sum;
}

int main()
{
  Job arr[] = {{1, 80}, {4, 25}, {3, 15}, {1, 65}, {2, 30}};
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = jobScheduling(arr, n);
  cout << "Following is maximum profit sequence of jobs \n"
       << result;

  return 0;
}