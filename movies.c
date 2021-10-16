#include "movies.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct movie *createMovie(char *curr){
	
	struct movie *nMovie = malloc(sizeof(struct movie));
	char *save;
	

	//first token is the name
	char* token =strtok_r(curr, ",", &save);
	nMovie->name = calloc(strlen(token)+1, sizeof(char));
	strcpy(nMovie->name, token);

	//next token is the year
	token =strtok_r(NULL, ",", &save);
	nMovie->year = atoi(token);


	//next token is the lang
	token =strtok_r(NULL, ",", &save);
	nMovie->lang = calloc(strlen(token)+1, sizeof(char));
	strcpy(nMovie->lang, token);

	//next token is the rating
	token =strtok_r(NULL, ",", &save);
	nMovie->rate=strtod(token, NULL);
	nMovie->next = NULL;

	return nMovie;
}

struct movie *processFile(char *fileP){

	//read only
	FILE *mFile = fopen(fileP, "r");
	if(mFile==NULL){
		printf("Invalid File\n");
		return NULL;

	}

	//setting up vars for file reading
	char* curr = NULL;
	size_t len = 0;
	ssize_t nread;
	char* tok;

	//head & tail created
	struct movie *head = NULL;
	struct movie *tail = NULL;

	//read line by line
	while((nread = getline(&curr, &len, mFile)) != -1){
		
		struct movie *nNode = createMovie(curr);

		if(head == NULL){
			head = nNode;
			tail = nNode;
		}
		else{
			tail->next = nNode;
			tail = nNode;
		}
	}
	free(curr);
	fclose(mFile);
	return head;
}



void printMovie(struct movie *head){ 
	printf("%s, %i, %s, %.1f\n", head->name, head->year, head->lang, head->rate); 
} 

int printList(struct movie *list){ 
	int x=0;
	while(list != NULL){
		printMovie(list);
		list = list->next;
		x++;
	}
	return x;
}

