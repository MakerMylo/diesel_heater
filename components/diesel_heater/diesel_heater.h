#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace diesel_heater {

class DieselHeater : public Component, public uart::UARTDevice {
 public:
  explicit DieselHeater(uart::UARTComponent *parent) : uart::UARTDevice(parent) {}

  void setup() override;
  void loop() override;

  // Method to get the run state
  int get_run_state() const { return run_state_; }

 private:
  static constexpr const char* TAG = "diesel_heater";
  int run_state_ = 0;  // Variable to store the run state
};

}  // namespace diesel_heater
}  // namespace esphome