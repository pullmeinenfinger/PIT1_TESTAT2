/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 6: STL
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Student.h"

using namespace std;


/**
 * Function to check whether a student exists
 *
 * @param studentenListe A vector of Students
 * @param matNr The matNr of the Student, which should be checked
 */
bool studentExists(vector<Student>* studentenListe, unsigned int matNr) {

	for (const Student& i : *studentenListe) {
		if (i.getMatNr() == matNr) return true;
	}

	return false;
}


int main()
{
    vector<Student> studentenListe; ///init Datenbank als Liste
    vector<Student>* vectorZeig;
    vectorZeig = &studentenListe;
    vector<Student>::iterator it;
    Student student; ///Konstrukt

    ///Variablen
    char abfrage;
	string dateiname, name, geburtsdatum, adresse;
	unsigned int matNr;



    std::cout << "Wollen Sie Daten aus einer Datei einlesen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(1, '\n');


    if (abfrage == 'j') {

    	cout << "Geben sie nun Bitte den Dateinamen an (DEFAULT: 'studierende.txt'): ";
        getline(std::cin, dateiname);    // ganze Zeile einlesen inklusive aller Leerzeichen
        if (dateiname.empty()) dateiname = "studierende.txt";

        ifstream eingabe(dateiname);

        if (!eingabe)
        {
        	cout << " Fehler beim Lesen der Datei!";
            studentenListe.clear();
            delete vectorZeig;
            student.~Student();
        	exit(1) ;
        }

		while (!eingabe.eof())
        {
			eingabe >> matNr;
        	eingabe.ignore(1, '\n'); /// wegen >> Whitespaces einnimmt
        	getline(eingabe , name);
        	getline(eingabe , geburtsdatum);
        	getline(eingabe , adresse);

        	student = Student(matNr, name, geburtsdatum, adresse);
			student.ausgabe();

			studentenListe.push_back(student);///Datenbank
        }


    };

    do
    {
        std::cout << "\nMenü:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufügen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
                  << "(5): Datenelement löschen" << std::endl
                  << "(6): Datenelement vorne hinzufügen" << std::endl
                  << "(7): Datenelement hinten entfernen" << std::endl
                  << "(8): Daten aus einer Datei einlesen" << std::endl
                  << "(9): Daten in eine Datei abspeichern" << std::endl
                  << "(0): Beenden" << std::endl;

        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {

            /// Datenelement hinten hinzufügen
            /// wird als leztze hinzugefügt
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtsdatum = "";
                    std::string adresse = "";
                    it = studentenListe.end();

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen
                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtsdatum);
                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);
                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtsdatum, adresse);

                    studentenListe.insert(it , student);
                }
                break;


            /// Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        it = studentenListe.begin();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        it->ausgabe();
                        studentenListe.erase(it);
                    }
                    else
                    {
                        std::cout << "Die Liste ist schon leer!\n";
                    }
                }
                break;


            /// Datenbank vorwärts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for (vector<Student>::iterator it1 = studentenListe.begin() ; it1 != studentenListe.end(); ++it1)
                        it1->ausgabe();
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;


            /// Datenbank rückwärts ausgeben
            case '4':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in rücklaufender Reihenfolge:" << std::endl;
                    for (vector<Student>::reverse_iterator it1 = studentenListe.rbegin() ; it1 != studentenListe.rend(); ++it1)
						it1->ausgabe();
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;


            /// Datenelement löschen!!
            case '5':
            	{
            		unsigned int zahl = 0;
            		unsigned int untreffZahl = 0;
            		unsigned int matNrLoeschen;

					if(studentenListe.empty())
					{
						std::cout << "Die Liste ist leer!\n\n" << std::endl;
						break;
					}

					cout << "Bitte geben sie die Matrikelnummer an: " << endl;
					cin >> matNrLoeschen;

					for(vector<Student>::iterator it1 = studentenListe.begin(); it1 != studentenListe.end(); it1++)
					{
						zahl++;
						if (matNrLoeschen == it1->getMatNr())
						{
							cout << "Der folgende Student wurde geloescht:\n" << endl;
							it1->ausgabe();
							studentenListe.erase(it1);
							///kein break; , falls duplizierte Student
						}
						else
						{
							untreffZahl++;
							continue;
						}
					}

					if(untreffZahl == zahl)
					{
						cout << "Der Student wurde nicht gefunden...\n\n";
					}
					else
					{
						for(vector<Student>::iterator it1 = studentenListe.begin(); it1 != studentenListe.end(); it1++)
						{
							zahl = 0;
							untreffZahl = 0;
							zahl++;
							if (matNrLoeschen == it1->getMatNr())
							{
								cout << "/nDer Student konnte nicht gelöscht werden:\n" << endl;
								abfrage = 0;
								break;

							}
							else
							{
								untreffZahl++;
								continue;
							}
						}

						if(untreffZahl == zahl)
						{
							cout << "/nDer Student wurde erfolgreich gelöscht.\n\n";
						}
					}
            	}
                break;

            /// Datenelement vorne hinzufügen
            case '6':
            	{
            		unsigned int matNr = 0;
					std::string name = "";
					std::string geburtstag = "";
					std::string adresse = "";
					it = studentenListe.begin();

					std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
					getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

					std::cout << "Geburtsdatum: ";
					getline(std::cin, geburtstag);

					std::cout << "Adresse: ";
					getline(std::cin, adresse);

					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;
					std::cin.ignore(10, '\n');

					student = Student(matNr, name, geburtstag, adresse);

					studentenListe.insert(it, student);
            	}

                break;

                /// Datenelement hinten entfernen
            case '7':
                {
                	if(!studentenListe.empty())
                    	{
                        	it = studentenListe.end();
                            std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                            it->ausgabe();
                            studentenListe.erase(it);
                        }
                        else
                        {
                            std::cout << "Die Liste ist schon leer!\n";
                        }
                }
                break;

            /// Daten aus einer Datei einlesen
			case '8':
				{
					bool mergeData = false;
					bool uberschrift = false;
					if(!studentenListe.empty())
					{
						cout << "Es sind bereits Daten vorhanden. Sollen diese:" << endl
								<< "(1) Gelöscht werden" << endl
								<< "(2) In die Datei 'tempStudents.txt' gespeichert, und dann lokal gelöscht (Default an keine Angabe)" << endl
								<< "(3) Mit den einzulesenden Dateien gemerged werden (hierbei haben die vorhandenen Daten Priorität)" << endl
								<< "(4) Mit den einzulesenden Dateien überschreibt werden (schreibt über vorhandenen Daten)" << endl
								<< "(0) Programm Beenden" << endl << endl;

						std::cin >> abfrage;
						std::cin.ignore(10, '\n');

						switch (abfrage)
						{
							case '0':
					            studentenListe.clear();
					            delete vectorZeig;
					            student.~Student();
					        	exit(1) ;

							case '1':
								studentenListe.clear();
								break;

							case '3':

								mergeData = true;

								break;

							case '4':

								mergeData = true;
								uberschrift = true;

								break;

							default:
								ofstream ausgabe("erstStudierende.txt");///neu Datei

								for(const Student& i : studentenListe)
								{
									ausgabe << i.getMatNr() << endl;
									ausgabe << i.getName() << endl;
									ausgabe << i.getGeburtstag() << endl;
									ausgabe << i.getAdresse() << endl;
								}

								ausgabe.close();
								studentenListe.clear();
								break;
						}

					}

					cout << "Geben sie nun Bitte den Dateinamen an. (ENTER für 'studierende.txt)'";

					string dateiname;
					getline(std::cin, dateiname);    // ganze Zeile einlesen inklusive aller Leerzeichen
					if (dateiname.empty()) dateiname = "studierende.txt";

					ifstream eingabe(dateiname);

					if (!eingabe)
					{
						cout << " Fehler beim oeffnen der Datei !";
			            studentenListe.clear();
			            delete vectorZeig;
			            student.~Student();
			        	exit(1) ;
					}

					unsigned int matNr;
					string name;
					string geburtsdatum;
					string adresse;

					while (!eingabe.eof())
					{
						eingabe >> matNr;
						eingabe.ignore(1, '\n');
						getline(eingabe , name);
						getline(eingabe , geburtsdatum);
						getline(eingabe , adresse);

						student = Student(matNr, name, geburtsdatum, adresse);

						if (uberschrift==false && mergeData && studentExists(&studentenListe, matNr))
						{
							cout << "Folgender Student wurde nicht eingefügt, da die Matrikelnummer bereits existiert: " << endl;
							student.ausgabe();
							cout << "wird vernachlässt";

						}
						else if (mergeData && uberschrift && studentExists(&studentenListe, matNr))
						{
							cout << "Matrikelnummer folgendes Students bereits existiert: " << endl;
							student.ausgabe();
							for(vector<Student>::iterator it1 = studentenListe.begin(); it1 != studentenListe.end(); it1++)
							{

								if (matNr == it1->getMatNr())
								{
									studentenListe.erase(it1);
									studentenListe.insert(it1, student);
									///kein break; , falls duplizierte Student
								}
							}
							cout << "wird über vorhandenen Daten schreibt";

						}
						else
						{
							studentenListe.push_back(student);
							cout << "Folgender Student wurde eingefügt: " << endl;
							student.ausgabe();
						}


					}

				}
				break;

            /// Daten in eine Datei speichern
			case '9':
				{
					if(studentenListe.empty())
					{
						cout << "Es sind keine Daten vorhanden, die abgespeichert werden könnten." << endl;

						break;
					}

					cout << "Geben sie nun Bitte den Dateinamen an. (ENTER für 'neuStudierende.txt)'";
					string dateiname;
					getline(std::cin, dateiname);    /// ganze Zeile einlesen inklusive aller Leerzeichen
					if (dateiname.empty()) dateiname = "neuStudierende.txt";

					ofstream ausgabe(dateiname); ///neu Datei


					if (!ausgabe)
					{
						cout << " Fehler beim Öffnen der Datei !";
			            studentenListe.clear();
			            delete vectorZeig;
			            student.~Student();
						exit(1) ;
					}

					for(const Student& i : studentenListe) {
						ausgabe << i.getMatNr() << endl;
						ausgabe << i.getName() << endl;
						ausgabe << i.getGeburtstag() << endl;
						ausgabe << i.getAdresse() << endl;
					}

					ausgabe.close();

				}
				break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');
    studentenListe.clear();
    delete vectorZeig;
    student.~Student();
    return 0;
}
