#ifndef __movies
#define __movies



//struct for movies, holds name, year, languages and rating
struct movie{
	char *name;
	int year;
	char *lang;
	double rate;
	struct movie *next;
};

struct movie *createMovie(char *curr);

struct movie *processFile(char *fileP);

void printMovie(struct movie *head);

int printList(struct movie *list);

#endif
