# UDP Chat System + OSI Model + Data Structures (C Project)

Project Overview

This project includes a **UDP-based chat system** written in C, demonstrating:

- 🧠 OSI Model concepts  
- 📦 Basic data structure usage  
- 🔁 Event-driven state machine  
- 💬 Command-line chat client/server over UDP

---

OSI Model Summary

| Layer | Name           | Description                          | Protocol Examples         |
|-------|----------------|--------------------------------------|---------------------------|
| 7     | Application    | Interface for user apps              | HTTP, FTP, DNS, SMTP      |
| 6     | Presentation   | Encryption, encoding, formatting     | SSL, JPEG, ASCII          |
| 5     | Session        | Manages sessions                     | NetBIOS, SIP              |
| 4     | Transport      | Data delivery and reliability        | TCP, UDP                  |
| 3     | Network        | IP addressing and routing            | IP, ICMP, OSPF            |
| 2     | Data Link      | MAC addressing, framing              | Ethernet, PPP, ARP        |
| 1     | Physical       | Transmission over physical medium    | USB, Wi-Fi, Fiber, DSL    |

---

UDP Chat Application (Client & Server)

- Uses UDP sockets (`recvfrom()` / `sendto()`)
- Server broadcasts messages to all clients
- Client uses threads to receive while typing

How to Compile:
gcc server.c -o server -lpthread
gcc client.c -o client 

./server 9090
./client 127.0.0.1 username
