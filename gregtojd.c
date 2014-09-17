/* 
 * File:   gregtojd.c
 * Author: glitchmaker
 * gregtojd: code to translate Gregorian date to Julian day
 * Created on August 18, 2014, 5:51 PM
 */

#include <stdio.h>
#include <stdlib.h>

double julian_centuries(double jd)
{
    
}
double hms2deg(int h, int m, double sec){
    return (9+((double)m/60)+((double) sec/3600))*15;
}
/*Function */
double UT2Gree(double julianDate)
{
    T=(julianDate - 2451545.0)/36525;
    
}


/*Function hms2secs
 Inpus:
        int hour - 0 to 23
        int min  - 0 to 59
        int seconds
 Returns the total number of seconds*/
int hms2secs(int hour,int min, int seconds){
    int result =0;
    result = (hour*3600)+(min*60)+seconds;
    return result;
}
/*Convert - converts a gregorian date to a Julian Day
  Inputs:
        int y - gregorian year
        int m - month
        double d- day and its fractions EX: noon of day 12 is 12.5*/
double convert(int y, int m, double d){
    int a=0;
    int b =0;
    int c =0;
    int e =0;
    int f =0;
    double jd =0;
    
    a = y /100;
    b = a/4;
    c = 2 - a + b;
    e = (int)(365.25 * (y+4716));
    f = (int)(30.6001 * (m+1));
    jd =c + d + e + f - 1524.5;
    return jd;
}
int main(int argc, char** argv) {
    int year=0;
    int month =0;
    float day = 0.0;
    int hours=0;
    int minutes =0;
    float seconds = 0.0;
    while(year > -4713){
    printf ("Date in format YYYY/M/D:");
    scanf ("%d/%d/%f",&year,&month,&day);
    if (month <= 2){
        year-=1;
        month+=12;
    }
    printf("%f\n",convert(year,month,day));
    }
    printf("Right ascention in xxHxxMxxS:");
    scanf("%dH%dM%fS",&hours,&minutes,&seconds);
    printf("Degrees:%f",hms2deg(hours,minutes,seconds));
    return (EXIT_SUCCESS);
}

