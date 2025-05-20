function setup() {
    createCanvas(windowWidth,windowHeight);
    background(220);//rgb
  
     verts = [];
  
    for( i= 0; i<25; i++){
      for( j = 0; j<25; j++){
        verts[i*25 + j] = new p5.Vector(100 + 50*j, 100 + 50*i);
      }
    }
    
    
  }
  
  function draw() {
  
    background(0,0,0,5);
    
    verts.forEach((vert,i)=> {
      d = dist(mouseX , mouseY , vert.x , vert.y);
      polygon(vert.x , vert.y ,20 + 1000/d ,5);
    })
  
  }
  
  function polygon(x,y,radius, npoints/*幾邊形*/){
    let angle = TWO_PI /*2π*/ / npoints;
    beginShape()
      for (let i = 0; i<TWO_PI; i = i+angle){
        let sx = x + radius * cos(i);
        let sy = y + radius * sin(i);
        vertex(sx,sy);
      }
    endShape(CLOSE)
  }
  
  