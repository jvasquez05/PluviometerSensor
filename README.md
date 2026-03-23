# PluviometerSensor

Librería ligera para el pluviómetro de **Proagro Technology**, diseñada para dataloggers agrícolas.  
Permite contar tips del balancín y convertirlos a milímetros de precipitación usando un **factor configurable (MME)**.

---

## ✨ Características
- Contador de tips con ISR (`handleIRQ()`).
- Conversión de tips a mm (`tipsToMM()`).
- Factor MME configurable (`setMME()` / `getMME()`).
- Optimizada para bajo consumo de memoria, apta para proyectos con uso intensivo de recursos.

---

## 📦 Instalación

### Opción 1: Desde GitHub
1. Descarga el archivo ZIP desde la sección **Releases**.
2. En Arduino IDE:  
   `Sketch → Include Library → Add .ZIP Library…`  
   Selecciona el ZIP descargado.

### Opción 2: Clonando el repositorio
```bash
git clone https://github.com/jvasquez05/PluviometerSensor/releases/tag/v1.0.0

🚀 Uso básico
#include <PluviometerSensor.h>

const int RAIN_PIN = 2;
PluviometerSensor pluvio(RAIN_PIN);

void setup() {
  Serial.begin(9600);
  pluvio.begin();
}

void loop() {
  unsigned int tips = pluvio.getTips();
  float mm = pluvio.tipsToMM(tips);

  Serial.print("Tips: ");
  Serial.println(tips);

  Serial.print("Precipitación mm: ");
  Serial.println(mm);

  delay(1000);
}



🔧 Opciones avanzadas
El ajuste dinámico de calibración (MME) está disponible únicamente cuando el sensor se utiliza dentro de un datalogger Proagro Technology, donde forma parte de la lógica de configuración vía Bluetooth junto con otros comandos especializados.
Este ajuste no está incluido en la librería independiente, que se limita a la lectura y conversión del sensor.
⚠️ Nota: El uso de estos comandos es exclusivo para usuarios avanzados que operen el datalogger completo.
El usuario normal de la librería no necesita realizar ninguna configuración adicional.

## 📖 Notas
- El valor base de calibración (`MME = 0.2794f`) corresponde al pluviómetro de referencia Proagro Technology, **basado en la hoja de datos del pluviómetro Argent DataSystem**.  
- La librería está diseñada para ser ligera y enfocada únicamente en el funcionamiento del pluviómetro.

🏷️ Versión
v1.0.0 – Primera versión oficial.
📧 Autor
Proagro Technology
Desarrollada por Jhonny Vásquez Jiménez


