function setup() {
    createCanvas(windowWidth, windowHeight);//創建跟視窗一樣大小的畫布
    background(100);//背景顏色
    noFill();
  
    x=width/2;
    y=height/2;
    r=100;
    
  }
  
  
  function draw() {
    r=random(50,300)
    
    stroke(random(100,255),random(100,255),random(100,255))
    strokeWeight(random(1,10))
    circle(x,y,r)
  }
  