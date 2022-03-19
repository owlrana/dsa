/*
    --- PROPERTIES OF THE MODULO OPERATOR (%) ---
    Mod is usually used to decrease the size of a number for computations etc.

    1.  (a + b) % m = ((a % m) + (b % m)) % m

    2.  (a - b) % m = ((a % m) - (b % m) + m) % m
        Why are we adding m in this?
        eg. (8 - 3) % 7 should be = 5
            but in above formula, without doing +m, we will get: -2
            So to get a positive value, we add m to it, and it becomes +ve: 5

    3.  (a * b) % m = ((a % m) * (b % m)) % m

    4.  (a / b) % m = ((a % m) * ((b^-1) % m)) % m
        b^-1 (b inverse) is also called multiplicative modulo inverse
        Eg. We know that 6 % 7 is equal to 1.
            suppose (6*y) % 7 is also equal to 1.
            So we need to find for what value of y will this be true.
            To solve such a question, we will have to find the modulo inverse of 6 wrt 7
            (in this case it came out to be 6, as 6*6 = 36, and 36 % 7 = 1)

    -- these properties will be useful in CRT questions that we do later on --
*/