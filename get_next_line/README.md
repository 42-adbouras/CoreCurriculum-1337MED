## Grade

<img src="https://cdn.discordapp.com/attachments/714092571655274496/1199403568243945533/Screen_Shot_2024-01-23_at_6.21.08_PM.png?ex=65e7549e&is=65d4df9e&hm=e3f43b2dcece5bc015103444d7911940f6504002426564129bd4b99d90d48a7e&" width=200px height=175px/>

## I - Mandatory Part

The purpose of the function get_next_line() is to read a line from a file descriptor and return it. The function reads the file line by line, which means that each call to get_next_line returns the next line in the file.
Here's a step-by-step explanation of how the code works:
- get_next_line is the main function. It takes a file descriptor `fd` as input. It has a static variable `line` which retains its value between function calls. This is used to keep track of the remaining part of the file to be read. 
- `ft_read` is called to read from the file descriptor `fd` into line. It reads up to `BUFFER_SIZE` characters at a time. If it encounters a newline character ('\n'), it stops reading. If an error occurs during reading, it frees `cup` and `line` and returns `NULL`. 
- If `line` is `NULL` or an empty string after the call to `ft_read`, get_next_line frees `line` and returns `NULL`. 
- `ft_substr_ft` is called to get the substring of `line` up to and including the first newline character. This is the line to be returned by get_next_line. 
- ft_save_static is called to get the remaining part of line after the first newline character. This is saved in line for the next call to get_next_line. 
- get_next_line returns the line read from the file. 
- `ft_substr_ft` and `ft_save_static` both allocate memory for the strings they return. It's the responsibility of the caller to free this memory when it's no longer needed. 
- If any of the memory allocations fail, the functions return `NULL`. 
This is a high-level overview of how the code works. The details of how each function works can be found in their respective definitions.

## II - Bonus Part

Basicly the same workflow the only defference is that get_next_line(), it has a static char array `line` of size 10240 (number of file descriptors you can open in one proscess). This array is used to store lines read from different file descriptors.

### Notice

⚠️ There is some minor mistakes but it still works! never gonna forget the evaluation for this project 🤦‍♂️
  - I let you find em!
