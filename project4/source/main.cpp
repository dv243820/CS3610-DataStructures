#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// SWAP FUNCTION -- USED TO SWAP TWO INDEXES IN THE LIST
void swap(vector<int> &list, int first, int second)
{
  int tmp;
  tmp = list[first];
  list[first] = list[second];
  
  list[second] = tmp;
}

int partition(vector<int> &list, int first, int last)
{
  // The pivot should be the median of the
  // first, middle, and last elements.
  int pivot;
  int index, smallIndex;
  int fst, mid, lst;
  fst = list[first];
  mid = list[first - last];
  lst = list[last];
  // six possible cases for median
  if (fst < mid && mid < lst) // middle is median
  {
    swap(list, first, (first + last) / 2);
  }
  else if (fst < lst && lst < mid) // last is median
  {
    swap(list, first, last);
  }
  else if (lst < mid && mid < fst) // middle is median
  {
    swap(list, first, (first + last) / 2);
  }
  else if (lst < fst && fst < mid) // first is median
  {
    // do nothing lol no need to swap its already first
  }
  else if (mid < fst && fst < lst) // first is median
  {
    // same here
  }
  else if (mid < lst && lst < fst) // last is median
  {
    swap(list, first, last);
  }

  pivot = list[first]; // already swapped the pivot to first in list
  smallIndex = first;
  for (index = first + 1; index <= last; index++)
    if (list[index] < pivot) // if what ever is at that spot is less than pivot
    {
      smallIndex++;                  // increment smallIndex first
      swap(list, smallIndex, index);
    }
  swap(list, first, smallIndex);
  return smallIndex;
}

void quicksort(vector<int> &list, int first, int last)
{
  int pivotLoc;
  if (first < last)
  {
    pivotLoc = partition(list, first, last);
    quicksort(list, first, pivotLoc - 1); //left, first to -1
    quicksort(list, pivotLoc + 1, last); //right +1 to last
  }
}

void multiway_merge(vector<vector<int>> &input_lists, vector<int> &output_list)
{

  int numLists = input_lists.size();       // gets the number of sublists
  int numElements = input_lists[0].size(); // gets the amount of elements in the sublists

  priority_queue<int, vector<int>, greater<int>> minHeap; // minHeap

  for (int i = 0; i < numLists; i++)
  {
    for (int j = 0; j < numElements; j++)
    {
      minHeap.push(input_lists[i][j]);
    }
  }
  int counter = 0;       // COUNTER FOR THE OUTPUT LIST
  while (minHeap.size()) // while the minheap contains something
  {
    output_list[counter] = (minHeap.top());
    counter++; // increment counter
    minHeap.pop(); //now that we have accessed it, pop out
  }
}

int main(int argc, char **argv)
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> input_lists(n, vector<int>(m));

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      cin >> input_lists[i][j];
    }
  }

  // Quicksort k sublists
  for (int i = 0; i < input_lists.size(); ++i)
    quicksort(input_lists[i], 0, m - 1);

  // Merge n input sublists into one sorted list
  vector<int> output_list(n * m);

  multiway_merge(input_lists, output_list);

  for (int i = 0; i < output_list.size(); ++i)
    cout << output_list[i] << " ";
  cout << endl;

  return 1;
}
