// A Simple Program To Demonstarte How To Use Arrays In C++
// Time Complexity To Access Any Element Of An Array => O(n)
#include<iostream>
using namespace std;

int main() {
    int n; // specifies size of array
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n]; // array of size n
    cout << "Enter elements of array: " << endl;
    cout << endl;
    
    for(int i = 0; i < n; i++) {   // loop over elements of array
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Elements of array are: ";
    for(int i = 0; i < n; i++) {   // loop over elements of array
        cout << arr[i] << " ";
    }
}
