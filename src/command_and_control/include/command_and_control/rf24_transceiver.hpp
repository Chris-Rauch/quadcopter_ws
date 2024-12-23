#ifndef RF24_TRANSCEIVER_HPP
#define RF24_TRANSCEIVER_HPP

#include "rclcpp/rclcpp.h"
#include "std_msgs/msg/String"

namespace command_and_control {

  class RF24Transceiver : public rclcpp::Node
  {
  public:
    /**
     * @brief Initialize the RF24 transceiver.
     *   Init the telemetry publisher
     */
    RF24Transceiver();

    // set up the command service server
    void transmit_command(const std::shared_ptr<interfaces::srv::MotorCommand::Request> request,
        std::shared_ptr<interfaces::srv::MotorCommand::Response> response);

    // set up telemetry publisher 
    //telem_publisher_ = this->create_publisher<interfaces::msg::TelemetryMsg>("telemetry", 10);
    
  private:
    rclcpp::Publisher<interfaces::msg::TelemetryMsg>::SharedPtr telem_publisher_;
  }

} // namespace command_and_control

#endif // RF24_TRANSCEIVER_HPP
