## Grade

<img src="https://cdn.discordapp.com/attachments/714092571655274496/1199403568243945533/Screen_Shot_2024-01-23_at_6.21.08_PM.png?ex=65e7549e&is=65d4df9e&hm=e3f43b2dcece5bc015103444d7911940f6504002426564129bd4b99d90d48a7e&" width=200px height=175px/>

## I - Mandatory Part

**I.1 Libc functions:**
You must write your own function implementing the following original ones. They do not require any external functions. Exept ft_calloc & ft_strdup, in order to implement the two functions, you will use malloc().

| function | description |
|--|--|
|[ft_isascii](ft_isascii.c)|tests if a given character, in the current locale, can be represented as a valid 7–bit US-ASCII character.        
|[ft_isprint](ft_isprint.c)         |checks whether a character is a printable character or not.            
|[ft_isalpha](ft_isalpha.c)        |checks if the passed character is alphabetic.
|[ft_isdigit](ft_isdigit.c)        |checks if the passed character is a decimal digit character.
|[ft_isalnum](ft_isalnum.c)        |checks if the passed character is alphanumeric.
|[ft_tolower](ft_tolower.c)        |converts a given letter to lowercase.
|[ft_toupper](ft_toupper.c)        |converts a given letter to uppercase.
|[ft_strlen](ft_strlen.c)        |computes the length of the string str up to, but not including the terminating null character.
|[ft_strchr](ft_strchr.c)        |searches for first occurrence of _c_ in the string _*str_.
|[ft_strrchr](ft_strrchr.c)        |searches for the last occurrence of the character _c_ (an unsigned char) in the string pointed to, by the argument _str_.
|[ft_strnstr](ft_strnstr.c)        |locates the first occurrence of the null-terminated string pointed by _little_ in string pointed by _big_. Characters that appear after a _'\0'_ or _len_ are not searched.
|[ft_strncmp](ft_strncmp.c)        |compares at most the first _n_ bytes of _str1_ and _str2_.
|[ft_strlcpy](ft_strlcpy.c)        |copies up to _size - 1_ characters from the NUL-terminated string _src_ to _dest_, NUL-terminating the result.
|[ft_strlcat](ft_strlcat.c)       |appends the NUL-terminated string _src_ to the end of _dest_. It will append at most _size - strlen(dst) - 1 bytes_, NUL-terminating the result.
|[ft_strdup](ft_strdup.c)        |returns a pointer to a new string duplicated of the string _s_. Memory for the new string is obtained with malloc.
|[ft_atoi](ft_atoi.c)        |converts the initial portion of the string pointed to by _str_ to int.
|[ft_memset](ft_memset.c)       |fills memory with a constant byte.
|[ft_bzero](ft_bzero.c)        |copies _n_ bytes, each with a value of zero, into string _s_.
|[ft_memcpy](ft_memcpy.c)        |copies _n_ bytes from memory area _src_ to memory area _dest_. The memory areas must not overlap. Use **ft_memmove** if the memory areas do overlap.
|[ft_memmove](ft_memmove.c)        |copies _n_ bytes from memory area _src_ to memory area _dest_ and will not be corrupted if memory areas do overlap.
|[ft_memchr](ft_memchr.c)        |Searches within the first _n_ bytes of the block of memory pointed by _str_ for the first occurrence of _c_ (interpreted as an unsigned char), and returns a pointer to it.
|[ft_memcmp](ft_memcmp.c)       |compares _n_ byte string s1 against _n_ byte string s2.
|[ft_calloc](ft_calloc.c)        |allocates _size_ bytes and returns a pointer to the allocated memory. The memory is not initialized.

**I.2 Additional functions**
In this second part, you must develop a set of functions that are either not in the libc, or that are part of it but in a different form.

| function | description |
|--|--|
|[ft_substr](ft_substr.c) | allocates (with malloc) and returns a substring from the string _s_. The substring begins at index _start_ and is of maximum size _len_. |
|[ft_strjoin](ft_strjoin.c) | allocates (with malloc) and returns a new string, which is the result of the concatenation of _s1_ and _s2_.
|[ft_strtrim](ft_strtrim.c) | allocates (with malloc) and returns a copy of _s1_ with the characters specified in _set_ removed from the beginning and the end of the string
|[ft_split](ft_split.c)| allocates (with malloc) and returns an array of strings obtained by splitting _s_ using the character _c_ as a delimiter. The array must beended by a NULL pointer.
|[ft_itoa](ft_itoa.c)| allocates (with malloc) and returns a string representing the integer received as an argument. Negative numbers must be handled.
|[ft_strmapi](ft_strmapi.c)| applies the function _f_ to each character of the string _s_ to create a new string (with malloc) resulting from successive applications of _f_.
|[ft_striteri](ft_striteri.c)| applies the function _f_ to each character of the string passed as argument, and passing its index as first argument. Each character is passed by address to f to be modified if necessary.
|[ft_putchar_fd](ft_putchar_fd.c)| outputs the character _c_ to the given file descriptor.
|[ft_putstr_fd](ft_putstr_fd.c)| outputs the string _s_ to the given file descriptor.
|[ft_putendl_fd](ft_putendl_fd.c)| outputs the string _s_ to the given file descriptor, followed by a newline.
|[ft_putnbr_fd](ft_putnbr_fd.c)| outputs the integer _n_ to the given file descriptor.

## II - Bonus Part
Functions to manipulate memory and strings is very useful. But you will soon discover that manipulating lists is even more useful.

| function | description |
|--|--|
|[ft_lstnew](ft_lstnew_bonus.c)    |Allocates (with malloc(3)) and returns a new node. The member variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.
|[ft_lstadd_front](ft_lstadd_front_bonus.c)    |Adds the node ’new’ at the beginning of the list.
|[ft_lstsize](ft_lstsize_bonus.c)    |Counts the number of nodes in a list.
|[ft_lstlast](ft_lstlast_bonus.c)    |Returns the last node of the list.
|[ft_lstadd_back](ft_lstadd_back_bonus.c)|Adds the node ’new’ at the end of the list.
|[ft_lstdelone](ft_lstdelone_bonus.c)    |Takes as a parameter a node and frees the memory of the node’s content using the function ’del’ given as a parameter and free the node. The memory of ’next’ must not be freed.
|[ft_lstclear](ft_lstclear_bonus.c)    |Deletes and frees the given node and every successor of that node, using the function ’del’ and free(3). Finally, the pointer to the list must be set to NULL.
|[ft_lstiter](ft_lstiter_bonus.c)    |Iterates the list ’lst’ and applies the function ’f’ on the content of each node.
|[ft_lstmap](ft_lstmap_bonus.c)    |Iterates the list ’lst’ and applies the function ’f’ on the content of each node. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of a node if needed.
