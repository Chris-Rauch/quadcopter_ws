#include "command_and_control/rf24_transceiver.cpp"

namespace command_and_control {
  
  RF24Transceiver::RF24Transceiver()
  {
    radio_ = RF24(CE_PIN, CSN_PIN, SPI_SPEED); // Initialize RF24
    while (!radio_.begin()) {}                // Wait until RF24 is ready
    radio_.setPALevel(RF24_PA_MIN);           // Set power level
    radio_.setDataRate(RF24_250KBPS);         // Set data rate
    radio_.setPayloadSize(PAYLOAD_SIZE);      // Set payload size
    radio_.openReadingPipe(0, PIPE[0]);       // Open pipe 0 for reading
    radio_.openWritingPipe(PIPE[1]);          // Open pipe 1 for writing
    radio_.startListening();                  // Start listening mode
    radio_.setChannel(69);                    // Set RF24 channel
    
    attachInterrupt(digitalPinToInterrupt(IRQ_PIN), _receiverCallback, FALLING); // Attach IRQ callback

    telem_publisher_ = this->create_publisher<interfaces::msg::TelemetryMsg>("telemetry", 10); // Init ROS2 publisher
  }


  void RF24Transceiver::transmit_command(const std::shared_ptr<interfaces::srv::MotorCommand::Request> request,
    std::shared_ptr<interfaces::srv::MotorCommand::Response> response)
  {
    uint8_t payload = request->payload;

    radio_.stopListening(); // Switch to transmit mode
    response->ack = radio.write(payload, PAYLOAD_SIZE); // Send data and store acknowledgment
    radio_.startListening(); // Switch back to listening mode
  }

  

  void RF24Transceiver::_receiverCallback()
  {
    uint8_t payload[32];
    
    // while data is being sent, publish to telem topic
    if(radio_.available())
    {
      radio_.read(payload, PAYLOAD_SIZE);
      interfaces::msg::TelemetryMsg msg;
      msg.data = std::string(payload, payload + PAYLOAD_SIZE);
      telem_publisher_->publish(msg);
    }
  }

} // namespace command_and_control