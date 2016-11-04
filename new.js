var SerialPort = require('../').SerialPort;
var port = new SerialPort();
 
port.on('data', function(data) {
  console.log(data.toString());
});
 
port.on('error', function(err) {
  console.log(err);
});
 
port.open('COM5', {
  baudRate: 9600,
  dataBits: 8,
  parity: 'none',
  stopBits: 1
}, function(err) {
  port.write("hello world");
  port.close();
});