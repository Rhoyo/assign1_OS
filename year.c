#include "year.h"
#include "movies.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortYear(struct movie *list, char* inp){
	
	//checking for correct input
	int four=strlen(inp);
	if(four!=4)
		return;
	
	//setting up year, new list for printing, iterator
	int year=atoi(inp);
	struct movie *iter=list;

	//establish head
	while(iter->year!=year&&iter!=NULL){iter=iter->next;}

	//setting up iterators, print the head of the list
	printf("\n");
	printMovie(iter);
	iter=iter->next;
	//head of list has been established for reading, finding next set of movies, print movie if fits
	while(iter!=NULL){
		if(iter->year==year)
			printMovie(iter);
		iter=iter->next;	
	}
}
