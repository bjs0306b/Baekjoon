#include <stdio.h>

typedef struct
{
	int top;
	int data[10000];
}stacktype;

void init(stacktype *s)
{
	s->top = -1;
}

void push(stacktype *s, int data)
{
	s->data[++s->top] = data;
}

int pop(stacktype *s)
{
	if(s->top == -1) return -1;
	return s->data[s->top--];
}

int size(stacktype *s)
{
	return s->top+1;
}

int empty(stacktype *s)
{
	return s->top == -1;
}

int top(stacktype *s)
{
	if(s->top == -1) return -1;
	return s->data[s->top];
}

int main(void)
{
	int num1,num2;
	char command[10];

	stacktype *sta = (stacktype*)malloc(sizeof(stacktype));
	init(sta);

	scanf("%d",&num1);

	for(int i=0;i<num1;i++)
	{
		scanf("%s", command);
		if(!strcmp(command, "push") )
		{
			scanf("%d", &num2);
			push(sta, num2);
		}
		else if(!strcmp(command, "pop"))
		{
			printf("%d\n",pop(sta));
		}
		else if(!strcmp(command, "top"))
		{
			printf("%d\n",top(sta));
		}
		else if(!strcmp(command, "size"))
		{
			printf("%d\n",size(sta));
		}
		else if(!strcmp(command, "empty"))
		{
			printf("%d\n",empty(sta)?1:0);
		}
	}
	return 0;
}