#include "libft.h"

void	ft_split_display(char **split, int fd)
{
	char	**ptr;

	if (!split)
		return ;
	ptr = split;
	while (*ptr)
	{
		ft_putendl_fd(*ptr, fd);
		ptr++;
	}
}
