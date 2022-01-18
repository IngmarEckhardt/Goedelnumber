#ifndef HELPPAGE_H
#define HELPPAGE_H

std::string helpText
        = "Das vorliegende Programm entstand als Abschlussarbeit der Vorlesung Grundlagen der Programmierung an der HTWK - Leipzig.\n\n"
          "Das Programm dient der Berechnung der sogenannten Gödelnummer nach der Eingabe einer Aussageformel. Die Gödelnummer beruht auf\n"
          "dem Vorschlag des Mathematikers Gödel, welcher jeder Aussagenformel eine eindeutige Kennzahl zuweisen wollte. Es werden dabei \n"
          "bestimmte Vorgaben für die Eingabe und Berechnung der Gödelnummer gemacht, deren genauer Zweck hier nicht erläutert werden soll.\n"
          "(weitergehende Informationen über die Gödelnummer und die Hintergründe dieser Vorgaben finden Sie in der deutschsprachigen Wiki-\n"
          "pedia im Artikel \"Gödelnummer\")\n"
          "Im folgenden werden die Vorgaben für die Eingabe der Formel erläutert:\n"
          "Zur Eingabe verwenden Sie bitte ausschließlich folgende Operatoren: +, -, * (Multiplikation), / (Division), =. \n\n"
          "In der Formel vorkommende konstante Ganzzahlwerte geben Sie bitte in der folgenden Form ein: \n"
          " '0' für die Zahl null, weitere Zahlen mit dem Buchstaben 's' als Nachfolger dieser Zahl. Beispiel: Die Zahlen 1 und 2 werden als\n"
          " 's0' und 'ss0' eingegeben, analog für jede weitere Zahl.\n\n"
          "Es stehen zur Eingabe einer Formel weiterhin die Variablen a,b,c,d,e und f zur Verfügung.\n\n"
          "Berechnung der Gödelnummer:\n"
          "Die eingegebenen Zeichen werden vom Programm intern in eine Kennzahl übersetzt. Die Operatoren erhalten die Zahlen: 1 bis 5 anhand\n"
          "der oben genannten Reihenfolge. Die Ziffer '0' wird mit der Zahl 6 kodiert, das Nachfolgersymbol 's mit der 7. Die Variablen\n"
          "werden mit den Zahlen 8 bis 13 entsprechend der alphabetischen Reihenfolge.\n\n"
          "Die Berechnung der Gödelnummer der Formel erfolgt nun nach dem Schema, dass eine Summe gebildet wird, bei der die einzelnen Summanden\n"
          "mit Hilfe der aufsteigenden Primzahlen (bis zum Wert 100.000) berechnet werden. Die erste Primzahl '2' wird dabei mit der ersten\n"
          "kodierten Zahl der Formel potenziert, der nächste Summand ist die darauf folgende Primzahl '3' welche mit der nächsten kodierten\n"
          "Zahl potenziert wird. Die Formel 1+a=2 wird vom Nutzer eingegeben als s0+a=ss0 und vom Programm zunächst kodiert mit den Zahlen\n"
          "7 6 1 8 5 7 7 6 und darauf folgend die Gödelnummer berechnet nach dem Schema 2(hoch 7) + 3(hoch 6) + 5 (hoch 1) + 7 (hoch 8)+...\n\n"
          "Das Program nutzt eine vorhandene Datei mit den Primzahlen bis zum Wert 100.000, ist aber in der Lage beim Fehlen dieser Datei mit\n"
          "Hilfe des Sieb des Erastothenes diese Primzahlen erneut zu berechnen und eine neue Datei für weitere Programmstarts anzulegen.\n\n"
          "Startparameter: '-np' Primzahlen-Datei wird neu erzeugt auch wenn sie vorhanden ist\n"
          "                '-debug' Das Programm berichtet detailliert über die internen Abläufe\n\n"
          "Autor: Ingmar Eckhardt. Kontakt: Ingmar.Eckhardt@stud.htwk-leipzig.de\n";

#endif // HELPPAGE_H
