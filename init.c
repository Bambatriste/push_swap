#include "push_swap.h"

int	get_keys(int *array, t_stack *a, t_index *index_data)
{
	int	i;
	int	key_index;

	index_data->size_a = get_stacksize(a);
	quicksort(array, 0, index_data->size_a);
	index_data->chunks = ft_sqrt(get_stacksize(a) / 2);
	i = 0;
	key_index = -1;
	index_data->chunksize = index_data->size_a / (index_data->chunks + 1);
	index_data->keys = malloc(sizeof(int) * index_data->chunks);
	if (index_data->keys == NULL)
		return (0);
	while (i < index_data->chunks)
	{
		key_index += index_data->chunksize;
		index_data->keys[i] = array[key_index];
		i++;
	}
	free(array);
	return (1);
}

int	init(t_flist *f_list, t_index **index_data)
{
	f_list->fs = &s;
	f_list->fp = &p;
	f_list->fss = &ss;
	f_list->fr = &r;
	f_list->frev_r = &rev_r;
	f_list->frr = &rr;
	f_list->frrr = &rrr;
	*index_data = malloc(sizeof(t_index));
	if (!*index_data)
		return (0);
	return (1);
}
