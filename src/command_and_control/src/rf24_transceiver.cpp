#include "command_and_control/rf24_transceiver.hpp"

namespace command_and_control {

  RF24Transceiver::RF24Transceiver() : Node("rf24_transceiver")
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

    auto receiverCallbackLambda = [this]() 
    {
        uint8_t payload[PAYLOAD_SIZE];
        if (radio_.available()) 
        {
            radio_.read(payload, PAYLOAD_SIZE);
            interfaces::msg::RawDataMsg msg;
            std::copy(payload, payload + PAYLOAD_SIZE, msg.payload.begin());
            raw_data_publisher_->publish(msg);
        }
    };

    // attach lambda function to callback on IRQ pin interrupt
    wiringPiISR(IRQ_PIN, INT_EDGE_FALLING, reinterpret_cast<void(*)()>(&receiverCallbackLambda));
    
    raw_data_publisher_ = this->create_publisher<interfaces::msg::RawDataMsg>("raw_data", 10);
  }


  void RF24Transceiver::transmit_command(const std::shared_ptr<interfaces::srv::SendCommand::Request> request,
    std::shared_ptr<interfaces::srv::SendCommand::Response> response)
  {
    // TODO - what happens if request->payload.size is > 32?
    radio_.stopListening(); // Switch to transmit mode
    response->ack = radio_.write(request->command.payload.data(), request->command.payload.size()); // Send data and store acknowledgment
    radio_.startListening(); // Switch back to listening mode
  }

} // namespace command_and_control


int main()
{
  return 0;
}