#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
	int num;
	char name[30];
	struct student *next;
}STU;

void link_print(STU *head)
{
	STU *pb = head;
	
	printf("学号\t姓名\n");
	while(pb != NULL){
		printf("%d\t%s\n",pb->num,pb->name);
		pb = pb->next;
	}
}

STU *link_create(int num)
{
	int i;
	STU *head,*pb,*pf = NULL;
	
	printf("学号\t姓名\n");
	for(i=0;i<num;i++){
		pb = malloc(sizeof(STU));
		scanf("%d%s",&pb->num,pb->name);
		if(i == 0){
			head = pb;
			pf = pb;
		}else{
			pf->next = pb;
			pf = pb;
		}
	}
	if(pf == NULL)
		return NULL;
	pf->next = NULL;
	return head;
}
STU *link_insert(STU *head,STU *p_new)
{
	if(head == NULL){
		head = p_new;
		head->next = NULL;
	}else{
		p_new->next = head;
		head = p_new;	
	}
	return head;
}

int main()
{
	int i,num;
	STU *head = NULL,*p_new;//head指向一个链表,即第一个节点
	
	printf("请输入你要创建的节点数量:\n");
	scanf("%d",&num);
	printf("学号\t姓名\n");
	for(i=0;i<num;i++){
		p_new = malloc(sizeof(STU));
		scanf("%d%s",&p_new->num,p_new->name);
		head = link_insert(head,p_new);	
	}
	link_print(head);
	return 0;
}
