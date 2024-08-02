# Wi-Fi-LEDs-controller-using-ESP3
## 20 LEDs controller using ESP32 through Wi-Fi

#### Wi-Fi 20 LEDs controller using ESP32 IOT application This project demonstrates how to connect an ESP32 microcontroller to Wi-Fi and control 20 LEDs through web browser in Wi-Fi network.

## Table of Contents 
*Installation*
*Usage*

## Installation

### Follow these steps to clone and Uploading and Running Code on ESP32:

### 1.Set Up Arduino IDE:

	Install the Arduino IDE from Arduino's official website. 

	Open Arduino IDE and go to File > Preferences. Click OK to close the Preferences window.

### 2.Install ESP32 Board Package:
 
	Go to Tools > Board > Board Manager. Search for "ESP32" and install the "esp32" by Espressif Systems package.

### 3.Select Board and Port:

	Go to Tools > Board and select your ESP32 board (e.g., ESP32 Dev Module). 

	Go to Tools > Port and select the port to which your ESP32 is connected.
## Usage

### 1.Follow these steps to clone and run the project on your ESP32. 
	Clone the repository:
	(git clone https://github.com/antonkingsley/wi_fi_20_LED-Lamp_controller.git)

### 2.Upload Code to ESP32:

	Open the ESP32_Web_Server_20_LED.ino file in Arduino IDE. 

	Click the Upload button (right arrow icon) to compile and upload the code to ESP32

### 3.Open Serial Monitor:

	After uploading, go to Tools > Serial Monitor. Set the baud rate to 115200 (or adjust according to your code).

### 4.Obtaining IP Address from Serial Monitor:

	To get the IP address of your ESP32 over Wi-Fi. Ensure Wi-Fi Initialization in Code. 

	Make sure your code includes Wi-Fi initialization and connection setup.

#### Here’s a basic example: 

	const char ssid = "YourSSID";

	const char password = "YourPassword";

	Once connected to Wi-Fi, the ESP32 will print its IP address to the Serial Monitor.

	Open a web browser and enter the IP address to access the ESP32 web server or other services.




