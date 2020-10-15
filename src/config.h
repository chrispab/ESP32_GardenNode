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


#define CMSM_READ_INTERVAL  1000*60

#define ESP32_WATCHDOG_TIMEOUT_SECS 60
#define ESP32_WATCHDOG_RESET_INTERVAL_SECS 30

#define MQTT_LAST_OCTET 100
#define PUBLISH_TOPIC "GardenNode1/Moisture/Level"
#define SUBSCRIBE_TOPIC "GardenNode1/#"
#endif
