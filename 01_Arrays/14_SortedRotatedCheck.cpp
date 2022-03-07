#include<iostream>
#include<vector>
using namespace std;

void check (vector<int> arr, int size, int mini, int maxi) {

    int sorted = 0;

    if (mini < maxi) {
        
        // 0 -> mini
        for (int i = 1; i <= mini; i ++) {
            if (arr[i-1] <= arr[i]) {
                sorted = -1;
            }
        }

        //mini -> end
        for (int i = maxi+1; i < size; i ++) {
            if (arr[i-1] <= arr[i]) {
                sorted = -1;
            }
        }

        // if starting element is greater than last, it means it is not rotated
        if (arr[0] >= arr[size-1]) {
            sorted = -1;
        }

    } else {

        // 0 -> maxi
        for (int i = 1; i <= maxi; i ++) {
            if (arr[i-1] >= arr[i]) {
                sorted = -1;
            }
        }

        //maxi -> end
        for (int i = mini+1; i < size; i ++) {
            if (arr[i-1] >= arr[i]) {
                sorted = -1;
            }
        }

        // if starting element is greater than last, it means it is not rotated
        if (arr[0] <= arr[size-1]) {
            sorted = -1;
        }

    }

    if (sorted == -1) {
        cout << "Nope." << endl;
    } else {
        cout << "SORTED & ROTATED!" << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the size of rotated array: ";    
    cin >> n;
    
    vector<int> arr (n);
    int mini = 0, maxi = 0;

    for (int i = 0; i < n; i ++) {
        cin >> arr[i];

        if (arr[i] < arr[mini]) {
            mini = i;
        }

        if (arr[i] > arr[maxi]) {
            maxi = i;
        }
    }

    if (abs(maxi - mini) != 1) {
        cout << "Nope.";
    } else {
        check(arr, n, mini, maxi);
    }
    
    return 0;
}