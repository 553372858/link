#include <stdio.h>
#include <stdlib.h>
#include "link.h"

void link_create (STU **head) {
	int n = 0;
	int i = 0;
	STU * pnew;
	printf("初始化人数\n");
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		pnew=(STU *)malloc(sizeof(STU));
		scanf("%d %s",&pnew->data,pnew->name);
		_link_create(head, pnew);
	}

}

void _link_create (STU **head, STU *pnew) {

	STU *pmov=*head;

	if (*head==NULL) {
		*head=pnew;
		pnew->next=NULL;
		return ;
	} 

	while (pmov->next!=NULL) {
		pmov=pmov->next;
	}
	pmov->next=pnew;	
	pnew->next=NULL;
}

void link_print (STU *head) {
	_link_print(head);
}
void _link_print (STU *head) {
	STU *pb=head;
	while (pb!=NULL) {
		printf("%d %s\n",pb->data,pb->name);	
		pb=pb->next;
	}
}

void link_delete(STU **head) {
	int num;
	printf("删除的节点数字\n");

	scanf("%d",&num);
	_link_delete(head, num);
	link_print(*head);
}
void _link_delete(STU **head ,int num) {
	STU *p=*head;
	STU *pf=NULL;
	if (*head==NULL) {
		printf("链表为空\n");
		return ;
	}
	if (p->data == num ) {
		*head=p->next;
		free(p);
		return;
	}
	while (p->data != num) {
		pf=p;
		p=p->next;
	}
	if (p==NULL) {
		printf("没找到\n");
		return ;
	}
	pf->next=p->next;
	free(p);

}


void link_search (STU *head) {
	int num;
	printf("要查找的节点\n");
	scanf("%d",&num);
	STU *ret;
	ret = malloc(sizeof(STU));
	ret = _link_search(head, num);
	if (ret ==NULL) {
		return ;
	}
	printf("%d %s\n",ret->data,ret->name);
}

STU * _link_search (STU *head,int num) {
	STU *p=head;
	if (head == NULL) {
		printf("链表为空\n");
		return NULL;
	}
	while (p->data != num) {
		p=p->next;
		if (p==NULL) {
			printf("没有要查找的节点\n");
			return NULL;
		}
	}
	return p;


}

void link_insert(STU **head) {
	STU * padd;
	printf("添加的成员学号和名字\n");
	padd=(STU *)malloc(sizeof(STU));
	scanf("%d %s",&padd->data,padd->name);
	_link_insert(head,padd);
	link_print(*head);
}
void _link_insert(STU **head ,STU *padd) {
	STU *p=*head;
	STU *pf=NULL;
	if ( *head == NULL) {
		*head=padd;
		padd->next=NULL;
		return ;
	}
	while((p->data <= padd->data )&& (p->next != NULL)) {
		pf=p;
		p=p->next;
	}
	if (p->data > padd->data) {
		if(p == *head) {
			padd->next=p;
			*head=padd;
		}
		else {
			pf->next=padd;
			padd->next=p;
		}
	}
	else {
		p->next=padd;
		padd->next=NULL;
	}

}
int main(int argc, const char *argv[])
{
	STU *head,*pnew,*padd;
	int i,n=0;
	int num;
	padd = NULL;
	head = NULL;
	while (1) {
		printf("create:1 print:2 delete:3 add:4 search:5 exit:x\n");
		int x=0;
		scanf("%d",&x);
		switch (x) {
			case 1:
				link_create(&head);
				break;
			case 2:
				link_print(head);
				break;
			case 3:
				link_delete(&head);
				break;
			case 4:
				link_insert(&head);
				break;
			case 5:
				link_search(head);
				break;
			default:
				return 0;
		}

	}
	return 0;

}
