#include <iostream>
#include <vector>

using std::vector;

void shellSort(vector<int>& arr, int n) {

    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2) {

        // Do a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap stored
        for (int i = gap; i < n; i += 1) {

            // add arr[i] to the elements that have been gap sorted
            // save arr[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            

            // put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

int main() {
    vector<int> arr = {7, 6, 8, 9, 3, 2, 10, 5, 1};
    int n = arr.size();

    shellSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}