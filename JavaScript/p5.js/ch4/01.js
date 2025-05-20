let Img;
function preload() {
  Img=loadImage('Dragon.png')
}
function setup() {
  
  //imageMode(CENTER)//錨點設為中間
  
  
}

function draw() {
  background(220);
  createCanvas(windowWidth, windowHeight);
  //const x=(windowWidth - Img.width) / 2;
  //onst y=(windowHeight-Img.height) / 2;
  //const x=width/2
  //const y=height/2
  //image(Img,x,y) //圖片, x座標, y座標
  const w=width
  const h=Img.height*(width/Img.width)
  image(Img,0,0,w,h)
}