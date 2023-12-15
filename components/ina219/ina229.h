#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/spi/spi.h"

namespace esphome
{
  namespace ina229
  {

    // original code for INA260 is not member of sensor::Sensor
    class INA229Component : public sensor::Sensor, public PollingComponent, public spi::SPIDevice<spi::BIT_ORDER_MSB_FIRST, spi::CLOCK_POLARITY_LOW, spi::CLOCK_PHASE_LEADING, spi::DATA_RATE_2MHZ>
    {
    public:
      void setup() override;
      void update() override;
      void loop() override;
      void dump_config() override;

      // example what can be here:
      // void set_shunt_resistance_ohm(float shunt_resistance_ohm) { shunt_resistance_ohm_ = shunt_resistance_ohm; }

    protected:
      /*   example what can be here
      float max_voltage_v_;
      uint32_t calibration_lsb_;
      sensor::Sensor *bus_voltage_sensor_{nullptr};
      sensor::Sensor *shunt_voltage_sensor_{nullptr};
      */
    };

  } // namespace ina229
} // namespace esphome