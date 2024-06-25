
//////////////////////////////////////////////////////////////////////////////
/// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "Student.h"

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Destruktor für die Student-Klasse.
 *
 * Dieser Destruktor ist verantwortlich für das Aufräumen
 * aller Ressourcen, die das Student-Objekt während seiner Lebensdauer
 * möglicherweise erworben hat. Da es in der aktuellen Implementierung
 * keine dynamisch zugewiesenen Ressourcen gibt, ist der Destruktor leer.
 */
Student::~Student()
{}

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Gibt alle Daten des Studenten in einer Zeile aus
 */
void Student::ausgabe(ostream& outStream) const
{
	auto* ofs = dynamic_cast<std::ofstream*>(&outStream);
	if (ofs)
	{
        outStream << name << std::endl;
        outStream << matNr << std::endl;
        outStream << geburtstag << std::endl;
        outStream << adresse << std::endl;
	}
	else
	{
	    outStream << name << ", MatNr. " << matNr << ", geb. am "
	              << geburtstag << ", wohnhaft in " << adresse
	              << std::endl;
	}

}



bool Student::operator==(const Student& otherStudent) const {
	if (this->matNr == otherStudent.getMatNr()) return true;
	else return false;
}
bool Student::operator<(const Student& otherStudent) const {
	if (this->matNr < otherStudent.getMatNr()) return true;
	else return false;
}
bool Student::operator>(const Student& otherStudent) const {
	if (this->matNr > otherStudent.getMatNr()) return true;
	else return false;
}
bool Student::operator<=(const Student& otherStudent) const {
	if (this->matNr <= otherStudent.getMatNr()) return true;
	else return false;
}
bool Student::operator>=(const Student& otherStudent) const {
	if (this->matNr >= otherStudent.getMatNr()) return true;
	else return false;
}


ostream& operator<<(ostream& outStream, const Student& student) {
	student.ausgabe(outStream);

	return outStream;
}

