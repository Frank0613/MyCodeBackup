function setup() {
    createCanvas(windowWidth, windowHeight);//創建跟視窗一樣大小的畫布
    background(100);//背景顏色
  
    
  }
  
  
  function draw() {
    x=mouseX
    y=mouseY
    r=random(-2,2)
    
    
    fill(100,100,100,100)
    rect(0,0,width,height);
  
    fill(105,25,255,55)
    circle(x,y,r);
    stroke(105,25,255,55)
    strokeWeight(random(10,100))
    //background(100);
   
  }