#include "MoistureSensor.h"
////

MoistureSensor::MoistureSensor(uint8_t ADC_Pin) : pin(ADC_Pin) {
    state = false;
    currentLevel = 500;  //start level??
    newStateFlag = true;
    newLevelFlag = true;
    pinMode(ADC_Pin, INPUT);
    // pin = ADC_Pin;
}

u_int MoistureSensor::getLevel() {
    u_long nowMs = millis();
    //only read a new sample if time is due
    if (nowMs > (lastReadMillis + readIntervalMillis)) {
        currentLevel = analogRead(pin);
        //Serial.println(currentLevel);
        if (currentLevel != previousLevel) {
            newLevelFlag = true;
            previousLevel = currentLevel;
        }
        lastReadMillis = nowMs;
    }
    return currentLevel;
}
char *MoistureSensor::getLevelStr() {
    dtostrf(currentLevel, 4, 0, levelStr);
    return levelStr;
}

bool MoistureSensor::hasNewLevel() {
    return newLevelFlag;
}

u_int MoistureSensor::clearNewLevelFlag() {
    newLevelFlag = false;  //indicate new data has been read by the program
    return currentLevel;
    //return analogRead(pin);
}

bool MoistureSensor::getState() {
    getLevel();         //initiate new sensor sample if due
    if (hasNewLevel())  //hystresis algorythm
    {
        clearNewLevelFlag();
        if (state == true) {
            if (currentLevel < lowerThresholdLevel) {  //: #(currentLevel < lowerHys):
                state = false;
                newStateFlag = true;
            }
        } else  //state is false
        {
            if (currentLevel > upperThresholdLevel) {  //}: #(currentLevel > upperHys):
                state = true;
                newStateFlag = true;
            }
        }
    }
    return state;
}

void MoistureSensor::setTelePeriod(u_int secs) {
    telePeriod = secs;
    readIntervalMillis = 1000 * secs;
}