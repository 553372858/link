#include <stdio.h>
#include <stdlib.h>
typedef struct student {
	int data;
	char name[50];
	struct student *next;
}STU;

void link_create (STU **head, STU *pnew) {

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
	STU *pb=head;
	while (pb!=NULL) {
		printf("%d %s\n",pb->data,pb->name);	
		pb=pb->next;
	}
}

void link_delete(STU **head ,int num) {
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

int main(int argc, const char *argv[])
{
	STU *head,*pnew;
	int i,n=0;
	int num;
	head = NULL;
	printf("初始化人数\n");
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		pnew=(STU *)malloc(sizeof(STU));
		scanf("%d %s",&pnew->data,pnew->name);
		link_create(&head, pnew);

	}
	link_print(head);
	printf("删除的节点数字\n");
	scanf("%d",&num);
	link_delete(&head, num);
	link_print(head);

	return 0;
}
