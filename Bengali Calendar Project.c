#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 1
int flag = 0;
void displayCalendar(FILE *calendar,int day,int year)
{
    int daysmonth, daycounter, month;
    fprintf(calendar,"             %d",year-593);
    for(month = 1; month <= 12; month++)
    {
        switch(month)
        {
        case 1:
            fprintf(calendar,"\n\nবৈশাখ");
            daysmonth = 31;
            break;
        case 2:
            fprintf(calendar,"\n\nজ্যৈষ্ঠ");
            daysmonth = 31;
            break;
        case 3:
            fprintf(calendar,"\n\nআষাঢ়");
            daysmonth = 31;
            break;
        case 4:
            fprintf(calendar,"\n\nশ্রাবণ");
            daysmonth = 31;
            break;
        case 5:
            fprintf(calendar,"\n\nভাদ্র");
            daysmonth = 31;
            break;
        case 6:
            fprintf(calendar,"\n\nআশ্বিন");
            daysmonth = 30;
            break;
        case 7:
            fprintf(calendar,"\n\nকার্ত্তিক");
            daysmonth = 30;
            break;
        case 8:
            fprintf(calendar,"\n\nঅগ্রহায়ণ");
            daysmonth = 30;
            break;
        case 9:
            fprintf(calendar,"\n\nপৌষ");
            daysmonth = 30;
            break;
        case 10:
            fprintf(calendar,"\n\nমাঘ");
            daysmonth = 30;
            break;
        case 11:
            fprintf(calendar,"\n\nফাল্গুন");
            daysmonth = (flag?31:30);
            break;
        case 12:
            fprintf(calendar,"\n\nচৈ্ত্র");
            daysmonth = 30;
            break;
        }

        fprintf(calendar,"\n\nSun Mon Tue Wed Thu Fri Sat\n");
        for(daycounter = 1; daycounter <= 1+day*4; daycounter++)
            fprintf(calendar," ");
        for(daycounter = 1; daycounter <= daysmonth; daycounter++)
        {
            fprintf(calendar,"%2d",daycounter);

            if((daycounter+day)%7>0)
                fprintf(calendar,"  ");
            else
                fprintf(calendar,"\n ");
        }
        day = (day + daysmonth)%7;
    }
}
int main ()
{
    int day, year, leapyear;
    FILE *calendar;
    calendar = fopen("Calendar1.txt","w");

    printf("Please input Year= ");
    scanf("%d",&year);
    year+=593;
    int x = (year-1)/4;
    int y = (year-1)/100;
    int z = (year-1)/400;
    day = (year+x-y+z)%7;
    if((year%4==0 && year%100!=0) ||(year%4==0))
    {
        flag = 1;
        day=( day + 104)%7;
    }
    else
        day=( day + 103)%7;


    displayCalendar(calendar, day, year);

}
