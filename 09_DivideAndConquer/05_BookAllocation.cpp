# include <iostream>
# include <vector>

using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int curr_min)
{
    int studentUsed = 1;
    int pages_reading = 0;

    for (int i = 0; i < n; i ++)
    {
        /*  // not required here as our init of s is largest in array 
            if (arr[i] > curr_min)
                return false;
        */

       if (pages_reading + arr[i] > curr_min)
       {
            studentUsed++;
           
            pages_reading = arr[i];

            if(studentUsed > m)
                return false;
       }
       else
       {
           pages_reading += arr[i];
       }
    }
    return true;
}

int findPage(vector<int> &arr, int n, int m)
{
    int sum = 0;
    // if n < m = print - 1
    if (n < m)
    {
        return -1;
    }

    for (int i = 0; i < n; i ++)
        sum += arr[i];

    // count the no of pages
    int s = arr[n-1];
    int e = sum;
    int ans = INT_MAX;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main ()
{
    int n= 5, m= 4;
    vector <int> arr {1,2,3,1,1};

    cout << findPage(arr, n, m) << endl;

    return 0;
}