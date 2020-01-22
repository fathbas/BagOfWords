#include <stdio.h> 
#include <dirent.h>
#include<stdlib.h>
#include<Math.h>
/*
*Fatih Baþ 
*150117048
*/


//struct for MLL, orders and infos
 typedef struct node{
	char word[76];
	int counter[3];
	double result[3][1];
    struct node *next;
	struct info *iNext;
	struct firstOrder *hFirst;
	struct secondOrder *sFirst;
	struct thirdOrder *tFirst;
	
}node;

typedef struct topicCounter{
	struct node *tNode;
	struct topicCounter *next;
}topicCounter;

typedef struct firstOrder{
	struct node *fNode;
struct firstOrder *next;
}firstOrder;

typedef struct secondOrder{
	struct node *sNode;
struct secondOrder *next;
}secondOrder;

typedef struct thirdOrder{
	struct node *tNode;
struct thirdOrder *next;
}thirdOrder;

typedef struct info{
	int txt;
	char topic[76];
	struct info *next;
}info;


//Global variables(heads)
node * folder1;
node * iter;
node * temp;
topicCounter * firstHead;
topicCounter * secondHead;
topicCounter * thirdHead;
char topicName[3][76];


DIR *dir2;
struct dirent *ent2;
DIR *dir;
struct dirent *ent;	

//calculate file number in topic
int sumOfFilesNumber(char* name){
	char names[100];
	strcpy(names,"dataset\\\\");
	strcat(names, name);
	
		int files = -2;
	if ((dir2 = opendir (names)) != NULL) {
  /* print all the files and directories within directory */
  	while ((ent2 = readdir (dir2)) != NULL) {
    //	printf ("%s\n", ent->d_name);
    	files++;
  	}
  	closedir (dir2);
	} else {
  	/* could not open directory */
  	perror ("");
}
return files;
}

//create MLL and add word's info
void MLL(char* buf,char* folder,int x){
	info * d;
		int a = 1 ;
		  if(folder1 == NULL){
         	folder1 = (node *) malloc(sizeof(node));
         	strcpy(folder1 -> word, buf);
            printf(" %s\n", folder1 -> word);
            if(strcmp(folder,topicName[0]) == 0){
            	 folder1 -> counter [0]  = 0;
            	 folder1 -> counter [1]  = 0;
            	 folder1 -> counter [2]  = 0;
            folder1 -> counter [0] = 1;	
            folder1 -> iNext = (info *) malloc(sizeof(info));
            folder1 -> iNext -> txt = x; 
            strcpy(folder1 -> iNext -> topic,topicName[0]);
            folder1 -> iNext -> next =NULL;
			}
			 if(strcmp(folder,topicName[1]) == 0){
			 	 folder1 -> counter [0]  = 0;
            	 folder1 -> counter [1]  = 0;
            	 folder1 -> counter [2]  = 0;
            folder1 -> counter [1] = 1;	
            folder1 -> iNext = (info *) malloc(sizeof(info));;
            folder1 -> iNext -> txt = x; 
            strcpy(folder1 -> iNext -> topic,topicName[1]);
             folder1 -> iNext -> next =NULL;
			}
			 if(strcmp(folder,topicName[2]) == 0){
			 	 folder1 -> counter [0]  = 0;
            	 folder1 -> counter [1]  = 0;
            	 folder1 -> counter [2]  = 0;
            folder1 -> counter [2] = 1;	
            folder1 -> iNext = (info *) malloc(sizeof(info));
            folder1 -> iNext -> txt = x; 
            strcpy(folder1 -> iNext -> topic,topicName[2]);
            folder1 -> iNext -> next =NULL;
			}
             iter = folder1;
             iter->next=NULL; 
			}else{
            	temp = folder1;
				while(temp != NULL){
					 a = strcmp(temp -> word,buf );
					if(a == 0){
						break;
					}
					 temp = temp -> next;
				    }
             	if(a != 0 ){
             	 	 iter -> next = (node*)malloc(sizeof(node));
        			 iter = iter -> next;
                     iter->next=NULL;
               		 strcpy(iter -> word, buf);
             		 printf(" %s\n", iter -> word);	
             		  if(strcmp(folder,topicName[0]) == 0)
					   {
					 	iter -> counter [0]  = 0;
            	        iter -> counter [1]  = 0;
            	 		iter -> counter [2]  = 0;
				  	    iter -> counter[0] = 1;
				  	    iter -> iNext = (info *) malloc(sizeof(info));;
                        iter -> iNext -> txt = x; 
                        strcpy(iter -> iNext -> topic,topicName[0]);
                        iter -> iNext -> next = NULL;
				       }
				      if(strcmp(folder,topicName[1]) == 0)
				       {
				       	iter -> counter [0]  = 0;
            	        iter -> counter [1]  = 0;
            	 		iter -> counter [2]  = 0;
				  	    iter -> counter[1] = 1;
				  	    iter -> iNext = (info *) malloc(sizeof(info));;
                        iter -> iNext -> txt = x; 
                        strcpy(iter -> iNext -> topic,topicName[1]);
                        iter -> iNext -> next = NULL;
				       } 
				       if(strcmp(folder,topicName[2]) == 0)
				       {
				       	iter -> counter [0]  = 0;
            	        iter -> counter [1]  = 0;
            	 		iter -> counter [2]  = 0;
				  	    iter -> counter[2] = 1;
				  	    iter -> iNext = (info *) malloc(sizeof(info));;
                        iter -> iNext -> txt = x; 
                        strcpy(iter -> iNext -> topic,topicName[2]);
                        iter -> iNext -> next = NULL;
				       } 
				  }	  
			}
               if(a == 0 && strcmp(folder,topicName[0]) == 0){
				  	temp -> counter[0] = temp -> counter[0] + 1;
				  	d = temp ->iNext;
				  	if(d -> next == NULL){
				  		  d -> next = (info *) malloc(sizeof(info)); 
                        d -> next -> txt = x; 
                        strcpy(d -> next -> topic,topicName[0]);	
                        d -> next -> next = NULL;
					  }
					  else{
					  while(d -> next -> next != NULL){
						  d = d -> next;
					  }
					   d -> next -> next = (info *) malloc(sizeof(info));
                        d -> next -> next-> txt = x; 
                        strcpy(d -> next -> next -> topic,topicName[0]);
                        d -> next -> next-> next = NULL;
					  }
				  }
				  if(a == 0 && strcmp(folder,topicName[1]) == 0){
				  		temp -> counter[1] = temp -> counter[1] + 1;
				   	d = temp ->iNext;
				  	if(d -> next == NULL){
				  		  d -> next = (info *) malloc(sizeof(info)); 
                        d -> next -> txt = x; 
                        strcpy(d -> next -> topic,topicName[1]);	
                        d -> next -> next = NULL;
					  }
					  else{
					  while(d -> next -> next != NULL){
						  d = d -> next;
					  }
					   d -> next -> next = (info *) malloc(sizeof(info));
                        d -> next -> next-> txt = x; 
                        strcpy(d -> next -> next -> topic,topicName[1]);
                        d -> next -> next-> next = NULL;
					  }
				  }
				  if(a == 0 && strcmp(folder,topicName[2]) == 0){
				  		temp -> counter[2] = temp -> counter[2] + 1;
				  	 	d = temp ->iNext;
				  	if(d -> next == NULL){
				  		  d -> next = (info *) malloc(sizeof(info)); 
                        d -> next -> txt = x; 
                        strcpy(d -> next -> topic,topicName[2]);	
                        d -> next -> next = NULL;
					  }
					  else{
					  while(d -> next -> next != NULL){
						  d = d -> next;
					  }
					   d -> next -> next = (info *) malloc(sizeof(info));
                        d -> next -> next-> txt = x; 
                        strcpy(d -> next -> next -> topic,topicName[2]);
                        d -> next -> next-> next = NULL;
					  }
				  }
}

//control topic and txt number for first order
int firstDifferences(struct info* x1, struct info* x2){
	info * d,* e;
	d = x1;
	int control1 = 1;
	while(d != NULL){
		e = x2;
		while(e != NULL){
			control1 = strcmp(d  -> topic,e  -> topic);
			if((d -> txt == e -> txt) == 1 && control1 == 0){
				return 1;
			}
			e = e -> next;
		}
			d = d -> next;
	}
	return 0;
}

//create and add first order word by word
void f(){
	node * iter,* iter2;
	firstOrder * fi;
	iter = folder1;
	int a;
	while(iter != NULL){
		iter2 = folder1;
		while(iter2 != NULL){
		  a = firstDifferences(iter -> iNext,iter2 -> iNext);
	     	if(a == 1 && strcmp(iter -> word,iter2 -> word) != 0){
			if(iter -> hFirst == NULL){
				iter -> hFirst = (firstOrder *) malloc(sizeof(firstOrder));
				iter -> hFirst -> fNode  = iter2;
				iter -> hFirst ->next = NULL;
				fi = iter -> hFirst;
			}
			else{
				while(fi -> next != NULL){
					fi = fi -> next;
				}
				fi -> next = (firstOrder *) malloc(sizeof(firstOrder));
				fi -> next -> fNode = iter2;
				fi -> next -> next  = NULL;
			}
		}
		iter2 = iter2 -> next;
		}
		iter = iter -> next;
	}
}

//create and add second order word by word
void s(){
	node * iter;
	firstOrder * fi,* fi2,* fi3;
	secondOrder * se,* se2;
	int a = 1;
	int b = 1;
	iter = folder1;
    while(iter!=NULL){
    		fi = iter ->hFirst;
    		while(fi != NULL){
    				fi2 = fi -> fNode -> hFirst;
    			while(fi2 != NULL){
    				 fi3 = iter ->hFirst;
    				 while(fi3 !=NULL){
    					a = strcmp(fi3 -> fNode -> word,fi2 -> fNode -> word);
    					if(a == 0 || strcmp(fi2 -> fNode -> word,iter->word)==0){
    						a = 0;
    						break;
						}
							a = 1;
						fi3 = fi3 -> next;
					 }
				if(a == 1){
				if(iter -> sFirst == NULL){
				iter -> sFirst = (secondOrder *) malloc(sizeof(secondOrder));
				iter -> sFirst -> sNode = fi2 -> fNode;
				iter -> sFirst -> next = NULL;
				se = iter -> sFirst;
			}
			else{
				se2 = iter -> sFirst;
				while(se2 != NULL){
					if(strcmp(se2 -> sNode -> word,fi2 -> fNode->word) == 0){
						b = 0;
						break;
					}
					b = 1;
					se2 = se2->next;	
				}
				if(b ==1){
				while(se -> next != NULL){
					se = se -> next;
				}
				se -> next = (secondOrder *) malloc(sizeof(secondOrder));
				se -> next -> sNode = fi2 -> fNode;
				se -> next -> next = NULL;
			}
		}
		}
		a = 1;
			fi2 = fi2 -> next;
				}
				fi = fi ->next;
				}
    		iter = iter -> next;
		}
	}

//create and add third order word by word
void t(){
	node * iter;
	firstOrder * fi;
	secondOrder * se,* se2,* se3;
	thirdOrder * th,* th2;

	int a = 1;
	int c = 1;
	iter = folder1;
    while(iter!=NULL){
    		se = iter ->sFirst;
    		while(se != NULL){
    				se2 = se -> sNode -> sFirst;
    			while(se2 != NULL){
    				 se3 = iter ->sFirst;
    				 while(se3 !=NULL){
    					a = strcmp(se3 -> sNode -> word,se2 -> sNode -> word);
    					if(a == 0 || strcmp(se2 -> sNode -> word,iter->word)==0){
    						a = 0;
    						break;
						}
							a = 1;
						se3 = se3 -> next;
					 }
					 if(a == 1){
					 	 fi = iter -> hFirst;
					 while(fi != NULL){
					 	if(strcmp(fi -> fNode -> word,se2 -> sNode -> word) == 0 || strcmp(se2 -> sNode -> word,iter->word)==0){
					 		a = 0;
					 		break;
						 }
						 a = 1;
						 fi = fi -> next;
					 }	
					 }
				if(a == 1){
				if(iter -> tFirst == NULL){
				iter -> tFirst = (thirdOrder *) malloc(sizeof(thirdOrder));
				iter -> tFirst -> tNode = se2 -> sNode;
				iter -> tFirst -> next = NULL;
				th = iter -> tFirst;
			}
			else{
					th2 = iter -> tFirst;
				while(th2 != NULL){
					if(strcmp(th2 -> tNode -> word,se2 -> sNode->word) == 0){
						c = 0;
						break;
					}
					c = 1;
					th2 = th2->next;	
				}
				if(c == 1){
					
				while(th -> next != NULL){
					th = th -> next;
				}
				th -> next = (thirdOrder *) malloc(sizeof(thirdOrder));
				th -> next -> tNode = se2 -> sNode;
				th -> next -> next = NULL;
			}
		}
		}
		a = 1;
			se2 = se2 -> next;
				}
				se = se ->next;
				}
    		iter = iter -> next;
		}
	}

//calculate word's idf and count and add linked list sort descenting for first topic
void counter1(int k){
	node * iter;
	info * d;
		  iter =folder1;
		while(iter != NULL){
			if(iter -> counter[0]!=0){
				topicCounter * tIter,* control,*temp;
					int count = 0;
				int c = 0;
				d =iter -> iNext;
				while(d != NULL){
					if(strcmp(d->topic,topicName[0])==0 && d->txt != c){
						count++;
					    c++;
					d =d ->next;
						continue;
					}
					d =d ->next;	
				}
				iter -> result[0][0] = 0;
				iter -> result[0][0] = log(k/(double)count);
			if(firstHead == NULL){
	        firstHead = (topicCounter*)malloc(sizeof(topicCounter));
			firstHead -> tNode = iter;
			firstHead -> next = NULL;
		    }
			else{
			    if(firstHead -> tNode -> counter[0] < iter -> counter[0]){
			    	control = (topicCounter*)malloc(sizeof(topicCounter));
			    	control -> tNode = iter;
			    	control -> next = firstHead;
			    	firstHead = control;
				}
				else{
						tIter = firstHead;
				while(tIter -> next != NULL && tIter -> next -> tNode -> counter[0] > iter -> counter[0]){
					tIter = tIter -> next;
				}
				if(tIter -> next != NULL){
				temp = (topicCounter*)malloc(sizeof(topicCounter));
				temp -> tNode = iter;
				temp -> next = tIter -> next;
				tIter -> next = temp;
				}
				else{
					tIter -> next = (topicCounter*)malloc(sizeof(topicCounter));
					tIter -> next -> tNode = iter;
					tIter -> next -> next= NULL;
				}	
				}
			}
		}
		iter = iter ->next;	
		}
}

//calculate word's idf and count and add linked list sort descenting for second topic
void counter2(int k){
	node * iter;
	info * d;
		  iter =folder1;
		while(iter != NULL){
			if(iter -> counter[1]!=0){
				topicCounter * tIter,* control,*temp;
				int count = 0;
				int c = 0;
				d =iter -> iNext;
				while(d != NULL){
					if(strcmp(d->topic,topicName[1])==0 && d->txt != c){
						count++;
					    c++;
					d =d ->next;
						continue;
					}
					d =d ->next;	
				}
				iter -> result[1][0] = 0;
				iter -> result[1][0] = log(k/(double)count);
			if(secondHead == NULL){
	        secondHead = (topicCounter*)malloc(sizeof(topicCounter));
			secondHead -> tNode = iter;
			secondHead -> next = NULL;
		    }
			else{
			    if(secondHead -> tNode -> counter[1] < iter -> counter[1]){
			    	control = (topicCounter*)malloc(sizeof(topicCounter));
			    	control -> tNode = iter;
			    	control -> next = secondHead;
			    	secondHead = control;
				}
				else{
						tIter = secondHead;
				while(tIter -> next != NULL && tIter -> next -> tNode -> counter[1] > iter -> counter[1]){
					tIter = tIter -> next;
				}
				if(tIter -> next != NULL){
				temp = (topicCounter*)malloc(sizeof(topicCounter));
				temp -> tNode = iter;
				temp -> next = tIter -> next;
				tIter -> next = temp;
				}
				else{
					tIter -> next = (topicCounter*)malloc(sizeof(topicCounter));
					tIter -> next -> tNode = iter;
					tIter -> next -> next= NULL;
				}	
				}
			}
		}
		iter = iter ->next;	
		}
}

//calculate word's idf and count and add linked list sort descenting for third topic
void counter3(int k){
	node * iter;
	info * d;
		  iter =folder1;
		while(iter != NULL){
			if(iter -> counter[2]!=0){
				topicCounter * tIter,* control,*temp;
					int count = 0;
				int c = 0;
				d =iter -> iNext;
				while(d != NULL){
					if(strcmp(d->topic,topicName[2])==0 && d->txt != c){
						count++;
					    c++;
					d =d ->next;
						continue;
					}
					d =d ->next;	
				}
				iter -> result[2][0] = 0;
				iter -> result[2][0] = log(k/(double)count);
			if(thirdHead == NULL){
	        thirdHead = (topicCounter*)malloc(sizeof(topicCounter));
			thirdHead -> tNode = iter;
			thirdHead -> next = NULL;
		    }
			else{
			    if(thirdHead -> tNode -> counter[2] < iter -> counter[2]){
			    	control = (topicCounter*)malloc(sizeof(topicCounter));
			    	control -> tNode = iter;
			    	control -> next = thirdHead;
			    	thirdHead = control;
				}
				else{
						tIter = thirdHead;
				while(tIter -> next != NULL && tIter -> next -> tNode -> counter[2] > iter -> counter[2]){
					tIter = tIter -> next;
				}
				if(tIter -> next != NULL){
				temp = (topicCounter*)malloc(sizeof(topicCounter));
				temp -> tNode = iter;
				temp -> next = tIter -> next;
				tIter -> next = temp;
				}
				else{
					tIter -> next = (topicCounter*)malloc(sizeof(topicCounter));
					tIter -> next -> tNode = iter;
					tIter -> next -> next= NULL;
				}	
				}
			}
		}
		iter = iter ->next;	
		}
}

//swap for sort descending idf
void swap(struct topicCounter *a, struct topicCounter *b) { 
    topicCounter* temp;
	temp->tNode = a->tNode; 
    a->tNode = b->tNode; 
    b->tNode = temp->tNode; 
} 

//control and sort idf descending for first topic
void firstBubbleSort() { 
    int swapped, i; 
     topicCounter *ptr1; 
     topicCounter *lptr = NULL; 
  
    /* Checking for empty list */
    if (firstHead == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = firstHead; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->tNode->result[0][0] < ptr1->next->tNode->result[0][0]) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

//control and sort idf descending for second topic
void secondBubbleSort() { 
    int swapped, i; 
     topicCounter *ptr1; 
     topicCounter *lptr = NULL; 
  
    /* Checking for empty list */
    if (secondHead == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = secondHead; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->tNode->result[1][0] < ptr1->next->tNode->result[1][0]) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

//control and sort idf descending for third topic
void thirdBubbleSort() { 
    int swapped, i; 
     topicCounter *ptr1; 
     topicCounter *lptr = NULL; 
  
    /* Checking for empty list */
    if (thirdHead == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = thirdHead; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->tNode->result[2][0] < ptr1->next->tNode->result[2][0]) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 


int main(){
//variables
folder1 = NULL;
firstHead = NULL;
secondHead = NULL;
thirdHead = NULL;
node * iter;
firstOrder * fi;
secondOrder * se;
thirdOrder * th;
topicCounter * tTemp;
int  j = 0;
int a  = 1;
int sumOfFile[3];

//read dataset and send to MLL method for add linkedList
	if ((dir = opendir ("dataset")) != NULL) {
		printf("----------------\n");
		printf("MLL\n");
		printf("----------------\n");
  	while ((ent = readdir (dir)) != NULL) {
  		sumOfFile[j] = sumOfFilesNumber(ent->d_name);
  	if(strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0 ){
  		continue;
  	}
  	else{
  		strcpy(topicName[j],ent->d_name);
    	for(int i = 1; i <= sumOfFile[j]; i++){
	char result[76]; 
    sprintf(result, "%d", i); 
		char names[76];
	strcpy(names,"dataset\\\\");
	strcat(names, ent->d_name);
	strcat(names, "\\\\");
	strcat(names, result);
	strcat(names, ".txt");
	FILE *fp = fopen(names,"r");
 
    char buf[76];
        while( fscanf(fp, "%s", buf) != EOF )
        { 
        MLL(buf,ent->d_name,i);
		}   
		}
	}
	j++;
  	}
  	closedir (dir);
	} else {
  	perror ("");
}

	iter = folder1;
	while(iter != NULL){
			iter -> hFirst = NULL;
        	iter -> sFirst = NULL;
        	iter -> tFirst = NULL;
        	iter = iter ->next;
	}
	
//call methods
 f();  
 s();  
 t();   
 counter1(sumOfFile[0]);
 counter2(sumOfFile[1]);
 counter3(sumOfFile[2]);

//print first ,second and third order
  iter =folder1;
        while(iter !=NULL){
        	printf("\n--------------\n");
        	 printf("%s \n",iter->word);
        	 printf("--------------\n");
        	 printf("FIRST ORDER \n");
        	fi = iter -> hFirst;
        	while(fi !=NULL){
        		printf(" %s",fi ->fNode ->word);
        		fi = fi ->next;
			}
			printf("\nSECOND ORDER \n");
				se = iter -> sFirst;
        	while(se !=NULL){
        		printf(" %s",se ->sNode ->word);
        		se = se ->next;
			}
			printf("\nThird ORDER \n");
				th = iter -> tFirst;
        	while(th !=NULL){
        		printf(" %s",th ->tNode ->word);
        		th = th ->next;
			}
			iter = iter ->next;
		}
		
//print 5 word which top 5 topic by topic	
printf("\n-----------------\n");
printf("COUNT TOP 5 WORD\n");	
		tTemp = firstHead;
			printf("-----------------\n");
			printf("%s\n",topicName[0]);
			printf("-----------------\n");
		for(int i = 0; i < 5; i++){
			printf("%d %s \n", tTemp -> tNode -> counter[0],tTemp -> tNode -> word);
			tTemp = tTemp -> next;
		}
			tTemp = secondHead;
			printf("-----------------\n");
			printf("%s\n",topicName[1]);
			printf("-----------------\n");
		for(int i = 0; i < 5; i++){
			printf("%d %s \n", tTemp -> tNode -> counter[1],tTemp -> tNode -> word);
			tTemp = tTemp -> next;
		}
			tTemp = thirdHead;
			printf("-----------------\n");
			printf("%s\n",topicName[2]);
			printf("-----------------\n");
		for(int i = 0; i < 5; i++){
			printf("%d %s \n", tTemp -> tNode -> counter[2],tTemp -> tNode -> word);
			tTemp = tTemp -> next;
		}
//call methods 
firstBubbleSort();
secondBubbleSort();
thirdBubbleSort();

//print word's idf which top 5 topic by topic
printf("-----------------\n");
printf("IDF TOP 5 WORD\n");
 	     tTemp = firstHead;
			printf("-----------------\n");
			printf("%s\n",topicName[0]);
			printf("-----------------\n");
		for(int i = 0; i < 5; i++){
			printf("%f %s \n", tTemp -> tNode -> result[0][0],tTemp -> tNode -> word);
			tTemp = tTemp -> next;
		}
		tTemp = secondHead;
			printf("-----------------\n");
			printf("%s\n",topicName[1]);
			printf("-----------------\n");
		for(int i = 0; i < 5; i++){
			printf("%f %s \n", tTemp -> tNode -> result[1][0],tTemp -> tNode -> word);
			tTemp = tTemp -> next;
		}
			tTemp = thirdHead;
			printf("-----------------\n");
			printf("%s\n",topicName[2]);
			printf("-----------------\n");
		for(int i = 0; i < 5; i++){
			printf("%f %s \n", tTemp -> tNode -> result[2][0],tTemp -> tNode -> word);
			tTemp = tTemp -> next;
		}
		
		
		
      return 0;
}


