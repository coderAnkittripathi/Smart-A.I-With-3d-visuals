---
title: "Shanda Pod"
author: "Hasnat"
description: "It is an MP3 player!"
created_at: "2025-06-05"
---
# June 5th: Started Making the base

I have started working on an MP3 player which will also be able to output audio to my Airbuds.

I have selected the ESP32 WROVER as the MCU.

Put an OLED display and SD card reader to it too.

![image](https://github.com/user-attachments/assets/983ff607-cd78-4104-bae1-0eee23f2e06c)

![image](https://github.com/user-attachments/assets/77ebb5aa-cf1e-4e92-93f0-d52ba4a4656f)

Not sure about them tho still a lot to do

**Total time spent: 3hr**

# June 8th: Edited the schematic a bit

I never used a microSD card with any microcontroller before so I was confused as how to wire the pins to my ESP32. I finally figured it out and wired them up. I also added 4 male jumper pins so that I can easily use a USB to 

TTL converter or my arduino nano to flash new codes on the ESP32.

![image](https://github.com/user-attachments/assets/cd13bfbf-7cc8-4739-8f66-eedcd2a3b625)

![image](https://github.com/user-attachments/assets/24d499ca-47c9-4a3c-9f9a-ebc3c1d17adb)

PCB looks like this now

**Total time spent: 1hr**

# June 9th: Added voltage converter

The ESP32 runs on 3.3v but most of the batteries we find like the 18650 li-ion batteries all have a voltage range of 3.7-4.2 which is not safe for the ESP32 so I desided to include a AMS1117 LDO to limit the voltage to 3.3v. I also put a JST connector to connect the battery to the PCB.

![image](https://github.com/user-attachments/assets/0c7aa5be-d46d-44a0-9bc9-d6c738963d87)

![image](https://github.com/user-attachments/assets/e54d9762-37b6-44fa-a259-5c51953ae877)



**Total time spent: 2hr**

# June 11th: Added extra switch and tidied up the schematic

Thought I need some more switches for the MP3 player. So added 2 more switches.

Gonna start working on the case now.

![image](https://github.com/user-attachments/assets/ec01024b-a128-4b2e-9bcb-7378826a94ab)

![image](https://github.com/user-attachments/assets/7615391b-5108-41eb-8551-717a2cbab5ba)


**Total time spent: 0.5hr**

# June 13th: Changed switch model and added voltage reading

I want to also see how much charge is left on the battery, so I added 2 resistors to step down the voltage which esp32 can read safely
Also Changed the switch models

![image](https://github.com/user-attachments/assets/1a5af187-fc32-41d4-8b3c-3d2679889c6c)

![image](https://github.com/user-attachments/assets/0d80c366-f133-4d58-9748-ae4329584c7a)

![image](https://github.com/user-attachments/assets/150b6c2c-f3c7-46f6-a84d-d3699be2efe2)

**Total time spent: 0.5hr**
