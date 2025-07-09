Contiki-NG + CoAP on nRF52840-DK
------------------------------------------------------------------------------------------------------------
This repository contains experiments and implementations of the CoAP protocol using the Contiki-NG operating system. It includes setup instructions, example code, and simulation using the Cooja simulator, as well as running on real hardware like the Nordic nRF52840-DK board.
----------------
📌 Project Overview
------------------------------------------------------------------------------------------------------------------
This project explores:
- Contiki-NG installation and setup
- CoAP protocol implementation
- Running CoAP server on nRF52840-DK
- Cooja simulation of CoAP server-client communication
- BLE and Sub-GHz range testing (Silicon Labs platform)
- LED blink demo on Nordic board (extra task)
---------------------------------------------------------------------------------------------------------------------
🔧 Installation and Setup
-----------------------------------------------------------------------------------------------------------------------
Contiki-NG & Dependencies
```bash
git clone https://github.com/contiki-ng/contiki-ng.git
cd contiki-ng
git submodule update --init --recursive

----------------------------------------------------------------------------------------------------------------------
