#define CE_PIN 22
#define CSN_PIN 0
#define IRQ_PIN 8

#ifndef RF24_TRANSCEIVER_HPP
#define RF24_TRANSCEIVER_HPP

#include <cstdlib>
#include "rclcpp/rclcpp.h"
#include "std_msgs/msg/String"
#include "/home/chris/rf24libs/RF24/RF24.h"

const int SPI_SPEED = 2000000;
const char* PIPE[2] = {"1Node", "2Node"};
const int PAYLOAD_SIZE = 32;

namespace command_and_control {
  /**
   * @brief The transceiver is configured to always be listening, except when
   * transmitting.
   * 
   */
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

  private:
    void _receiverCallback(); 
    void _configureListenMode();
    void _configureWriteMode();
  private:
    rclcpp::Publisher<interfaces::msg::TelemetryMsg>::SharedPtr telem_publisher_;
    RF24 radio_;
  };

} // namespace command_and_control

#endif // RF24_TRANSCEIVER_HPP
