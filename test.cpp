#include <iostream>
#include <vector>
#include <typeinfo>
#include <limits>

using namespace std;

int main()
{
    vector<int> nums;
    char input;
    int sum{0};
    double avg{0};
    int min{0};
    int max{0};

    do
    {
        cout << "   P - Print Numbers\n"
             << "   A - Add a Number\n"
             << "   M - Display Mean of the Numbers\n"
             << "   S - Display the Smallest Number\n"
             << "   L - Display the Largest Number\n"
             << "   Q - Quit\n"
             << endl;

        cout << "   ";
        cin >> input;
        cout << "\n";

        switch (input)
        {
        case 'P':
        case 'p':
            cout << "   List Numbers\n\n";
            if (nums.size() > 0)
            {
                cout << "   { ";
                for (auto num : nums)
                {
                    cout << num << " ";
                }
                cout << "}\n\n";
            }
            else
            {
                cout << "   The list is empty\n\n";
            }
            break;

        case 'A':
        case 'a':
        {
            int numberToAdd;
            do
            {
                cout << "   Please enter an integer: ";
                cin >> numberToAdd;
                if (!cin)
                {
                    cout << "   This is not an integer!\n\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                else
                {
                    nums.push_back(numberToAdd);
                    cout << "   " << numberToAdd << " was added to the list!\n\n";
                }
            } while (1);
            break;
        }
        case 'M':
        case 'm':
            cout << "   List average:\n\n";
            if (nums.size() > 0)
            {
                cout << "   The average is ";
                for (auto num : nums)
                {
                    sum += num;
                    avg = static_cast<double>(sum) / nums.size();
                }
                cout << avg << "\n\n";
            }
            else
            {
                cout << "   The list is empty\n\n";
            }
            break;

        case 'S':
        case 's':
            if (nums.size() > 0)
            {
                cout << "   The smallest number is ";
                min = nums.at(0);
                for (auto num : nums)
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
            break;

        case 'L':
        case 'l':
            if (nums.size() > 0)
            {
                cout << "   The largest number is ";
                max = nums.at(0);
                for (auto num : nums)
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
            break;

        default:
            cout << "   Please enter a valid character\n\n";
            break;
        }
    } while (input != 'q' && input != 'Q');
}
