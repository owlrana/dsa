/*
    --- Some more problems that we can solve by bits manipulation ---

    1.  Finding if the given number is even or odd
        ->  Every number is represented in it's binary form through 0s and 1s.
            If a number has it's FIRST PLACE from RIGHT ==> 1, then the number is odd
            This can be understood as every other power of 2 contributes an even number
            
            Eg.
                00001010 is even (10)
                00001011 is odd (11)
                00001000 is even (16)
                00001001 is odd (17)

            But how do you check if a given number is odd or even?
            ->  By doing & with 1.
            
            Eg. ( 5 & 1 ) ==> 1 MEANS ODD
                    5 = 00000101
                    1 = 00000001
                ==> 1 means ODD //  can also be said:
                                    if (5 & 1)
                                        cout << "Num is odd";
                                        
            Similarly, for even:
                ( 4 & 1 ) ==> 0 MEANS EVEN

    2.  Getting the ith bit of a number ( from the right side )
        ->  N = 5 ( 0000 0101 )
            i = 2 ( 7654 3210 ) // the 2nd bit from right is 1
            so what we do is, we do AND op on our num and a num that has 1 on ith place

            Eg.
                5   ( 0000 0101 )
                ?   ( 0000 0100 )
                AND ( 0000 0100 )
                If the number after this is > 0, means that the number has 1 in ith position..
                and if it comes out to be totally == 0, then it means there was 0 in ith place

                But, how do you create this number through which we can do AND op and find out?
                This mask can be created by taking 1 and shifting it left by i bits. (1 << i)
                So then we do (N & (1 << i))

    3.  Setting a particular ith bit as 1.
        ->  Eg. We need to set the 1st bit as 1 in 5.
            N = 5 ( 0000 0101 )
            i = ? ( 0000 0010 )
            OR op ( 0000 0111 )

            But how do you find this mask with which you need to do OR?
            Just take 1, left shift it to i places.

            So then we do (N | (1 << i))

    4.  Clear a bit at ith index.
        ->  Eg. We need to clear the 3rd bit of 5.
            N = 5 ( 0000 0101 )
            i = ? ( 1111 1011 )
            AND = ( 0000 0001 )

            But how do you made this mask which has all bits = 1 except at the ith position
            You take 1, shift it i places to the left, and the NEGATE it (flip all bits)

            So then we do (N & (~(1 << i)))

    5.  Update Bit
        ->  Eg. We need to update ith bit with the value that the user provides.
            So, first we need to clear the bit on ith place (make ith bit 0)
                Then create a new mask with user's choice (0 or 1)
                    Then we do cleared_n OR newMask
            Eg. 5 ( 0000 0101 )
                First we make sure, the 1st bit is cleared (is 0):
                ->( 0000 0101 )
                Need to make the 1st bit = 1, user enters: i = 1, v = 1;
                v << i
                ? ( 0000 00v0 ) => ( 0000 0010 )
                Now we do OR of cleared_n with this new user defined mask
                cleared_5 OR ? => ( 0000 0101 ) OR ( 0000 0010 )
                               => ( 0000 0111 )
                                    EXACTLY WHAT THE USER WANTED!

    6.  Clear last i bits
        ->  Eg. We need to clear last 3 bits of 5:
            5 ( 0000 0101 )
            =>( 0000 0000 )

            we need a mask of form ( 1111 1000 ) and then we do AND operation
            for this, we use -1 ( 1111 1111 ) and shift it i places 
            Eg -1 << 3 => ( 1111 1000 )
            AND with 5 => ( 0000 0000 )

    7.  Clear a range of bits
        ->  suppose we want to remove zeroes from 2 to 6 in a number: 1111 1111
            we need a mask like:
            N = ( 1111 1111 )
            ? = ( 1000 0011 )
            But how do we get a mask like this?
            We can get it by combining two masks as follows:
                1.a ( 1000 0000 ) ... can be achieved by j+1 shifting of ~0
                2.b ( 0000 0011 ) ... can be achieved by the number ((2^i) - 1)
                        Effect of ((2^i) - 1) [also equal to (1 << i) - 1]:
                            --> 1 << 2:
                                ( 0000 0100 ) 
                            --> 1 << 2 - 1:
                                ( 0000 0011 ) FINAL

                3. doing (a OR b): ( 1000 0011 ) ... IS THE ACHIEVED MASK!
            Then all we need to do is: (N AND Mask)

*/  

# include <iostream>

using namespace std;

// 1. To find if a number is odd or not
bool isOdd (int n)
{
    return (n & 1);
}

// 2. Get bit of a number on it's ith place
int getBit (int n, int i)
{
    int mask = ( 1 << i );

    // is (n & mask) greater than 0? if it is, then bit = 1, else bit = 0
    int bit = (n & mask) > 0? 1:0; 
    
    return bit;
}

// 3. Setting ith bit as 1
int setBit (int n, int i)
{
    int ret = (n | (1 << i));
    return ret;
}

// 4. Clear ith bit
int clearBit (int n, int i)
{
    int ret = (n & (~(1 << i)));
    return ret;
}

// 5. Update ith bit with v value
void updateBit (int &n, int i, int v)
{
    int mask = ~(1 << i);
    int cleared_n = n & mask;
    n = cleared_n | (v << i);   
    cout << n << endl;
}

// 6. Clear Last i bits
int clearLastIBits (int n, int i)
{
    int mask = (-1 << i);
    return ( n & mask );
}

// 7. Clear a range of bits
int clearRangeItoJ (int n, int i, int j)
{
    int ones = ~0;
    int a = ones << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    return (mask & n);
}

int main ()
{
    // 1. Find out if a number is odd or not
    cout << "-- FINDING ODD OR EVE --" << endl;
    int a = 5;
    cout << isOdd(a) << endl;
    cout << isOdd(a+1) << endl;

    // 2. Get bit of a number at ith place
    cout << "-- GETTING BIT --" << endl;
    int b = 5;
    cout << getBit(b, 0) << endl;
    cout << getBit(b, 1) << endl;

    // 3. Set the ith bit of a number 1s
    cout << "-- SETTING BIT --" << endl;
    int c = 5;
    cout << setBit(c, 1) << endl;
    cout << setBit(c, 3) << endl;

    // 4. Clearing ith bit of a number
    cout << "-- CLEARING BIT --" << endl;
    int d = 5;
    cout << clearBit(d, 2) << endl;
    cout << clearBit(d, 0) << endl;

    // 5. Updating ith position by vth bit
    cout << "-- UPDATING BIT --" << endl;
    int e = 5;
    updateBit(e, 1, 1);
    updateBit(e, 1, 0);

    // 6. Clear last i bits
    cout << "-- CLEAR LAST i BITS --" << endl;
    int f = 5;
    cout << clearLastIBits(f, 3) << endl;
    cout << clearLastIBits(f, 1) << endl;
    
    // 7. Clearing a range of bits from i to j
    cout << "-- CLEAR RANGE i TO j --" << endl;
    int g = 31;
    cout << clearRangeItoJ(g, 1, 3) << endl;
    cout << clearRangeItoJ(g, 1, 2) << endl;
    
}