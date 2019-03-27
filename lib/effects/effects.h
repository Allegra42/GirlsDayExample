#ifndef __EFFECTS_H__
#define __EFFECTS_H__

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

uint32_t Farbrad(Adafruit_NeoPixel* pixel, byte position);
void Regenbogen(Adafruit_NeoPixel* pixel, unsigned long wartezeit);
void Blinken(Adafruit_NeoPixel* pixel, uint8_t pixelNummer, uint32_t farbe1, uint32_t farbe2, unsigned long wartezeit);

#endif /* __EFFECTS_H__*/