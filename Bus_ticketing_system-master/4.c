#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"
#include"2.h"
#include"3.h"
#include"1.h"
#include"5.h"
#include"6.h"

int timecheck(char time[])
{
	int len;
	len = strlen(time);
	if (len != 5 && len != 4)
	{
		printf("\t\t\t\t\t\t\t%s\n", "Invalid time input!");
		return 1;
	}
	if (len == 4)
	{
		int hours = atoi(&time[0]);
		int min = atoi(&time[2]);
		int temp = time[1];
		if ((min > 59) || (min < 0) || (hours > 9) || (hours < 0) || (temp != 58))
		{
			printf("\t\t\t\t\t\t\t%s\n", "Invalid time input!");
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if(len == 5)
	{
		int hours = atoi(&time[0]);
		int min = atoi(&time[3]);
		int temp = time[2];
		if((hours < 0) || (hours > 23) || (min < 0) || (min > 59) || (temp != 58))
		{
			printf("\t\t\t\t\t\t\t%s\n", "Invalid time input!");
			return 1;
		}
		else
		{
			return 2;
		}
	}
}

int placecheck(char place[])
{
	int len = strlen(place);
	if(len != 3)
	{
		return 1;
	}
	else
	{
	    return 2;
	}
}

void add_bus(void)
{
	FILE *fp, *fp1, *out;
	char bus_number[14];
	char boarding_city[4];
	char time_of_dep[6];
	char destination[4];
	char time_of_arr[6];
	char dur_of_journey[5];
	char AC[2];
	char SLEEPER[2];
	int distance;

 	printf("\t\t\t\t\t%s", "Bus number (eg XX-00-AA-0000)                    : ");
	scanf("%s", bus_number);
	upper_case_string(bus_number);

 	printf("\t\t\t\t\t%s", "Boarding city code (3 letter code)               : ");
	scanf("%s", boarding_city);
	int val = placecheck(boarding_city);
	if(val == 1)
	{
		while(val != 2)
		{
			printf("\t\t\t\t\t\t%s", "Please Input Valid City code             : ");
			scanf("%s", boarding_city);
			val = placecheck(boarding_city);
		}
	}
	upper_case_string(boarding_city);

	printf("\t\t\t\t\t%s", "Destination city code (3 letter code)            : ");
	scanf("%s", destination);
	val = placecheck(destination);
	if(val == 1)
	{
		while(val != 2)
		{
			printf("\t\t\t\t\t\t%s", "Please Input Valid City code             : ");
			scanf("%s", destination);
			val = placecheck(destination);
		}
	}
	upper_case_string(destination);

	printf("\t\t\t\t\t%s", "Time of departure (24 hrs format(hh:mm))         : ");
	scanf("%s", time_of_dep);
	val = timecheck(time_of_dep);
	if(val == 1)
	{
		while(val != 2)
		{
			printf("\t\t\t\t\t\t%s", "Please Input Valid Time                  : ");
			scanf("%s", time_of_dep);
			val = timecheck(time_of_dep);	
		}
	}
	if (strlen(time_of_dep)==4)
	{
		time_of_dep[4]= ' ';
		time_of_dep[5]= '\0';
	}

	printf("\t\t\t\t\t%s", "Time of arrival (24 hrs format(hh:mm))           : ");
	scanf("%s", time_of_arr);
	val = timecheck(time_of_arr);
	if(val == 1)
	{
		while(val != 2)
		{
			printf("\t\t\t\t\t\t%s", "Please Input Valid Time                  : ");
			scanf("%s", time_of_arr);
			val = timecheck(time_of_arr);	
		}
	}
	if (strlen(time_of_arr)==4)
	{
		time_of_arr[4]= ' ';
		time_of_arr[5]='\0';
	}


	printf("\t\t\t\t\t%s", "Duration of journey (approx. in hours)           : ");
	scanf("%s", dur_of_journey);
	if (strlen(dur_of_journey)==1)
	{
		dur_of_journey[1]= ' ';
	}

	printf("\t\t\t\t\t%s\n", "\n\t\t\t\t\t			Type of Bus                \n");
	
	printf("\t\t\t\t\t%s", "Is the Bus type AC (Y for yes and N for no)      : ");
	scanf("%s", AC);
	upper_case_string(AC);
	while((AC[0] != 'Y') && (AC[0] != 'N'))
	{
		printf("\t\t\t\t\t\t%s", "Please input (Y/N)                       :");
		scanf("%s", AC);
		upper_case_string(AC);
	}

	printf("\t\t\t\t\t%s", "Is the bus type SLEEPER (Y for yes and N for no) : ");
	scanf("%s", SLEEPER);
	upper_case_string(SLEEPER);
	while((SLEEPER[0] != 'Y') && (SLEEPER[0] != 'N'))
	{
		printf("\t\t\t\t\t\t%s", "Please input (Y/N)                       : ");
		scanf("%s", SLEEPER);
		upper_case_string(SLEEPER);
	}
	
	printf("\t\t\t\t\t%s", "Enter the distance between the cities (in km)    : ");
	scanf("%d", &distance);
	
	fp = fopen("data.txt", "a+");
	int linesCount = 0;
	char ch;

	while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')
            linesCount++;
    }
    fclose(fp);

    fp = fopen("data.txt", "r");
    char line[70];

    for(int i = 0; i < linesCount; i++)
    {
    	fgets(line, 70, fp);
    }

    char ind[3];
    int index;
    char d = line[0];
    ind[0] = d;
    index = atoi(ind);
    index++;
    
    fclose(fp);

    fp = fopen("data.txt", "r");
	int check = 0;

	while ( fgets(line, 70, fp) != NULL ) 
    {
        if(strstr(line, bus_number))
		{
			printf("\n\t\t\t\t\t%s\n\n", "The bus is currently in service. The details are as follows:");
			check = 1;
			break;
		}	
    }
    fclose(fp);

    fp = fopen("data.txt", "a");
    
	if(check == 0)
	{
		fprintf(fp, "%d %s %s %s %s %s %s %s %s %d\n", index, bus_number, boarding_city, destination, time_of_dep,  time_of_arr, dur_of_journey, AC, SLEEPER, distance);
		printf("\n\t\t\t\t\tNew bus has been added successfully! Bus details are as follows : \n\n");
	}

	fclose(fp);

	fp = fopen("data.txt", "r");

	while ( fgets(line, 70, fp) != NULL ) 
    {
		if(strstr(line, bus_number))
		{
			printf("\nS.no. Bus no.\t\tDeparture city  Arrival city  Time of Departure  Time of Arrival  Duration(in hr)  AC  Sleeper  Distance(km)\n\n");
			display_details(line);
			break;
		}	
    }

	fclose(fp);
	
	char buffer[5];
	sprintf(buffer, "%d", index);
	char* extension = ".txt";
    char fileSpec[strlen(buffer)+strlen(extension)+1];
	snprintf( fileSpec, sizeof( fileSpec ), "%s%s", buffer, extension );
	out = fopen( fileSpec, "w" );
    fclose(out);

}

void delete_bus(void)
{
	FILE *fp1;
	FILE *fp2;
	char line[70];
	char bus_number[14];
	char temp[70];

	printf("%s", "\t\t\t\t\tEnter the Bus number to remove (eg XX-00-AA-0000) : ");
	scanf("%s", bus_number);
	upper_case_string(bus_number);

	fp1 = fopen("data.txt", "r");
	fp2 = fopen("updated.txt", "w");
	
	int check = 0;
	while(fgets(line, 70, fp1) != NULL  && check == 0)
	{
		if(strstr(line , bus_number))
		{
			rewind(fp1);
			while((fgets(temp, 70, fp1)) != NULL)
			{
				if(strstr(temp, line) == NULL)
				{
					fputs(temp, fp2);
				}
			}

			printf("%s\n", "\n\t\t\t\t\t\tThe Bus has been removed from service successfully!\n");
			check = 1;
		}
	}

	if(check == 0)
	{	
		printf("%s\n", "\n\t\t\t\t\t\t  The given bus is not in service.");
	}
	fclose(fp1);
	fclose(fp2);
	if(check == 1)
	{
		remove("data.txt");
		rename("updated.txt", "data.txt");
	}
}
