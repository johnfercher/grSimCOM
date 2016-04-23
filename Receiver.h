#ifndef _RECEIVER_H_
#define _RECEIVER_H_

#include "messages_robocup_ssl_detection.pb.h"
#include "messages_robocup_ssl_geometry.pb.h"
#include "messages_robocup_ssl_refbox_log.pb.h"
#include "messages_robocup_ssl_wrapper.pb.h"
#include "referee.pb.h"

#include "iostream"
#include "Qts/Qts.h"

using namespace std;
 
class Receiver{
private:
	// Socket info
	QUdpSocket udpsocket;
    quint16 _port;
    QHostAddress *_addr;
    QByteArray dgram;
    
    // grSim info
public:
	Receiver(string ip = "224.5.23..2", int port = 10020);

	void receiveFromgrSim();
	void getState();
};

#endif