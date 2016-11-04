$(document).ready(function(){

var socket = io("http://localhost:3000");

$("#setearm1").click(function(){
	socket.emit("enviandoDatos","setearm1");
	});


$("#moverm1").click(function(){
	socket.emit("enviandoDatos","moverm1");
});


$("#moverm2").click(function(){
	socket.emit("enviandoDatos","moverm2");
});


$("#setear_gradosm2").click(function(){
	socket.emit("enviandoDatos","setear_gradosm2");
});

$("#prenderDC").click(function(){
	socket.emit("enviandoDatos","prenderDC");
});

$("#apagarDC").click(function(){
	socket.emit("enviandoDatos","apagarDC");
});

$("#girarDerDC").click(function(){
	socket.emit("enviandoDatos","girarDerDC");
});

$("#girarIzqDC").click(function(){
	socket.emit("enviandoDatos","girarIzqDC");
});

socket.on('mostrarTemp',function(temp){
	jQuery("#temp").text(temp);
	
});

$("#setearm1").click(function(){
	socket.emit("enviandoDatos","setearm1",$('#s1').val());


});

$("#setear_gradosm2").click(function(){
	socket.emit("enviandoDatos","setear_gradosm2",$('#s2').val());


});		




});

