#include <iostream>
#include <chrono> // Tambahkan header chrono

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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
    selectionSort(arr, n);
    auto end = chrono::high_resolution_clock::now(); // Waktu selesai
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Elemen setelah diurutkan secara ascend: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Waktu eksekusi: " << duration.count() << " mikrodetik" << endl;

    return 0;
}
