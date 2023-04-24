#ifndef MAIN_H
#define MAIN_H


#include <stdlib.h>

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_t 1024

/*structs*/

/**
 *struct cmdnode - a node for one command in a command list
 *@cmd: command string
 *@op: operation between current command and next command
 *@estat: exit status (shows if the command has been excuted or not)
 *@next: a pointer to the next operand
 */
typedef struct cmdnode
{
	char *cmd;
	char *op;
	int estat;
	struct cmdnode *next;
} cmdnode;

/**
 *struct alias - a node for one alias
 *@key: the alais
 *@value: value of the alias
 *@next: a pointer to the next alias
 */
typedef struct alias
{
	char *key;
	char *value;
	struct alias *next;
} alias;



void cmdmv(cmdnode **, int);
int xcmd(char **, int, alias **);



char *getfpath(char *);
void parseargs(char *, const char *, char ***, int);
int getinput(char **, size_t *, char ***, int);
void trims(char **, char *);



int *handlebin(char **, alias **);



void freedp(char **);
int arlen(char **);
void *smalloc(unsigned int);
void *srealloc(void *, unsigned int);



char **sarrdup(char **);
void printdp(char **);



int _getline(char **, size_t *, int);
int _strcmpd(char *, const char *);
char *_strtok(char *, const char *, int);
int _strcmps(char *, const char *);




int findd(char *, char *);
int fnrep(char **, char *, char *);



int _strlen(const char *);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strcmp(char *, char *);
char *_strcpy(char *, char *);


int _putenv(char *);
int _setenv(const char *, const char *, int);
int _unsetenv(const char *);
char *_getenv(const char *);
void _printenv(void);


int _chdir(char *);
int runscript(char *);
int execute(char **);


int strexpand(char **, int);


int add_alias(alias **, char *, char *);
int print_aliass(alias *);
int print_alias(alias *, char *);
int handle_alias(char **, alias **);
int freealias(alias *);

void aliasexpand(char **, alias *);


int remove_alias(alias **, char *);

int add_node(cmdnode **, char *, char *);
cmdnode *build_list(char *);
int print_cmdnodes(cmdnode *);
void free_cmdlist(cmdnode *);
cmdnode *add_nodein(cmdnode **, char *, char *, int);


char *itoa(int);
int _atoi(char *);

void phelp(char *arg);

int phistory(void);
int whistory(char *);

int _write(int, char *, int);

void perr(char *, int *, char *);

extern char **environ;


#endif
