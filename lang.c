#include "lang.h"
#include "movies.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//similar structure, search for the substring using strstr(char,char) find boolean connect

void sortLang(struct movie *list, char* inp){
	
	//setting up year, new list for printing, iterator
	struct movie *iter=list;

	//setting up and checking if keyword is in the first movie from list
	char* sub=NULL;
	sub=strstr(iter->lang, inp);

	while(sub==NULL&&iter!=NULL){
		sub=strstr(iter->lang, inp);
		if(sub!=NULL)
			break;
		iter=iter->next;
	}
	
	//setting up iterators and head
	printf("\n");
	printMovie(iter);
	iter=iter->next;
	//head of list has been established for reading, finding next set of movies, print if fit criteria
	while(iter!=NULL){
		sub=strstr(iter->lang, inp);

		if(sub!=NULL)
			printMovie(iter);
		iter=iter->next;
	}
}
