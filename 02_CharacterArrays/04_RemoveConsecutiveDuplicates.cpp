// "cccooooodddiing" should become "coding"

# include <iostream>
# include <cstring>
using namespace std;


void removeDuplicates (char a[]) {

    int length = strlen(a);
    if (length == 1) {
        return;
    }

    int prev = 0;
    for (int current = 1; current < length; current++) { // keep moving until not matched.
        // when not matched, store the next place of prev with the char and move (repeat)
        if (a[current] != a[prev]) {
            prev ++;
            a[prev] = a[current];
        }
    }
 
    a[prev + 1] = '\0';
    return;

}

int main()
{
    char str[100] = "rrraaaahuuuul!!";

    cout << str << endl;

    removeDuplicates(str);

    cout << str << endl;    

    return 0;
}