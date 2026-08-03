/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 12:11:58 by masilva-          #+#    #+#             */
/*   Updated: 2026/02/27 12:11:58 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"

// content: The data contained in the node.
// next: The address of the next node, 
// or NULL if the current node is the last one.
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*   PART 1   */

/* new */
int		ft_isupper(int c);
int		ft_islower(int c);

/* ft_islower() || ft_isupper */
int		ft_isalpha(int c);

/* checks for a digit (0 through 9). */
int		ft_isdigit(int c);

/* (isalpha(c) || isdigit(c)). */
int		ft_isalnum(int c);

/* checks if c is a 7-bit US-ASCII character code (0 <= c <= 127) */
int		ft_isascii(int c);

/* checks if c is printable (32 <= c <= 126) */
int		ft_isprint(int c);

/* calculate the length of a string */
size_t	ft_strlen(const char *s);

/* fill memory with a constant byte, returns a pointer to the memory area s */
void	*ft_memset(void *s, int c, size_t n);

/* erases the data in the n bytes of the memory starting at the */
/* location pointed to by s, by writing zeros to that area */
void	ft_bzero(void *s, size_t n);

/* copy memory area */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/* copies n bytes from memory area src to memory area dest.  */
/* the memory areas may overlap: copies bytes from src -> temporary -> dest */
void	*ft_memmove(void *dest, const void *src, size_t n);

/* copies up to size - 1 characters */
/* from the true C string src to dst, NUL-terminating the result */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* Appends the NUL-terminated string src to the end of dst. */
/* It will append at most size - strlen(dst) - 1 bytes, with Nul term */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* convert lowercase letters to uppercase, and vice versa */
/* libc <ctype.h> */
int		ft_toupper(int c);
int		ft_tolower(int c);

/* returns a pointer to the first occurrence of the character in the string s */
/* returns NULL if the char is not found */
/* The '\0' byte is considered part of the string, so that if c is  */
/* specified as '\0', these functions return a pointer to the terminator */
char	*ft_strchr(const char *s, int c);

/* returns a pointer to the last occurrence of the char c in the string s */
char	*ft_strrchr(const char *s, int c);

/* compares two strs, returns an int indicating the result of the comparison */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* scans the initial n bytes of the memory area pointed to by s. */
/* for the first instance of c. Both c and the bytes of the memory area 
pointed to by s are interpreted as unsigned char */
void	*ft_memchr(const void *s, int c, size_t n);

/* compares the first n bytes (each interpreted as unsigned char)
of the memory areas s1 and s2 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* locates the first occurrence of the '\0' string little in the string big, 
where not more than len characters are searched */
/* Characters  that  appear after a ‘\0’ character are not searched */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* converts a string to an integer, skips isspace() and takes one sign. */
/* returns the int correspondant to the initial portion of the string, 
0 upon error - man strtol */
int		ft_atoi(const char *str);

/* returns a pointer to (nmemb * size) bytes allocated */
/* calloc(0) should return freeable ptr */
/* if malloc error or nmemb * size > SIZE_MAX, return NULL */
void	*ft_calloc(size_t nmemb, size_t size);

/* duplicates a string, returning a pointer to dup */
/* Memory for the new string is obtained with malloc(3), 
and can be freed with free(3) */
char	*ft_strdup(const char *s);

/*   PART 2   */
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*   PART 3   */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif