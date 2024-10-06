#ifndef _BT_DEMO_HPP_
#define _BT_DEMO_HPP_
#include <behaviortree_cpp/basic_types.h>
#include <iostream>
#include <chrono>

#include "behaviortree_cpp/action_node.h"
#include "behaviortree_cpp/bt_factory.h"

class ApproachObject : public BT::SyncActionNode
{
  public:
  explicit ApproachObject(const std::string &name);
  BT::NodeStatus tick() override;
  BT::NodeStatus CheckBattery();

};

class GripperInterface{
    public:
    GripperInterface();
    BT::NodeStatus open();
    BT::NodeStatus close();
    private:
    bool _open;
};




#endif //_BT_DEMO_HPP_
