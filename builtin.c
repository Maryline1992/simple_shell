#include "shell.h"
/**
 * _myexit - it exits in the shell
 * @info: the structure containing has a potential arguments
 * Return: exits with given exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int excheck;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		excheck = _erratoi(info->argv[1]);
		if (excheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mycd - it changes a current directory of the process
 * @info: its a structure containing potential arguments.
 * Return: 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int cd

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			cd = /* TODO: what should this be? */
				cd((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			cd = cd(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		cd = /* TODO: what should this be? */
			cdi((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		cd = cd(info->argv[1]);
	if (cd == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _myhelp - it change the current directory of the process
 * @info: it’s a structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
