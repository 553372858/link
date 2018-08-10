#ifndef __LINK_H__
#define __LINK_H__

typedef struct student {
	int data;
	char name[50];
	struct student *next;
}STU;


void link_create (STU **head);
void link_insert(STU **head);
void link_delete(STU **head);
void link_search (STU *head);
void link_print (STU *head);
void _link_create (STU **head, STU *pnew);
void _link_insert(STU **head ,STU *padd);
void _link_delete(STU **head ,int num);
STU * _link_search (STU *head,int num);
void _link_print (STU *head);
#endif
