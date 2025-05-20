var d;
function setup() {
  createCanvas(windowWidth,windowHeight);
  background(220);//rgb
  noStroke()
  reset()
}
function draw() {

    d+=10;
  
  if(d>900){
    reset();
  }
  background(220)  
  circle(width/2,height/2,d)
}


function reset(){
  d=0
}

