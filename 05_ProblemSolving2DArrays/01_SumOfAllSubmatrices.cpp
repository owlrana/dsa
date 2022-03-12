# include <iostream>
using namespace std;

int sumOfSubmatrix(int **arr, int n, int m) {

    int sum = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int tl = (i+1)*(j+1); // top left choices that may have this particular index
            int br = (n-i)*(m-j); // bottom right choices that may have this particular index
            sum += (tl * br) * arr[i][j]; // computing the contribution this particular cell has in sum
        }
    }
    return sum;
}

int main ()
{
    int n, m;
    cin >> n >> m;
    int **arr = new int*[n];
    for (int i = 0; i < n; i ++) {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j ++) {
            cin >> arr[i][j];
        }
    }

    cout << sumOfSubmatrix(arr, n, m) << endl;

    return 0;
}