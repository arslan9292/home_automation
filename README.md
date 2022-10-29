# home_automation
## DTMF &amp; GSM based Home Automation

### Introduction

The concept of smart home is not a new one; it however has been an influencing technological fantasy over the entire twenty first century. The entire sight of home automation or smart home pans the ability of the user to exhibit c1ontrol over the home from any remote distance and to be able to monitor a breach in security or even the change in behavior of an element of the home.

Home automation is the residential extension of building automation. It is automation of the home, housework or household activity. Home automation may include centralized control of lighting, HVAC (heating, ventilation and air conditioning), appliances, security locks of gates and doors and other systems, to provide improved convenience, comfort, energy efficiency and security. Home automation for the elderly and disabled can provide increased quality of life for persons who might otherwise require caregivers or institutional care.

The popularity of home automation has been increasing greatly in recent years due to much higher affordability and simplicity through Smartphone and tablet connectivity. The concept of the "Internet of Things" has tied in closely with the popularization of home automation.

### Overview of Project

The project aims to develop an archetype of a smart home, which uses the available GSM techniques utilized by a conventional mobile phone to manifest a contiguous user to home communication, and hence obtain an emulated model of an automated home with a two way communication existing between the user and the home to insure remote home control and surveillance as well as judicious smart home. The concept of remote home controlling is a fairly developing issue, with previous models using a dedicated remote control, manifested upon RF communication to establish home automation. The current mode uses the DTMF enabled mobile device, which is a conspicuous necessity in the age to enable a communication link between the user and the home station. However besides home remote controlling, the project undermines several ostensible features. The aspects and objectives of the projects are as follows:

 - To develop a DTMF link between the user and the home.
 - To use this DTMF link to enable the user to operate desired operation from any remote distance.
 - To develop a feedback link from the fixed home station to the user.
 - To utilize the feedback link to intimate the user for any breach in home security.
 - To manifest the judicious use of power in the home, and hence develop a prototype of a smart home. 

As mentioned above, the project envisions to develop the model of a “Intelligent home” which not only is remote operable, but also is robust, i.e. generates a feedback in case of security breach and also is “smart” in energy consumption. The project completed and executed in collaboration with Akshat Lakhiwal, Gaurav Binjola and Anu Sinha.

### Modes in the Project

1. MODE A - “SECURE MODE” :

In this mode, the house shall be Secured and guarded by the internal security network, which includes doors and windows monitoring, and sound level monitoring. This mode is best prescribed for the absence of user/family from the house for a short span of time. In this mode the smart house is inactive and any appliance switched on or off remains in that state until manually over ridden. Key features of the Secure mode are as following:

 - 1.1. All the sensors, viz. door, window contact sensors and decibel sensors will be activated.
 - 1.2. In case of security breach, i.e. breach detection by the sensors, the microcontroller will be intimidated which will trigger the GSM-module to generate a short text message, which is forwarded to the user/local security services.
 - 1.3. In this mode, the smart features of the home are disabled and the home merely serves to be in secure mode.

2. MODE B - “LONG SECURE MODE”:

This mode is an extended version of the secure mode, where the house shall be Secured and guarded by the internal security network, which includes doors and windows monitoring, and sound level monitoring. Besides these the smart home feature will now be active which will insure any unnecessary power wastage, including appliance running in user absence. However the house will take care of its lighting based on ambience darkness. Owing to these features, this mode makes the house self sustaining in the absence of user on a short or long term basis. All the user intimation will be done by a GSM based feedback
network. Key features of the Long Secure mode are as following:

 - 2.1. All the sensors will get activated.
 - 2.2. In case of security breach, i.e. breach detection by the sensors, the microcontroller will be intimidated which will trigger the GSM-module to generate a short text message, which is forwarded to the user/local security services This interrupt will tell the GSM module to send a message to the predefined number(s).
 - 2.3. Meanwhile, smart feature of the home are active during this period, viz. Smart presence detection, ambience light and temperature monitoring, overhead water level detection, street light and door lighting operations.
 - 2.4. To ensure judicious energy usage, the shall ensure no unnecessary energy consumption during the absence of the user
 - 2.5. Since this mode is best suited for the absence of user for a long period, the smart home shall manage house vicinity lighting during nights.

3. MODE C - “SMART MODE”:

This mode ensures efficient power consumption in the house when the user is in situ. In this mode all the smart features of the home viz. ambience controlled lighting, temperature controlled air conditioning/fan speed regulation, automatic lights shut in absence of user and automatic water pumping will be enabled. It must be mentioned that all these features will be calibrated as per the user’s preference. In the smart mode all the user intimation will be done by a GSM based feedback network. Key features of the Smart mode are as following:

 - 3.1. This mode is suited for a user inhabitited house.
 - 3.2. The smart house features will be at their peak during this period, with all the sensors enabled and monitoring vital parameters such as temperature, ambience light, overhead water level, no. of users in the house and their locations.
 - 3.3. This parameter are delivered to the microcontroller, which then controls the appliances such as lights, fans/air conditioner regulators/speeds, electric pumps, and also switches them off as the user transits from one room to the other.
 - 3.4. Thus, this mode is aimed at judicious energy usage and minimizing user interference with electric gadgets.
 - 3.5. The efficiency of the smart house may further be increased by using graded sensors.
 - 3.6. Despite the smart operation, at any point the user may interfere with the working of the devices.

4. MODE D - “MANUAL MODE”:

The user besides having the advantage of remote home automation using mobile phone, also will have the added benefit of a manual console based in the home station itself, which can be used to manually command in case of mobile failure. In the manual mode the smart home as well as the automated features will be disabled and the home will be open for manual controlling. In this mode at any point of time, user will be able to control the appliances manually.
