# AI-Enabled IoT Smart Anganwadi System

An IoT-based smart monitoring system designed to support digital child growth monitoring, attendance tracking and health-status assessment in Anganwadi centres.

The system combines embedded hardware, IoT connectivity and basic data analysis to reduce manual data entry and provide a more organized approach to monitoring children's health-related parameters.

---

## 📌 Project Overview

Anganwadi centres play an important role in monitoring children's growth and providing essential services under the Integrated Child Development Services (ICDS) programme.

Traditional measurement and record-keeping processes can involve manual data entry, which may lead to errors, delays and difficulty in maintaining records.

To address these challenges, we developed an **AI-Enabled IoT Smart Anganwadi System** that collects child-related measurements and attendance information using sensors and sends the data to cloud-based dashboards for monitoring.

The prototype focuses on:

- Digital height and weight measurement
- Attendance monitoring
- BMI calculation
- Z-score based health assessment
- IoT-based data monitoring
- Basic malnutrition-risk assessment
- Cloud dashboard visualization

---

## 🎯 Objectives

- Digitize child growth-monitoring activities.
- Reduce manual errors in recording measurements.
- Monitor height and weight electronically.
- Calculate BMI and related health indicators.
- Track attendance digitally.
- Send collected data to an IoT dashboard.
- Provide an organized view of child health-related information.
- Explore the use of AI/data-based approaches for identifying possible malnutrition risks.

---

## ✨ Key Features

### 1. Digital Height Measurement

A distance/ToF sensing approach is used to obtain the child's height.

### 2. Digital Weight Measurement

A load cell with an HX711 amplifier is used to measure the child's weight.

### 3. Attendance Monitoring

RFID technology is used for digital attendance identification.

### 4. BMI Calculation

The system calculates Body Mass Index (BMI) using the measured height and weight.

### 5. Health Assessment

The collected measurements can be used for basic health-status assessment using BMI and Z-score related parameters.

### 6. IoT Monitoring

The collected information is transmitted to cloud-based platforms for monitoring and visualization.

### 7. Data Visualization

Sensor data can be monitored through IoT dashboards such as Blynk and ThingSpeak.

### 8. Malnutrition Risk Assessment

The project explores the use of data-based/AI-assisted approaches to identify children who may require further health assessment.

> Note: This prototype is intended for educational and demonstration purposes and is not a replacement for professional medical diagnosis.

---

## 🏗️ System Architecture

```text
                Child
                  │
                  ▼
        ┌───────────────────┐
        │  Sensor Modules   │
        │                   │
        │ Height / ToF      │
        │ Weight / LoadCell │
        │ RFID Attendance   │
        └─────────┬─────────┘
                  │
                  ▼
             ┌─────────┐
             │  ESP32  │
             └────┬────┘
                  │
        ┌─────────┴─────────┐
        │                   │
        ▼                   ▼
  Data Processing       IoT Connectivity
        │                   │
        │             ┌─────┴─────┐
        │             │           │
        ▼             ▼           ▼
      BMI /        Blynk      ThingSpeak
   Health Data      Dashboard    Dashboard
        │
        ▼
 Health Status /
 Risk Assessment

⚠️ Disclaimer
This project is an academic prototype developed for learning, demonstration and innovation purposes.
The health-related calculations and risk indications produced by the prototype should not be considered a medical diagnosis or a substitute for professional healthcare assessment.
