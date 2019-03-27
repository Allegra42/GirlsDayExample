#include "effects.h"

uint32_t Farbrad(Adafruit_NeoPixel* pixel, byte position) {
    position = 255 - position;
    if (position < 85) {
        return pixel->Color(255 - position * 3, 0, position * 3);
    }
    if (position < 170) {
        position -= 85;
        return pixel->Color(0, position * 3, 255 - position *3);
    }
    position -= 170;
    return pixel->Color(position * 3, 255 - position * 3, 0);
}

void Regenbogen(Adafruit_NeoPixel* pixel, unsigned long wartezeit) {
    for (uint16_t j = 0; j < 256; j++) {
        for (uint16_t i = 0; i < pixel->numPixels(); i++) {
            uint32_t c = Farbrad(pixel, ((i+j) & 255));
            pixel->setPixelColor(i, c);
        }
        pixel->show();
        delay(wartezeit);
    }
}

void Blinken(Adafruit_NeoPixel* pixel, uint8_t pixelNummer, uint32_t farbe1, uint32_t farbe2, unsigned long wartezeit) {
    pixel->setPixelColor(pixelNummer, farbe1);
    pixel->show();
    delay(wartezeit);

    pixel->setPixelColor(pixelNummer, farbe2);
    pixel->show();
    delay(wartezeit);
}