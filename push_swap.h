#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

# define LEFT 44
# define RIGHT -44

typedef struct s_stack
{
	int		value;
	void	*next;
}	t_stack;

typedef struct index_data
{
	int	size_a;
	int	*keys;
	int	chunks;
	int	key_index;
	int	chunksize;
	int	dir;
	int	r_count;
}	t_index;

typedef struct keys_dir
{
	int	right_count;
	int	left_count;
	int	right_value;
	int	left_value;
}	t_keysdir;

typedef void	(*t_fs)(t_stack **la);
typedef void	(*t_fp)(t_stack **la, t_stack **lb);
typedef void	(*t_fr)(t_stack **la);
typedef void	(*t_frev_r)(t_stack **la);
typedef void	(*t_frr)(t_stack **la, t_stack **lb);
typedef void	(*t_frrr)(t_stack **la, t_stack **lb);
typedef void	(*t_fss)(t_stack **la, t_stack **lb);

typedef struct s_flist
{
	t_fs		fs;
	t_fp		fp;
	t_fss		fss;
	t_fr		fr;
	t_frev_r	frev_r;
	t_frr		frr;
	t_frrr		frrr;
}	t_flist;

void		p(t_stack **la, t_stack **lb);
void		s(t_stack **la);
void		r(t_stack **la);
void		rev_r(t_stack **la);
void		ss(t_stack **la, t_stack **lb);
void		rr(t_stack **la, t_stack **lb);
void		rrr(t_stack **la, t_stack **lb);
void		parsing(int ac, char **av, t_stack **la, int **array);
void		ft_exit(t_stack **la, t_stack **lb,
				t_index **index_data, int **aray);
void		find_next_key_left(t_stack *a, int key, t_keysdir *keysdir);
void		find_next_key_right(t_stack *a,
				int key, t_keysdir *keysdir);
void		r_closest(t_stack **la, t_stack **lb,
				t_flist *f_list, t_keysdir *keysdir);
void		sort_3(t_stack **la, t_stack **lb, t_flist *f_list);
void		small_sort(t_stack **la, t_stack **lb, t_flist *f_list);
void		sort_2(t_stack **la, t_stack **lb, t_flist *f_list);
void		quicksort(int *array, int start, int end);
void		swap(int *array, int left, int right);
void		print_array(int *array, int size);
void		get_dir_and_count(t_stack *a, int value, t_index *index_data);
void		r_stack(t_stack **la, t_stack **lb,
				t_index *index_data, t_flist *f_list);
void		sort(t_stack **la, t_stack **lb,
				t_flist *f_list, t_index *index_data);
void		swap_if_lower(t_stack **la, t_stack **lb, t_flist *flist);
void		print_comp(t_stack **la, t_stack **lb, t_flist *flist, char *move);
t_stack		*create_node(int value);
t_stack		*destroy_chain(t_stack *head, int chain_size);
t_stack		*destroy_node(t_stack *head, int pos);
t_stack		*add_node(t_stack *list, int pos, int value);
t_stack		*get_at(t_stack *head, int pos);
t_stack		*get_last(t_stack *lst);
int			get_stacksize(t_stack *lst);
int			ft_sqrt(int nb);
int			find_highest_value(t_stack *la, int nb_elems);
int			is_sorted(t_stack *a);
int			check_str(char *str);
int			init(t_flist *f_list, t_index **index_data);
int			get_keys(int *array, t_stack *a, t_index *index_data);

#endif
