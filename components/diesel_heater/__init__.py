import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import CONF_ID
import esphome.codegen as cg

# Define the namespace and class
diesel_heater_ns = cg.esphome_ns.namespace('diesel_heater')
DieselHeater = diesel_heater_ns.class_('DieselHeater', cg.Component, uart.UARTDevice)

# Define the configuration schema
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(DieselHeater),
}).extend(cv.COMPONENT_SCHEMA).extend(uart.UART_DEVICE_SCHEMA)

# Register the component
async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID], await cg.get_variable(config[uart.CONF_UART_ID]))
    await cg.register_component(var, config)