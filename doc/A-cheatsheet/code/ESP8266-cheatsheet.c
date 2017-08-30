Hardware Parameters
	Peripheral Bus :
	            * UART/HSPI/Ir Remote Contorl
	            * GPIO/PWM/I2C/I2S/
	          Operating Voltage : 3.0~3.6V
	          Operating Current : ~ 80mA
	          Operating Temperature
	          range : -40°~125°

Software Parameters
	Wi-Fi mode :
	            * Station
	            * SoftAP
	            * SoftAP+station
	Security : WPA/WPA2
	Firmware Upgrade :
	            * UART Download
	            * OTA(via network)
	            * Download and write firmware via host
	Network Protocols :
	            IPv4, TCP/UDP/HTTP/FTP
	User Configuration :
	            * AT Instruction Set
	            * Cloud Server
	            * Android/iOS App

WiFi Paramters
	Certificates  FCC/CE/ROSH
	          WiFi Protocles  802.11 b/g/n
	          Frequency Range 2.4GHz~2.5GHz

    	  +--------+--------+--------+------------------+
          |GPIO_15 | GPIO_0 | GPIO_2 | Mode             |
          +--------+--------+--------+------------------+
          |LOW     | LOW    | HIGH   | Serial Programing|
          +--------+--------+--------+------------------+
          |LOW     | HIGH   | HIGH   | Boot from flash  |
          +--------+--------+--------+------------------+
          |HIGH    | ANY    | ANY    | Boot from SD Card|
          +--------+--------+--------+------------------+


Esp8266 with Arduino
	I/O
	      void pinMode(uint8_t pin, uint8_t mode);
          // mode = INPUT,OUTPUT,INPUT_PULLUP
          void digitalWrite(uint8_t pin, uint8_t value);
          // value = HIGH, LOW
          int digitalRead(uint8_t pin);
          int analogRead(uint8_t pin); // only on A0
          void analogWrite(uint8_t pin, int value);
          // pin : GPIO 0 to GPIO 16
          // value = < from 0 to 1023>
    
    Utils
          unsigned long millis();
          unsigned long micros();
          -----------------------
          void delay(unsigned long time);
          void yield();
          ------------------------
          void ESP.reset();
          uint32_t ESP.getFreeHeap();
          uint32_t ESP.getChipId();

    WiFi Mode

    	  Station
    		//establish station mode
          	WiFi.mode(WIFI_STA);
          	// STA connect to AP
          	WiFi.begin(ssid, password);
          	// disconect to AP
          	bool WiFi.disconnect();
          	// local IP of station
          	WiFi.localIP();
          	//return:  connection statuses
          	WiFi.status();
          	//Return the name of Wi-Fi network
          	WiFi.SSID();
          	// strength of Wi-Fi network
          	WiFi.RSSI();
          	//Start WPS configuration mode
          	WiFi.beginWPSConfig();
          	//Start smart configuration mode
          	beginSmartConfig();
   
          Soft AP
          	//establish a Wi-Fi network.
          	WiFi.softAP(ssid, password);
          	//Configure the soft AP
          	softAPConfig (local_ip, gateway, subnet);
          	//Get the count of the stations
          	WiFi.softAPgetStationNum();
          	//Disconnect stations
          	WiFi.softAPdisconnect(wifioff);
          	//Return IP address of the AP
          	WiFi.softAPIP();
          	//Return MAC address of soft AP
          	WiFi.softAPmacAddress(mac);

    WiFi features

    	  Scan 
    	    //Set WiFi to station mode
            WiFi.mode(WIFI_STA);
            //Scan-available-Wi-Fi networks
            //return number of networks
            WiFi.scanNetworks();
            //Return the SSID of a network
            WiFi.SSID(networkItem);
            //Return all the network information
            WiFi.getNetworkInfo(networkItem,
            &ssid, &encryptionType, &RSSI,
            *&BSSID, &channel, &isHidden)

          Diagnostics
            Use printDiag
            //Wi-Fi diagnostic information
            WiFi.printDiag(Serial);
            //Enable Wi-Fi Diagnostic
            Serial.setDebugOutput(true)

          WebServer
            //TCP server at port 80 will respond
            //to HTTP requests
            ESP8266WebServer server (80);
            //write data to all the clients
            server.write(buf, len)
            // initial server
            server.on ( "URL", handleRoot )
            //start listening for clients
            server.begin();
            // webserver interact with esp8266
            server.handleClient();
            //check variable on server
            server.hasArg(variable)
            // get value of variable on server
            server.arg(val_on_server);
            // sent request to update data
            server.send (code, "text/html",
            content);

          MQTT
            #include <ESP8266WiFi.h>
            #include <PubSubClient.h>
            WiFiClient espClient;
            PubSubClient client(espClient);
            static void callback(char* topic,
            byte* payload, unsigned int length) { }
            PubSubClient& client.setServer(
            char* domain, uint16_t port);
            // sets subscribe callback
            PubSubClient& client.setCallback(callback);
            boolean client.connected();
            boolean client.connect(char* id);
            // id = unique ident
            boolean client.publish(char* topic
            , char* payload);
            // publish message
            boolean client.subscribe(char* topic);
            boolean loop(); // in loop

          mDNS