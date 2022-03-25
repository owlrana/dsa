/*
    Some special functions that C++ Classes give you when you create a new class/object.
    Here are 4 different special functions that are always present when you create a class:
        1.  Constructor
        2.  Copy Constructor
        3.  Copy Assignment Operator
        4.  Destructor

    1.1 Constructor
        -   Special function responsible for creating an object
        -   gets called automatically and ONLY ONCE
        -   to override, you need to create a function with SAME NAME and NO RETURN TYPE
            Eg. class Rana
                {
                    private:
                        // some variables that you will require in this class
                        // this is the INITIALISATION SECTION

                    public:
    1.2                 // this is the constructor and it will be called each time you create object of this class
                        Rana ()
                        {
                            // this is where you can initiliase this class constructor's variables
                            // this is the INITIALISATION SECTION
                        }
                        
                        // you can also have multiple constructors to fit your needs
                        Rana (int aNumber)
                        {
                            int number = aNumber;
                            // this is a Parameterised Constructor
                            // this is also INITIALISATION SECTION
                        }
                }

    When you have same function with DIFFERENT NAMES, it is called FUNCTION OVERLOADING.
    Here, you just saw an example of CONSTRUCTOR OVERLOADING.

*/