# Computer Networks Lab Practicals

This repository contains practical implementations covering fundamental concepts in computer networking, including networking devices, topologies, troubleshooting commands, socket programming, protocol analysis, flow control, and routing algorithms.

## Table of Contents

1. [Practical 1: Networking Devices, Topologies & Troubleshooting](#practical-1-networking-devices-topologies--troubleshooting)
2. [Practical 2: TCP Client](#practical-2-tcp-client)
2. [Practical 3: TCP Server](#practical-3-tcp-server)
3. [Practical 4: UDP Client](#practical-4-udp-client)
4. [Practical 5: UDP Server](#practical-5-udp-server)
5. [Practical 6: DNS Packet Analysis](#practical-6-dns-packet-analysis)
6. [Practical 7: DNS and HTTP Analysis](#practical-7-dns-and-http-analysis)
7. [Practical 8.1: Go-Back-N ARQ](#practical-81-go-back-n-arq)
8. [Practical 8.2: Selective Repeat ARQ](#practical-82-selective-repeat-arq)
9. [Practical 9.1: Leaky Bucket Algorithm](#practical-91-leaky-bucket-algorithm)
10. [Practical 9.2: Token Bucket Algorithm](#practical-92-token-bucket-algorithm)
11. [Practical 10: Distance Vector Routing](#practical-10-distance-vector-routing)

---

## Practical 1: Networking Devices, Topologies & Troubleshooting

**Objective:** Understand fundamental networking devices, network topologies, and basic troubleshooting commands.

### Part A: Networking Devices

**1. Router**
- Function: Connects different networks together and routes data between them
- Key Use: Connects home/office networks to the internet
- Smart Features: Assigns IP addresses, provides firewall and security

**2. Switch**
- Function: Connects multiple devices within a LAN
- Key Use: Forwards data to specific devices using MAC addresses
- Advantage: More intelligent than hubs, sends data only to intended device

**3. Hub (Legacy Device)**
- Function: Connects multiple Ethernet devices
- Key Use: Broadcasts incoming data to all ports
- Limitation: Not efficient, doesn't filter data or know destination devices

**4. Modem (Modulator-Demodulator)**
- Function: Converts digital data to analog for transmission and vice versa
- Key Use: Connects home network to ISP
- Types: DSL, Cable, Fiber modems

**5. Access Point (AP)**
- Function: Extends wired network by adding Wi-Fi capability
- Key Use: Used in wireless LANs (WLANs)
- Note: Many routers include built-in access points

**6. Network Interface Card (NIC)**
- Function: Allows a computer to connect to a network
- Key Use: Every network device needs one
- Types: Wired (Ethernet NIC), Wireless (Wi-Fi NIC)

**7. Bridge**
- Function: Connects two LANs using the same protocol
- Key Use: Divides network into segments to reduce traffic
- Advantage: Filters traffic based on MAC addresses

**8. Gateway**
- Function: Translates between different network protocols
- Key Use: Connects different systems (e.g., enterprise network to internet)

**9. Repeater**
- Function: Boosts or regenerates signals in a network
- Key Use: Extends network range by amplifying signals
- Common in: Large buildings or areas with weak signals

**10. Firewall**
- Function: Controls incoming and outgoing network traffic based on security rules
- Key Use: Protects against unauthorized access
- Types: Hardware or Software

**11. Brouter (Bridge + Router)**
- Function: Hybrid device combining bridge and router functions
- Key Use: Can route protocols and bridge non-routable protocols

### Part B: Network Topologies

**1. Bus Topology**
- Structure: All devices connected to a single central cable
- Data Flow: Travels in both directions along the cable
- Advantages:
  - Easy and inexpensive to implement
  - Requires less cable than star topology
- Disadvantages:
  - Main cable failure brings down entire network
  - Difficult to troubleshoot
  - Limited cable length and number of nodes

**2. Star Topology**
- Structure: All devices connected to a central device (hub/switch)
- Data Flow: Devices communicate through central device
- Advantages:
  - Easy to install and manage
  - Single node failure doesn't affect rest of network
- Disadvantages:
  - Central device is single point of failure
  - Uses more cable than bus topology

**3. Ring Topology**
- Structure: Each device connected to two others, forming circular path
- Data Flow: Travels in one direction (or both in dual ring)
- Advantages:
  - Orderly data flow
  - Equal access for all devices
- Disadvantages:
  - Any cable/device failure breaks the loop
  - Difficult troubleshooting
  - Adding/removing devices disrupts network

**4. Mesh Topology**
- Structure: Every device connected to every other device
- Types:
  - Full Mesh: All nodes interconnected
  - Partial Mesh: Some nodes interconnected
- Advantages:
  - Very reliable and redundant
  - Single link failure doesn't affect communication
- Disadvantages:
  - Expensive and complex
  - Requires lots of cabling and ports

**5. Tree Topology (Hierarchical)**
- Structure: Combination of star topologies connected to central bus
- Advantages:
  - Scalable and structured
  - Easy to expand
- Disadvantages:
  - Backbone failure affects entire network
  - Requires more cabling

**6. Hybrid Topology**
- Structure: Combination of two or more different topologies
- Examples: Star-Bus, Star-Ring
- Advantages:
  - Flexible and scalable
  - Combines benefits of multiple topologies
- Disadvantages:
  - Complex design and maintenance
  - Costly implementation

### Part C: Basic Network Troubleshooting Commands

**1. ping**
- Purpose: Tests connectivity to another device or website
- Usage:
  ```bash
  ping google.com
  ping 192.168.1.1
  ```
- Shows: Reachability, response time, packet loss

**2. ipconfig (Windows)**
- Purpose: Displays IP address, subnet mask, default gateway
- Usage:
  ```bash
  ipconfig
  ipconfig /all
  ipconfig /release
  ipconfig /renew
  ipconfig /flushdns
  ```
- Key Uses:
  - /release and /renew: Refresh IP address
  - /flushdns: Clears DNS cache

**3. ifconfig (Linux/macOS)**
- Purpose: Shows and configures network interfaces
- Usage:
  ```bash
  ifconfig
  ```
- Note: Use `ip a` on modern Linux systems

**4. tracert (Windows) / traceroute (Linux/macOS)**
- Purpose: Shows the path (hops) data takes to reach destination
- Usage:
  ```bash
  tracert google.com      # Windows
  traceroute google.com   # Linux/macOS
  ```

**5. nslookup**
- Purpose: Queries DNS to find IP address of domain name
- Usage:
  ```bash
  nslookup google.com
  ```

**6. route**
- Purpose: Displays and manipulates routing table
- Usage:
  ```bash
  route print       # Windows
  route -n          # Linux
  ```

### Practical Exercises

**Exercise 1: Device Identification**
- Identify networking devices in your lab/home network
- Document their functions and connections

**Exercise 2: Topology Analysis**
- Draw the network topology of your lab
- Identify advantages and disadvantages of the current setup

**Exercise 3: Troubleshooting Practice**
1. Use `ping` to test connectivity to various websites
2. Use `ipconfig` or `ifconfig` to find your IP address
3. Use `tracert` to trace the path to a remote server
4. Use `nslookup` to resolve domain names
5. View your routing table using `route` command

**Exercise 4: Network Documentation**
- Create a network diagram showing all devices
- Label each device with its IP address and function
- Identify the topology type used

### Learning Outcomes

After completing this practical, you will understand:
- Different types of networking devices and their functions
- Various network topologies and their characteristics
- Basic network troubleshooting commands
- How to diagnose common network connectivity issues
- Network design considerations

---

## Practical 2: TCP Client

**Objective:** Implement a TCP client for file transfer using socket programming.

**Description:** This program creates a TCP client that connects to a server and transfers a file over a reliable TCP connection.

**Key Features:**
- Socket creation and connection establishment
- File reading and transmission
- Error handling for network operations

**Usage:**
```bash
gcc "PRACTICAL 2 TCP CLIENT" -o tcp_client
./tcp_client <filename>
```

**Port:** 10146

---

## Practical 3: TCP Server

**Objective:** Implement a TCP server to receive files from clients.

**Description:** This program creates a TCP server that listens for incoming connections and receives files from clients.

**Key Features:**
- Socket binding and listening
- Client connection acceptance
- File reception and storage
- Concurrent client handling capability

**Usage:**
```bash
gcc "PRACTICAL 3 TCP SERVER" -o tcp_server
./tcp_server
```

**Port:** 10035

---

## Practical 4: UDP Client

**Objective:** Implement a UDP client for connectionless file transfer.

**Description:** This program sends files using UDP protocol, demonstrating connectionless communication.

**Key Features:**
- UDP socket creation
- File size calculation and transmission
- Datagram-based file transfer

**Usage:**
```bash
gcc "PRACTICAL 4 UDP CLIENT" -o udp_client
./udp_client
```

**Port:** 9146

---

## Practical 5: UDP Server

**Objective:** Implement a UDP server to receive files via connectionless protocol.

**Description:** This program receives files sent over UDP, handling datagram-based communication.

**Key Features:**
- UDP socket binding
- Datagram reception
- File reconstruction from packets

**Usage:**
```bash
gcc "PRACTICAL 5 UDP SEREVR" -o udp_server
./udp_server
```

**Port:** 9146

---

## Practical 6: DNS Packet Analysis

**Objective:** Analyze DNS packets using command-line tools and Wireshark.

**Description:** This practical demonstrates DNS query-response mechanism and packet structure analysis.

**Tools Required:**
- Windows PC with Internet access
- Command Prompt
- Wireshark

**Key Concepts:**
- DNS query types (A, MX records)
- nslookup command usage
- DNS packet structure (Transaction ID, Flags, Questions, Answers)
- UDP port 53 communication

**Commands:**
```bash
nslookup www.example.com
nslookup -query=MX example.com
```

---

## Practical 7: DNS and HTTP Analysis

**Objective:** Analyze Application Layer protocols (DNS and HTTP) using Wireshark.

**Description:** Comprehensive packet analysis of DNS and HTTP protocols to understand their structure and operation.

**Tools Required:**
- Wireshark
- Web Browser
- Command-line tools

**Key Observations:**
- DNS: UDP-based, port 53, A records, TTL values
- HTTP: TCP-based, port 80, GET requests, status codes, content types

**Analysis Points:**
- Transaction IDs and flags
- Query/Response structure
- HTTP methods and headers
- Status codes and content delivery

---

## Practical 8.1: Go-Back-N ARQ

**Objective:** Simulate the Go-Back-N sliding window protocol for error control.

**Description:** Implementation of Go-Back-N ARQ where the sender retransmits all frames starting from the lost frame.

**Key Features:**
- Sliding window mechanism
- Cumulative acknowledgment
- Retransmission of entire window on error
- Sequence number management

**Usage:**
```bash
gcc "PRACTICAL8.1( Go-Back-N ARQ" -o gobackn
./gobackn
```

**Concepts:**
- Window size configuration
- Frame transmission and acknowledgment
- Error simulation and recovery

---

## Practical 8.2: Selective Repeat ARQ

**Objective:** Simulate the Selective Repeat sliding window protocol.

**Description:** Implementation of Selective Repeat ARQ where only lost or corrupted frames are retransmitted.

**Key Features:**
- Individual frame acknowledgment
- Selective retransmission
- More efficient than Go-Back-N
- Independent frame tracking

**Usage:**
```bash
gcc "PRACTICAL 8.2 (Selective Repeat ARQ)" -o selective_repeat
./selective_repeat
```

**Advantages:**
- Reduced retransmissions
- Better bandwidth utilization
- Individual frame error handling

---

## Practical 9.1: Leaky Bucket Algorithm

**Objective:** Implement the Leaky Bucket algorithm for traffic shaping and congestion control.

**Description:** Simulation of the leaky bucket algorithm that smooths bursty traffic by outputting packets at a constant rate.

**Key Features:**
- Bucket capacity management
- Constant outgoing rate
- Overflow handling and packet loss calculation
- Traffic smoothing

**Usage:**
```bash
gcc "PRACTICAL 9_1(Leaky Bucket)" -o leaky_bucket
./leaky_bucket
```

**Parameters:**
- Bucket size (capacity)
- Outgoing rate
- Incoming packet rate

---

## Practical 9.2: Token Bucket Algorithm

**Objective:** Implement the Token Bucket algorithm for traffic shaping.

**Description:** Simulation of the token bucket algorithm that allows bursty traffic while maintaining average rate control.

**Key Features:**
- Token generation at fixed rate
- Bucket capacity limits
- Burst handling capability
- Packet dropping when tokens unavailable

**Usage:**
```bash
gcc "PRACTICAL 9_2(Token Bucket)" -o token_bucket
./token_bucket
```

**Parameters:**
- Bucket size
- Token generation rate
- Packet arrival pattern

**Difference from Leaky Bucket:**
- Allows traffic bursts
- More flexible rate control
- Token-based transmission permission

---

## Practical 10: Distance Vector Routing

**Objective:** Implement the Distance Vector Routing algorithm (Bellman-Ford).

**Description:** Simulation of distance vector routing protocol where routers exchange routing information with neighbors to build routing tables.

**Key Features:**
- Cost matrix input
- Iterative distance calculation
- Routing table generation for each node
- Next hop determination

**Usage:**
```bash
gcc "PRCATICAL 10 Distance Vector Algorithm" -o distance_vector
./distance_vector
```

**Algorithm:**
- Bellman-Ford equation: D(x,y) = min{c(x,v) + D(v,y)}
- Distributed computation
- Convergence through information exchange

**Input:**
- Number of nodes
- Cost matrix (use 999 for infinity/no connection)

**Output:**
- Routing table for each node showing destination, next hop, and distance

---

## Prerequisites

### For C Programs (Practicals 2-5, 8-10):
- GCC compiler
- Linux/Unix environment (or MinGW for Windows)
- Basic understanding of C programming

### For Packet Analysis (Practicals 6-7):
- Wireshark installed
- Windows OS (for Practical 6)
- Internet connection
- Administrator privileges

## Compilation Instructions

For Linux/Unix systems:
```bash
gcc <source_file> -o <output_name>
./<output_name>
```

For Windows with MinGW:
```bash
gcc <source_file> -o <output_name>.exe -lws2_32
<output_name>.exe
```

## Important Notes

1. TCP vs UDP: TCP provides reliable, connection-oriented communication while UDP is connectionless and faster but unreliable.

2. Port Numbers: Ensure the client and server use matching port numbers. You may need to modify ports based on your system configuration.

3. Firewall: Some programs may require firewall exceptions to allow network communication.

4. Root Privileges: Server programs may require elevated privileges to bind to certain ports.

5. Wireshark: Run Wireshark with administrator privileges for proper packet capture.

6. ARQ Protocols: Go-Back-N is simpler but less efficient than Selective Repeat for high error rates.

7. Traffic Shaping: Leaky bucket provides constant output rate while token bucket allows bursts.

8. Routing: Distance vector routing may suffer from count-to-infinity problem in certain network topologies.

## Learning Outcomes

After completing these practicals, you will understand:
- Socket programming in C (TCP and UDP)
- Client-server architecture
- Application layer protocols (DNS, HTTP)
- Packet analysis using Wireshark
- Error control mechanisms (ARQ protocols)
- Flow control and congestion control algorithms
- Routing algorithms and table construction

## Troubleshooting

**Connection Refused:**
- Ensure server is running before starting client
- Check if ports are not already in use
- Verify firewall settings

**Compilation Errors:**
- Include necessary header files
- Link socket libraries (use -lws2_32 on Windows)
- Check for platform-specific code

**Wireshark Issues:**
- Run as administrator
- Select correct network interface
- Apply appropriate filters (dns, http)

## References

- Computer Networks by Andrew S. Tanenbaum
- TCP/IP Protocol Suite by Behrouz A. Forouzan
- Unix Network Programming by W. Richard Stevens
- Wireshark User Guide

## License

These practicals are for educational purposes only.
