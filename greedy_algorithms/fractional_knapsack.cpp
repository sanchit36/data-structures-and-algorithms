#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
  double value, weight;
  Item(double value, double weight)
  {
    this->value = value;
    this->weight = weight;
  }
};

bool comp(Item a, Item b)
{
  double r1 = a.value / a.weight;
  double r2 = b.value / b.weight;
  return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
  sort(arr, arr + n, comp);

  int curWeight = 0;
  double finalvalue = 0;

  for (int i = 0; i < n; i++)
  {
    if (curWeight + arr[i].weight <= W)
    {
      curWeight += arr[i].weight;
      finalvalue += arr[i].value;
    }
    else
    {
      double remain = W - curWeight;
      finalvalue += arr[i].value * (remain / arr[i].weight);
      break;
    }
  }

  return finalvalue;
}

int main()
{
  int W = 15;
  Item arr[] = {Item(10, 2), Item(5, 3), Item(15, 5), Item(7, 7), Item(6, 1), Item(18, 4), Item(3, 1)};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Maximum value we can obtain = " << endl
       << fractionalKnapsack(W, arr, n);

  return 0;
}