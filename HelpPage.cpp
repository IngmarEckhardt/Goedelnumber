#include "HelpPage.h"

std::string helpText() {

    std::string helpText =
            "Das vorliegende Programm entstand als Abschlussarbeit der Vorlesung Grundlagen der Programmierung an der HTWK-Leipzig.\n\n"
            "Das Programm dient der Berechnung der sogenannten Goedelnummer nach der Eingabe einer Aussageformel. Die Goedelnummer \n"
            "beruht auf dem Vorschlag des Mathematikers Goedel, welcher jeder Aussagenformel eine eindeutige Kennzahl zuweisen\n"
            "wollte. Es werden dabei bestimmte Vorgaben fuer die Eingabe und Berechnung der Goedelnummer gemacht, deren genauer\n"
            "Zweck hier nicht erlaeutert werden soll.(weitergehende Informationen ueber die Goedelnummer und die Hintergruende \n"
            "dieser Vorgaben finden Sie in der deutschsprachigen Wikipedia im Artikel \"Goedelnummer\")\n\n"
            "Im folgenden werden die Vorgaben fuer die Eingabe der Formel erlaeutert:"
            "Zur Eingabe verwenden Sie bitte ausschliesslich folgende Operatoren: +, -, * (Multiplikation), / (Division), =. \n\n"
            "In der Formel vorkommende konstante Ganzzahlwerte geben Sie bitte in der folgenden Form ein: \n"
            "'0' fuer die Zahl null, weitere Zahlen mit dem Buchstaben 's' als Nachfolger dieser Zahl. Beispiel: Die Zahlen 1 und 2\n"
            "werden als 's0' und 'ss0' eingegeben, analog fuer jede weitere Zahl.\n"
            "Es stehen zur Eingabe einer Formel weiterhin die Variablen a,b,c,d,e und f zur Verfuegung.\n\n"
            "Berechnung der Goedelnummer:\n"
            "Die eingegebenen Zeichen werden vom Programm intern in eine Kennzahl uebersetzt. Die Operatoren erhalten die Zahlen: 1\n"
            "bis 5 anhand der oben genannten Reihenfolge. Die Ziffer '0' wird mit der Zahl 6 kodiert, das Nachfolgersymbol 's' mit\n"
            "der 7. Die Variablen werden mit den Zahlen 8 bis 13 entsprechend der alphabetischen Reihenfolge kodiert.\n\n"
            "Die Berechnung der Goedelnummer der Formel erfolgt nun nach dem Schema, dass ein Produkt gebildet wird, bei der die\n"
            "einzelnen Faktoren mit Hilfe der aufsteigenden Primzahlen (bis zum Wert 100.000) berechnet werden. Die erste Prim-\n"
            "zahl '2' wird dabei mit der ersten kodierten Zahl der Formel potenziert, der naechste Faktor ist die darauf folgende\n"
            "Primzahl '3' welche mit der naechsten kodierten Zahl potenziert wird. Die Formel 1+a=2 wird vom Nutzer eingegeben als\n"
            "s0+a=ss0 und vom Programm zunaechst kodiert mit den Zahlen 7 6 1 8 5 7 7 6 und darauf folgend die Goedelnummer berech-\n"
            "net nach dem Schema 2(hoch 7) * 3(hoch 6) * 5 (hoch 1) * 7 (hoch 8) * 11 (hoch 5) * 13 (hoch 7)...\n\n"
            "Das Program nutzt eine vorhandene Datei mit den Primzahlen bis zum Wert 100.000, ist aber in der Lage beim Fehlen\n"
            "dieser Datei mit Hilfe des Sieb des Erastothenes diese Primzahlen erneut zu berechnen und eine neue Datei fuer wei-\n"
            "tere Programmstarts anzulegen.\n\n"
            "Startparameter: '-np' Primzahlen-Datei wird neu erzeugt auch wenn sie vorhanden ist\n"
            "                '-debug' Das Programm berichtet detaillierter ueber die internen Abläufe\n\n"
            "Autor: Ingmar Eckhardt. Kontakt: Ingmar.Eckhardt@stud.htwk-leipzig.de\n";

    return helpText;
}