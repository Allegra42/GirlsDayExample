#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <effects.h>

/*
 * Zuerst müssen wir dem Programm sagen an welchen Pad Nummern 
 * (das sind die goldenen Flächen auf dem Chip) wir die LEDs anschliesen wollen.
 * 
 * Die LED auf dem Flora selbst hat dabei immer die Nummer 8. 
 * (Steht auch klein direkt daneben)
 */

#define FLORA_PIXEL     8

/* 
 * Für die zusätzlichen LEDs brauchst du nur ein Pad, also eine Nummer, 
 * um alle LEDs zu kontrollieren, solange du sie in einer Reihe anschließt.
 * Möglich sind die Nummern : 12, 6, 9, 10. Die anderen Pad Nummern haben spezielle Funktionen.
 * Wenn du sie nicht unbedingt brauchst lass sie lieber frei um vielleicht später einmal genau
 * für diese Funktionen zu nutzen.
 */

#define EXTERNE_PIXEL   9

/*
 * Damit wir bei mehreren Pixeln hintereinander auch einzeln sagen können welche Farbe sie haben 
 * sollen, müssen wir dem Programm sagen wie viele der Pixel denn überhaupt an dem Pad hängen.
 * Die interne LED ist immer nur eine, aber Externe kannst du fast beliebig viele anschließen.
 * Deshalb müssen diese extra angeben. Es ist nämlich viel einfacher die Anzahl hier einmal zu 
 * ändern und im Code immer nur 'ANZAHL_PIXEL' zu sagen.
 */
#define ANZAHL_PIXEL    1


/*
 * Im nächsten Schritt müssen wir eine Pixel-Instanz erstellen.
 * Das heißt wir müssen im Programm sagen, dass wir z.B. an Pad 9 gerne NeoPixel nutzen möchten.
 * Und zwar z.B. 4 Stück davon. 
 * 
 * Dazu sagen schreiben wir zuerst Adafruit_NeoPixel und sagen dem Programm damit, dass wir ein
 * solches Objekt haben wollen. 
 * Das Objekt braucht noch eine Namen: 'flora_pixel' für die interne LED 
 * und 'externe_pixel' zum Beispiel. 
 * Oder 'Hugo' wenn dir du dir so besser merken kannst was gemeint ist.
 * 
 * Als nächstes müssen wir dem Programm klar machen, dass unser flora_pixel oder Hugo aus 1 - ? 
 * vielen einzelnen Pixeln besteht und an Pad ? angeschlossen ist. 
 * Das sind die ersten beiden Parameter um die Instanz zu erstellen. 
 * Der letzte Parameter sagt etwas über die Farbanordnung und die Kommunikation zwischen den 
 * Pixeln aus. Übernimm den Wert einfach aus dem Beispiel.
 * 
 * Der Befehl sieht dann etwa so aus:
 * Adafruit_NeoPixel <Name> = Adafruit_NeoPixel(<AnzahlPixel>, <PadNummer>, NEO_GRB + NEO_KHZ800); 
 */
Adafruit_NeoPixel flora_pixel = Adafruit_NeoPixel(1, FLORA_PIXEL, NEO_GRB + NEO_KHZ800); 


/*
 * Nun müssen die Pixel noch leuchten. Also zuerst einmal das einzelne auf dem Flora.
 * Dazu müssen wir es initialisieren. Das machen wir in der Funktion 'setup'.
 * Hier schreiben wir alle Befehle hinein die wir genau einmal ausführen möchten.
 * Zum Beispiel die LED einmal in deiner Lieblingsfarbe einschalten.
 */
 void setup() {
 
  /*
   * Dazu müssen wir dem oder den Pixeln natürlich sagen was sie tun sollen.
   * Zuerst einmal müssen sie überhaupt erst einmal aktiviert werden.
   * Das machen wir indem wir den Namen des bzw. der Pixel schreiben und direkt danach ".begin();"
   */
  flora_pixel.begin();

  /*
   * Nun müssen wir die Farbe für das Pixel setzen. Dazu müssen wir die Nummer des Pixels 
   * angeben um diese auch geziehlt ansprechen zu können sollten wir mehrere davon haben.
   * Aber vorsicht! Informatiker fangen bei 0 an zu zählen...
   * z.B. mit <Pixelname>.setPixelColor(<Nummer>, <Farbe>);
   * 
   * Dann müssen wir noch die Farbe setzen. Die Farbe wird als R G B Wert angegeben.
   * Wir sagen also wie viel Rot, Grün und Blau Anteil das Licht haben soll und mixen daraus die 
   * gewünschte Farbe. Vielleicht musst du ein bisschen ausprobieren bis es so aussieht wie du es
   * dir vorgestellt hast. Es funktioniert mit dem Befehl:
   * <Pixelname>.Color(<RotWert>, <GrünWert>, <BlauWert>);
   * Du kannst dabei Zahlen zwischen 0 und 255 eintragen.
   * 
   * Der gesamte Befehl lautet dann:
   */
  flora_pixel.setPixelColor(0, flora_pixel.Color(0, 255, 255));

  /*
   * Aber damit wir auch etwas sehen müssen wir dem Pixel noch sagen, dass er das Licht jetzt endlich
   * anschalten bzw. verändern soll.
   * Das machen wir indem wir <Pixelname>.show(); sagen.
   * 
   * Vergisst du es, wird das Pixel nicht oder in der vorherigen Farbe leuchten.
   */
  flora_pixel.show();

  /*
   * Damit du auch siehst was für eine Farbe du gesetzt hast ist es manchmal, z.b. wenn du danach die Farbe wieder
   * ändern möchtest, sinnvoll den Programmablauf zu verzögern. Das tust du mit:
   * 
   * delay(<ZeitInMillisekunden>);
   */
  delay(2000);  // Das entspricht einer Verzögerung von 2 Sekunden
}


/*
 * Die eigentliche Programmierung deines Floras findet allerdings hier statt, im "loop".
 * Das ist eine Schleife, die unendlich oft hintereinander durchlaufen wird. In ihr kannst du deinen Pixeln 
 * einen Ablauf vorgeben und bestimmen wie sie sich verhalten sollen.
 * 
 * Dazu kannst du entweder wie oben im "setup" bestimmte Pixel leuchten lassen und über Verzögerungen Abläufe programmieren,
 * oder du benutzt Effekte, die wir dir vorbereitet haben.
 * 
 * Achtung: Die Befehle im "loop" werden hintereinander und nicht gleichzeitig ausgeführt!
 * Wenn du beispielsweise den Regenbogen Effekt für den internen und die externen Pixel benutzen möchtest wird er erst für das eine und
 * danach für das/die anderen Pixel durchlaufen.
 */
void loop() {
  /*
   * Den Regenbogen Effekt kannst du nur auf alle Pixel an einem Pad anwenden, also auf einen Neopixel Namen im Ganzen.
   * Du startest ihn, indem du "Regenbogen(&<Pixelname>, <Zeitdauer>);" schreibst. Wichtig ist dabei das "&" vor dem 
   * Namen. Mit der Zeitdauer gibst du an, wie lange eine einzelne Farbe gehalten werden soll bevor der Übergang zur nächsten erfolgt.
   */ 
  Regenbogen(&flora_pixel, 50);

  /*
   * Der Blinken Effekt ist nur eine Vereinfachung. Eigentlich kannst du auch mit Hilfe der Befehle die du schon kennst ein Pixel 
   * blinken lassen.
   * Der Befehl funktioniert indem du angibtst welches Pixelreihe und welches einzelne Pixel davon du blinken lassen möchtest.
   * Danach musst du noch angeben in welchen zwei Farben das Pixel blinken soll und wie lange die Farben gehalten werden.
   * Das ganze sieht dann so aus: "Blinken(&<Pixelname>, <PixelNummer>, <Farbe1>, <Farbe2>, <Zeitdauer>);"
   */
  Blinken(&flora_pixel, 3, flora_pixel.Color(255, 0, 0), flora_pixel.Color(255, 100, 0), 2000);
}