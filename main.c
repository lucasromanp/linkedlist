/*
 ============================================================================
 Name        : LL with prompt
 Author      : Lucas Roman
 Version     : 1.0
 Copyright   : opensource
 Description : code for kryptus interview
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ll_struct
{
    int val;
    struct ll_struct *next;
};

struct ll_struct *head = NULL;
struct ll_struct *curr = NULL;


struct ll_struct* create_list(int val)
{
    struct ll_struct *ptr = (struct ll_struct*)malloc(sizeof(struct ll_struct));
    if(NULL == ptr)
    {
        printf("\n Erro 1 \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;
}

struct ll_struct* add_to_list(int val)
{
    if(NULL == head)
    {
        return (create_list(val));
    }

    struct ll_struct *ptr = (struct ll_struct*)malloc(sizeof(struct ll_struct));
    if(NULL == ptr)
    {
        printf("\n Erro 2 \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;

    curr->next = ptr;
    curr = ptr;
    
    return ptr;
}

struct ll_struct* search_in_list(int val, struct ll_struct **prev)
{
    struct ll_struct *ptr = head;
    struct ll_struct *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value [%d] \n",val);

    while(ptr != NULL)
    {
        if(ptr->val == val)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(true == found)
    {
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}
int get_in_list(int val, struct ll_struct **prev)
{
    struct ll_struct *ptr = head;
    struct ll_struct *tmp = NULL;
    int counter = 0;
    
    while(ptr != NULL)
    {
        if(counter == val)
        {
            return ptr->val;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
        counter++;
    }
    return 0;
    
}

int delete_in_list(int val, struct ll_struct **prev)
{
    struct ll_struct *ptr = head;
    struct ll_struct *tmp = NULL;
    int counter = 0;
    
    while(ptr != NULL)
    {
        if(counter == val)
        {
            return ptr->val;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
        counter++;
    }
    return -1;
    
}


int delete_from_list(int val)
{
    struct ll_struct *prev = NULL;
    struct ll_struct *del = NULL;

    printf("\n Deleting value [%d] from list\n",val);

    del = search_in_list(val,&prev);
    if(del == NULL)
    {
        return -1;
    }
    else
    {
        if(prev != NULL)
            prev->next = del->next;

        if(del == curr)
        {
            curr = prev;
        }
        else if(del == head)
        {
            head = del->next;
        }
    }

    free(del);
    del = NULL;

    return 0;
}

void print_list(void)
{
    struct ll_struct *ptr = head;
    while(ptr != NULL)
    {
        printf(" %d ",ptr->val);
        ptr = ptr->next;
    }
    printf("\n");

    return;
}

void process_entry(char *entry) {
    char * spaceAdd = NULL; 
    spaceAdd = strchr(entry,' ');
    if(spaceAdd){
        

        char comm[6],commBuffer[6];
        int i=0;
        while(entry < spaceAdd){
              //printf("You entered: %s\n", entry);
              comm[i] = entry[0];
              entry++;
              i++;
            
        }
        int insertion =0;
        sscanf(entry, "%d", &insertion);
        strcpy(commBuffer, "put");
        if( strcmp(comm, commBuffer) == 0)
        {
             add_to_list(insertion);
             print_list();
        }
         strcpy(commBuffer, "get");
        if( strcmp(comm, commBuffer) == 0)
        {
            printf("%d \n",get_in_list(insertion,NULL));
        }
        	
        	
    }else{
        strcpy(commBuffer, "list");
        if( strcmp(comm, commBuffer) == 0)
        {
            print_list();
        }
        strcpy(commBuffer, "first");
        if( strcmp(comm, commBuffer) == 0)
        {
            print_list();
        }
        strcpy(commBuffer, "last");
        if( strcmp(comm, commBuffer) == 0)
        {
            print_list();
        }
        
    }
	
}


int main(int argc, char *argv[]) {
	char input[201];
    int i = 0, ret = 0;
    struct test_struct *ptr = NULL;

    print_list();

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

		process_entry(input);
	}

	return EXIT_SUCCESS;
}
