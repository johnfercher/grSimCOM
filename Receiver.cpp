#include "Receiver.h"

Receiver::Receiver(string ip, int port){
	cout << ip << ":" << port << endl;
	_addr = new QHostAddress(QString::fromStdString(ip));
	_port = port;
}

void Receiver::receiveFromgrSim(){
	//udpsocket.connectToHost(*_addr, _port);

	if(udpsocket.bind(*_addr, _port)){
		cout << "OK" << endl;
	}else{
		cout << "!OK" << endl;
	}

	/*udpsocket.waitForConnected(1000);

	if (udpsocket.state() == QUdpSocket::ConnectedState){
		cout << "ON" << endl;
	}else{
		cout << "!ON" << endl;
	}
	

	while (udpsocket.state() == QUdpSocket::ConnectedState){
		QByteArray datagram;
        datagram.resize(packet.ByteSize());
        QHostAddress sender;
        quint16 senderPort;

        udpsocket.readDatagram(datagram.data(), datagram.size(), _addr, &_port);

        cout << "conectado" << endl;
	}*/
        /*QByteArray datagram;
        datagram.resize(udpsocket.pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        udpsocket.readDatagram(datagram.data(), datagram.size(), _addr, &_port);

        //processTheDatagram(datagram);	
        cout << "recebeu" << endl;
    }

    cout << "saiu" << endl;*/
    /*
    udpsocket.readDatagram(dgram.data(), dgram.size(), *_addr, _port);*/
}

SSL_WrapperPacket Receiver::getFrame(){
	return packet;
}