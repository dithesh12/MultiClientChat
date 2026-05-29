# MultiClientChat

A real-time multi-client chat application developed in C++ using TCP socket programming and multithreading. The application enables multiple clients to communicate simultaneously through a centralized server.

## Features

* Real-time client-server communication
* Support for multiple clients concurrently
* Message broadcasting to connected users
* TCP socket-based communication
* Multithreaded client handling
* Connection management and message delivery

## Technologies Used

* C++
* TCP Sockets
* Multithreading
* Linux Networking APIs
* GCC Compiler

## System Architecture

* Server accepts incoming client connections.
* Each client is handled in a separate thread.
* Messages received from a client are broadcast to other connected clients.
* Server manages active client connections and communication.

## Concepts Applied

* Socket Programming
* Client-Server Architecture
* TCP/IP Communication
* Multithreading
* Concurrent Programming
* Network Communication

## Example Workflow

1. Start the server.
2. Connect multiple clients.
3. Send messages from any client.
4. Messages are broadcast to all connected clients in real time.

## Build and Run

### Compile Server

```bash
g++ server.cpp -o server -pthread
```

### Compile Client

```bash
g++ client.cpp -o client -pthread
```

### Start Server

```bash
./server
```

### Start Client

```bash
./client
```

## Learning Outcomes

* Understanding TCP socket communication
* Managing concurrent client connections
* Working with threads in C++
* Implementing client-server applications
* Building real-time communication systems

## Future Enhancements

* Private messaging
* Group chat support
* User authentication
* File sharing
* Message encryption
* Chat history storage

## Author

Dithesh Gowda
