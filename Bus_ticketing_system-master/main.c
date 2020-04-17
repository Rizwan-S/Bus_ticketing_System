#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"1.h"
#include"2.h"
#include"3.h"
#include"4.h"
#include"5.h"
#include"6.h"

void menu(void)
{
    char quit = 'Y';
    char response[2];
    char destination[4];
    char boarding[4];

	int choice;
	printf("\n\t\t\t\t\t\t    WELCOME TO BUS TICKETING SYSTEM");
	printf("\n\n\t\t\t\t\t\t\t1. Display all buses");
	printf("\n\t\t\t\t\t\t\t2. Display all cities");
	printf("\n\t\t\t\t\t\t\t3. Display all buses from required city");
	printf("\n\t\t\t\t\t\t\t4. Display all buses to required city");
	printf("\n\t\t\t\t\t\t\t5. Book ticket");
	printf("\n\t\t\t\t\t\t\t6. Cancel ticket");
	printf("\n\t\t\t\t\t\t\t7. Add a Bus");
	printf("\n\t\t\t\t\t\t\t8. Delete a Bus");
	printf("\n\t\t\t\t\t\t\t9. Quit program");

    while (quit == 'Y')
    {
        printf("\n\n\t\t\t\t\t\t      ENTER YOUR CHOICE : ");
	    scanf("%d", &choice);
        switch(choice)
	    {
            case 1:
                display_all_buses();
                break;
            case 2:
                departure_cities();
                arrival_cities();
                break;
            case 3:
                printf("\n");
                printf("%s", "\t\t\t\t\t\tBoarding city code (3 letter code) : ");
                scanf("%s", boarding);
                upper_case_string(boarding);
                int val = placecheck(boarding);
                if(val == 1)
                {
                    while(val != 2)
                    {
                        printf("%s", "\n\t\t\t\t\t\t  Please Input Valid City code: ");
                        scanf("%s", boarding);
                        val = placecheck(boarding);
                    }
                }
                boarding_city(boarding);
                break;
            case 4:
                printf("\n");
                printf("%s", "\t\t\t\t\t\tDestination city code (3 letter code) : ");
                scanf("%s", destination);
                upper_case_string(destination);
                val = placecheck(destination);
                if(val == 1)
                {
                    while(val != 2)
                    {
                        printf("%s", "Please Input Valid City code: ");
                        scanf("%s", destination);
                        val = placecheck(destination);
                    }
                }
                destination_city(destination);
                break;
            case 5:
                book();
                break;
            case 6:
                cancel_ticket();
                break;
            case 7:
                printf("\n");
                add_bus();
                break;
            case 8:
                printf("\n");
                delete_bus();
                break;
            case 9:
                printf("\n\t\t\t\t\t\t    Thank you for using this System!!\n\n");
                exit(0);
                break;
            default:
                printf("\n\t\t\t\t\t\t    Please Enter a Valid Choice!!");
                printf("\n");
                menu();
                break;
	    }
    
        printf("\n\t\t\t\t\tWould you like to continue (Y for yes and N for no) : ");
        while(1)
        {
            scanf(" %c",response);
            upper_case_string(response);
            if (response[0] == 'Y' || response[0] == 'N')
            {
                quit = response[0];
                break;
            }
            else
            {
                printf("\n\t\t\t\t\t\tPlease Enter valid choice (Y/N) : ");
            }
        }        
    }

printf("\n\t\t\t\t\t\t    Thank you for using this System!!\n\n");
}

int main()
{
    menu();
    return 0;   
}

