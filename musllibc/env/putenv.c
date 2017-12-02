#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

extern char **environ;
char **__env_map;

int __putenv(char *s, int a)
{
	int i=0, j=0;
	char *end = strchr(s, '=');
	size_t l = end-s+1;
	char **newenv = 0;
	char **newmap = 0;
	static char **oldenv;
	
	if (!end || l == 1) return -1;
	for (; environ[i] && memcmp(s, environ[i], l); i++);
	if (a) {
		if (!__env_map) {
			__env_map = calloc(2, sizeof(char *));
			if (__env_map) __env_map[0] = s;
		} else {
			for (; __env_map[j] && __env_map[j] != environ[i]; j++);
			if (!__env_map[j]) {
				newmap = realloc(__env_map, sizeof(char *)*(j+2));
				if (newmap) {
					__env_map = newmap;
					__env_map[j] = s;
					__env_map[j+1] = NULL;
				}
			} else {
				free(__env_map[j]);
			}
		}
	}
	if (!environ[i]) {
		newenv = malloc(sizeof(char *)*(i+2));
		if (!newenv) {
			if (a && __env_map) __env_map[j] = 0;
			return -1;
		}
		memcpy(newenv, environ, sizeof(char *)*i);
		newenv[i] = s;
		newenv[i+1] = 0;
		environ = newenv;
		free(oldenv);
		oldenv = environ;
	}

	environ[i] = s;
	return 0;
}

int putenv(char *s)
{
	return __putenv(s, 0);
}
