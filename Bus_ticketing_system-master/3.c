#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"
#include"2.h"
#include"1.h"
#include"4.h"
#include"5.h"
#include"6.h"

# define MAX 10000

struct date date1,date2;
int num_seats;

int seat(int bus_number)
{
	FILE *bus;
	char buffer[10];
	char arr[50][9]={"EMPTY(01)","EMPTY(02)","EMPTY(03)","EMPTY(04)","EMPTY(05)","EMPTY(06)","EMPTY(07)","EMPTY(08)","EMPTY(09)","EMPTY(10)","EMPTY(11)","EMPTY(12)","EMPTY(13)","EMPTY(14)","EMPTY(15)","EMPTY(16)","EMPTY(17)","EMPTY(18)","EMPTY(19)","EMPTY(20)"};
	int num_of_seats;
	int final_arr[50];

	int bookes_seats = seat_numbers(bus_number, final_arr);

	for(int i = 0; i < bookes_seats; i++)
	{
		arr[final_arr[i]-1][0]='B';
		arr[final_arr[i]-1][1]='O';
		arr[final_arr[i]-1][2]='O';
		arr[final_arr[i]-1][3]='K';
		arr[final_arr[i]-1][4]='E';
		arr[final_arr[i]-1][5]='D';
		arr[final_arr[i]-1][6]=' ';
		arr[final_arr[i]-1][7]=' ';
		arr[final_arr[i]-1][8]=' ';
	}

	display_seats(arr);

	printf("\n\t\t\t\t\tHow many seats do you want to book  : ");
	scanf(" %d", &num_of_seats);
	num_seats=num_of_seats;
	printf("\n\t\t\t\t\tPlease select your seat number followed by spaces: ");

	sprintf(buffer, "%d", bus_number); 
	strcat(buffer,".txt");
	bus = fopen(buffer, "a+");
	int arrr[num_of_seats];	

	int flag1 = 0;

	while(1)
	{

		for(int i=0;i<num_of_seats;i++)
		{
			scanf("%d", &arrr[i]);
		}

		for (int i=0;i<num_of_seats;i++)
		{
			if(arrr[i]>20)
			{
				printf("\n\t\t\t\t\tPlease enter valid seat number : ");
				break;
			}
			else
			{
				flag1++;
			}
		}
		if (flag1 == num_of_seats)
		{
			break;
		}

	}
	int flag = 0;
	int value = 1;
	for(int i = 0; i < bookes_seats; i++)
	{
		for(int j = 0; j < num_of_seats; j++)
		{
			if(final_arr[i] == arrr[j])
			{
				printf("\n\t\t\t\t\tSome of these seats are already reserved ..\n\n");
				flag++;
				value = 0;
				break; 					
			}
		
			else
			{
				for(int i = 0; i < num_of_seats; i++)
				{
					arr[arrr[i]-1][0]='B';
					arr[arrr[i]-1][1]='O';
					arr[arrr[i]-1][2]='O';
					arr[arrr[i]-1][3]='K';
					arr[arrr[i]-1][4]='E';
					arr[arrr[i]-1][5]='D';
					arr[arrr[i]-1][6]=' ';
					arr[arrr[i]-1][7]=' ';
					arr[arrr[i]-1][8]=' ';		
				}

			}
		}
		if(flag != 0)
		{
			break;
		}

		if (flag1 == num_of_seats)
		{
			for(int i=0;i<num_of_seats;i++)
			{
				fprintf(bus, "%d ", arrr[i]);
			}
			break;
		}

	}
	display_seats(arr);
	fclose(bus);
	return value;
}
int book(void)
{
	int flag = 0, val;
	char dep[3], dest[3];
	printf("\n\n\t\t\t\t\t\t\t  BOOK YOUR TICKET EASILY\n");

	printf("\n\t\t\t\t\t\tEnter your departure city(XXX)                 : ");
	scanf("%s", dep);
	val = placecheck(dep);
	if(val == 1)
	{
		while(val != 2)
		{
			printf("%s", "\n\t\t\t\t\t\tPlease Input Valid City code: ");
			scanf("%s", dep);
			val = placecheck(dep);
		}
	}
	upper_case_string(dep);
	
	printf("\t\t\t\t\t\tEnter your destination city(XXX)               : ");
	scanf("%s", dest);
	val = placecheck(dest);
	if(val == 1)
	{
		while(val != 2)
		{
			printf("%s", "\n\t\t\t\t\t\tPlease Input Valid City code: ");
			scanf("%s", dest);
			val = placecheck(dest);
		}
	}
	upper_case_string(dest);

	printf("\t\t\t\t\t\tEnter your date of your journey(00/00/0000)    : ");
	scanf("%d/%d/%d", &date1.dd, &date1.mm, &date1.yy);

	printf("\t\t\t\t\t\tEnter today's date(00/00/0000)                 : ");
	scanf("%d/%d/%d", &date2.dd, &date2.mm, &date2.yy);


	int check = 1;
	while(check > 0)
	{
		int count = 0;
		if(date2.yy > date1.yy)
		{
			count += 1;
		}
		else if(date2.mm > date1.mm)
		{
			count += 1;
		}
		else if(date2.dd > date1.dd)
		{
			count += 1;
		}
	
	
		if(count > 0)
		{
		printf("\t\t\t\t\t\tPlease enter Valid dates!!\n");
		printf("\t\t\t\t\t\tEnter your date of your journey(00/00/0000)    : ");
		scanf("%d/%d/%d", &date1.dd, &date1.mm, &date1.yy);

		printf("\t\t\t\t\t\tEnter today's date(00/00/0000)                 : ");
		scanf("%d/%d/%d", &date2.dd, &date2.mm, &date2.yy);
		}
		else 
		{
			check = 0;
		}
	}
	
	printf("\n\t\t\t\t\tThe buses available at your selected date are listed below     ");	
	printf("\n\n");
	flag = check_cities(dep,dest);

	if (flag > 0)	
	{
		int busc;
		printf("\n\t\t\t\t\tEnter the serial number corresponding to your desired bus  : ");
		scanf(" %d", &busc);
	
		printf("\n\t\t\t\t\tThe available seats in the selected bus are : \n");	
		int a = seat(busc);
		if(a != 0){
		float price;
	
		char ac;
		char kms[5];
		char sleep;
		
		FILE *fp1;
		char arr[MAX];
		fp1=fopen("data.txt","r");
		int j=0;
		while(fgets(arr,MAX,fp1))
		{
				char arr1[1];
				arr1[0]=arr[0];
				if(atoi(arr1)==(busc))
				{
					if(arr[39]=='Y')
					{
						ac='Y';
					}
					else if(arr[39]=='N')
					{
						ac='N';
					}

					if(arr[41]=='Y')
					{		
						sleep='Y';
					}
					else if(arr[41]=='N')
					{
						sleep='N';
					}

					for(int i=43;i<strlen(arr);i++)
					{
						kms[j]=arr[i];
						j++;
					}
					break;
				}
			}
		fclose(fp1);
		price=priceCalculator(date1,date2,sleep,ac,num_seats,atoi(kms));
		printf("\n\t\t\t\t\tYour total fare for the journey is :  Rs. %f\n", price);
		}	
		}

	else
	{
		char s = 'Y';
		printf("\n\t\t\t\t\tThere are no buses available between your desired destinations.");
		printf("\n\t\t\t\t\tDo you want to book any more tickets(Y/N)  :");	
		while(1)
		{
		scanf(" %c", &s);
		if(s == 'Y' || s == 'y')
		{	
			book();
			break;
		}

		else if(s == 'N' || s == 'n')
		{
			menu();
			break;
		}

		else
		{
			printf("\n\t\t\t\t\tPlease enter a valid choice!(Y/N) : ");
		}
		}
		
	}

}
