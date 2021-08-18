#define BLYNK_PRINT Serial
#include "gsmconfig.h"

// Select your modem:
#define TINY_GSM_MODEM_SIM800
#define SIM800L_IP5306_VERSION_20190610

// Set serial for debug console (to the Serial Monitor, default speed 115200)
#define SerialMon Serial

// Set serial for AT commands (to the module)
// Use Hardware Serial on Mega, Leonardo, Micro
#define SerialAT Serial1

// See all AT commands, if wanted
#define DUMP_AT_COMMANDS

// Define the serial console for debug prints, if needed
#define TINY_GSM_DEBUG SerialMon

// set GSM PIN, if any
#define GSM_PIN ""

// Your GPRS credentials, if any
const char apn[] = "YourAPN";
const char gprsUser[] = "";
const char gprsPass[] = "";

#include <TinyGsmClient.h>
#include <BlynkSimpleTinyGSM.h>
#ifdef DUMP_AT_COMMANDS
#include <StreamDebugger.h>
StreamDebugger debugger(SerialAT, SerialMon);
TinyGsm modem(debugger);
#else
TinyGsm modem(SerialAT);
#endif
TinyGsmClient client(modem);


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
const char auth[] = "paXt0HWXUFQBqpCce_ymcl0fZif9ZHZa";

void setup()
{
    // Set console baud rate
    SerialMon.begin(115200);

    delay(10);

    setupModem();

    SerialMon.println("Wait...");

    // Set GSM module baud rate and UART pins
    SerialAT.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);

    delay(6000);

    // Restart takes quite some time
    // To skip it, call init() instead of restart()
    SerialMon.println("Initializing modem...");
    modem.restart();
    // modem.init();

    String modemInfo = modem.getModemInfo();
    SerialMon.print("Modem Info: ");
    SerialMon.println(modemInfo);

    // Unlock your SIM card with a PIN
    //modem.simUnlock("1234");

    Blynk.begin(auth, modem, apn, gprsUser, gprsPass);
    // Initialize the indicator as an output
    pinMode(LED_GPIO, OUTPUT);
}

BLYNK_WRITE(V0) {
  int restarts = param.asInt();
  if (restarts == 1) {
    digitalWrite(LED_GPIO,LOW);
    }
    else {
    digitalWrite(LED_GPIO,HIGH);
  }
}
void loop()
{
    Blynk.run();
}
