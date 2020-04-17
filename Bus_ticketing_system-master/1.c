#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"
#include"2.h"
#include"3.h"
#include"4.h"
#include"5.h"
#include"6.h"
#define MAX 50
#define MAX_CITIES 25

//Converts lower case string to upper case string  
void upper_case_string(char *s)
{
    for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
		}
	}
}

// Display all Details of the Buses
void display_details(char string[])
{
    int len = strlen(string);
    for(int i= 0; i<1; i++)
    {
        putchar(string[i]);
    }
    printf("     ");

    for(int i= 2; i<15; i++)
    {
        putchar(string[i]);
    }
    printf("     ");

    for(int i= 16; i<19; i++)
    {
        putchar(string[i]);
    }
    printf("\t\t");

    for(int i= 20; i<23; i++)
    {
        putchar(string[i]);
    }
    printf("\t      ");

    for(int i= 24; i<29; i++)
    {
        putchar(string[i]);
    }
    printf("\t\t ");

    for(int i= 30; i<35; i++)
    {
        putchar(string[i]);
    }
    printf("\t\t  ");

    for(int i= 36; i<38; i++)
    {
        putchar(string[i]);
    }
    printf("\t\t   ");

    for(int i= 39; i<40; i++)
    {
        putchar(string[i]);
    }
    printf("   ");

    for(int i= 41; i<42; i++)
    {
        putchar(string[i]);
    }
    printf("\t");

    for(int i= 43; i<len; i++)
    {
        putchar(string[i]);
    }
    printf("\n");
}

// Display details of all buses read from database into a table format 
void display_all_buses(void)
{
    FILE *fp;
    char line[MAX];
    fp = fopen("data.txt", "r");

    printf("\nS.no. Bus no.\t\tDeparture city  Arrival city  Time of Departure  Time of Arrival  Duration(in hr)  AC  Sleeper  Distance(km)\n\n");
    while(fgets(line, MAX, fp))
    {
        display_details(line);
    }

    fclose(fp);
}

//Find all the cities from database from where buses are departing
void departure_cities(void)
{
    FILE *fp;
    char line[MAX];
    char cities[MAX_CITIES][3];
    int flag = 0;
    int j =0;
    memset(cities, 'X', sizeof(cities));
    fp = fopen("data.txt", "r");
    printf("\n\t\t\t\t\t\t    Buses departing from cities: \n\n");
    while(fgets(line, 50, fp))
    {
        for (int i = 0; i<MAX_CITIES; i++)
        {
            if (cities[i][0] == line[16] && cities[i][1] == line[17] && cities[i][2] == line[18])
            {
                flag = 0;
                break;
            }
            else 
            {
                flag++;
            }
        }
        if (flag != 0)
        {
            cities[j][0] = line[16];
            cities[j][1] = line[17];
            cities[j][2] = line[18];
            j++;
        }
        
        flag =0;
    }

    for(int i =0; i<j; i++)
    {
        printf("\t\t\t\t\t\t\t        %c%c%c\n",cities[i][0],cities[i][1],cities[i][2]);
    }

    fclose(fp);
}

//Find all the cities from database from where buses are arriving
void arrival_cities(void)
{
    FILE *fp;
    char line[MAX];
    char cities[MAX_CITIES][3];
    int flag = 0;
    int j =0;
    memset(cities, 'X', sizeof(cities));
    fp = fopen("data.txt", "r");
    printf("\n\t\t\t\t\t\t    Buses arriving to cities: \n\n");
    while(fgets(line, 50, fp))
    {
        for (int i = 0; i<MAX_CITIES; i++)
        {
            if (cities[i][0] == line[20] && cities[i][1] == line[21] && cities[i][2] == line[22])
            {
                flag = 0;
                break;
            }
            else 
            {
                flag++;
            }
        }
        if (flag != 0)
        {
            cities[j][0] = line[20];
            cities[j][1] = line[21];
            cities[j][2] = line[22];
            j++;
        }
        
        flag =0;
    }

    for(int i =0; i<j; i++)
    {
        printf("\t\t\t\t\t\t\t        %c%c%c\n",cities[i][0],cities[i][1],cities[i][2]);
    }

    fclose(fp);
}

//Function to read numbers from database of buses
//Find the seat numbers of corresponding bus which are already booked  
int seat_numbers(int bus_number, int num_array[])
{
	FILE *bus;
	char buffer[10];
	sprintf(buffer, "%d", bus_number); 
	strcat(buffer,".txt");
	bus = fopen(buffer, "r");

    char booked_seats[MAX][3];
    int i = 0, j= 0;

    while(!feof(bus))
    {
        booked_seats[i][j] = fgetc(bus);

        if (booked_seats[i][j] == ' ')
        {
            j = 0; 
            i++;
        }
        else
        {
            j++;
        }
    }
    i++;

    for(int k=0; k<i; k++)
    {
        num_array[k] = atoi(booked_seats[k]);
    }
    fclose(bus);
    return i;
}
