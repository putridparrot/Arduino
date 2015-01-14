# Arduino

Arduino related library code.

The intention is to implement various sensors/components for use with the Arduino, using interfaces where appropriate to allow me to build more complex hardware and unit test the code. The interfaces will add to the size of the end binary, so I may also look at ways to remove them from final builds.

The use of the Export.h file allows me to define API which when built with the define EXPORT_LIB will compile to a DLL using Visual Studio (I am using Visual Micro for Visual Studio to work with the Arduino). When compiled as a DLL we can run unit tests against our code. Undef EXPORT_LIB to build for deployment.

### Interfaces

The interfaces are probably self-explanatory, but I'll list them any way as I add them.

*ITemperature*

Sensors which support temperature sensing such as the DHT11 will implement this interface, simply implement/call the method getTemperature.

*IHumidity*

Sensors which support humidity (again) such as the DHT11 will implement this interfaces, simply implement/call the method getHumidity.

*IDistance*

Sensors which spport distance measurements such as the HCSR04 will implement this interface, simple implement/call the method getDistance.

### Classes

*DHT11* 

This is a component/class which supports both humidity and temperature sensing.

*HCSR04*

The HCSR04 component/class supports distance reading. It's an ultrasound sensor.


### Library license

The library is available under the MIT license. See the [License file][1] in the GitHub repository.

  [1]: https://github.com/putridparrot/Arduino/blob/master/LICENSE
