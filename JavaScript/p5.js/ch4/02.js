let Img;
function preload() {
  Img=loadImage('Finish.png')
}
function setup() {
  createCanvas(windowWidth, windowHeight);
  imageMode(CENTER)
  
  
}

function draw() {
  background(220);
  const a =width/height //畫面寬高比
  const b =Img.width/Img.height //圖片寬高比

  if(a<b){
    w=Img.width*(height/Img.height)
    h=height
    
  }
  else{
    w=width
    h=Img.height*(Img.width/width)
    
  }
  image(Img,width/2,height/2,w,h)
}