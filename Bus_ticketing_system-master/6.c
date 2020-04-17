#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"
#include"2.h"
#include"3.h"
#include"4.h"
#include"5.h"
#include"1.h"
#define MAX 50 

int check_cities(char from_city[],char to_city[])
{
        FILE *fp;
        char str[MAX];
        int flag = 0;
        fp=fopen("data.txt","r");
        printf("\nS.no. Bus no.\t\tDeparture city  Arrival city  Time of Departure  Time of Arrival  Duration(in hr)  AC  Sleeper  Distance(km)\n\n");
        while(fgets(str,MAX,fp))
        {
                if((str[16]==from_city[0] && str[17]==from_city[1] && str[18]==from_city[2]) && (str[20]==to_city[0]&& str[21]==to_city[1] && str[22]==to_city[2]))
                {
                        display_details(str);
                        flag++;
                }
        }
        if (flag == 0)
                printf("\t\t\t\t\tCurrently there are no buses on this route\n");
        fclose(fp);
        return flag;
}

void boarding_city(char city[])
{
        FILE *fp;
        char str[MAX];
        int flag = 0;
        fp=fopen("data.txt","r");
        printf("\nS.no. Bus no.\t\tDeparture city  Arrival city  Time of Departure  Time of Arrival  Duration(in hr)  AC  Sleeper  Distance(km)\n\n");
        while(fgets(str,MAX,fp))
        {
                if(str[16]==city[0] && str[17]==city[1] && str[18]==city[2])
                {
                        display_details(str);
                        flag++;
                }
        }
        if (flag == 0)
                printf("\t\t\t\t\tCurrently there are no buses on this route\n");
        fclose(fp);
}

void destination_city(char city[])
{
	FILE *fp;
	char str[MAX];
        int flag = 0;
	fp=fopen("data.txt","r");
        printf("\nS.no. Bus no.\t\tDeparture city  Arrival city  Time of Departure  Time of Arrival  Duration(in hr)  AC  Sleeper  Distance(km)\n\n");
	while(fgets(str,MAX,fp))
	{
		if(str[20]==city[0] && str[21]==city[1] && str[22]==city[2])
		{
                        display_details(str);
                        flag++;
		}
	}
        if (flag == 0)
                printf("\t\t\t\t\t\t    Currently there are no buses on this route\n");
	fclose(fp);
}

