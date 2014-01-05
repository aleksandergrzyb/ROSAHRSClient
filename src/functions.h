
#include <math.h>
#include <stdio.h>

#define PI 3.14159265

/// wait
void wait(int ile);
/// przelicza stopnie na radiany
double deg2rad(double degree);
/// zamienia katy w radianach na stopnie
double rad2deg(double angle);
/// zwraca wartosc bezwzgledna
float abs(float value);
///znajduje maksimum w tablicy float
int findMax(float *max, int size, float * max_value);
///znajduje maksimum w tablicy float (wartosc bezwzgledna)
int findAbsMax(float *table, int size, float * max_value);
///znajduje minimum w tablicy float
int findMin(float *table, int size, float * max_value);
///znajduje minimum w tablicy float (wartosc bezwzgledna)
int findAbsMin(float *table, int size, float * max_value);
///funkcja do zaokraglania
int my_round(double x);