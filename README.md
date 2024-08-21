# Get Next Line
Get Next Line is a project developed as part of the 42 school curriculum. This project provides a function that reads a line from a file descriptor in C, one line at a time, regardless of the line's length. A unique aspect of this implementation is the use of a single static buffer to store any remaining data after each read, optimizing memory usage and performance. The function is also capable of handling multiple file descriptors simultaneously, each with its own buffer, allowing for efficient management of multiple input streams within a single program.

# Contents
# Core Functionality:

Reading lines from a file descriptor (get_next_line)
Using a static buffer to store unread data between calls
Handling varying line lengths
Managing multiple file descriptors with separate buffers
Memory and Buffer Management:

# Efficient use of memory with a static buffer
Managing dynamic memory allocation for line output
Ensuring minimal overhead and avoiding unnecessary reallocations
Objectives
This project deepens your understanding of file handling in C, strengthens skills in memory and buffer management, and lays a strong foundation for handling more complex input/output operations in future projects.

# Usage
To use this function in your projects, compile it along with your source files, and include the get_next_line.h header file. The get_next_line function can be integrated into any C program that requires line-by-line file reading, with efficient memory and buffer management, and support for multiple file descriptors.

![Screenshot from 2024-08-21 21-27-12](https://github.com/user-attachments/assets/22622306-f377-4977-baf4-e5e00b8422cf)
