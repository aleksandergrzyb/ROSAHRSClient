/*
* simple parser for config files
* Author: Dominik Belter 
* Poznan University of Technology
* Institute of Control and Information Engineering
* www: www.walkingrobots.pl
* e-mail: dominik.belter@put.poznan.pl
* created: 10.2009, last updated: 02.2010
*/

#ifndef CCONFIG_H
#define CCONFIG_H

class CConfig
{
    public:
	CConfig(void);
	~CConfig(void);
	/// odczytuje wartosc tablicy na podstawie wiersza odczytanego z pliku
	bool readInt2DArrayValue(char * str,const char * table_name, int **table);
	/// odczytuje wartosc parametru
	bool readParam(char * str,char * param_name, float * value);
	/// odczytuje parametry robota
	void readParameters(const char * filename);
	/// zwraca wartosc parametru
	float readParameter(const char *param_name, int idx1=-1, int idx2=1);

    //zmienne
    private:
	/// maksymalna predkosc zmian kata przy resetowaniu IMU [stopnie]
	float RESET_DELTA_ANGLE;
};

#endif