#include <iostream>
#include <chrono> // Tambahkan header chrono

using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    // Mengukur waktu eksekusi
    auto start = chrono::high_resolution_clock::now(); // Waktu mulai
    insertionSort(arr, n);
    auto end = chrono::high_resolution_clock::now(); // Waktu selesai
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Elemen setelah diurutkan secara ascend: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}
