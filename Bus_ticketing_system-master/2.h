struct date
        {
            int dd;
            int mm;
            int yy;
        };
int days(int mm);
void Calendar(int start);
long int dateDiff(struct date date1,struct date date2);
int checkHoliday(struct date date1);
float priceCalculator(struct date date1 ,struct date date2, char seatType,char ac,int numSeats,int kms);
