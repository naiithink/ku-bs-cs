//Pin Connect
//Arduino Tx -> RS485 DI
//Arduino Rx <- RS485 RO
//GPIO EN -> RE,DE

/*
 * If someone is curios about the Modbus RTU request bytes. They are:
station address
function - 0x03 Read Multiple Holding Registers
register address - 2 bytes
number of registers to read - 2 bytes
checksum - 2 bytes

The response:

station address return
function or error code
data length
data - length bytes
checksum - 2 bytes*/
#include <OneWire.h>
#include <DallasTemperature.h>

#include "Crc16.h"
#define RS485Enable_pin 7
#define RS485Transmit    HIGH
#define RS485Receive     LOW


// co2
const int co2SlaveAddress9 = 9;
const int co2SlaveAddress10 = 10;
const int co2SlaveAddress11 = 11;
const int Modbusfunction = 0x03; // Read Multiple Holding Registers
const int StartingAddress = 0x02;
const int DataLength = 0x01;

byte rawData[200];
unsigned int co2ValueAddress9 = 0;
unsigned int co2ValueAddress10 = 0;
unsigned int co2ValueAddress11 = 0;
// co2

// temp humi lux
const int thlSlaveAddress6 = 6;
const int thlSlaveAddress7 = 7;
const int thlSlaveAddress8 = 8;
const int thlModbusfunction = 0x03; // Read Multiple Holding Registers
const int thlStartingAddress = 0x00;
const int thlDataLength = 0x03;
float humidityAddress6 = 0;
float humidityAddress7 = 0;
float humidityAddress8 = 0;
float temperatureAddress6 = 0 ;
float temperatureAddress7 = 0 ;
float temperatureAddress8 = 0 ;
float lightAddress6 = 0;
float lightAddress7 = 0;
float lightAddress8 = 0;
// temp humi lux

// wind speed
const int windSlaveAddress12 = 12;
const int windSlaveAddress13 = 13;
const int windSlaveAddress14 = 14;
const int windModbusfunction = 0x03; // Read Multiple Holding Registers
const int windStartingAddress = 0x00;
const int windDataLength = 0x01;
float windSpeedAddress12  = 0;
float windSpeedAddress13  = 0;
float windSpeedAddress14  = 0;

// wind speed

// energy power

const int epSlaveAddress15 = 15;
const int epModbusfunction = 0x04; // Read Multiple Holding Registers
const int epStartingAddress = 0x00;
const int epDataLength = 0x0A;
float voltage = 0, current = 0, power = 0,  frequency = 0, powerFactor = 0 ;
long int energy = 0, alarm = 0;

// energy power

// ec
const int ecSlaveAddress1 = 0x01;
const int ecModbusfunction = 0x03; // Read Multiple Holding Registers
const int ecStartingAddress = 0x00;
const int ecDataLength = 0x02;

float ecCalibrationValue = 0, ecValue = 0;
// ec

// ph
const int phSlaveAddress3 = 3;
const int phModbusfunction = 0x03; // Read Multiple Holding Registers
const int phStartingAddress = 0x00;
const int phDataLength = 0x01;
float ph  = 0;

// ph

// water temp

#define ONE_WIRE_BUS_Pin 8
#define TempResolutionBit 10

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS_Pin);
DallasTemperature sensors(&oneWire);
DeviceAddress waterTempAddress = {0x28, 0xE7, 0x1B, 0x76, 0xE0, 0x01, 0x3C, 0x01};

float waterTemp = 0.0;
// water temp

int count = 0;
bool ReceivedData = false;


//Crc 16 library (XModem)
Crc16 crc; 

void resetValue();
void printDebugAllValue();

void setup() 
{
  Serial.begin(9600); // for debug
  Serial2.begin(9600);
  pinMode(RS485Enable_pin,OUTPUT);
  crc.clearCrc();
  // water temp config
  sensors.begin();
  sensors.setResolution(waterTempAddress, TempResolutionBit);
  // water temp config
}

void loop() 
{

  Serial.println("start ========== Water Temp ===============");
  Serial.print("Number of Devices found on bus = ");  
  Serial.println(sensors.getDeviceCount());
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  Serial.println("DONE");

  waterTemp = sensors.getTempC(waterTempAddress);
  
  Serial.println("end ========== Water Temp ===============");

  
  Serial.println("start ========== CO2 ===============");
  byte data9[] = {co2SlaveAddress9, Modbusfunction, 0x00, StartingAddress, 0x00, DataLength}; 
  // Modbus CRC calculation
  crc.clearCrc();
  unsigned int value9 = crc.Modbus(data9,0,sizeof(data9)); // 0 to upper bound;
  data9[sizeof(data9)] = value9&0x00FF;
  data9[sizeof(data9)+1] = (value9&0xFF00)>>8;

  delay(10);
  digitalWrite(RS485Enable_pin,RS485Transmit);
  Serial2.write(data9,sizeof(data9)+2);
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Receive);
  delay(100);  

  
  byte data10[] = {co2SlaveAddress10, Modbusfunction, 0x00, StartingAddress, 0x00, DataLength}; 
  // Modbus CRC calculation
  crc.clearCrc();
  unsigned int value10 = crc.Modbus(data10,0,sizeof(data10)); // 0 to upper bound;
  data10[sizeof(data10)] = value10&0x00FF;
  data10[sizeof(data10)+1] = (value10&0xFF00)>>8;


  delay(10);
  digitalWrite(RS485Enable_pin,RS485Transmit);
  Serial2.write(data10,sizeof(data10)+2);
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Receive);
  delay(100);  


  
  byte data11[] = {co2SlaveAddress11, thlModbusfunction, 0x00, StartingAddress, 0x00, DataLength}; 
  // Modbus CRC calculation
  crc.clearCrc();
  unsigned int value11 = crc.Modbus(data11,0,sizeof(data11)); // 0 to upper bound;
  data11[sizeof(data11)] = value11&0x00FF;
  data11[sizeof(data11)+1] = (value11&0xFF00)>>8;

  
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Transmit);
  Serial2.write(data11,sizeof(data11)+2);
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Receive);
  delay(100);   

  
  Serial.println("end ========== C0 2===============");

  Serial.println("start ========== wind speed ===============");

  byte data12[] = {windSlaveAddress12, windModbusfunction, 0x00, windStartingAddress, 0x00, windDataLength}; 
  // Modbus CRC calculation
  crc.clearCrc();
  unsigned int value12 = crc.Modbus(data12,0,sizeof(data12)); // 0 to upper bound;
  data12[sizeof(data12)] = value12&0x00FF;
  data12[sizeof(data12)+1] = (value12&0xFF00)>>8;
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Transmit);
//  for(int i=0;i<=sizeof(data12)+1;i++)
//  {
//    Serial2.write(data12[i]);
//  }
  Serial2.write(data12,sizeof(data12)+2);
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Receive);
  delay(100);

  byte data13[] = {windSlaveAddress13, windModbusfunction, 0x00, windStartingAddress, 0x00, windDataLength}; 
  // Modbus CRC calculation
  crc.clearCrc();
  unsigned int value13 = crc.Modbus(data13,0,sizeof(data13)); // 0 to upper bound;
  data13[sizeof(data13)] = value13&0x00FF;
  data13[sizeof(data13)+1] = (value13&0xFF00)>>8;

  delay(10);
  digitalWrite(RS485Enable_pin,RS485Transmit);
//  for(int i=0;i<=sizeof(data13)+1;i++)
//  {
//    Serial2.write(data13[i]);
//  }
  Serial2.write(data13,sizeof(data13)+2);
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Receive);
  delay(100);

  
  byte data14[] = {windSlaveAddress14, windModbusfunction, 0x00, windStartingAddress, 0x00, windDataLength}; 
  // Modbus CRC calculation
  crc.clearCrc();
  unsigned int value14 = crc.Modbus(data14,0,sizeof(data14)); // 0 to upper bound;
  data14[sizeof(data14)] = value14&0x00FF;
  data14[sizeof(data14)+1] = (value14&0xFF00)>>8;
  
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Transmit);
//  for(int i=0;i<=sizeof(data14)+1;i++)
//  {
//    Serial2.write(data14[i]);
//  }
  Serial2.write(data14,sizeof(data14)+2);
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Receive);
  delay(100);
  Serial.println("end ========== wind speed ===============");

  
  Serial.println("start ========== temp humi lux ===============");

  byte data6[] = {thlSlaveAddress6, thlModbusfunction, 0x00, thlStartingAddress, 0x00, thlDataLength}; 
  // Modbus CRC calculation
  crc.clearCrc();
  unsigned int value6 = crc.Modbus(data6,0,sizeof(data6)); // 0 to upper bound;
  data6[sizeof(data6)] = value6&0x00FF;
  data6[sizeof(data6)+1] = (value6&0xFF00)>>8;
  
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Transmit);
//  for(int i=0;i<=sizeof(data6)+1;i++)
//  {
//    Serial2.write(data6[i]);
//  }
  Serial2.write(data6,sizeof(data6)+2);
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Receive);
  delay(100);
 
 
  byte data7[] = {thlSlaveAddress7, thlModbusfunction, 0x00, thlStartingAddress, 0x00, thlDataLength}; 
  // Modbus CRC calculation
  crc.clearCrc();
  unsigned int value7 = crc.Modbus(data7,0,sizeof(data7)); // 0 to upper bound;
  data7[sizeof(data7)] = value7&0x00FF;
  data7[sizeof(data7)+1] = (value7&0xFF00)>>8;

  delay(10);
  digitalWrite(RS485Enable_pin,RS485Transmit);
//  for(int i=0;i<=sizeof(data7)+1;i++)
//  {
//    Serial2.write(data7[i]);
//  }
  Serial2.write(data7,sizeof(data7)+2);
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Receive);
  delay(100);
  

  byte data8[] = {thlSlaveAddress8, thlModbusfunction, 0x00, thlStartingAddress, 0x00, thlDataLength}; 
  // Modbus CRC calculation
  crc.clearCrc();
  unsigned int value8 = crc.Modbus(data8,0,sizeof(data8)); // 0 to upper bound;
  data8[sizeof(data8)] = value8&0x00FF;
  data8[sizeof(data8)+1] = (value8&0xFF00)>>8;
  
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Transmit);
//  for(int i=0;i<=sizeof(data8)+1;i++)
//  {
//    Serial2.write(data8[i]);
//  }
  Serial2.write(data8,sizeof(data8)+2);
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Receive);
  delay(100);


  Serial.println("end ========== temp humi lux ===============");

  Serial.println("start ========== Energy Power ===============");
  
  byte data15[] = {epSlaveAddress15, epModbusfunction, 0x00, epStartingAddress, 0x00, epDataLength}; 
  // Modbus CRC calculation
  crc.clearCrc();
  unsigned int value15 = crc.Modbus(data15,0,sizeof(data15)); // 0 to upper bound;
  data15[sizeof(data15)] = value15&0x00FF;
  data15[sizeof(data15)+1] = (value15&0xFF00)>>8;
  
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Transmit);
  Serial2.write(data15,sizeof(data15)+2);
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Receive);
  delay(100);
  
  Serial.println("end ========== Energy Power ===============");

  Serial.println("start ========== EC ===============");

  byte data1[] = {ecSlaveAddress1, ecModbusfunction, 0x00, ecStartingAddress, 0x00, ecDataLength}; 
  // Modbus CRC calculation
  crc.clearCrc();
  unsigned int value1 = crc.Modbus(data1,0,sizeof(data1)); // 0 to upper bound;
  data1[sizeof(data1)] = value1&0x00FF;
  data1[sizeof(data1)+1] = (value1&0xFF00)>>8;
  
  digitalWrite(RS485Enable_pin,RS485Transmit);
  Serial2.write(data1,sizeof(data1)+2);
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Receive);
  delay(100);

  Serial.println("end ========== EC ===============");
  
  Serial.println("start ========== PH ===============");

  byte data3[] = {phSlaveAddress3, phModbusfunction, 0x00, phStartingAddress, 0x00, phDataLength}; 
  // Modbus CRC calculation
  crc.clearCrc();
  unsigned int value3 = crc.Modbus(data3,0,sizeof(data3)); // 0 to upper bound;
  data3[sizeof(data3)] = value3&0x00FF;
  data3[sizeof(data3)+1] = (value3&0xFF00)>>8;

  digitalWrite(RS485Enable_pin,RS485Transmit);
  Serial2.write(data3,sizeof(data3)+2);
  delay(10);
  digitalWrite(RS485Enable_pin,RS485Receive);
  delay(100);
  Serial.println("end ========== PH ===============");



  

  
  
  looping();

  if(ReceivedData == true)
  {
    readData();
  }
  delay(5000);
  
}
void looping(){
  Serial.println("start looping");
  unsigned long starttime = millis();
  unsigned long endtime = starttime;
  while ((endtime - starttime) <=1000) // do this loop for up to 1000mS
  {
  endtime = millis();
  }
  Serial.println("end looping");
}



void readData(){
  Serial.print("Count = ");
  Serial.println(count);

  int i = 0;
  while (i < count){
    int addr = int(rawData[i]);
    Serial.print("i = ");
    Serial.print(i);
    Serial.print("address = ");
    Serial.println(addr);
    if ((addr == ecSlaveAddress1) && (rawData[i+2] == 4)){
      ecCalibrationValue = (float)((rawData[i+3]<<8) + rawData[i+4])/10;
      ecValue = (float)((rawData[i+5]<<8) + rawData[i+6])/10;
      
    }else if ((addr == phSlaveAddress3) && (rawData[i+2] == 2)){
      ph = (float)((rawData[i+3]<<8) + rawData[i+4])/100;
      i += 7;
    }else if ((addr == thlSlaveAddress6) && (rawData[i+2] == 6)){
      humidityAddress6 = (float)((rawData[i+3]<<8) + rawData[i+4])/10;
      temperatureAddress6 = (float)((rawData[i+5]<<8) + rawData[i+6])/10;
      lightAddress6 = (float)((rawData[i+7]<<8) + rawData[i+8]);
      i += 11;
    }else if ((addr == thlSlaveAddress7) && (rawData[i+2] == 6)){
      humidityAddress7 = (float)((rawData[i+3]<<8) + rawData[i+4])/10;
      temperatureAddress7 = (float)((rawData[i+5]<<8) + rawData[i+6])/10;
      lightAddress7 = (float)((rawData[i+7]<<8) + rawData[i+8]);
      i += 11;
    }else if ((addr == thlSlaveAddress8) && (rawData[i+2] == 6)){
      humidityAddress8 = (float)((rawData[i+3]<<8) + rawData[i+4])/10;
      temperatureAddress8 = (float)((rawData[i+5]<<8) + rawData[i+6])/10;
      lightAddress8 = (float)((rawData[i+7]<<8) + rawData[i+8]);
      i += 11;
    }else if ((addr == co2SlaveAddress9) && (rawData[i+2] == 2)){
      co2ValueAddress9 = ((rawData[i+3]<<8) + rawData[i+4]);
      i += 7;
    }else if ((addr == co2SlaveAddress10) && (rawData[i+2] == 2)){
      co2ValueAddress10 = ((rawData[i+3]<<8) + rawData[i+4]);
      i += 7;
    }else if ((addr == co2SlaveAddress11) && (rawData[i+2] == 2)){
      co2ValueAddress11 = ((rawData[i+3]<<8) + rawData[i+4]);
      i += 7;
    }else if ((addr == windSlaveAddress12) && (rawData[i+2] == 2)){
      windSpeedAddress12 = (float)((rawData[i+3]<<8) + rawData[i+4])/10;
      i += 7;
    }else if ((addr == windSlaveAddress13) && (rawData[i+2] == 2)){
      windSpeedAddress13 = (float)((rawData[i+3]<<8) + rawData[i+4])/10;
      i += 7;
    }else if ((addr == windSlaveAddress14) && (rawData[i+2] == 2)){
      windSpeedAddress14 = (float)((rawData[i+3]<<8) + rawData[i+4])/10;
      i += 7;
    }else if ((addr == epSlaveAddress15) && (rawData[i+2] == 0x14)){
      voltage = (float)((rawData[i+3]<<8) + rawData[i+4])/10;
      current = (float)((rawData[i+7]<<24) + (rawData[i+8]<<16) + (rawData[i+5]<<8) + rawData[i+6])/1000;
      power = (float)((rawData[i+11]<<24) + (rawData[i+12]<<16) + (rawData[i+9]<<8) + rawData[i+10])/10;
      energy = ((rawData[i+15]<<24) + (rawData[i+16]<<16) + (rawData[i+13]<<8) + rawData[i+14]);
      frequency = (float)((rawData[i+17]<<8) + rawData[i+18])/10;
      powerFactor = (float)((rawData[i+19]<<8) + rawData[i+20])/100;
      alarm = ((rawData[i+21]<<8) + rawData[i+22]);
      i += 25;
    }
    else {
      i += 1;
    }
 
  }
  
  

      
  memset(rawData,0,sizeof(rawData));
  Serial.println();
  ReceivedData = false;
  printDebugAllValue();
  resetValue();
}

void serialEvent2() // Read Data from RS485 ModBus RTU
{ 
  count = 0;
  Serial.print("Receive Data = ");
  while(Serial2.available()) 
  {
    byte respone = Serial2.read();
    rawData[count] = respone;
    count++;
    if(respone <= 15)Serial.print("0");
    Serial.print(respone,HEX);
    Serial.print(" ");
  }
  Serial.println();
  ReceivedData = true;
  Serial2.flush();
 
}

void resetValue(){
  humidityAddress6 = 0;
  humidityAddress7 = 0;
  humidityAddress8 = 0;
  temperatureAddress6 = 0 ;
  temperatureAddress7 = 0 ;
  temperatureAddress8 = 0 ;
  lightAddress6 = 0;
  lightAddress7 = 0;
  lightAddress8 = 0;
  co2ValueAddress9 = 0;
  co2ValueAddress10 = 0;
  co2ValueAddress11 = 0;
  windSpeedAddress12  = 0;
  windSpeedAddress13  = 0;
  windSpeedAddress14  = 0;
  voltage = 0;
  current = 0;
  power = 0;
  energy = 0;
  frequency = 0;
  powerFactor = 0;
  alarm = 0;
  ecCalibrationValue = 0;
  ecValue = 0;
  ph = 0;
  waterTemp = 0;
}

void printDebugAllValue(){
  Serial.println("EC calibration Value = " + String(ecCalibrationValue) + " us/cm");
  Serial.println("EC Value = " + String(ecValue) + " us/cm");
  Serial.println("pH Value = " + String(ph));
  Serial.println("Humidity Value 6 = " + String(humidityAddress6) + " %");
  Serial.println("Temperature Value 6 = " + String(temperatureAddress6) + " °c");
  Serial.println("Light Value 6 = " + String(lightAddress6) + " lux");
  Serial.println("Humidity Value 7 = " + String(humidityAddress7) + " %");
  Serial.println("Temperature Value 7 = " + String(temperatureAddress7) + " °c");
  Serial.println("Light Value 7 = " + String(lightAddress7) + " lux");
  Serial.println("Humidity Value 8 = " + String(humidityAddress8) + " %");
  Serial.println("Temperature Value 8 = " + String(temperatureAddress8) + " °c");
  Serial.println("Light Value 8 = " + String(lightAddress8) + " lux");
  Serial.println("CO2  Value 9 = " + String(co2ValueAddress9) + " ppm");
  Serial.println("CO2  Value 10 = " + String(co2ValueAddress10) + " ppm");
  Serial.println("CO2  Value 11 = " + String(co2ValueAddress11) + " ppm");
  Serial.println("Wind speed 12 = " + String(windSpeedAddress12) + " m/s");
  Serial.println("Wind speed 13 = " + String(windSpeedAddress13) + " m/s");
  Serial.println("Wind speed 14 = " + String(windSpeedAddress14) + " m/s");
  Serial.println("Voltage = " + String(voltage) + " V");
  Serial.println("Current = " + String(current) + " A");
  Serial.println("Power = " + String(power) + " W");
  Serial.println("Energy = " + String(energy) + " Wh");
  Serial.println("Frequency = " + String(frequency) + " Hz");
  Serial.println("Power Factor = " + String(powerFactor));
  Serial.println("Alarm = " + String(alarm,HEX));
  Serial.print("Water_Temp C temperature is:   ");
  Serial.println(waterTemp);
}

//0B 03 02 04 29 E3 5B 
//06 03 06 02 FC 00 FC 02 BA 16 50 
//07 03 06 03 08 00 FC 01 DA AB 1C 
//0D 03 02 00 00 A8 45 
//0E 03 02 00 03 AC 44 
//
//
//0B 03 02 03 B4 20 C2 
//06 03 06 03 1A 00 FD 02 BD 0E 55 
//07 03 06 03 25 00 FC 01 D9 47 1B 
//0D 03 02 00 00 A8 45 
//E8 FF FF FD FF 
