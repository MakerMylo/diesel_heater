import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_ID
from esphome import automation
import esphome.codegen as cg

# Define the namespace and class
diesel_heater_ns = cg.esphome_ns.namespace('diesel_heater')
DieselHeater = diesel_heater_ns.class_('DieselHeater', cg.Component)

# Define the configuration schema
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(DieselHeater),
}).extend(sensor.SENSOR_SCHEMA)