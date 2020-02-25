#include "libft.h"
#include "vector.h"

static t_memory		**mem_list(void)
{
	static t_memory	*memory = NULL;

	return (&memory);
}

void				ft_free_all(void)
{
	t_memory	**memory;
	t_memory	*temp;

	memory = mem_list();
	while (*memory)
	{
		temp = (*memory)->next;
		free(*memory);
		*memory = temp;
	}
}

void				ft_my_free(void *ptr)
{
	t_memory	**memory;
	t_memory	*temp;
	t_memory	*iter;

	memory = mem_list();
	iter = *memory;
	if ((*memory)->ptr == ptr)
	{
		(*memory) = (*memory)->next;
		free(iter);
	}
	else
	{
		while (iter->next && iter->next->ptr != ptr)
			iter = iter->next;
		if (!iter->next)
			ft_error(
		"Cannot find the pointer that must be freed among the allocated memory",
				0);
		temp = iter->next->next;
		free(iter->next);
		iter->next = temp;
	}
}

static void			*ft_memadd(size_t size)
{
	t_memory	**memory;
	t_memory	*new_ptr;

	memory = mem_list();
	new_ptr = (t_memory*)malloc(sizeof(t_memory) + size);
	if (!new_ptr)
		ft_error("Can't allocate the memory", 0);
	new_ptr->ptr = (void*)((char*)new_ptr + sizeof(t_memory));
	new_ptr->next = *memory;
	*memory = new_ptr;
	return (new_ptr->ptr);
}

void				*ft_malloc(size_t size)
{
	return (ft_memadd(size));
}
