 

# Cheetsheat



### Konstante Zahl definieren

Definiert man einen symbolischen Namen für eine Zahl, kannst du diesen statt der Zahl verwendet werden.

```c
#define <NAME> <Zahl>

#define PIXEL 	7
```



### Ein oder mehrere Pixel im Code erstellen

Bevor du die Pixel programmieren kannst, musst du dem Programm sagen, wo du wie viele NeoPixel angeschlossen hast. Das kannst du mit folgendem Befehl machen:

```c++
Adafruit_NeoPixel <pixelname> = Adafruit_NeoPixel(<AnzahlPixelInEinerReihe>, <PadNummer>, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel flora_pixel = Adafruit_NeoPixel(ANZAHL_FLORA_PIXEL, FLORA_PIXEL, NEO_GRB + NEO_KHZ800);
```



### Pixel initialisieren

Damit der oder die Pixel auch leuchten, müssen sie gestartet werden. Das tust du mit folgendem Befehl innerhalb der `setup()` Methode.

```c++
void setup() {	// nach dieser Zeile
    
    <pixelname>.begin();
    
    flora_pixel.begin();
}
```



### Pixel  programmieren

Das eigentliche Verhalten der Pixel, also wie sie leuchten oder blinken sollen beschreibst du innerhalb der `loop()` Methode. 

Alles was zwischen `void loop() {` und `}` steht wird der Reihe nach in einer Endlosschleife durchlaufen.



#### Pixel leuchten lassen

Achtung beim Verwenden der Pixel-Nummer! Informatiker fangen bei 0 an zu zählen!

Der erste Pixel hat also die Nummer 0.

```c++
// Farbwert setzen, aus den Grundfarben Rot, Grün und Blau kannst du alle Farben mischen.
// Probier es einfach aus.
<pixelname>.setPixelColor(<pixelNummer>, <pixelname>.Color(<Rotwert>, <Grünwert>, <Blauwert>));
// Farbwert anzeigen
<pixelname>.show();
// Bestimmen wie lange die Fabe gezeigt werden soll bevor der nächste Befehl ausgeführt wird
delay(<WartezeitVorNächstemFarbwechsel>);

flora_pixel.setPixelColor(0, flora_pixel.Color(255, 0, 0));
flora_pixel.show();
delay(2000);	// 2000 Millisekunden entspricht 2 Sekunden
```



#### Regenbogen

Der Regenbogen ist ein vorgefertigter Effekt, den du für alle Pixel die in einer Reihe an einem Pad angeschlossen sind aktivieren kannst. Mit der Wartezeit bestimmst du wie lange jede einzelne Farbe zu sehen ist bevor zur nächsten gewechselt wird.

```c++
Regenbogen(&<pixelname>, <Wartezeit>); 	

Regenbogen(&flora_pixel, 20);
```



#### Blinken

Blinken kannst du auch mit den Befehlen oben (Pixel leuchten lassen) darstellen. Um es dir zu Vereinfachen kannst du aber auch diesen vorgefertigten Effekt für einzelne Pixel verwenden.

```c++
Blinken(&<pixelname>, <pixelNummer>, <Farbe1>, <Farbe2>, <Wartezeit>);
Blinken(&flora_pixel, 3, flora_pixel.Color(255, 0, 0), flora_pixel.Color(255, 100, 0), 2000);
```

