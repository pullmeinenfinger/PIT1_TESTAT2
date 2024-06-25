/**
 * Buch.cpp
 *
 *  Created on: 12 Jun 2024
 *      Author: baris
 */

#include "Buch.h"

using namespace std;

Buch::Buch(std::string initTitel, std::string initAutor):
	Medium(initTitel),
	autor(Person(initAutor, Datum()))
{

}

void Buch::ausgabe(ostream& outStream) const
{

	Medium::ausgabe(outStream);

	outStream << "Name des Autors: " << this->autor.getName() << endl;

}

Buch::~Buch()
{

}


