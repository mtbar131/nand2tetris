#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#define MAX_SYMBOL_LEN 64
#define MAX_LINE_LEN 512

typedef struct symbol {
    char str[MAX_SYMBOL_LEN];
    int address;
} symbol;

typedef struct s_table {
    symbol *head;
    int size;
    int capacity;
} s_table;

char* readline(int fd) {
    char* buf = (char*) malloc (MAX_LINE_LEN);
    int i = 0;
    int ch;
    while ((ch = read(fd, &buf[i], 1)) > 0 &&
	   buf[i] != '\n') i++;
    buf[i] = 0;
    if (ch <= 0)
	return NULL;
    return buf;
}

s_table* init_s_table() {
    s_table *tab = (s_table*) malloc (sizeof(s_table));
    tab->capacity = 100;
    tab->head = (symbol*) malloc (tab->capacity * sizeof(symbol));
    symbol *entry = tab->head;
    
    // Pre-defined symbols
    strcpy(entry[0].str, "R0");
    entry[0].address = 0;
    strcpy(entry[1].str, "R1");
    entry[1].address = 1;
    strcpy(entry[2].str, "R2");
    entry[2].address = 2;
    strcpy(entry[3].str, "R3");
    entry[3].address = 3;
    strcpy(entry[4].str, "R4");
    entry[4].address = 4;
    strcpy(entry[5].str, "R5");
    entry[5].address = 5;
    strcpy(entry[6].str, "R6");
    entry[6].address = 6;
    strcpy(entry[7].str, "R7");
    entry[7].address = 7;
    strcpy(entry[8].str, "R8");
    entry[8].address = 8;
    strcpy(entry[9].str, "R9");
    entry[9].address = 9;
    strcpy(entry[10].str, "R10");
    entry[10].address = 10;
    strcpy(entry[11].str, "R11");
    entry[11].address = 11;
    strcpy(entry[12].str, "R12");
    entry[12].address = 12;
    strcpy(entry[13].str, "R13");
    entry[13].address = 13;
    strcpy(entry[14].str, "R14");
    entry[14].address = 14;
    strcpy(entry[15].str, "R15");
    entry[15].address = 15;
    strcpy(entry[16].str, "SP");
    entry[16].address = 0;
    strcpy(entry[17].str, "LCL");
    entry[17].address = 1;
    strcpy(entry[18].str, "ARG");
    entry[18].address = 2;
    strcpy(entry[19].str, "THIS");
    entry[19].address = 3;
    strcpy(entry[20].str, "THAT");
    entry[20].address = 4;
    strcpy(entry[21].str, "SCREEN");
    entry[21].address = 16384;
    strcpy(entry[22].str, "KBD");
    entry[22].address = 24576;

    tab->size = 23;

    return tab;
}


/**
   Removes the starting and ending whitespace characters from 
   given string. Also, removes the comments from this statement
   if present.
*/
void cleanup(char *line) {
    
}

int assembler(int infd, int outfd) {

    s_table *tab = init_s_table(stable);
    
    // First pass
    char *line;
    while ((line = readline(infd)) != NULL) {
	cleanup(line);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
	printf("Usage: %s <file.asm>\n", argv[0]);
	exit(0);
    }

    int infd = open(argv[1], O_RDONLY);
    if (infd < 0) {
	perror("Error opening file. Exiting");
	exit(0);
    }

    char out_filename[64];
    int i = 0;
    while (argv[1][i] != '.') {
	out_filename[i] = argv[1][i];
	i++;
    }
    strcpy(out_filename + i, ".hack");

    int outfd = open(out_filename, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    if (outfd < 0) {
	perror("Error creating output file. Exiting");
	exit(0);
    }
    
    assembler(infd, outfd);
    
    return 0;
}
