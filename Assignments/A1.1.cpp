#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {

  int n;

  printf("Input n: ");
  if (scanf("%d", &n) != 1 || n <= 0) return 1;

  std::vector<int> arr(n);

  printf("\n(input array must be taken from 0 to n)\n\nInput Array: ");

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int max = arr[0];

  // max value

  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  printf("\nmax = %d\n", max);

  std::vector<int> arr3;

  // sorting

  std::sort(arr.begin(), arr.end());

  printf("\nsorted: \n");

  for (int i = 0; i < n; i++) {
    printf("%d\n", arr[i]);
  }

  // Find missing elements from 0 to max
  int curr = 0;
  for (int val : arr) {
    while (curr < val) {
      arr3.push_back(curr);
      curr++;
    }
    if (curr == val) {
      curr++;
    }
  }
  while (curr <= max) {
    arr3.push_back(curr);
    curr++;
  }

  printf("\nMissing elements:\n");

  for (size_t i = 0; i < arr3.size(); i++) {
    printf("%d\n", arr3[i]);
  }

  return 0;
}
