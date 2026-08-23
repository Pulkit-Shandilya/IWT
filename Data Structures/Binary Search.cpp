#include <iostream>
using namespace std;

int main(){
    int x, y;
    int arr[100];
    cout << "Enter a number: ";
    cin >> x;
    cout << "You entered: " << x << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "Enter number for the array: ";
        cin >> y;
        arr[i] = y;
    }
    
}

int binary_search(int arr[], int n, int key){
    auto sarr = sort(arr, n);


}

// template <size_t N>
// int arr_len(int (&arr)[N]){
//     return static_cast<int>(N);
// }

// template <size_t N>
// int arr_len(int (&)[N]) {
//     return N;
// }

auto sort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
    
        while (j >=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
    return arr;
}