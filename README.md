# PluviometerSensor
Lightweight library for the Proagro Technology pluviometer, designed for agricultural dataloggers.
It allows counting tips from the tipping bucket and converting them to millimeters of precipitation using a configurable factor (MME).

✨ Features
- Tip counter with ISR (handleIRQ()).
- Conversion from tips to mm (tipsToMM()).
- Configurable MME factor (setMME() / getMME()).
- Optimized for low memory usage, suitable for resource-intensive projects.

📦 Installation
Option 1: From GitHub
- Download the ZIP file from the Releases section.
- In Arduino IDE:
Sketch → Include Library → Add .ZIP Library…
Select the downloaded ZIP.
Option 2: Clone the repository
git clone https://github.com/jvasquez05/PluviometerSensor/releases/tag/v1.0.0



🚀 Basic Usage
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

  Serial.print("Precipitation mm: ");
  Serial.println(mm);

  delay(1000);
}



🔧 Advanced Options
Dynamic calibration adjustment (MME) is only available when the sensor is used within a Proagro Technology datalogger, where it is part of the Bluetooth configuration logic together with other specialized commands.
This adjustment is not included in the standalone library, which is limited to sensor reading and conversion.
⚠️ Note: These commands are intended exclusively for advanced users operating the full datalogger.
Regular library users do not need to perform any additional configuration.

📖 Notes
- The base calibration value (MME = 0.2794f) corresponds to the Proagro Technology reference pluviometer, based on the Argent DataSystem pluviometer datasheet.
- The library is designed to be lightweight and focused solely on pluviometer operation.

🏷️ Version
v1.0.0 – First official release.

📧 Author
Proagro Technology
Developed by Jhonny Vásquez Jiménez


