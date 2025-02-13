#include <zmqpp/zmqpp.hpp>
#include <iostream>
#include <string>

using namespace std;

int main(){
    const string endpoint = "tcp://localhost:5555";

    // init 0MQ context
    zmqpp::context context;

    // Generate a push socket
    zmqpp::socket_type  type = zmqpp::socket_type::req;
    zmqpp::socket socket(context, type);

    // open the connection
    cout << "Connecting to hello world server..." << endl;
    socket.connect(endpoint);

    int request_nbr;
    for(request_nbr = 0; request_nbr != 10; request_nbr++){
        // send a message
        cout << "Sending Hello " << request_nbr << "..." << endl;
        zmqpp::message message;

        //compose a message from a string and a number
        message << "Hello";
        socket.send(message);
        string buffer;
        socket.receive(buffer);

        cout << "Received World " << request_nbr << endl;
    }
}
