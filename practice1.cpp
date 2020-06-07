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
void DisplayMean(vector<int> &numbers);
void DisplaySmallest(vector<int> &numbers);
void DisplayLargest(vector<int> &numbers);

int main()
{
    vector<int> nums;
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

void DisplayMean(vector<int> &numbers)
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

void DisplaySmallest(vector<int> &numbers)
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

void DisplayLargest(vector<int> &numbers)
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
