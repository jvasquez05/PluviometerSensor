#ifndef PLUVIOMETER_SENSOR_H
#define PLUVIOMETER_SENSOR_H

#include <Arduino.h>

class PluviometerSensor {
  public:
    PluviometerSensor(uint8_t pin, float mmeDefault = 0.2794f);

    void begin();                     // inicializa el pin
    void handleIRQ();                 // ISR: incrementa contador de tips con debounce
    unsigned int getTips();           // devuelve tips acumulados
    void resetTips();                 // reinicia contador
    float tipsToMM(unsigned int tips);// convierte tips a mm
    float getMME();                   // devuelve mm por tip
    void setMME(float mme);           // configura mm por tip

  private:
    uint8_t _pin;
    volatile unsigned int _tips;
    float _mme;
    volatile unsigned long _lastInterrupt; // nuevo: para debounce
};

#endif
