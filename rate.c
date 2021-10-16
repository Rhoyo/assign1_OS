#include "rate.h"
#include "movies.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//checks if the year is in the list thru the array
int checkList(int x[], int len, int year){
	for(int i=0;i<len;i++)
		if(x[i]==year)
			return 0;
	return 1;	
}

//works by checking the year of a movie, if it has not been seen yet, print out the highest rate for that year
void sortRate(struct movie *list){
	//setting up year, new list for printing, iterator
	struct movie *iter=list;
	struct movie *prev;

	//this struct will hold the current highest rate for that year
	struct movie *temp=iter;
	int len=0;

	while(iter!=NULL){
		len++;
		iter=iter->next;
	}
	iter=list;
	int in[len];
	int x=1;

	//set up "seen list", insert the head->year into the "seen list"
	for(int i=1;i<len;i++)
		in[i]=-1;
	in[0]=iter->year;


	//search for highest rate of that year of the head, print it
	while(iter!=NULL){
		if(iter->year==temp->year&&iter->rate>temp->rate)
			temp=iter;
		iter=iter->next;
	}
	printMovie(temp);

	//set up iterators find next
	iter=list;
	prev=iter;
	prev=prev->next;
	while(prev!=NULL){
		//if this year has not been cataloged yet	
		if(checkList(in, len, prev->year)==1){

			//put it into the "print queue"
			in[x]=prev->year;
			temp=prev;

			//set iterator to top of list
			iter=list;
			//search for the highest rate for that year
			while(iter!=NULL){
				if(iter->year==temp->year&&iter->rate>temp->rate)
					temp=iter;
				iter=iter->next;
			}
			//print that year
			printMovie(temp);
		}
		prev=prev->next;
		x++;
	}
}


