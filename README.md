# Qt Client-Server Networking Test (UDP JSON, UDP Audio, TCP Binary)

This Qt C++ application demonstrates a versatile client-server architecture utilizing both TCP and UDP protocols. It showcases real-time audio streaming, JSON-based messaging, and binary data transmission, making it a valuable resource for developers interested in network programming with Qt.

## Overview

The project is divided into two main components:

- **Client:** Receives and processes incoming data from the Server.
- **Server:** Sends audio streams, JSON messages, and binary data to the Client.

## Features

### UDP JSON Messaging
- **Lightweight Communication:** Efficient message exchange using JSON format over UDP.
- **Asynchronous Handling:** Non-blocking operations for sending and receiving messages.
- **Custom Protocols:** Easily extendable for various application needs.

### UDP Audio Streaming
- **Real-Time Audio:** Stream audio data with low latency.
- **Buffer Management:** Smooth playback through efficient buffering techniques.
- **Cross-Platform Support:** Compatible with multiple operating systems.

### TCP Binary Transfer
- **Reliable Transmission:** Ensures data integrity over TCP connections.
- **Binary Data Handling:** Suitable for file transfers and other binary data exchanges.
- **Connection Management:** Handles multiple client connections concurrently.

## Getting Started

### Prerequisites
- **Qt Framework:** Qt 5.x or higher.
- **C++ Compiler:** Compatible with your Qt version..
- **Development Environment:** UQt Creator or any IDE supporting Qt projects.

## **Building the Project:**
1.Clone the Repository: 

	git clone https://github.com/avazaghaei/qt-client-server.git.
	
2.Open the Project:

    Launch Qt Creator.
    Open the .pro file located in the project directory.
	
3.Build the Project:

    Configure the project as needed.
	Click the "Build" button to compile.
	
4.Run the Application:
 
    Start the server application.
	Launch the client application to initiate communication.

### **Usage:**
- **Starting the Server:** Run the server application to begin listening for incoming connections.
- **Running the Client:** Launch the client application to connect to the server and start sending data.
- **Monitoring Communication:** Observe the console outputs or UI elements to monitor the data exchange.
  
### **Future Enhancements:**
- **Encryption Support:** Implement SSL/TLS for secure data transmission.
- **GUI Improvements:** Enhance the user interface for better usability.
- **Protocol Extensions:** Add support for additional protocols or data formats.
  
### **Contribution:**
	
Contributions are welcome! If you'd like to contribute:
1. Fork the Repository: Create your own fork of the project.

2. Create a Branch: Develop your feature or fix in a new branch.

3. Submit a Pull Request: Share your changes for review.
	
### **License:**
	
This project is licensed under the MIT License. See the LICENSE file for details.
	
### **Contact:**
	
For questions or suggestions, feel free to open an issue in the repository or contact me via GitHub.
