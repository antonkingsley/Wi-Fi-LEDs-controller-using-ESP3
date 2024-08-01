// Load Wi-Fi library
#include <WiFi.h>

// Network credentials Here
const char* ssid     = "ESP32-Network";
const char* password = "Password";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

//variables to store the current LED states
String statePin1 = "off";
String statePin2 = "off";
String statePin3 = "off";
String statePin4 = "off";
String statePin5 = "off";
String statePin12 = "off";
String statePin13 = "off";
String statePin14 = "off";
String statePin15 = "off";
String statePin16 = "off";
String statePin17 = "off";
String statePin18 = "off";
String statePin19 = "off";
String statePin21 = "off";
String statePin22 = "off";


//Output variable to GPIO pins

const int ledPin1 = 1;
const int ledPin2 = 2;
const int ledPin3 = 3;
const int ledPin4 = 4;
const int ledPin5 = 5;
const int ledPin12 = 12;
const int ledPin13 = 13;
const int ledPin14 = 14;
const int ledPin15 = 15;
const int ledPin16 = 16;
const int ledPin17 = 17;
const int ledPin18 = 18;
const int ledPin19 = 19;
const int ledPin21 = 21;
const int ledPin22 = 22;



// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  
  pinMode(ledPin1, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin1, 0);      // turn LED off by default

  pinMode(ledPin2, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin2, 0);      // turn LED off by default

  pinMode(ledPin3, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin3, 0);      // turn LED off by default

  pinMode(ledPin4, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin4, 0);      // turn LED off by default

  pinMode(ledPin5, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin5, 0);      // turn LED off by default

  pinMode(ledPin12, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin12, 0);      // turn LED off by default

  pinMode(ledPin13, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin13, 0);      // turn LED off by default

  pinMode(ledPin14, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin14, 0);      // turn LED off by default

  pinMode(ledPin15, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin15, 0);      // turn LED off by default

  pinMode(ledPin16, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin16, 0);      // turn LED off by default

  pinMode(ledPin17, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin17, 0);      // turn LED off by default

  pinMode(ledPin18, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin18, 0);      // turn LED off by default

  pinMode(ledPin19, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin19, 0);      // turn LED off by default

  pinMode(ledPin21, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin21, 0);      // turn LED off by default

  pinMode(ledPin22, OUTPUT);      // set the LED pin mode
  digitalWrite(ledPin22, 0);      // turn LED off by default


  WiFi.softAP(ssid,password);
  
  // Print IP address and start web server
  Serial.println("");
  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client

    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /1/on") >= 0) {
              statePin1 = "on";
              digitalWrite(ledPin1, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /1/off") >= 0) {
              statePin1 = "off";
              digitalWrite(ledPin1, LOW);                //turns the LED off
            }

            if (header.indexOf("GET /2/on") >= 0) {
              statePin2 = "on";
              digitalWrite(ledPin2, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /2/off") >= 0) {
              statePin2 = "off";
              digitalWrite(ledPin2, LOW);                //turns the LED off
            }

            if (header.indexOf("GET /3/on") >= 0) {
              statePin3 = "on";
              digitalWrite(ledPin3, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /3/off") >= 0) {
              statePin3 = "off";
              digitalWrite(ledPin3, LOW);                //turns the LED off
            }


            if (header.indexOf("GET /4/on") >= 0) {
              statePin4 = "on";
              digitalWrite(ledPin4, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /4/off") >= 0) {
              statePin4 = "off";
              digitalWrite(ledPin4, LOW);                //turns the LED off
            }


            if (header.indexOf("GET /5/on") >= 0) {
              statePin5 = "on";
              digitalWrite(ledPin5, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /5/off") >= 0) {
              statePin5 = "off";
              digitalWrite(ledPin5, LOW);                //turns the LED off
            }


            if (header.indexOf("GET /12/on") >= 0) {
              statePin12 = "on";
              digitalWrite(ledPin12, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /12/off") >= 0) {
              statePin12 = "off";
              digitalWrite(ledPin12, LOW);                //turns the LED off
            }


            if (header.indexOf("GET /13/on") >= 0) {
              statePin13 = "on";
              digitalWrite(ledPin13, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /13/off") >= 0) {
              statePin13 = "off";
              digitalWrite(ledPin13, LOW);                //turns the LED off
            }


            if (header.indexOf("GET /14/on") >= 0) {
              statePin14 = "on";
              digitalWrite(ledPin14, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /14/off") >= 0) {
              statePin14 = "off";
              digitalWrite(ledPin14, LOW);                //turns the LED off
            }


            if (header.indexOf("GET /15/on") >= 0) {
              statePin15 = "on";
              digitalWrite(ledPin15, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /15/off") >= 0) {
              statePin15 = "off";
              digitalWrite(ledPin15, LOW);                //turns the LED off
            }

            
            if (header.indexOf("GET /16/on") >= 0) {
              statePin16 = "on";
              digitalWrite(ledPin16, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /16/off") >= 0) {
              statePin16 = "off";
              digitalWrite(ledPin16, LOW);                //turns the LED off
            }
            
            if (header.indexOf("GET /17/on") >= 0) {
              statePin17 = "on";
              digitalWrite(ledPin17, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /17/off") >= 0) {
              statePin17 = "off";
              digitalWrite(ledPin17, LOW);                //turns the LED off
            }

            if (header.indexOf("GET /18/on") >= 0) {
              statePin18 = "on";
              digitalWrite(ledPin18, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /18/off") >= 0) {
              statePin18 = "off";
              digitalWrite(ledPin18, LOW);                //turns the LED off
            }


            if (header.indexOf("GET /19/on") >= 0) {
              statePin19 = "on";
              digitalWrite(ledPin19, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /19/off") >= 0) {
              statePin19 = "off";
              digitalWrite(ledPin19, LOW);                //turns the LED off
            }


            if (header.indexOf("GET /21/on") >= 0) {
              statePin21 = "on";
              digitalWrite(ledPin21, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /21/off") >= 0) {
              statePin21 = "off";
              digitalWrite(ledPin21, LOW);                //turns the LED off
            }


            if (header.indexOf("GET /22/on") >= 0) {
              statePin22 = "on";
              digitalWrite(ledPin22, HIGH);               // turns the LED on
            } else if (header.indexOf("GET /22/off") >= 0) {
              statePin22 = "off";
              digitalWrite(ledPin22, LOW);                //turns the LED off
            }


            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            client.println("<style>html { font-family: monospace; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println("div {align: center;text-align: center;}");

            client.println(".button { background-color: yellowgreen; border-radius: 12px; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 32px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: red;border-radius: 12px;}</style></head>");
          
            client.println("<body><h1>Lamp</h1>");
            client.println("<p>Lamp Control Pannel </p>");
           

            if (statePin1 == "off") {
              client.println("<p><a href=\"/1/on\"><button class=\"button\">OFF</button></a>");
            } else {
              client.println("<p><a href=\"/1/off\"><button class=\"button button2\">ON</button></a>");
            }

            if (statePin2 == "off") {
              client.println("<a href=\"/2/on\"><button class=\"button\">OFF</button></a>");
            } else {
              client.println("<a href=\"/2/off\"><button class=\"button button2\">ON</button></a>");
            }

            if (statePin3 == "off") {
              client.println("<a href=\"/3/on\"><button class=\"button\">OFF</button></a>");
            } else {
              client.println("<a href=\"/3/off\"><button class=\"button button2\">ON</button></a>");
            }

            if (statePin4 == "off") {
              client.println("<a href=\"/4/on\"><button class=\"button\">OFF</button></a>");
            } else {
              client.println("<a href=\"/4/off\"><button class=\"button button2\">ON</button></a>");
            }

            if (statePin5 == "off") {
              client.println("<a href=\"/5/on\"><button class=\"button\">OFF</button></a></p>");
            } else {
              client.println("<a href=\"/5/off\"><button class=\"button button2\">ON</button></a></p>");
            }
  
            if (statePin12 == "off") {
              client.println("<p><a href=\"/12/on\"><button class=\"button\">OFF</button></a>");
            } else {
              client.println("<p><a href=\"/12/off\"><button class=\"button button2\">ON</button></a>");
            }
          
           if (statePin13 == "off") {
              client.println("<a href=\"/13/on\"><button class=\"button\">OFF</button></a>");
            } else {
              client.println("<a href=\"/13/off\"><button class=\"button button2\">ON</button></a>");
            }
        

            if (statePin14 == "off") {
              client.println("<a href=\"/14/on\"><button class=\"button\">OFF</button></a>");
            } else {
              client.println("<a href=\"/14/off\"><button class=\"button button2\">ON</button></a>");
            }

            if (statePin15 == "off") {
              client.println("<a href=\"/15/on\"><button class=\"button\">OFF</button></a>");
            } else {
              client.println("<a href=\"/15/off\"><button class=\"button button2\">ON</button></a>");
            }

            if (statePin16 == "off") {
              client.println("<a href=\"/16/on\"><button class=\"button\">OFF</button></a></p>");
            } else {
              client.println("<a href=\"/16/off\"><button class=\"button button2\">ON</button></a></p>");
            }

            if (statePin17 == "off") {
              client.println("<p><a href=\"/17/on\"><button class=\"button\">OFF</button></a>");
            } else {
              client.println("<p><a href=\"/17/off\"><button class=\"button button2\">ON</button></a>");
            }

            if (statePin18 == "off") {
              client.println("<a href=\"/18/on\"><button class=\"button\">OFF</button></a>");
            } else {
              client.println("<a href=\"/18/off\"><button class=\"button button2\">ON</button></a>");
            }

           if (statePin19 == "off") {
              client.println("<a href=\"/19/on\"><button class=\"button\">OFF</button></a>");
            } else {
              client.println("<a href=\"/19/off\"><button class=\"button button2\">ON</button></a>");
            }

            if (statePin21 == "off") {
              client.println("<a href=\"/21/on\"><button class=\"button\">OFF</button></a>");
            } else {
              client.println("<a href=\"/21/off\"><button class=\"button button2\">ON</button></a>");
            }

            if (statePin22 == "off") {
              client.println("<a href=\"/22/on\"><button class=\"button\">OFF</button></a></p>");
            } else {
              client.println("<a href=\"/22/off\"><button class=\"button button2\">ON</button></a></p>");
            }

           
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}