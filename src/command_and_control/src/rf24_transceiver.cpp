#include "command_and_control/rf24_transceiver.hpp"

namespace command_and_control {

  void receiverCallbackLambda();

  RF24Transceiver::RF24Transceiver() : Node("rf24_transceiver")
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Initializing RF24 transceiver");
    // Init RF24
    radio_ = RF24(CE_PIN, CSN_PIN, SPI_SPEED);     
    while (!radio_.begin()) {}                // Wait until RF24 is ready
    radio_.setPALevel(RF24_PA_MIN);           // Set power level
    radio_.setDataRate(RF24_250KBPS);         // Set data rate
    radio_.setPayloadSize(PAYLOAD_SIZE);      // Set payload size
    radio_.openWritingPipe(PIPE[1]);
    radio_.openReadingPipe(1, PIPE[0]);       // Open pipe 0 for reading
    radio_.setChannel(69);                    // Set RF24 channel
    radio_.setAutoAck(true);
    radio_.startListening();                  // Start listening mode
    radio_.printPrettyDetails();

//    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Initializing the IRQ callback pin");
    // Init WiringPi
/*
    wiringPiSetupGpio();
    pinMode(IRQ_PIN, INPUT);
    pullUpDnControl(IRQ_PIN, PUD_UP); // default to a high state

    // attach lambda function to callback on IRQ pin interrupt
    wiringPiISR(IRQ_PIN, INT_EDGE_FALLING, &interrupt);
*/ 
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Initializing Raw Data publisher");
    raw_data_publisher_ = this->create_publisher<interfaces::msg::RawDataMsg>("raw_data", 10);
    send_command_service_ = this->create_service<interfaces::srv::SendCommand>("send_command", std::bind(&RF24Transceiver::transmit_command, this, std::placeholders::_1, std::placeholders::_2));
   
    // create the callback that will poll the transceiver resource
    auto timer_callback =  
      [this]() -> void  
      {
        // data received is unreliable during a falling transition
        // reset IRQ pin to high
 //       bool tx_ds, tx_df, rx_dr;
 //      radio_.whatHappened(tx_ds, tx_df, rx_dr); // data is now reliable

        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "lambda callback");
        uint8_t payload[PAYLOAD_SIZE];
        if (radio_.available()) 
        {
            radio_.read(payload, PAYLOAD_SIZE);
            interfaces::msg::RawDataMsg msg;
            std::copy(payload, payload + PAYLOAD_SIZE, msg.payload.begin());
            raw_data_publisher_->publish(msg);
        }
     };

    timer_ = this->create_wall_timer(std::chrono::milliseconds(500), timer_callback);

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


int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<command_and_control::RF24Transceiver>());
  rclcpp::shutdown();
  return 0;
}
