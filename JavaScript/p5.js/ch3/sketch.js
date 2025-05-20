let t,x1,x2,y1,y2
function setup() {
  createCanvas(windowWidth,windowHeight)
  background(50)
  x1=0
  x2=width
  y1=height
  y2=0
  t=0

}

function draw() {
  const x=lerp(x1,x2,easeOutBounce(t))
  const y=lerp(y1,y2,easeOutBounce(t))
  t+=0.005
  if(t>1){
    t=0
  }
  clear()
  background(50)
  circle(x,y,20)

}

function squareT(t){
  return t*t
}

function linear(t){
  return t
}

function easeOutBounce(x){
  const n1 = 7.5625
  const d1 = 2.75

  if(x<1/d1){
    return n1*x*x
  }
  else if(x<2/d1){
    return n1 * (x-=1.5/d1)*x+0.75
  }
  else if(x<2.5/d1){
    return n1 * (x-=2.25/d1)*x+0.9375
  }
  else{
    return n1 * (x-=2.625/d1)*x+0.984375
  }
}

