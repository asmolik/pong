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
    $("#paddleA").css("left", data.paddleAPosx - 5);
    $("#paddleB").css("left", data.paddleBPosx - 5);
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
	//setInterval(gameLoop, 1000 / 60);
});

// function gameLoop() {
// 	//moveBall();
// 	//movePaddles();
// }
// 
// function movePaddles() {
// 	var paddleSpeed = 6;
// 
// 	// if (pressedKeys[KEY.W]) {
// 	// 	var top = parseInt($("#paddleA").css("top"));
// 	// 	if (top >= -parseInt($("#paddleA").css("height"))/2) {
// 	// 		$("#paddleA").css("top", top - paddleSpeed);
// 	// 	}
// 	// }
// 	// if (pressedKeys[KEY.S]) {
// 	// 	var top = parseInt($("#paddleA").css("top"));
// 	// 	if (top <= (parseInt($("#game").css("height")) - (parseInt($("#paddleA").css("height")))/2)) {
// 	// 		$("#paddleA").css("top", top + paddleSpeed);
// 	// 	}
// 	// }
// 	if (pressedKeys[KEY.UP]) {
// 		var top = parseInt($("#paddleB").css("top"));
// 		if (top >= -parseInt($("#paddleB").css("height"))/2) {
// 			$("#paddleB").css("top", top - paddleSpeed);
// 		}
// 	}
// 	if (pressedKeys[KEY.DOWN]) {
// 		var top = parseInt($("#paddleB").css("top"));
// 		if (top <= (parseInt($("#game").css("height")) - (parseInt($("#paddleB").css("height")))/2)) {
// 			$("#paddleB").css("top", top + paddleSpeed);
// 		}
// 	}
// }
// 
// function moveBall() {
// 	var gameWidth = parseInt($("#game").width());
// 	var gameHeight = parseInt($("#game").height());
// 
// 	if (pauseBall) return;
// 	
// 	//y:
// 	// collisionDown
// 	if (ball.y + ball.speed * ball.directionY > (gameHeight - parseInt($("#ball").height()))) {
// 		ball.directionY = -1
// 	}
// 	
// 	// collisionUp
// 	if (ball.y + ball.speed * ball.directionY < 0) {
// 		ball.directionY = 1
// 	}
// 	
// 	//x:
// 	// collisionRight
// 	if (ball.x + ball.speed * ball.directionX > gameWidth ) {
// 		ball.x = 290;
// 		ball.y = 140;
// 		pauseBall = true;
// 		$("#ball").animate({ "left": ball.x, "top": ball.y }, 2000, function() { pauseBall = false; });
// 		ball.directionX = -1;
// 		return;
// 	}
// 
// 	// collisionLeft
// 	if (ball.x + ball.speed * ball.directionX < 0) {
// 		ball.x = 290;
// 		ball.y = 140;
// 		pauseBall = true;
// 		$("#ball").animate({ "left": ball.x, "top": ball.y }, 2000, function() { pauseBall = false; });
// 		ball.directionX = 1;
// 		return;
// 	}
// 
// 	ball.x += ball.speed * ball.directionX;
// 	ball.y += ball.speed * ball.directionY;
// 
// 	// paddleA
// 	var paddleAX = parseInt($("#paddleA").css("left")) + parseInt($("#paddleA").css("width"));
// 	if (ball.x + ball.speed * ball.directionX < paddleAX) {
// 		var paddleAYBottom = parseInt($("#paddleA").css("top")) + parseInt($("#paddleA").css("height"));
// 		var paddleAYTop = parseInt($("#paddleA").css("top"));
// 
// 		if ((ball.y + ball.speed * ball.directionY <= paddleAYBottom) && (ball.y + ball.speed * ball.directionY >= paddleAYTop)) {
// 			ball.directionX = 1
// 		}
// 	}
// 
// 	// paddleB
// 	var paddleBX = parseInt($("#paddleB").css("left")) - parseInt($("#paddleB").css("width"));
// 	if (ball.x + ball.speed * ball.directionX >= paddleBX) {
// 		var paddleBYBottom = parseInt($("#paddleB").css("top")) + parseInt($("#paddleB").css("height"));
// 		var paddleBYTop = parseInt($("#paddleB").css("top"));
// 
// 		if ((ball.y + ball.speed * ball.directionY <= paddleBYBottom) && (ball.y + ball.speed * ball.directionY >= paddleBYTop)) {
// 			ball.directionX = -1
// 		}
// 	}
// 	$("#ball").css({ "left": ball.x, "top": ball.y });
// };
