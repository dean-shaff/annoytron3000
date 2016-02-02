import processing.serial.*; 

Serial myPort ; 
float val = 0; 
float minVal = 100; 
float maxVal ; 

void setup(){
  size(800,600);
  //println(Serial.list());
  String portName = "/dev/cu.usbmodem1411" ;
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
  colorMode(HSB,100) ;
  
}

void draw(){
  background(0,0,100); 
  int valdim = int(map(val, minVal, maxVal, 50,100));
  fill(valdim, 100,100) ;
  ellipse(width/2, height/2, 100,100);
  //rect(width/2 - valdim, height/2 - valdim, width/2 + valdim, height/2 + valdim); 
  println("Current Value: "+val+" minimum value: " + minVal); 
}

void serialEvent(Serial myPort){
  String input = myPort.readString() ; 
  val = float(input) ; 
  if (val < minVal){
    minVal = val ; 
    maxVal = minVal + 10 ; 
  }
  //println(val) ; 
  //myPort.write('x');
}