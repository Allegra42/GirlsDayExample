# FloraBag
## Quellcode und Anleitung für den FloraBag Girl's Day Workshop 2019
![Two Bags](/pictures/two-bags.jpg)

## Inhaltsverzeichnis
- [Motivation](#motivation)
- [Idee](#idee)
- [Material](#material)
- [Verkabelung](#verkabelung)
- [Umsetzung](#umsetzung)
- [Entwicklungsumgebung](#entwicklungsumgebung)
- [Programmierung](#programmierung)

### Motivation
Bisher bestand unser Girl's Day immer aus 4 kleineren Workshops aufgeteilt auf 4 Stationen.
Leider konnten die Mädchen kaum etwas aus diesen Workshops mit nach Hause nehmen und Eltern, Freunden und Bekannten vorführen, was sie an dem ereignisreichen Tag selbst erschaffen haben oder daran weiter zu arbeiten.

### Idee
Arduinos sind klein, günstig und einsteigerfreundlich - aber begrenzt ansprechend. 
Eine leuchtende Tasche basierend auf einem Adafruit Flora und NeoPixel LEDs deutlich mehr.
Die Tasche ist praktisch einsetzbar, kann nach eigenen Ideen gestaltet werden, zu Hause vorgeführt und verändert werden.

### Material
- Adafruit Flora
- NeoPixel LEDs
- Schaltdraht
- Akkupack oder Batteriepack
- Stofftaschen
- Filz in verschiedenen Farben um Motive zu basteln
- Klettband und Heißkleber um Motiv und Schaltung wieder ablösbar an den Taschen zu befestigen
- Scheren / Abisolierzange / Lötmaterial

### Verkabelung
Die Grundlagen zum Flora und der Verkabelung findest du in den [Folien](https://github.com/Allegra42/GirlsDayExample/blob/master/Workshop_Flora.pdf).

### Umsetzung
Siehe [inovex Blog](https://www.inovex.de/blog/girlsday-2019-bei-inovex/).
![Pinky Pi](/pictures/pinky-pie.jpg)
![Handball](/pictures/handball.jpg)
![Unicorn](/pictures/unicorn-cookies.jpg)

### Entwicklungsumgebung
- Installiere https://code.visualstudio.com auf deinem Computer.
![Download](/pictures/code-download.png)
- Starte das Programm und wähle Extensions aus der linken Toolbar im Hauptfenster und schreibe platformio in das Suchfeld. Drücke auf dem erscheinenden Suchergebnis bei PlatformIO IDE auf den grünen Button Install.
![Install](/pictures/code-install-platformio.png)
- Nach der erfolgreichen Installation lädst Du Dir von [GitHub](https://github.com/Allegra42/GirlsDayExample) mit dem Drop-Down Clone or Download und anschließender Auswahl des Download ZIP-Button das Zip-File zum Kurs herunter.
- Anschließend kannst Du das heruntergeladene Projekt mit “ + Open Project” unterhalb von Quick Access importieren.
![Open](/pictures/code-new-project.png)
- Im unteren Bereich der Applikation kannst Du das Programm mittels dem Button Upload auf den Flora übertragen, sobald dieser an Deinen Computer angeschlossen ist.
![Upload](/pictures/code-upload.png)
- Ändere das Programm nach belieben, speichere es und übertrage es erneut auf den Flora, um die Änderungen zu sehen.

### Programmierung
Alle Infos die du für die Programmierung benötigst sind als Kommentare (beginnen mit /\*) im Quellcode an den entsprechenden Stellen hinterlegt.
Zusätzlich gibt es noch das [Cheatsheet](https://github.com/Allegra42/GirlsDayExample/blob/master/Cheatsheet.pdf), in dem alle notwendigen Informationen noch einmal kurz zusammengefasst sind. 
