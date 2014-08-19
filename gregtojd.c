/* 
 * File:   gregtojd.c
 * Author: glitchmaker
 * gregtojd: code to translate Gregorian date to Julian day
 * Created on August 18, 2014, 5:51 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

float convert(int year, int month, int day){
    int centuries=0;
    int b =0;
    int c =0;
    int e =0;
    int f =0;
    float jd =0;
    
    centuries = year /100;
    b = centuries/4;
    c = 2 - centuries - b;
    e = 365.25 * (year+4716);
    f = 30.6001 * (month-1);
    jd =c + day + e + f - 1524.5;
    return jd;
}
int main(int argc, char** argv) {
    int year=0;
    int month =0;
    int day = 0;
    printf ("Date in format YYYY/M/D:");
    scanf ("%d/%d/%d",&year,&month,&day);
    if (month==1 || month==2){
        year-=1;
    }
    printf("%f\n",convert(year,month,day));
    return (EXIT_SUCCESS);
}

