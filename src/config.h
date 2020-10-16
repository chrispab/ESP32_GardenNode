#ifndef __SETTINGS_H
#define __SETTINGS_H

//#define DEBUG_WSERIAL

#define RELEASE

// #define ALT_ID

#ifdef ALT_ID
    #define MQTT_CLIENT_NAME "IRBridgeMQTTClientALT"
    #define LWT_TOPIC "irbridgeALT/LWT"
#else
    #define MQTT_CLIENT_NAME "GardenNode1"
    #define LWT_TOPIC "GardenNode1/LWT"
#endif


#define DEFAULT_CMSM_READ_INTERVAL  1000*10

#define ESP32_WATCHDOG_TIMEOUT_SECS 60
#define ESP32_WATCHDOG_RESET_INTERVAL_SECS 30

#define MQTT_LAST_OCTET 100
#define PUBLISH_TOPIC "GardenNode1/Moisture/Level"
#define SUBSCRIBE_TOPIC "GardenNode1/#"
#define SET_TELEPERIOD_TOPIC "GardenNode1/setteleperiod"

// Note: ADC2 pins cannot be used when Wi-Fi is used. 
// So, if you’re using Wi-Fi and you’re having trouble getting the value from an ADC2 GPIO,
// you may consider using an ADC1 GPIO instead, that should solve your problem. 

// #define CSMS_PIN GPIO_NUM_15 // RHS_P_3, capacitive soil moisture sensor pin 
#define CSMS_PIN GPIO_NUM_36 // LHS_P_14, capacitive soil moisture sensor pin 

#define ESP32_ONBOARD_BLUE_LED_PIN GPIO_NUM_2 // RHS_P_4 esp32 devkit on board blue LED


#endif
