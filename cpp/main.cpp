#include "iostream"
#include "net.h"

using namespace std;

int main(int argc, char** argv){
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    Net net;
    grSim_Packet packet_grSim;

    
    net.setIpPortSend();        // with default values
    net.setIpPortReceive();     // with default values

	
    bool yellow = false;

    packet_grSim.mutable_commands()->set_isteamyellow(yellow);
    packet_grSim.mutable_commands()->set_timestamp(0.0);

    grSim_Robot_Command* command = packet_grSim.mutable_commands()->add_robot_commands();
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

    net.sendPacket(packet_grSim);
    
    while(1){
        if(net.hasNewPacket()){
            net.receivePacket();
        }
    }
	
	return 0;
}
