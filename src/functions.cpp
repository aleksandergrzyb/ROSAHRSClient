#include "functions.h"

/// przelicza stopnie na radiany
double deg2rad(double degree)
{
	return (degree*PI)/180;
}

/// zamienia kat w radianach na stopnie
double rad2deg(double angle)
{
	return (angle*180/PI);
}

/// zwraca wartosc bezwzgledna
float abs(float value)
{
	if (value>0) return value;
	else {
		value=-value;
		return value;
	}
}

/// wait
void wait(int ile){
	volatile float a=0.1234567;
	volatile float b=2.3456788;
	for (volatile int i=0 ; i<ile; i++){
		volatile float c=a*b;
	}
}

///znajduje maksimum w tablicy float
int findMax(float *table, int size, float * max_value){
	int max_iter=0;
	for(int i=1;i<size;i++) {
		if (table[i]>table[max_iter]) {
			max_iter = i;
		}
	}
	*max_value=table[max_iter];
	return max_iter;
}

///znajduje maksimum w tablicy float (wartosc bezwzgledna)
int findAbsMax(float *table, int size, float * max_value){
	int max_iter=0;
	for(int i=1;i<size;i++) {
		if (abs(table[i])>abs(table[max_iter])) {
			max_iter = i;
		}
	}
	*max_value=abs(table[max_iter]);
	return max_iter;
}

///znajduje minimum w tablicy float
int findMin(float *table, int size, float * max_value){
	int min_iter=0;
	for(int i=1;i<size;i++) {
		if (table[i]<table[min_iter]) {
			min_iter = i;
		}
	}
	*max_value=table[min_iter];
	return min_iter;
}

///znajduje minimum w tablicy float (wartosc bezwzgledna)
int findAbsMin(float *table, int size, float * max_value){
	int min_iter=0;
	for(int i=1;i<size;i++) {
		if (abs(table[i])<abs(table[min_iter])) {
			min_iter = i;
		}
	}
	*max_value=abs(table[min_iter]);
	return min_iter;
}

///funkcja do zaokraglania
int my_round (double x) {
  int i = (int) x;
  if (x >= 0.0) {
    return ((x-i) >= 0.5) ? (i + 1) : (i);
  } else {
    return (-x+i >= 0.5) ? (i - 1) : (i);
  }
} 
