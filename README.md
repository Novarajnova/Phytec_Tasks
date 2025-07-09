Week 2 – Embedded Networking and CoAP Tasks
-----------------------------------------------
This week's focus was on understanding and implementing embedded communication protocols using **Contiki-NG**, **Cooja simulator**, and **Nordic nRF52840-DK** board. We also explored Sub-GHz and BLE range testing using the **Silicon Labs** platform.

-------------------------------------------------------------------------------------------------------------------------------------------------------------

🧠 Topics Covered
-----------------------
🔹 Contiki-NG & CoAP
- Installed Contiki-NG OS on Ubuntu
- Understood the architecture and build system of Contiki
- Worked with `coap-example-server` and added custom resources
- Compiled CoAP server code for both:
  - Nordic nRF52840-DK (`.hex`)
  - Cooja simulator (`.cooja`)
--------------------------------------------
Nordic nRF52840-DK
- Installed Segger Embedded Studio
- Setup J-Link & nRF Command Line Tools
- Flashed Contiki-generated `.hex` file onto the board
- Verified LED blink & UART debug messages
--------------------------------------------------------
  🔹 Cooja Simulator
- Installed & ran Cooja using Gradle
- Built and tested CoAP server in simulated environment
- Analyzed packet flow between client/server
----------------------------------------------------------------
🔹 BLE & Sub-GHz Testing
- BLE Range Test using Silicon Labs BLE stack (EFR32 board)
- RAIL-based Sub-GHz test with S2LP module
- Compared BLE and Sub-GHz performance over distance

----------------------------------------------------------------------

✅ Deliverables

- [x] CoAP Server build on Contiki-NG (nRF52840 and Cooja)
- [x] Working resource `/test/hello` via CoAP
- [x] Nordic LED Blink program flashed and tested
- [x] BLE Range Test App using Simplicity Studio
- [x] Sub-GHz test using RAIL stack (Silicon Labs)
- [x] Screenshots and test results (attached in repo/docs)

-----------------------------------------------------------------

🛠️ Tools Used

- **Contiki-NG OS**
- **Cooja Simulator**
- **Segger Embedded Studio**
- **nRF Command Line Tools**
- **Simplicity Studio** (for Silicon Labs BLE/RAIL)
- **Linux (Ubuntu 22.04)**

-----------------------------------------------------------------------

