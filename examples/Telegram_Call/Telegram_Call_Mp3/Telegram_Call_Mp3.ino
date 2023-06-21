/**
 * @file Telegram_Call_Mp3.ino
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief Example Telegram Call Mp3
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
// username : @username or phonenumber (Indonesia +62, Example: "+62897461238")
// You need to authorize CallMeBot to contact you using this link : https://api2.callmebot.com/txt/login.php. 
// Or alternatively, you can start the bot sending /start to @CallMeBot_txtbot.
String username = "@your_username/phonenumber";
String mp3link = "your_mp3_link";

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

	// Telegram Call
	Callmebot.telegramCallMp3(username, mp3link);
	Serial.println(Callmebot.debug());
}

void loop() {
	
}