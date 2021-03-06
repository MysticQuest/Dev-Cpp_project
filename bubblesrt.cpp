#include <iostream>
#include <vector>
#include <typeinfo>
#include <limits>

using namespace std;

//Prototypes
void DisplayMenu();
char GetInput();
void ClearInput();
void PrintNumbers(const vector<int> &numbers);
vector<int> AddNumber(vector<int> &numbers);
void DisplayMean(const vector<int> &numbers);
void DisplaySmallest(const vector<int> &numbers);
void DisplayLargest(const vector<int> &numbers);
void BubbleSort(vector<int> &numbers);
void BubbleSortPointers(vector<int> &numbers);

int main()
{
    vector<int> nums{283, 7, 56, 2536, 13, 49, 368, 856, 423, 124, 3, 1, 55, 23, 62, 0};
    char input;

    do
    {
        DisplayMenu();
        input = GetInput();

        switch (input)
        {
        case 'P':
        case 'p':
            PrintNumbers(nums);
            break;
        case 'A':
        case 'a':
        {
            AddNumber(nums);
            break;
        }
        case 'M':
        case 'm':
            DisplayMean(nums);
            break;

        case 'S':
        case 's':
            DisplaySmallest(nums);
            break;

        case 'L':
        case 'l':
            DisplayLargest(nums);
            break;

        case 'X':
        case 'x':
            BubbleSort(nums);
            break;

        case 'Z':
        case 'z':
            BubbleSortPointers(nums);
            break;

        default:
            cout << "   Please enter a valid character\n\n";
            break;
        }
    } while (input != 'q' && input != 'Q');
}

void DisplayMenu()
{
    cout << "   P - Print Numbers\n"
         << "   A - Add a Number\n"
         << "   M - Display Mean of the Numbers\n"
         << "   S - Display the Smallest Number\n"
         << "   L - Display the Largest Number\n"
         << "   X - Bubble Sort and print\n"
         << "   Z - Bubble Sort w/ pointers and print\n"
         << "   Q - Quit\n"
         << endl;
}

char GetInput()
{
    cout << "   ";
    char x;
    cin >> x;
    cout << "\n";
    return x;
}

void ClearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void PrintNumbers(const vector<int> &numbers)
{
    cout << "   List Numbers\n\n";
    if (numbers.size() > 0)
    {
        cout << "   { ";
        for (auto num : numbers)
        {
            cout << num << " ";
        }
        cout << "}\n\n";
    }
    else
    {
        cout << "   The list is empty\n\n";
    }
}

vector<int> AddNumber(vector<int> &numbers)
{
    int numberToAdd;
    do
    {
        cout << "   Please enter an integer: ";
        cin >> numberToAdd;
        if (!cin)
        {
            cout << "   This is not an integer!\n\n";
            ClearInput();
            break;
        }
        else
        {
            numbers.push_back(numberToAdd);
            cout << "   " << numberToAdd << " was added to the list!\n\n";
        }
    } while (1);
    return numbers;
}

void DisplayMean(const vector<int> &numbers)
{
    int sum{0};
    double avg{0};

    cout << "   List average:\n\n";
    if (numbers.size() > 0)
    {
        cout << "   The average is ";
        for (auto num : numbers)
        {
            sum += num;
            avg = static_cast<double>(sum) / numbers.size();
        }
        cout << avg << "\n\n";
    }
    else
    {
        cout << "   The list is empty\n\n";
    }
}

void DisplaySmallest(const vector<int> &numbers)
{
    int min{0};

    if (numbers.size() > 0)
    {
        cout << "   The smallest number is ";
        min = numbers.at(0);
        for (auto num : numbers)
        {
            if (num < min)
            {
                min = num;
            }
        }
        cout << min << "\n\n";
    }
    else
    {
        cout << "   The list is empty\n\n";
    }
}

void DisplayLargest(const vector<int> &numbers)
{
    int max{0};

    if (numbers.size() > 0)
    {
        cout << "   The largest number is ";
        max = numbers.at(0);
        for (auto num : numbers)
        {
            if (num > max)
            {
                max = num;
            }
        }
        cout << max << "\n\n";
    }
    else
    {
        cout << "   The list is empty\n\n";
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(vector<int> &numbers)
{
    int i, j;
    for (i = 0; i < numbers.size() - 1; i++)
    {
        for (j = 0; j < numbers.size() - i - 1; j++)
        {

            if (numbers[j] > numbers[j + 1])
            {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
    PrintNumbers(numbers);
}

void BubbleSortPointers(vector<int> &numbers)
{
    int *arr = &numbers[0];
    int *arrBytes = arr + numbers.size() - 1;
    int iteration;
    for (iteration = 0; iteration < numbers.size() - 1; iteration++)
    {
        arr = arr - numbers.size();
        while (arr < arrBytes)
        {
            if (*arr > *(arr + 1))
            {
                int temp = *arr;
                *arr = *(arr + 1);
                *(arr + 1) = temp;
            }
            arr++;
        }
    }

    PrintNumbers(numbers);
}
