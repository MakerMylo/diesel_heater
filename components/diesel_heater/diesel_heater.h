#pragma once

#include "esphome.h"

namespace esphome {
namespace diesel_heater {

class DieselHeater : public Component {
 public:
  void setup() override;
  void loop() override;
};

}  // namespace diesel_heater
}  // namespace esphome