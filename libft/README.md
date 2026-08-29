*This project has been created as part of the 42 curriculum by cebouhad*

# 🧑‍🏭 libft

## Description

Libft is a project aimed at recreating certain functions from the libc standard library, as well as additional utility functions.

It is a project that allows students to master the fundamentals of programming, covering memory manipulation, string handling, and data structures like linked lists.

Just as apprentices in manual trades would craft their own personalized toolboxes, Libft establishes the foundation of a toolkit that will be essential throughout the entire 42 curriculum.

## Instructions

To compile the library and generate the static library.

```bash
make
```
or

```bash
make libft
```
or

```bash
make all
```
To delete all object files
```bash
make clean
```

To delete all object files and the static library:
```bash
make fclean
```

To delete all object files, the static library and compile the library:
```bash
make re
```

## Resources

* https://linux.die.net/man/ 
* www.google.com
* https://www.geeksforgeeks.org
* https://www.gnu.org/software/make/manual
* https://stackoverflow.com



## detailed description of the library 

* **ft_memset**: The ft_memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
* **ft_bzero**: The ft_bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area.
* **ft_memcpy**: The ft_memcpy() function copies n bytes from memory area src to memory area dest.
* **ft_memmove**: The ft_memmove() function copies n bytes from memory area src to memory area dest.  The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.
* **ft_memchr**: The  ft_memchr() function scans the initial n bytes of the memory area pointed to by s for the first instance of c.  Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.
* **ft_memcmp**:  The  ft_memcmp() function returns an integer less than, equal to, or greater than zero if the first n bytes of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2.
* **ft_strlen**: The ft_strlen() function calculates the length of the string pointed to by s, excluding the terminating null byte ('\0')
* **ft_isalpha**: checks  for an alphabetic character.
* **ft_isdigit**: checks for a digit (0 through 9).
* **ft_isalnum**: checks for an alphanumeric character; it is equivalent to (isalpha(c) || isdigit(c)).
* **ft_isascii**: checks whether c is a 7-bit unsigned char value that fits into the ASCII character set.
* **ft_isprint**: checks for any printable character including space.
* **ft_toupper**: These functions convert lowercase letters to uppercase.
* **ft_tolower**: These functions convert uppercase letters to lowercase.
* **ft_strchr**: The ft_strchr() function returns a pointer to the first occurrence of the character c in the string s.
* **ft_strrchr**: The ft_strrchr() function returns a pointer to the last occurrence of the character c in the string s.
* **ft_strncmp**: The ft_strcmp()  function  compares  the two strings s1 and s2. The function compares only the first (at most) n bytes of s1 and s2.
* **ft_strlcpy**: The ft_strlcpy() function copies up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result.
* **ft_strlcat**
* **ft_strnstr**:The ft_strnstr() function locates the first occurrence of the null-terminated string little in the string big, where not more than len characters are searched. 
* **ft_atoi**: The ft_atoi() function converts the initial portion of the string pointed to by nptr to int.
* **ft_calloc**: The ft_calloc() function allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.
* **ft_strdup**:  The  strdup()  function returns a pointer to a new string which is a duplicate of the string s.  Memory for the new string is obtained with malloc, and can be freed with free.
* **ft_substr**: Allocates memory (using malloc(3)) and returns a substring from the string ’s’. The substring starts at index ’start’ and has a maximum length of ’len’
* **ft_strjoin**:Allocates memory (using malloc(3)) and returns a new string, which is the result of concatenating ’s1’ and ’s2’.
* **ft_strtrim**: Allocates memory (using malloc(3)) and returns a copy of ’s1’ with characters from ’set’ removed from the beginning and the end.
* **ft_split**: Allocates memory (using malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. Each string in the returned array is allocated independently. The array of pointers itself is also allocated dynamically. The returned array must be NULL terminated
* **ft_itoa**: Allocates memory (using malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled
* **ft_strmapi**: Applies the function ’f’ to each character of the string passed as argument, passing its index as the first argument. Each character is passed by
address to ’f’ so it can be modified if necessary.
* **ft_putchar_fd**: Outputs the character ’c’ to the specified file descriptor.
* **ft_putstr_fd**: Outputs the string ’s’ to the specified file descriptor.
* **ft_putendl_fd**: Outputs the string ’s’ to the specified file descriptor followed by a newline.
* **ft_putnbr_fd**: Outputs the integer ’n’ to the specified file descriptor.
* **ft_striteri**: Applies the function f to each character of the string s, passing its index as the first argument and the character itself as the second. A new
string is created (using malloc(3)) to store the results from the successive applications of f.
* **ft_lstnew**: Allocates memory (using malloc(3)) and returns a new node. The ’content’ member variable is initialized with the given parameter ’content’. The variable ’next’ is initialized to NULL.
* **ft_lstadd_front**: Adds the node ’new’ at the beginning of the list.
* **ft_lstsize**: Counts the number of nodes in the list.
* **ft_lstlast**: Returns the last node of the list.
* **ft_lstadd_back**: Adds the node ’new’ at the end of the list.
* **ft_lstdelone**: Takes a node as parameter and frees its content using the function ’del’. Free the node itself but does NOT free the next node
* **ft_lstclear**: Deletes and frees the given node and all its successors, using the function ’del’ and free(3). Finally, set the pointer to the list to NULL.
* **ft_lstiter**: Iterates through the list ’lst’ and applies the function ’f’ to the content of each node.
* **ft_lstmap**: Iterates through the list ’lst’, applies the function ’f’ to each node’s content, and creates a new list resulting of the successive applications
of the function ’f’. The ’del’ function is used to delete the content of a node if needed