# AI-Enabled IoT Smart Anganwadi System

An IoT-based smart monitoring system designed to support digital child growth monitoring, attendance tracking, health-status assessment, and data-driven malnutrition risk analysis in Anganwadi centres.

The system integrates an ESP32 microcontroller, height and weight sensing, RFID-based attendance identification, BMI calculation, IoT cloud connectivity, and real-time dashboards to reduce manual effort and improve the organization of child health-related data.

---

## 📌 Project Overview

Anganwadi centres play an important role in child growth monitoring, nutrition support, and early childhood care under the Integrated Child Development Services (ICDS) framework.

Traditional growth-monitoring processes may involve manual measurement, paper-based record keeping, and delayed reporting. These processes can increase the possibility of recording errors and make continuous monitoring difficult.

To address these challenges, this project proposes an **AI-Enabled IoT Smart Anganwadi System** that combines embedded systems, sensors, IoT connectivity, and data-based health assessment.

The prototype is designed to collect child-related parameters such as:

- Height
- Weight
- BMI
- Z-score-related data
- Attendance
- Health status
- Risk indication

The processed information can then be monitored through IoT dashboards such as **Blynk** and **ThingSpeak**.

---

## 🎯 Objectives

- Automate the collection of child growth-related parameters.
- Reduce manual errors in recording height and weight.
- Calculate BMI automatically using measured height and weight.
- Support digital attendance identification using RFID.
- Process sensor data using an ESP32 microcontroller.
- Transmit processed information to IoT cloud platforms.
- Provide real-time visualization through dashboards.
- Explore data-based approaches for early identification of possible nutritional risks.
- Reduce the workload involved in manual health-data recording.
- Provide a scalable foundation for future smart Anganwadi applications.

---

## ✨ Key Features

### 1. Digital Height Measurement

A distance/ToF sensing approach is used to obtain the required distance information for determining the child's height.

### 2. Digital Weight Measurement

A load cell connected through an HX711 amplifier is used to obtain the child's weight.

### 3. RFID-Based Attendance

An RFID module can be used to identify children and support digital attendance tracking.

### 4. Automatic BMI Calculation

The ESP32 processes height and weight values and calculates BMI automatically.

### 5. Health Status Assessment

The processed measurements are used to generate a basic health-status indication based on the implemented prototype logic.

### 6. Data-Based Risk Assessment

The prototype includes a basic prediction/risk-analysis logic that compares measured and calculated parameters to indicate possible health risks.

### 7. IoT Connectivity

The ESP32 communicates with cloud-based IoT platforms for remote monitoring and data visualization.

### 8. Blynk Dashboard

Blynk can be used to display real-time values such as:

- Height
- Weight
- BMI
- Z-score
- Attendance
- Health status
- Predicted weight
- Risk indication

### 9. ThingSpeak Monitoring

ThingSpeak is used for cloud-based data storage and visualization of selected parameters for historical monitoring.

### 10. Alert Mechanism

The prototype includes an alert mechanism for identifying selected health-risk conditions and notifying the monitoring system.

---

## 🏗️ System Architecture

```text
                         CHILD
                           │
                           ▼
              ┌────────────────────────┐
              │     SENSOR MODULES     │
              │                        │
              │  Height / ToF Sensor   │
              │  Load Cell + HX711     │
              │  RFID Attendance       │
              └───────────┬────────────┘
                          │
                          ▼
                    ┌───────────┐
                    │   ESP32   │
                    │Controller │
                    └─────┬─────┘
                          │
              ┌───────────┴───────────┐
              │                       │
              ▼                       ▼
      ┌────────────────┐      ┌─────────────────┐
      │ Data Processing│      │ IoT Connectivity│
      │                │      │                 │
      │ Height         │      │ Blynk           │
      │ Weight         │      │ ThingSpeak      │
      │ BMI            │      └─────────────────┘
      │ Z-score data   │
      │ Health Status  │
      │ Risk Analysis  │
      └───────┬────────┘
              │
              ▼
      ┌──────────────────┐
      │ Monitoring &     │
      │ Visualization    │
      │                  │
      │ Health Status    │
      │ Risk Indication  │
      │ Historical Data  │
      └──────────────────┘


🔄 Working Principle
Step 1 — Child Identification
The child can be identified using the RFID-based attendance mechanism.

Step 2 — Height Measurement
The height-sensing module collects distance information and uses it to determine the child's height.

Step 3 — Weight Measurement
The load cell measures the child's weight. The HX711 amplifier conditions the load-cell signal before it is processed by the ESP32.

Step 4 — Data Processing
The ESP32 receives the sensor values and performs the required processing.
The system calculates:
Height
Weight
BMI
Z-score-related value
Attendance status
Predicted weight
Health/risk indication

Step 5 — Health Assessment
The processed parameters are evaluated using the implemented prototype logic to provide a basic health-status and risk indication.

Step 6 — IoT Transmission
The ESP32 sends the processed information to configured IoT platforms through Wi-Fi connectivity.

Step 7 — Dashboard Monitoring
The data can be viewed through Blynk and ThingSpeak dashboards for real-time and historical monitoring.

Step 8 — Alert Generation
When the implemented risk conditions are detected, the system can generate an alert through the configured notification mechanism.

📊 Data Flow
RFID / Sensors
      │
      ▼
    ESP32
      │
      ├── Height
      ├── Weight
      ├── Attendance
      │
      ▼
Data Processing
      │
      ├── BMI Calculation
      ├── Z-score-related Data
      ├── Predicted Weight
      └── Risk Analysis
      │
      ▼
IoT Cloud Platforms
      │
      ├── Blynk
      └── ThingSpeak
      │
      ▼
Monitoring & Visualization

🔧 Hardware Components

Component - Purpose

ESP32 - Main microcontroller and Wi-Fi connectivity
ToF / Distance Sensor - Height measurement
Load Cell - Weight measurement
HX711 Load-cell - signal amplification and conversion
RFID MFRC522 / RC522 - Child identification and attendance
Buzzer - Alert indication
Power Supply - Provides power to the system
Connecting Wires - Hardware interconnection
Measuring Platform / Enclosure - Supports the child during measurement

The exact sensor configuration may vary depending on the prototype implementation and simulation environment.

💻 Software & Technologies
Programming
C/C++
Arduino-compatible ESP32 programming
Embedded & IoT
ESP32
Embedded Systems
Internet of Things (IoT)
Sensor Interfacing
RFID
Load Cell and HX711
IoT Platforms
Blynk IoT
ThingSpeak
Simulation & Development
Wokwi
Arduino IDE
Data Processing
BMI Calculation
Z-score-related processing
Basic risk-analysis logic
Real-time parameter monitoring
Documentation & Version Control
GitHub
Markdown

🧪 Simulation
The system can be simulated using Wokwi to test the ESP32-based implementation and observe the processing flow before or alongside physical hardware development.

The simulation environment helps validate:
ESP32 programming
Sensor interfacing concepts
Data processing
BMI calculation
Attendance logic
IoT communication
Dashboard-related outputs

📡 IoT Monitoring
Blynk
Blynk is used as a real-time monitoring interface.

The dashboard can display:
Height
Weight
BMI
Z-score
Attendance
Health status
Predicted weight
Risk indication

ThingSpeak
ThingSpeak is used for cloud-based storage and visualization.
The system can transmit parameters such as:
Height
Weight
BMI
Z-score
Attendance
Predicted weight
This enables historical data visualization and trend monitoring.

📁 Repository Structure
iot-smart-anganwadi-system/
│
├── README.md
│
├── src/
│   └── smart_anganwadi.ino
│   ├── abstract.pdf
│   ├── project-report.pdf
│   └── project-presentation.pptx
│
├── outputs/
│   ├── blynk-dashboard.png
│   ├── thingspeak-dashboard.png
│   └── system-output.png
|   └── images/
|   ├── prototype.jpg
|   └── circuit.jpg

🧩 Implementation
The ESP32 acts as the central controller of the prototype.

The implementation includes:

Wi-Fi connectivity
Sensor-data processing
BMI calculation
Z-score-related processing
Attendance handling
Basic risk analysis
Blynk communication
ThingSpeak data transmission
Alert generation
Serial monitoring

The source code is available in:
src/smart_anganwadi.ino

📈 Health Data Processing
The prototype calculates BMI using height and weight:
BMI = Weight (kg) / Height² (m²)

The system also performs additional data processing to generate health-status and risk indications.

The implemented calculations are prototype-level logic intended for demonstration and academic purposes. Clinical child-growth assessment should use age- and sex-specific standards and professional medical guidance.

🔔 Alert Mechanism
The prototype includes a notification mechanism for selected risk conditions.
For example, an alert can be generated when the implemented logic identifies a potential underweight or malnutrition-related risk.

This feature is intended to support early attention and monitoring rather than provide a medical diagnosis.

🧪 Testing
The prototype was tested through simulation and system-level observation.

Testing areas include:
ESP32 connectivity
Sensor interfacing
Height measurement logic
Weight measurement logic
RFID attendance handling
BMI calculation
Data processing
Blynk communication
ThingSpeak communication
Dashboard visualization
Alert conditions
Serial monitor output

🚧 Challenges & Learning
During the development of the project, we worked with multiple hardware modules, embedded programming concepts, sensors, and IoT platforms.

Key Learning Areas
ESP32 programming
Embedded C/C++
Sensor interfacing
RFID integration
Load-cell integration
HX711 interfacing
Wi-Fi communication
Blynk configuration
ThingSpeak API integration
Data processing
Hardware/software integration
Debugging and troubleshooting
Technical documentation
Team-based project development
The project provided practical experience in integrating embedded hardware, software logic, wireless communication, cloud platforms, and data visualization into a single engineering solution.

🌟 Advantages
Reduces manual data-entry effort.
Supports digital height and weight monitoring.

Automates BMI calculation.

Enables digital attendance tracking.

Provides real-time IoT monitoring.

Supports historical data visualization.
Provides basic data-based risk indications.

Helps organize child health-related information.

Demonstrates a low-cost approach for smart monitoring.

Provides a foundation for future AI/ML enhancements.

🌍 Potential Applications
Anganwadi Centres
Digital growth and attendance monitoring for children.

Primary Health Centres
Supportive digital monitoring during routine child health assessments.

Schools and Pre-Schools
Basic growth-monitoring applications for young children.

Rural Health Monitoring
IoT-based monitoring in locations where centralized supervision is difficult.

Government and NGO Programs
The concept can be adapted for large-scale child nutrition and welfare monitoring systems.

Research and Education
The prototype can be used as an educational platform for embedded systems, IoT, cloud monitoring, and AI-assisted data analysis.

🔮 Future Scope
The current prototype can be enhanced with the following features:

Advanced machine-learning-based malnutrition prediction.

Training using properly validated child-growth datasets.

Age- and sex-specific growth-standard integration.

Long-term individual growth-trend analysis.

Dedicated web/mobile application.
Structured cloud database.

Multi-child profile management.

QR/RFID-based child records.

Offline data storage and automatic synchronization.

Automated report generation.

Role-based access for workers and administrators.

Improved sensor calibration and measurement accuracy.

Additional health-monitoring sensors.

Voice assistance in Tamil and English.

Solar-powered implementation.

Multi-centre monitoring.

Integration with appropriate government health-monitoring systems, subject to official APIs, standards, authorization, and privacy requirements.

👩‍💻 My Contribution
As a member of the project team, my contributions included:

Embedded system integration
ESP32 programming and implementation support
Sensor interfacing
IoT-based monitoring
Data collection and processing
Blynk and ThingSpeak integration support
Testing and troubleshooting
Project documentation
Technical research
Project presentation
Individual contributions may be updated to accurately reflect the work completed by each team member.

📚 Documentation
Additional project documentation is available in the docs/ directory.

It may include:
Project Abstract
Project Report
Project Presentation

🏆 Project Recognition
The project was developed as an academic and innovation-oriented engineering project in the field of Electronics and Communication Engineering.

It demonstrates the practical integration of:

Embedded Systems + Sensors + IoT + Cloud Monitoring + Data Processing

👥 Team
Developed as a team project by students of:

Department of Electronics and Communication Engineering
PET Engineering College, Vallioor, Tamil Nadu, India.

Team Members
S. Vajitha Bervin
S. Srimathi Mangai
T. Keerthana
S. Vahitha Bervin 

⚠️ Disclaimer
This project is an academic prototype developed for learning, demonstration, and innovation purposes.

The health-related calculations, classifications, and risk indications produced by the prototype must not be considered a medical diagnosis or a substitute for professional healthcare assessment.

Actual deployment for child health monitoring would require validated clinical/growth standards, appropriate calibration, secure handling of personal data, field testing, regulatory considerations, and review by qualified healthcare and government authorities.

📌 Conclusion
The AI-Enabled IoT Smart Anganwadi System demonstrates how embedded systems, sensors, IoT connectivity, cloud platforms, and data-based analysis can be combined to create a smart child-monitoring solution.

The prototype automates important parts of the monitoring workflow, including height and weight data processing, BMI calculation, attendance handling, IoT transmission, dashboard visualization, and basic risk assessment.

The project provided practical experience in ESP32 programming, sensor interfacing, RFID, load-cell integration, IoT communication, cloud platforms, data processing, debugging, and collaborative engineering.

With further development, validation, and integration of advanced machine-learning models and secure data-management systems, the concept can serve as a foundation for scalable digital monitoring solutions for Anganwadi and child-welfare environments.

📄 License
This project is primarily intended for educational and academic purposes.
Please contact the repository owner before reusing substantial portions of the implementation, documentation, or project materials.
