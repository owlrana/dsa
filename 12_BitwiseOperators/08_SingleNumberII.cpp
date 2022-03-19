// https://leetcode.com/problems/single-number-ii/

# include <iostream>
# include <vector>

using namespace std;

int main ()
{
    vector<int> nums {1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6};
    int n = nums.size();

    // to store where the bits are in multiples of 3: 
    // bit positions stored in cnt as: [0][1][2][3][4] ...
    // so it is easier to make the number from units, tenths, hundredths, etc.
    vector<int> cnt (64, 0);
    for (int i = 0; i < n; i ++)
    {
        // updating cnt array by extracting bits
        int j = 0;
        while (nums[i] > 0)
        {
            int last_bit = (nums[i] & 1);
            cnt[j] += last_bit;
            j += 1;
            nums[i] = nums[i] >> 1;
        }
    }
/*
    for (auto x: cnt)
        cout << x << ", ";
    cout << endl;
*/
    // iterate over the array and reduce everything by mod 3
    // then convertin 0 and 1 into a number
    int p = 1; // initial value of 2^0 
    int ans = 0;
    for (int i = 0; i < 64; i ++) // as max bit size we thought was 64
    {
        cnt[i] = cnt[i] % 3;
        ans = ans + (cnt[i]*p);
        p = p << 1;
        // could have also done :
        // p = p*2;
    }

    cout << ans << endl;

    return 0;
}