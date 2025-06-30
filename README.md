# Group_2

**Project**: Real-Time IoT Monitoring System using ESP32, MQTT, Node-RED, InfluxDB, and Grafana
**Goal**: Read temperature from a DHT11 sensor with ESP32 and send the data to Grafana

---------------------------------------------------

### 1. Wire DHT11 to ESP32
![IMG_20250624_114434_627](https://github.com/user-attachments/assets/aaa55c7c-d2f1-445c-a8bf-84e01116e2b0)
![IMG_20250624_114502_954](https://github.com/user-attachments/assets/f94c8293-35d6-442b-9113-21ad07159a18)

### 2-3. Code for temperature reading and displaying in serial monitor:
  First, ensure that the ESP32 board is already wired to your device.
  The code is located in the (esp32-mqtt) folder.

### 4. Connect ESP32 with WIFI
  ![image](https://github.com/user-attachments/assets/81b409cb-4e38-40e4-8648-e1f1d4f21fcb)
  First, locate this part of the code. Then just fill in the credentials of the wifi that you are currently connected to in the required fields.
  The MQTT part will be mentioned in the next step.

### 5-6. What is *MQTT*, and how do we send data from ESP32 to MQTT?
  According to the official MQTT website, *MQTT* is an OASIS standard messaging protocol for the Internet of Things (IoT). It is designed as an extremely lightweight publish/subscribe messaging transport that is ideal for connecting remote devices with a small code footprint and minimal network bandwidth. 
  Now, to send data from ESP32 to MQTT, we will be using **Mosquitto**, which is an open-source MQTT broker.  
  ***WINDOWS:*** MQTT Broker (Mosquitto) setup:  
  Link: ![Hosting a Mosquitto Server on Windows: A Step-by-Step Tutorial](https://shop.theengs.io/blogs/news/installing-mosquitto-on-windows-and-make-it-accessible-from-your-local-network)  
  The website includes:
  - Installing and making Mosquitto accessible from your local network
  - Configuring Windows Firewall to allow port 1883 through to run Mosquitto properly
  - Creating users/passwords
  - Editing your *mosquitto.conf* file to make it run smoothly on your local device

  Next, install MQTT Explorer from this link: ![MQTT Explorer](https://mqtt-explorer.com)
  What is MQTT Explorer? -> MQTT Explorer is a comprehensive MQTT client that provides a structured overview of your MQTT topics and makes working with devices/services on your broker dead-simple.

  After setting Mosquitto up, you should have a user & pass prepared. Fill in the necessary fields below in the code:
  ![image](https://github.com/user-attachments/assets/6f0c225f-c83d-4bfd-b29f-fb7e5b2df2e0)
  For the mqtt_server area, you fill it with your IP address as you are running it locally on your device. Run "ipconfig" in Command Prompt, then copy & paste your IPv4 Address into the field.

  Now, let's use MQTT Explorer to see the data update in real time.
  ![image](https://github.com/user-attachments/assets/b8ee38c4-a67c-4f0c-920e-990a64ae76df)
  For 'name', just name it whatever you want.
  For 'host', copy and paste your IPv4 address. Keep the port the same.
  For 'username' and 'password', fill them in again like you did earlier.
  Click connect, then you should be able to see the sensor. Click it, then you'll be able to see the data on the MQTT broker.


---------------------------------------------------

### 1. Set up Node-RED and InfluxDB
  *To set up Node-RED:
  1. Go to: https://nodered.org
  2. Click get started -> run locally -> getting started -> running locally
  3. The website then provides you with detailed information on how to download and set it up on your local device properly.

  ***Optional but recommended***: Use pm2 to run Node-RED
  4. On cmd prompt, type: "npm install pm2 -g"
  5. Type: "pm2 start cmd --name nodered -- /c "node-red"
  (Why use PM2? -> PM2 can automatically restart your application if it crashes and automatically reload your application when you update your code. PM2 enables easy monitoring and works like a health tracker for your node app. It shows memory usage states and more in a centralized dashboard. PM2 allows you to manage multiple Node.)

  6. The command will execute, and you will have to click on the link that says "Server now running at... " 
  7. To stop running the command, just type "pm2 kill" and then it should end.

  *To set up InfluxDB:
  1. Go to: https://www.influxdata.com/downloads/
  2. Scroll and find InfluxDB OSS 1.x
  3. Change 'Platform' settings to fit your own needs

...
  


