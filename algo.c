#include "filler.h"

int			**init_map(t_info *info)
{
	int		**map;
	int		i;

	map = malloc(sizeof(int *) * info->size_y);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < info->size_y)
	{
		map[i] = malloc(sizeof(int) * info->size_x);
		if (map[i] == NULL)
			return (NULL);
		i++;
	}
	return (map);
}

int		make_heatmap(int **map)
{
	
}

