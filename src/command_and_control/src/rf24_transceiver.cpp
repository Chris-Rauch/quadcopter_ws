#include "command_and_control/rf24_transceiver.cpp"

namespace command_and_control {
  RF24Transceiver::RF24Transceiver()
  {
    // I NEED THE CODE ON MY WINDOWS MACHINE HERE

    // init telem publisher
    telem_publisher_ = this->create_publisher<interfaces::msg::TelemetryMsg>("telemetry", 10);
  }

} // namespace command_and_control