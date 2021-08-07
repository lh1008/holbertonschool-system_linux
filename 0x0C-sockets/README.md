# 0x0C. Sockets

### `man or help`

- `socket (2)`
- `bind (2)`
- `listen (2)`
- `accept (2)`
- `connect (2)`
- `send (2)`
- `recv (2)`

### Learning Objectives

- What is a socket and how it is represented on a Linux/UNIX system
- What are the different types of sockets
- What are the different socket domains
- How to create a socket
- How to bind a socket to an address/port
- How to listen and accept incoming traffic
- How to connect to a remote application
- What is the the HTTP protocol
- How to create a simple HTTP server

### Tasks

_**0. Listen**_
Write a program that opens an `IPv4/TCP` socket, and listens to traffic on port `12345` (Any address).

_**1. Accept**_
Write a program that opens an `IPv4/TCP` socket, and listens to traffic on port `12345` (Any address).

_**2. Client**_
Write a program that connects to a listening server.

_**3. Roger**_
Write a program that opens an `IPv4/TCP` socket, and listens to traffic on port `12345` (Any address).

_**4. REST API - The Request**_
Write a program that opens an `IPv4/TCP` socket, and listens to traffic on port `8080` (Any address).

_**5. REST API - Queries**_
Write a program that opens an `IPv4/TCP` socket, and listens to traffic on port `8080` (Any address).

_**6. REST API - Headers**_
Write a program that opens an `IPv4/TCP` socket, and listens to traffic on port `8080` (Any address).

_**7. REST API - Body parameters**_
Write a program that opens an `IPv4/TCP` socket, and listens to traffic on port `8080` (Any address).

_**8. REST API - Create TODO**_
Now that you can parse an HTTP request, it’s time to implement our REST API. Start by handling the `POST` method for the path `/todos`

_**9. REST API - Retrieve all TODOs**_
Handle the `GET` method for the path `/todos`
