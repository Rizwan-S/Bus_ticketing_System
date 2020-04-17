#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"
#include"1.h"
#include"3.h"
#include"4.h"
#include"5.h"
#include"6.h"

//function to compute the number of days between the two days
//algo:
//year*365 + number of days currently over in year + number of leap years to accomodate extra days
//leap year calculation when month of feb is already crossed:
//yy/4-yy/100+yy/400 else if m<=2 then we replace yy with yy-1
//defining the structure for date as it forms the basis of all calculations and
//such for the pricing functions and calendar function.

int cal[24][64];
struct date
        {
            int dd;
            int mm;
            int yy;
        }date1, date2;

//function to relate month with number of days in the month.
int days(int mm)
        {
            int days = 0;
            switch (mm)
        {
            case 1:
                days = 31;
                break;
            case 2:
                days = 28;
                break;
            case 3:
                days = 31;
                break;
            case 4:
                days = 30;
                break;
            case 5:
                days = 31;
                break;
            case 6:
                days = 30;
                break;
            case 7:
                days = 31;
                break;
            case 8:
                days = 31;
                break;
            case 9:
                days = 30;
                break;
            case 10:
                days = 31;
                break;
            case 11:
                days = 30;
                break;
            case 12:
                days = 31;
                break;
        }
        return days;
        }


//this function is used to populate a calendar using the start date given
//this helps in the fact that we need not manually check for saturdays and sundays
//to mark as holiday
//in the future it'll also be able to read a holiday list and mark them as holidays on the calendar
void Calendar(int start)
{
    for (int i = 0;i < 24;i++)
    {
        for(int j = 0; j < 64; j++)
        {
            cal[i][j] = 0;
        }
    }
    for (int i = 1;i <= 12;i++)
    {
        cal[i-1][0] = 2019;
        cal[i-1][1] = i;
    }
    for(int i = 13;i <= 24; i++)
    {
        cal[i-1][0] = 2020;
        cal[i-1][1] = i-12;
    }
    int day[7] = {1,2,3,4,5,6,7};//array to store days-M-1,T-2,W-3,T-4,F-5,S-6,S-7
    int j = start;
    for(int month = 1;month <= 12; month++)
    {
        int i = 2;
        for(i = 2;i < days(month)+2;i++)
        {
            if(j < 8)
            {
                cal[month-1][i] = j;
                j++;
            }
            else
            {
                j = j-7;
                cal[month-1][i] = j;
                j++;
            }
        }
        while(i < 32)
        {
            cal[month-1][i] = 0;
            i++;
        }
    }
    for(int i = 1; i <= 12; i++)
        {
            int j = 33;
            for(j = 33;j < days(i)+33;j++)
            {
                if(cal[i-1][j-31] == 6 || cal[i-1][j-31] ==7)
                {
                    cal[i-1][j] = 2;//flagging holiday
                }
                else
                {
                    cal[i-1][j] = 1;//lower flag
                }
            }
            while(j < 64)
            {
                cal[i-1][j] = 0;
                j++;
            }
        }
    for(int month = 1;month <= 12; month++)
    {
        int i = 2;
        for(i = 2;i < days(month)+2;i++)
        {
            if(j < 8)
            {
               cal[month-1+12][i] = j;
               j++;
            }
            else
            {
                 j = j-7;
                 cal[month-1+12][i] = j;
                 j++;
            }
        }
        while(i < 32)
        {
            cal[month-1+12][i] = 0;
            i++;
        }
    }
    for(int i = 1; i <= 12; i++)
    {
        int j = 33;
        for(j = 33;j < days(i)+33;j++)
        {
            if(cal[i-1+12][j-31] == 6 || cal[i-1+12][j-31] ==7)
            {
                cal[i-1+12][j] = 2;//flagging holiday
            }
            else
            {
                cal[i-1+12][j] = 1;//lower flag
            }
        }
        while(j < 64)
        {
            cal[i-1+12][j] = 0;
            j++;
        }
    }

}


//this function checks if it s an almost last date booking in order to increase the price
//accordingly
long int dateDiff(struct date date1,struct date date2)
{
    int leapYr1;
    if(date1.mm>2)
    {
        leapYr1 = date1.yy/4 - date1.yy/100 + date1.yy/400;
    }
    else
    {
        leapYr1 = (date1.yy-1)/4 - (date1.yy-1)/100 + (date1.yy-1)/400;
    }
    int prevDays1 = 0;

    for(int i = 1;i < date1.mm;i++)
    {
         prevDays1 += days(i);
    }
    prevDays1 += date1.dd;
    long int totalDays1 = prevDays1+date1.yy*365+leapYr1;
    int leapYr2;
        if(date2.mm>2)
        {
            leapYr2 = date2.yy/4 - date2.yy/100 + date2.yy/400;
        }
        else
        {
            leapYr2 = (date2.yy-1)/4 - (date2.yy-1)/100 + (date2.yy-1)/400;
        }
    int prevDays2 = 0;
    for(int i = 1;i < date2.mm;i++)
    {
        prevDays2 += days(i);
    }
    prevDays2 += date2.dd;
    long int totalDays2 = prevDays2+date2.yy*365+leapYr2;
    return abs(totalDays2-totalDays1);
}

//this function is made to find if there are continuous holidays near the booked date
//as demand increases during such days and prices would increase
int checkHoliday(struct date date1)
{
    int day1 = 0;
    int day2 = 0;
    int day3 = 0;
    if(date1.yy == 2019)
    {
        if(date1.dd < 30)
        {
            day1 = (cal[date1.mm-1][33+date1.dd-1]);
            day2 = (cal[date1.mm-1][33+date1.dd]);
            day3 = (cal[date1.mm-1][33+date1.dd+1]);
        }
        else
        {
            switch (date1.dd)
            {
                case 30:
                    day1 = (cal[date1.mm-1][33+date1.dd-1]);
                    day2 = (cal[date1.mm-1][33+date1.dd]);
                    day3 = (cal[date1.mm][33]);
                    break;
                case 31:
                    day1 = (cal[date1.mm-1][33+date1.dd-1]);
                    day2 = (cal[date1.mm][33]);
                    day3 = (cal[date1.mm][34]);
                    break;
                default:
                    printf("Invalid Input");
            }
        }
    }
    else
    {
        if(date1.dd < 30)
        {
             day1 = (cal[date1.mm-1+12][33+date1.dd-1]);
             day2 = (cal[date1.mm-1+12][33+date1.dd]);
             day3 = (cal[date1.mm-1+12][33+date1.dd+1]);
        }
        else
        {
              switch (date1.dd)
              {
                   case 30:
                        day1 = (cal[date1.mm-1+12][33+date1.dd-1]);
                        day2 = (cal[date1.mm-1+12][33+date1.dd]);
                        day3 = (cal[date1.mm+12][33]);
                        break;
                   case 31:
                        day1 = (cal[date1.mm-1+12][33+date1.dd-1]);
                        day2 = (cal[date1.mm+12][33]);
                        day3 = (cal[date1.mm+12][34]);
                        break;
                   default:
                        printf("Invalid Input");
              }
        }
    }
    int counter = 0;
    if(day1 == 2)
    {
        counter += 1;
    }
    if(day2 == 2)
    {
        counter += 1;
    }
    if(day3 == 2)
    {
        counter += 1;
    }
    return counter;
}

//this function is the final calculator
//replicates a surge pricing function at a small level as it increases the price dynamically when
//the date is very close to holidays as demand would be high.
//the whole pricing program is also so made that in the future we would be able to add holidays at will
//remove holidays and all such spontaneous changes can be made with the smallest of tech support.
float priceCalculator(struct date date1,struct date date2,char seatType,char ac,int numSeats,int kms)
{
    float multiplier = 1;
    int holidays = checkHoliday(date1);

    long int diff = dateDiff(date1,date2);
    for(int i = 1;i <= 5-diff;i++)
    {
        multiplier += 0.02*multiplier;
    }
    if(ac == 'Y')//
    {
        multiplier += 0.4;
    }
    if(seatType == 'Y')
    {
        multiplier += 0.2;
    }
    float price = kms*1.15;
  
    //to increase price during holidays we use the holiday counter above to increase multiplier
    multiplier += holidays*(0.2);
    price *= multiplier;
    float finalPrice = price*numSeats;//calculating total price for all seats
    return finalPrice;
}

