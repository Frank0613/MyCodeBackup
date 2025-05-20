var points = []
var space = 50

function setup(){
  createCanvas(windowWidth,windowHeight)
  background(220)
  fill(0)
  strokeWeight(2)
  for (let x = space; x <= width- space; x = x+space){
    for (let y = space;y <= height - space;y=y+space){
      points.push(new p5.Vector(x,y))
    }
  }

  //drawGrid()
  drawCell()

}

function drawGrid(){
  points.forEach(point => {
    rectMode(CENTER)
    fill(255)
    rect(point.x,point.y,space,space)
  })
}

function drawCell(){
  noiseSeed()
  points.forEach(point=>{
    let dir=floor(100*random())
    if(dir%3==1){
      //image(img,point.x,point.y,space,space)
      line(point.x-0.5*space,point.y-0.5*space,point.x+0.5*space,point.y+0.5*space)
    }
    else{
      //image(img2,point.x,point.y,space,space)
      line(point.x+0.5*space,point.y-0.5*space,point.x-0.5*space,point.y+0.5*space)
    }
  })
}