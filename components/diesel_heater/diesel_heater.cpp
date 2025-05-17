#include "diesel_heater.h"

namespace esphome {
namespace diesel_heater {

void DieselHeater::setup() {
  ESP_LOGCONFIG(TAG, "Setting up Diesel Heater...");
}

void DieselHeater::loop() {
  if (this->available() >= 3) {
    uint8_t buffer[3];
    this->read_array(buffer, 3);
    this->run_state_ = buffer[2];
    ESP_LOGD(TAG, "Run state updated: %d", this->run_state_);
  }
}

}  // namespace diesel_heater
}  // namespace esphome