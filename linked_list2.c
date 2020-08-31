#include<stdio.h>
#include<stdlib.h>
typedef struct list{
	char data ;
	struct list* next;
	} ELEMENT;
typedef  ELEMENT* LINKER;


LINKER create_node(char dat)
{
	LINKER header;

	header=malloc(sizeof(ELEMENT));
	header->data=dat;
	header->next=NULL;
	return header;
}
LINKER string_to_list(char *str)
{
	if (str[0]=='\0') return NULL;
	else
	{
		LINKER header=create_node(str[0]);
		str++;
		header->next=string_to_list(str);
		return header;
	}



}
int  print_list(LINKER header)
{
	if (header->next==NULL)
	{
		printf("-------------------");
		printf("\n%c\n",header->data);
		printf("-------------------\n");

	 return 0;
	}
	else 
	{	
		printf("-------------------");
		printf("\n%c\n",header->data);
		print_list(header->next);
		return 1;
	
	}

}
int count_list_element(LINKER header)
{
	int count=0;
	while(header!=NULL)
	{	
		count++;
		header=header->next;
	}
	return count;
}







LINKER concatinate_str_str2(LINKER header1 ,LINKER header2)
{
	LINKER trail=header1;
	int count =count_list_element(header1);
	for (int i=0;i<count;i++)
	{      if (i==(count-1)) trail->next=header2;
			

		trail=trail->next;

	}
	return  header1;
}

void insertion(LINKER header , char str, int place)
{
printf("\n i am here %c %d",str,place);
	LINKER trail=header,temp,trail1;

	int count=count_list_element(header);
	if (count<place) 
{printf("you can  insert the charecter in the list");
exit(1);
}	for (int i=0;i<count;i++)
	{
		if(i==place-1)
		{
			temp=trail->next;
			trail1=create_node(str);
			trail->next=trail1;
		}

		if(i==place)
		{
			trail->next=temp;
		}

		trail=trail->next;
	}
		
}
void delete_list(LINKER header , int place)

{

	LINKER trail=header,temp,temp3,temp2,trail1;

	int count=count_list_element(header);
	if (count<place) printf("you can  delete  the charecter from the list");
	for (int i=0;i<count;i++)
	{
		if(i==place-1)
		{
			temp=trail->next;
			free(temp);
		}

		if(i==place)
		{
			temp2=trail->next;
		}
		if(i==place-2)
		{

			temp3=trail->next;
		}

		trail=trail->next;
		
	}
temp3->next=temp2;
		

}

int main ()
{
char var='a';
LINKER header;
header=create_node(var);
printf("\n the first node %c\n",(header->data));
char *va="123123";
char *va2="#####";


printf("   \n\
		 ________________________________________________________________________________\n\
        	|                                                                                |\n\
		|			%20s                                   	 |\n\
		|________________________________________________________________________________|\n",va);
LINKER Str=string_to_list(va);
LINKER Str2=string_to_list(va2);
/* concatenate the Str2 to the end of the list 1 */;
print_list(Str);
int number=count_list_element(Str);
printf("\nthe number of elements in  linear linked list is %d\n",number);
LINKER sum=concatinate_str_str2(Str ,Str2);
print_list(sum);
char a1='M';
int place1=3;
insertion(sum,a1, place1);
printf("************************************ ");
print_list(sum);
delete_list(sum, 3);
printf("************************************ ");
print_list(sum);

return 0;
}
