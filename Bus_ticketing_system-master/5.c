#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"
#include"2.h"
#include"3.h"
#include"4.h"
#include"1.h"
#include"6.h"

void display_seats(char arr[][9])
{	
	for(int j=0;j<20;j++)
	{
		for (int i=0;i<9;i++)
		{	
			printf("%c",arr[j][i]);
			if(j==1 || j==5 ||j== 9 ||j== 13 ||j== 17)
			{
				if(i==8)
				{
					printf("\t\t");
				}
			}				
			if(i==8)
			{
				printf("\t");
			}	
			if(j==3 || j==7|| j==11 || j==15 ||j== 19) 
			{
				if (i==8)
				{
					printf("\n");
				}
			}
		}
	}
}	

void cancel_ticket(void)
{
	display_all_buses();
	int bus_number;
	printf("\n\t\t\t\t\tEnter the bus Serial Number to cancel ticket : ");
	scanf("%d", &bus_number);
	FILE *bus;
	char buffer[10];
	sprintf(buffer, "%d", bus_number); 
	strcat(buffer,".txt");
	bus = fopen(buffer, "r");
	char arr[50][9]={"EMPTY(01)","EMPTY(02)","EMPTY(03)","EMPTY(04)","EMPTY(05)","EMPTY(06)","EMPTY(07)","EMPTY(08)","EMPTY(09)","EMPTY(10)","EMPTY(11)","EMPTY(12)","EMPTY(13)","EMPTY(14)","EMPTY(15)","EMPTY(16)","EMPTY(17)","EMPTY(18)","EMPTY(19)","EMPTY(20)"};
	int num_of_seats;
	int final_arr[5000];

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
	
	int cncl, ar[40];
	printf("\n\t\t\t\tHow many tickets do you want to cancel : ");
	scanf(" %d", &cncl);
	printf("\n\t\t\t\tEnter the seat number you want to cancel : ");
	for(int i = 0; i < cncl; i ++)
	{		
		scanf("%d", &ar[i]);
	}
	for (int i=0;i<cncl;i++)
	{	
		if(ar[i]>=1 && ar[i]<=9)
		{
			arr[ar[i]-1][0]='E';
			arr[ar[i]-1][1]='M';
			arr[ar[i]-1][2]='P';
			arr[ar[i]-1][3]='T';
			arr[ar[i]-1][4]='Y';
			arr[ar[i]-1][5]='(';
			arr[ar[i]-1][6]='0';
			arr[ar[i]-1][7]=ar[i] + '0';
			arr[ar[i]-1][8]=')';
		}
		else if(ar[i]>=10 && ar[i] < 20)
		{
			arr[ar[i]-1][0]='E';
			arr[ar[i]-1][1]='M';
			arr[ar[i]-1][2]='P';
			arr[ar[i]-1][3]='T';
			arr[ar[i]-1][4]='Y';
			arr[ar[i]-1][5]='(';
			arr[ar[i]-1][6]='1';
			arr[ar[i]-1][7]= ar[i]%10 +'0';
			arr[ar[i]-1][8]=')';
		}
		else if(ar[i] == 20)
		{
			arr[ar[i]-1][0]='E';
			arr[ar[i]-1][1]='M';
			arr[ar[i]-1][2]='P';
			arr[ar[i]-1][3]='T';
			arr[ar[i]-1][4]='Y';
			arr[ar[i]-1][5]='(';
			arr[ar[i]-1][6]='2';
			arr[ar[i]-1][7]='0';
			arr[ar[i]-1][8]=')';
		}
	}	
	display_seats(arr);
	FILE *fp2;
	fp2 = fopen("buffc.txt", "w+");
	for(int i = 0; i < bookes_seats;  i++)
	{
		int j;
		for(j = 0; j < cncl; j++)
		{
			if(final_arr[i] == ar[j])
			{
				break;
			}
		}
		if(j == cncl && final_arr[i] != 0)
		{
			fprintf(fp2, "%d ", final_arr[i]);
		}
	}
	remove(buffer);
	rename("buffc.txt", buffer);
	fclose(fp2);
	fclose(bus);
}
