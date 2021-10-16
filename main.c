#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lang.h"
#include "year.h"
#include "rate.h"
#include "movies.h"


int main(int argc, char *argv[]){

	//file processing
	if(argc <2){
		printf("Failure to provide all args, try again.");
		return EXIT_FAILURE;
	}
	struct movie *list = processFile(argv[1]);
	if(list==NULL)
		return EXIT_FAILURE;

	int initList=printList(list);
	printf("\nProcessed %s, for %i movies\n", argv[1], initList);

	//seting up vars for user input and prog loop	
	int choice=0;
	char specs;
	struct movie *c1;
	struct movie *c2;
	struct movie *c3;
	while(choice!=4){
		c1=list;
		c2=list;
		c3=list;

		printf("Select from choices ranging, 1-4\n");
		printf("1. Show movies released in a year\n");
		printf("2. Show highest rated movie for each year\n");
		printf("3. Show the title and year of release of all movies in a specific language\n");
		printf("4. Quit the program\n");
		printf("Your selection: ");
		scanf("%d", &choice);
		printf("\n");

		if(choice!=1&&choice!=2&&choice!=3&&choice!=4)
			printf("Incorrect option, pick again\n");

		printf("\n");
		if(choice==1){
			printf("Enter the year: ");
			scanf("%s", &specs);
			sortYear(c1, &specs);
		}

		if(choice==2)
			sortRate(c2);

		if(choice==3){	
			printf("Enter the language: ");
			scanf("%s", &specs);
			sortLang(list, &specs);	
		}

		printf("\n");


	}

	return EXIT_SUCCESS;
}
