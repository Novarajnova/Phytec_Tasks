OVERVIEW OF WEEK -1
--------------------

Communication Layering and UDP Chat System
1. Summary of OSI Model with Protocol Examples
------------------------------------------------

Layer	Layer Number	Function	Example Protocols

Application	7	User interaction, application services	HTTP, FTP, SMTP, DNS

Presentation	6	Data encoding, encryption, compression	SSL/TLS, JPEG, ASCII

Session	5	Dialog control, session management	NetBIOS, RPC

Transport	4	Reliable delivery, flow control	TCP, UDP

Network	3	Routing and addressing	IP, ICMP, ARP

Data Link	2	Frame-level error detection, MAC	Ethernet, PPP, HDLC

Physical	1	Electrical signals, transmission media	RS-232, Ethernet cables, Wi-Fi, DSL

3. Code Implementations
   ---------------------
a) Basic Data Structures
Queue (FIFO)
------------

Operations: enqueue(), dequeue()

Applications: scheduling, buffering

Linked List
-------------

Singly or doubly linked, dynamic size

Applications: memory management, list traversal

Circular Buffer
---------------

Fixed-size, wrap-around indexing

Applications: UART buffers, audio streaming

b) Event-Driven State Machine
--------------------------------
Enum-based state representation (IDLE, SENDING, WAITING)

Event-driven transitions (e.g., input triggers state change)

Example: traffic light controller, message handler

Benefits:

Structured control logic

Easy to extend and debug

c) UDP Chat App (Client-Server Model)
--------------------------------------
Architecture

Server: receives, broadcasts messages

Clients: send/receive messages using command-line input

Features
----------
Multi-client support (via UDP and server-side threading)

Packet-based message format (JOIN, MSG, LEAVE)

Server can also send messages to clients

Command-line Interface
-----------------------
Server:
./server <port>

Client:
./client <server_ip> <port> <username>


OUTPUT :
----------
[RB-A5D2X SERVER](https://github.com/user-attachments/assets/c741e2c6-bed8-46c8-9a1e-18ac0ee05894) //

[RB-A5D2X CLIENT](https://github.com/user-attachments/assets/9fcc2929-0879-40ac-8c78-7614da327168)


