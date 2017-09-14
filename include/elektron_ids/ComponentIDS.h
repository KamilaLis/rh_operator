#ifndef COMPONENTIDS_H
#define COMPONENTIDS_H

#include <iostream>
#include <stdlib.h>

//ROS
#include <ros/ros.h>
//#include <ros/topic_manager.h>
#include "XmlRpc.h"

namespace elektron_ids {

class ComponentIDS
{
public:
    ComponentIDS();

    void detectInterception(const std::string &topic, XmlRpc::XmlRpcValue & publishers);
    void detectFabrication(const std::string &topic, XmlRpc::XmlRpcValue & subscribers);
    void detectInterruption(const std::string& topic);
    void on_working();

    XmlRpc::XmlRpcValue getSystemState();
    XmlRpc::XmlRpcValue getURI(const std::string& node_name);
    XmlRpc::XmlRpcValue getParam(const std::string& param_name);
    XmlRpc::XmlRpcValue getPubsName(const std::string& topic, XmlRpc::XmlRpcValue & publishers);
    XmlRpc::XmlRpcValue getSubsName(const std::string& topic, XmlRpc::XmlRpcValue & subscribers);
    bool isAuthorizated(const std::string& node_name,const std::string& topic_name, bool sub);

private:
    // parameters
    XmlRpc::XmlRpcValue par_IP_;

    bool hasProperIP(const std::string& node_name);
    bool isOnList(const std::string& node_name, const std::string& topic_name, bool sub);
};


}; /* namespace elektron_ids */


#endif //COMPONENTIDS_H
