# MindPhreak

*Our official HackUTA 2018 submission, write-up & media can be found on [DevPost](https://devpost.com/software/mindphreak).*
After seeing the hardware on offer to us, we decided to push the boundaries of what we could make.

## The device
MindPhreak quantifies output from the brain and uses it to control a moving robot. The potential benefit of our system huge, as it could provide communications and movement to people that suffer from debilitating diseases, such as quadraplegia, locked-in syndrome and ALS.

## How it works
MindPhreak works by using an EEG reader, a compact headband made by Muse. It is commercially made for helping people meditate and be calm, however we used its EEG feedback to read certain thoughts and nuances of the mind. This allows us to identify known thoughts, such as stroking a cat to mean "turn left" or eating an apple to mean "turn right".

Once the data from the headset has been read and the command identified, the instruction is sent to a microcontroller onboard the robot and it moves, responding directly to the thought that the wearer just thought.

## Challenges
Our biggest challenge did not actually involve the headset, but rather was in configuring the networking. The microcontrollers at our disposal had either faulty WiFi chips or were poorly compatible with the debian system we loaded, and therefore we spent many hours struggling trying to get connectivity. We did eventually remedied the problem by using nmcli to manually handle all of the WiFi configuration errors.

Our second biggest challenge was, of course, to interpret the headset data. The data is a two-way stream over a Bluetooth serial connection, as binary message of 150 characters long. We must manually send keep-alive responses and command the headset to send the different types of metrics it supports. For example, we must push fff to get readings from the forehead and ears, but ffff to read the gyro, accelerometer, etc.

We're proud of our adversity, diligence, and our ability to weave this project together.

### The Team
We're a team of four undergraduate students from the University of North Texas, studying computer science and engineering.

The possibilities are endless for MindPhreak.
