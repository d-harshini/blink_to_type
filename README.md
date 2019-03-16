# blink_to_type
Processing eyeblink EMG signals on OpenVibe to use functionalities of Windows On Screen Keyboard in any active application.

Software used-
1. Openvibe 2.1.0
2. Visual studio 2015

Mindwave Manager - connect your headset to the Mindwave manager on a recognised port. Ensure the drivers in device manager read Mindwave USB Adapter.

Thinkgear Connector - Edit preferences to change the port number to the one where connection was established to headset.

Openvibe acquisition server - Select your device from the list and choose the correct port numbers and the signals you want to acquire. Ensure the noise levels are as desired.

Openvibe designer - Run the suitable .xml files to acquire the signal, process it, train the classifier and for testing. Send the required values via a VRPN server.

Visual studio - compile vrpn_client.cpp and sendkey.py to generate vrpn_client.exe application

Run vrpn_client.exe to send data to the On Screen Keyboard.

On Screen Keyboard- Make changes in the Options regarding speed of scanning and the key to be pressed to select.

Notepad - A basic active application to check the working.
