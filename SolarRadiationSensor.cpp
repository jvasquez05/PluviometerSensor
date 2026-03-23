#include "PluviometerSensor.h"

PluviometerSensor::PluviometerSensor(uint8_t pin, float mmeDefault) {
  _pin = pin;
  _tips = 0;
  _mme = mmeDefault;
}

void PluviometerSensor::begin() {
  pinMode(_pin, INPUT_PULLUP);
  // La ISR se asigna en el sketch principal con attachInterrupt()
}

void PluviometerSensor::handleIRQ() {
  _tips++;
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