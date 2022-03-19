#include<iostream>
using namespace std;

int sqrt (int num) {

    if (num < 2) {
        return num;
    }

    int start = 1;
    int end = num/2; 
    int ans = 1;

    while (start <= end) {

        double mid = (start + end) / 2;

        double sqr = mid * mid;

        if (sqr == num) {
            return mid;
        } 

        if (sqr < num) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int num;
    cin >> num;

    cout << sqrt(num) << endl;

    return 0;
}