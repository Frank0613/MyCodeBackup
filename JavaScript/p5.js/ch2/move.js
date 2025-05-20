function setup() {
    createCanvas(windowWidth, windowHeight);//創建跟視窗一樣大小的畫布
    background(100);//背景顏色
  
    x=0;
    y=height/2;
    r=50;
  }
  
  
  function draw() {
    x=x+1;
    x=x%(width/4);
    clear();
  
    push();//先儲存目前位置
  
    translate(x,y);//將畫布座標軸移到(x,y)
  
    circle(0,0,r);//參照新的座標軸繪製圓
  
    pop()//回到初始位置
  
    //circle(x,y,r)
  }
  