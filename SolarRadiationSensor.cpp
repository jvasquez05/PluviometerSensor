#include "PluviometerSensor.h"

PluviometerSensor::PluviometerSensor(uint8_t pin, float mmeDefault) {
  _pin = pin;
  _tips = 0;
  _mme = mmeDefault;
  _lastInterrupt = 0;
}

void PluviometerSensor::begin() {
  pinMode(_pin, INPUT_PULLUP);
  _tips = 0;
  _lastInterrupt = millis(); // evita registrar un pulso espurio al inicio
}

void PluviometerSensor::handleIRQ() {
  unsigned long now = millis();
  if (now - _lastInterrupt > 200) {   // 200 ms de debounce
    _tips++;
    _lastInterrupt = now;
  }
}

unsigned int PluviometerSensor::getTips() {
  return _tips;
}

void PluviometerSensor::resetTips() {
  _tips = 0;
}

float PluviometerSensor::tipsToMM(unsigned int tips) {
  return tips * _mme;
}

float PluviometerSensor::getMME() {
  return _mme;
}

void PluviometerSensor::setMME(float mme) {
  if (mme > 0.0f) _mme = mme;
}
