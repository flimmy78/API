#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct student {
	int num;
	int age;
	struct student * next;
}STU;
STU *creat(int n);
STU *search(STU*head);
void link_print(STU * head);
int main()
{
	STU * head;
	head=creat(3);

	//link_print(head);
	search(head);
	return 0;
}

STU *creat(int n)
{
	int i;
	STU * head,*pb,*pf;
	for(i=0;i<n;i++)
	{
		pb=(STU *)malloc(sizeof(STU));
		printf("please input num  age:\n");
		scanf("%d%d",&(pb->num),&(pb->age));
		getchar();
		if(i==0)
		{
			head=pf=pb;
		}
		else
		{
			pf->next=pb;
			pf=pb;
		}
	}
	pb->next=NULL;
	return head;
}

/*void link_print(STU * head)
{
	STU *pb;
	pb=head;
	while(pb!=NULL)
	{
		printf("%d %d \n",pb->num,pb->age);
		pb=pb->next;
	}
}*/
void search(STU*head)
{
	STU *pb;
	pb=head;
	int no,i=0;
	printf("please input the no you are searching for:\n");
    scanf("%d",&no);
	for(;pb!=NULL;pb++)
      if(pb->num==no)break;
	  printf("%d %d\n",pb->num,pb->age);
}