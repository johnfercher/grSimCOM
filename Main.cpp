#include "iostream"
#include <google/protobuf/text_format.h>

#include "Sender.h"
#include "Receiver.h"

using namespace std;

int main(int argc, char** argv){
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    /*Sender sender;

	grSim_Packet packet;
    bool yellow = false;

    packet.mutable_commands()->set_isteamyellow(yellow);
    packet.mutable_commands()->set_timestamp(0.0);

    grSim_Robot_Command* command = packet.mutable_commands()->add_robot_commands();
    command->set_id(0);

    command->set_wheelsspeed(0);
    command->set_wheel1(0);
    command->set_wheel2(0);
    command->set_wheel3(0);
    command->set_wheel4(0);
    command->set_veltangent(0);
    command->set_velnormal(0);
    command->set_velangular(1);

    command->set_kickspeedx(0);
    command->set_kickspeedz(0);
    command->set_spinner(false);

    sender.setPacket(packet);
    sender.send2grSim();*/
    Receiver receiver("224.5.23.2", 10020);
    receiver.receiveFromgrSim();
	
	return 0;
}
