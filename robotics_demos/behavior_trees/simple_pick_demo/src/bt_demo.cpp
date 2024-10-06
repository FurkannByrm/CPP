#include "bt_demo.hpp"
#include <functional>

ApproachObject::ApproachObject(const std::string &name) : BT::SyncActionNode(name, {}){}

BT::NodeStatus ApproachObject::tick(){
    std::cout<< "Approach Object: "<< this->name()<< std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus ApproachObject::CheckBattery()
{
    std::cout<<"Battery OK"<< std::endl;
    return BT::NodeStatus::SUCCESS;
}
GripperInterface::GripperInterface() : _open(true){}

BT::NodeStatus GripperInterface::open()
{
    _open =true;
    std::cout<<"Gripper open"<<std::endl;
    return BT::NodeStatus::SUCCESS;
}
BT::NodeStatus GripperInterface::close()
{
    _open =false;
    std::cout<<"Gripper close"<<std::endl;
    return BT::NodeStatus::SUCCESS;
}



int main()
{
    BT::BehaviorTreeFactory factory;

    factory.registerNodeType<ApproachObject>("ApproachObject");

    factory.registerSimpleCondition("CheckBattery", std::bind(CheckBattery));

    GripperInterface gripper;

    factory.registerSimpleAction(
        "OpenGripper",
        std::bind(&GripperInterface::open, &gripper));

    factory.registerSimpleAction(
        "CloseGripper",
        std::bind(&GripperInterface::close, &gripper));

    //Create Tree
    auto tree = factory.createTreeFromFile("./../bt_tree.xml");

    //execute the tree
    tree.tickRoot();
    return 0;;
}
