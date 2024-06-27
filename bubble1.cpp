#include <iostream>
#include <chrono> // Tambahkan header chrono

using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int n;

    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int arr[n];

    cout << "Masukkan elemen: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    auto start = chrono::high_resolution_clock::now();

    bubbleSort(arr, n);

    // Mengukur waktu eksekusi
    auto stop = chrono::high_resolution_clock::now();                          // Waktu mulai
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); // Waktu selesai

    cout << "Sorted list: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}
