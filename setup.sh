#!/usr/bin/env bash
cd ~/Documents/Arduino

# ATMEGA 328 Setup
ln -sf $(pwd)/AcceleratedLED/lib/AcceleratedLED328/lib $(pwd)/libraries/AcceleratedLED328
mkdir -p $(pwd)/AcceleratedLED328
ln -sf $(pwd)/AcceleratedLED/lib/AcceleratedLED328/AcceleratedLED328.ino $(pwd)/AcceleratedLED328/AcceleratedLED328.ino

cd ~/Documents/Arduino/libraries
git clone git@github.com:adafruit/Adafruit-WS2801-Library.git Adafruit_WS2801
git clone git@github.com:bguest/ADXL362.git

# Eagle
cd ~/Documents
ln -sf $(pwd)/Arduino/AcceleratedLED/eagle $(pwd)/eagle/AcceleratedLED
echo "Finished"
