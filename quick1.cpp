#include <iostream>
#include <chrono> // Tambahkan header chrono

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pindex = partition(arr, low, high);
        quickSort(arr, low, pindex - 1);
        quickSort(arr, pindex + 1, high);
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
    quickSort(arr, 0, n - 1);
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
