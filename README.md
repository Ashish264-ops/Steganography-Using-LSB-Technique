# Steganography Using LSB Technique

## Description
Steganography using the Least Significant Bit (LSB) technique is a method of hiding secret information inside an image without visibly changing the image quality. The secret message is embedded into the least significant bits of image pixels, making the hidden data difficult to detect.

This project is implemented using the C programming language and demonstrates concepts like file handling, bitwise operations, and image processing.

---

## Features
- Encode secret message into an image
- Decode hidden message from image
- Supports BMP image format
- Maintains original image quality
- Secure data hiding technique

---

## Technologies Used
- C Programming
- File Handling
- Bitwise Operations
- Image Processing

---

## Project Structure
```text
.
├── encode.c
├── decode.c
├── common.h
├── encode.h
├── decode.h
├── main.c
└── README.md
```

---

## How LSB Technique Works

Original Byte:
```text
10110110
```

After Encoding:
```text
10110111
```

Only the least significant bit changes, so the image difference is not visible to the human eye.

---

## How to Compile
```bash
gcc *.c
```

---

## How to Run

### Encoding
```bash
./a.out -e input.bmp secret.txt output.bmp
```

### Decoding
```bash
./a.out -d output.bmp decoded.txt
```

---

## Applications
- Secure Communication
- Digital Watermarking
- Data Protection
- Information Hiding

---

## Concepts Used
- Steganography
- Least Significant Bit (LSB)
- Bit Manipulation
- File Processing

---

## Author
Ashish Singh
