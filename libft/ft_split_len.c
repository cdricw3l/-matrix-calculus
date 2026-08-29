#include "libft.h"

size_t	ft_split_len(char **split)
{
	size_t	len;

	if (!split)
		return (0);
	len = 0;
	while (split[len])
		len++;
	return (len);
}
