#include<iostream>
using namespace std;
void display(int arr[],int n)
{
  cout<<"Array elements:";
for(inti=0;i<n;i++)
{
cout<<arr[i]<<" ";
}cout<<endl;
}
int main()
{int arr[100],n,choice,pos,value,ket;

cout<<"Enter number of elements:";
cin>>n;
cout<<"Enter array elements:";
for(inti=0;i<n;i++)
{
cin>>arr[i];
}
do
    {
        cout << "\n--- Array Operations ---\n";
        cout << "1. Traversal\n";
        cout << "2. Insertion\n";
        cout << "3. Deletion\n";
        cout << "4. Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Traversal
            display(arr, n);
            break;

        case 2:
            // Insertion
            cout << "Enter position (1 to " << n + 1 << "): ";
            cin >> pos;

            cout << "Enter value: ";
            cin >> value;
            if (pos < 1 || pos > n + 1)
            {
                cout << "Invalid position!\n";
            }
            else
            {
                for (int i = n; i >= pos; i--)
                {
                    arr[i] = arr[i - 1];
                }

                arr[pos - 1] = value;
                n++;

                cout << "Element inserted successfully.\n";
                display(arr, n);
            }
            break;

        case 3:
            // Deletion
            cout << "Enter position to delete (1 to " << n << "): ";
            cin >> pos;

            if (pos < 1 || pos > n)
            {
                cout << "Invalid position!\n";
            }
            else
            {
                for (int i = pos - 1; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }

                n--;

                cout << "Element deleted successfully.\n";
                display(arr, n);
            }
            break;

        case 4:
            // Search
            cout << "Enter element to search: ";
            cin >> key;

            {
                int found = 0;

                for (int i = 0; i < n; i++)
                {
                    if (arr[i] == key)
                    {
                        cout << "Element found at position "
                             << i + 1 << endl;
                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Element not found.\n";
                }
            }
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
