/*C program to calculate age in terms of number of days ,months and years*/
#include <stdio.h>
#include <time.h>

int is_leap_year(int year, int month)
{
    int check = 0;

	if (year % 4 == 0)
    {
		  if (month == 2)
		  {
				check = 1;
		  }
    }
    return (check);
}


int main()
{
	//number of  days in months from January to December respectively
    int num_of_days_in_months[] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};

    int day = 0, month = 0, year = 0;

    time_t time_in_sec = 0;
    struct tm *current_time = NULL;

    printf("Please enter your date of birth in (DD/MM/YYYY) format: ");
    scanf("%d/%d/%d",&day,&month, &year);

    time_in_sec = time(NULL);
    current_time = localtime(&time_in_sec);//returns pointer to a tm structure

    /*tm_mon starts from 0 for january so 1 is added to it   and tm_year returns number of
    years since 1900 so 1900 is added to it*/
    printf("Current date is : %d/%d/%d\n",current_time ->tm_mday, current_time ->tm_mon + 1, current_time ->tm_year + 1900);

    /*calculating number of days left in the birth month*/
    day = num_of_days_in_months[month - 1] - day + 1;

    /* leap year checking*/
    if (is_leap_year(year, month))
    {
            day = day + 1;
    }

    /* calculating age in number of days, years and months */
    day = day + current_time->tm_mday;
    month = (12 - month) + (current_time->tm_mon);
    year = (current_time->tm_year + 1900) - year - 1;

    /* checking for leap year feb - 29 days */
    if (is_leap_year((current_time ->tm_year + 1900), (current_time ->tm_mon + 1)))
    {
            if (day >= (num_of_days_in_months[current_time->tm_mon] + 1))
            {
				 day = day - (num_of_days_in_months[current_time ->tm_mon] + 1);
				 month = month + 1;
            }
    }

    else if (day >= num_of_days_in_months[current_time ->tm_mon])
    {
            day = day - (num_of_days_in_months[current_time->tm_mon]);
            month = month + 1;
    }

    if (month >= 12)
    {
            year = year + 1;
            month = month - 12;
    }

    printf("\nCurrent age is %d years %d months and %d days\n", year, month, day);

    return 0;
}
