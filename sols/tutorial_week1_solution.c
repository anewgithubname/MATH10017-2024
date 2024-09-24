//I am a comment
/*
    I am a multi-line 
    comment
*/

//The code below is a preprocessing command.
//It will be executed before compilation
#include <stdio.h>

//The code below is a function, contains a list of instructions
// to be compiled and run on the CPU. 
int main()
{
    //below are statements, they will be executed sequentially.
    printf("My name is Song Liu. \n");
    printf("I am from China. \n");
    printf("My student ID is sl9885. \n");
    printf("My favourite food is fried chicken. \n");


    printf("My Student ID %s.\n", "sl9885");
    printf("My Student ID %s%d.\n", "sl", 9885);
    printf("The outcome of 1/3 is %.3f\n", 1.0/3.0);
    // this does not work, why?
    //printf("The outcome of 1/3 is %.3f", 1/3);
    printf("This is a happy face😀.\n");


    printf("|\\\n");
    printf("| \\\n");
    printf("|  \\\n");
    printf("|   \\\n");
    printf("|____\\\n");

    //the following statement returns a value from this function.
    //Here, it returns "0", means all OK with your program. 
    //If needded, you can return a non-zero value which means something is wrong. 
    return 0;
}

/*
To compile, press ctrl+' to bring out the command line. 

Type ine the command line gcc THIS_FILE_NAME -o EXECUTABLE_FILE_NAME 
(on Windows, the file name must end with .exe)
Press enter. 

To run, 
Type in the command line ./EXECUTABLE_FILE_NAME 
press enter. 

*/