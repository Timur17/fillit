#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	void *content;
	size_t  content_size;
	struct s_list *next; 
}t_list;

int main ()
{
//	t_list *me = {"Timur", 29};
	t_list *me;
	me = (t_list *)malloc(sizeof(t_list));
	me->content = (void *)malloc(sizeof(void) * 6);
//	me->content = memcpy(me->content, "Timur",6);
	me->content = "Timur";
	me->content_size = 29;
	printf("%s %ld\n", (char *)me->content, me->content_size); 

	me->next = (t_list *)malloc(sizeof(t_list));
	me->next->content = "Alla";
	me->next->content_size = 32;
	printf("%s %ld\n", (char *)me->next->content, me->next->content_size);
	t_list **p;
	me->next->next = (t_list *)malloc(sizeof(t_list));
	p = &me->next->next;
        me->next->next->content = "Alisa";
        me->next->next->content_size = 2;
	printf("%s %ld\n",(char *) (*p)->content, (*p)->content_size);
	char str[] = "1234567";
	char dest[5];
//	dest = (char *)malloc(sizeof(char) * 5);
	memcpy(dest, str, 3);
	printf("%s", dest);

}

