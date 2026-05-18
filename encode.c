#include <stdio.h>
#include "encode.h"
#include "types.h"

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

uint get_file_size(FILE *fptr)
{
    // Find the size of secret file data
}

/*
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */

Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    //step1 -> check source file name having .bmp present or not
            // no -> return e_failure
            // yes -> store source file name into encInfo->src_image_fname
    //step2 -> check secret file having extn or not
            // no -> return e_failure
            // yes -> store secret file name into encInfo->src_image_fname
    // step3 -> check optional file is passed or not
            // yes -> check the file having .bmp or not
                    // no -> return e_failure
                    // yes -> store the file name into encInfo->stego_image_fname
            // no -> store default name to encInfo->stego_image_fname = "stego.bmp";
    //step4 -> return e_success
}

Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

        return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

        return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

        return e_failure;
    }

    // No failure return e_success
    return e_success;
}

Status check_capacity(EncodeInfo *encInfo)
{
    // step1 -> encInfo->image_capacity =get_image_size_for_bmp(source_file_pointer)
    
    // step2 -> find secret file size encInfo -> size_secret_file = get_file_size(secret file pointer)

    // step3 -> compare encInfo->image_capacity > 16 + 32 + 32 + 32 + 54 + (encInfo -> size_secret_file * 8)
            // yes -> return e_success
            // no -> return e_failure
}

Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    //step1 -> rewind file pointer 0th pos

    //step2 -> read 54 bytes from source file(use fread)

    //step3 -> write the 54 bytes to stego image file(from buffer)

    // return e_success

}
Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    //step1 ->  read 8 bytes of buffer from source image
    
    //step2 -> call encode_bytes_to_lsb(magic_string[0], buffer)

    //step3 -> store the buffer to stego image file
            // do this upto magic string size time (step1)

    // return e_success;
}
Status encode_secret_file_extn_size(int size, EncodeInfo *encInfo)
{
    //step1 -> read 32 bytes of buffer from source image

    //step2 -> call encode_size_to_lsb(size, buffer)

    //step3 -> store the buffer to stego image file

    // return e_success.
}

Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo)
{
    //step1 -> read 8 bytes of buffer from source image file

    //step2 -> call encode_byte_to_lsb(file_extn[0], buffer)

    //step3 -> store the buffer into stego image file
            // repeat this upto size of extn size

    // return e_success
}

Status encode_secret_file_size(long file_size, EncodeInfo *encInfo)
{   
    //step1 -> read 32 bytes of buffer from source image

    //step2 -> call encode_size_to_lsb(file_size, buffer)

    //step3 -> store the buffer to stego image file

    // return e_success.
}

Status encode_secret_file_data(EncodeInfo *encInfo)
{
    //step1 -> read the secret data into one data_buffer

    //step2 -> read 8 bytes of buffer from source image file

    //step3 -> call encode_byte_to_lsb(data_buffer[0], buffer)

    //step4 -> store the buffer into stego image file
            // repeat this upto size of secret file(step2)

    // return e_success.
}

Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{
    // run a loop upto reaching EOF
    // read buffer from source image file
    // store into stego image file.
    

    // return e_success.
}

Status encode_byte_to_lsb(char data, char *image_buffer)
{
   // logic to encode the data.
}

Status encode_size_to_lsb(int size, char *imageBuffer)
{
    //logic to encode the size.
}

Status do_encoding(EncodeInfo *encInfo)
{
    //step1 -> call open file(encInfo)
            // e_failure -> print error msg and return e_failure
            // e_success -> print success msg goto next step

    // step2 -> call check_capacity(encInfo)
            // e_failure -> print error msg and return e_failure
            // e_success -> print success msg goto next step

    // step3 -> call copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_stego_image);
            // print success msg and goto next step

    // step4 -> call encode_magic_string(MAGIC_STRING,encInfo)
            // print success msg and goto next step

    // step5 -> call encode_secret_file_extn_size(strlen(encInfo -> extn_secret_file), encInfo)
            // print success msg and goto next step

    // step6 -> call encode_secret_file_extn(encInfo -> extn_secret_file, encInfo)
            // print success msg and goto next step

    //step7 -> call encode_secret_file_size(encInfo -> size_secret_file, encInfo)
            // print success msg and goto next step
    
    //step8 -> call encode_secret_file_data(encInfo)
            // print success msg and goto next step

    //step9 -> call copy_remaining_img_data(pass two file pointers)
            // print success msg and goto next step

    //step10 -> return e_seccess.
}
