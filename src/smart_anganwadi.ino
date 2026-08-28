
Docs

#define BLYNK_TEMPLATE_ID "TMPL3Fv7NlUX8"
#define BLYNK_TEMPLATE_NAME "esp32"
#define BLYNK_AUTH_TOKEN "3e3nMluztXM2-Xmj9zmmFL7biE8zrD9b"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ----------- WIFI ---------------
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// ----------- ThingSpeak ----------
String apiKey = "XFUQP3WK51JFMZ3O";
const char* server = "api.thingspeak.com";

// ---------- VARIABLES ------------
float height_cm = 100;
float weight_kg = 15;
float bmi = 0;
float zScore = 0;
float predictedWeight = 0;

String statusStr = "";
String aiStatus = "";

int attendance = 0;
bool alertSent = false;

// ---------- FUNCTIONS ------------

float calculateBMI(float w, float h) {
  float h_m = h / 100.0;
  if (h_m == 0) return 0;
  return w / (h_m * h_m);
}

float calculateZ(float h, float w) {
  return (w - 12.5);
}

String getStatus(float bmi) {
  if (bmi < 14) return "Severe";
  else if (bmi < 15) return "Moderate";
  else if (bmi < 18.5) return "Underweight";
  else return "Normal";
}

float predictWeight(float height) {
  return (height - 100) * 0.9;
}

String getAIStatus(float actual, float predicted) {
  if (actual < predicted - 2) return "Underweight Risk";
  else if (actual > predicted + 2) return "Overweight";
  else return "Healthy";
}

// ------------ SETUP --------------
void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, pass);
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  randomSeed(analogRead(0));
}

// ---------- SEND TO THINGSPEAK ----------
void sendToThingSpeak() {
  WiFiClient client;
  if (client.connect(server, 80)) {
    String postStr = "api_key=" + apiKey;
    postStr += "&field1=" + String(height_cm);
    postStr += "&field2=" + String(weight_kg);
    postStr += "&field3=" + String(bmi);
    postStr += "&field4=" + String(zScore);
    postStr += "&field5=" + String(attendance);
    postStr += "&field6=" + String(predictedWeight);
    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: " + String(postStr.length()) + "\n\n");
    client.print(postStr);

    Serial.println("Uploaded to ThingSpeak!");
  }
}

// ------------ MAIN LOOP --------------
void loop() {
  Blynk.run();

  // 🔥 SMOOTH RANDOM CHANGE
  height_cm += random(-2, 3);   // small variation
  weight_kg += random(-1, 2);

  // limit values
  height_cm = constrain(height_cm, 80, 130);
  weight_kg = constrain(weight_kg, 10, 25);

  // attendance simulate
  attendance = random(0, 2);

  // ---------- CALCULATIONS ----------
  bmi = calculateBMI(weight_kg, height_cm);
  zScore = calculateZ(height_cm, weight_kg);
  statusStr = getStatus(bmi);

  // 🤖 AI
  predictedWeight = predictWeight(height_cm);
  aiStatus = getAIStatus(weight_kg, predictedWeight);

  // 🔔 ALERT
  if ((bmi < 14 || aiStatus == "Underweight Risk") && !alertSent) {
    Blynk.logEvent("malnutrition_alert", "⚠️ Child Health Risk!");
    alertSent = true;
  }

  // ---------- SERIAL ----------
  Serial.println("------ DATA ------");
  Serial.print("Height: "); Serial.println(height_cm);
  Serial.print("Weight: "); Serial.println(weight_kg);
  Serial.print("BMI: "); Serial.println(bmi);
  Serial.print("Predicted: "); Serial.println(predictedWeight);
  Serial.print("AI Status: "); Serial.println(aiStatus);

  // ---------- BLYNK ----------
  Blynk.virtualWrite(V0, height_cm);
  Blynk.virtualWrite(V1, weight_kg);
  Blynk.virtualWrite(V2, bmi);
  Blynk.virtualWrite(V3, zScore);
  Blynk.virtualWrite(V4, attendance);
  Blynk.virtualWrite(V5, statusStr);
  Blynk.virtualWrite(V6, predictedWeight);
  Blynk.virtualWrite(V7, aiStatus);

  // ---------- THINGSPEAK ----------
  sendToThingSpeak();

  delay(15000);
}
Simulation
