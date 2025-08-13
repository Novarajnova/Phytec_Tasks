🧠 Topics Covered
------------------------
🔹 STM32 UART Parsing & Serialization

Implemented real-time UART data parsing using HAL with circular buffer.

Printed parsed data to UART terminal (minicom) for verification.

Serialized sensor data (temperature, pressure, humidity) into byte streams for UART transmission.
----------------------------------------------------------------------------------------------------------
🔹 UDP-like Communication over UART

Designed packet-based communication with sequence numbers, ACK, and retransmissions.

Simulated UDP client/server behavior on STM32 boards without Ethernet.

Verified packet loss handling and re-transmission logic.
-------------------------------------------------------------------------------------------------------------
🔹 BLE Advertising (nRF52840 + Contiki-NG)

Modified radio.c to send raw BLE advertisement packets on channels 37, 38, and 39.

Embedded device name "Contiki-BLE" in advertising payload.

Verified advertisement visibility using BLE scanner app.
---------------------------------------------------------------------------------------------------------------
🔹 Advanced C Programming Practice

String manipulation (palindrome check, reversal, pattern printing).

Matrix operations (transpose, multiplication).

Bitwise operations and complex number handling.

File operations (read/write/seek/append).

POSIX message queues (mq_open, mq_send, mq_receive).
-------------------------------------------------------------------------------------------------------------------------
🔹 Yocto BSP & Rootfs Customization

Customized Yocto rootfs with additional packages.

Integrated board support package for target hardware.

Studied OTA update strategy for embedded Linux systems.
-------------------------------------------------------------------------------------------------------------------
✅ Deliverables
 UART parser implementation on STM32 with live testing in minicom.

 Sensor struct serialization to byte stream.

 UDP-over-UART communication with ACK/retry logic.

 BLE advertisement packet with custom device name (Contiki-BLE).

 Solved 20+ advanced C programming problems.

 Custom Yocto image build with BSP integration.
-----------------------------------------------------------------------------------------------------------------
🛠️ Tools Used
STM32CubeIDE (STM32 firmware development)

Minicom (UART testing)

Contiki-NG (BLE implementation)

nRF Command Line Tools + J-Link (flashing nRF52840)

Yocto Project (BSP & rootfs customization)

Ubuntu 22.04 (development environment)

Git & GitHub (version control)
