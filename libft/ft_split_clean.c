#include "libft.h"

void	*ft_split_clean(char ***split)
{
	char	**ptr;

	if (!(*split))
		return (NULL);
	ptr = *split;
	while (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
		ptr++;
	}
	free(*split);
	return (NULL);
}
