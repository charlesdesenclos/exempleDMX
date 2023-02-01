var websocket = new WebSocket("ws://192.168.64.237:1234");
//filtre wireshark (ip.src == 192.168.65.143 && ip.dst == 192.168.65.44)||(ip.src == 192.168.65.44 && ip.dst == 192.168.65.143)
window.addEventListener('load', onload);

function onload(event) {
    initWebSocket();
}

function getValues(){
    websocket.send("getValues");
}               

function initWebSocket() {
    websocket.onopen = onOpen;
    websocket.onmessage = onMessage;
}

function onOpen(event) {
    //console.log('Connection opened');
    getValues();
}

function updateSliderPWM(element) {
    var sliderNumber = element.id.charAt(element.id.length-1);
    var sliderValue = document.getElementById(element.id).value;
    document.getElementById("sliderValue"+sliderNumber).innerHTML = sliderValue;
    // console.log(sliderValue);
    websocket.send(sliderNumber+"s"+sliderValue.toString());
}

function onMessage(event) {
    console.log(event.data);
    var myObj = JSON.parse(event.data);
    var keys = Object.keys(myObj);

    // for (var i = 0; i < keys.length; i++){
    //     var key = keys[i];
    //     document.getElementById(key).innerHTML = myObj[key];
    //     document.getElementById("slider"+ (i+1).toString()).value = myObj[key];
    //     console.log(sliderValue);
    // }
}