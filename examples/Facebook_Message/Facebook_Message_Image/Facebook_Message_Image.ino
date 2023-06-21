/**
 * @file Facebook_Message_Image.ino
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief Example Facebook Message
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/Callmebot_ESP_Client
 */

#include <ESP8266WiFi.h>
#include <Callmebot_ESP_Client.h>

const char* ssid = "your_ssid";
const char* password = "your_password";

// Note :
// apiKey : Follow instruction on https://www.callmebot.com/blog/free-api-facebook-messenger/
String apiKey = "your_apiKey";
String imglink = "your_image_link";

void setup() {
	Serial.begin(115200);

	WiFi.begin(ssid, password);
	Serial.println("Connecting");
	while(WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	Serial.println("");
	Serial.print("Connected to WiFi network with IP Address: ");
	Serial.println(WiFi.localIP());
	
	Callmebot.begin();

	// Facebook Message
	Callmebot.facebookMessageImg(apiKey, imglink);
	Serial.println(Callmebot.debug());
}

void loop() {
	
}