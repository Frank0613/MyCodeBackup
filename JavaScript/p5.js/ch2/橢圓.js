function setup() {
  createCanvas(windowWidth, windowHeight); //創建跟視窗一樣大小的畫布
  background(0); //背景顏色
  noFill();
}

function draw() {
  r = random(0, 300);
  z = random(0, 300);
  x = width / random(-5, 5);
  y = height / 2;
  fill(0, 0, 0, 10);
  rect(0, 0, width, height);
  stroke(random(180, 255), random(180, 255), random(100, 255), 100);
  strokeWeight(random(0, 100));
  ellipse(x, y, r, z);
}
