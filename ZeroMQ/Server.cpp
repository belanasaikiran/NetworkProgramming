#include <zmqpp/compatibility.hpp>
#include <zmqpp/context.hpp>
#include <zmqpp/socket_types.hpp>
#include<zmqpp/zmqpp.hpp>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;


int main(int argc, char *argv[]){
    const string endpoint = "tcp://*:5555";

    //initialize the 0mQ context
    zmqpp::context context;

    // generate a pull socket
    zmqpp::socket_type type = zmqpp::socket_type::reply;
    zmqpp::socket socket (context, type);

    //bind to socket
    socket.bind(endpoint);
    while(1){
        // receive the message
        zmqpp::message message;

        // decompose the message
        socket.receive(message);
        string text;
        message >> text;

        // Do Some `Work`
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Received Hello"<< endl;
        socket.send("World");
    }
}
