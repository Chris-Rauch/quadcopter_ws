#define CE_PIN 22
#define CSN_PIN 0
#define IRQ_PIN 8

#ifndef RF24_TRANSCEIVER_HPP
#define RF24_TRANSCEIVER_HPP

#include <wiringPi.h>
#include "rclcpp/rclcpp.hpp"
#include "interfaces/msg/telemetry_msg.hpp"
#include "interfaces/srv/send_command.hpp"
#include "RF24/RF24.h"

const int SPI_SPEED = 2000000;
const uint8_t PIPE[2][6] = {"1Node", "2Node"};
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

    /**
     * @brief 
     * 
     * @param request 
     * @param response 
     */
    void transmit_command(const std::shared_ptr<interfaces::srv::SendCommand::Request> request,
        std::shared_ptr<interfaces::srv::SendCommand::Response> response);

  private:
    rclcpp::Publisher<interfaces::msg::RawDataMsg>::SharedPtr raw_data_publisher_;
    RF24 radio_;
  };

} // namespace command_and_control

#endif // RF24_TRANSCEIVER_HPP
