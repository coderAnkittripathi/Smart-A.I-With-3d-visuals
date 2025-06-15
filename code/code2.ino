#include <WiFi.h>
#include <HTTPClient.h>
#include "esp_camera.h"
#include <FS.h>
#include <SD_MMC.h>
#include <TFT_eSPI.h>   
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

// Replace with your credentials
const char* ssid = "my_SSID";
const char* password = "my_PASSWORD";

TFT_eSPI tft = TFT_eSPI();  

void setup() {
  Serial.begin(115200);
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); 

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(2);
  tft.println("Hello Ankit!");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  if (!SD_MMC.begin()) {
    Serial.println("SD Card Mount Failed");
    return;
  }

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer   = LEDC_TIMER_0;
  config.pin_d0       = 5;
  config.pin_d1       = 18;
  config.pin_d2       = 19;
  config.pin_d3       = 21;
  config.pin_d4       = 36;
  config.pin_d5       = 39;
  config.pin_d6       = 34;
  config.pin_d7       = 35;
  config.pin_xclk     = 0;
  config.pin_pclk     = 22;
  config.pin_vsync    = 25;
  config.pin_href     = 23;
  config.pin_sscb_sda = 26;
  config.pin_sscb_scl = 27;
  config.pin_pwdn     = 32;
  config.pin_reset    = -1;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size   = FRAMESIZE_QVGA;
  config.jpeg_quality = 12;
  config.fb_count     = 1;

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  // Simulated wake command
  delay(2000);
  speak("Hello, I am Ankit's assistant.");
  showHologram("assistant_image.jpg");
}

void loop() {
  // Simulate image request
  delay(10000);
  captureImage();
  speak("This is a bottle.");  
}
 

void captureImage() {
  camera_fb_t *fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Camera capture failed");
    return;
  }

  File file = SD_MMC.open("/photo.jpg", FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open file");
    return;
  }

  file.write(fb->buf, fb->len);
  file.close();
  esp_camera_fb_return(fb);
  Serial.println("Image captured and saved");
}

void speak(String msg) {
  Serial.println("Speaking: " + msg);
}

void showHologram(String filename) {
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(10, 40);
  tft.setTextColor(TFT_CYAN);
  tft.println("Visualizing...");
}
 
