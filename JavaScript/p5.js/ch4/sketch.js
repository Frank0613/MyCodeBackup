let size = 50;
let col = {
  r: 0,
  g: 0,
  b: 0
};

function setup() {
  createCanvas(600, 600);
  background(255);
  noStroke();
}

function draw() {
  fill(col.r, col.g, col.b);
  triangle(random(width), random(height), random(width), random(height), random(width), random(height));
}

function mousePressed() {
  size = random(20, 100);
  col.r = random(0, 255);
  col.g = random(0, 255);
  col.b = random(0, 255);
  background(255);
}