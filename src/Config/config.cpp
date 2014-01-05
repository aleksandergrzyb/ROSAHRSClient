
#include "config.h"
#include <stdio.h>
#include <string.h>


CConfig::CConfig(void){

}

CConfig::~CConfig(void){

}

///odczytuje wartosc tablicy na podstawie wiersza odczytanego z pliku
bool CConfig::readInt2DArrayValue(char * str,const char * table_name, int **table){
    char tbl_name[50];
    int x1,x2,value;
    sscanf (str,"%s (%d,%d) = %d",tbl_name,&x1,&x2,&value);
    if (strcmp(table_name,tbl_name)==0){
	table[x1][x2]=value;
    }
    else
	return false;
    return true;
}

///odczytuje wartosc parametru
bool CConfig::readParam(char * str,char * param_name, float * value){
    sscanf (str,"%s = %f",param_name,value);
    return true;
}

/// odczytuje parametry robota
void CConfig::readParameters(const char * filename){
    char str[200], param_name[50];//wiersz z pliku
    float value;
    FILE * file = fopen(filename,"r"); //otwieramy plik do odczytu
    if (file!=NULL) {//jezeli udalo się otworzyc plik
	while (fgets (str, 200, file)) {
	    if ((str[0]!='#')&&(str[0]!=' ')&&(str[0]!='$')&&(str[0]!='\n')&&(str[0]!='\r')){
		readParam(str, param_name, &value);
		if (strcmp(param_name,"RESET_DELTA_ANGLE")==0)
		    RESET_DELTA_ANGLE = value;
		//else if (strcmp(param_name,"SEGMENT_2")==0)
		  //  SEGMENT_2 = value;
		else
		    printf("\nUnknown parameter: %s!\n",str);
	    }
	}
	fclose(file);
    }
}

/// zwraca wartosc parametru
float CConfig::readParameter(const char *param_name, int idx1, int idx2){
	if (strcmp(param_name,"RESET_DELTA_ANGLE")==0)
	    return RESET_DELTA_ANGLE;
	//else if (strcmp(param_name,"SEGMENT_2")==0)
	  //  return SEGMENT_2;
	else
	    printf("\nUnknown parameter: %s!\n",param_name);
	return -1;
}