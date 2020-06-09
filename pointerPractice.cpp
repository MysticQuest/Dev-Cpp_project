#include <iostream>

using namespace std;

int main()
{
    const size_t arr1Size{5};
    const size_t arr2Size{3};

    int array1[]{1, 2, 3, 4, 5};
    int array2[]{10, 20, 30};

    void Print(const int *const array, size_t size);
    int *ApplyAll(const int *const arr1, size_t size1, const int *const arr2, size_t size2);

    cout << "\nArray 1: ";
    Print(array1, arr1Size);

    cout << "\nArray 2: ";
    Print(array2, arr2Size);

    int *result = ApplyAll(array1, arr1Size, array2, arr2Size);
    const size_t result_size = (arr1Size * arr2Size);

    cout << "\nResult: ";
    Print(result, result_size);

    delete[] result;

    int x;
    cin >> x;
}

void Print(const int *const array, size_t size)
{
    cout << "{ ";
    for (size_t i{}; i < size; i++)
    {
        cout << *(array + i) << " ";
    }
    cout << "}";
}

int *ApplyAll(const int *const arr1, size_t size1, const int *const arr2, size_t size2)
{
    int *newArray{};
    newArray = new int[size1 * size2];
    int position{0};

    for (size_t i{0}; i < size2; i++)
    {
        for (size_t j{0}; j < size1; j++)
        {
            newArray[position] = *(arr2 + i) * *(arr1 + j);
            ++position;
        }
    }
    return newArray;
}