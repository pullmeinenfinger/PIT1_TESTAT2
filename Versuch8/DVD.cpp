
/**
 * DVD.cpp
 *
 *  Created on: 12 Jun 2024
 *      Author: baris
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre):
	Medium(initTitel),
	altersfreigabe(initAltersfreigabe),
	genre(initGenre)
{

}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	if ((ausleihdatum - person.getGeburtsdatum())  < (altersfreigabe * 12))
	{
		cout << "Die ausleihende Person ist nicht alt genug für diese DVD." << endl;
		return false;
	}
	else
	{
		return Medium::ausleihen(person, ausleihdatum);
	}
}

void DVD::ausgabe(ostream& outStream) const
{
	/**
ID: 2
Titel: Der unsichtbare Dritte
Status: Medium ist zurzeit nicht verliehen.
FSK: ab 12 Jahre
Genre: Action, Krimi
	 */
	Medium::ausgabe(outStream);
	outStream << "FSK: ab " << altersfreigabe << " Jahre" << endl;
	outStream << "Genre: " << genre << endl;
}

DVD::~DVD()
{
}


