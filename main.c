#include <stdio.h>
#include "encode.h"
#include "types.h"

OperationType check_operation_type(char *);

int main(int argc, char *argv[])
{
    //step1 -> check_operation_type(argv[1])

    //step2 -> check the return value == e_encode
            // declare structure variable EncodeInfo encInfo
            // read_and_validate_encode_args(pass command line arg, &encInfo) == e_success or e_failure
            // e_failure -> print error msg and stop the program
            // e_success -> next step.
        // call do_encoding(&encInfo);
            //e_failure -> print error msg and stop the program
            //e_success -> print success msg and stop the program 

    //step3 -> return value == e_decode
            // --
    //step3 -> return value == e_unsupported
            // --> print invalid arg
            // -e -> encode
            // -d  -> decode
}

OperationType check_operation_type(char *symbol)
{
    //step1 -> check it is -e or -d 
    // if it is -e return e_encode
    // else if it is -d rteun e_decode
    // else return e_unsuported
}
