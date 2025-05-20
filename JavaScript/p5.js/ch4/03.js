const cw = 16
const ch = 18
const scale = 5
let Img

function preload(){
  img=loadImage('Finish.png')
}
function setup(){
  createCanvas(windowWidth,windowHeight)
  noSmooth()

  for (let i = 0;i<3;i++){
    copy(img,cw*i,0,cw,ch,cw*i*scale,0,cw*scale,ch*scale)
  }
}