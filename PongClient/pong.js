var KEY = { UP: 38, DOWN: 40, W: 87, S: 83 };
var pressedKeys = [];
var ball = { speed: 3, x: 290, y: 140, directionX: 1, directionY: 1 };
var pauseBall = false;
var webSocket = new WebSocket("ws://localhost:8888/ws");

webSocket.onopen = function() {
    var msg = {"start": true, "width": 900, "height": 600, "velx": 200, "vely": 0};
	webSocket.send(JSON.stringify(msg));
}
webSocket.onmessage = function(msg) {
    var data = JSON.parse(msg.data);
    $("#ball").css({ "left": data.ballPosx - 10, "top": data.ballPosy - 10 });
    $("#paddleA").css("top", data.paddleAPosy - 45);
    $("#paddleB").css("top", data.paddleBPosy - 45);
    $("#paddleA").css("left", data.paddleAPosx - 15);
    $("#paddleB").css("left", data.paddleBPosx);
}
var sendMessage = function() {
    var msg = {"up": false, "down": false};
	if (pressedKeys[KEY.W]) {
		msg.up = true;
	}
	if (pressedKeys[KEY.S]) {
		msg.down = true;
	}
    webSocket.send(JSON.stringify(msg));
}
var intervalID = window.setInterval(sendMessage, 20);
webSocket.onclose = function() {
    window.clearInterval(intervalID);
}

$(function() {
	$(document).keydown(function(e) {
		pressedKeys[e.which] = true;
	});
	$(document).keyup(function(e) {
		pressedKeys[e.which] = false;
	});
});
