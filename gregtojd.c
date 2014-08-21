/* 
 * File:   gregtojd.c
 * Author: glitchmaker
 * gregtojd: code to translate Gregorian date to Julian day
 * Created on August 18, 2014, 5:51 PM
 */

#include <stdio.h>
#include <stdlib.h>

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
    printf ("Date in format YYYY/M/D:");
    scanf ("%d/%d/%f",&year,&month,&day);
    if (month <= 2){
        year-=1;
        month+=12;
    }
    printf("%f\n",convert(year,month,day));
    return (EXIT_SUCCESS);
}

