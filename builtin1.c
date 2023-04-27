#include "shell.h"
/**
 * _myhistory - it displays the history of the list 1 command by line preceded
 * @info: the structure containing potential arguments.
 *  Return: 0 always
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - it sets alias to a string
 * @info: its a parameter struct
 * @str: it's the string alias
 * Return: 0 if successful or 1 if error
 */
int unset_alias(info_t *info, char *str)
{
	char *q, c;
	int r;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	c = *q;
	*q = 0;
	r = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = c;
	return (r);
}
/**
 * set_alias - it sets alias to a string
 * @info: it’s a parameter struct
 * @str: is a  string alias
 * Return: 0 if works or 1 if error
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = _strchr(str, '=');

	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - it prints an alias string
 * @node: it is the alias node
 * Return: Always 0 if works or 1 if error
 */
int print_alias(list_t *node)
{
	char *q = NULL, *a = NULL;

	if (node)
	{
		q = _strchr(node->str, '=');
		for (a = node->str; a <= q; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - it mimics the alias builtin, man alias
 * @info: it’s a structure containing potential arguments
 *  Return:  0
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *q = NULL;

	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		q = _strchr(info->argv[x], '=');
		if (q)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}
	return (0);
}
