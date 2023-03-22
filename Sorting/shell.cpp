#include <iostream>
using namespace std;

// Best	O(nlog n)
// Worst	O(n2)
// Average	O(nlog n)

void shellSort(int array[], int n) {
  
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      
      array[j] = temp;
    }
  }

}


// Driver code
int main() {
  int arr[] = {9, 8, 3, 7, 5, 6, 4, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  shellSort(arr, size);
  cout << "Sorted array: \n";
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
}