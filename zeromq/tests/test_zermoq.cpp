#include <cest/cest.h>

#include <zeromq/zmq.h>

describe("zeromq", []() {
    it("creates zmq connection", []() {
        char buffer[10];
        
        void *responder_context = zmq_ctx_new();
        void *responder = zmq_socket(responder_context, ZMQ_REP);
        int rc = zmq_bind (responder, "tcp://*:5555");

        void *requester_context = zmq_ctx_new();
        void *requester = zmq_socket(requester_context, ZMQ_REQ);
        zmq_connect (requester, "tcp://localhost:5555");

        zmq_send (requester, "Hello", 5, 0);
        zmq_recv (responder, buffer, 10, 0);

        expect(rc).toBe(0);
        expect(std::string(buffer)).toBe("Hello");
    });
});
