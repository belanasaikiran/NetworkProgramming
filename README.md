# NetworkProgramming

### ZeroMQ

In arch, install the following packages:
```bash
sudo pacman -S zeromq cppzmq
yay -S zmqpp
```

To Compile the code, use the following command:
```bash
g++ -o server server.cpp -lzmq -lzmqpp
g++ -o client client.cpp -lzmq -lzmqpp
```
